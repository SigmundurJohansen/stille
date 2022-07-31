cmake_minimum_required(VERSION 3.22.2)
project(Simulation VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
find_package(Vulkan REQUIRED)

add_subdirectory(external/avarice)
add_executable(Simulation src/main.cpp)


target_link_libraries(${PROJECT_NAME} PUBLIC Avarice)

target_include_directories(Simulation
        PUBLIC
        Avarice
        VulkanMemoryAllocator
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_BINARY_DIR}"
    )
