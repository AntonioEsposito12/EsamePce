#include "utente.h"
#include "gestioneRisorse.h"
#include "prenotazione.h"
#include <iostream>
#include <string>
#include <map>



int main()
{
	map<string,Prenotazione> Elenco;
	GestioneRisorse materie (100, 100, 100, 60, 30);
	materie.set_prezzi(4.0, 4.0, 2.0, 10.0, 12.0);
	char uscita = 'u';
	cout << "Benvenuto nel menu della prenotazione, se desidera aggiumgere una prenotazione, prema a\
	, se desidera modificare una prenotazione, prema m, se desidera cancellare una prenotazione, prema\
	c, se desidera visualizzaere le risorse rimanenti o il prezzo delle risorse, prema r, se desidera invece vedere l'elenco delle prenotazioni premere e, altrimenti prema u per uscire dal menu"<<endl;
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
				Elenco[Paolo.cognome]=PaoloPre;
			}
			break;
				
			case 'm':{
				if(Elenco.empty()) {cout << "non ci sono prenotazione" << endl;} else {
				cout << endl;
				cout << endl;
				cout << "Selezionare il cognome della prenotazione che si vuole modificare ";
				string cog;
				cin >> cog;
				Elenco.find(cog)->second.mod_servizi();
				}
			}
			break;
				
			case 'c':{
				if(Elenco.empty()) {cout << "non ci sono prenotazione" << endl;} else {
				cout << endl;
				cout << endl;
				cout << "Selezionare il cognome della prenotazione che si vuole cancellare ";
				string cog;
				cin >> cog;
				Elenco.erase(cog);
				}
			}
			break;
			
			case 'e':
			{
				cout << endl;
				cout << endl;
				for(map<string,Prenotazione>::iterator it=Elenco.begin(); it!=Elenco.end(); ++it)
				{
					cout << it->first;
					cout << " - ";
					it->second.get_Data();
					it->second.get_prenot();
				}
				if(Elenco.empty()) {cout << "non ci sono prenotazione" << endl;};
			}
			break;
			
			case 'r':
				char visRisorse;
				while(visRisorse != 'u'){
				cout << " Selezionare cosa desidera vedere: il prezzo delle risorse(p) oppure le rimanenze delle risorse (r). Se desidera invece tornare al menu, prema u" << endl;
				cin >> visRisorse;
					switch(visRisorse) {
						case 'p':
							materie.get_prezzi();
							cout << endl;
						break;
						
						case 'r':
							materie.get_risorse();
							cout << endl;
						break;
						
						case 'u':
							cout << " Ottimo, continui a navigare nel menu " << endl;
							cout << endl;
						break;
						
						default:
							cout << "Carattere non riconosciuto, ripetere prego: ";
					}
				}
				
			break;
				
			case 'u':
			{
				cout << "Arrivederci!" <<endl;
			}
			break;
			
			default:
				cout << "Carattere non riconosciuto, ripetere prego" << endl;
		}
	cout << "Desidera continuare? E desidera aggiungere una prenotazione, prema a, se desidera modificare una prenotazione, prema m, se desidera cancellare una prenotazione, prema\
	c, se desidera invece vedere l'elenco delle prenotazioni premere e, altrimenti prema u per uscire dal menu" << endl;
	cin >> menu;
	if (menu == uscita){
		cout << "Arrivederci!" <<endl;
		}
	}while(uscita!=menu);
}

//fatto da Emanuele Scarpati (DES) & Antonio Esposito (Æ)
