CFLAGS = -g -Wall -Werror

all: run
run: main.o load.o move.o
	gcc $^ -g -o run

%.o: %.c input_error.h types.h
	gcc $< -c $(CFLAGS) -o $@
clean:
	rm -f *.o run

