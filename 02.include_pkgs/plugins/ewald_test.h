/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef KSPACE_CLASS
// clang-format off
KSpaceStyle(ewald/test,EwaldTest);
// clang-format on
#else

#ifndef LMP_EWALD_TEST_H
#define LMP_EWALD_TEST_H

#include "ewald.h"
#include <fstream>
#include <iostream>

namespace LAMMPS_NS
{

   class EwaldTest : public Ewald
   {
   public:
      EwaldTest(class LAMMPS *);
      virtual ~EwaldTest();
      virtual void compute(int, int);
   };

} // namespace LAMMPS_NS

#endif
#endif
