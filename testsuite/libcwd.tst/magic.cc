// $Header$
//
// Copyright (C) 2000, by
// 
// Carlo Wood, Run on IRC <carlo@alinoe.com>
// RSA-1024 0x624ACAD5 1997-01-26                    Sign & Encrypt
// Fingerprint16 = 32 EC A7 B6 AC DB 65 A6  F6 F6 55 DD 1C DC FF 61
//
// This file may be distributed under the terms of the Q Public License
// version 1.0 as appearing in the file LICENSE.QPL included in the
// packaging of this file.
//

#include "libcw/sys.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>
#include <unistd.h>
#include "libcw/debug.h"

RCSTAG_CC("$Id$")

int main(void)
{
  Debug( check_configuration() );

  // Don't show allocations that are allocated before main()
  make_all_allocations_invisible_except(NULL);

  // Select channels
  Debug( dc::malloc.off() );

  // Write debug output to cout
  Debug( libcw_do.set_ostream(&cout) );

  // Turn debug object on
  Debug( libcw_do.on() );

  int* p = new int[4];
  AllocTag(p, "Test array");
  Debug( list_allocations_on(libcw_do) );
  p[4] = 5;

  pid_t pid = fork();
  if (pid == -1)
    DoutFatal(error_cf, "fork");
  if (pid == 0)
  {
    // This must core dump:
    delete[] p;
    DoutFatal(dc::fatal, "This should not be reached!");
  }
  // Parent process
  int status;
  exit((pid == wait(&status) && WIFSIGNALED(status)) ? 0 : 1);
}