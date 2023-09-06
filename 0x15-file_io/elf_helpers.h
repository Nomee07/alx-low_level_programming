#ifndef ELF_HELPERS_H
#define ELF_HELPERS_H

#define ELFOSABI_SORTIX 100
#define ELFOSABI_SPARC 101

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

void print_magic(const unsigned char *magic);
void print_class(const unsigned char elf_class);
void print_data(const unsigned char data);
void print_osabi(unsigned char osabi);
void print_abi_version(unsigned char abi_version);
void print_elf_type(unsigned int elf_type);
void print_entry_point(unsigned long entry_point);

#endif
