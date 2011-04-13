# $Header: Makefile.SH,v 2.0 88/06/05 00:15:31 root Exp $
#
# $Log:	Makefile.SH,v $
# Revision 2.0  88/06/05  00:15:31  root
# Baseline version 2.0.
#
#

CC = cc
bin = /usr/local/bin
lib =
mansrc = /usr/man/man1
manext = 1
CFLAGS =  -O
LDFLAGS =

libs =  -lm

public = a2p s2p

private =

manpages = a2p.man s2p.man

util =

h = EXTERN.h INTERN.h config.h handy.h hash.h a2p.h str.h util.h

c = hash.c str.c util.c walk.c

obj = hash.o str.o util.o walk.o

lintflags = -phbvxac

addedbyconf = Makefile.old bsd eunice filexp loc pdp11 usg v7

.c.o:
	$(CC) -c $(CFLAGS) $*.c

all: $(public) $(private) $(util)
	echo "done"

a2p: $(obj) a2p.o
	$(CC) $(LDFLAGS) $(obj) a2p.o $(libs) -o a2p

a2p.c: a2p.y
	@ echo Expect 103 shift/reduce errors...
	yacc a2p.y
	mv y.tab.c a2p.c

a2p.o: a2p.c a2py.c a2p.h EXTERN.h util.h INTERN.h handy.h ../config.h
	$(CC) -c $(CFLAGS) a2p.c

install: a2p s2p
	echo "need to be written"
	exit

clean:
	rm -f *.o

realclean:
	rm -f a2p *.orig */*.orig *.o core $(addedbyconf)

# The following lint has practically everything turned on.  Unfortunately,
# you have to wade through a lot of mumbo jumbo that can't be suppressed.
# If the source file has a /*NOSTRICT*/ somewhere, ignore the lint message
# for that spot.

lint:
	lint $(lintflags) $(defs) $(c) > a2p.fuzz

