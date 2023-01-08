#include "../componente.hpp"
#include <fstream>

int main()
{
	vector<Componente> libreria;
	
	ifstream is;
	is.open("cell_library");
	libreria = CaricaLibreria(is);
	
	/* bool b;
	string f = "XOR2";
	ofstream os;
	os.open(f + ".txt");
	
	for(unsigned i=0; i<libreria.size(); i++)
	{
		b=false;
		for(unsigned j=0; j<libreria[i].NumUscite(); j++)
			if(libreria[i].VediUscita(j).NomeFunzione()==f)
				b=true;
		
		if(b)
			os << libreria[i] << endl;
	} */
	
	bool b;
	ofstream os;
	os.open("GateConPiuTipiTiming.txt");
	
	for(unsigned i=0; i<libreria.size(); i++)
	{
		b = false;
		for(unsigned j=0; j<libreria[i].NumUscite(); j++)
			if((libreria[i].VediUscita(j).NumCellFall()>0 && libreria[i].VediUscita(j).NumCellFallPositive()>0)||
				(libreria[i].VediUscita(j).NumCellFall()>0 && libreria[i].VediUscita(j).NumCellFallNegative()>0)||
				(libreria[i].VediUscita(j).NumCellFallNegative()>0 && libreria[i].VediUscita(j).NumCellFallPositive()>0))
				b=true;
		if(b)
			os << libreria[i];
	}
}