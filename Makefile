GTK_CFLAGS = $(shell pkg-config --cflags gtk4)
GTK_LIBS = $(shell pkg-config --libs gtk4)

all: main

main: main.c
gcc main.c -o main $(GTK_CFLAGS) $(GTK_LIBS)