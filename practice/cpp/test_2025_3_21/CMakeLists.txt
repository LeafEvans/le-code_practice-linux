cmake_minimum_required(VERSION 3.10.0)
project(test_2025_3_21 VERSION 0.1.0 LANGUAGES C CXX)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS system filesystem)

add_executable(test_2025_3_21 main.cpp)

target_link_libraries(test_2025_3_21 PRIVATE
  Boost::system
  Boost::filesystem
)

set_target_properties(test_2025_3_21 PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)