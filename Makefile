CC=gcc
CFLAGS= -g -Wall -Werror -c

main: main.o lectureEnTete.o affichageSections.o lectureEnTete.o affichageContenuSection.o
	$(CC) -g -o $@ $^ -lm
	
%.o: %.c
	$(CC) $(CFLAGS) $<

lectureEnTete.o:projet.h
affichageSections.o:projet.h
affichageContenuSection.o:projet.h

main.o:projet.h
