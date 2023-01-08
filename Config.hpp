#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Circuito.hpp"
#include "Gate.hpp"
#include "Componente.hpp"

using namespace std;

class TraduzioneFunzione
{
	friend istream& operator>>(istream& is, TraduzioneFunzione& tf);
	friend ostream& operator<<(ostream& os, const TraduzioneFunzione& tf);
public:
	TraduzioneFunzione() {}
	string NomeFunzione() const {return nome_funzione;}
	unsigned NumNomiIngressi() const {return nomi_ingressi.size();}
	string VediNomeIngresso(unsigned i) const {return nomi_ingressi[i];}
	unsigned NumFunzioniUscite() const {return funzioni_uscite.size();}
	string VediFunzioneUscita(unsigned i) const {return funzioni_uscite[i];}
private:
	string nome_funzione;
	vector<string> nomi_ingressi;
	vector<string> funzioni_uscite;
};

class Config
{
	friend ostream& operator<<(ostream& os, const Config& c);
public:
	static Config* IstanzaConfig();
	unsigned NumTraduzioniFunzioni() const {return traduzioni_funzioni.size();}
	const TraduzioneFunzione& VediTraduzioneFunzione(unsigned i) const {return traduzioni_funzioni[i];}
	unsigned NumEquivalenzeFunzioni() const {return equivalenze_funzioni.size();}
	vector<string> VediEquivalenzeFunzione(unsigned i) const {return equivalenze_funzioni[i];}
	unsigned NumTraduzioniGate() const {return traduzioni_gate.size();}
	pair<string, string> VediTraduzioneGate(unsigned i) const {return traduzioni_gate[i];}
	void CaricaTraduzioniFunzioni(istream& is);
	void CaricaEquivalenzeFunzioni(istream& is);
	void CaricaTraduzioniGate(istream& is);
	void CaricaConfig(string ftf, string fef, string ftg);
	void CaricaConfig();
	int CercaTraduzione(Componente* c) const;
	bool Equivalenti(string nf1, string nf2) const;
	int NumeroUsciteFunzione(string nf) const;
	Gate TraduciGate(string s, Circuito* c) const;
private:
	Config() {};
	static Config* istanza_config;
	vector<TraduzioneFunzione> traduzioni_funzioni;
	vector<vector<string>> equivalenze_funzioni;
	vector<pair<string, string>> traduzioni_gate;
};

#endif