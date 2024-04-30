# Step-by-step guide to run LAMMPS with plugins

Here is a simple tutorial for writing LAMMPS plugins by yourself and run them in IKKEM HPC. You can find:

1. How to compile given plugin code and call the plugins in LAMMPS in `00.setup`
2. How to write your first plugin in `01.compute_test`

Please make sure that the following modules are loaded when both the compiling the plugins and running LAMMPS:

    ```bash
    module load intel/oneapi2021.1
    module load dev/cmake/3.26.3 
    module load lammps/2022.6.23-plugin

    export LAMMPS_SOURCE_DIR=/public/software/lammps/lammps-23Jun2022-plugin/src
    ```

For convenience, the readers are recommended to set these up via a shell script or a conda environment (create an environment and set up in `$CONDA_PREFIX/etc/conda/activate.d/activate.sh`). 

Further details of the examples can be found in the corresponding directories.
More information about developing LAMMPS can be found in:
- [LAMMPS Developer Guide](https://docs.lammps.org/Developer.html)
- [Extending and Modifying LAMMPS Writing Your Own](https://github.com/PacktPublishing/Extending-and-Modifying-LAMMPS-Writing-Your-Own-Source-Code)

