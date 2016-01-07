#include <stdio.h>
#include <elf.h>
#include <byteswap.h>
#include <string.h>
#include <stdlib.h>

Elf32_Ehdr recupEnTete(FILE* f);
void affichage_enTete(Elf32_Ehdr header_elf);
void recupTabsection(FILE* f, Elf32_Ehdr header_elf, Elf32_Shdr *t);
void affichageTabsection(Elf32_Shdr *section_elf, Elf32_Ehdr header_elf);
void affichageContenuSection(Elf32_Shdr* tabEnTeteSection, int numberSection, FILE* elf);
void getTableauSymboles(FILE* f, Elf32_Ehdr header_elf, Elf32_Shdr section_elf);
