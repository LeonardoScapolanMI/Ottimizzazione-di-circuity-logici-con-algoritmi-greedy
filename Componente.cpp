#include "Componente.hpp"
#include "Config.hpp"
//funzioni per la classe Timing
ostream& operator<< (ostream& os, const Timing& t)
{
	os << t.tempo_transizione_ingresso << " " << t.capacita_vista << " " << t.tempo;
	return os;
}

istream& operator>> (istream& is, Timing& t)
{
	is >> t.tempo_transizione_ingresso >> t.capacita_vista >> t.tempo;
	return is;
}

//funzioni per la classe PinIn
ostream& operator<< (ostream& os, const PinIn& p)
{
	os << p.nome << "    <-  (" << p.capacita << ")";
	return os;
}

//funzioni per la classe PinOut
ostream& operator<< (ostream& os, const PinOut& p)
{
	// cerr << "stampa funzione" << endl;
	os << p.nome << "    ->  (" << p.max_capacita_pilotabile << ") (" << p.funzione << ")";
	
	// cerr << "stampa nome funzione" << endl;
	if(p.nome_funzione!="")
		os << "	--- " << p.nome_funzione;
	
	// cerr << "stampa timing" << endl;
	for(unsigned i=0; i<p.cell_fall.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "cell_fall" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.cell_fall[i];
	}
	
	for(unsigned i=0; i<p.cell_rise.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "cell_rise" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.cell_rise[i];
	}
	
	for(unsigned i=0; i<p.fall_transition.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "fall_transition" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.fall_transition[i];
	}

	for(unsigned i=0; i<p.rise_transition.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "rise_transition" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.rise_transition[i];
	}

	for(unsigned i=0; i<p.cell_fall_positive.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "cell_fall positive_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.cell_fall_positive[i];
	}

	for(unsigned i=0; i<p.cell_rise_positive.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "cell_rise positive_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.cell_rise_positive[i];
	}

	for(unsigned i=0; i<p.fall_transition_positive.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "fall_transition positive_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.fall_transition_positive[i];
	}

	for(unsigned i=0; i<p.rise_transition_positive.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "rise_transition positive_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.rise_transition_positive[i];
	}

	for(unsigned i=0; i<p.cell_fall_negative.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "cell_fall negative_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.cell_fall_negative[i];
	}

	for(unsigned i=0; i<p.cell_rise_negative.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "cell_rise negative_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.cell_rise_negative[i];
	}

	for(unsigned i=0; i<p.fall_transition_negative.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "fall_transition negative_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.fall_transition_negative[i];
	}

	for(unsigned i=0; i<p.rise_transition_negative.size(); i++)
	{
		os << endl;
		if(i==0)
			os << "      " << "rise_transition negative_unate" << endl
		        << "            input_net_transition total_output_net_capacitance time" << endl;
		
		os << "            " << p.rise_transition_negative[i];
	}

	return os;
}

double PinOut::TempoDiPropagazione(double tti, double c, string t) const
{
	const vector<Timing>* t1;
	if((t1 = SelezioneTiming(t)) == nullptr)
		throw invalid_argument("La stringa di selezione non è in un formato accettabile");
	
	vector<Timing> tm = RicercaTrePiuVicini(*t1, tti, c);
	
	//cerr << "a+" << tm[0].TempoTransizioneIngresso() << "*b+" << tm[0].CapacitaVista() << "*c=" << tm[0].Tempo() << endl;
	//cerr << "a+" << tm[1].TempoTransizioneIngresso() << "*b+" << tm[1].CapacitaVista() << "*c=" << tm[1].Tempo() << endl;
	//cerr << "a+" << tm[2].TempoTransizioneIngresso() << "*b+" << tm[2].CapacitaVista() << "*c=" << tm[2].Tempo() << endl;

	vector<double> coefficenti = CalcolaCoefficenti(tm);
	
	//cerr << coefficenti[0] << " " << coefficenti[1] << " " << coefficenti[2] << endl;
	
	return coefficenti[0] + coefficenti[1]*tti + coefficenti[2]*c;
}

char PinOut::SuffissoTipoTiming() const
{
	if(cell_fall.size() >=3 && cell_rise.size() >=3 && fall_transition.size() >=3 && rise_transition.size() >=3)
		return '-';
	
	if(cell_fall_positive.size() >=3 && cell_rise_positive.size() >=3 && fall_transition_positive.size() >=3 && rise_transition_positive.size() >=3)
		return 'p';
	
	return 'n';
}

