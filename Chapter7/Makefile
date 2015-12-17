ROOT=..
include $(ROOT)/Make.defines

PROGS = 7-2 7-3 7-4 7-5 7-6 7-7 

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
