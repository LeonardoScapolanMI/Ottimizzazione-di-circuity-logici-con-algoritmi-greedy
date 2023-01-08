#include "../Circuito.hpp"
#include "../Config.hpp"
#include <fstream>

#define N_CIRCUITI 29

int main()
{
	string nome_file, nome_file_return;
	Circuito c;
	
	Config::IstanzaConfig()->CaricaConfig();
	
	/* cout << "Inserisci il file con la descrizione del circuito: ";
	cin >> nome_file;
	cout << endl; */
	
	ifstream is;
	ofstream os;
	
	/* nome_file = "../../Circuiti_casuali/rc.001.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	
	cerr << c.NumSegnali() << endl;
	
	nome_file_return = "Circuiti_casuali_return/rc.001.vhdl";
	os.open(nome_file_return);
	os << c;
	os.close(); */
	
	unsigned i;
	for(i=1; i<10 && i<=N_CIRCUITI; i++)
	{
		//cerr << "Lettura Circuito " << i << endl;
		nome_file = "../../Circuiti_casuali/rc.00" + to_string(i) + ".vhdl";
		is.open(nome_file);
		is >> c;
		is.close();
		cout << i << " " << c.NumGate() << endl;
		//nome_file_return=nome_file.substr(0, nome_file.rfind('.'));
		//nome_file_return+="_return.vhdl";
		//cerr << "Scrittura Circuito " << i << endl;
		//nome_file_return = "Circuiti_casuali_return/rc.00" + to_string(i) + ".vhdl";
		//os.open(nome_file_return);
		//os << c;
		//os.close();
	}
	
	for(; i<100 && i<=N_CIRCUITI; i++)
	{
		//cerr << "Lettura Circuito " << i << endl;
		nome_file = "../../Circuiti_casuali/rc.0" + to_string(i) + ".vhdl";
		is.open(nome_file);
		is >> c;
		is.close();
		cout << i << " " << c.NumGate() << endl;
		//nome_file_return=nome_file.substr(0, nome_file.rfind('.'));
		//nome_file_return+="_return.vhdl";
		//cerr << "Scrittura Circuito " << i << endl;
		//nome_file_return = "Circuiti_casuali_return/rc.0" + to_string(i) + ".vhdl";
		//os.open(nome_file_return);
		//os << c;
		//os.close();
	} 
	
	nome_file = "../../Circuiti_reali/adder16.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "A16 " << c.NumGate() << endl;
	
	nome_file = "../../Circuiti_reali/adder64.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "A64 " << c.NumGate() << endl;
	
	nome_file = "../../Circuiti_reali/deco3.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "D3 " << c.NumGate() << endl;
	
	nome_file = "../../Circuiti_reali/deco4.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "D4 " << c.NumGate() << endl;
	
	nome_file = "../../Circuiti_reali/deco5.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "D5 " << c.NumGate() << endl;
	
	nome_file = "../../Circuiti_reali/deco6.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "D6 " << c.NumGate() << endl;
	
	nome_file = "../../Circuiti_reali/multiplier11.vhdl";
	is.open(nome_file);
	is >> c;
	is.close();
	cout << "M " << c.NumGate() << endl;
	/* string nome_circuito = "multiplier11.vhdl";
	
	nome_file = "../../Circuiti_reali/" + nome_circuito;
	is.open(nome_file);
	is >> c;
	is.close();
	
	//cerr << c.NumSegnali() << endl;
	
	nome_file_return = "Circuiti_reali_return/" + nome_circuito;
	os.open(nome_file_return);
	os << c;
	os.close(); */
	
}