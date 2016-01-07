#include "projet.h"

void getTableauSymboles(FILE* f, Elf32_Ehdr header_elf, Elf32_Shdr section_elf) 
{

	Elf32_Sym *symboltable;
	int i = 0, symboltable_size = 0;
	fseek(f, symboltable_size, SEEK_SET);

	while(symboltable[i] != '\0')
	{

		fseek(f, symboltable_size, SEEK_SET);
		symboltable = (Elf32_Sym*) malloc(sizeof(Elf32_Sym)+i);

		if(symboltable[i] == ELFDATA2LSB)
		{
			fread(&symbole_elf.st_name, sizeof(uint32_t), 1, f);
		} 

		else if(header_elf.e_ident[5] == ELFDATA2MSB)
		{
			fread(&symbole_elf.st_name, sizeof(uint32_t), 1, f);
			symbole_elf.st_name = __bswap_32(symbole_elf.st_name);
		}

		else
		{
			printf("Section au format de donnée inconnu");
			exit(0);
		}

		symboltable[i] = symbole_elf;
		symboltable_size += 1;
		i += 1;
	}
	
}



