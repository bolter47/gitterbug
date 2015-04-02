CFLAGS = -Wall -c

%.o: %.cpp %.h
	g++ -o $@ $(CFLAGS) $< 

all: main

main: main.o PanierArticle.o Article.o
	g++ -Wall $^ -o $@

PanierArticle.o : Panier.h PanierArticle.h Article.h

main.o: PanierArticle.h Article.h
