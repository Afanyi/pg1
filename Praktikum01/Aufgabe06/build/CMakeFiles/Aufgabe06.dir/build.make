# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stud/Desktop/Praktikum01/Aufgabe06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud/Desktop/Praktikum01/Aufgabe06/build

# Include any dependencies generated for this target.
include CMakeFiles/Aufgabe06.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Aufgabe06.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Aufgabe06.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Aufgabe06.dir/flags.make

CMakeFiles/Aufgabe06.dir/main.cpp.o: CMakeFiles/Aufgabe06.dir/flags.make
CMakeFiles/Aufgabe06.dir/main.cpp.o: /home/stud/Desktop/Praktikum01/Aufgabe06/main.cpp
CMakeFiles/Aufgabe06.dir/main.cpp.o: CMakeFiles/Aufgabe06.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/stud/Desktop/Praktikum01/Aufgabe06/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aufgabe06.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aufgabe06.dir/main.cpp.o -MF CMakeFiles/Aufgabe06.dir/main.cpp.o.d -o CMakeFiles/Aufgabe06.dir/main.cpp.o -c /home/stud/Desktop/Praktikum01/Aufgabe06/main.cpp

CMakeFiles/Aufgabe06.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Aufgabe06.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stud/Desktop/Praktikum01/Aufgabe06/main.cpp > CMakeFiles/Aufgabe06.dir/main.cpp.i

CMakeFiles/Aufgabe06.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Aufgabe06.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stud/Desktop/Praktikum01/Aufgabe06/main.cpp -o CMakeFiles/Aufgabe06.dir/main.cpp.s

# Object files for target Aufgabe06
Aufgabe06_OBJECTS = \
"CMakeFiles/Aufgabe06.dir/main.cpp.o"

# External object files for target Aufgabe06
Aufgabe06_EXTERNAL_OBJECTS =

Aufgabe06: CMakeFiles/Aufgabe06.dir/main.cpp.o
Aufgabe06: CMakeFiles/Aufgabe06.dir/build.make
Aufgabe06: CMakeFiles/Aufgabe06.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/stud/Desktop/Praktikum01/Aufgabe06/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Aufgabe06"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Aufgabe06.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Aufgabe06.dir/build: Aufgabe06
.PHONY : CMakeFiles/Aufgabe06.dir/build

CMakeFiles/Aufgabe06.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Aufgabe06.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Aufgabe06.dir/clean

CMakeFiles/Aufgabe06.dir/depend:
	cd /home/stud/Desktop/Praktikum01/Aufgabe06/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud/Desktop/Praktikum01/Aufgabe06 /home/stud/Desktop/Praktikum01/Aufgabe06 /home/stud/Desktop/Praktikum01/Aufgabe06/build /home/stud/Desktop/Praktikum01/Aufgabe06/build /home/stud/Desktop/Praktikum01/Aufgabe06/build/CMakeFiles/Aufgabe06.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Aufgabe06.dir/depend

