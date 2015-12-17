ROOT=..
include $(ROOT)/Make.defines

PROGS =	1-3 1-4 1-5 1-6 1-7 1-8 1-9 1-10

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
