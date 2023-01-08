#include "../funzioni.hpp"
#include "../componente.hpp"
#include <fstream>

int main()
{
	string nome_libreria;
	vector<Componente> libreria;
	
	cout << "Inserisci il file di libreria: ";
	cin >> nome_libreria;
	cout << endl;
	
	ifstream is;
	is.open(nome_libreria);
	libreria = CaricaLibreria(is);
	
	ofstream os("lista_componenti.txt");
	for(unsigned i=0; i<libreria.size(); i++)
	{
		os << libreria[i].Nome() << endl;
		for(unsigned j=0; j<libreria[i].NumUscite(); j++)
			os << libreria[i].VediUscita(j).Nome() << " " << libreria[i].VediUscita(j).Funzione() << " " << libreria[i].VediUscita(j).NomeFunzione() << endl;
		os << endl;
	}
	
}