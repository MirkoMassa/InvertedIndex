parole = main.o liste.o compito.o tipo.o

parole: $(parole)
	g++ -o parole $(parole)

main.o: main.cc liste.h parola.h compito.h tipo.h
	g++ -c main.cc

liste.o: tipo.h
	g++ -c liste.cc

tipo.o:
	g++ -c tipo.cc

compito.o: liste.h parola.h
	g++ -c compito.cc

PHONY: cleanall
cleanall:
	rm *.o parole