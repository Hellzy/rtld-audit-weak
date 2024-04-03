#include <iostream>
#include <cstring>

#include "bypass.h"

void __attribute__((constructor)) before_main() {
    printf("This function gets executed before main()\n");
}

unsigned int la_version(unsigned int version)
{
    std::cerr << "la_version call: " << version << '\n';
    return LAV_CURRENT;
}

char *la_objsearch(const char* name, uintptr_t *cookie, unsigned int flag)
{
    std::cerr << "la_objsearch call: " << name << '\n';
    //if (!strcmp(name, "libprint.so"))
     //   return "print/libprint.so";//"stub/libstub.so";
    return const_cast<char*>(name);
}

unsigned int la_objopen(link_map* map, Lmid_t lmid, uintptr_t *cookie) {
    std::cerr << "la_objopen call\n";
    return 0;
}

uintptr_t la_symbind32(Elf32_Sym *sym, unsigned int ndx,
                       uintptr_t *refcook, uintptr_t *defcook,
                       unsigned int *flags, const char *symname)
{
    std::cout << "symbind32 for " << sym->st_name << '\n';
    return sym->st_value;
}

uintptr_t la_symbind64(Elf64_Sym *sym, unsigned int ndx,
                       uintptr_t *refcook, uintptr_t *defcook,
                       unsigned int *flags, const char *symname)
{
    std::cout << "symbind64 for " << sym->st_name << '\n';
    return sym->st_value;
}

Elf64_Addr la_x86_64_gnu_pltenter (Elf64_Sym *sym,
					  unsigned int ndx,
					  uintptr_t *refcook,
					  uintptr_t *defcook,
					  La_x86_64_regs *regs,
					  unsigned int *flags,
					  const char *symname,
					  long int *framesizep)
{
    std::cout << "plt enter: " << sym->st_name << '\n';
    return sym->st_value;
}
unsigned int la_x86_64_gnu_pltexit (Elf64_Sym *sym,
					   unsigned int ndx,
					   uintptr_t *refcook,
					   uintptr_t *defcook,
					   const La_x86_64_regs *inregs,
					   La_x86_64_retval *outregs,
					   const char *symname)
{
    std::cout << "plt exit: " << sym->st_name << '\n';
    return 0;
}