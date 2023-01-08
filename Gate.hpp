#ifndef GATE_HPP
#define GATE_HPP

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include "Componente.hpp"
#include "Segnale.hpp"

class Uscita
{
	friend ostream& operator<<(ostream& os, const Uscita& u);
public:
	Uscita(){}
	Uscita(string n, SegnaleParziale s){nome=n; segnale=s; capacita_vista=0;}
	string Nome() const {return nome;}
	SegnaleParziale Segnale() const {return segnale;}
	double CapacitaVista() const {return capacita_vista;}
	double& CapacitaVista() {return capacita_vista;}
	void SetNome(string n) {nome=n;}
	void SetSegnale(SegnaleParziale s) {segnale=s;}
	
private:
	string nome;
	SegnaleParziale segnale;
	double capacita_vista;
};

class Gate
{
	friend ostream& operator<<(ostream& os, const Gate& g);
public:
	Gate(){componente_associato = nullptr;}
	string Nome() const {return nome;}
	string Funzione() const {return funzione;}
	unsigned NumIngressi() const {return ingressi.size();}
	pair<string,SegnaleParziale> VediIngresso(unsigned i) const {return ingressi[i];}
	unsigned NumUscite() const {return uscite.size();}
	const Uscita& VediUscita(unsigned i) const {return uscite[i];}
	Uscita& VediUscita(unsigned i) {return uscite[i];}
	Componente* ComponenteAssociato() const {return componente_associato;}
	
	void SetNome(string n) {nome=n;}
	void SetFunzione(string f) {funzione=f;}
	void AggiungiIngresso(string n, SegnaleParziale s) {ingressi.push_back(pair<string,SegnaleParziale>(n,s));}
	void RimuoviIngresso(unsigned i) {ingressi.erase(ingressi.begin()+i);}
	void AggiungiUscita(string n, SegnaleParziale s) {uscite.push_back(Uscita(n, s));}
	void RimuoviUscita(unsigned i) {uscite.erase(uscite.begin()+i);}
	void AssociaComponente(Componente* c){componente_associato = c;}
	
	pair<double, double> TempoDiPropagazione (double ti, double cl, unsigned i_out) const;
	//funzione che restituisce il caso peggiore tra tempo di rise e di fall con relativo tempo di transizone attraverso l'uscita
	//  di indice [i_out] con capacità di lavoro [cl] e tempo di transizione in ingresso [ti]
private:
	string nome;
	string funzione;
	vector<pair<string,SegnaleParziale>> ingressi;
	vector<Uscita> uscite;
	Componente* componente_associato;
};


#endif 