# README

## Run LAMMPS with plugins

```bash
module load intel/oneapi2021.1
module load dev/cmake/3.26.3 

module load lammps/2022.6.23-plugin

# setup the path to lammps source code
export LAMMPS_SOURCE_DIR=/public/software/lammps/lammps-23Jun2022-plugin/src

mkdir -p lmp_plugins/build
cd lmp_plugins/build
cmake -DLAMMPS_SOURCE_DIR=$LAMMPS_SOURCE_DIR ..
make

export LAMMPS_PLUGIN_PATH=$PWD:$LAMMPS_PLUGIN_PATH
```