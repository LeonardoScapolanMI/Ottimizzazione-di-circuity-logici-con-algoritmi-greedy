#include "../Circuito.hpp"
#include "../Componente.hpp"
#include "../Config.hpp"
#include <fstream>

int main()
{
	Circuito circ;
	double vincolo, tti, c;
	Config::IstanzaConfig()->CaricaConfig();
	ifstream is("../../cell_library");
	vector<Componente> lib = CaricaLibreria(is);
	is.close();
	
	is.open("../../Circuiti_reali/adder16.vhdl");
	is >> circ;
	is.close();
	
	tti = 0.014;
	c = 0.07;
	
	circ.AssegnaComponentiRandom(lib);
	circ.StampaComponentiAssociati(cout);
	cout << endl;
	cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione(0, tti, c) << endl;
	cout << "Area: " << circ.Area() << endl << endl;
	vincolo = 1.95;
	for(unsigned k=0; k<3; k++)
	{
		cout << "Vincolo rispettato? " << circ.AssegnaComponentiOttimi(lib, vincolo, "sum", tti, c) << endl;
		circ.StampaComponentiAssociati(cout);
		cout << endl;
		cout << "Tempo di Propagazione: " << circ.TempoDiPropagazione("sum", tti, c) << endl;
		cout << "Area: " << circ.Area() << endl << endl;
		vincolo -= 0.1;
	}
	
	ofstream os("adder16");
	os << circ.GeneraComponente();
		
}