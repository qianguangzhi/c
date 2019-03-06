#!/bin/bash -x
CC = gcc
CFLAGS = -Wall -g -O0

INC_DIR = -I include
SRCEXT = .c
TARGET_C = client
TARGET_S = server

BIN_DIR = bin
OBJ_DIR = obj

SRC_DIR = $(patsubst ./%,%,$(shell find . -type d))

vpath %.c $(SRC_DIR)
vpath %.h ./include

SRC_C = $(foreach dir,$(SRC_DIR),$(wildcard $(addprefix $(dir)/*,$(SRCEXT))))
OBJ_O = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(notdir $(SRC_C))))
OBJ_name = $(patsubst %.c,%.o,$(notdir $(SRC_C)))

OBJ_C = $(filter-out $(OBJ_DIR)/server.o,$(OBJ_O))
OBJ_S = $(filter-out $(OBJ_DIR)/client.o,$(OBJ_O))

all: Make CHECKDIR $(OBJ_name) $(OBJ_O) $(BIN_DIR)/$(TARGET_C) $(BIN_DIR)/$(TARGET_S) ECHO 
Make:
			@echo Making...
CHECKDIR:
			@mkdir -p $(SUB_DIR) $(BIN_DIR) $(OBJ_DIR)
$(OBJ_name):%.o:%.c  
			@$(CC) -c $(CFLAGS) $(INC_DIR) $< -o $(OBJ_DIR)/$@ -lpthread

$(OBJ_O):$(OBJS_name)
			@cp $(*F).o $(OBJ_DIR)/

$(BIN_DIR)/$(TARGET_C):$(OBJ_C)
			@$(CC) $(CFLAGS) $(INC_DIR) $^ -o $@ -lpthread

$(BIN_DIR)/$(TARGET_S):$(OBJ_S)
			@$(CC) $(CFLAGS) $(INC_DIR) $^ -o $@ -lpthread
ECHO:
			@echo All directory : $(SRC_DIR) $(notdir $(.)) 
			@echo Make completed!

.PHONY:clean
clean:
	@$(RM) $(BIN_DIR) $(OBJ_DIR) -rf
