#include <iostream>
#include <cstring>

#include "bypass.h"

unsigned int la_version(unsigned int version)
{
    std::cerr << "la_version call: " << version << '\n';
    return LAV_CURRENT;
}

char *la_objsearch(const char* name, uintptr_t *cookie, unsigned int flag)
{
    std::cerr << "la_objsearch call: " << name << '\n';
    if (!strcmp(name, "libprint.so"))
        return "stub/libstub.so";
    auto newName = (char*)malloc(strlen(name));
    strcpy(newName, name);
    return newName;
}

unsigned int la_objopen(link_map* map, Lmid_t lmid, uintptr_t *cookie) {
    std::cerr << "la_objopen call\n";
    return 0;
}