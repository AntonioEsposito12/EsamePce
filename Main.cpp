#include "utente.h"
#include "gestioneRisorse.h"
#include "prenotazione.h"
#include <iostream>
#include <string>
#include <map>



int main()
{
	map<string,Prenotazione> Elenco;
	GestioneRisorse materie (30, 70, 100, 60, 30);
	materie.set_prezzi(4.0, 4.0, 2.0);
	char uscita = 'u';
	cout << "Benvenuto nel menu della prenotazione, se desidera aggiumgere una prenotazione, prema a\
	, se desidera modificare una prenotazione, prema m, se desidera cancellare una prenotazione, prema\
	c, se desidera invece vedere l'elenco delle prenotazioni premere e, altrimenti prema u per uscire dal menu"<<endl;
	char menu;
	cin >> menu;
	do{
	Cliente Paolo;
	Prenotazione PaoloPre;
		switch (menu) {
			case 'a':
			{
				Paolo.set_dati();
				cout << endl;
				PaoloPre.set_noPersona(Paolo);
				PaoloPre.serviziScelti(materie);
				PaoloPre.set_prezzoTot(materie);
				Elenco[Paolo.nome]=PaoloPre;
			}
			break;

				
			case 'm':
				PaoloPre.get_Data();
				PaoloPre.get_prenot();
				PaoloPre.mod_servizi();
				break;
				
			case 'c':
				
				
				break;
			
			case 'e':
				
				break;
				
			case 'u':
				cout << "Arrivederci!" <<endl;
				break;
		}
	cout << "Desidera continuare? E desidera aggiumgere una prenotazione, prema a, se desidera modificare una prenotazione, prema m, se desidera cancellare una prenotazione, prema\
	c, se desidera invece vedere l'elenco delle prenotazioni premere e, altrimenti prema u per uscire dal menu" << endl;
	cin >> menu;
	if (menu == uscita){
		cout << "Arrivederci!" <<endl;
		}
	}while(uscita!=menu);
}

