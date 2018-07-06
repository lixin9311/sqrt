c := Sqrt.c

ccopts := -I./
ccopts += -march=native
ccopts += -O3
ccopts += -D CPUSPEED_MHZ=2900
CC := gcc

all : c

c :
	$(CC) -o $(patsubst %.c,%,$(c))-c $(ccopts) ./$(c)
