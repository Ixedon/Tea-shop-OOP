class Herbata : public Wezel
{
public:
	string getTyp() {string s= string(typeid(*this).name()); return s.substr(1,s.size()-1);}
	
	
	virtual bool czyLisc(){return 0;}
	
	vector<Herbata*> obiekty;
private:
	int roczne_plony;


protected:
	string name;

};


class Zielona : public Herbata 
{
public:
protected:
	
};

class Biala : public Herbata, public Lisc
{
public:
	bool czyLisc() {return 1;}
	
protected:	
private:
	
};

class Czarna : public Herbata
{
public:
protected:
};


class Chinska : virtual public Zielona
{
public:
protected:
};

class Japonska : virtual public Zielona
{
public:
protected:
};

class Indyjska : public Czarna
{
public:
protected:
};


class Ceylon : public Czarna, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
private:
	
};

class Sencha : public Japonska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:	
private:
};


class Gunpowder : public Chinska, public Japonska, public Lisc
{
public:
	bool czyLisc(){return 1;}
protected:
private:
};


class Longjing : public Chinska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
private:
};

class Assam : public Indyjska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
private:
};


class Nilgiri : public Indyjska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
private:
};

Herbata* create_object(string a)
{
	Herbata* h;
	if(a=="Herbata")h=new Herbata;
	if(a=="Zielona")h=new Zielona;
	if(a=="Czarna")h=new Czarna;
	if(a=="Biala")h=new Biala;
	if(a=="Chinska")h=new Chinska;
	if(a=="Japonska")h=new Japonska;
	if(a=="Indyjska")h=new Indyjska;
	if(a=="Ceylon")h=new Ceylon;
	if(a=="Sencha")h=new Sencha;
	if(a=="Gunpowder")h=new Gunpowder;
	if(a=="Assam")h=new Assam;
	if(a=="Nilgiri")h=new Nilgiri;

	return h;
}