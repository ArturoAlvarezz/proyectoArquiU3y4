# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/arturo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/223.7571.171/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/arturo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/223.7571.171/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arturo/CLionProjects/proyectoArquiU3y4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proyectoArquiU3y4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proyectoArquiU3y4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proyectoArquiU3y4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyectoArquiU3y4.dir/flags.make

CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o: CMakeFiles/proyectoArquiU3y4.dir/flags.make
CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o: /home/arturo/CLionProjects/proyectoArquiU3y4/main.cpp
CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o: CMakeFiles/proyectoArquiU3y4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o -MF CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o.d -o CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o -c /home/arturo/CLionProjects/proyectoArquiU3y4/main.cpp

CMakeFiles/proyectoArquiU3y4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proyectoArquiU3y4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arturo/CLionProjects/proyectoArquiU3y4/main.cpp > CMakeFiles/proyectoArquiU3y4.dir/main.cpp.i

CMakeFiles/proyectoArquiU3y4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proyectoArquiU3y4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arturo/CLionProjects/proyectoArquiU3y4/main.cpp -o CMakeFiles/proyectoArquiU3y4.dir/main.cpp.s

# Object files for target proyectoArquiU3y4
proyectoArquiU3y4_OBJECTS = \
"CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o"

# External object files for target proyectoArquiU3y4
proyectoArquiU3y4_EXTERNAL_OBJECTS =

proyectoArquiU3y4: CMakeFiles/proyectoArquiU3y4.dir/main.cpp.o
proyectoArquiU3y4: CMakeFiles/proyectoArquiU3y4.dir/build.make
proyectoArquiU3y4: CMakeFiles/proyectoArquiU3y4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyectoArquiU3y4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proyectoArquiU3y4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyectoArquiU3y4.dir/build: proyectoArquiU3y4
.PHONY : CMakeFiles/proyectoArquiU3y4.dir/build

CMakeFiles/proyectoArquiU3y4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proyectoArquiU3y4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proyectoArquiU3y4.dir/clean

CMakeFiles/proyectoArquiU3y4.dir/depend:
	cd /home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arturo/CLionProjects/proyectoArquiU3y4 /home/arturo/CLionProjects/proyectoArquiU3y4 /home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug /home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug /home/arturo/CLionProjects/proyectoArquiU3y4/cmake-build-debug/CMakeFiles/proyectoArquiU3y4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proyectoArquiU3y4.dir/depend

