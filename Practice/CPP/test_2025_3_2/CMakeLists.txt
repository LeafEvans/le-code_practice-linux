cmake_minimum_required(VERSION 3.20)
project(test_2025_3_2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

find_package(Boost REQUIRED COMPONENTS filesystem system thread)
find_package(TBB REQUIRED)

add_executable(test_2025_3_2 src/main.cc)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(test_2025_3_2 PRIVATE -g)
endif()

target_compile_options(test_2025_3_2 PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(test_2025_3_2 PRIVATE
    TBB::tbb
    Boost::filesystem
    Boost::system
    Boost::thread
)

target_include_directories(test_2025_3_2 PRIVATE
    ${Boost_INCLUDE_DIRS}
)

install(TARGETS test_2025_3_2 DESTINATION bin)
