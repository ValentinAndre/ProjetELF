#include "lectureEnTeteSection.h"

int main(int argc, char *argv[]){
	
	Elf32_Ehdr enTete;
	Elf32_Shdr *SectionTable;
	int SectionNumber;
	FILE* elf;

	if(argc == 0){
		printf("un argument est demandé");
		exit(0);
	}
	
	
	elf = fopen(argv[1], "r");
	
	enTete = recupEnTete(elf);
	affichage_enTete(enTete);
	printf("\n ---------------------------------------------------- \n");
	
	SectionNumber =  enTete.e_shnum;
	fseek(elf, enTete.e_shoff, SEEK_SET);
	SectionTable = (Elf32_Shdr*) malloc(sizeof(Elf32_Shdr)*(SectionNumber));
	recupTabsection(elf, enTete, SectionTable);
	affichageTabsection(SectionTable, enTete);
	
	printf("\n ---------------------------------------------------- \n");
	
	affichageContenuSection(SectionTable, SectionNumber, elf);
	printf("\n ---------------------------------------------------- \n");
	
	fclose(elf);
	return 0;
}
