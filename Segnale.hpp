#ifndef SEGNALE_HPP
#define SEGNALE_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Segnale
{
	friend ostream& operator<<(ostream& os, const Segnale& s);
public:
	Segnale() {}
	Segnale(string n, string t, bool dt=true, unsigned d=0) {nome=n; tipo=t; downto=dt; dimensione= d;}
	string Nome() const {return nome;}
	string Tipo() const {return tipo;}
	bool Downto() const {return downto;}
	unsigned Dimensione() const {return dimensione;}
	
private:	
	string nome;
	string tipo;
	bool downto;
	unsigned dimensione;
};

class SegnaleParziale
{
	friend ostream& operator<<(ostream& os, const SegnaleParziale& s);
	friend istream& operator>>(istream& is, SegnaleParziale& s);
public:
	SegnaleParziale() {segnale = nullptr;};
	SegnaleParziale(Segnale* s) {segnale=s; range_segnale.first=0; range_segnale.second=s->Dimensione()-1; downto=s->Downto();}
	SegnaleParziale(Segnale* s, unsigned i, unsigned f) 
						{segnale=s; range_segnale.first=i; range_segnale.second=f; downto=s->Downto();}
	SegnaleParziale(Segnale* s, unsigned i, unsigned f, bool d) 
						{segnale=s; range_segnale.first=i; range_segnale.second=f; downto=d;}
	Segnale* SegnaleAssociato() const {return segnale;}
	pair<unsigned, unsigned> RangeSegnale() const {return range_segnale;}
	bool Downto() const {return downto;}
	bool InRange(pair<unsigned, unsigned> r) const {return !(r.second<range_segnale.first || range_segnale.second<r.first);}
private:
	Segnale* segnale;
	pair<unsigned, unsigned> range_segnale;
	bool downto;
};

#endif