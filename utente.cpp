#include <iostream>
#include "utente.h"


Utente::Utente(){
	nome = " ";
	cognome = " ";
	numerotel = 0;
	};

Cliente::Cliente(){
	tipo = " ";
	numerop = 0;
	};

void Utente::set_dati(){
	string a, b;
	long long int i;
	cout << "inserire nome per la prenotazione: ";
	cin >> a;
	nome = a;
	cout << "inserire cognome per la prenotazione: ";
	cin >> b;	
	cognome = b;
	cout << "inserire numero cell. per la prenotazione: ";
	while (!(cin >> i)) { //metodo per evitare che vada in crash se inserito un char
		cin.clear();
		cin.ignore(10000000000, '\n');
		cout << "Inserisca un numero di telefono per davvero, grazie" << endl;
	}
	numerotel = i;
};
	
void Utente::get_dati(){
	cout <<"nome: "<< nome << " cognome: "<< cognome << " numero telefono: "<< numerotel << endl;
};

void Cliente::set_tipo(string f) {
	tipo = f;
};
	
void  Cliente::get_tipo() {
	cout << tipo << " ";
};


