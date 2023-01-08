#include <fstream>
#include <cmath>
#include "../Config.hpp"
#include "../Circuito.hpp"

#define N_CIRCUITI 29

int main()
{
	vector<Componente> libreria;
	Config::IstanzaConfig()->CaricaConfig();
	
	/* string tempo;
	int uscita, tipo_tempo;
	double tti, c, r;
	srand((unsigned) time(0));
	
	ifstream is("HA1X18.txt");
	libreria = CaricaLibreria(is);
	
	for(int i=0; i<5; i++)
	{		
		r = rand();
		uscita = static_cast<unsigned>(r/RAND_MAX+0.5);
		r = rand();
		tipo_tempo = static_cast<unsigned>(3*(r/RAND_MAX)+0.5);
		r = rand();
		tti = (r/RAND_MAX)/(1/0.6);
		r = rand();
		c =(r/RAND_MAX)/(1/0.35);
		switch(tipo_tempo)
		{
			case 0 : tempo = "cf"; break;
			case 1 : tempo = "cr"; break;
			case 2 : tempo = "ft"; break;
			case 3 : tempo = "rt"; break;
			default: exit(1); break;
		}
		cout << uscita << " " << tempo << " " << tti << " " << c << endl;
		cout << libreria[0].TempoDiPropagazione(tti, c, 2, tempo+libreria[0].SuffissoTipoTiming(uscita)) << endl;
		cin.ignore();
	} */
	
	/* Circuito circ;
	pair<double, double> t;
	
	ifstream is("XOR2.txt");
	libreria = CaricaLibreria(is);
	is.close();
	cerr << "Checkpoint main 1" << endl;
	is.open("XOR2.vhdl");
	is >> circ;
	cerr << "Checkpoint main 2" << endl;
	circ.AssegnaComponentiRandom(libreria);
	cerr << "Checkpoint main 3" << endl;
	circ.StampaComponentiAssociati(cout);
	cout << endl;
	cerr << "Checkpoint main 4" << endl;
	t = circ.VediGate(0).TempoDiPropagazione(0.005, 0.0014, 0);
	cout << t.first << " " << t.second << endl; */
	
	/* Circuito circ;
	double tp;
	pair<double, double> t;
	double tti, c, r;
	
	r = rand();
	tti = (r/RAND_MAX)/(1/0.6);
	r = rand();
	c =(r/RAND_MAX)/(1/0.35);
	
	ifstream is("cell_library");
	libreria = CaricaLibreria(is);
	is.close();
	
	is.open("circuito.vhdl");
	is >> circ;
	
	circ.AssegnaComponentiRandom(libreria);
	// for(unsigned i=0; i<libreria.size(); i++)
	// {
		// if(libreria[i].Nome()=="AND2X4")
			// circ.AssociaComponente(0, &libreria[i]);
		// if(libreria[i].Nome()=="OR2X18")
			// circ.AssociaComponente(1, &libreria[i]);
		// if(libreria[i].Nome()=="XOR2X18")
			// circ.AssociaComponente(2, &libreria[i]);
	// }
	circ.StampaComponentiAssociati(cout);
	cout << endl;
	// cout << circ.VediGate(0).ComponenteAssociato()->Nome() << " " << circ.VediGate(1).ComponenteAssociato()->Nome() << " " << circ.VediGate(2).ComponenteAssociato()->Nome() << endl;
	// cout << circ.VediGate(0).VediUscita(0).Segnale() << " " << circ.VediGate(2).VediIngresso(0).second << endl;
	// cout << circ.VediGate(1).VediUscita(0).Segnale() << " " << circ.VediGate(2).VediIngresso(1).second << endl;
	t = circ.VediGate(0).TempoDiPropagazione(tti, circ.VediGate(2).ComponenteAssociato()->VediIngresso(0).Capacita(), 0);
	cout << t.first << " " << t.second << endl;
	t = circ.VediGate(2).TempoDiPropagazione(t.second, c, 0);
	cout << t.first << " " << t.second << endl;
	t = circ.VediGate(1).TempoDiPropagazione(tti, circ.VediGate(2).ComponenteAssociato()->VediIngresso(1).Capacita(), 0);
	cout << t.first << " " << t.second << endl;
	t = circ.VediGate(2).TempoDiPropagazione(t.second, c, 0);
	cout << t.first << " " << t.second << endl;
	
	tp = circ.TempoDiPropagazione("out0", tti, c);
	cout << tp << endl; */
	
	/* Circuito circ;
	double tp;
	pair<double, double> t;
	string nome_file;
	double tti, c, r;
	unsigned i;
	
	ifstream is("cell_library");
	libreria = CaricaLibreria(is);
	is.close();
	
	for(i=1; i<10 && i<=N_CIRCUITI; i++)
	{
		cerr << i << endl;
		nome_file = "../../Circuiti_casuali/rc.00" + to_string(i) + ".vhdl";
		is.open(nome_file);
		is >> circ;
		is.close();
	
		cerr << "Generazione numeri casuali" << endl;
		r = rand();
		cerr << r << endl;
		cerr << "Prima divisione" << endl;
		tti = (r/RAND_MAX)/(1/0.6);
		cerr << tti << endl;
		cerr << r << endl;
		r = rand();
		cerr << "Seconda divisione" << endl;
		c =(r/RAND_MAX)/(1/0.35);
		
		cerr << tti << " " << c << endl;
		circ.AssegnaComponentiRandom(libreria);
		cerr << "Stampa componenti" << endl;
		circ.StampaComponentiAssociati(cout);
		cout << endl;
	
		cerr << endl << "Inizio calcolo tempi" << endl;
		tp = circ.TempoDiPropagazione(0, tti, c);
		cout << tp << endl << endl;
	}
	
	for(; i<100 && i<=N_CIRCUITI; i++)
	{
		cerr << i << endl;
		nome_file = "../../Circuiti_casuali/rc.0" + to_string(i) + ".vhdl";
		is.open(nome_file);
		is >> circ;
		is.close();
		
		cerr << "Generazione muneri casuali" << endl;
		r = rand();
		tti = (r/RAND_MAX)/(1/0.6);
		r = rand();
		c =(r/RAND_MAX)/(1/0.35);
		
		circ.AssegnaComponentiRandom(libreria);
		cerr << "Stampa componenti" << endl;
		circ.StampaComponentiAssociati(cout);
		cout << endl;
	
		cerr << endl << "Inizio calcolo tempi" << endl;
		tp = circ.TempoDiPropagazione(0, tti, c);
		cout << tp << endl << endl;
	} */
	
	Circuito circ;
	double tp;
	pair<double, double> t;
	double tti, c;
	//double r;
	
	//r = rand();
	tti = 0.07; //(r/RAND_MAX)/(1/0.6);
	//r = rand();
	c = 0.2; //(r/RAND_MAX)/(1/0.35);
	
	ifstream is("cell_library");
	libreria = CaricaLibreria(is);
	is.close();
	
	string nome_circuito = "multiplier11.vhdl";
	is.open("../../Circuiti_reali/" + nome_circuito);
	is >> circ;
	
	circ.AssegnaComponentiRandom(libreria);
	circ.StampaComponentiAssociati(cout);
	
	tp = circ.TempoDiPropagazione("res", tti, c);
	cout << tp << endl;
}