#ifndef GESTIONERISORSE_H
#define GESTIONERISORSE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GestioneRisorse {
	
	public:
		int postiRistorante;
		int postiPiscina;
		int lettiniRim;
		int sdraioRim;
		int ombrelloniRim;
		float prezziLet;
		float prezziSdr;
		float prezziOmbr;
		float prezziRis;
		float prezziPis;
		
	public:
		GestioneRisorse(int a, int b, int c, int e, int w);
		void modLettini(int let);
		void modSdraio(int sdr);
		void modOmbrelloni(int omb);
		void modRistorante(int ris);
		void modPiscina(int pis);
		void set_prezzi(float o, float l, float s, float r, float p);
		void get_risorse();
		void get_prezzi();
};


#endif
