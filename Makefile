CC=g++

CFLAGS= -Wall -Werror -Wextra

SRC=main.cpp

OUT=main

$(OUT):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f *.o $(OUT)
