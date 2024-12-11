# 设置最低版本要求
cmake_minimum_required(VERSION 3.10)

# 添加可执行文件
add_executable(logTest LogTest.cpp)

# 添加库文件搜素路径
link_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(logTest PRIVATE log)

