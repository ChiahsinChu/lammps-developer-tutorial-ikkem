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
```

## Details of plugins

In the example in `01.first_trial`, our plugins only depend on the common library in LAMMPS but not any package. In fact, you need to specify the dependency to the packages in `CMakeLists.txt` if your plugin use any of them. For example, a `kspace ewald/test` plugin is implemented in this example. This plugin makes nothing changes based on the `kspace ewald` but print `hello world!` on the screen in every timestep. The main part of the implementation can be found in the `void EwaldTest::compute(int eflag, int vflag)` method in `plugins/ewald_test.cpp`. You can test the plugin by 1) checking the output of `dump` and 2) checking the screen output in `test`. In order to make our plugin find the necessary libraries, we make the following modification in `CMakeLists.txt`:

```bash
set(libname "mylmpplugin")
# add ${LAMMPS_SOURCE_DIR}/kspace.cpp and ${LAMMPS_SOURCE_DIR}/KSPACE/ewald.cpp
file(GLOB LMP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
${LAMMPS_SOURCE_DIR}/kspace.cpp
${LAMMPS_SOURCE_DIR}/KSPACE/ewald.cpp)
add_library(${libname} MODULE ${LMP_SRC})
target_link_libraries(${libname} PRIVATE lammps)
# add ${LAMMPS_SOURCE_DIR}/KSPACE
target_include_directories(
  ${libname}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..
          ${LAMMPS_SOURCE_DIR}/PLUGIN ${LAMMPS_SOURCE_DIR}/KSPACE
          ${LAMMPS_SOURCE_DIR})
set_target_properties(${libname} PROPERTIES PREFIX "" SUFFIX ".so")
```

