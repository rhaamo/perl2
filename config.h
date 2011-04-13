/* config.h
 * This file was produced by running the config.h.SH script, which
 * gets its values from config.sh, which is generally produced by
 * running Configure.
 *
 * Feel free to modify any of this as the need arises.  Note, however,
 * that running config.h.SH again will wipe out any changes you've made.
 * For a more permanent change edit config.sh and rerun config.h.SH.
 */


/* EUNICE:
 *	This symbol, if defined, indicates that the program is being compiled
 *	under the EUNICE package under VMS.  The program will need to handle
 *	things like files that don't go away the first time you unlink them,
 *	due to version numbering.  It will also need to compensate for lack
 *	of a respectable link() command.
 */
/* VMS:
 *	This symbol, if defined, indicates that the program is running under
 *	VMS.  It is currently only set in conjunction with the EUNICE symbol.
 */
//#undef	EUNICE		/**/
//#undef	VMS		/**/

/* CPPSTDIN:
 *	This symbol contains the first part of the string which will invoke
 *	the C preprocessor on the standard input and produce to standard
 *	output.	 Typical value of "cc -E" or "/lib/cpp".
 */
/* CPPMINUS:
 *	This symbol contains the second part of the string which will invoke
 *	the C preprocessor on the standard input and produce to standard
 *	output.  This symbol will have the value "-" if CPPSTDIN needs a minus
 *	to specify standard input, otherwise the value is "".
 */
#define CPPSTDIN "/usr/bin/cpp"
#define CPPMINUS ""

/* BCOPY:
 *	This symbol, if defined, indicates that the bcopy routine is available
 *	to copy blocks of memory.  Otherwise you should probably use memcpy().
 */
#define	BCOPY		/**/

/* CRYPT:
 *	This symbol, if defined, indicates that the crypt routine is available
 *	to encrypt passwords and the like.
 */
#define	CRYPT		/**/

/* DOSUID:
 *	This symbol, if defined, indicates that the C program should
 *	check the script that it is executing for setuid/setgid bits, and
 *	attempt to emulate setuid/setgid on systems that have disabled
 *	setuid #! scripts because the kernel can't do it securely.
 *	It is up to the package designer to make sure that this emulation
 *	is done securely.  Among other things, it should do an fstat on
 *	the script it just opened to make sure it really is a setuid/setgid
 *	script, it should make sure the arguments passed correspond exactly
 *	to the argument on the #! line, and it should not trust any
 *	subprocesses to which it must pass the filename rather than the
 *	file descriptor of the script to be executed.
 */
//#undef DOSUID		/**/

/* FCHMOD:
 *	This symbol, if defined, indicates that the fchmod routine is available
 *	to change mode of opened files.  If unavailable, use chmod().
 */
//#undef	FCHMOD		/**/

/* FCHOWN:
 *	This symbol, if defined, indicates that the fchown routine is available
 *	to change ownership of opened files.  If unavailable, use chown().
 */
//#undef	FCHOWN		/**/

/* GETGROUPS:
 *	This symbol, if defined, indicates that the getgroups() routine is
 *	available to get the list of process groups.  If unavailable, multiple
 *	groups are probably not supported.
 */
//#undef	GETGROUPS		/**/

/* KILLPG:
 *	This symbol, if defined, indicates that the killpg routine is available
 *	to kill process groups.  If unavailable, you probably should use kill
 *	with a negative process number.
 */
#define	KILLPG		/**/

/* MEMCPY:
 *	This symbol, if defined, indicates that the memcpy routine is available
 *	to copy blocks of memory.  Otherwise you should probably use bcopy().
 *	If neither is defined, roll your own.
 */
#define	MEMCPY		/**/

/* RENAME:
 *	This symbol, if defined, indicates that the rename routine is available
 *	to rename files.  Otherwise you should do the unlink(), link(), unlink()
 *	trick.
 */
#define	RENAME		/**/

/* SETEGID:
 *	This symbol, if defined, indicates that the setegid routine is available
 *	to change the effective gid of the current program.
 */
