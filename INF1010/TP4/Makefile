CFLAGS = -W -Wall -std=c++11
BASE = Meteo.o DateHeure.o
AFFICHEURS = AfficheurMeteoStatistiques.o AfficheurDateHeure.o AfficheurMeteo.o

all: Main

Main: Main.o SiteMeteo.o
	g++ $^ -o $@ $(CFLAGS)

%.o: %.cpp %.h
	g++ -c $^ -o $@ $(CFLAGS)

SiteMeteo.o: Meteo.h DateHeure.h AfficheurMeteoStatistiques.h AfficheurDateHeure.h AfficheurMeteo.h

Main.o:Meteo.h DateHeure.h AfficheurMeteoStatistiques.h AfficheurDateHeure.h AfficheurMeteo.h SiteMeteo.h

$(AFFICHEURS): Afficheur.h Connection.h

$(BASE): BaseDeDonnees.h

clean:
	rm *.o

.PHONY: clean
