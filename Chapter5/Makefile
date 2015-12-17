ROOT=..
#PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines

PROGS =	5-1 5-2 5-3 5-4 5-5 

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
