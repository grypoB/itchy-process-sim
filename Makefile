# Definitions de macros
EXEC = domotique.x

CXX      = g++
CXXFLAGS = -pedantic -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
-Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion \
-Wshadow -Weffc++ -Wredundant-decls -Winit-self -Wswitch-default \
-Wswitch-enum -Wundef -Winline -Wsign-conversion
# -std=c++11
CPPFILES = src/Controller.cpp src/Phenomenon.cpp src/RngPhenomenon.cpp src/Server.cpp src/Simulator.cpp src/State.cpp src/main.cpp src/random.cpp
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
Controller.o: src/Controller.cpp src/Controller.h src/State.h src/Agent.h \
  src/Server.h
Phenomenon.o: src/Phenomenon.cpp src/Phenomenon.h src/State.h src/Agent.h
RngPhenomenon.o: src/RngPhenomenon.cpp src/RngPhenomenon.h \
  src/Phenomenon.h src/State.h src/Agent.h src/random.h
Server.o: src/Server.cpp src/Server.h src/Agent.h
Simulator.o: src/Simulator.cpp src/Simulator.h src/Agent.h
State.o: src/State.cpp src/State.h src/Agent.h
main.o: src/main.cpp src/Simulator.h src/Agent.h src/Controller.h \
  src/State.h src/Server.h src/RngPhenomenon.h src/Phenomenon.h
random.o: src/random.cpp src/random.h
