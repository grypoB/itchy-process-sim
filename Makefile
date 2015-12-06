# Definitions de macros
EXEC = domotique.x

CXX      = g++
CXXFLAGS = -pedantic -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
-Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion \
-Wshadow -Wredundant-decls -Winit-self -Wswitch-default \
-Wswitch-enum -Wundef -Winline -Wsign-conversion
# -std=c++11 -Weffc++ 
SOURCE_DIR = src/
CPPFILES = src/SinPhenomenon.cpp src/PulsePhenomenon.cpp src/OnOffController.cpp src/GainController.cpp src/SaturationController.cpp src/Controller.cpp src/Phenomenon.cpp src/RngPhenomenon.cpp src/Server.cpp src/Simulator.cpp src/State.cpp src/main.cpp src/random.cpp \
src/xml_parser.cpp \
src/tinyxml/tinystr.cpp \
src/tinyxml/tinyxml.cpp \
src/tinyxml/tinyxmlerror.cpp \
src/tinyxml/tinyxmlparser.cpp
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
	@/bin/rm -f $(SOURCE_DIR)/*.o *.x *.cpp~ *.h~ *.gch

vanish:
	@echo " *** EFFACE MODULES OBJET ***"
	@/bin/rm -f $(SOURCE_DIR)/*.o *.cpp~ *.h~ *.gch
	
#
# -- Regles de dependances generees automatiquement
#
# DO NOT DELETE THIS LINE
SinPhenomenon.o: src/SinPhenomenon.cpp src/SinPhenomenon.h \
  src/Phenomenon.h src/State.h src/Agent.h src/random.h
PulsePhenomenon.o: src/PulsePhenomenon.cpp src/PulsePhenomenon.h \
  src/Phenomenon.h src/State.h src/Agent.h
OnOffController.o: src/OnOffController.cpp src/OnOffController.h \
  src/Controller.h src/State.h src/Agent.h src/Server.h
GainController.o: src/GainController.cpp src/GainController.h \
  src/Controller.h src/State.h src/Agent.h src/Server.h
SaturationController.o: src/SaturationController.cpp \
  src/SaturationController.h src/Controller.h src/State.h src/Agent.h \
  src/Server.h
Controller.o: src/Controller.cpp src/Controller.h src/State.h src/Agent.h \
  src/Server.h
Phenomenon.o: src/Phenomenon.cpp src/Phenomenon.h src/State.h src/Agent.h \
  src/random.h
RngPhenomenon.o: src/RngPhenomenon.cpp src/RngPhenomenon.h \
  src/Phenomenon.h src/State.h src/Agent.h src/random.h
Server.o: src/Server.cpp src/Server.h src/Agent.h
Simulator.o: src/Simulator.cpp src/Simulator.h src/Agent.h
State.o: src/State.cpp src/State.h src/Agent.h
main.o: src/main.cpp src/xml_parser.h src/Simulator.h src/Agent.h \
  src/OnOffController.h src/Controller.h src/State.h src/Server.h \
  src/SinPhenomenon.h src/Phenomenon.h
random.o: src/random.cpp src/random.h
xml_parser.o: src/xml_parser.cpp src/xml_parser.h src/tinyxml/tinyxml.h \
  src/xml_utils.h src/OnOffController.h src/Controller.h src/State.h \
  src/Agent.h src/Server.h src/SinPhenomenon.h src/Phenomenon.h \
  src/Simulator.h
tinystr.o: src/tinyxml/tinystr.cpp src/tinyxml/tinystr.h
tinyxml.o: src/tinyxml/tinyxml.cpp src/tinyxml/tinyxml.h
tinyxmlerror.o: src/tinyxml/tinyxmlerror.cpp src/tinyxml/tinyxml.h
tinyxmlparser.o: src/tinyxml/tinyxmlparser.cpp src/tinyxml/tinyxml.h
