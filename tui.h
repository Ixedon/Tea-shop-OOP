
class Tui
{
public:
	void cd(string a) {current = mapa_nazw[a];};
	void dir();
	void mo();
	void dob();
	void mdo();
	void tree();

	void legenda()
	{
		for (int i = 0; i < wezel.size(); ++i)
		{
			cout <<wezel[i]->index<<" : "<<wezel[i]->getTyp()<<"     ";
			std::vector<Herbata*> v;
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
			//auto k=wezel[i];
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
	
};


void Tui::dir()
{
	cout << "dir: \n";
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
			cout <<k->index<<" "<<k->getTyp()<<" "<<k->czyLisc()<<"     ";
			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i]->index<<" ";
				if(!od[ v[i]->index ])
				{
					q.push(v[i]);
				}
			}

			od[k->index] = 1;
			if(k->czyLisc())szukane.push_back(k);
		}
		q.pop();
		cout << "\n";
	}

	for (int i = 0; i < szukane.size(); ++i)
	{
		cout << szukane[i]->getTyp()<< ": \n";
	}


}