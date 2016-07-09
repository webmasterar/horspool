ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT =
	endif
endif

CC = gcc
CFLAGS = -msse4.2 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: horspool
	$(CC) $(CFLAGS) -o horspool$(EXT) horspool.o main.o

horspool:
	$(CC) $(CFLAGS) -c horspool.c main.c

clean:
	$(RM) horspool.o main.o horspool$(EXT)
