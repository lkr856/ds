#!/bin/bash
# 创建构建目录并进入
mkdir build
cd build
rm -rf *


# 运行 CMake 配置项目
cmake ..

# 构建项目
cmake --build .