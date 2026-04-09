# CMakeList.txt: gCFPM_demo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。

# CMake最低版本
cmake_minimum_required(VERSION 3.15)

# 项目名
project("Helloworld" VERSION 0.0.1 LANGUAGES CXX)

# 把整个项目默认的 C++ 标准设置为 C++20
set(CMAKE_CXX_STANDARD 20)
# 必须用 C++20，不允许降级
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 不用编译器私有扩展
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找 ArrayFire 包
find_package(ArrayFire REQUIRED)

if(ArrayFire_CPU_FOUND)
    # 将源代码添加到此项目的可执行文件。
    add_executable(Helloworld_cpu "src/Helloworld.cpp")
    target_link_libraries(Helloworld_cpu ArrayFire::afcpu)

    add_library(Helloworld_cpudll SHARED src/Helloworld.cpp)
    target_link_libraries(Helloworld_cpudll ArrayFire::afcpu)
endif()

if(ArrayFire_CUDA_FOUND)
    # 将源代码添加到此项目的可执行文件。
    add_executable(Helloworld_cuda "src/Helloworld.cpp" )
    target_link_libraries(Helloworld_cuda ArrayFire::afcuda)

    add_library(Helloworld_cudadll SHARED src/Helloworld.cpp)
    target_link_libraries(Helloworld_cudadll ArrayFire::afcuda)
endif()



