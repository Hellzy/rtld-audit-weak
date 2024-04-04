#pragma once

#include <elf.h>
#include <memory>

struct symInfo {
    symInfo() = default;
    symInfo(Elf64_Sym* symt, void* strt): symtab(symt), strtab(strt){}

    char* getName(Elf64_Sym*);
    void* getAddr(Elf64_Sym*);

private:
    Elf64_Sym *symtab = nullptr;
    void *strtab = nullptr;
};
using symInfoPtr_t = std::shared_ptr<symInfo>;

symInfoPtr_t getSymInfo(Elf64_Dyn* section, uintptr_t base_addr);