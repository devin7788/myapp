cmake_minimum_required(VERSION 3.26)
project(myserver C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 添加可执行文件及源文件
add_executable(myserver
        main.c
        ts_queue.c
        ts_queue.h
)

# 添加 pthread 库（线程库）
find_package(Threads REQUIRED)
target_link_libraries(myserver PRIVATE Threads::Threads)

# 添加编译选项
target_compile_options(myserver PRIVATE -Wall -Wextra -O2)

# 启用测试
enable_testing()
add_subdirectory(tests)