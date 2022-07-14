cmake_minimum_required(VERSION 3.16)
project(Degrees_of_LinkedIn)

set(CMAKE_CXX_STANDARD 14)

# The configure_file statements below ensure that files are copied into the data
# folder that will be created in the build folder.
configure_file(data/links.txt data/links.txt NEWLINE_STYLE UNIX)


# This target is for the main project.  Add in any additional files you need or that you're copying
# over from a previous project.
add_executable(Degrees_of_LinkedIn main.cpp DSVector.h DSLinkedList.h DSAdjacencyList.h DSListNode.h DSString.h DSString.cpp Links.cpp Links.h Paths.h)

# this is the testing target.  Don't include your main driver.cpp file in this target.
add_executable(Degrees_of_LinkedIn_tests DSVector.h catch.hpp  DataStructure_Tests.cpp DSString.cpp DSString.h)