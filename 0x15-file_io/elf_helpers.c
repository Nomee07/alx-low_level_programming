#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include "elf_helpers.h"

/**
 * print_osabi - Print the ELF OS/ABI.
 * @osabi: The ELF OS/ABI value.
 */

void print_osabi(unsigned char osabi)
{
	printf("OS/ABI:                            ");
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris");
			break;
		case ELFOSABI_SORTIX:
			printf("Sortix");
			break;
		case ELFOSABI_SPARC:
			printf("SPARC big-endian");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone");
			break;
		default:
			printf("Unknown");
			break;
	}
	printf("\n");
}

/**
 * print_abi_version - Print the ABI Version.
 * @abi_version: The ABI Version value.
 */

void print_abi_version(unsigned char abi_version)
{
	printf("ABI Version:                       %d\n", abi_version);
}

/**
 * print_elf_type - Print the ELF Type.
 * @elf_type: The ELF Type value.
 */

void print_elf_type(unsigned int elf_type)
{
	printf("Type:                              %s\n",
			elf_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
}

/**
 * print_entry_point - Print the Entry Point address.
 * @entry_point: The Entry Point address.
 */

void print_entry_point(unsigned long entry_point)
{
	printf("Entry point address:               %#lx\n", entry_point);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line argument strings.
 *
 * Return: 0 on success, 98 on failure.
 */

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	if (bytes_read != sizeof(header) ||
			memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "%s: Not an Elf file\n", argv[1]);
		close(fd);
		exit(98);
	}
	print_elf_type(header.e_type);
	close(fd);
	return (0);
}
