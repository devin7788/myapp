#!/bin/bash

set -e  # 脚本出错即退出

echo "==> 开始构建项目..."
./build.sh

echo "==> 进入 build 目录，执行测试..."
cd build
ctest --output-on-failure
