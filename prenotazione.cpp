#include <iostream>
#include <ctime>
#include "prenotazione.h"
#include "gestioneRisorse.h"

using namespace std;

Prenotazione::Prenotazione()
{
	nuPersone=0;
	prezzoTot=0;
	nuLettini=0;
	nuOmbrelloni=0;
	nuSdraio=0;
	ristorante=0;
	piscina = false;
	prenEff = false;
	giorno = 0;
	mese = 0; 
	anno = 0;   
};

void Prenotazione::set_noPersona(Cliente h) {
	noPersona = h;
	
};

void Prenotazione::serviziScelti(GestioneRisorse &ris) { //indica quali servizi il cliente decide di scegliere
	cout << "Scegliere la data di prenotazione" << endl;
	cout << endl;
	this->set_dataPr(); //per usare il metodo bisogna usare this
	int p;
	cout << "Inserire il numero di persone: ";
	cin >> p;
	nuPersone=p;
	char y;
	cout << "Si vuole usufruire della piscina? Abbiamo: " << ris.postiPiscina << " posti disponibili, premere y se desidera prenotare anche la piscina o n se non desidera prenotare la piscina ";
	do{
		cin >> y;
		cout << endl;
		if (y=='y') {
			piscina=true;
			ris.modPiscina(this->nuPersone);
			} else if (y == 'n') {
				piscina = false;
			} else {
				cout << endl << " carattere non riconosciuto, ripetere l'immissione ";
			}
		}while(y!='y' && y!='n');
	cout << "Si vuole usufruire del ristorante? Abbiamo: " << ris.postiRistorante << " posti disponibili premere, y se desidera prenotare anche il ristorante o n se non desidera prenotare il ristorante ";
	do{
		cin >> y;
		cout << endl;
		if (y=='y') {
			ristorante=true;
			ris.modRistorante(this->nuPersone);
			} else if (y == 'n') {
				ristorante = false;
			} else {
				cout << endl << " carattere non riconosciuto, ripetere l'immissione ";
			}
		}while(y!='y' && y!='n');
	int f;
	cout << "Scegliere il numero di ombrelloni: ";
	cin >> f;
	nuOmbrelloni=f;
	ris.modOmbrelloni(this->nuOmbrelloni);
	cout << endl;
	int e;
	cout << "Scegliere il numero di lettini: ";
	cin >> e;
	nuLettini=e;
	ris.modLettini(this->nuLettini);
	cout << endl;
	int r;
	cout << "Scegliere il numero di sdraio: ";
	cin >> r;
	nuSdraio=r;
	ris.modSdraio(this->nuSdraio);
	cout << endl;
	prenEff=true;
};

void Prenotazione::set_dataPr(){
	
	int g,m,a;

	do{
		cout << "Inserire il giorno: "<<endl;
		while (!(cin >> g)) { //metodo per evitare che vada in crash se inserito un char
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Inserisca un giorno per davvero, grazie" << endl << endl;
			}
		}
		while ( !(g >0 && g < 32));        
		giorno = g;

	do{
		do{
			cout << "Inserire il mese: " << endl;
			while (!(cin >> m)) { //metodo per evitare che vada in crash se inserito un char
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Inserisca un mese per davvero, grazie" << endl << endl;
				}
				
			}while((m == 2 && giorno > 28) ||  ((m==4 || m==6 ||m==9 || m==11) && giorno > 30));
			
		}while ( !(m >0 && m < 13));        
		mese = m;
		
	do{
		cout << "Inserire l'anno: "<<endl;
		while (!(cin >> a)) { //metodo per evitare che vada in crash se inserito un char
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Inserisca un anno per davvero, grazie" << endl << endl;
			}
			
		}while ( !(a >=2021 && a < 2050));        
		anno = a;	
		
};

void Prenotazione::get_Data(){
	if (prenEff==true) {
		cout << "la data selezionata corrisponde a " << giorno << '/' << mese << '/' << anno << endl;
	} else {
		cout << "La prenotazione è stata cancellata" << endl;
	}   
};

void Prenotazione::eliPren(Prenotazione prenotazione) {
	prenotazione.prenEff=false;
	cout << "prenotazione cancellata" <<endl;
};

void Prenotazione::set_prezzoTot(GestioneRisorse &pre) {
	prezzoTot = pre.prezziLet*nuPersone;
	prezzoTot = prezzoTot+(pre.prezziSdr*nuPersone);
	prezzoTot = prezzoTot+(pre.prezziOmbr*nuPersone);
	prezzoTot = prezzoTot+(pre.prezziPis*nuPersone);
	prezzoTot = prezzoTot+(pre.prezziRis*nuPersone);
};

void Prenotazione::get_prenot(){
	cout << "n. persone: " << nuPersone <<endl;
	cout << "n. Ombrelloni: " << nuOmbrelloni <<endl;
	cout << "n. Lettini: " << nuLettini <<endl;
	cout << "n. Sdraio: " << nuSdraio <<endl;
	if(piscina==true){
		cout << "Piscina: si'" << endl;
	} else {
		cout << "Piscina: no" << endl;
	}
	if(ristorante==true) {
		cout << "Ristorante: si'" << endl;
	} else {
		cout << "Ristorante: no" << endl;
	}
	cout << "prezzo totale e' di: " << prezzoTot << " euro" << endl;
	cout << "nome della prenotazione: "; noPersona.get_dati(); cout << endl;
};
void Prenotazione::mod_servizi() {
	if(prenEff==true){
	char more = 'y';
	while(more == 'y'){
		cout << "Scegliere cosa si vuole modificare: n.Persone(p), n.Lettini(l), n.Ombrelloni(o), n.Sdraio(s), ristorante(r), piscina(i), data(d)"<<endl;
		char p;
		cin >> p;
		switch(p) {
			case 'p':
				cout << "Indicare il nuovo numero di persone: "<<endl;
				int e;
				cin>>e;
				nuPersone=e;
				break;
			
			case 'l':
				cout << "Indicare il nuovo numero di lettini: "<< endl;
				int l;
				cin>>l;
				nuLettini=l;
				break;
			
			case 'o':
				cout << "Indicare il nuovo numero di ombrelloni: " << endl;
				int o;
				cin>>o;
				nuOmbrelloni=o;
				break;
			
			case 's':
				cout << "Indicare il nuovo numero di sdraio: " << endl;
				int s;
				cin>>s;
				nuSdraio=s;
				break;
				
			case 'r':
				if (ristorante==true) {
					ristorante=false;
					cout << "prenotazione ristorante annullata " <<endl;
				} else {
					ristorante=true;
					cout << "prenotazione ristorante aggiunta" << endl;
				}
				break;
			
			case 'i':
				if (piscina==true) {
					piscina=false;
					cout << "prenotazione piscina annullata " <<endl;
				} else {
					piscina=true;
					cout << "prenotazione piscina aggiunta" << endl;
				}
				break;
			
			case 'd':
				this->set_dataPr();
				break;
			
			cout << "Se si desidera modificare altro, prema y altrimenti prema un altro pulsante "<<endl;
			cin >> more;
			}
		}
	} else {
		cout << " La prenotazione non esiste ";
	}
}


