# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BinarySearchTree.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BinarySearchTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinarySearchTree.dir/flags.make

CMakeFiles/BinarySearchTree.dir/main.c.obj: CMakeFiles/BinarySearchTree.dir/flags.make
CMakeFiles/BinarySearchTree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BinarySearchTree.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BinarySearchTree.dir\main.c.obj -c C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\main.c

CMakeFiles/BinarySearchTree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BinarySearchTree.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\main.c > CMakeFiles\BinarySearchTree.dir\main.c.i

CMakeFiles/BinarySearchTree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BinarySearchTree.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\main.c -o CMakeFiles\BinarySearchTree.dir\main.c.s

# Object files for target BinarySearchTree
BinarySearchTree_OBJECTS = \
"CMakeFiles/BinarySearchTree.dir/main.c.obj"

# External object files for target BinarySearchTree
BinarySearchTree_EXTERNAL_OBJECTS =

BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/main.c.obj
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/build.make
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/linklibs.rsp
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/objects1.rsp
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BinarySearchTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BinarySearchTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinarySearchTree.dir/build: BinarySearchTree.exe
.PHONY : CMakeFiles/BinarySearchTree.dir/build

CMakeFiles/BinarySearchTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BinarySearchTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BinarySearchTree.dir/clean

CMakeFiles/BinarySearchTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\cmake-build-debug C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\cmake-build-debug C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\BinarySearchTree\cmake-build-debug\CMakeFiles\BinarySearchTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BinarySearchTree.dir/depend
