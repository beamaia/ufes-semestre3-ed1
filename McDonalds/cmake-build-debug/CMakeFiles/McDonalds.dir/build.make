# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/bea/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bea/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bea/ufes/semestre-03/ed1/McDonalds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/McDonalds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/McDonalds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/McDonalds.dir/flags.make

CMakeFiles/McDonalds.dir/pedido.c.o: CMakeFiles/McDonalds.dir/flags.make
CMakeFiles/McDonalds.dir/pedido.c.o: ../pedido.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/McDonalds.dir/pedido.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/McDonalds.dir/pedido.c.o   -c /home/bea/ufes/semestre-03/ed1/McDonalds/pedido.c

CMakeFiles/McDonalds.dir/pedido.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/McDonalds.dir/pedido.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bea/ufes/semestre-03/ed1/McDonalds/pedido.c > CMakeFiles/McDonalds.dir/pedido.c.i

CMakeFiles/McDonalds.dir/pedido.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/McDonalds.dir/pedido.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bea/ufes/semestre-03/ed1/McDonalds/pedido.c -o CMakeFiles/McDonalds.dir/pedido.c.s

CMakeFiles/McDonalds.dir/produto.c.o: CMakeFiles/McDonalds.dir/flags.make
CMakeFiles/McDonalds.dir/produto.c.o: ../produto.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/McDonalds.dir/produto.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/McDonalds.dir/produto.c.o   -c /home/bea/ufes/semestre-03/ed1/McDonalds/produto.c

CMakeFiles/McDonalds.dir/produto.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/McDonalds.dir/produto.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bea/ufes/semestre-03/ed1/McDonalds/produto.c > CMakeFiles/McDonalds.dir/produto.c.i

CMakeFiles/McDonalds.dir/produto.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/McDonalds.dir/produto.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bea/ufes/semestre-03/ed1/McDonalds/produto.c -o CMakeFiles/McDonalds.dir/produto.c.s

CMakeFiles/McDonalds.dir/progpedidos.c.o: CMakeFiles/McDonalds.dir/flags.make
CMakeFiles/McDonalds.dir/progpedidos.c.o: ../progpedidos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/McDonalds.dir/progpedidos.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/McDonalds.dir/progpedidos.c.o   -c /home/bea/ufes/semestre-03/ed1/McDonalds/progpedidos.c

CMakeFiles/McDonalds.dir/progpedidos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/McDonalds.dir/progpedidos.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bea/ufes/semestre-03/ed1/McDonalds/progpedidos.c > CMakeFiles/McDonalds.dir/progpedidos.c.i

CMakeFiles/McDonalds.dir/progpedidos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/McDonalds.dir/progpedidos.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bea/ufes/semestre-03/ed1/McDonalds/progpedidos.c -o CMakeFiles/McDonalds.dir/progpedidos.c.s

# Object files for target McDonalds
McDonalds_OBJECTS = \
"CMakeFiles/McDonalds.dir/pedido.c.o" \
"CMakeFiles/McDonalds.dir/produto.c.o" \
"CMakeFiles/McDonalds.dir/progpedidos.c.o"

# External object files for target McDonalds
McDonalds_EXTERNAL_OBJECTS =

McDonalds: CMakeFiles/McDonalds.dir/pedido.c.o
McDonalds: CMakeFiles/McDonalds.dir/produto.c.o
McDonalds: CMakeFiles/McDonalds.dir/progpedidos.c.o
McDonalds: CMakeFiles/McDonalds.dir/build.make
McDonalds: CMakeFiles/McDonalds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable McDonalds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/McDonalds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/McDonalds.dir/build: McDonalds

.PHONY : CMakeFiles/McDonalds.dir/build

CMakeFiles/McDonalds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/McDonalds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/McDonalds.dir/clean

CMakeFiles/McDonalds.dir/depend:
	cd /home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bea/ufes/semestre-03/ed1/McDonalds /home/bea/ufes/semestre-03/ed1/McDonalds /home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug /home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug /home/bea/ufes/semestre-03/ed1/McDonalds/cmake-build-debug/CMakeFiles/McDonalds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/McDonalds.dir/depend

