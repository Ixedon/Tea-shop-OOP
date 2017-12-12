
class Tui
{
friend class Terminal;
public:
	void cd(string a) {current = mapa_nazw[a];};
	void dir();
	void tree();
	void mo(string);
	void dob(string);
	void mdo(string);
	void show(string,bool);
	void read(string);
	void save(string);

	void legenda()
	{
		for (int i = 0; i < wezel.size(); ++i)
		{
			cout <<wezel[i]->index<<" : "<<wezel[i]->getTyp()<<"     ";
			vector<Herbata*> v;
			v=wezel[i]->getNext();
			for (int i = 0; i < v.size(); ++i)
			{
				cout <<v[i]->index<<" ";
			}
			cout << "\n";
		}
	}

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

private:
	vector<Herbata*> galazie;
	vector<Herbata*> liscie;
	vector<Herbata*> wezel;
	Herbata* current;

	map<string,Herbata*>mapa_nazw;
	void dfs(Herbata*,int);
	bool istnieje(string);
};


void Tui::dir()
{
	//cout << "dir: \n";
	vector<Herbata*>szukane;  //szuakne wezly
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
			//cout <<k->index<<" "<<k->getTyp()<<" "<<k->czyLisc()<<"     ";
			for (int i = 0; i < v.size(); ++i)
			{
				//cout << v[i]->index<<" ";
				if(!od[ v[i]->index ])
				{
					q.push(v[i]);
				}
			}

			od[k->index] = 1;
			if(k->czyLisc())szukane.push_back(k);
		}
		q.pop();
		//cout << "\n";
	}

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
			v[i]->wartosc_s = s;
		}
		else 
		{
			cout << v[i]->nazwa <<" (w "<<v[i]->jednostka<<") : ";
			cin >> f;
			v[i]->wartosc_f = f;
		}
	}
	getline(cin,s);
	
	h->setElementy(v);	

	current->obiekty.push_back(h);
	current->mapa_obiektow[param]=current->obiekty.size() - 1;
}

void Tui::dob(string param)
{
	if(!istnieje(param)){cout << "No such object\n";return;}
	map<string,int>::iterator it;
	it = current->mapa_obiektow.find(param);
	current->obiekty.erase(current->obiekty.begin() + it->second);
	current->mapa_obiektow.erase (it);
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
		cin >> s;
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


// void Tui::write(string path)
// {
// 	ofstream o;
// 	o.open(path);
// }


// void Tui::read(string path)
// {

// }