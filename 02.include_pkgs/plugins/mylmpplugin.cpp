// SPDX-License-Identifier: LGPL-3.0-or-later
/**
 * See https://docs.lammps.org/Developer_plugins.html
 */
#include "lammpsplugin.h"
#include "version.h"

#include "ewald_test.h"

using namespace LAMMPS_NS;


static KSpace *ewaldtest(LAMMPS *lmp) {
  return new EwaldTest(lmp);
}

extern "C" void lammpsplugin_init(void *lmp, void *handle, void *regfunc) 
{
  lammpsplugin_t plugin;
  lammpsplugin_regfunc register_plugin = (lammpsplugin_regfunc) regfunc;

  plugin.version = LAMMPS_VERSION;
  plugin.author = "Jia-Xin Zhu (jiaxinzhu@stu.xmu.edu.cn)";

  plugin.style = "kspace";
  plugin.name = "ewald/test";
  plugin.info = "kspace_style ewald/test";
  plugin.creator.v1 = (lammpsplugin_factory1 *) &ewaldtest;
  (*register_plugin)(&plugin, lmp);
}
