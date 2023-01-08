#ifndef COMPONENTE_HPP
#define COMPONENTE_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm> 
#include <cmath>

using namespace std;

class Componente;

class Timing
{
	friend ostream& operator<< (ostream& os, const Timing& t);
	friend istream& operator>> (istream& is, Timing& t);
	
public:
	Timing(){}
	Timing(double tti, double cv, double t){tempo_transizione_ingresso=tti; capacita_vista=cv; tempo=t;}
	double TempoTransizioneIngresso() const {return tempo_transizione_ingresso;}
	double CapacitaVista() const {return capacita_vista;}
	double Tempo() const {return tempo;}
	
	double Distanza(double tti, double c) const {return sqrt((tempo_transizione_ingresso-tti)*(tempo_transizione_ingresso-tti)
														+(capacita_vista-c)*(capacita_vista-c));}
	
private:
	double tempo_transizione_ingresso;
	double capacita_vista;
	double tempo;
};

class PinIn
{
	friend ostream& operator<< (ostream& os, const PinIn& p);
	friend vector<Componente> CaricaLibreria(istream& is);
	
public:
	PinIn(){}
	PinIn(string n, double c){nome=n; capacita=c;}
	string Nome() const {return nome;}
	double Capacita() const {return capacita;}
	
private:
	string nome;
	double capacita;
};

class PinOut
{
	friend ostream& operator<< (ostream& os, const PinOut& p);
	friend vector<Componente> CaricaLibreria(istream& is);
	
public:
	PinOut(){}
	PinOut(string n, double c, string f, string nf, vector<Timing> cf, vector<Timing> cr, vector<Timing> ft, vector<Timing> rt)
			{nome=n; max_capacita_pilotabile=c; funzione=f; nome_funzione=nf; cell_fall=cf; cell_rise=cr; fall_transition=ft; 
			rise_transition=rt;}
	string Nome() const {return nome;}
	double MaxCapacitapilotabile() const {return max_capacita_pilotabile;}
	string Funzione() const {return funzione;}
	string NomeFunzione() const {return nome_funzione;}
	
	double TempoDiPropagazione(double tti, double c, string t) const;
	//funzione che restituisce il tempo di propagazione/transizione indicato dalla stringa identificativa [t] attraverso
	//	 un interpolazione dei dati disponibili in funzione della capacita di lavoro [c] e del tempo di trnsizione del segnale
	//  in ingresso [tti]
	char SuffissoTipoTiming() const;
	//funzione che restituisce l'ultimo carattere della stringa identificativa del tempo di  propagazione/transizione corretto
	//  i possibili valori di ritorno sono: - p n 
	
private:
	string nome;
	double max_capacita_pilotabile;
	string funzione;
	string nome_funzione;
	vector<Timing> cell_fall;
	vector<Timing> cell_rise;
	vector<Timing> fall_transition;
	vector<Timing> rise_transition;
	vector<Timing> cell_fall_positive;
	vector<Timing> cell_rise_positive;
	vector<Timing> fall_transition_positive;
	vector<Timing> rise_transition_positive;
	vector<Timing> cell_fall_negative;
	vector<Timing> cell_rise_negative;
	vector<Timing> fall_transition_negative;
	vector<Timing> rise_transition_negative;
	
	const vector<Timing>* SelezioneTiming(string t) const;
	//restituisce il puntatore al tempo di  propagazione(transizione) identificato dalla stringa [t]
};

class Componente
{
	friend ostream& operator<< (ostream& os, const Componente& c);
	friend vector<Componente> CaricaLibreria(istream& is);
	
public:
	Componente(){}
	Componente(string n, double a, string nf, vector<PinIn> i, vector<PinOut> u){nome=n; area=a; nome_funzione=nf;
			ingressi=i; uscite=u;}
	string Nome() const {return nome;}
	double Area() const {return area;}
	string NomeFunzione() const {return nome_funzione;}
	unsigned NumIngressi() const {return ingressi.size();}
	const PinIn& VediIngresso(unsigned i) const {return ingressi[i];}
	unsigned NumUscite() const {return uscite.size();}
	const PinOut& VediUscita(unsigned i) const {return uscite[i];}
	
	double TempoDiPropagazione(double tti, double c, unsigned i_out, string t) const;
	//funzione che restituisce il tempo di propagazione/transizione indicato dalla stringa identificativa [t] attraverso
	//	 un interpolazione dei dati disponibili in funzione della capacita di lavoro [c] e del tempo di trnsizione del segnale
	//  in ingresso [tti] attraverso l'uscita di indice [i_out]
	char SuffissoTipoTiming(unsigned i_out) const {return uscite[i_out].SuffissoTipoTiming();}
	
private:
	string nome;
	double area;
	string nome_funzione;
	vector<PinIn> ingressi;
	vector<PinOut> uscite;
	
	void GeneraNomeFunzione();
	//funzione che converte le informazioni sulla funzione delle singole uscite del componente nella funzione che il 
	//  componente implementa
};

vector<Timing> RicercaTrePiuVicini(const vector<Timing>& t, double tti, double c);
//restituisce i tre tempi di  propagazione(transizione) che nel piano (tempo transizione ingressi, capacita) 
//  sono più vicini al punto ([tti], [c]) senza che essi, nello spazio tempo transizione ingressi, capacita, tempo propagazione)
//  siano allineati e senza che per essi passi un paino parallelo all'asse tempo propagazione

vector<double> CalcolaCoefficenti(const vector<Timing>& t);
//calcola i coefficenti per l'interpolazione locale attorno ai punti [t] 

double DeterminanteTrePerTre(vector<vector<double>> m);
//funzione che calcola il determinante della matrice 3x3 [m]
//precondizione: la matrice deve essere 3x3 (invalid_argument)

bool Allineati(const vector<Timing>& t);
//funzione che verifica se i tre punti nello spazio (tempo transizione ingressi, capacita, tempo propagazione)
//  rappresentati dal vettore [t] sono allineati

bool PianoParalleloTerzoAsse(const vector<Timing>& t);
//funzione che verifica se per i tre punti nello spazio (tempo transizione ingressi, capacita, tempo propagazione)
//  rappresentati dal vettore [t] passi un piano parallelo all'asse dei tempi di propagazione

vector<Componente> CaricaLibreria(istream& is);
//funzione per il caricamento della libreria dal file associato allo stream [is]

void PulisciSpazi(istream& is);
//funzione che elimina dallo stream di ingresso is tutti i caratteri ASCII che non sono strettamente caratteri

#endif