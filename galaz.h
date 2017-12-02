class Galaz
{
public:
	std::vector<Herbata*> prev;
	std::vector<Herbata*> next;
	void setprev(vector<Herbata*> arg1)
	{
		prev = arg1;
	}
	Galaz();
	~Galaz();

};