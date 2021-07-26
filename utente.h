#ifndef UTENTE_H
#define UTENTE_H 

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Utente {
	public:

		
	public:
		string nome;
		string cognome;
		long long int numerotel;
		
	public:
		
		Utente();
		void set_dati ();
		void get_dati();
		
	};
	
class Cliente:public Utente {
	private:
		string tipo;
		int numerop;
		
	public:
		Cliente();
		void set_tipo(string f);
		void get_tipo();
	};

#endif
