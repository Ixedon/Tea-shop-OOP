
class Tui
{
friend class Terminal;
friend void execute();
protected:
	void cd(string a) {current = mapa_nazw[a];};
	void dir(bool);
	void tree();
	void mo(string);
	void dob(string,bool);
	void mdo(string);
	void show(string,bool);
	void read();
	void save();

	void feedgalaz(Herbata& a)
	{
		galazie.push_back(&a);
		wezel.push_back(&a);
		a.index = wezel.size() - 1;
	}
	void feedlisc(Herbata& a)
	{
		liscie.push_back(&a);
		wezel.push_back(&a);
		a.index = wezel.size() - 1;
	}
	void init(Herbata& start)
	{

		current = &start;

		for (int i = 0; i < wezel.size(); ++i)
		{
			vector<Herbata*> temp;
			temp = wezel[i]->getPrev();
			for (int j = 0; j < temp.size(); ++j)
			{
				if(temp[j]!=nullptr)
					temp[j]->addNext(wezel[i]);
			}

			//if(wezel[i]->czyLisc()) wezel[i]->addNext(nullptr);

			mapa_nazw[ wezel[i]->getTyp() ] = wezel[i];
		}

	}
	bool czyLisc(){return current->czyLisc();}
	string getTyp(){return current->getTyp();}

private:
	vector<Herbata*> galazie;
	vector<Herbata*> liscie;
	vector<Herbata*> wezel;
	vector<Herbata*> znalezione;
	Herbata* current;

	map<string,Herbata*>mapa_nazw;
	void dfs(Herbata*,int);
	bool istnieje(string);
};


void Tui::dir(bool b)
{
	//cout << "dir: \n";
	vector<Herbata*>szukane;  //szuakne wezly
	znalezione.clear();
	vector<bool> od;

	for (int i = 0; i < wezel.size(); ++i)
	{
		od.push_back(0);
	}
	queue<Herbata*> q;
	q.push(current);
	Herbata* k;
	vector<Herbata*>v;
	while(!q.empty())
	{
		
		k=q.front();
		v=k->getNext();
		if(!od[k->index])
		{
			for (int i = 0; i < v.size(); ++i)
			{
				if(!od[ v[i]->index ])
				{
					q.push(v[i]);
				}
			}

			od[k->index] = 1;
			if(k->czyLisc())szukane.push_back(k);
			if(b && k->czyLisc())znalezione.push_back(k);
		}
		q.pop();
	}
	if(b)return;

	for (int i = 0; i < szukane.size(); ++i)
	{
		cout << szukane[i]->getTyp()<< ": ";
		vector<Herbata*> a = szukane[i]->obiekty;
		if(a.size() == 0) cout << "Brak obiektow\n";
		else
		{
			for (int j = 0; j < szukane[i]->obiekty.size(); ++j)
			{
				cout << szukane[i]->obiekty[j]->name<<" ";
			}
			cout << "\n";
		}
	}
}

bool Tui::istnieje(string param)
{
	map<string,int>::iterator it;
	it = current->mapa_obiektow.find(param);
  	return (it != current->mapa_obiektow.end());
}

void Tui::mo(string param)
{
	if(istnieje(param)){cout << "Object already exists\n";return;}

	Herbata* h = create_object(current->getTyp());
	h->name=param;
	string s;
	float f;
	vector<Element*> v = h->getElementy();
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i]->typ)
		{
			cout << v[i]->nazwa<<" : ";
			cin >> s;
			//getline(cin,s);
			v[i]->wartosc_s = s;
		}
		else 
		{
			cout << v[i]->nazwa <<" (w "<<v[i]->jednostka<<") : ";
			cin >> s;
			f = atof(s.c_str());
			v[i]->wartosc_f = f;
		}
	}
	getline(cin,s);
	h->setElementy(v);	

	current->obiekty.push_back(h);
	current->mapa_obiektow[param]=current->obiekty.size() - 1;
}

void Tui::dob(string param, bool b)
{
	if(!istnieje(param)){if(b)cout << "No such object\n";return;}
	map<string,int>::iterator it;
	it = current->mapa_obiektow.find(param);
	current->obiekty.erase(current->obiekty.begin() + it->second);
	current->mapa_obiektow.erase (it);

	vector<Herbata*>v=current->obiekty;

	for (int i = 0; i < v.size(); ++i)
	{
		current->mapa_obiektow[v[i]->name]=i;
	}
}


