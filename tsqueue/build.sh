#!/bin/bash

# 如果 build 目录不存在则创建
if [ ! -d "build" ]; then
  mkdir build
fi

cd build || exit 1

# 运行 cmake 和 make
cmake ..
make

# 返回上级目录（可选）
cd ..
