#include "projet.h"


Elf32_Ehdr recupEnTete(FILE* f){
	Elf32_Ehdr header_elf;
	int i;
	
	for(i = 0; i<16;i++){
		fread(&header_elf.e_ident[i], 1, 1, f); 
	}
	
	if(header_elf.e_ident[5] == ELFDATA2LSB){
		fread(&header_elf.e_type, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_machine, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_version, sizeof(uint32_t), 1, f);
		fread(&header_elf.e_entry, sizeof(uint32_t), 1, f);
		fread(&header_elf.e_phoff, sizeof(uint32_t), 1, f);
		fread(&header_elf.e_shoff, sizeof(uint32_t), 1, f);
		fread(&header_elf.e_flags, sizeof(uint32_t), 1, f);
		fread(&header_elf.e_ehsize, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_phentsize, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_phnum, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_shentsize, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_shnum, sizeof(uint16_t), 1, f);
		fread(&header_elf.e_shstrndx, sizeof(uint16_t), 1, f);
	}else if(header_elf.e_ident[5] == ELFDATA2MSB){
		fread(&header_elf.e_type, sizeof(uint16_t), 1, f);
		header_elf.e_type = __bswap_16(header_elf.e_type);
		fread(&header_elf.e_machine, sizeof(uint16_t), 1, f);
		header_elf.e_machine = __bswap_16(header_elf.e_machine);
		fread(&header_elf.e_version, sizeof(uint32_t), 1, f);
		header_elf.e_version = __bswap_32(header_elf.e_version);
		fread(&header_elf.e_entry, sizeof(uint32_t), 1, f);
		header_elf.e_entry = __bswap_32(header_elf.e_entry);
		fread(&header_elf.e_phoff, sizeof(uint32_t), 1, f);
		header_elf.e_phoff = __bswap_32(header_elf.e_phoff);
		fread(&header_elf.e_shoff, sizeof(uint32_t), 1, f);
		header_elf.e_shoff = __bswap_32(header_elf.e_shoff);
		fread(&header_elf.e_flags, sizeof(uint32_t), 1, f);
		header_elf.e_flags = __bswap_32(header_elf.e_flags);
		fread(&header_elf.e_ehsize, sizeof(uint16_t), 1, f);
		header_elf.e_ehsize = __bswap_16(header_elf.e_ehsize);
		fread(&header_elf.e_phentsize, sizeof(uint16_t), 1, f);
		header_elf.e_phentsize = __bswap_16(header_elf.e_phentsize);
		fread(&header_elf.e_phnum, sizeof(uint16_t), 1, f);
		header_elf.e_phnum = __bswap_16(header_elf.e_phnum);
		fread(&header_elf.e_shentsize, sizeof(uint16_t), 1, f);
		header_elf.e_shentsize = __bswap_16(header_elf.e_shentsize);
		fread(&header_elf.e_shnum, sizeof(uint16_t), 1, f);
		header_elf.e_shnum = __bswap_16(header_elf.e_shnum);
		fread(&header_elf.e_shstrndx, sizeof(uint16_t), 1, f);
		header_elf.e_shstrndx = __bswap_16(header_elf.e_shstrndx);
	}else{
		printf("Format de donnée inconnu");
		exit(0);
	}
	
	return header_elf;
}


void affichage_enTete(Elf32_Ehdr header_elf){
	
	int i;
	
	printf("e_ident (identifiant du fichier) : ");
	for(i=0;i<16;i++){
		if(header_elf.e_ident[i]/16 == 0){
			printf(" 0%x", header_elf.e_ident[i]);
		}else{
			printf(" %x",header_elf.e_ident[i]);
		}
	}
	printf(" \n");



	printf("Type du fichier: ");
	switch(header_elf.e_type){
		case ET_NONE :
			printf("type de fichier inconnu");
			break;
		case ET_REL :
			printf("fichier repositionnable");
			break;
		case ET_EXEC :
			printf("fichier exécutable");
			break;
		case ET_DYN :
			printf("fichier objet partagé");
			break;
		case 4 :
			printf("Fichier core");
			break;
		default :
			printf("Erreur");
			break;

	}
	printf("\n");

	printf("Machine: ");
	switch(header_elf.e_machine){
		case EM_NONE :
			printf("inconne");
			break;
		case EM_M32 :
			printf("AT&T WE 32100");
			break;
		case EM_SPARC :
			printf("Sun Microsystems SPARC");
			break;
		case EM_386 :
			printf("Intel 80386");
			break;
		case EM_68K :
			printf("Motorola 68000");
			break;
		case EM_88K :
			printf("Motorola 88000");
			break;
		case EM_860 :
			printf("Intel 80860");
			break;
		case EM_MIPS :
			printf("MIPS RS3000");
			break;
		case EM_PARISC :
			printf("HP/PA");
			break;
		case EM_SPARC32PLUS :
			printf("SPARC avec jeu d'instruction étendu");
			break;
		case EM_PPC :
			printf("PowerPC");
			break;
		case EM_PPC64 :
			printf("PowerPC 64 bits");
			break;
		case EM_S390 :
			printf("BM S/390");
			break;
		case EM_ARM :
			printf("Machines de technologies RISc avancées");
			break;
		case EM_SH :
			printf("Renesas SuperH");
			break;
		case EM_SPARCV9 :
			printf("Machine : SPARCC v9 64 bits");
			break;
		case EM_IA_64 :
			printf("Intel Itanium");
			break;
		case EM_X86_64 :
			printf("AMD x86-64");
			break;
		case EM_VAX :
			printf("DEC Vax");
			break;
		default :
			printf("Erreur");
			break;

	}
	printf("\n");
	printf("Version: ");
	switch(header_elf.e_version){
		case EV_NONE :
			printf("non valable");
			break;
		case EV_CURRENT :
			printf("actuelle");
			break;
	}
	
	printf("Taille de l'en-tête du fichier : %d\n", header_elf.e_ehsize);
	
	printf("Point d'entrée : 0x%x\n",header_elf.e_entry);

	printf("Offset table de contenant l'en-tête du programme : %d\n", header_elf.e_phoff);

	printf("Offset table des en-têtes de section : %d\n", header_elf.e_shoff);

	printf("Flags : 0x%x\n",header_elf.e_flags);

	printf("Taille des sections : %d (bytes)\n",header_elf.e_shentsize);

	printf("Nombre de sections : %d\n",header_elf.e_shnum);

	printf("Indice des en-têtes de sections : %d\n",header_elf.e_shstrndx);

	printf("Taille d'une entrée de la table d'en tête : %d\n", header_elf.e_phentsize);

	printf("Nombre d'entrée de la table d'en tête : %d\n", header_elf.e_phnum);

}
