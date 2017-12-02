#include <iostream>
#include <vector>

using namespace std;


class Herbata
{
public:
	Herbata();
	~Herbata();

	void dir()
	{

	}
	//virtual bool lisc () = 0;

private:
	int roczne_plony;
	static vector <Herbata*> obiekty;


protected:
	string typ_herbaty;
};


class Zielona : public Herbata 
{
public:
	Zielona();
	~Zielona();
	
};

class Biala : public Herbata
{
public:
	Biala();
	~Biala();
	
};

class Czarna : public Herbata
{
public:
	Czarna();
	~Czarna();
	
};


class Chinska : virtual public Zielona
{
public:
	Chinska();
	~Chinska();
	
};

class Japonska : virtual public Zielona
{
public:
	Japonska();
	~Japonska();
	
};

class Indyjska : public Czarna
{
public:
	Indyjska();
	~Indyjska();
	
};


class Ceylon : public Czarna
{
public:
	Ceylon();
	~Ceylon();
	
};

class Sencha : public Chinska
{
public:
	Sencha();
	~Sencha();
	
};


class Gunpowder : public Chinska, public Japonska
{
public:
	Gunpowder();
	~Gunpowder();
	
};


class Longjing : public Japonska
{
public:
	Longjing();
	~Longjing();
	
};

class Assam : public Indyjska
{
public:
	Assam();
	~Assam();
	
};


class Nilgiri : public Indyjska
{
public:
	Nilgiri();
	~Nilgiri();
	
};
int main(int argc, char const *argv[])
{
	
	return 0;
}
