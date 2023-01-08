#include <vector>
#include <string>
#include <iostream>

#include "../Config.hpp"
#include "../Gate.hpp"
#include "../Componente.hpp"
#include "../Segnale.hpp"
#include "../Componente.hpp"

int main()
{
	cerr << "Lettura Config" << endl;
	Config::IstanzaConfig()->CaricaConfig();
	cerr << "Stampa Config" << endl;
	cout << *(Config::IstanzaConfig()) << endl;
	
	cout << Config::IstanzaConfig()->Equivalenti("NOT", "NOT1") << " " 
		  << Config::IstanzaConfig()->Equivalenti("PROVA3", "PROVA1") << " "
		  << Config::IstanzaConfig()->Equivalenti("PROVA1", "NOT1") << " " 
		  << Config::IstanzaConfig()->Equivalenti("GIANNI", "PROVA1") << endl;
		  
	cout << Config::IstanzaConfig()->NumeroUsciteFunzione("HA") << " " 
		  << Config::IstanzaConfig()->NumeroUsciteFunzione("HA") << " " 
		  << Config::IstanzaConfig()->NumeroUsciteFunzione("TIPO") << endl;
}