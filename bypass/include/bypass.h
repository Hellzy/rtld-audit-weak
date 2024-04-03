#pragma once

#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif

#include <link.h>

unsigned int la_version(unsigned int version);

char *la_objsearch(const char* name, uintptr_t *cookie, unsigned int flag);

unsigned int la_objopen(link_map* map, Lmid_t lmid, uintptr_t *cookie);

uintptr_t la_symbind32 (Elf32_Sym *sym, unsigned int ndx,
			       uintptr_t *refcook, uintptr_t *defcook,
			       unsigned int *flags, const char *symname);
uintptr_t la_symbind64 (Elf64_Sym *sym, unsigned int ndx,
			       uintptr_t *refcook, uintptr_t *defcook,
			       unsigned int *flags, const char *symname);

Elf64_Addr la_x86_64_gnu_pltenter (Elf64_Sym *sym,
					  unsigned int ndx,
					  uintptr_t *refcook,
					  uintptr_t *defcook,
					  La_x86_64_regs *regs,
					  unsigned int *flags,
					  const char *symname,
					  long int *framesizep);
unsigned int la_x86_64_gnu_pltexit (Elf64_Sym *sym,
					   unsigned int ndx,
					   uintptr_t *refcook,
					   uintptr_t *defcook,
					   const La_x86_64_regs *inregs,
					   La_x86_64_retval *outregs,
					   const char *symname);