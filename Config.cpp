#include "Config.hpp"

Config* Config::istanza_config = 0;

//funzioni della classe TraduzioneFunzione
istream& operator>>(istream& is, TraduzioneFunzione& tf)
{
	char c;
	unsigned n;
	string s;
	is >> tf.nome_funzione >> c >> n;
	tf.nomi_ingressi.clear();
	for(unsigned i=0; i<n; i++)
	{
		is >> s;
		tf.nomi_ingressi.push_back(s);
	}
	is >> n;
	tf.funzioni_uscite.clear();
	for(unsigned i=0; i<n; i++)
	{
		is >> s;
		tf.funzioni_uscite.push_back(s);
	}
	return is;
}
ostream& operator<<(ostream& os, const TraduzioneFunzione& tf)
{
	os << tf.nome_funzione << " : " << tf.nomi_ingressi.size();
	for(unsigned i=0; i<tf.nomi_ingressi.size(); i++)
		os << " " << tf.nomi_ingressi[i];
	os << " " << tf.funzioni_uscite.size();
	for(unsigned i=0; i<tf.funzioni_uscite.size(); i++)
		os << " " << tf.funzioni_uscite[i];
	return os;
}
	
//funzioni della classe config
ostream& operator<<(ostream& os, const Config& c)
{
	os << "Traduzioni Funzioni:" << endl;
	for(unsigned i=0; i<c.traduzioni_funzioni.size(); i++)
		os << c.traduzioni_funzioni[i] << endl;
	os << endl << "Equivalenze Funzioni:" << endl;
	for(unsigned i=0; i<c.equivalenze_funzioni.size(); i++)
	{
		if(c.equivalenze_funzioni[i].size()!=0)
		{
			os << c.equivalenze_funzioni[i].size() << " :";
			for(unsigned j=0; j<c.equivalenze_funzioni[i].size(); j++)
				os << " " << c.equivalenze_funzioni[i][j];
			os << endl;
		}		
	}
	os << endl << "Traduzioni Gate:" << endl;
	if(c.traduzioni_gate.size()!=0)
	{
		for(unsigned i=0; i<c.traduzioni_gate.size()-1; i++)
			os << c.traduzioni_gate[i].first << " : \"" << c.traduzioni_gate[i].second << '\"' << endl;
		
		os << c.traduzioni_gate[c.traduzioni_gate.size()-1].first << " : \"" 
			<< c.traduzioni_gate[c.traduzioni_gate.size()-1].second << '\"';
	}
	
	return os;
}

Config* Config::IstanzaConfig()
{
	if(istanza_config == 0)
		istanza_config = new Config();
	return istanza_config;
}

void Config::CaricaTraduzioniFunzioni(istream& is)
{
	string s;
	TraduzioneFunzione tf;
	traduzioni_funzioni.clear();
	do
	{
		is >> s;
	}while(s!="start");
	
	while(!is.eof())
	{
		is >> tf;
		traduzioni_funzioni.push_back(tf);
	}
}

void Config::CaricaEquivalenzeFunzioni(istream& is)
{
	string s;
	unsigned n;
	vector<string> vs;
	equivalenze_funzioni.clear();
	do
	{
		is >> s;
	}while(s!="start");
	
	while(!is.eof())
	{
		vs.clear();
		is >> n >> s;
		for(unsigned i=0; i<n; i++)
		{
			is >> s;
			vs.push_back(s);
		}
		equivalenze_funzioni.push_back(vs);
	}
}

void Config::CaricaTraduzioniGate(istream& is)
{
	string s, nf;
	char ch;
	traduzioni_gate.clear();
	do
	{
		is >> s;
	}while(s!="start");
	
	while(!is.eof())
	{
		is >> nf >> ch >> ch >> s;
		while((ch=is.get()) != '\"' && !is.eof())
			s.push_back(ch);
		if(!is.eof()) traduzioni_gate.push_back(pair<string, string>(nf, s));
	}
}

void Config::CaricaConfig(string ftf, string fef, string ftg)
{
	ifstream is;
	//cerr << "Lettura Traduzioni Funzioni" << endl;
	is.open(ftf);
	CaricaTraduzioniFunzioni(is);
	is.close();
	//cerr << "Lettura Equivalenze Funzioni" << endl;
	is.open(fef);
	CaricaEquivalenzeFunzioni(is);
	is.close();
	//cerr << "Lettura Traduzioni Gate" << endl;
	is.open(ftg);
	CaricaTraduzioniGate(is);
	is.close();
}

