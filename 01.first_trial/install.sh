module purge

module load intel/2021.1
module load gcc/9.3
module load dev/cmake/3.26.3

mkdir -p lmp_plugins/build
cd lmp_plugins/build
cmake -LAMMPS_SOURCE_DIR=$LAMMPS_SOURCE_DIR ..
make -j 4
