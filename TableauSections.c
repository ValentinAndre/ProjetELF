#include "lectureEnTeteSection.h"


/* 
TODO 

*/

void recupTabsection(FILE* f, Elf32_Ehdr header_elf, Elf32_Shdr *t) 
{

	Elf32_Shdr section_elf;
	//fread(&section_elf, sizeof(Elf32_Ehdr), 1, f);
	int i;
	
	for(i=0; i<header_elf.e_shnum; i++)
	{	

		if(header_elf.e_ident[5] == ELFDATA2LSB)
		{
			fread(&section_elf.sh_name, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_type, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_flags, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_addr, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_offset, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_size, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_link, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_info, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_addralign, sizeof(uint32_t), 1, f);
			fread(&section_elf.sh_entsize, sizeof(uint32_t), 1, f);
		} 

		else if(header_elf.e_ident[5] == ELFDATA2MSB)
		{

			fread(&section_elf.sh_name, sizeof(uint32_t), 1, f);
			section_elf.sh_name = __bswap_32(section_elf.sh_name);
			fread(&section_elf.sh_type, sizeof(uint32_t), 1, f);
			section_elf.sh_type = __bswap_32(section_elf.sh_type);
			fread(&section_elf.sh_flags, sizeof(uint32_t), 1, f);
			section_elf.sh_flags = __bswap_32(section_elf.sh_flags);
			fread(&section_elf.sh_addr, sizeof(uint32_t), 1, f);
			section_elf.sh_addr = __bswap_32(section_elf.sh_addr);
			fread(&section_elf.sh_offset, sizeof(uint32_t), 1, f);
			section_elf.sh_offset = __bswap_32(section_elf.sh_offset);
			fread(&section_elf.sh_size, sizeof(uint32_t), 1, f);
			section_elf.sh_size = __bswap_32(section_elf.sh_size);
			fread(&section_elf.sh_link, sizeof(uint32_t), 1, f);
			section_elf.sh_link = __bswap_32(section_elf.sh_link);
			fread(&section_elf.sh_info, sizeof(uint32_t), 1, f);
			section_elf.sh_info = __bswap_32(section_elf.sh_info);
			fread(&section_elf.sh_addralign, sizeof(uint32_t), 1, f);
			section_elf.sh_addralign = __bswap_32(section_elf.sh_addralign);
			fread(&section_elf.sh_entsize, sizeof(uint32_t), 1, f);
			section_elf.sh_entsize = __bswap_32(section_elf.sh_entsize);

		}

		else
		{
			printf("Section au format de donnée inconnu");
			exit(0);
		}

		t[i] = section_elf;
	
	}


}


void affichageTabsection(Elf32_Shdr *section_elf, Elf32_Ehdr header_elf){

	int i;
	for(i=0; i<header_elf.e_shnum; i++)
	{	

	printf("\n __ SECTION %d __ \n", i +1);
	
	
	printf("Nom de la section : %d\n", section_elf[i].sh_name);

	printf("Contenu et sémantique de la section: ");
	switch(section_elf[i].sh_type){
		case SHT_NULL :
			printf("entête de section est inactif");
			break;
		case SHT_PROGBITS :
			printf("informations définies par le programme");
			break;
		case SHT_SYMTAB :
			printf("tableau de symboles");
			break;
		case SHT_STRTAB :
			printf("tableau de chaînes");
			break;
		case SHT_RELA :
			printf("entrées de repositionnement");
			break;
		case SHT_HASH :
			printf("table de hachage pour les symboles");
			break;
		case SHT_DYNAMIC :
			printf("informations de liaison dynamique");
			break;
		case SHT_NOTE :
			printf("marquage du fichier");
			break;
		case SHT_NOBITS :
			printf("informations définies par le programme sans occuper de place dans le fichier");
			break;
		case SHT_REL :
			printf("entrées de repositionnement sans additif explicite");
			break;
		case SHT_SHLIB :
			printf("section réservée et sémantique non définie");
			break;
		case SHT_DYNSYM :
			printf("jeu de symboles minimal de liaison dynamique");
			break;
		case SHT_LOPROC :
			printf("sémantiques spécifiques au processeur");
			break;
		case SHT_HIPROC :
			printf("sémantiques spécifiques au processeur");
			break;
		case SHT_LOUSER :
			printf("borne inférieure de la plage des indices réservés aux programmes applicatifs");
			break;
		case SHT_HIUSER :
			printf("borne supérieure de la plage des indices réservés aux programmes applicatifs");
			break;
		default :
			printf("Erreur");
			break;

	}
	printf("\n");
	

	// MARCHE PAS LOL
	printf("Drapeaux binaires de la section: ");
	switch(section_elf[i].sh_flags){

		case SHF_WRITE :
			printf("données modifiables durant l'exécution");
			break;
		case SHF_ALLOC :
			printf("section est présente en mémoire durant l'exécution du processus");
			break;
		case SHF_EXECINSTR :
			printf("instructions machine exécutables");
			break;
		case SHF_MASKPROC :
			printf("bits réservés à des sémantiques spécifiques au processeur");
			break;
		default :
			printf(" ");
			break;

	printf("\n");

	}
	printf("\n");

	
	
	printf("Adresse à laquelle le premier octet de la section doit se trouver : %d\n", section_elf[i].sh_addr);
	printf("Décalage du premier octet de la section par rapport au début du fichier : %d\n", section_elf[i].sh_offset);
	
	printf("Taille de la section en octets : %d\n", section_elf[i].sh_size);
	
	// deux suivants marchent pas
	printf("Lien vers un indice de la table des entêtes de sections : %d\n", section_elf[i].sh_link);
	printf("Informations complémentaires : %d\n", section_elf[i].sh_info);
	
	printf("Contraintes d'alignement : %d\n", section_elf[i].sh_addralign);
	
	// Suivant a check
	printf("Table contenant un nombre d'entrées fixe : %d\n", section_elf[i].sh_entsize);


	
	}

}
