#ifndef CIRCUITO_HPP
#define CIRCUITO_HPP

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <locale>
#include "Gate.hpp"
#include "Componente.hpp"
#include "Segnale.hpp"

class Circuito
{
	friend istream& operator>>(istream& is, Circuito& c);
	friend ostream& operator<<(ostream& os, const Circuito& c);
public:
	Circuito(){area = 0;}
	string Nome() const {return nome;}
	double Area() const {return area;}
	unsigned NumSegnali() const {return segnali.size();}
	Segnale VediSegnale(unsigned i) const {return segnali[i];}
	unsigned NumIngressi() const {return ingressi.size();}
	Segnale VediIngresso(unsigned i) const {return ingressi[i];}
	unsigned NumGate() const {return gate.size();}
	const Gate& VediGate(unsigned i) const {return gate[i];}
	unsigned NumUscite() const {return uscite.size();}
	Segnale VediUscita(unsigned i) const {return uscite[i];}
	unsigned NumCollegamenti() const {return collegamenti.size();}
	pair<SegnaleParziale, SegnaleParziale> VediCollegamento(unsigned i) const {return collegamenti[i];}
	
	void StampaComponentiAssociati(ostream& os) const;
	//funzione di debug che per ogni gate stampa nome e nome del componenete associato (solo se ha un componente assocciato)
	
	
	SegnaleParziale GeneraSegnaleParziale(string m);
	//genera il segnale parziale corrispondente alla stringa m
	bool AssociaComponente(unsigned i, Componente* comp);
	//Associa al gate di indice [i] il componente [c] aggiornando l'area occupata dal circuito e la capacità vista da tutti i
	//  gate a esso collegato
	bool AssegnaComponentiRandom(vector<Componente>& lib);
	//Associa a ogni gate un componente a caso dalla libreria [lib]
	bool AssegnaComponentiOttimi(vector<Componente>& lib, double vincolo_t, string nome_uscita, double tti, double cl);
	//Associa a ogni gate il componente della libreria [lib] che  minimizza l'area, mantenendo il tempo di propagazione 
	//  minore di [vincolo_t] attraverso l'uscita con nome [nome_uscita] e collegata a una capacita [cl]
   //  e con tempo di transizione degli ingressi del circuito [tti]
	double TempoDiPropagazione(string n, double tti, double cl);
	//calcola il tempo di propagazione attraverso l'uscita di nome [n] con capacità di lavoro [cl] e tempo di transizione
	//  degli ingressi del circuito [tti]
	double TempoDiPropagazione(unsigned i_out, double tti, double cl);
	//calcola il tempo di propagazione attraverso l'uscita di indice [i_out] con capacità di lavoro [cl] e tempo di transizione
	//  degli ingressi del circuito [tti]
	
	Componente GeneraComponente();
	
private:
	string nome;
	double area;
	vector<Segnale> segnali;
	vector<Segnale> ingressi;
	vector<Gate> gate;
	vector<Segnale> uscite;
	vector<pair<SegnaleParziale, SegnaleParziale>> collegamenti;
	
	pair<double, double> TempoDiPropagazioneRicorsivo(unsigned i_gate, double tti, double c, unsigned i_out);
	//funzione ricorsiva che restituisce il tempo di propagazione dagli ingressi del circuito al gate di indice [i_gate] e il
	//  tempo di transizione del segnale in uscita dal gate (in questo ordine).
	//  [tti] è il tempo di transizione degli ingressi del circuito, [i_out] l'indice dell'uscita del gate rispetto alla quale
	//  si vogliono calcolare i tempi e [c] la capacita vista da tale uscita
	int CercaUscitaNome(string n);
	//restituisce l'indice dell'uscita con nome [n], o -1 se non è stato trovato nulla
	vector<unsigned> CercaUscitaSegnale(Segnale* s);
	//restituisce l'indice dell'uscita collegata al segnale [s], o -1 se non è stato trovato nulla
	vector<unsigned> CercaIngressoSegnale(SegnaleParziale s);
	//restituisce l'indice dell'ingresso collegata al segnale parziale [s], o -1 se non è stato trovato nulla
	vector<pair<unsigned, unsigned>> CercaGateConSegnaleUscita(SegnaleParziale s);
	//restituisce gli indici dei gate con uscita collegata al segnale parziale [s], assieme all'indice di tale uscita
	vector<pair<unsigned, unsigned>> CercaGateConSegnaleIngresso(SegnaleParziale s);
	//restituisce gli indici dei gate con ingresso collegato al segnale parziale [s], assieme all'indice di tale ingresso
	bool MatchFunzione(unsigned i, unsigned j, vector<Componente>& lib) const;
	//Verifica che il gate di indice [i] abbia la stessa funzione della prima uscita del componente [j] all'interno
	//  della libreria [lib]. Unica eccezione è la funzione NOT1 che può essere abbinata anche alla funzione NOT
	bool Collegati(Segnale* s, Segnale* t) const;
	//funzione che verifica se il segnale [s] è collegato al segnale [t] anche attraverso un numero indefinito di segnali 
	//  nel mezzo
	bool Collegati(SegnaleParziale s, SegnaleParziale t) const;
	//funzione che verifica se il segnale parziale [s] è collegato al segnale parziale [t] anche attraverso un numero 
	//  indefinito di segnali nel mezzo
	bool CollegatiRicorsivo(Segnale* s, pair<unsigned, unsigned> rs, Segnale* t, pair<unsigned, unsigned> rt, vector<Segnale*> &sc) const;
	//funzione che verifica se la parte di segnale [s] nel range [rs] è collegata alla parte di segnale [t] nel range [rt]
	//  anche attraverso un numero indefinito di segnali nel mezzo. La funzione tiene conto di quali segnali intremedi ha già 
	//  controllato nel vettore [sc]
	pair<unsigned, unsigned> TraduciPrimoRange(unsigned i, pair<unsigned, unsigned> r) const;
	//funzione che dato un range [r] per il primo segnale del collegamneto di indice [i] e
	//  restituisce il range del secondo segnale corrispondente
	pair<unsigned, unsigned> TraduciSecondoRange(unsigned i, pair<unsigned, unsigned> r) const;
	//funzione che dato un range [r] per il secondo segnale del collegamneto di indice [i] e
	//  restituisce il range del primo segnale corrispondente
};



#endif 