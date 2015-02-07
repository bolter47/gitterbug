CFLAGS= -W -Wall -ansi -pedantic

all:main
main: main.o Panier.o Article.o
	g++ -o $@ $^
	make clean

main.o: Panier.h Article.h

Panier.o: Article.h

%.o: %.cpp
	g++ -o $@ $(CFLAGS) -c $<


#Cleaning command, maybe add at the end of build

clean:
	rm *.o

#Clears the created file
rmproper:
	rm Main
