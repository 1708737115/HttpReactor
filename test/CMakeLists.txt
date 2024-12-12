# 设置最低版本要求
cmake_minimum_required(VERSION 3.10)

# 添加可执行文件
add_executable(logTest LogTest.cpp)
add_executable(bufferTest BufferTest.cpp)

# 添加库文件搜素路径
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 添加头文件搜索路径
target_include_directories(bufferTest PRIVATE 
    ${PROJECT_SOURCE_DIR}/src/Network
)
target_link_libraries(logTest PRIVATE log)
target_link_libraries(bufferTest PRIVATE Buffer)

