cmake_minimum_required(VERSION 3.12)
project(grammer)

set(CMAKE_CXX_STANDARD 11)


find_package(Boost REQUIRED COMPONENTS system)

add_executable(ReactorDemo ./src/ReactorDemo.cpp)
target_include_directories(ReactorDemo PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(ReactorDemo PRIVATE ${Boost_LIBRARIES})
set_target_properties(ReactorDemo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(ProactorDemo ./src/ProactorDemo.cpp)
target_include_directories(ProactorDemo PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(ProactorDemo PRIVATE ${Boost_LIBRARIES})
set_target_properties(ProactorDemo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Friend ./src/friendFuncAndClass.cpp)
set_target_properties(Friend PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

