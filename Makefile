CFLAGS = -g -Wall -Werror

all: main
main: main.o
	gcc $^ -g -o main

%.o: %.c input_error.h types.h
	gcc $< -c $(CFLAGS) -o $@
clean:
	rm -f *.o main

