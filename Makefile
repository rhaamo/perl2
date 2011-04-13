# $Header: Makefile.SH,v 2.0.1.1 88/06/28 16:26:04 root Exp $
#
# $Log:	Makefile.SH,v $
# Revision 2.0.1.1  88/06/28  16:26:04  root
# patch1: support for DOSUID
# patch1: realclean now knows about ~ extension
#
# Revision 2.0  88/06/05  00:07:54  root
# Baseline version 2.0.
#
#

CC?= cc
bin = /usr/local/bin
lib = /usr/local/lib/perl
mansrc = /usr/man/man1
manext = 1
CFLAGS =  -O
LDFLAGS =
SLN = ln

libs =  -lm

public = perl perldb

private =

manpages = perl.man perldb.man

util =

h1 = EXTERN.h INTERN.h arg.h array.h cmd.h config.h form.h handy.h
h2 = hash.h perl.h regexp.h spat.h stab.h str.h util.h
h = $(h1) $(h2)

c1 = arg.c array.c cmd.c dump.c eval.c form.c hash.c
c2 = perly.c regexp.c stab.c str.c toke.c util.c version.c
c = $(c1) $(c2)

obj1 = arg.o array.o cmd.o dump.o eval.o form.o hash.o
obj2 = regexp.o stab.o str.o toke.o util.o version.o
obj = $(obj1) $(obj2)

lintflags = -phbvxac

addedbyconf = Makefile.old bsd eunice filexp loc pdp11 usg v7

.c.o:
	$(CC) -c $(CFLAGS) $*.c

all: $(public) $(private) $(util)
	echo "done"

perl: perly.o $(obj) perl.o
	$(CC) $(LDFLAGS) perly.o $(obj) perl.o $(libs) -o perl


perl.c perly.h: perl.y
	@echo "Expect 37 shift/reduce errors..."
	yacc -d perl.y
	mv y.tab.c perl.c
	mv y.tab.h perly.h

perl.o: perl.c perly.h perl.h EXTERN.h regexp.h util.h INTERN.h handy.h config.h
	$(CC) -c $(CFLAGS) perl.c

perl.man: perl.man.1 perl.man.2
	cat perl.man.1 perl.man.2 >perl.man

install: perl perl.man
	echo "need to be written"
	exit

clean:
	rm -f *.o

realclean:
	rm -f perl *.orig */*.orig *~ */*~ *.o core $(addedbyconf)

bisonclean:
	rm -f perl.c perly.h

# The following lint has practically everything turned on.  Unfortunately,
# you have to wade through a lot of mumbo jumbo that can't be suppressed.
# If the source file has a /*NOSTRICT*/ somewhere, ignore the lint message
# for that spot.

lint: perl.c $(c)
	lint $(lintflags) $(defs) perl.c $(c) > perl.fuzz

test: perl
	chmod +x t/TEST t/base.* t/comp.* t/cmd.* t/io.* t/op.*
	cd t && (rm -f perl; $(SLN) ../perl .) && ./perl TEST

