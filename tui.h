
class Tui
{
public:
	void cd();	
	void mo();
	void dob();
	void mdo();
	void tree();

	void feedgalaz(Herbata& a)
	{
		galazie.push_back(&a);
		wezel.push_back(&a);
	}
	void feedlisc(Herbata& a)
	{
		liscie.push_back(&a);
		wezel.push_back(&a);
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
				temp[j]->addNext(wezel[i]);
			}

		}
	}

private:
	vector<Herbata*> galazie;
	vector<Herbata*> liscie;
	vector<Herbata*> wezel;
	Herbata* current;
	
};