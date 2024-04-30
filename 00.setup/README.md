# README

> The examples come from the official code, with minor modification of the cmake setup to fit in the IKKEM.

1. Load the required modules and setup the environment variables

    ```bash
    module load intel/oneapi2021.1
    module load dev/cmake/3.26.3 
    
    module load lammps/2022.6.23-plugin

    # setup the path to lammps source code
    export LAMMPS_SOURCE_DIR=/public/software/lammps/lammps-23Jun2022-plugin/src
    ```

2. Compile the plugins

    ```bash
    cd plugins
    mkdir -p build && cd build
    rm -r *
    cmake -DLAMMPS_SOURCE_DIR=$LAMMPS_SOURCE_DIR ..
    make
    # setup the path to lammps plugins
    export LAMMPS_PLUGIN_PATH=$PWD:$LAMMPS_PLUGIN_PATH
    ```

3. Run the example

    ```bash
    cd ../../test
    lmp_intel_cpu_intelmpi -i input.lmp
    ```
