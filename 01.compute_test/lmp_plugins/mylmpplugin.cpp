// SPDX-License-Identifier: LGPL-3.0-or-later
/**
 * See https://docs.lammps.org/Developer_plugins.html
 */
#include "lammpsplugin.h"
#include "version.h"

#include "compute_test_scalar_atom.h"
#include "compute_test_vector_atom.h"

using namespace LAMMPS_NS;


static Compute *computetestscalaratom(LAMMPS *lmp, int narg, char **arg) {
  return new ComputeTestScalarAtom(lmp, narg, arg);
}

static Compute *computetestvectoratom(LAMMPS *lmp, int narg, char **arg) {
  return new ComputeTestVectorAtom(lmp, narg, arg);
}

extern "C" void lammpsplugin_init(void *lmp, void *handle, void *regfunc) 
{
  lammpsplugin_t plugin;
  lammpsplugin_regfunc register_plugin = (lammpsplugin_regfunc) regfunc;

  plugin.version = LAMMPS_VERSION;
  plugin.author = "Jia-Xin Zhu (jiaxinzhu@stu.xmu.edu.cn)";

  plugin.style = "compute";
  plugin.name = "test/scalar/atom";
  plugin.info = "compute test/scalar/atom";
  plugin.creator.v2 = (lammpsplugin_factory2 *) &computetestscalaratom;
  plugin.handle = handle;
  (*register_plugin)(&plugin, lmp);

  plugin.style = "compute";
  plugin.name = "test/vector/atom";
  plugin.info = "compute test/vector/atom";
  plugin.creator.v2 = (lammpsplugin_factory2 *) &computetestvectoratom;
  (*register_plugin)(&plugin, lmp);
}
