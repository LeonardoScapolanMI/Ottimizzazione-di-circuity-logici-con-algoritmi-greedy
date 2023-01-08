#include "Circuito.hpp"
#include "Config.hpp"

//funzioni per la calsse Circuito
istream& operator>>(istream& is, Circuito& c)
{
	string s, n, nf, m, t;
	char ch;
	unsigned u1, u2;
	int num;
	bool dt, buttato;
	vector <string> nomi;
	Gate g;
	
	c.area = 0;
	c.segnali.clear();
	c.ingressi.clear();
	c.gate.clear();
	c.uscite.clear();
	c.collegamenti.clear();
	
	do{
		is >> s;
	}while(s!="entity");
	is >> c.nome >> s >> s >> ch;
	
	//cerr << "checkpoint 1" << endl;
	
	while(is.peek() != ')')
	{
		u1=0;
		u2=0;
		dt=true;
		is >> n >> ch >> m >> s;
		if(s.find('(')!=string::npos && s.find(')')==string::npos)
		{
			while((ch=is.get())!=')')
				s.push_back(ch);
			s.push_back(ch);
			if(is.peek()==';')
				is.get();
		}
		if(s[s.size()-1]!=';')
			s.push_back(';');
		//cerr << n << " " << m << " " << s << endl;
		
		//cerr << s << endl;
		stringstream ss(s);
		
		//cerr << "checkpoint 1.1" << endl;
		
		t.clear();
		while(ss.peek()!=';' && ss.peek()!='(')
			t.push_back(ss.get());
		
		//cerr << "checkpoint 1.2" << endl;
		
		if(ss.peek()=='(')
		{
			ss >> ch >> u1 >> s >> u2;
			dt = s=="downto";
			if(!dt)
				u1=u2;
		}
		
		//cerr << "checkpoint 1.3" << endl;
		//cerr << n << " " << m << " " << t << " " << dt << " " << u1 << endl;
		for(unsigned i=0; i<n.size(); i++)
			n[i]=tolower(n[i]);
		if(m == "in")
			c.ingressi.push_back(Segnale(n, t, dt, u1+1));
		else if(m == "out")
			c.uscite.push_back(Segnale(n, t, dt, u1+1));
		else
			throw invalid_argument ("Modalità di uno dei pin non supportata");
		
		is >> ws;
	}
	
	do{
		is >> s;
	}while(s!="signal" && s!="begin");
	
	//cerr << "checkpoint 2" << endl;
	
	while(s=="signal")
	{
		nomi.clear();
		is >> n;
		do
		{
			if(n.find(',')==n.size()-1)
				n.pop_back();
			nomi.push_back(n);
			is >> n;
		}while(n!=":");
		
		s.clear();
		while((ch=is.get())!=';')
			s.push_back(ch);
		s.push_back(ch);
		stringstream ss(s);
		t.clear();
		u1=0;
		dt=true;
		ss >> ws;
		while(ss.peek()!=';' && ss.peek()!='(')
			t.push_back(ss.get());
		
		if(ss.peek()=='(')
		{
			ss >> ch >> u1 >> s >> u2;
			dt = s=="downto";
			if(!dt)
				u1=u2;
		}
		//cerr << nomi[0] << " " << t << " " << dt << " " << u1+1 << endl;
		for(unsigned i=0; i<nomi.size(); i++)
		{
			for(unsigned j=0; j<n.size(); j++)
				nomi[i][j]=tolower(nomi[i][j]);
			c.segnali.push_back(Segnale(nomi[i], t, dt, u1+1));
		}
		
		is >> s;
	}
	
	//cerr << "checkpoint 3" << endl;
	
	is >> t;
	if(t.find('(')!=string::npos && t.find(')')==string::npos)
	{
		while((ch=is.get())!=')')
			t.push_back(ch);
		t.push_back(ch);
	}
	
	while(t!="end")
	{
		is >> s;
		//cerr << t << " " << s << " ";
		if(s==":")
		{
			//cerr << "Gate" << endl;
			while(g.NumIngressi()!=0)
				g.RimuoviIngresso(g.NumIngressi());
			while(g.NumUscite()!=0)
				g.RimuoviUscita(g.NumUscite());
			
			//cerr << "checkpoint 3.1" << endl;
			
			g.SetNome(t);
			is >> nf;
			g.SetFunzione(nf);
			
			//cerr << t << " " << nf << endl;
			
			while(is.get()!='(');
			
			//cerr << is.peek() << endl;
			
			is >> n >> s >> m;
			if(m.find('(')!=string::npos && m.find(')')==string::npos)
			{
				while((ch=is.get())!=')')
					m.push_back(ch);
				m.push_back(ch);
				while(is.peek()==',' || is.peek()==')' || is.peek()==';')
					m.push_back(is.get());
			}
			
			while(m[m.size()-1] == ',')
			{
				//cerr << n << s << m << endl;
				m.pop_back();
				g.AggiungiIngresso(n, c.GeneraSegnaleParziale(m));
				is >> n >> s >> m;
				if(m.find('(')!=string::npos && m.find(')')==string::npos)
				{
					while((ch=is.get())!=')')
						m.push_back(ch);
					m.push_back(ch);
					while(is.peek()==',' || is.peek()==')' || is.peek()==';')
						m.push_back(is.get());
				}
			}
			
			buttato = false;
			while(m[m.size()-1] == ';' || (m.find('(') != string::npos && m.find(')')!=m.rfind(')')) || 
					(m.find('(') == string::npos && m.find(')') != string::npos))
			{
				m.pop_back();
				buttato = true;
			}
			
			//cerr << "checkpoint 3.2" << endl;
			//cerr << nf << endl;
			if((num=Config::IstanzaConfig()->NumeroUsciteFunzione(nf))>1)
			{
				//cerr << " dentro l'if" << endl;
				for(unsigned i=0; i<static_cast<unsigned>(num-1); i++)
				{
					g.AggiungiUscita(g.VediIngresso(g.NumIngressi()-1).first, g.VediIngresso(g.NumIngressi()-1).second);
					g.RimuoviIngresso(g.NumIngressi()-1);
				}
			}
			
			//cerr << "checkpoint 3.3" << endl;
			g.AggiungiUscita(n, c.GeneraSegnaleParziale(m));
			c.gate.push_back(g);

			if(!buttato)
				while(is.get() != ';' && !is.eof());
		}
		else if(s=="<=")
		{
			is >> m;
			//cerr << m << endl;
			if(m.find('(')!=string::npos && m.find('(')!=0 && m.find(')')==string::npos)
			{
				while((ch=is.get())!=')')
					m.push_back(ch);
				m.push_back(ch);
				if(is.peek()==';')
					m.push_back(is.get());
			}
			if(m[m.size()-1] == ';')
			{
				//cerr << "Collegamento" << endl;
				m.pop_back();
				//cerr << t << " " << m << endl;
				c.collegamenti.push_back(pair<SegnaleParziale, SegnaleParziale>
													(c.GeneraSegnaleParziale(t), c.GeneraSegnaleParziale(m)));
			}
			else
			{
				is >> n;
				if(n=="&")
				{
					//cerr << "Multi-Collegamento" << endl;
					vector<SegnaleParziale> vsp;
					SegnaleParziale out = c.GeneraSegnaleParziale(t);
					//cerr << t << endl;
					m.erase(m.begin());
					vsp.push_back(c.GeneraSegnaleParziale(m));
					//cerr << "checkpoint 3.3.1" << endl;
					is >> m;
					if(m.find('(')!=string::npos && m.find(')')==string::npos)
					{
						while((ch=is.get())!=')')
							m.push_back(ch);
						m.push_back(ch);
					}
					while(m[m.size()-1]!=';')
					{
						vsp.push_back(c.GeneraSegnaleParziale(m));
						is >> n >> m;
						if(m.find('(')!=string::npos && m.find(')')==string::npos)
						{
							while((ch=is.get())!=')')
								m.push_back(ch);
							m.push_back(ch);
						}
						//cerr << n << " " << m << endl;
					}
					m.pop_back();
					m.pop_back();
					vsp.push_back(c.GeneraSegnaleParziale(m));
					//cerr << "checkpoint 3.3.2" << endl;
					if(out.Downto())
					{
						u1 = out.RangeSegnale().second;
						for(unsigned i=0; i<vsp.size(); i++)
						{
							c.collegamenti.push_back(pair<SegnaleParziale, SegnaleParziale>(SegnaleParziale(out.SegnaleAssociato(),
																				u1-(vsp[i].RangeSegnale().second- vsp[i].RangeSegnale().first),
																				u1, out.Downto()), vsp[i]));
							u1=u1-(vsp[i].RangeSegnale().second- vsp[i].RangeSegnale().first)-1;
						}
					}
					else
					{
						u1 = out.RangeSegnale().first;
						for(unsigned i=0; i<vsp.size(); i++)
						{
							c.collegamenti.push_back(pair<SegnaleParziale, SegnaleParziale>(SegnaleParziale(out.SegnaleAssociato(), u1,
																				u1+(vsp[i].RangeSegnale().second- vsp[i].RangeSegnale().first),
																				out.Downto()), vsp[i]));
							u1=u1+(vsp[i].RangeSegnale().second- vsp[i].RangeSegnale().first)+1;
						}
					}
				}
				else
				{
					//cerr << "Gate Implicito" << endl;
					s = t + " <= " + m + " " + n;
					m.clear();
					while((ch = is.get()) != ';')
						m.push_back(ch);
					s += m;
					//cerr << s << endl;
					c.gate.push_back(Config::IstanzaConfig()->TraduciGate(s, &c));
				}
			}
		}
		
		is >> t;
		//cerr << t;
		if(t.find('(')!=string::npos && t.find(')')==string::npos)
		{
			while((ch=is.get())!=')')
				t.push_back(ch);
			t.push_back(ch);
		}
		
		//cerr << "t: " << t << endl;
	}
	
	return is;
}

