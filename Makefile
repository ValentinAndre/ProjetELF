CC=gcc
CFLAGS= -g -Wall -Werror -c

main: main.o  Header.o TableauSections.o ContenuSection.o TableauSymboles.o
	$(CC) -g -o $@ $^ -lm
	
%.o: %.c
	$(CC) $(CFLAGS) $<

Header.o:projet.h
TableauSections.o:projet.h
ContenuSection.o:projet.h
TableauSymboles.o:projet.h

main.o:projet.h
