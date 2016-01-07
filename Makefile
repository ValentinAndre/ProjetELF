CC=gcc
CFLAGS= -g -Wall -Werror -c

main: main.o lectureEnTete.o affichageSections.o lectureEnTete.o affichageContenuSection.o
	$(CC) -g -o $@ $^ -lm
	
%.o: %.c
	$(CC) $(CFLAGS) $<

lectureEnTete.o:lectureEnTeteSection.h
affichageSections.o:lectureEnTeteSection.h
affichageContenuSection.o:lectureEnTeteSection.h

main.o: lectureEnTeteSection.h
