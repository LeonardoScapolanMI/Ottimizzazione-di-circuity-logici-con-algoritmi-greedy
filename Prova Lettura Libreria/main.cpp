#include "../Componente.hpp"
#include "../Config.hpp"
#include <fstream>

int main()
{
	string nome_libreria;
	vector<Componente> libreria;
	
	Config::IstanzaConfig()->CaricaConfig();
	
	/* cout << "Inserisci il file di libreria: ";
	cin >> nome_libreria;
	cout << endl; */
	nome_libreria = "cell_library";
	
	ifstream is;
	is.open(nome_libreria);
	libreria = CaricaLibreria(is);
	cerr << libreria.size() << endl;
	
	nome_libreria.resize(nome_libreria.size()-4);
	nome_libreria+="_return.txt";
	
	//cerr << "Inizio stampa" << endl;
	
	ofstream os(nome_libreria);
	for(unsigned i=0; i<libreria.size(); i++)
	{
		os << libreria[i] << endl;
		
		//if(libreria[i].Nome().find("HA")!=string::npos || libreria[i].Nome().find("FA")!=string::npos)
		cout << libreria[i].Nome() << " " << libreria[i].NomeFunzione() << endl;
	}
}