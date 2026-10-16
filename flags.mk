##
## EPITECH PROJECT, 2023
## __
## File description:
## flags.mk
##

CFLAGS := -std=gnu11

CFLAGS += -fdiagnostics-generate-patch
CFLAGS += -fno-builtin
CFLAGS += -fno-tree-loop-distribute-patterns

CFLAGS += -pipe

CFLAGS += -O2
CFLAGS += -Wno-format-security
CFLAGS += -march=native
CFLAGS += -mtune=native

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Winit-self
CFLAGS += -Winline
CFLAGS += -Wredundant-decls
CFLAGS += -Wshadow
CFLAGS += -Wstrict-overflow=2
CFLAGS += -Wundef
CFLAGS += -Wunreachable-code
CFLAGS += -Wwrite-strings
CFLAGS += -pedantic
CFLAGS += -lm

CFLAGS += -iquote ./include -iquote ./lib/include -g

LDFLAGS += -L ./lib
LDFLAGS += -lhephaestos
LDFLAGS += -g

CSFML += -lcsfml-graphics
CSFML += -lcsfml-system
CSFML += -lcsfml-audio
CSFML += -lcsfml-window