void Config::CaricaConfig()
{
	CaricaConfig("../config/traduzione_funzione.txt", "../config/equivalenza_funzione.txt",
											"../config/traduzione_gate.txt");
}

int Config::CercaTraduzione(Componente* c) const
{
	bool presente;
	string s;
	size_t l;
	
	for(unsigned i=0; i<traduzioni_funzioni.size(); i++)
	{
		presente = false;
		if(c->NumIngressi() == traduzioni_funzioni[i].NumNomiIngressi() && 
		   c->NumUscite() == traduzioni_funzioni[i].NumFunzioniUscite())
		{
			presente = true;
			for(unsigned j=0; presente && j<traduzioni_funzioni[i].NumFunzioniUscite(); j++)
			{
				s=traduzioni_funzioni[i].VediFunzioneUscita(j);
				for(unsigned k=0; k<traduzioni_funzioni[i].NumNomiIngressi(); k++)
					while((l=s.find(traduzioni_funzioni[i].VediNomeIngresso(k)))!=string::npos && 
							c->VediIngresso(k).Nome()!=traduzioni_funzioni[i].VediNomeIngresso(k))
						s.replace(l, traduzioni_funzioni[i].VediNomeIngresso(k).size(), c->VediIngresso(k).Nome());
				
				if(s!=c->VediUscita(j).Funzione())
					presente=false;
			}
			if(presente)
				return i;
		}
	}
	
	return -1;
}

bool Config::Equivalenti(string nf1, string nf2) const
{
	unsigned i_1;
	bool trovato = false;
	for(unsigned i=0; !trovato && i<equivalenze_funzioni.size(); i++)
		for(unsigned j=0; !trovato && j<equivalenze_funzioni[i].size(); j++)
			if(nf1 == equivalenze_funzioni[i][j])
			{
				i_1 = i;
				trovato = true;
			}
			
	if(trovato)
		for(unsigned j=0; j<equivalenze_funzioni[i_1].size(); j++)
			if(nf2 == equivalenze_funzioni[i_1][j])
				return true;
			
	return false;
}

int Config::NumeroUsciteFunzione(string nf) const
{
	for(unsigned i=0; i<traduzioni_funzioni.size(); i++)
		if(nf == traduzioni_funzioni[i].NomeFunzione())
			return traduzioni_funzioni[i].NumFunzioniUscite();
		
	return -1;
}

Gate Config::TraduciGate(string s, Circuito* c) const  //da testare
{
	Gate g;
	string t, out;
	size_t pos;
	vector<string> in;
	bool trovato;
	int i_traduzione;
	
	stringstream ss(s);
	ss >> out >> t;
	
	ss >> t;
	while(t.find('(')==0)
		t.erase(t.begin());
	while(t.find(')')!=string::npos)
		t.erase(t.end()-1);
	if(t.find('(')!=string::npos)
		t.push_back(')');
	in.push_back(t);
	//cerr << out << " " << t;
	while(!ss.eof())
	{
		ss >> t;
		if(!ss.eof())
		{
			ss >> t;
			while(t.find('(')==0)
				t.erase(t.begin());
			while(t.find(')')!=string::npos)
				t.erase(t.end()-1);
			if(t.find('(')!=string::npos)
				t.push_back(')');
			trovato=false;
			for(unsigned i=0; !trovato && i<in.size(); i++)
				if(in[i]==t)
					trovato=true;
			if(!trovato)
				in.push_back(t);
		}
	}
	
	for(unsigned i=0; i<in.size(); i++)
		while((pos=s.find(in[i]))!=string::npos)
			s.replace(pos, in[i].size(), "X");
	
	s.replace(0, out.size(), "X");
	
	//cerr << s << endl;
	
	i_traduzione = -1;
	for(unsigned i=0; i_traduzione==-1 && i<traduzioni_gate.size(); i++)
		if(traduzioni_gate[i].second == s)
			i_traduzione = i;

	if(i_traduzione == -1)
		throw invalid_argument ("Uno dei gate definiti implicitamente non ha traduzione");
	else
	{
		g.SetNome("gate_implicito");
		g.SetFunzione(traduzioni_gate[i_traduzione].first);
		g.AggiungiUscita("out0", c->GeneraSegnaleParziale(out));
		for(unsigned i=0; i<in.size(); i++)
			g.AggiungiIngresso("in"+to_string(i), c->GeneraSegnaleParziale(in[i]));
	}
	
	return g;
}