# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/lab6_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/lab6_autogen.dir/ParseCache.txt"
  "CMakeFiles/untitled10_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/untitled10_autogen.dir/ParseCache.txt"
  "lab6_autogen"
  "untitled10_autogen"
  )
endif()