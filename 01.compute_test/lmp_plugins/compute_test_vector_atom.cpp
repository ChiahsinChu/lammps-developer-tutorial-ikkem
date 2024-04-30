// clang-format off
/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   LAMMPS development team: developers@lammps.org

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#include "compute_test_vector_atom.h"
#include <cstring>
#include "atom.h"
#include "update.h"
#include "modify.h"
#include "comm.h"
#include "force.h"
#include "memory.h"
#include "error.h"

using namespace LAMMPS_NS;

/* ---------------------------------------------------------------------- */

ComputeTestVectorAtom::ComputeTestVectorAtom(LAMMPS *lmp, int narg, char **arg) :
  Compute(lmp, narg, arg),
  tensor(nullptr)
{
  if (narg != 3) error->all(FLERR,"Illegal compute test/vector/atom command");

  peratom_flag = 1;
  size_peratom_cols = 3;

  nmax = 0;
}

/* ---------------------------------------------------------------------- */

ComputeTestVectorAtom::~ComputeTestVectorAtom()
{
  memory->destroy(tensor);
}

/* ---------------------------------------------------------------------- */

void ComputeTestVectorAtom::init() {}

/* ---------------------------------------------------------------------- */

void ComputeTestVectorAtom::compute_peratom()
{
  invoked_peratom = update->ntimestep;

  // grow ke array if necessary

  if (atom->nmax > nmax) {
    memory->destroy(tensor);
    nmax = atom->nmax;
    memory->create(tensor, nmax, size_peratom_cols,"test/vector/atom:tensor");
    array_atom = tensor;
  }
  
  int nlocal = atom->nlocal;

  for (int ii = 0; ii < nlocal; ii++) {
    for (int jj = 0; jj < size_peratom_cols; jj++) {
      tensor[ii][jj] = 0.01 * (double)ii + 0.1 * (double)jj;
    }
  }
}

/* ----------------------------------------------------------------------
   memory usage of local atom-based array
------------------------------------------------------------------------- */

double ComputeTestVectorAtom::memory_usage()
{
  double bytes = (double)nmax * sizeof(double);
  return bytes;
}
