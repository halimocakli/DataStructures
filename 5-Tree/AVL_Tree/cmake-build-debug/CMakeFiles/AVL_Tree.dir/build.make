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
CMAKE_SOURCE_DIR = C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AVL_Tree.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/AVL_Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AVL_Tree.dir/flags.make

CMakeFiles/AVL_Tree.dir/main.c.obj: CMakeFiles/AVL_Tree.dir/flags.make
CMakeFiles/AVL_Tree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AVL_Tree.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AVL_Tree.dir\main.c.obj -c C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\main.c

CMakeFiles/AVL_Tree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AVL_Tree.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\main.c > CMakeFiles\AVL_Tree.dir\main.c.i

CMakeFiles/AVL_Tree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AVL_Tree.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\main.c -o CMakeFiles\AVL_Tree.dir\main.c.s

# Object files for target AVL_Tree
AVL_Tree_OBJECTS = \
"CMakeFiles/AVL_Tree.dir/main.c.obj"

# External object files for target AVL_Tree
AVL_Tree_EXTERNAL_OBJECTS =

AVL_Tree.exe: CMakeFiles/AVL_Tree.dir/main.c.obj
AVL_Tree.exe: CMakeFiles/AVL_Tree.dir/build.make
AVL_Tree.exe: CMakeFiles/AVL_Tree.dir/linklibs.rsp
AVL_Tree.exe: CMakeFiles/AVL_Tree.dir/objects1.rsp
AVL_Tree.exe: CMakeFiles/AVL_Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AVL_Tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AVL_Tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AVL_Tree.dir/build: AVL_Tree.exe
.PHONY : CMakeFiles/AVL_Tree.dir/build

CMakeFiles/AVL_Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AVL_Tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AVL_Tree.dir/clean

CMakeFiles/AVL_Tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\cmake-build-debug C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\cmake-build-debug C:\Users\halim\OneDrive\Desktop\DataStructures\Trees\AVL_Tree\cmake-build-debug\CMakeFiles\AVL_Tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AVL_Tree.dir/depend
