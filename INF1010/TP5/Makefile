CFLAGS = -Wall -c -std=c++11

%.o: %.cpp %.h
	g++ -o $@ $(CFLAGS) $< 

all: main

main: main.o PanierArticle.o Article.o Commerce.o Client.o
	g++ -Wall $^ -o $@

PanierArticle.o : Panier.h PanierArticle.h Article.h

main.o: PanierArticle.h Article.h Commerce.h

Commerce.o: Client.h Article.h PanierArticle.h
