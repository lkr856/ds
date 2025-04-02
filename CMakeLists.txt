cmake_minimum_required(VERSION 3.10)
project(MyProject)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加子目录
# add_subdirectory(bst)

# 添加可执行文件
add_executable(MyProject main.cpp base/node.cpp)
# 指定头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE bst)
# 链接库到可执行文件
# target_link_libraries(MyProject PRIVATE BSTLibrary)
# 添加包含目录
# target_include_directories(MyProject PRIVATE ${CMAKE_SOURCE_DIR}/bst)
# 自定义命令：在构建后将 BSTLibrary.dll 复制到可执行文件目录
# add_custom_command(TARGET MyProject POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     "${CMAKE_BINARY_DIR}/bst/Debug/BSTLibrary.dll"  # 源 DLL 文件路径
#     "${CMAKE_BINARY_DIR}/Debug/BSTLibrary.dll")    # 目标 DLL 文件路径


# # DEBUG配置：禁用优化并添加调试信息
# target_compile_options(MyProject PRIVATE "$<$<CONFIG:DEBUG>:/Od>")
# target_compile_options(MyProject PRIVATE "$<$<CONFIG:DEBUG>:/Zi>")


# 为 Debug 配置添加编译选项
target_compile_options(MyProject PRIVATE
    $<$<CONFIG:DEBUG>:-O0>  # 禁用优化
    $<$<CONFIG:DEBUG>:-g>   # 添加调试信息
)
# # RELEASE配置：启用优化
# target_compile_options(MyProject PRIVATE "$<$<CONFIG:RELEASE>:/O2>")

