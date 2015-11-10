# Definitions de macros
EXEC = domotique.x

CXX      = g++
CXXFLAGS = -pedantic -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
-Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion \
-Wshadow -Weffc++ -Wredundant-decls -Winit-self -Wswitch-default \
-Wswitch-enum -Wundef -Winline -Wsign-conversion
# -std=c++11
CPPFILES = Controller.cpp Phenomenon.cpp Server.cpp Simulator.cpp State.cpp main.cpp
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
Controller.o: Controller.cpp Controller.h State.h Server.h Agent.h
Phenomenon.o: Phenomenon.cpp Phenomenon.h State.h Agent.h
Server.o: Server.cpp Server.h Agent.h
Simulator.o: Simulator.cpp Simulator.h Agent.h
State.o: State.cpp State.h
main.o: main.cpp
