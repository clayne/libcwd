dnl CW_CHECK_STATICLIB(LIBRARY, FUNCTION [, ACTION-IF-FOUND
dnl		 [, ACTION-IF-NOT-FOUND  [, OTHER-LIBRARIES]]])
dnl Like AC_CHECK_LIB but looking for static libraries, however
dnl unlike AC_CHECK_LIB this macro adds OTHER-LIBRARIES to LIBS
dnl when successful.  LIBRARY must be of the form libxxx.a.
AC_DEFUN(CW_CHECK_STATICLIB,
[AC_MSG_CHECKING([for $2 in $1 $5])
dnl Use a cache variable name containing both the library and function name,
dnl because the test really is for library $1 defining function $2, not
dnl just for library $1.  Separate tests with the same $1 and different $2s
dnl may have different results.
ac_lib_var=`echo $1['_']$2 | sed 'y%./+-%__p_%'`
AC_CACHE_VAL(ac_cv_lib_static_$ac_lib_var,
[if test -r /etc/ld.so.conf ; then
  ld_so_paths="/lib /usr/lib `cat /etc/ld.so.conf`"
else
  ld_so_paths="/lib /usr/lib"
fi
for path in $ld_so_paths; do
  ac_save_LIBS="$LIBS"
  LIBS="$path/$1 $5 $LIBS"
  AC_TRY_LINK(dnl
  ifelse(AC_LANG, [FORTRAN77], ,
  ifelse([$2], [main], , dnl Avoid conflicting decl of main.
  [/* Override any gcc2 internal prototype to avoid an error.  */
  ]ifelse(AC_LANG, CPLUSPLUS, [#ifdef __cplusplus
  extern "C"
  #endif
  ])dnl
  [/* We use char because int might match the return type of a gcc2
      builtin and then its argument prototype would still apply.  */
  char $2();
  ])),
	      [$2()],
	      eval "ac_cv_lib_static_$ac_lib_var=\"$path/$1 $5\"",
	      eval "ac_cv_lib_static_$ac_lib_var=no")
  LIBS="$ac_save_LIBS"
  if eval "test \"`echo '$ac_cv_lib_static_'$ac_lib_var`\" != no"; then
    break
  fi
done
])dnl
eval result=\"`echo '$ac_cv_lib_static_'$ac_lib_var`\"
if test "$result" != no; then
  AC_MSG_RESULT([$result])
  ifelse([$3], ,
[changequote(, )dnl
  ac_tr_lib=HAVE_`echo "$1" | sed -e 's/[^a-zA-Z0-9_]/_/g' \
    -e 'y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/'`
changequote([, ])dnl
  AC_DEFINE_UNQUOTED([$ac_tr_lib])
  LIBS="$result $LIBS"
], [$3])
else
  AC_MSG_RESULT(no)
ifelse([$4], , , [$4
])dnl
fi
])

dnl CW_BUG_20000813
dnl
dnl Check whether the compiler has bug #20000813
dnl Set CW_CONFIG_DWARF2OUT_BUG to `define' when this is the case
dnl with the current CXXFLAGS, to `undef' otherwise.
dnl
AC_DEFUN(CW_BUG_20000813,
[changequote(, )dnl
cw_bug_var=`echo " $CXXFLAGS" | sed -e 's/ [^-][^ ]*//g' -e 's/ -[^Ogf][^ ]*//g' \
    -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/' -e 's/ //g' -e 's/[^a-z0-9]/_/g'`
changequote([, ])dnl
AC_MSG_CHECKING([if compiler crashes when we declare a static vector in an inline function])
AC_CACHE_VAL(cw_cv_bug_20000813$cw_bug_var,
AC_TRY_COMPILE(
[#include <vector>
inline void f(void) { static vector<int> ids; }],
[f()], eval "cw_cv_bug_20000813$cw_bug_var=no", eval "cw_cv_bug_20000813$cw_bug_var=yes"))
if eval "test \"`echo '$cw_cv_bug_20000813'$cw_bug_var`\" = no"; then
CW_CONFIG_DWARF2OUT_BUG=undef
AC_MSG_RESULT(no)
else
CW_CONFIG_DWARF2OUT_BUG=define
AC_MSG_RESULT(yes)
fi
AC_SUBST(CW_CONFIG_DWARF2OUT_BUG)
])

dnl CW_BUG_REDEFINES_INITIALIZATION
dnl
AC_DEFUN(CW_BUG_REDEFINES_INITIALIZATION,
[CW_REDEFINES_FIX=
AC_SUBST(CW_REDEFINES_FIX)])