const vector<Timing>* PinOut::SelezioneTiming(string t) const
{
	if(t=="cf-")
		return &cell_fall;
	if(t=="cr-")
		return &cell_rise;
	if(t=="ft-")
		return &fall_transition;
	if(t=="rt-")
		return &rise_transition;
	if(t=="cfp")
		return &cell_fall_positive;
	if(t=="crp")
		return &cell_rise_positive;
	if(t=="ftp")
		return &fall_transition_positive;
	if(t=="rtp")
		return &rise_transition_positive;
	if(t=="cfn")
		return &cell_fall_negative;
	if(t=="crn")
		return &cell_rise_negative;
	if(t=="ftn")
		return &fall_transition_negative;
	if(t=="rtn")
		return &rise_transition_negative;
	
	return nullptr;
}

//funzioni per la classe Componente
ostream& operator<<(ostream& os, const Componente& c)
{
	// cerr << "stampa nome e area" << endl;
	
	os << "  " << c.nome << endl
	   << "    area: " << c.area << endl;
		
	// cerr << "stampa ingressi" << endl;
	for(unsigned i=0; i<c.ingressi.size(); i++)
		os << "    " << c.ingressi[i] << endl;
	
	// cerr << "stampa uscite" << endl;
	if(c.uscite.size()!=0)
	{
		for(unsigned i=0; i<c.uscite.size()-1; i++)
			os << "    " << c.uscite[i] << endl;
	
		os << "    " << c.uscite[c.uscite.size()-1];
	}
	
	return os;
}

double Componente::TempoDiPropagazione(double tti, double c, unsigned i_out, string t) const
{
	if(uscite.size() == 0)
		throw logic_error("Nessuna uscita\n");
	
	if(uscite.size() <= i_out)
		throw invalid_argument("Indice " + to_string(i_out) + " troppo grande; " + (uscite.size()-1==1?"c'e":"ci sono") + " solo " + to_string(uscite.size()-1) + " uscit" + (uscite.size()-1==1?"a":"e") + "\n");
	
	return uscite[i_out].TempoDiPropagazione(tti, c, t);
}

void Componente::GeneraNomeFunzione()
{
	int i;
	if(uscite.size() == 1)
		nome_funzione=uscite[0].NomeFunzione();
	
	if((i=Config::IstanzaConfig()->CercaTraduzione(this))!=-1)
		nome_funzione=Config::IstanzaConfig()->VediTraduzioneFunzione(i).NomeFunzione();
}

//funzioni esterne
vector<Timing> RicercaTrePiuVicini(const vector<Timing>& t, double tti, double c)
{
	vector<Timing> tm(3);
	vector<double> d(3);
	Timing t_temp;
	double d_temp;
	unsigned i;
	
	if(t.size() < 3)
		throw logic_error ("Il vettore di timing non ha 3 elementi");
	
	for(i=0; i<tm.size()-1; i++)
	{
		d[i] = t[i].Distanza(tti, c);
		tm[i] = t[i];
	}
	if(d[1]<d[0])
	{
		swap(d[1], d[0]);
		swap(tm[1], tm[0]);
	}
	
	do{
		if(i==t.size())
			throw logic_error ("Il vettore non ha 3 elementi non alineati nello spazio");
		d[2] = t[i].Distanza(tti, c);
		tm[2] = t[i];
		if(d[2]<d[1])
		{
			swap(d[2], d[1]);
			swap(tm[2], tm[1]);
			if(d[1]<d[0])
			{
				swap(d[1], d[0]);
				swap(tm[1], tm[0]);
			}
		}
		i++;
		//cerr << i << ": " << tm[0] << " | " << tm[1] << " | " << tm[2] << endl;
	}while(Allineati(tm)||PianoParalleloTerzoAsse(tm));
	
	
	for(; i<t.size(); i++)
	{
		d_temp=t[i].Distanza(tti, c);
		if(d_temp < d[2])
		{
			if(d_temp < d[1])
			{
				if(d_temp < d[0])
				{
					t_temp=tm[2];
					tm[2]=tm[1];
					tm[1]=tm[0];
					tm[0]=t[i];
					if(Allineati(tm)||PianoParalleloTerzoAsse(tm))
					{
						swap(tm[2], t_temp);
						if(Allineati(tm)||PianoParalleloTerzoAsse(tm))
						{
							swap(tm[1], t_temp);
							if(Allineati(tm)||PianoParalleloTerzoAsse(tm))
								swap(tm[0], t_temp);
							else
								d[0]=d_temp;
						}
						else
						{
							d[1]=d[0];
							d[0]=d_temp;
						}
					}
					else
					{
						d[2]=d[1];
						d[1]=d[0];
						d[0]=d_temp;
					}
				}
				else
				{
					t_temp=tm[2];
					tm[2]=tm[1];
					tm[1]=t[i];
					if(Allineati(tm)||PianoParalleloTerzoAsse(tm))
					{
						swap(tm[2], t_temp);
						if(Allineati(tm)||PianoParalleloTerzoAsse(tm))
						{
							swap(tm[1], t_temp);
						}
						else
							d[1]=d_temp;
					}
					else
					{
						d[2]=d[1];
						d[1]=d_temp;
					}
				}
			}
			else
			{
				t_temp=tm[2];
				tm[2]=t[i];
				if(Allineati(tm)||PianoParalleloTerzoAsse(tm))
				{
					swap(tm[2], t_temp);
				}
				else
					d[2]=d_temp;
			}
		}
		//cerr << i << ": " << tm[0] << " | " << tm[1] << " | " << tm[2] << endl;
	}
	
	return tm;
}

