#!./perl -P

# $Header: comp.cpp,v 2.0 88/06/05 00:12:37 root Exp $

print "1..3\n";

#this is a comment
#define MESS "ok 1\n"
print MESS;

#If you capitalize, it's a comment.
#ifdef MESS
	print "ok 2\n";
#else
	print "not ok 2\n";
#endif

open(try,">Comp.cpp.tmp") || die "Can't open temp perl file.";
print try '$ok = "not ok 3\n";'; print try "\n";
print try "#include <Comp.cpp.inc>\n";
print try "#ifdef OK\n";
print try '$ok = OK;'; print try "\n";
print try "#endif\n";
print try 'print $ok;'; print try "\n";
close try;

open(try,">Comp.cpp.inc") || (die "Can't open temp include file.");
print try '#define OK "ok 3\n"'; print try "\n";
close try;

$pwd=`pwd`;
$pwd =~ s/\n//;
$x = `./perl -P -I$pwd Comp.cpp.tmp`;
print $x;
`/bin/rm -f Comp.cpp.tmp Comp.cpp.inc`;
