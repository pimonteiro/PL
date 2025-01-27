#  / ____| |  \/  |   /\   | |/ /  ____|  ____|_   _| |    |  ____|
# | |      | \  / |  /  \  | ' /| |__  | |__    | | | |    | |__
# | |      | |\/| | / /\ \ |  < |  __| |  __|   | | | |    |  __|
# | |____  | |  | |/ ____ \| . \| |____| |     _| |_| |____| |____
#  \_____| |_|  |_/_/    \_\_|\_\______|_|    |_____|______|______|
#
#

SHELL       = /bin/sh
detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
BIN_NAME    = prog
CC          = gcc
LD          = gcc `pkg-config --libs glib-2.0`
CFLAGS      = -Wall -Wextra -Wno-unused-parameter -pedantic -g -O0 `pkg-config --cflags glib-2.0`
DEBUG		= 1


#ifeq ($(DEBUG), yes)
#	CFLAGS += -O0 -g
#else
#	CFLAGS += -O2
#endif

# ____  ____  _     _____  ____  ____  _    _
#/   _\/  _ \/ \  //__ __\/  __\/  _ \/ \  / \
#|  /  | / \|| |\ || / \  |  \/|| / \|| |  | |
#|  \__| \_/|| | \|| | |  |    /| \_/|| |_/\ |_/\
#\____/\____/\_/  \| \_/  \_/\_\\____/\____|____/


SRC_DIR    = src
BIN_DIR    = bin
BUILD_DIR  = build
SRC        = $(wildcard $(SRC_DIR)/*.c)
OBJ        = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS       = $(patsubst $(BUILD_DIR)/%.o,$(BUILD_DIR)/%.d,$(OBJ))
DOC_DIR    = docs/
PROGRAM    = program

vpath %.c $(SRC_DIR)

# ____  _     _    _________
#/  __\/ \ /\/ \  /  __/ ___\
#|  \/|| | ||| |  |  \ |    \
#|    /| \_/|| |_/\  /_\___ |
#\_/\_\\____/\____|____\____/

.DEFAULT_GOAL = all

.PHONY: run fmt doc checkdirs all clean

$(BUILD_DIR)/%.d: %.c
	$(CC) -M $(CFLAGS) $(INCLUDES) $< -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(BIN_DIR)/$(BIN_NAME): $(DEPS) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

run:
	@./$(BIN_DIR)/$(BIN_NAME)

fmt:
	@astyle --style=google -nr *.c,*.h

doc:
	@doxygen Doxyfile

checkdirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

all: checkdirs $(BIN_DIR)/$(BIN_NAME)

clean:
	@echo "Cleaning..."
	@echo ""
	@rm -rd $(BUILD_DIR)/* $(BIN_DIR)/*
	@rm -rd $(DOC_DIR)/*
	@echo ""
	@echo "...✓ done!"

prepare:
	@flex ngen.l
	@yacc -d ngen.y
	@mv lex.yy.c y.tab.c y.tab.h src/
