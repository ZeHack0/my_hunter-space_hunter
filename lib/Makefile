##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## .
##

LIB = libmy.a

SRC = src/mini_printf.c
SRC += src/my_atoi.c
SRC += src/my_char_isalpha.c
SRC += src/my_compute_power_rec.c
SRC += src/my_compute_square_root.c
SRC += src/my_convert_int_to_char.c
SRC += src/my_find_prime_sup.c
SRC += src/my_getnbr.c
SRC += src/my_is_prime.c
SRC += src/my_isneg.c
SRC += src/my_len_int.c
SRC += src/my_power.c
SRC += src/my_put_hexa.c
SRC += src/my_put_nbr.c
SRC += src/my_put_octal.c
SRC += src/my_putchar.c
SRC += src/my_putstr.c
SRC += src/my_revstr.c
SRC += src/my_sort_in_array.c
SRC += src/my_str_isalpha.c
SRC += src/my_str_islower.c
SRC += src/my_str_isnum.c
SRC += src/my_str_isupper.c
SRC += src/my_str_to_word_array.c
SRC += src/my_strcat.c
SRC += src/my_strcmp.c
SRC += src/my_strcpy.c
SRC += src/my_strdup.c
SRC += src/my_strlen.c
SRC += src/my_strlowcase.c
SRC += src/my_strncat.c
SRC += src/my_strncmp.c
SRC += src/my_strncpy.c
SRC += src/my_strstr.c
SRC += src/my_strupcase.c
SRC += src/my_swap.c

CC := gcc

BUILD_DIR := .build

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

CFLAGS = -Wall -Wextra -g -I include/

GRE := \033[0;32m
GRA := \033[0;37m
BLU := \033[0;34m
RED := \033[0;31m

all: $(LIB)
.PHONY: all

$(LIB): $(OBJ)
	@ $(AR) rc ./libmy.a $(OBJ)
	@ echo -e "$(BLU)===--- $(GRE)Compiled$(GRA) < $@ > $(BLU)---===$(GRA)"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c -o $@ $<
	@ echo -e "$(GRE)Compiled$(GRA) $<"

clean:
	@ $(RM) $(SRC:.c=.gcda)
	@ $(RM) $(SRC:.c=.gcno)
	@ $(RM) $(OBJ) $(TOBJ)
	@ $(RM) *.0
	@ echo -e "$(RED)Cleaned$(GRA)"

fclean: clean
	@ $(RM) $(LIB)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM) *.0
	@ echo -e "$(RED)Force cleaned$(GRA)"

.PHONY: clean fclean

re: fclean
	@ $(MAKE) all -j --no-print-directory

.PHONY: re