ostream& operator<<(ostream& os, const Circuito& c)
{
	vector<unsigned> indici;
	
	os << "----------------------------------------------------------------------" << endl;
	os << "entity " << c.nome << " is" << endl;
	os << "\tport (" << endl;
	for(unsigned i=0; i<c.ingressi.size(); i++)
	{
		os << "\t\t" << setfill(' ') << left << setw(9) << c.ingressi[i].Nome() << ": in  ";
		os << c.ingressi[i].Tipo();
		if(c.ingressi[i].Tipo()=="std_logic_vector")
		{
			os << '(';
			if(c.ingressi[i].Downto())
				os << c.ingressi[i].Dimensione()-1 << " downto 0";
			else
				os << "0 to " << c.ingressi[i].Dimensione()-1;
			os << ')';
		}
		os << ";" << endl;
	}
	for(unsigned i=0; c.uscite.size()>0 && i<c.uscite.size()-1; i++)
	{
		os << "\t\t" << setfill(' ') << left << setw(9) << c.uscite[i].Nome() << ": out ";
		os << c.uscite[i].Tipo();
		if(c.uscite[i].Tipo()=="std_logic_vector")
		{
			os << '(';
			if(c.uscite[i].Downto())
				os << c.uscite[i].Dimensione()-1 << " downto 0";
			else
				os << "0 to " << c.uscite[i].Dimensione()-1;
			os << ')';
		}
		os << ";" << endl;
	}
	os << "\t\t" << setfill(' ') << left << setw(9) << c.uscite[c.uscite.size()-1].Nome() << ": out ";
	os << c.uscite[c.uscite.size()-1].Tipo();
	if(c.uscite[c.uscite.size()-1].Tipo()=="std_logic_vector")
	{
		os << '(';
		if(c.uscite[c.uscite.size()-1].Downto())
			os << c.uscite[c.uscite.size()-1].Dimensione()-1 << " downto 0";
		else
			os << "0 to " << c.uscite[c.uscite.size()-1].Dimensione()-1;
		os << ')';
	}
	os << endl << "\t);" << endl;
	os << "end " << c.nome << ';' << endl;
	os << "----------------------------------------------------------------------" << endl << endl;
	os << "----------------------------------------------------------------------" << endl;
	os << "architecture struct of " << c.nome << " is" << endl;
	for(unsigned i=0; i<c.segnali.size(); i++) 
		os << "\t" << c.segnali[i] << endl;
	os << "begin" << endl;
	for(unsigned i=0; i<c.collegamenti.size(); i++)
		os << "\t" << c.collegamenti[i].first << " <= " << c.collegamenti[i].second << ";" << endl;
	for(unsigned i=0; i<c.gate.size(); i++)
		os << '\t' << c.gate[i] << endl;
	os << "end struct;" << endl;
	os << "----------------------------------------------------------------------" << endl;
	
	return os;
}

