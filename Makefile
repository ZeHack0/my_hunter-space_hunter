##
## EPITECH PROJECT, 2024
## starting_project
## File description:
## Makefile
##

include sources.mk
include flags.mk

NAME = space_hunter

CC := gcc

BUILD_DIR := .build

OBJ := $(src:%.c=.build/%.o)

LDFLAGS = -L./lib/ -lmy

GRE := \033[0;32m
GRA := \033[0;37m
BLU := \033[0;34m
RED := \033[0;31m

all:
	@ cd lib/ && $(MAKE) -j --no-print-directory
	@ $(MAKE) $(NAME) -j --no-print-directory

$(NAME): $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS) $(CSFML)
	@ echo -e "$(BLU)===--- $(GRE)Compiled$(GRA) < $@ > $(BLU)---===$(GRA)"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)
	@ echo -e "$(GRE)Compiled$(GRA) $<"

clean:
	@ cd lib/ && $(MAKE) clean -j --no-print-directory
	@ $(RM) $(SRC:.c=.gcda)
	@ $(RM) $(SRC:.c=.gcno)
	@ $(RM) $(OBJ) $(TOBJ)
	@ $(RM) *.a
	@ echo -e "$(RED)Cleaned$(GRA)"

fclean: clean
	@ cd lib/ && $(MAKE) fclean -j --no-print-directory
	@ $(RM) $(NAME)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM) *.a
	@ echo -e "$(RED)Force cleaned$(GRA)"

.PHONY: clean fclean

re: fclean
	@ cd lib/ && $(MAKE) fclean --no-print-directory
	@ $(MAKE) all -j --no-print-directory

.PHONY: re

docker:
	@ docker build -t space_hunter .
	@ cp docker/space_hunter.sh $(NAME) && chmod +x $(NAME)
	@ printf "$(BLU)===--- $(GRE)Docker image ready$(GRA) < ./$(NAME) > $(BLU)---===$(GRA)\n"

.PHONY: re docker
