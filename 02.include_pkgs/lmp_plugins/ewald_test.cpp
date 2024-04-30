// clang-format off
/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing authors: Roy Pollock (LLNL), Paul Crozier (SNL)
     per-atom energy/virial added by German Samolyuk (ORNL), Stan Moore (BYU)
     group/group energy/force added by Stan Moore (BYU)
     triclinic added by Stan Moore (SNL)
------------------------------------------------------------------------- */

#include "ewald_test.h"
#include "ewald.h"

#include "atom.h"
#include "comm.h"
#include "domain.h"
#include "error.h"
#include "force.h"
#include "math_const.h"
#include "memory.h"
#include "pair.h"

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>

using namespace LAMMPS_NS;
using namespace MathConst;
using namespace std;

#define SMALL 0.00001

/* ---------------------------------------------------------------------- */

EwaldTest::EwaldTest(LAMMPS *lmp) : Ewald(lmp) {}

EwaldTest::~EwaldTest() {}

void EwaldTest::compute(int eflag, int vflag)
{
  std::cout << "hello world!" << std::endl;
  Ewald::compute(eflag, vflag);
}