void Circuito::StampaComponentiAssociati(ostream& os) const
{
	unsigned i;
	if(gate.size()!=0)
	{
		for(i=0; i<gate.size()-1; i++)
		{
			os << gate[i].Nome() << " : ";
			if(gate[i].ComponenteAssociato() != nullptr)
				os << gate[i].ComponenteAssociato()->Nome();
			else 
				os << "Nessuno";
			os << endl;
		}

		os << gate[i].Nome() << " : ";
		if(gate[i].ComponenteAssociato() != nullptr)
			os << gate[i].ComponenteAssociato()->Nome();
		else 
			os << "Nessuno";
	}
}

SegnaleParziale Circuito::GeneraSegnaleParziale(string m)
{
	char c;
	string n;
	bool trovato=false;
	Segnale* sig;
	unsigned u1, u2;
	
	if((m[0]=='\'' && m[m.size()-1]=='\'') || (m[0]=='\"' && m[m.size()-1]=='\"'))
		return SegnaleParziale();
	
	stringstream ss(m);
	
	while(!ss.eof() && ss.peek()!='(')
	{
		ss >> c;
		if(!ss.eof())
			n.push_back(c);
	}
	
	for(unsigned i=0; i<n.size(); i++)
		n[i]=tolower(n[i]);
	
	for(unsigned i=0; i<ingressi.size(); i++)
	{
		if(!trovato && ingressi[i].Nome() == n)
		{
			sig = &ingressi[i];
			trovato = true;
		}
	}
	for(unsigned i=0; i<segnali.size(); i++)
	{
		if(!trovato && segnali[i].Nome() == n)
		{
			sig = &segnali[i];
			trovato = true;
		}
	}	
	for(unsigned i=0; i<uscite.size(); i++)
	{
		if(!trovato && uscite[i].Nome() == n)
		{
			sig = &uscite[i];
			trovato = true;
		}
	}	
	
	if(!trovato)
		throw logic_error ("Il segnale "+ n +" non è dichiarato");
	
	if(ss.eof())
		return SegnaleParziale(sig);
	
	ss >> c >> u1;
	if(ss.peek()==')')
		return SegnaleParziale(sig, u1, u1);

	ss >> n >> u2 >> c;
	trovato = (n=="downto");
	if(u1<u2)
		return SegnaleParziale(sig, u1, u2, trovato);

	return SegnaleParziale(sig, u2, u1, trovato);
}