void Tui::show(string param,bool b)
{
	if(!istnieje(param)){cout << "No such object\n";return;}
	vector<Element*>v = current->obiekty[ current->mapa_obiektow [param] ]->getElementy();
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i]->typ)
		{
			if(b)cout << i<<" : ";
			cout << v[i]->nazwa<<" : "<< v[i]->wartosc_s<<"\n";
		}
		else 
		{
			if(b)cout << i<<" : ";
			cout << v[i]->nazwa << " : "<< v[i]->wartosc_f<<" [ "<<v[i]->jednostka<<" ]\n";
		}
	}
}

void Tui::tree()
{
	Herbata *tmp=current;
	dfs(current,0);
	
}

void Tui::dfs(Herbata* a, int k)
{
	vector<Herbata*> v=a->getNext();
	for (int i = 0; i <k ; ++i)cout << "   ";
	cout << a->getTyp()<<": ";
	if(a->czyLisc())
	{
		for (int i = 0; i < a->obiekty.size(); ++i)
		{
			cout << a->obiekty[i]->name<<" ";
		}
	}
	cout << "\n";
	for (int i = 0; i <v.size() ; ++i)
	{
		dfs(v[i],k+1);
	}
}

void Tui::mdo(string param)
{
	string s;
	int k;
	show(param,1);
	if(!istnieje(param))return;

	float f;
	vector<Element*>v = current->obiekty[ current->mapa_obiektow [param] ]->getElementy();

	cout << "Modify which attribute? (Select index) >> ";
	cin >> k;
	if(k<0 || k>v.size()-1){cout << "No such attribute\n";getline(cin,s);return;}
	cout << "Enter new value : ";

	
	if(v[k]->typ)
	{
		cout << v[k]->nazwa<<" : ";
		getline(cin,s);
		//cin >> s;
		v[k]->wartosc_s = s;
	}
	else 
	{
		cout << v[k]->nazwa <<" (w "<<v[k]->jednostka<<") : ";
		cin >> f;
		v[k]->wartosc_f = f;

	}
	getline(cin,s);
	current->obiekty[ current->mapa_obiektow [param] ]->setElementy(v);	
}


void Tui::save()
{
	ofstream o;
	o.open(current->getTyp()+".txt");
	o<<current->getTyp()<<"\n";   //dodanie identyfiaktora wezla dla pliku
	string s;
	dir(1); //zapisanie wszystkich podwierzcholkow do vektora znalezione

	for (int k = 0; k < znalezione.size(); ++k)
	{
		o<<znalezione[k]->getTyp()<<" "<<znalezione[k]->obiekty.size()<<"     "; 
		for (int j = 0; j < znalezione[k]->obiekty.size(); ++j)
		{
			o <<"\n"<<znalezione[k]->obiekty[j]->name<<"   ";
			vector<Element*>v = znalezione[k]->obiekty[j]->getElementy();
			for (int i = 0; i < v.size(); ++i)
			{
				if(v[i]->typ)
				{
					s=v[i]->wartosc_s;
					for(int q=0;q<s.size();q++){if(s[i]==' ')s[i]='@';}
					o  <<"string "<<s<<"  ";
				}
				else 
				{
					o  <<"float "<<v[i]->wartosc_f <<" "<<v[i]->jednostka<<"  ";
				}
			}	
		}
		o << "\n";
	}
	o.close();
}


void Tui::read()
{
	ifstream ifs;
	ifs.open(current->getTyp()+".txt");

	string nazwa_klasy,nazwa_obiektu,typ_elementu,korzen;
	//vector<Herbata*>o;
	vector<Element*>v;
	Element *ele;
	Herbata *h,*klasa;
	int il_obiektow;
	dir(1); //zapisanie wszystkich podwierzcholkow do vektora znalezione

	ifs >> korzen;
	for(int q = 0; q<znalezione.size();q++)
	{
		ifs >> nazwa_klasy >> il_obiektow;  //wczytanie ilosci obiektow sanej klasy
		klasa = mapa_nazw[nazwa_klasy];
		for (int i = 0; i < il_obiektow; ++i)
		{
			ifs >> nazwa_obiektu;      //wczytanie nazwy obiektu
			h = create_object(nazwa_klasy);
			h->name = nazwa_obiektu;
			v = h->getElementy();
			for (int j = 0; j < v.size(); ++j)
			{
				ifs >> typ_elementu;
				if(typ_elementu == "float") {ifs >> v[j]->wartosc_f >> v[j]->jednostka; v[j]->typ = 0; }
				else {ifs >> v[j]->wartosc_s; v[j]->typ=1;}
			}
			h->setElementy(v);
			current = mapa_nazw[h->getTyp()];
			dob(h->name,0);
			klasa->obiekty.push_back(h);
			klasa->mapa_obiektow[h->name]=klasa->obiekty.size() - 1;
			
		}



	}
	current = mapa_nazw[korzen];


}