#include "../Circuito.hpp"
#include "../Componente.hpp"
#include "../Config.hpp"
#include <fstream>

int main()
{
	Circuito circ;
	double vincolo, tti, c;
	//double r;
	Config::IstanzaConfig()->CaricaConfig();
	ifstream is("cell_library");
	vector<Componente> lib = CaricaLibreria(is);
	is.close();
	/* is.open("adder16");
	lib.push_back(CaricaLibreria(is)[0]);
	cout << lib[lib.size()-1].NomeFunzione() << endl;
	is.close(); */
	
	is.open("../../Circuiti_reali/adder16.vhdl");
	is >> circ;
	
	//r = rand();
	tti = 0.014; //(r/RAND_MAX)/(1/0.6);
	//r = rand();
	c = 0.07; //(r/RAND_MAX)/(1/0.35);
	
	circ.AssegnaComponentiRandom(lib);
	circ.StampaComponentiAssociati(cout);
	cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione(0, tti, c) << endl;
	cout << "Area: " << circ.Area() << endl << endl;
	
	for(unsigned k=0; k<5; k++)
	{
		cout << "inserisci il vincolo:";
		cin >> vincolo;
		cout << "Vincolo rispettato? " << circ.AssegnaComponentiOttimi(lib, vincolo, "sum", tti, c) << endl;
		circ.StampaComponentiAssociati(cout);
		cout << endl;
		cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione("sum", tti, c) << endl;
		cout << "Area: " << circ.Area() << endl << endl;
	}
		
}