bool Circuito::AssociaComponente(unsigned i, Componente* comp)
{
	double c;
	for(unsigned j=0; j<gate.size(); j++)
		for(unsigned k=0; k<gate[j].NumUscite(); k++)
			for(unsigned l=0; l<gate[i].NumIngressi(); l++)
				if(Collegati(gate[i].VediIngresso(l).second, gate[j].VediUscita(k).Segnale()))
				{
					c=gate[j].VediUscita(k).CapacitaVista();
					if(gate[i].ComponenteAssociato()!=nullptr)
						c-=gate[i].ComponenteAssociato()->VediIngresso(l).Capacita();
					
					c+=comp->VediIngresso(l).Capacita();
					
					if(c>gate[j].ComponenteAssociato()->VediUscita(k).MaxCapacitapilotabile())
						return false;
					
					gate[j].VediUscita(k).CapacitaVista()=c;
				}		
	if(gate[i].ComponenteAssociato()!=nullptr)
		area-=gate[i].ComponenteAssociato()->Area();
	gate[i].AssociaComponente(comp);
	area+=gate[i].ComponenteAssociato()->Area();
	return true;
}

bool Circuito::AssegnaComponentiRandom(vector<Componente>& lib)
{
	vector<unsigned> indici;
	unsigned j_rand;
	srand((unsigned) time(0));
	
	for(unsigned i=0; i<gate.size(); i++)
	{
		indici.clear();
		//cerr << "Generazione vettore indici" << endl;
		for(unsigned j=0; j<lib.size(); j++)
			if(MatchFunzione(i, j, lib))
				indici.push_back(j);
		
		if(indici.size()==0)
			throw logic_error ("Nessun componente implementa la funzione " + gate[i].Funzione());
		
		//cerr << "Generazione j_rand; numero indici: " << indici.size() << endl;
		j_rand = rand()%indici.size();
		while(indici.size()!=0 && !AssociaComponente(i, &lib[indici[j_rand]]))
		{
			indici.erase(indici.begin()+j_rand);
			//cerr << "Generazione j_rand" << endl;
			if(indici.size()!=0)
				j_rand = static_cast<unsigned>(rand()%indici.size());			
		}
		if(indici.size()==0)
				return false;
	}
	return true;
}

