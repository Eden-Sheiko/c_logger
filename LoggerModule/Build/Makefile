# === Variables ===
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I../Inc
TARGET = logger_test

SRC_DIR = ../Src
TEST_DIR = ../Tests

SRCS = $(SRC_DIR)/Logger.c $(TEST_DIR)/main.c

# === Build Rules ===
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
