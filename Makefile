
srcfiles := src/database.c src/graph_handling.c src/main.c src/visualization.c

.PHONY: all
all: $(srcfiles)
	gcc $(srcfiles) -o bin/main -lraylib -Wall