bool Circuito::AssegnaComponentiOttimi(vector<Componente>& lib, double vincolo_t, string nome_uscita, double tti, double cl)
{
	vector<unsigned> indici;
	bool vincolo_rispettato = TempoDiPropagazione(nome_uscita, tti, cl)<=vincolo_t;
	double area_min;
	Componente* componente_ottimo;
	
	for(unsigned i=0; i<gate.size(); i++)
		if(gate[i].ComponenteAssociato()==nullptr)
			throw logic_error ("Prima di cercare la configurazione ottima, c'è bisogno che ad ogni gate sia associato un componente\n");
	
	if(vincolo_rispettato)
		area_min = area;
		
	
	for(unsigned i=0; i<gate.size(); i++)
	{
		cerr << "Gate: " << i << endl;
		// cerr << "Generazione vettore indici" << endl;
		indici.clear();
		for(unsigned j=0; j<lib.size(); j++)
			if(MatchFunzione(i, j, lib))
				indici.push_back(j);
			
		if(indici.size()==0)
			throw logic_error ("Nessun componente implementa la funzione " + gate[i].Funzione());
		
		// for(unsigned j=0; j<indici.size()-1; j++)
			// cerr << lib[indici[j]].Nome() << " ";
		// cerr << lib[indici[indici.size()-1]].Nome() << endl;
		
		componente_ottimo = gate[i].ComponenteAssociato();
		
		// cerr << "Inizio ottiizzzione" << endl;
		for(unsigned k=0; k<indici.size(); k++)
		{
			if(AssociaComponente(i, &lib[indici[k]]))
			{
				if(TempoDiPropagazione(nome_uscita, tti, cl)<=vincolo_t)
				{
					if(!vincolo_rispettato)
					{	
						area_min = area;
						vincolo_rispettato = true;
					}
					
					if(area <= area_min)
					{
						componente_ottimo = gate[i].ComponenteAssociato();
						area_min = area;
					}
				}
				AssociaComponente(i, componente_ottimo);
			}
		}	
	}
	
	return vincolo_rispettato;
}

double Circuito::TempoDiPropagazione(string n, double tti, double cl)
{
	int i_out;
	if(uscite.size() == 0)
		throw logic_error("Nessuna uscita");
	if((i_out=CercaUscitaNome(n))==-1)
		throw invalid_argument("Nessuna uscita con il nome " + n);
	for(unsigned i=0; i<gate.size(); i++)
		if(gate[i].ComponenteAssociato()==nullptr)
			throw logic_error ("Prima di cercare il tempo di propagazione, c'è bisogno che ad ogni gate sia associato un componente\n");
		
	return TempoDiPropagazione(i_out, tti, cl);
}

double Circuito::TempoDiPropagazione(unsigned i_out, double tti, double cl)
{
	double t_max, t_aux;
	
	for(unsigned i=0; i<gate.size(); i++)
		if(gate[i].ComponenteAssociato()==nullptr)
			throw logic_error ("Prima di cercare il tempo di propagazione, c'è bisogno che ad ogni gate sia associato un componente\n");
		
	vector<pair<unsigned,unsigned>> indici_gate = CercaGateConSegnaleUscita(SegnaleParziale(&uscite[i_out]));
	
	if(indici_gate.size()==0)
		throw logic_error("Nessun gate Collegato all'uscita del circuito numero "+to_string(i_out)+'\n');
	
	t_max = TempoDiPropagazioneRicorsivo(indici_gate[0].first, tti, cl, indici_gate[0].second).first;
	for(unsigned i=1; i<indici_gate.size(); i++)
	{
		t_aux = TempoDiPropagazioneRicorsivo(indici_gate[i].first, tti, cl, indici_gate[i].second).first;
		if(t_aux>t_max)
			t_max = t_aux;
	}
	
	return t_max;
}

