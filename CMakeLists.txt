cmake_minimum_required(VERSION 3.14)
project(DCCircuitCalculator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(circuit_lib src/dummy.cpp)
target_include_directories(circuit_lib PUBLIC include)

add_executable(kalkulator src/main.cpp)
target_link_libraries(kalkulator PRIVATE circuit_lib)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(unit_tests tests/test_dummy.cpp)
target_link_libraries(unit_tests PRIVATE circuit_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)