#include "projet.h"

void affichageContenuSection(Elf32_Shdr* tabEnTeteSection, int numberSection, FILE* elf){
	int i;
	int j;
	int x;
	char car;
	int flag;
	int offsetcourant, sizecourant;
	int tab[numberSection];
	
	for(i = 1; i < numberSection; i++){
		printf("numéro de section: %d\n", tabEnTeteSection[i].sh_name);
		tab[i] = tabEnTeteSection[i].sh_name;
	}
	
	flag = 0;
	while(!flag){
		printf("Numero de section?");
		scanf("%d", &x);
		for(i=1; i<numberSection; i++){
			if(x==tab[i])
				flag = 1 ;
		}
	}
	
	for (i=1;i<numberSection;i++){
		if (x==tabEnTeteSection[i].sh_name){
			offsetcourant=tabEnTeteSection[i].sh_offset;
			sizecourant=tabEnTeteSection[i].sh_size;
		}
	}
	
	fseek(elf,offsetcourant,SEEK_SET);
	j=1;
	car = fgetc(elf);
	printf("%x", car);
	while(j<=sizecourant){
		car = fgetc(elf);
		printf("%x", car);
		j++;
	}
	printf("\n");
	
}
