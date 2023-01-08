#include "Gate.hpp"

// funzioni della classe Uscita
ostream& operator<<(ostream& os, const Uscita& u)
{
	os << u.nome << " => " << u.segnale;
	
	return os;
}

// funzioni della classe Gate
ostream& operator<<(ostream& os, const Gate& g)
{
	os << g.nome << " : " << g.funzione << " port map(";
	for(unsigned i=0; i<g.ingressi.size(); i++)
		os << g.ingressi[i].first << " => " << g.ingressi[i].second << ", ";
	for(unsigned i=0; g.uscite.size()>0 && i<g.uscite.size()-1; i++)
		os << g.uscite[i] << ", ";
	os << g.uscite[g.uscite.size()-1] << ");";
	
	return os;
}

pair<double, double> Gate::TempoDiPropagazione (double ti, double cl, unsigned i_out) const
{
	bool fall = true;
	char tipo = componente_associato->SuffissoTipoTiming(i_out);
	pair <double, double> t;
	
	t.first = componente_associato->TempoDiPropagazione(ti, cl, i_out, string("cf")+tipo);
	t.second = componente_associato->TempoDiPropagazione(ti, cl, i_out, string("cr")+tipo);
	
	if(t.second > t.first)
	{
		fall = false;
		t.first = t.second;
	}
	
	if(fall)
		t.second = componente_associato->TempoDiPropagazione(ti, cl, i_out, string("ft")+tipo);
	else
		t.second = componente_associato->TempoDiPropagazione(ti, cl, i_out, string("rt")+tipo);
	
	return t;
}
