// type exact
DEBUG   : Disabled
NOTICE  : Enabled
WARNING : Disabled
SYSTEM  : Enabled
MALLOC  : Disabled
BFD     : Disabled
FOO     : Enabled
BAR     : Enabled
RUN     : Enabled
===========================================================================
 Unnested tests

---------------------------------------------------------------------------
NOTICE  : This is a single line
---------------------------------------------------------------------------
NOTICE  : This is a single line
---------------------------------------------------------------------------
NOTICE  : This is a single line with an error message behind it: 0 (Success)
---------------------------------------------------------------------------
[31mNOTICE  : This is a single line with an error message behind it written to cerr: 0 (Success)
[0m===========================================================================
 Simple nests

---------------------------------------------------------------------------
FOO     :     Inside `nested_foo()'
NOTICE  : `nested_foo(0, 0)' returns the string "Foo" when I call it.
---------------------------------------------------------------------------
[31mFOO     :     Inside `nested_foo()'
[0mNOTICE  : `nested_foo(0, 1)' returns the string "Foo" when I call it.
---------------------------------------------------------------------------
FOO     :     Inside `nested_foo()': 0 (Success)
NOTICE  : `nested_foo(1, 0)' returns the string "Foo" when I call it.
---------------------------------------------------------------------------
[31mFOO     :     Inside `nested_foo()': 0 (Success)
[0mNOTICE  : `nested_foo(1, 1)' returns the string "Foo" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()'
FOO     :         Inside `nested_foo()'
BAR     :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
BAR     :     Leaving `nested_bar()'
NOTICE  : `nested_bar(0, 0, 0, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()'
[31mFOO     :         Inside `nested_foo()'
[0mBAR     :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
BAR     :     Leaving `nested_bar()'
NOTICE  : `nested_bar(0, 0, 0, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()'
FOO     :         Inside `nested_foo()': 0 (Success)
BAR     :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
BAR     :     Leaving `nested_bar()'
NOTICE  : `nested_bar(0, 0, 1, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()'
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mBAR     :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
BAR     :     Leaving `nested_bar()'
NOTICE  : `nested_bar(0, 0, 1, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()'
[0m[31mFOO     :         Inside `nested_foo()'
BAR     :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
[0m[31mBAR     :     Leaving `nested_bar()'
[0mNOTICE  : `nested_bar(0, 1, 0, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()'
[0m[31mFOO     :         Inside `nested_foo()'
BAR     :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
[0m[31mBAR     :     Leaving `nested_bar()'
[0mNOTICE  : `nested_bar(0, 1, 0, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()'
[0m[31mFOO     :         Inside `nested_foo()': 0 (Success)
BAR     :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
[0m[31mBAR     :     Leaving `nested_bar()'
[0mNOTICE  : `nested_bar(0, 1, 1, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()'
[0m[31mFOO     :         Inside `nested_foo()': 0 (Success)
BAR     :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
[0m[31mBAR     :     Leaving `nested_bar()'
[0mNOTICE  : `nested_bar(0, 1, 1, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
FOO     :         Inside `nested_foo()'
BAR     :     `nested_foo(0, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  : `nested_bar(1, 0, 0, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
[31mFOO     :         Inside `nested_foo()'
[0mBAR     :     `nested_foo(0, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  : `nested_bar(1, 0, 0, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
FOO     :         Inside `nested_foo()': 0 (Success)
BAR     :     `nested_foo(1, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  : `nested_bar(1, 0, 1, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
BAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mBAR     :     `nested_foo(1, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  : `nested_bar(1, 0, 1, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :         Inside `nested_foo()'
BAR     :     `nested_foo(0, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  : `nested_bar(1, 1, 0, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :         Inside `nested_foo()'
BAR     :     `nested_foo(0, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  : `nested_bar(1, 1, 0, 1)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :         Inside `nested_foo()': 0 (Success)
BAR     :     `nested_foo(1, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  : `nested_bar(1, 1, 1, 0)' returns the string "Bar" when I call it.
---------------------------------------------------------------------------
[31mBAR     :     Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :         Inside `nested_foo()': 0 (Success)
BAR     :     `nested_foo(1, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :     Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  : `nested_bar(1, 1, 1, 1)' returns the string "Bar" when I call it.
===========================================================================
 Continued tests, single depth

---------------------------------------------------------------------------
RUN     : Hello World
---------------------------------------------------------------------------
RUN     : Libcw is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :     Single interruption before.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
FOO     :     Single interruption after.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :     Single interruption before and
RUN     : <continued> is an awesome <unfinished>
FOO     :     a single interruption after.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :     Double interruption before,
FOO     :     double means two lines.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
FOO     :     Double interruption after,
FOO     :     double means two lines.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :     Double interruption before and
FOO     :     (double means two lines)
RUN     : <continued> is an awesome <unfinished>
FOO     :     a double interruption after
FOO     :     (double means two lines)
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()'
NOTICE  :     `nested_foo(0, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()'
[0mNOTICE  :     `nested_foo(0, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
FOO     :         Inside `nested_foo()': 0 (Success)
NOTICE  :     `nested_foo(1, 0)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> is an awesome <unfinished>
[31mFOO     :         Inside `nested_foo()': 0 (Success)
[0mNOTICE  :     `nested_foo(1, 1)' returns the string "Foo" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()'
FOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()'
[31mFOO     :             Inside `nested_foo()'
[0mBAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()'
FOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()'
[31mFOO     :             Inside `nested_foo()': 0 (Success)
[0mBAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
FOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[31mFOO     :             Inside `nested_foo()'
[0mBAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
FOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[31mFOO     :             Inside `nested_foo()': 0 (Success)
[0mBAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> is an awesome library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()'
FOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()'
[31mFOO     :             Inside `nested_foo()'
[0mBAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()'
FOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()'
[31mFOO     :             Inside `nested_foo()': 0 (Success)
[0mBAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.
BAR     :         Leaving `nested_bar()'
NOTICE  :     `nested_bar(0, 0, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()'
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.
[0m[31mBAR     :         Leaving `nested_bar()'
[0mNOTICE  :     `nested_bar(0, 1, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
FOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[31mFOO     :             Inside `nested_foo()'
[0mBAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
FOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
BAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[31mFOO     :             Inside `nested_foo()': 0 (Success)
[0mBAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
BAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
NOTICE  :     `nested_bar(1, 0, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 0, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()'
BAR     :         `nested_foo(0, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 0, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 0)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 1, 0)' returns the string "Bar" when I call it.
RUN     : <continued> library!
---------------------------------------------------------------------------
RUN     : Libcw is an awesome <unfinished>
[31mBAR     :         Entering `nested_bar()': EINVAL (Invalid argument)
[0m[31mFOO     :             Inside `nested_foo()': 0 (Success)
BAR     :         `nested_foo(1, 1)' returns the string "Foo" when I call it.: EINVAL (Invalid argument)
[0m[31mBAR     :         Leaving `nested_bar()': EINVAL (Invalid argument)
[0mNOTICE  :     `nested_bar(1, 1, 1, 1)' returns the string "Bar" when I call it.
RUN     : <continued> library!
===========================================================================
 Continued tests, deep

RUN     :     1<unfinished>
FOO     :             Inside `nested_foo()'
RUN     :             1<unfinished>
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mRUN     :                     1<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 2<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 3
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mFOO     :                 Foo3:3Foo
RUN     :             <continued> 2<unfinished>
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mRUN     :                     1<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 2<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 3
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mFOO     :                 Foo3:3Foo
RUN     :             <continued> 3
FOO     :             Inside `nested_foo()'
FOO     :         Foo4:4Foo
RUN     :     <continued> 2<unfinished>
FOO     :             Inside `nested_foo()'
RUN     :             1<unfinished>
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mRUN     :                     1<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 2<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 3
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mFOO     :                 Foo3:3Foo
RUN     :             <continued> 2<unfinished>
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mRUN     :                     1<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 2<unfinished>
FOO     :                             Inside `nested_foo()': 0 (Success)
RUN     :                             1<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 2<unfinished>
[31mFOO     :                                     Inside `nested_foo()'
[0mFOO     :                                     Inside `nested_foo()': 0 (Success)
FOO     :                                 Foo1BOTTOM1Foo
RUN     :                             <continued> 3
[31mFOO     :                             Inside `nested_foo()'
[0mFOO     :                         Foo2:2Foo
RUN     :                     <continued> 3
[31mFOO     :                     Inside `nested_foo()': 0 (Success)
[0mFOO     :                 Foo3:3Foo
RUN     :             <continued> 3
FOO     :             Inside `nested_foo()'
FOO     :         Foo4:4Foo
RUN     :     <continued> 3
NOTICE  : :