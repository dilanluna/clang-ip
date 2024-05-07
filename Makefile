CC = gcc
CFLAGS = -Wall
SOURCE_FILES = $(wildcard src/*c)

build:
	$(CC) $(CFLAGS) -I $(CURDIR) -o output/ip $(SOURCE_FILES)

