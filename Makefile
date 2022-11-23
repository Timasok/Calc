I_FLAG := -I./include/ -I./lib/stack/include/ -I./lib/ #-I./inc/

CC:= g++
CFLAGS :=  -g -fsanitize=address # -Wall $(I_FLAG)

SRC_DIR := ./src/
LIB_DIR := ./lib/
SRC_STK := ./lib/stack/src/

SOURCES 	:= calc.cpp calc_f.cpp text_funcs.cpp
EXECUTABLE  := calc

all:
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)