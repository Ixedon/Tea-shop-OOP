
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
				cout << szukane[i]->obiekty[j]<<" ";
			}
			cout << "\n";
		}
	}


}

void Tui::mo(string param)
{
	Herbata* h = create_object(current->getTyp());

	current->obiekty.push_back(h);
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
			cout << a->obiekty[i]<<" ";
		}
	}
	cout << "\n";
	for (int i = 0; i <v.size() ; ++i)
	{
		dfs(v[i],k+1);
	}
}