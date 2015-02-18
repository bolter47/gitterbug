CFLAGS= -W -Wall -ansi -pedantic -std=c++11
EMPEXT= AgentSecurite.o Etudiant.o Professeur.o

all:main
main: main.o $(EMPEXT) PirateInformatique.o SystemeSecurite.o Employe.o RegleAcces.o
	g++ $^ -o $@ $(CFLAGS)
	make clean

$(EMPEXT): Employe.h

PirateInformatique.o: AgentSecurite.h

SystemeSecurite.o: RegleAcces.h

main.o: SystemeSecurite.h PirateInformatique.h

%.o: %.cpp
	g++ -o $@ $(CFLAGS) -c $<

clean:
	rm *.o
