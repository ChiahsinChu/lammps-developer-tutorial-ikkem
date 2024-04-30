# README

## Run LAMMPS with plugins

```bash
module load intel/oneapi2021.1
module load dev/cmake/3.26.3 

module load lammps/2022.6.23-plugin

# setup the path to lammps source code
export LAMMPS_SOURCE_DIR=/public/software/lammps/lammps-23Jun2022-plugin/src

mkdir -p plugins/build
cd plugins/build
cmake -DLAMMPS_SOURCE_DIR=$LAMMPS_SOURCE_DIR ..
make

export LAMMPS_PLUGIN_PATH=$PWD:$LAMMPS_PLUGIN_PATH

cd ../../test
lmp_intel_cpu_intelmpi -i input.lmp
```

## Details of plugins

In the example in `00.setup`, each new style are added into the `CMakeLists.txt` manually and wrap into an individual plugin. Instead, we use `GLOB` and put all plugins into one plugin call `mylmpplugin`. Then, it is no need to modify the `CMakeLists.txt` once you add new plugins. Nevertheless, you still need to add the information of the new style in `mylmpplugin.cpp`. **Please make sure the name of the `.cpp` file is consistent with the `libname` set in the `CMakeLists.txt`.** You can find more details for different styles in the [offical guide](https://docs.lammps.org/Developer_plugins.html). 

In this example, we implement two plugins here, i.e., `compute test/scalar/atom` and `compute test/coord/atom`. In the first plugin, `0.01*(id-1)` is set as the atomic scalar quantities and printed out via `dump`. You can find the example output in `test/ref_output/test_scalar.lammpstrj`. The main part of the implementation is in the `void ComputeTestScalarAtom::compute_peratom()` method in `lmp_plugins/compute_test_scalar_atom.cpp`. More details about the variables used in the `compute` style can be found in the [guidebook](https://github.com/PacktPublishing/Extending-and-Modifying-LAMMPS-Writing-Your-Own-Source-Code). Similarly, in the second plugin, the atomic coordinates are set as the atomic vector quantities and printed out via `dump`. You can verify the method by comparing the output with those from `dump custom x y z`. 