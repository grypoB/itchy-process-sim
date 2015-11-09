# Definitions de macros
EXEC = domotique.x

CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wsign-conversion
CPPFILES = Aera.cpp Controller.cpp Phenomenon.cpp Server.cpp State.cpp

OFILES = $(CPPFILES:.cpp=.o)

# Definition de la premiere regle

all: $(EXEC)

# Definitions de cibles particulieres

$(EXEC): $(OFILES)
	$(CXX) $(OFILES) -o $(EXEC)

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CXX) -MM $(CXXFLAGS) $(CPPFILES) | \
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
Aera.o: Aera.cpp Aera.h Phenomenon.h State.h Controller.h Server.h
Controller.o: Controller.cpp Controller.h State.h Phenomenon.h
Phenomenon.o: Phenomenon.cpp Phenomenon.h
Server.o: Server.cpp Server.h
State.o: State.cpp State.h Phenomenon.h
