CFLAGS=-Wall -std=c++11

%.o: %.cpp %.h
	g++ -o $@ -c $< $(CFLAGS)

all: main

main: main.o PanierArticle.o Article.o Commerce.o Client.o Panier.h
	g++ -Wall $^ -o $@

PanierArticle.o : Panier.h PanierArticle.h Article.h

main.o: PanierArticle.h Article.h Commerce.h

Commerce.o: Client.h Article.h PanierArticle.h
