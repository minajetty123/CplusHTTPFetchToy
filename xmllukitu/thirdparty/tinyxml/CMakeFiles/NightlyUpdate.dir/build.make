# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/cmake-3.23.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.23.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tom/fetch_lukitu/xmllukitu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tom/fetch_lukitu/xmllukitu

# Utility rule file for NightlyUpdate.

# Include any custom commands dependencies for this target.
include thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/compiler_depend.make

# Include the progress variables for this target.
include thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/progress.make

thirdparty/tinyxml/CMakeFiles/NightlyUpdate:
	cd /home/tom/fetch_lukitu/xmllukitu/thirdparty/tinyxml && /opt/cmake-3.23.1-linux-x86_64/bin/ctest -D NightlyUpdate

NightlyUpdate: thirdparty/tinyxml/CMakeFiles/NightlyUpdate
NightlyUpdate: thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/build.make
.PHONY : NightlyUpdate

# Rule to build all files generated by this target.
thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/build: NightlyUpdate
.PHONY : thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/build

thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/clean:
	cd /home/tom/fetch_lukitu/xmllukitu/thirdparty/tinyxml && $(CMAKE_COMMAND) -P CMakeFiles/NightlyUpdate.dir/cmake_clean.cmake
.PHONY : thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/clean

thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/depend:
	cd /home/tom/fetch_lukitu/xmllukitu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tom/fetch_lukitu/xmllukitu /home/tom/fetch_lukitu/xmllukitu/thirdparty/tinyxml /home/tom/fetch_lukitu/xmllukitu /home/tom/fetch_lukitu/xmllukitu/thirdparty/tinyxml /home/tom/fetch_lukitu/xmllukitu/thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/tinyxml/CMakeFiles/NightlyUpdate.dir/depend