vector<double> CalcolaCoefficenti(const vector<Timing>& t)
{
	vector<double> v(3);
	vector<vector<double>> a(3, vector<double>(3, 1));
	vector<vector<double>> a0;
		
	for(unsigned i=0; i<a.size(); i++)
	{
		a[i][1] = t[i].TempoTransizioneIngresso();
		a[i][2] = t[i].CapacitaVista();
	}
	
	
	for(unsigned i=0; i<v.size(); i++)
	{
		a0=a;
		for(unsigned j=0; j<a0.size(); j++)
			a0[j][i] = t[j].Tempo();
		
		v[i]=DeterminanteTrePerTre(a0)/DeterminanteTrePerTre(a);
	}
	
	return v;
}

double DeterminanteTrePerTre(vector<vector<double>> m)
{
	if(m.size() != 3 || m[0].size() != 3 || m[1].size() != 3 || m[2].size() != 3)
		throw invalid_argument("La matrice non è 3x3");
	
	return m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1] -
			 m[0][2]*m[1][1]*m[2][0] - m[0][1]*m[1][0]*m[2][2] - m[0][0]*m[1][2]*m[2][1];
}

bool Allineati(const vector<Timing>& t)
{
	return (t[1].TempoTransizioneIngresso()-t[0].TempoTransizioneIngresso())*(t[2].CapacitaVista()-t[0].CapacitaVista())==
			 (t[2].TempoTransizioneIngresso()-t[0].TempoTransizioneIngresso())*(t[1].CapacitaVista()-t[0].CapacitaVista())&&
			 (t[1].TempoTransizioneIngresso()-t[0].TempoTransizioneIngresso())*(t[2].Tempo()-t[0].Tempo())==
			 (t[2].TempoTransizioneIngresso()-t[0].TempoTransizioneIngresso())*(t[1].Tempo()-t[0].Tempo());
}

bool PianoParalleloTerzoAsse(const vector<Timing>& t)
{
	return (t[1].TempoTransizioneIngresso()-t[0].TempoTransizioneIngresso())*(t[2].CapacitaVista()-t[0].CapacitaVista())-
			 (t[2].TempoTransizioneIngresso()-t[0].TempoTransizioneIngresso())*(t[1].CapacitaVista()-t[0].CapacitaVista()) == 0;
}

