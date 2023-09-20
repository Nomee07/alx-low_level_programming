#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

#define ELF_ERROR_CODE 98

/**
 * showElfHeaderInfo - Displays info from the elf header
 * @header: Pointer to the header structure.
 */

void showElfHeaderInfo(const Elf64_Ehdr *header)
{
	int i = 0;

	printf("Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\nClass: %d-bit\n", header->e_ident[EI_CLASS]
			== ELFCLASS32 ? 32 : 64);
	printf("Data: %s-endian\n", header->e_ident[EI_DATA]
			== ELFDATA2LSB ? "Little" : "Big");
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header->e_type);
	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command line args
 * @argv: Array of command line args string
 * Return: Elf_ERROR_CODE or 0 on success
 */

int main(int argc, char *argv[])
{
	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (ELF_ERROR_CODE);
	}

	if (fd == -1)
	{
		perror("Error opening file");
		return (ELF_ERROR_CODE);
	}

	if (bytes_read != sizeof(header))
	{
		perror("Error reading ELF header");
		close(fd);
		return (ELF_ERROR_CODE);
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (ELF_ERROR_CODE);
	}

	showElfHeaderInfo(&header);
	close(fd);
	return (0);
}
