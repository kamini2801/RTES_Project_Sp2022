INCLUDE_DIRS = 
LIB_DIRS = 
CC=gcc

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS= 

HFILES= 
CFILES= process.c

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	process

clean:
	-rm -f *.o *.d
	-rm -f process

process: process.o
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $@.o -lm -lrt

depend:

.c.o:
	$(CC) $(CFLAGS) -c $<