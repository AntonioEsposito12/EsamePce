#ifndef UTENTE_H
#define UTENTE_H 

#include <iostream>
#include <string>

using namespace std;

class Utente { //Classe padre utente
	public:
		string nome;
		string cognome;
		long long int numerotel; //Per poter inserire numeri simil telefonici (dai 3 miliardi in su)
		
	public:
		
		Utente();
		void set_dati (); 
		void get_dati();
		
	};
	
class Cliente:public Utente { //classe figlio utente
	private:
		string tipo; // tipo di cliente
		int numerop; //numero persone per la prenotazione
		
	public:
		Cliente();
		void set_tipo(string f);
		void get_tipo();
	};

#endif
