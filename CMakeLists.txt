cmake_minimum_required(VERSION 3.16)
project(robot_control_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(robot_control_system
    main.cpp
    src/common/data.cpp
    src/manager/robot_manager.cpp
    src/robot/robot.cpp
    src/robot/assembly_robot.cpp
    src/robot/welding_robot.cpp
)

target_include_directories(robot_control_system PRIVATE include)
