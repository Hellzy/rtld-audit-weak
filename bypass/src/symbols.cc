#include <iostream>
#include "symbols.h"

void* symInfo::getAddr(Elf64_Sym* sym)
{
    return nullptr;
}

char* symInfo::getName(Elf64_Sym* sym)
{
    return ((char*)this->strtab) + sym->st_name;
}

symInfoPtr_t getSymInfo(Elf64_Dyn* section, uintptr_t base_addr)
{
    Elf64_Sym *symtab = NULL;
    char *strtab = NULL;

    // Iterate through dynamic entries to find symbol and string tables
    for (Elf64_Dyn *entry = section; entry->d_tag != DT_NULL; ++entry)
    {
        switch (entry->d_tag)
        {
        case DT_SYMTAB:
            symtab = (Elf64_Sym *)(base_addr + entry->d_un.d_ptr);
            break;
        case DT_STRTAB:
            strtab = (char *)(base_addr + entry->d_un.d_ptr);
            break;
            // Handle other dynamic tags as needed
        }
    }

    if (!symtab || !strtab)
    {
        std::cerr << "Symbol table or string table not found\n";
        return nullptr;
    }

    std::cerr << "Symbol/String table found\n";
    std::cerr << "Symtab: " << strtab << '\n';
    return std::make_shared<symInfo>(symtab, strtab);

}