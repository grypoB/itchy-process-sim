# Definitions de macros

CC     = g++
CFLAGS = -Wall
CPPFILES = Vehicule.cpp Voiture.cpp Camion.cpp PlacePark.cpp Parking.cpp main.cpp
OFILES = Vehicule.o Voiture.o Camion.o PlacePark.o Parking.o main.o

# Definition de la premiere regle

domotique.x: $(OFILES)
	$(CC) $(OFILES) -o domotique.x

# Definitions de cibles particulieres

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CC) -MM $(CFLAGS) $(CPPFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x *.c~ *.h~

#
# -- Regles de dependances generees automatiquement
#
# DO NOT DELETE THIS LINE

