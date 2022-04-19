INCLUDE_DIRS = 
LIB_DIRS = 
CC=gcc

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS= 

HFILES= 
CFILES= trig.c process.c

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	trig process

clean:
	-rm -f *.o *.d
	-rm -f trig

trig: trig.o
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $@.o -lm -lrt

process: process.o
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $@.o -lm -lrt

depend:

.c.o:
	$(CC) $(CFLAGS) -c $<