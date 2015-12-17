ROOT=..
#PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines

PROGS =	3-1 3-2 3-5 3-11

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