pair<double, double> Circuito::TempoDiPropagazioneRicorsivo(unsigned i_gate, double tti, double c, unsigned i_out) 
{
	pair <double, double> t_max, t_aux1, t_aux2;
	vector<pair<unsigned,unsigned>> i_gate_collegati;
	bool primo = true;
	
	//cerr << "Inizio ricorsione per " << gate[i_gate].Nome() << endl;
	if(gate[i_gate].NumIngressi()==0)
		return pair<double, double> (0, tti); //si suppone che un gate senza ingressi generi un segnale istantaneamente e con
	                                         //un tempo di transizione pari a quello degli ingressi del circuito
														  //(nella libreria fornita c'è un componente senza ingressi senza alcuna
														  //specifica sui suoi tempi di propagazione/transizione)
	
	for(unsigned i=0; i<gate[i_gate].NumIngressi(); i++)
	{
		//cerr << "Sto esaminando il suo ingresso di indice " << i << endl;
		if(CercaIngressoSegnale(gate[i_gate].VediIngresso(i).second).size()!=0)
		{
			//cerr << "\tIl gate è collegato a un ingresso del circuito" << endl;
			t_aux1=gate[i_gate].TempoDiPropagazione(tti, c, i_out);
			if(primo || t_aux1.first > t_max.first)
			{
				if(primo)
					primo=false;
				t_max = t_aux1;
			}
		}
		else if((i_gate_collegati=CercaGateConSegnaleUscita(gate[i_gate].VediIngresso(i).second)).size()!=0)
		{
			for(unsigned j=0; j<i_gate_collegati.size(); j++)
			{
				t_aux1 = TempoDiPropagazioneRicorsivo(i_gate_collegati[j].first, tti, 
						gate[i_gate_collegati[j].first].VediUscita(i_gate_collegati[j].second).CapacitaVista(), 
						i_gate_collegati[j].second);
				t_aux2 = gate[i_gate].TempoDiPropagazione(t_aux1.second, c, i_out);
				if(primo || t_aux1.first + t_aux2.first > t_max.first)
				{
					if(primo)
						primo=false;
					t_max.first = t_aux1.first + t_aux2.first;
					t_max.second = t_aux2.second;
				}
			}
		}
		else if(gate[i_gate].VediIngresso(i).second.SegnaleAssociato()==nullptr)
		{
			t_aux1=gate[i_gate].TempoDiPropagazione(0, c, i_out);
			if(primo || t_aux1.first > t_max.first)
			{
				if(primo)
					primo=false;
				t_max = t_aux1;
			}
		}
		else 
			throw logic_error("L'ingresso "+to_string(i)+" del gate "+to_string(i_gate)+" non è collegato a nulla\n");
	}
	//cerr << "Fine ricorsione per " << gate[i_gate].Nome() << ": " << t_max.first << " " << t_max.second << endl;
	
	return t_max;
}

int Circuito::CercaUscitaNome(string n)
{
	for(unsigned i=0; i<uscite.size(); i++)
		if(uscite[i].Nome() == n)
			return i;
		
	return -1;
}

vector<unsigned> Circuito::CercaUscitaSegnale(Segnale* s)
{
	vector<unsigned> indici;
	for(unsigned i=0; i<uscite.size(); i++)
		if(Collegati(s, &uscite[i]))
			indici.push_back(i);
		
	return indici;
}

vector<unsigned> Circuito::CercaIngressoSegnale(SegnaleParziale s)
{
	vector<unsigned> indici;
	for(unsigned i=0; i<ingressi.size(); i++)
		if(Collegati(s, SegnaleParziale(&ingressi[i])))
			indici.push_back(i);
		
	return indici;
}

vector<pair<unsigned, unsigned>> Circuito::CercaGateConSegnaleUscita(SegnaleParziale s)
{
	vector<pair<unsigned, unsigned>> indici;
	for(unsigned i=0; i<gate.size(); i++)
		for(unsigned j=0; j<gate[i].NumUscite(); j++)
			if(Collegati(s, gate[i].VediUscita(j).Segnale()))
				indici.push_back(pair<unsigned,unsigned>(i,j));
	
	return indici;
}

vector<pair<unsigned, unsigned>> Circuito::CercaGateConSegnaleIngresso(SegnaleParziale s)
{
	vector<pair<unsigned, unsigned>> indici;
	for(unsigned i=0; i<gate.size(); i++)
		for(unsigned j=0; j<gate[i].NumIngressi(); j++)
			if(Collegati(s, gate[i].VediIngresso(j).second))
				indici.push_back(pair<unsigned,unsigned>(i,j));
	
	return indici;
}

bool Circuito::MatchFunzione(unsigned i, unsigned j, vector<Componente>& lib) const
{
	if(gate[i].Funzione()==lib[j].NomeFunzione())
		return true;
	
	if(Config::IstanzaConfig()->Equivalenti(gate[i].Funzione(), lib[j].NomeFunzione()))
		return true;

	return false;
}

bool Circuito::Collegati(Segnale* s, Segnale* t) const
{
	vector<Segnale*> sc;
	pair<unsigned, unsigned> rs(0, s->Dimensione()-1);
	pair<unsigned, unsigned> rt(0, t->Dimensione()-1);
	//cerr << "\t\t" << s->Nome() << " e " << t->Nome() << " collegati?" << endl;
	return CollegatiRicorsivo(s, rs, t, rt, sc);
}

