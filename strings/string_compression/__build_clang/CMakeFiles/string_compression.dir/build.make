# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/c/vika/leetcode/strings/string_compression

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/vika/leetcode/strings/string_compression/__build_clang

# Include any dependencies generated for this target.
include CMakeFiles/string_compression.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/string_compression.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/string_compression.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/string_compression.dir/flags.make

CMakeFiles/string_compression.dir/main.cpp.o: CMakeFiles/string_compression.dir/flags.make
CMakeFiles/string_compression.dir/main.cpp.o: ../main.cpp
CMakeFiles/string_compression.dir/main.cpp.o: CMakeFiles/string_compression.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/vika/leetcode/strings/string_compression/__build_clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/string_compression.dir/main.cpp.o"
	/usr/bin/clang++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/string_compression.dir/main.cpp.o -MF CMakeFiles/string_compression.dir/main.cpp.o.d -o CMakeFiles/string_compression.dir/main.cpp.o -c /mnt/c/vika/leetcode/strings/string_compression/main.cpp

CMakeFiles/string_compression.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_compression.dir/main.cpp.i"
	/usr/bin/clang++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/vika/leetcode/strings/string_compression/main.cpp > CMakeFiles/string_compression.dir/main.cpp.i

CMakeFiles/string_compression.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_compression.dir/main.cpp.s"
	/usr/bin/clang++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/vika/leetcode/strings/string_compression/main.cpp -o CMakeFiles/string_compression.dir/main.cpp.s

# Object files for target string_compression
string_compression_OBJECTS = \
"CMakeFiles/string_compression.dir/main.cpp.o"

# External object files for target string_compression
string_compression_EXTERNAL_OBJECTS =

string_compression: CMakeFiles/string_compression.dir/main.cpp.o
string_compression: CMakeFiles/string_compression.dir/build.make
string_compression: libstring_compression_lib.a
string_compression: CMakeFiles/string_compression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/vika/leetcode/strings/string_compression/__build_clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable string_compression"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_compression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/string_compression.dir/build: string_compression
.PHONY : CMakeFiles/string_compression.dir/build

CMakeFiles/string_compression.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/string_compression.dir/cmake_clean.cmake
.PHONY : CMakeFiles/string_compression.dir/clean

CMakeFiles/string_compression.dir/depend:
	cd /mnt/c/vika/leetcode/strings/string_compression/__build_clang && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/vika/leetcode/strings/string_compression /mnt/c/vika/leetcode/strings/string_compression /mnt/c/vika/leetcode/strings/string_compression/__build_clang /mnt/c/vika/leetcode/strings/string_compression/__build_clang /mnt/c/vika/leetcode/strings/string_compression/__build_clang/CMakeFiles/string_compression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/string_compression.dir/depend
