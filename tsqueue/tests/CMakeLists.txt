# 不再使用 find_package

add_executable(test_ts_queue test_ts_queue.c ../ts_queue.c)

# 查找系统动态库
find_library(CHECK_LIB check REQUIRED)

# 链接 pthread 和 check 库
target_link_libraries(test_ts_queue ${CHECK_LIB} pthread)
