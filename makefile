all: main.c
	gcc main.c -o main `pkg-config --cflags --libs gobject-2.0`
