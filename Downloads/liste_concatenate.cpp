#include <iostream>

using namespace std;

struct Nodo{
	int valore;
	Nodo* next;
} ;

class Lista{
	Nodo* p;
 public:
	Lista() { p = NULL;}
	int inserisci(int e); //ritorna 0 se operazione OK -1 se operazione KO
	int cancella(int e); //ritorna 0 se operazione OK -1 se operazione KO
	void stampa();
};

int Lista::cancella(int e){
	if( p == NULL) return -1; // impossibile eliminare l'elemento 
	if( p->valore == e ){ // il valore da eliminare coincide con il primo della lista
		Nodo* r = p;
		p=p->next;
		delete r;
		return 0;
	}
	Nodo* q = p;
	// per gli elementi successivi al primo
	while (q->next != NULL){
		if (q->next->valore == e) {
			Nodo* r= q->next;
			q->next=q->next->next;
			return 1;
		}
		q=q->next ;
	}
}

void Lista::stampa(){
	cout << "#####################################" << endl;
	
	if (p != NULL){ // se non è vuota
		Nodo* q = p;
		int i = 1;
		do{ //ce n'è almeno uno
			cout << "Posizione " << i << " valore: " << q->valore << endl;
			q = q->next;
		}while (q != NULL);
	} else {
		cout << "Lista vuota" << endl;
	}
} 

int Lista::inserisci(int e){
	if(p == NULL){
		//Nessun nodo in lista, inserimento primo valore
		p = new Nodo;
		p->next=NULL;
		p->valore=e;
	} else if(e < p->valore){
		// Nuovo nodo come primo della lista
		Nodo* q = new Nodo;
		q->next = p;
		q->valore = e;
		p = q;
				
	} else {
		// inserimento in posizione intermedia
		Nodo* q = p;
		int inserito = 0;
		while(q->next != NULL && !inserito){
			if (e<q->next->valore){
				// Ho trovato la posizione dove inserire il nuovo nodo
				Nodo* r = q->next;
				q->next = new Nodo;
				q->next->valore = e;
				q->next->next = r;
				
				inserito = 1; // ho inserito per cui metto inserito a TRUE
			} else {
				q=q->next;
			}
		}
		// Ciclo terminato perché ho inserito il nuovo nodo	 (inserito == TRUE)
		// oppure perché sono arrivato alla fine della lista
		if (!inserito){
			// Se inserito è falso, vuol dire che ero arrivato alla fine della lista
			// inserisco il nuovo nodo in coda
			q->next = new Nodo;
			q->next->valore = e;
			q->next->next = NULL;
		}
	}
		
	return 0;
}

int main(){
	Lista l;
	l.stampa();
	l.inserisci(5); // inserimento a lista vuota
	l.stampa();
	l.inserisci(1); // inserimento con primo elemento maggiore del nuovo
	l.stampa();
	l.inserisci(10); // inserimento di un valore più grande di tutti quelli in lista
	l.stampa();
	l.inserisci(7); // inserimento in posizione intermedia
	l.stampa();
	l.cancella(20); // cancella non presente a lista piena
	l.stampa();
	l.cancella(7); // cancella in mezzo
	l.stampa();
	l.cancella(10); // cancella ultimo
	l.stampa();
	l.cancella(1); // cancella primo
	l.stampa();
	l.cancella(5); // cancella ultimo elemento in lista
	l.stampa();
	l.cancella(10); // cancella non presente a lista vuota
	l.stampa();
}
