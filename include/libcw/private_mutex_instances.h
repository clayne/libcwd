// $Header$
//
// Copyright (C) 2001 - 2002, by
//
// Carlo Wood, Run on IRC <carlo@alinoe.com>
// RSA-1024 0x624ACAD5 1997-01-26                    Sign & Encrypt
// Fingerprint16 = 32 EC A7 B6 AC DB 65 A6  F6 F6 55 DD 1C DC FF 61
//
// This file may be distributed under the terms of the Q Public License
// version 1.0 as appearing in the file LICENSE.QPL included in the
// packaging of this file.
// 

/** \file libcw/private_mutex_instances.h
 * Do not include this header file directly, instead include "\ref preparation_step2 "debug.h"".
 */

#ifndef LIBCW_PRIVATE_MUTEX_INSTANCES_H
#define LIBCW_PRIVATE_MUTEX_INSTANCES_H

#if LIBCWD_THREAD_SAFE

namespace libcw {
  namespace debug {
    namespace _private_ {

// The different instance-ids used in libcwd.
enum mutex_instance_nt {
  // Recursive mutexes.
  tsd_initialization_instance,
  object_files_instance,	// rwlock
  end_recursive_types,
  // Fast mutexes.
  memblk_map_instance,
  location_cache_instance,	// rwlock
  threadlist_instance,
  mutex_initialization_instance,
  ids_singleton_tct_S_ids_instance,
  alloc_tag_desc_instance,
  type_info_of_instance,
  dlopen_map_instance,
  write_max_len_instance,
  set_ostream_instance,
  kill_threads_instance,
  debug_objects_instance,	// rwlock
  debug_channels_instance,	// rwlock
  list_allocations_instance,
  // Values reserved for read/write locks.
  reserved_instance_low,
  reserved_instance_high = 3 * reserved_instance_low,
  // Values reserved for test executables.
  test_instance0 = reserved_instance_high,
  test_instance1,
  test_instance2,
  test_instance3,
  instance_locked_size		// Must be last in list
};

#if CWDEBUG_DEBUG
extern int instance_locked[instance_locked_size];	// MT: Each element is locked by the
							//     corresponding instance.
#if CWDEBUG_DEBUGT
extern pthread_t locked_by[instance_locked_size];	// The id of the thread that last locked it, or 0 when that thread unlocked it.
extern void const* locked_from[instance_locked_size];	// and where is was locked.
#endif
__inline__ bool is_locked(int instance) { return instance_locked[instance] > 0; }
#endif

    } // namespace _private_
  } // namespace debug
} // namespace libcw

#endif // LIBCWD_THREAD_SAFE
#endif // LIBCW_PRIVATE_MUTEX_INSTANCES_H
