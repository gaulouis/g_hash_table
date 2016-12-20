all: main.c
	gcc `pkg-config --cflags --libs gobject-2.0` main.c -o main
