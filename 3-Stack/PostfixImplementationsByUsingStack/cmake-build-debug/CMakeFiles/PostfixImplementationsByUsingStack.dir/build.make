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
CMAKE_SOURCE_DIR = C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PostfixImplementationsByUsingStack.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PostfixImplementationsByUsingStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PostfixImplementationsByUsingStack.dir/flags.make

CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.obj: CMakeFiles/PostfixImplementationsByUsingStack.dir/flags.make
CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PostfixImplementationsByUsingStack.dir\main.c.obj -c C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\main.c

CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\main.c > CMakeFiles\PostfixImplementationsByUsingStack.dir\main.c.i

CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\main.c -o CMakeFiles\PostfixImplementationsByUsingStack.dir\main.c.s

# Object files for target PostfixImplementationsByUsingStack
PostfixImplementationsByUsingStack_OBJECTS = \
"CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.obj"

# External object files for target PostfixImplementationsByUsingStack
PostfixImplementationsByUsingStack_EXTERNAL_OBJECTS =

PostfixImplementationsByUsingStack.exe: CMakeFiles/PostfixImplementationsByUsingStack.dir/main.c.obj
PostfixImplementationsByUsingStack.exe: CMakeFiles/PostfixImplementationsByUsingStack.dir/build.make
PostfixImplementationsByUsingStack.exe: CMakeFiles/PostfixImplementationsByUsingStack.dir/linklibs.rsp
PostfixImplementationsByUsingStack.exe: CMakeFiles/PostfixImplementationsByUsingStack.dir/objects1.rsp
PostfixImplementationsByUsingStack.exe: CMakeFiles/PostfixImplementationsByUsingStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PostfixImplementationsByUsingStack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PostfixImplementationsByUsingStack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PostfixImplementationsByUsingStack.dir/build: PostfixImplementationsByUsingStack.exe
.PHONY : CMakeFiles/PostfixImplementationsByUsingStack.dir/build

CMakeFiles/PostfixImplementationsByUsingStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PostfixImplementationsByUsingStack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PostfixImplementationsByUsingStack.dir/clean

CMakeFiles/PostfixImplementationsByUsingStack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\cmake-build-debug C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\cmake-build-debug C:\Users\halim\OneDrive\Desktop\DataStructures\Kitap\PostfixImplementationsByUsingStack\cmake-build-debug\CMakeFiles\PostfixImplementationsByUsingStack.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PostfixImplementationsByUsingStack.dir/depend

