#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "utente.h"
#include "gestioneRisorse.h"
#include <iostream>

using namespace std;

class Prenotazione {
	
	public:
		int nuPersone;
		float prezzoTot;
		int nuLettini;
		int nuOmbrelloni;
		int nuSdraio;
		Cliente noPersona;
		bool ristorante;
		bool piscina;
		bool prenEff;
		int giorno;
		int mese;
		int anno;
	
	public:
		Prenotazione();
		void set_dataPr();
		void get_Data();
		void set_prezzoTot(GestioneRisorse &pre);
		void serviziScelti(GestioneRisorse &ris);
		void set_noPersona(Cliente h);
		void get_prenot();
		void mod_servizi();
		void eliPren(Prenotazione prenotazione);
};

#endif
