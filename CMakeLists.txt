# CMakeList.txt: gCFPM_demo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。

# CMake最低版本
cmake_minimum_required(VERSION 3.15)

# 项目名
project("hellowrold_cpp" VERSION 0.0.1 LANGUAGES CXX)

# 把整个项目默认的 C++ 标准设置为 C++20
set(CMAKE_CXX_STANDARD 20)
# 必须用 C++20，不允许降级
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 不用编译器私有扩展
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找 ArrayFire 包
find_package(ArrayFire  REQUIRED)
# 查找 OpenCV 包
find_package(OpenCV REQUIRED)


# 公共源文件
set(COMMON_SRC
    src/main.cpp
    src/helloworld.cpp
    src/helloworld.h
)


add_executable(hellowrold_cpp ${COMMON_SRC})
target_link_libraries(hellowrold_cpp PRIVATE ArrayFire::afcuda  ${OpenCV_LIBS})

add_library(hellowrold_cpp_dll SHARED src/helloworld.cpp)
target_link_libraries(hellowrold_cpp_dll PRIVATE ArrayFire::afcuda ${OpenCV_LIBS})

# 项目根路径
add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")


# 资源拷贝
file(COPY ${CMAKE_SOURCE_DIR}/images
    DESTINATION ${CMAKE_BINARY_DIR})




