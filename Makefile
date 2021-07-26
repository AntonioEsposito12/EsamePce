all: Stabilimento_Balneare

Stabilimento_Balneare: utente.o prenotazione.o gestioneRisorse.o Main.o
	 g++ -o Stabilimento_Balneare utente.o prenotazione.o gestioneRisorse.o Main.o

utente.o: utente.cpp utente.h
	   g++ -c utente.cpp

prenotazione.o: prenotazione.cpp prenotazione.h
		  g++ -c prenotazione.cpp

gestioneRisorse.o: gestioneRisorse.cpp gestioneRisorse.h
		    g++ -c gestioneRisorse.cpp

Main.o: Main.cpp utente.h prenotazione.h gestioneRisorse.h
	 g++ -c Main.cpp
clean:
	rm -f *.o
	rm -f ./Stabilimento_Balneare
	rm -f *~
