# cmake的最低版本
cmake_minimum_required(VERSION 3.20)

# 项目名称
project(HttpReactor)

# 设置C++标准(c++11)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置编译选项
set (CMAKE_BUILD_TYPE DEBUG)

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")    # 为 Debug 类型设置 -g（生成调试信息），不设置优化\
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")  # 为 Debug 类型设置 -O0（不优化）
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-O2")  # 为 Release 类型设置 -O2（优化）
endif()

# 添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(src)
add_subdirectory(test)