bool Circuito::Collegati(SegnaleParziale s, SegnaleParziale t) const
{
	vector<Segnale*> sc;
	//cerr << "\t\t" << s << " e " << t << " collegati?" << endl;
	return CollegatiRicorsivo(s.SegnaleAssociato(), s.RangeSegnale(), t.SegnaleAssociato(), t.RangeSegnale(), sc);
}

bool Circuito::CollegatiRicorsivo(Segnale* s, pair<unsigned, unsigned> rs, Segnale* t, pair<unsigned, unsigned> rt, vector<Segnale*> &sc) const
{
	bool presente;
	pair<unsigned, unsigned> rc;
	sc.push_back(t);
	
	if(s==nullptr || t==nullptr)
		return false;
	
	//cerr << "\t\t\t" << s->Nome() << " e " << t->Nome() << " collegati?" << endl;
	
	
	if(s==t && !(rs.second<rt.first || rt.second<rs.first))
		return true;
	
	for(unsigned i=0; i<collegamenti.size(); i++)
		if((collegamenti[i].first.SegnaleAssociato()==s && collegamenti[i].first.InRange(rs) && 
			 collegamenti[i].second.SegnaleAssociato()==t && collegamenti[i].second.InRange(rt)) ||
			(collegamenti[i].first.SegnaleAssociato()==t && collegamenti[i].first.InRange(rt) && 
			 collegamenti[i].second.SegnaleAssociato()==s && collegamenti[i].second.InRange(rs)))
			return true;
	
	for(unsigned i=0; i<collegamenti.size(); i++)
	{		
		if(t == collegamenti[i].first.SegnaleAssociato() && collegamenti[i].first.InRange(rt))
		{
			//cerr << "dentro primo if" << endl;
			presente = false;
			for(unsigned j=0; j<sc.size() && !presente; j++)
				if(sc[j] == collegamenti[i].second.SegnaleAssociato())
					presente = true;
		
			if(!presente)
			{
				rc=TraduciPrimoRange(i,rt);
				if(CollegatiRicorsivo(s, rs, collegamenti[i].second.SegnaleAssociato(), rc, sc))
					return true;
			}
		}
		if(t == collegamenti[i].second.SegnaleAssociato() && collegamenti[i].second.InRange(rt))
		{
			//cerr << "dentro secondo if" << endl;
			presente = false;
			for(unsigned j=0; j<sc.size() && !presente; j++)
				if(sc[j] == collegamenti[i].first.SegnaleAssociato())
					presente = true;
		
			if(!presente)
			{
				rc=TraduciSecondoRange(i,rt);
				if(CollegatiRicorsivo(s, rs, collegamenti[i].first.SegnaleAssociato(), rc, sc))
					return true;
			}
		}
	}
	
	return false;
}

pair<unsigned, unsigned> Circuito::TraduciPrimoRange(unsigned i, pair<unsigned, unsigned> r) const
{
	pair<unsigned, unsigned> rreturn;
	
	if(collegamenti[i].first.Downto()==collegamenti[i].second.Downto())
	{
		if(r.first<=collegamenti[i].first.RangeSegnale().first)
			rreturn.first = collegamenti[i].second.RangeSegnale().first;
		else
			rreturn.first = collegamenti[i].second.RangeSegnale().first + (r.first-collegamenti[i].first.RangeSegnale().first);
	
		if(r.second>=collegamenti[i].first.RangeSegnale().second)
			rreturn.second = collegamenti[i].second.RangeSegnale().second;
		else
			rreturn.second = collegamenti[i].second.RangeSegnale().second - (collegamenti[i].first.RangeSegnale().second-r.second);
	}
	else
	{
		if(r.first<=collegamenti[i].first.RangeSegnale().first)
			rreturn.second = collegamenti[i].second.RangeSegnale().second;
		else
			rreturn.second = collegamenti[i].second.RangeSegnale().second - (r.first-collegamenti[i].first.RangeSegnale().first);
	
		if(r.second>=collegamenti[i].first.RangeSegnale().second)
			rreturn.first = collegamenti[i].second.RangeSegnale().first;
		else
			rreturn.first = collegamenti[i].second.RangeSegnale().first + (collegamenti[i].first.RangeSegnale().second-r.second);
	}
	return rreturn;
}

