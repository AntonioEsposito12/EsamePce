#include "gestioneRisorse.h"
#include "prenotazione.h"
#include <iostream>

using namespace std;

void GestioneRisorse::modLettini(int let){
		if(let <= lettiniRim) {
			lettiniRim = lettiniRim-let;
		} else if (let > lettiniRim) {
			cout << let << " lettini non disponibili, sono invece disponibili: " << lettiniRim << " lettini" << endl;
		}
		cout << "n. Lettini rimanenti: " << lettiniRim << endl;
};

void GestioneRisorse::modSdraio(int sdr){
		if(sdr <= sdraioRim) {
			sdraioRim = sdraioRim-sdr;
		} else if (sdr > sdraioRim) {
			cout << sdr << " sdraio non disponibili, sono invece disponibili: " << sdraioRim << " sdraio";
		}
		cout << "n. Sdraio rimanenti: " << sdraioRim << endl;

};

void GestioneRisorse::modOmbrelloni(int omb){
		if(omb <= ombrelloniRim) {
			ombrelloniRim = ombrelloniRim-omb;
		} else if (omb > ombrelloniRim) {
			cout << omb << " ombrelloni non disponibili, sono invece disponibili: " << ombrelloniRim << " ombrelloni";
		}
		cout << "n. Ombrelloni rimanenti: " << ombrelloniRim << endl;

};

void GestioneRisorse::set_prezzi(float e, float r, float t){
	prezziLet  = e;
	prezziOmbr = r;
	prezziSdr  = t;
};

void GestioneRisorse::get_prezzi(){
	cout <<"prezzo per il lettino: "<< prezziLet <<" prezzo per l'ombrellone"<< " " << prezziOmbr << " prezzo per la sdraio " << prezziSdr << " ";
};

GestioneRisorse::GestioneRisorse(int a, int b, int c, int e, int w) {
	lettiniRim = a;
	sdraioRim = b;
	ombrelloniRim = c;
	postiRistorante = e;
	postiPiscina = w;
};