dnl CW_BUG_REDEFINES([HEADERFILE])
dnl
dnl Check whether the HEADERFILE causes macros to be redefined
dnl
AC_DEFUN(CW_BUG_REDEFINES,
[AC_REQUIRE([CW_BUG_REDEFINES_INITIALIZATION])
changequote(, )dnl
cw_bug_var=`echo $1 | sed -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/' -e 's/ //g' -e 's/[^a-z0-9]/_/g'`
changequote([, ])dnl
AC_MSG_CHECKING([if $1 redefines macros])
AC_CACHE_VAL(cw_cv_bug_redefines_$cw_bug_var,
[cat > conftest.$ac_ext <<EOF
#include <$1>
int main() { return 0; }
EOF
save_CXXFLAGS="$CXXFLAGS"
CXXFLAGS="`echo $CXXFLAGS | sed -e 's/-Werror//g'`"
if { (eval echo configure: \"$ac_compile\") 1>&5; (eval $ac_compile) 2>&1 | tee conftest.out >&5; }; then
changequote(, )dnl
  cw_result="`grep 'warning.*redefined' conftest.out | sed -e 's/[^A-Z_]*redefined.*//' -e 's/.*warning.* [^A-Z_]*//'`"
  eval "cw_cv_bug_redefines_$cw_bug_var=\"\$cw_result\""
  cw_result="`grep 'previous.*defin' conftest.out | sed -e 's/:.*//' -e 's%.*include/%%g' | sort | uniq`"
changequote([, ])dnl
  eval "unset cw_cv_bug_redefines_${cw_bug_var}_prev"
  AC_CACHE_VAL(cw_cv_bug_redefines_${cw_bug_var}_prev, [eval "cw_cv_bug_redefines_${cw_bug_var}_prev=\"$cw_result\""])
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  eval "cw_cv_bug_redefines_$cw_bug_var="
  eval "cw_cv_bug_redefines_${cw_bug_var}_prev="
fi
CXXFLAGS="$save_CXXFLAGS"
rm -f conftest*])
eval "cw_redefined_macros=\"\$cw_cv_bug_redefines_$cw_bug_var\""
eval "cw_redefined_from=\"\$cw_cv_bug_redefines_${cw_bug_var}_prev\""
AC_MSG_RESULT($cw_redefined_macros from $cw_redefined_from)
for i in $cw_redefined_from; do
CW_REDEFINES_FIX="$CW_REDEFINES_FIX\\
#include <$i>"
done
for i in $cw_redefined_macros; do
CW_REDEFINES_FIX="$CW_REDEFINES_FIX\\
#undef $i"
done])

dnl CW_OUTPUT([FILE... [, EXTRA_CMDS [, INIT-CMDS]]])
dnl
dnl Like AC_OUTPUT, but preserve the timestamp of the output files
dnl when they are not changed.
dnl
AC_DEFUN(CW_OUTPUT,
[AC_OUTPUT_COMMANDS(
[for cw_outfile in $1; do
  if test -f $cw_outfile.$cw_pid; then
    if cmp -s $cw_outfile $cw_outfile.$cw_pid 2>/dev/null; then
      echo "$cw_outfile is unchanged"
      touch -r $cw_outfile.$cw_pid $cw_outfile
    fi
  fi
  rm -f $cw_outfile.$cw_pid
done], [cw_pid=$cw_pid])
cw_pid=$$
if test "$no_create" != yes; then
  for cw_outfile in $1; do
    if test -f $cw_outfile; then
      mv $cw_outfile $cw_outfile.$cw_pid
    fi
  done
fi
AC_OUTPUT([$1], [$2], [$3])])

dnl CW_DEFINE_TYPE_INITIALIZATION
dnl
AC_DEFUN(CW_DEFINE_TYPE_INITIALIZATION,
[CW_TYPEDEFS=
AC_SUBST(CW_TYPEDEFS)])

dnl CW_DEFINE_TYPE(NEWTYPE, OLDTYPE)
dnl
dnl Add `typedef OLDTYPE NEWTYPE' to the output variable CW_TYPEDEFS
dnl
AC_DEFUN(CW_DEFINE_TYPE,
[AC_REQUIRE([CW_DEFINE_TYPE_INITIALIZATION])
CW_TYPEDEFS="$CW_TYPEDEFS\\
typedef $2 $1;"
])

dnl CW_TYPE_EXTRACT_FROM(FUNCTION, INIT, ARGUMENTS, ARGUMENT)
dnl
dnl Extract the type of ARGUMENT argument of function FUNCTION with ARGUMENTS arguments.
dnl INIT are possibly needed #includes.  The result is put in `cw_result'.
dnl
AC_DEFUN(CW_TYPE_EXTRACT_FROM,
[cat > conftest.$ac_ext <<EOF
[$2]
template<typename ARG>
  void detect_type(ARG)
  {
    return 1;
  }
EOF
echo $ac_n "template<typename ARG0[,] $ac_c" >> conftest.$ac_ext
i=1
while test "$i" != "$3"; do
echo $ac_n "typename ARG$i[,] $ac_c" >> conftest.$ac_ext
i=`echo $i | sed -e 'y/012345678/123456789/'`
done
echo "typename ARG$3>" >> conftest.$ac_ext
echo $ac_n "void foo(ARG0(*f)($ac_c" >> conftest.$ac_ext
i=1
while test "$i" != "$3"; do
echo $ac_n "ARG$i[,] $ac_c" >> conftest.$ac_ext
i=`echo $i | sed -e 'y/012345678/123456789/'`
done
echo "ARG$3)) { ARG$4 arg;" >> conftest.$ac_ext
cat >> conftest.$ac_ext <<EOF
  detect_type(arg);
}
int main(void)
{
  foo($1);
  return 0;
}
EOF
save_CXXFLAGS="$CXXFLAGS"
CXXFLAGS="`echo $CXXFLAGS | sed -e 's/-Werror//g'`"
if { (eval echo configure: \"$ac_compile\") 1>&5; (eval $ac_compile) 2>&1 | tee conftest.out >&5; }; then
changequote(, )dnl
  cw_result="`grep 'detect_type<.*>' conftest.out | sed -e 's/.*detect_type<//g' -e 's/>[^>]*//' | head -n 1`"
changequote([, ])dnl
else
  echo "configure: failed program was:" >&5
  cat conftest.$ac_ext >&5
  AC_MSG_ERROR(Fatal compilation error)
fi
CXXFLAGS="$save_CXXFLAGS"
rm -f conftest*
])

dnl CW_TYPE_SOCKLEN_T
dnl
dnl If `socklen_t' is not defined in sys/socket.h,
dnl define it to be the type of the fifth argument
dnl of `setsockopt'.
dnl
AC_DEFUN(CW_TYPE_SOCKLEN_T,
[AC_CACHE_CHECK(type socklen_t, cw_cv_type_socklen_t,
[AC_EGREP_HEADER(socklen_t, sys/socket.h, cw_cv_type_socklen_t=exists,
[CW_TYPE_EXTRACT_FROM(setsockopt, [#include <sys/socket.h>], 5, 5)
eval "cw_cv_type_socklen_t=\"$cw_result\""])])
if test "$cw_cv_type_socklen_t" != exists; then
  CW_DEFINE_TYPE(socklen_t, [$cw_cv_type_socklen_t])
fi
])

dnl CW_TYPE_OPTVAL_T
dnl
dnl If `optval_t' is not defined in sys/socket.h,
dnl define it to be the type of the fourth argument
dnl of `getsockopt'.
dnl
AC_DEFUN(CW_TYPE_OPTVAL_T,
[AC_CACHE_CHECK(type optval_t, cw_cv_type_optval_t,
[AC_EGREP_HEADER(optval_t, sys/socket.h, cw_cv_type_optval_t=exists,
[CW_TYPE_EXTRACT_FROM(getsockopt, [#include <sys/socket.h>], 5, 4)
eval "cw_cv_type_optval_t=\"$cw_result\""])])
if test "$cw_cv_type_optval_t" != exists; then
  CW_DEFINE_TYPE(optval_t, [$cw_cv_type_optval_t])
fi
])

dnl CW_TYPE_SIGHANDLER_PARAM_T
dnl
dnl If `sighandler_param_t' is not defined in signal.h,
dnl define it to be the type of the the first argument of `SIG_IGN'.
dnl
AC_DEFUN(CW_TYPE_SIGHANDLER_PARAM_T,
[AC_CACHE_CHECK(type sighandler_param_t, cw_cv_type_sighandler_param_t,
[AC_EGREP_HEADER(sighandler_param_t, signal.h, cw_cv_type_sighandler_param_t=exists,
[CW_TYPE_EXTRACT_FROM(SIG_IGN, [#include <signal.h>], 1, 1)
eval "cw_cv_type_sighandler_param_t=\"$cw_result\""])])
if test "$cw_cv_type_sighandler_param_t" != exists; then
  CW_DEFINE_TYPE(sighandler_param_t, [$cw_cv_type_sighandler_param_t])
fi
])

dnl CW_MALLOC_OVERHEAD
dnl
dnl Defines CW_MALLOC_OVERHEAD_C to be the number of bytes extra
dnl allocated for a call to malloc.
dnl
AC_DEFUN(CW_MALLOC_OVERHEAD,
[AC_CACHE_CHECK(malloc overhead in bytes, cw_cv_system_mallocoverhead,
[AC_TRY_RUN([#include <cstdlib>
#include <cstddef>

bool bulk_alloc(size_t malloc_overhead_attempt, size_t size)
{
  int const number = 100;
  long int distance = 9999;
  char* ptr[number];
  ptr[0] = (char*)malloc(size - malloc_overhead_attempt);
  for (int i = 1; i < number; ++i)
  {
    ptr[i] = (char*)malloc(size - malloc_overhead_attempt);
    if (ptr[i] > ptr[i - 1] && (ptr[i] - ptr[i - 1]) < distance)
      distance = ptr[i] - ptr[i - 1];
  }
  for (int i = 0; i < number; ++i)
    free(ptr[i]);
  return (distance == (long int)size);
}

int main(int argc, char* argv[])
{
  if (argc == 1)
    exit(0);	// This wasn't the real rest yet
  for (size_t s = 0; s <= 64; s += 2)
    if (bulk_alloc(s, 2048))
      exit(s);
  exit(8);	// Guess a default
}],
./conftest run
cw_cv_system_mallocoverhead=$?,
[AC_MSG_ERROR(Failed to compile a test program!?)],
cw_cv_system_mallocoverhead=4 dnl Guess a default for cross compiling
)])
eval "CW_MALLOC_OVERHEAD_C=$cw_cv_system_mallocoverhead"
AC_SUBST(CW_MALLOC_OVERHEAD_C)
])

dnl CW_NEED_WORD_ALIGNMENT
dnl
dnl Defines CW_CONFIG_NEED_WORD_ALIGNMENT to `define' or `undef'
dnl when the host needs respectively size_t alignment or not.
AC_DEFUN(CW_NEED_WORD_ALIGNMENT,
[AC_CACHE_CHECK(if machine needs word alignment, cw_cv_system_needwordalignment,
[AC_TRY_RUN([#include <cstddef>
#include <cstdlib>

int main(void)
{
  size_t* p = reinterpret_cast<size_t*>((char*)malloc(5) + 1);
  *p = 0x12345678;
  exit ((((unsigned long)p & 1UL) && *p == 0x12345678) ? 0 : -1);
}],
cw_cv_system_needwordalignment=no,
cw_cv_system_needwordalignment=yes,
cw_cv_system_needwordalignment="why not")])
if test "$cw_cv_system_needwordalignment" = no; then
  CW_CONFIG_NEED_WORD_ALIGNMENT=undef
else
  CW_CONFIG_NEED_WORD_ALIGNMENT=define
fi
AC_SUBST(CW_CONFIG_NEED_WORD_ALIGNMENT)
])

dnl CW_NBLOCK
dnl
dnl Defines CW_CONFIG_NBLOCK to be `POSIX', `BSD' or `SYSV'
dnl depending on whether socket non-blocking stuff is
dnl posix, bsd or sysv style respectively.
AC_DEFUN(CW_NBLOCK,
[AC_CACHE_CHECK(non-blocking socket flavour, cw_cv_system_nblock,
[AC_TRY_RUN([#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <signal.h>
#include <unistd.h>
$ac_cv_type_signal alarmed($cw_cv_type_sighandler_param_t) { exit(1); }
int main(int argc, char* argv[])
{
  if (argc == 1)
    exit(0);
  char b[12];
  struct sockaddr x;
  size_t l = sizeof(x);
  int f = socket(AF_INET, SOCK_DGRAM, 0);
  if (f >= 0 && !(fcntl(f, F_SETFL, (*argv[1] == 'P') ? O_NONBLOCK : O_NDELAY)))
  {
    signal(SIGALRM, alarmed);
    alarm(2);
    recvfrom(f, b, 12, 0, &x, &l);
    alarm(0);
    exit(0);
  }
  exit(1);
}],
[./conftest POSIX
if test "$?" = "0"; then
  cw_cv_system_nblock=POSIX
else
  ./conftest BSD
  if test "$?" = "0"; then
    cw_cv_system_nblock=BSD
  else
    cw_cv_system_nblock=SYSV
  fi
fi],
[AC_MSG_ERROR(Failed to compile a test program!?)],
[cw_cv_system_nblock=crosscompiled_set_to_POSIX_BSD_or_SYSV
AC_CACHE_SAVE
AC_MSG_WARN(Cannot set cw_cv_system_nblock for unknown platform (you are cross-compiling).)
AC_MSG_ERROR(Please edit config.cache and rerun ./configure to correct this!)])])
if test "$cw_cv_system_nblock" = crosscompiled_set_to_POSIX_BSD_or_SYSV; then
  AC_MSG_ERROR(Please edit config.cache and correct the value of cw_cv_system_nblock, then rerun ./configure)
fi
CW_CONFIG_NBLOCK=$cw_cv_system_nblock
AC_SUBST(CW_CONFIG_NBLOCK)
])