vector<Componente> CaricaLibreria(istream& is)
{
	string s, n;
	double d;
	char c;
	Timing ti;
	Componente comp;
	vector<Componente> componenti;
	bool primo = true;
	
	//cerr << "Inizio lettura libreria" << endl;
	
	while(!is.eof())
	{
		//cerr << "Lettura di 2 stringhe" << endl;
		is >> n >> s;
	
		if(s == "<-")
		{
			//cerr << "E' un pin di ingresso" << endl;
			PinIn pi;
			pi.nome = n;
			is >> c >> d >> c;
			pi.capacita = d;
			comp.ingressi.push_back(pi);
		}
		else if(s == "->")
		{
			//cerr << "E' un pin di uscita" << endl;
			PinOut po;
			po.nome = n;
			is >> c >> d >> c;
			PulisciSpazi(is);
			po.max_capacita_pilotabile = d;
			
			if(is.peek()=='(')
			{
				is.get();
				n.clear();
				while((c=is.get())!=')')
					n.push_back(c);
				PulisciSpazi(is);
				po.funzione = n;
			}
			
			if(is.peek()=='-')
			{
				//cerr << "Ha il nome della funzione" << endl;
				is >> s >> n;
				PulisciSpazi(is);
				po.nome_funzione = n;
			}
			
			while(is.peek()=='c' || is.peek()=='f' || is.peek()=='r')
			{
				is >> s;
				PulisciSpazi(is);
				if(is.peek()=='(')
					is >> n;
				if(s=="cell_fall")
				{
					is >> s;
					PulisciSpazi(is);
					if(is.peek()=='(')
						is >> n;
					if(s == "positive_unate")
					{
						is >> s >> s >> s;
						PulisciSpazi(is);
						
						//cerr << "Lettura timing cfp" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.cell_fall_positive.push_back(ti);
						}
					}
					else if(s == "negative_unate")
					{
						is >> s >> s >> s;
						PulisciSpazi(is);
						
						//cerr << "Lettura timing cfn" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.cell_fall_negative.push_back(ti);
						}
					}
					else
					{
						is >> s >> s; 
						PulisciSpazi(is);
					
						//cerr << "Lettura timing cf-" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti; 
							PulisciSpazi(is);
							po.cell_fall.push_back(ti);
						}
					}
				}
				if(s=="cell_rise")
				{
					is >> s;
					PulisciSpazi(is);
					if(is.peek()=='(')
						is >> n;
					if(s == "positive_unate")
					{
						is >> s >> s >> s; 
						PulisciSpazi(is); 

						//cerr << "Lettura timing crp" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti; 
							PulisciSpazi(is);
							po.cell_rise_positive.push_back(ti);
						}
					}
					else if(s == "negative_unate")
					{
						is >> s >> s >> s; 
						PulisciSpazi(is);
					
						//cerr << "Lettura timing crn" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti; 
							PulisciSpazi(is);
							po.cell_rise_negative.push_back(ti);
						}
					}
					else
					{
						is >> s >> s;
						PulisciSpazi(is);
					
						//cerr << "Lettura timing cr-" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.cell_rise.push_back(ti);
						}
					}
				}
				if(s=="fall_transition")
				{
					is >> s;
					PulisciSpazi(is);
					if(is.peek()=='(')
						is >> n;
					if(s == "positive_unate")
					{
						is >> s >> s >> s;
						PulisciSpazi(is); 
					
						//cerr << "Lettura timing ftp" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.fall_transition_positive.push_back(ti);
						}
					}
					else if(s == "negative_unate")
					{
						is >> s >> s >> s;
						PulisciSpazi(is);
						
						//cerr << "Lettura timing ftn" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.fall_transition_negative.push_back(ti);
						}
					}
					else
					{
						is >> s >> s;
						PulisciSpazi(is);
					
						//cerr << "Lettura timing ft-" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.fall_transition.push_back(ti);
						}
					}
				}
				if(s=="rise_transition")
				{
					is >> s;
					PulisciSpazi(is);
					if(is.peek()=='(')
						is >> n;
					if(s == "positive_unate")
					{
						is >> s >> s >> s;
						PulisciSpazi(is); 
						
						//cerr << "Lettura timing rtp" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.rise_transition_positive.push_back(ti);
						}
					}
					else if(s == "negative_unate")
					{
						is >> s >> s >> s;
						PulisciSpazi(is);
						
						//cerr << "Lettura timing rtn" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.rise_transition_negative.push_back(ti);
						}
					}
					else
					{
						is >> s >> s;
						PulisciSpazi(is);
					
						//cerr << "Lettura timing rt-" << endl;
						while(is.peek()>='0' && is.peek()<='9')
						{
							is >> ti;
							PulisciSpazi(is);
							po.rise_transition.push_back(ti);
						}
					}
				}
			}
			comp.uscite.push_back(po);
		}
		else //si tratta di un nuovo componente
		{
			if(primo)
				primo = !primo;
			else
			{
				comp.GeneraNomeFunzione();
				componenti.push_back(comp);
				comp.ingressi.clear();
				comp.uscite.clear();
			}
			//cin.ignore();
			//cerr << n << endl;
			comp.nome = n;
			is >> d;
			comp.area = d;
		}
	}
	comp.GeneraNomeFunzione();
	componenti.push_back(comp);
	return componenti;
}

void PulisciSpazi(istream& is)
{
	while(is.peek()<=32 && is.peek()!=EOF)
		is.get();
}