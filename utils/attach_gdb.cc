// $Header$
//
// Copyright (C) 2003, by
//
// Carlo Wood, Run on IRC <carlo@alinoe.com>
// RSA-1024 0x624ACAD5 1997-01-26                    Sign & Encrypt
// Fingerprint16 = 32 EC A7 B6 AC DB 65 A6  F6 F6 55 DD 1C DC FF 61
//
// This file may be distributed under the terms of the Q Public License
// version 1.0 as appearing in the file LICENSE.QPL included in the
// packaging of this file.
//

#include "sys.h"
#include "cwd_debug.h"
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fstream>

int libcwd_attach_gdb_hook = 0;

namespace libcw {
  namespace debug {

void attach_gdb(void)
{
  pid_t pid1 = getpid();
  std::ofstream f;
  f.open("gdb.cmds");
  f << "b *" << __builtin_return_address(0) << "\nset libcwd_attach_gdb_hook=0\nc\n";
  f.close();
  char format[256];
  Dout(dc::always, "konsole_command = \"" << rcfile.konsole_command() << "\".");
  size_t len = snprintf(format, sizeof(format), "%s %s", rcfile.konsole_command().c_str(), "-x gdb.cmds /proc/%u/exe %u");
  if (len >= sizeof(format))
    DoutFatal(dc::fatal, "rcfile: value of keyword 'xterm' too long (" << rcfile.konsole_command());
  char command[512];
  Dout(dc::always, "format = \"" << format << "\".");
  Dout(dc::always, "gdb_bin = \"" << rcfile.gdb_bin() << "\".");
  len = snprintf(command, sizeof(command), format, rcfile.gdb_bin().c_str(), pid1, pid1);
  Dout(dc::always, "command = \"" << command << "\".");
  if (len >= sizeof(command))
    DoutFatal(dc::fatal, "rcfile: value of keyword 'gdb' too long (" << rcfile.gdb_bin());
  libcwd_attach_gdb_hook = 1;
  pid_t pid2 = fork();
  switch(pid2)
  {
    case -1:
      DoutFatal(dc::fatal|error_cf, "fork()");
    case 0:
    {
      system(command);
      exit(0);
    }
    default:
    {
      struct timespec t = { 0, 100000000 };
      while (libcwd_attach_gdb_hook)
	nanosleep(&t, NULL);
      Dout(dc::always, "ATTACHED!");
    }
  }
}

  } // namespace debug
} // namespace libcw