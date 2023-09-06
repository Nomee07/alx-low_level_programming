#include "elf_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * print_elf_info - Prints information from the ELF header.
 * @header: Pointer to the header structure.
 */

void print_elf_info(const Elf64_Ehdr *header)
{
	print_magic(header->e_ident);
	print_class(header->e_ident[EI_CLASS]);
	print_data(header->e_ident[EI_DATA]);
	print_osabi(header->e_ident[EI_OSABI]);
}

/**
 * print_magic - Prints the elf magic bytes.
 * @magic: Pointer to the magic bytes array.
 */
void print_magic(const unsigned char *magic)
{
	int i;

	printf("Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", magic[i]);
	}

	printf("\n");
}

/**
 * print_class - Prints the elf class (32 bit or 64 bit).
 * @elf_class: Class value.
 */
void print_class(const unsigned char elf_class)
{
	printf("Class:                             %s\n",
			elf_class == ELFCLASS32 ? "ELF32" :
			(elf_class == ELFCLASS64 ? "ELF64" : "Unknown"));
}

/**
 * print_data - Prints the elf data encoding (little or big endian).
 * @data: The data value.
 */
void print_data(const unsigned char data)
{
	printf("Data:                              %s\n",
			data == ELFDATA2LSB ? "2's complement, little-endian" :
			(data == ELFDATA2MSB ? "2's complement, big-endian" : "Unknown"));
}

/**
 * print_version - Prints the elf version.
 * @version: The elf version.
 */
void print_version(const unsigned char version)
{
	printf("Version:                           %d (current)\n",
			version);
}