pair<unsigned, unsigned> Circuito::TraduciSecondoRange(unsigned i, pair<unsigned, unsigned> r) const
{
	pair<unsigned, unsigned> rreturn;
	if(collegamenti[i].first.Downto()==collegamenti[i].second.Downto())
	{
		if(r.first<=collegamenti[i].second.RangeSegnale().first)
			rreturn.first = collegamenti[i].first.RangeSegnale().first;
		else
			rreturn.first = collegamenti[i].first.RangeSegnale().first + (r.first-collegamenti[i].second.RangeSegnale().first);
	
		if(r.second>=collegamenti[i].second.RangeSegnale().second)
			rreturn.second = collegamenti[i].first.RangeSegnale().second;
		else
			rreturn.second = collegamenti[i].first.RangeSegnale().second - (collegamenti[i].second.RangeSegnale().second-r.second);
	}
	else
	{
		if(r.first<=collegamenti[i].second.RangeSegnale().first)
			rreturn.second = collegamenti[i].first.RangeSegnale().second;
		else
			rreturn.second = collegamenti[i].first.RangeSegnale().second - (r.first-collegamenti[i].second.RangeSegnale().first);
	
		if(r.second>=collegamenti[i].second.RangeSegnale().second)
			rreturn.first = collegamenti[i].first.RangeSegnale().first;
		else
			rreturn.first = collegamenti[i].first.RangeSegnale().first + (collegamenti[i].second.RangeSegnale().second-r.second);
	}
	return rreturn;
}

Componente Circuito::GeneraComponente()
{
	pair<double, double> t_max, t_aux;
	vector<pair<unsigned,unsigned>> indici_gate;
	double min_cap;
	vector<Timing> cf, ft;
	vector<PinOut> out;
	vector<PinIn> in;
	vector<double> c{0.0014, 0.013, 0.026, 0.053, 0.11, 0.21}, tti{0.005, 0.035, 0.07, 0.14, 0.28, 0.56};
	
	for(unsigned i=0; i<gate.size(); i++)
		if(gate[i].ComponenteAssociato()==nullptr)
			throw logic_error ("Prima di generare il componente, c'è bisogno che ad ogni gate sia associato un componente\n");
	
	for(unsigned i=0; i<uscite.size(); i++)
	{
		indici_gate = CercaGateConSegnaleUscita(SegnaleParziale(&uscite[i]));
	
		if(indici_gate.size()==0)
			throw logic_error("Nessun gate Collegato all'uscita del circuito numero "+to_string(i)+'\n');
		for(unsigned j=0; j<tti.size(); j++)
		{
			for(unsigned k=0; k<c.size(); k++)
			{
	
				t_max = TempoDiPropagazioneRicorsivo(indici_gate[0].first, tti[j], c[k], indici_gate[0].second);
				for(unsigned l=1; l<indici_gate.size(); l++)
				{
					t_aux = TempoDiPropagazioneRicorsivo(indici_gate[l].first, tti[j], c[k], indici_gate[l].second);
					if(t_aux.first>t_max.first)
						t_max = t_aux;
				}
				cf.push_back(Timing(tti[j], c[k], t_max.first));
				ft.push_back(Timing(tti[j], c[k], t_max.second));
			}
		}
		min_cap = gate[indici_gate[0].first].ComponenteAssociato()->VediUscita(indici_gate[0].second).MaxCapacitapilotabile();
		for(unsigned l=1; l<indici_gate.size(); l++)
			if(min_cap > gate[indici_gate[l].first].ComponenteAssociato()->VediUscita(indici_gate[l].second).MaxCapacitapilotabile())
				min_cap = gate[indici_gate[l].first].ComponenteAssociato()->VediUscita(indici_gate[l].second).MaxCapacitapilotabile();
		out.push_back(PinOut("out"+to_string(i), min_cap, "", nome, cf, cf, ft, ft));
	}
	
	min_cap = 0;
	for(unsigned i=0; i<ingressi.size(); i++)
	{
		indici_gate = CercaGateConSegnaleUscita(SegnaleParziale(&uscite[i]));
		for(unsigned l=1; l<indici_gate.size(); l++)
			min_cap += gate[indici_gate[0].first].ComponenteAssociato()->VediIngresso(indici_gate[0].second).Capacita();
		
		in.push_back(PinIn("in"+to_string(i), min_cap));
	}
	
	return Componente("my"+nome, area, nome, in, out);
}