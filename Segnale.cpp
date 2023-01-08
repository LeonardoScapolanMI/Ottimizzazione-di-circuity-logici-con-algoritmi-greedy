#include "Segnale.hpp"
//funzioni della classe Segnale
ostream& operator<<(ostream& os, const Segnale& s)
{
	char c = os.fill();
	os.fill(' ');
	os << "signal ";
	os.width(11);
	os << left << s.nome;
	os << ": " << s.tipo;
	if(s.tipo=="std_logic_vector")
	{
		os << '(';
		if(s.downto)
			os << s.dimensione-1 << " downto 0";
		else
			os << "0 to " << s.dimensione-1;
		os << ')';
	}
	os << ';';
	os.fill(c);
	return os;
}

//funzioni della classe SegnaleParziale

ostream& operator<<(ostream& os, const SegnaleParziale& s)
{
	if(s.segnale==nullptr)
	{
		os << "\'SEGNALE COSTANTE\'";
		return os;
	}
	
	os << s.segnale->Nome();
	
	if(s.segnale->Tipo() == "std_logic_vector")
	{
		os << '(';
		if(s.range_segnale.first == s.range_segnale.second)
		{
			os << s.range_segnale.first;
		}
		else
		{
			if(s.downto)
				os << s.range_segnale.second << " downto " << s.range_segnale.first;
			else
				os << s.range_segnale.first << " to " << s.range_segnale.second;
		}
		os << ')';
	}
			
	return os;
}