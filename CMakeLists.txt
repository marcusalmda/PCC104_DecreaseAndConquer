# CMakeList.txt : CMake project for PCC104_DeacreaseAndConquer_Maplotpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PCC104_DeacreaseAndConquer_Maplotpp")

add_subdirectory (matplotplusplus)

# Add source to this project's executable.
add_executable (PCC104_DeacreaseAndConquer_Maplotpp "PCC104_DeacreaseAndConquer_Maplotpp.cpp" "PCC104_DeacreaseAndConquer_Maplotpp.h")

target_link_libraries (PCC104_DeacreaseAndConquer_Maplotpp PUBLIC matplot)

# TODO: Add tests and install targets if needed.
