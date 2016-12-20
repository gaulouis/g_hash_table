all: main.c
	gcc dummy.c main.c -o main `pkg-config --cflags --libs gobject-2.0`
