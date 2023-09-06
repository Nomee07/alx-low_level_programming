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
	int i;

	printf("Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}

	printf("\n");

	printf("Class:                             %s\n", header->e_ident[EI_CLASS]
			== ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:                              %s\n", header->e_ident[EI_DATA] ==
			ELFDATA2LSB ? "2's complement, little-endian" :
			"2's complement, big-endian");
	printf("Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("OS/ABI:                            %d\n",
			header->e_ident[EI_OSABI]);
	printf("ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %s\n",
			header->e_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
	printf("Entry point address:               %#lx\n",
			(unsigned long)header->e_entry);
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
	print_elf_info(&header);
	close(fd);
	return (0);
}
