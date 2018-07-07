c := Sqrt.c

ccopts := -I./
ccopts += -march=native
ccopts += -O3
ccopts += -ffast-math
# ccopts += -funroll-all-loops
ccopts += -D CPUSPEED_MHZ=2900
CC := gcc

all : c

c :
	$(CC) -o $(patsubst %.c,%,$(c))-c $(ccopts) ./$(c)
	