# 自动查找源文件并存储在 SRC_UTILS 变量中
aux_source_directory(. SRC_UTILS)

# 创建共享库 config
# 使用 SRC_UTILS 变量中的所有源文件构建库
add_library(config SHARED ${SRC_UTILS})
add_library(log SHARED ${SRC_UTILS})


# 如果有外部依赖项，可以在这里添加
# target_link_libraries(config PRIVATE external_lib)