SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
INCLUDES := $(shell find $(SRC_DIR) -type d)
CFLAGS := -Wall $(foreach dir,$(INCLUDES),-I$(dir))

all: $(BIN_DIR)/app

$(BIN_DIR)/app: $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)/app
