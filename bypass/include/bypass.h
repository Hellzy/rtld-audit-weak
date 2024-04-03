#pragma once

#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif

#include <link.h>

unsigned int la_version(unsigned int version);
char *la_objsearch(const char* name, uintptr_t *cookie, unsigned int flag);
unsigned int la_objopen(link_map* map, Lmid_t lmid, uintptr_t *cookie);