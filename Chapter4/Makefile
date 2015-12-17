ROOT=..
#PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines

PROGS =	4-1 4-2 4-3 4-4 4-5 4-6 4-7 4-8 4-9 4-10

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
