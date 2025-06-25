# 编译器与参数
CC = gcc
CFLAGS = -Wall -Iinclude -Isrc/math -Isrc/utils

# 目录结构
SRC_DIR = src
MATH_DIR = $(SRC_DIR)/math
UTILS_DIR = $(SRC_DIR)/utils
BUILD_DIR = build
BIN_DIR = bin

# 源码与目标文件列表
SRCS = $(SRC_DIR)/main.c $(MATH_DIR)/math.c $(UTILS_DIR)/utils.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# 最终二进制
TARGET = $(BIN_DIR)/app

# 默认目标
all: $(TARGET)

# 链接生成最终程序
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# 编译每个 .c 文件为对应 .o，保持目录结构
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理规则
.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
