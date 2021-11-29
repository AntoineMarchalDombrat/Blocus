### VARIABLES ###
 
CC = gcc

CFLAGS = -Wall \
         -lgraph

EXE = blocus

OFILES = display.o \
		 game.o \
		 mouse.o \
         main.o
 
### BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
 
display.o : display.h

game.o : game.h

mouse.o : mouse.h
 
main.o : display.h game.h mouse.h
 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}

### REGLES OPTIONNELLES ###
 
clean :
	-rm -f ${OFILES}

mrproper : clean but

run :
	./blocus

### BUTS FACTICES ###
 
.PHONY : but clean mrproper
 
### FIN ###