#define	SETEGID		/**/

/* SETEUID:
 *	This symbol, if defined, indicates that the seteuid routine is available
 *	to change the effective uid of the current program.
 */
#define	SETEUID		/**/

/* SETRGID:
 *	This symbol, if defined, indicates that the setrgid routine is available
 *	to change the real gid of the current program.
 */
//#undef	SETRGID		/**/

/* SETRUID:
 *	This symbol, if defined, indicates that the setruid routine is available
 *	to change the real uid of the current program.
 */
//#undef	SETRUID		/**/

/* STATBLOCKS:
 *	This symbol is defined if this system has a stat structure declaring
 *	st_blksize and st_blocks.
 */
//#undef	STATBLOCKS 	/**/

/* STDSTDIO:
 *	This symbol is defined if this system has a FILE structure declaring
 *	_ptr and _cnt in stdio.h.
 */
//#undef	STDSTDIO 	/**/

/* STRCSPN:
 *	This symbol, if defined, indicates that the strcspn routine is available
 *	to scan strings.
 */
#define	STRCSPN		/**/

/* STRUCTCOPY:
 *	This symbol, if defined, indicates that this C compiler knows how
 *	to copy structures.  If undefined, you'll need to use a block copy
 *	routine of some sort instead.
 */
#define	STRUCTCOPY	/**/

/* SYMLINK:
 *	This symbol, if defined, indicates that the symlink routine is available
 *	to create symbolic links.
 */
//#undef	SYMLINK		/**/

/* TMINSYS:
 *	This symbol is defined if this system declares "struct tm" in
 *	in <sys/time.h> rather than <time.h>.  We can't just say
 *	-I/usr/include/sys because some systems have both time files, and
 *	the -I trick gets the wrong one.
 */
//#undef	TMINSYS 	/**/

/* vfork:
 *	This symbol, if defined, remaps the vfork routine to fork if the
 *	vfork() routine isn't supported here.
 */
#define	vfork fork	/**/

/* VOIDSIG:
 *	This symbol is defined if this system declares "void (*signal())()" in
 *	signal.h.  The old way was to declare it as "int (*signal())()".  It
 *	is up to the package author to declare things correctly based on the
 *	symbol.
 */
#define	VOIDSIG 	/**/

/* GIDTYPE:
 *	This symbol has a value like gid_t, int, ushort, or whatever type is
 *	used to declare group ids in the kernel.
 */
#define GIDTYPE gid_t		/**/

/* STDCHAR:
 *	This symbol is defined to be the type of char used in stdio.h.
 *	It has the values "unsigned char" or "char".
 */
#define STDCHAR char	/**/

/* UIDTYPE:
 *	This symbol has a value like uid_t, int, ushort, or whatever type is
 *	used to declare user ids in the kernel.
 */
#define UIDTYPE uid_t		/**/

/* VOIDFLAGS:
 *	This symbol indicates how much support of the void type is given by this
 *	compiler.  What various bits mean:
 *
 *	    1 = supports declaration of void
 *	    2 = supports arrays of pointers to functions returning void
 *	    4 = supports comparisons between pointers to void functions and
 *		    addresses of void functions
 *
 *	The package designer should define VOIDUSED to indicate the requirements
 *	of the package.  This can be done either by #defining VOIDUSED before
 *	including config.h, or by defining defvoidused in Myinit.U.  If the
 *	level of void support necessary is not present, defines void to int.
 */
#ifndef VOIDUSED
#define VOIDUSED 7
#endif
#define VOIDFLAGS 7
#if (VOIDFLAGS & VOIDUSED) != VOIDUSED
#define void int		/* is void to be avoided? */
#define M_VOID		/* Xenix strikes again */
#endif

/* PRIVLIB:
 *	This symbol contains the name of the private library for this package.
 *	The library is private in the sense that it needn't be in anyone's
 *	execution path, but it should be accessible by the world.
 */
#define PRIVLIB "/usr/local/lib/perl"		/**/

