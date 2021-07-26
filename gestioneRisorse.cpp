#include "gestioneRisorse.h"
#include "prenotazione.h"
#include <iostream>

using namespace std;

void GestioneRisorse::modPiscina(int pis){ //modifica il numero di posti per la piscina
	do{
		if(pis <= postiPiscina) {
			postiPiscina = postiPiscina-pis;
			cout << " n. posti per la piscina rimanenti: " << postiPiscina << endl;
		} else if (pis > postiPiscina) {
			cout << pis << " lettini non disponibili, sono invece disponibili: " << postiPiscina << " lettini" << endl;
		}
	}while(pis > postiPiscina);
};

void GestioneRisorse::modRistorante(int ris){ //modifica il numero di posti per il ristorante
	do{
		if(ris <= postiRistorante) {
			postiRistorante = postiRistorante-ris;
			cout << "n. posti per il ristorante rimanenti: " << postiRistorante << endl;
		} else if (ris > postiRistorante) {
			cout << ris << " lettini non disponibili, sono invece disponibili: " << postiRistorante << " lettini" << endl;
		}
	}while(ris > postiRistorante);
};

void GestioneRisorse::modLettini(int let){ //modifica il numero di lettini
	do{
		if(let <= lettiniRim) {
			lettiniRim = lettiniRim-let;
			cout << "n. Lettini rimanenti: " << lettiniRim << endl;
		} else if (let > lettiniRim) {
			cout << let << " lettini non disponibili, sono invece disponibili: " << lettiniRim << " lettini" << endl;
		}
	}while(let > lettiniRim);
};

void GestioneRisorse::modSdraio(int sdr){ //modifica il numero di sdraio
	do{
		if(sdr <= sdraioRim) {
			sdraioRim = sdraioRim-sdr;
			cout << "n. Sdraio rimanenti: " << sdraioRim << endl;
			} else if (sdr > sdraioRim) {
			cout << sdr << " sdraio non disponibili, sono invece disponibili: " << sdraioRim << " sdraio";
		}
	}while(sdr > sdraioRim);
};

void GestioneRisorse::modOmbrelloni(int omb){ //modifica il numero di ombrellini
	do{
		if(omb <= ombrelloniRim) {
			ombrelloniRim = ombrelloniRim-omb;
			cout << "n. Ombrelloni rimanenti: " << ombrelloniRim << endl;
			} else if (omb > ombrelloniRim) {
			cout << omb << " ombrelloni non disponibili, sono invece disponibili: " << ombrelloniRim << " ombrelloni";
		}
	}while(omb > ombrelloniRim);
};

void GestioneRisorse::set_prezzi(float o, float l, float s, float r, float p){ //setta i prezzi
	prezziLet  = l;
	prezziOmbr = o;
	prezziSdr  = s;
	prezziRis = r;
	prezziPis = p;
};

void GestioneRisorse::get_prezzi(){
	cout <<"prezzo per il lettino: "<< prezziLet <<endl<<" prezzo per l'ombrellone " << prezziOmbr <<endl<< " prezzo per la sdraio ";
	cout << prezziSdr <<endl<< " prezzo per il Ristorante " << prezziRis <<endl<< " prezzo per la Piscina " << prezziPis << endl;
};

void GestioneRisorse::get_risorse(){
	cout << "Sono rimasti:" << endl << "Ombrelloni -> " << ombrelloniRim << endl;
	cout << "Lettini -> " << lettiniRim << endl << "Sdraio -> " << sdraioRim << endl;
	cout << "Posti per il Ristorante -> " << postiRistorante << endl;
	cout << "Posti per la Piscina -> " << postiPiscina << endl;
};

GestioneRisorse::GestioneRisorse(int a, int b, int c, int e, int w) { //costruttore
	lettiniRim = a;
	sdraioRim = b;
	ombrelloniRim = c;
	postiRistorante = e;
	postiPiscina = w;
};


