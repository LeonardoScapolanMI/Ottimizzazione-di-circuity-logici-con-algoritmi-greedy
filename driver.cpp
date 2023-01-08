#include "Circuito.hpp"
#include "Componente.hpp"
#include "Config.hpp"
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	Circuito circ;
	double vincolo, tti, c;
	double r;
	bool rispettato;
	
	if(argc!=3 && argc!=4)
	{
		cout << "Inserire come parametro il percorso dei un file VHDL(compresa l'estensione) che descrive un circuito, assieme al nome dell'uscita rispetto alla quale si vogliono calcolare i tempi di propagazione" << endl;
		cout << "Si può aggiungere anche un vincolo al tempo di propagazione direttamnete come terzo parametro, nel qual caso il programma eseguirà un singolo ciclo di ottimizzazione" << endl;
		exit(1);
	}
	
	//caricamento config
	Config::IstanzaConfig()->CaricaConfig("config/traduzione_funzione.txt", "config/equivalenza_funzione.txt",
																				"config/traduzione_gate.txt");
	//caricamento libreria
	ifstream is("cell_library");
	vector<Componente> lib = CaricaLibreria(is);
	is.close();

	//aggiunta dell'adder come componente
	is.open("adder16");
	lib.push_back(CaricaLibreria(is)[0]);
	is.close();

	is.open(string(argv[1]));
	is >> circ;
	
	srand(time(NULL));
	r = rand();
	tti = (r/RAND_MAX)/(1/0.6);
	r = rand();
	c = (r/RAND_MAX)/(1/0.35);

	circ.AssegnaComponentiRandom(lib);
	circ.StampaComponentiAssociati(cout);
	cout << endl;
	cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione(argv[2], tti, c) << endl;
	cout << "Area: " << circ.Area() << endl << endl;

	if(argc==4)
	{
		vincolo = atof(argv[3]);
		rispettato = circ.AssegnaComponentiOttimi(lib, vincolo, argv[2], tti, c);
		cout << "Vincolo rispettato? " << rispettato << endl;
		circ.StampaComponentiAssociati(cout);
		cout << endl;
		cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione(argv[2], tti, c) << endl;
		cout << "Area: " << circ.Area() << endl << endl;
	}
	else
	{
		for(unsigned k=0; k<5; k++)
		{
			cout << "Inserire il tempo di propagazione massimo accettabile: ";
			cin >> vincolo;
			rispettato = circ.AssegnaComponentiOttimi(lib, vincolo, argv[2], tti, c);
			cout << "Vincolo rispettato? " << rispettato << endl;
			circ.StampaComponentiAssociati(cout);
			cout << endl;
			cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione(argv[2], tti, c) << endl;
			cout << "Area: " << circ.Area() << endl << endl;
		}
	}
}