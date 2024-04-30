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

#include "compute_test_scalar_atom.h"
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

ComputeTestScalarAtom::ComputeTestScalarAtom(LAMMPS *lmp, int narg, char **arg) :
  Compute(lmp, narg, arg),
  test_vector(nullptr)
{
  if (narg != 3) error->all(FLERR,"Illegal compute test/scalar/atom command");

  peratom_flag = 1;
  size_peratom_cols = 0;

  nmax = 0;
}

/* ---------------------------------------------------------------------- */

ComputeTestScalarAtom::~ComputeTestScalarAtom()
{
  memory->destroy(test_vector);
}

/* ---------------------------------------------------------------------- */

void ComputeTestScalarAtom::init()
{
  // int count = 0;
  // for (int i = 0; i < modify->ncompute; i++)
  //   if (strcmp(modify->compute[i]->style,"test/atom") == 0) count++;
  // if (count > 1 && comm->me == 0)
  //   error->warning(FLERR,"More than one compute test/atom");
}

/* ---------------------------------------------------------------------- */

void ComputeTestScalarAtom::compute_peratom()
{
  invoked_peratom = update->ntimestep;

  // grow ke array if necessary

  if (atom->nmax > nmax) {
    memory->destroy(test_vector);
    nmax = atom->nmax;
    memory->create(test_vector,nmax,"test/scalar/atom:test_vector");
    vector_atom = test_vector;
  }

  int nlocal = atom->nlocal;

  for (int ii = 0; ii < nlocal; ii++) {
    test_vector[ii] = 0.01 * ii;
  }
}

/* ----------------------------------------------------------------------
   memory usage of local atom-based array
------------------------------------------------------------------------- */

double ComputeTestScalarAtom::memory_usage()
{
  double bytes = (double)nmax * sizeof(double);
  return bytes;
}
