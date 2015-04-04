CFLAGS = -Wall -c

%.o: %.cpp %.h
	g++ -o $@ $(CFLAGS) $< 

all: main

main: main.o PanierArticle.o Article.o Commerce.o
	g++ -Wall $^ -o $@

PanierArticle.o : Panier.h PanierArticle.h Article.h

main.o: PanierArticle.h Article.h Commerce.h

Commerce.o: Commerce.h Client.h Article.h PanierArticle.h
