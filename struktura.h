class Herbata : public Wezel
{
public:
	string getTyp() {string s= string(typeid(*this).name()); return s.substr(1,s.size()-1);}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	virtual bool czyLisc(){return 0;}
	
	vector<Herbata*> obiekty;
	Herbata(){roczne_plony= new Element("Roczne plony","kg");elementy.push_back(roczne_plony);}
	string name;

protected:
	Element *roczne_plony;
private:
	//Element* waga("Waga porcji","g");
	vector<Element*>elementy;

};


class Zielona : public Herbata 
{
public:
	Zielona(){czas_parzenia = new Element("Czas parzenia","min");
elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);}
protected:
	Element *czas_parzenia;
private:
	vector<Element*>elementy;

	
};

class Biala : public Herbata, public Lisc
{
public:
	bool czyLisc() {return 1;}
	Biala(){smak = new Element( "Smak (jaki owoc)" );
	elementy.push_back(roczne_plony);elementy.push_back(smak);}
protected:
	Element *smak;
private:
	vector<Element*>elementy;
};

class Czarna : public Herbata
{
public:
	Czarna(){moc_parzenia = new Element("Moc zaparzonej herbaty","0-10");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);}
protected:
	Element *moc_parzenia ;
private:
	vector<Element*>elementy;
};


class Chinska : virtual public Zielona
{
public:
	Chinska(){region = new Element("Region pochodzenia");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(region);}
protected:
	Element *region;
private:
	vector<Element*>elementy;
};

class Japonska : virtual public Zielona
{
public:
	Japonska(){czas_dojrzewania = new Element("Czas dojrzewania","mce");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(czas_dojrzewania);}
protected:
	Element *czas_dojrzewania;
private:
	vector<Element*>elementy;
};

class Indyjska : public Czarna
{
public:
	Indyjska(){miesiac = new Element("Miesiac zbiorow");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(miesiac);}
protected:
	Element *miesiac;
private:
	vector<Element*>elementy;
};


class Ceylon : public Czarna, public Lisc
{

public:
	bool czyLisc() {return 1;}
	Ceylon(){data_zerwania = new Element("Data zerwania");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(data_zerwania);}
protected:
	Element *data_zerwania;
private:
	
	vector<Element*>elementy;
};

class Sencha : public Japonska, public Lisc
{

public:
	bool czyLisc() {return 1;}
	Sencha(){opiekun = new Element("Opiekun plantacji");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(czas_dojrzewania);elementy.push_back(opiekun);}
protected:
	Element *opiekun;
private:
	vector<Element*>elementy;
};


class Gunpowder : public Chinska, public Japonska, public Lisc
{

public:
	bool czyLisc(){return 1;}
	Gunpowder(){moc_wybuchu = new Element("Moc wybuchu","Mt");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);
	elementy.push_back(czas_dojrzewania);elementy.push_back(region);elementy.push_back(moc_wybuchu);}
protected:
	Element *moc_wybuchu ;
private:
	vector<Element*>elementy;
};


class Longjing : public Chinska, public Lisc
{

public:
	bool czyLisc() {return 1;}
	Longjing(){ksztalt = new Element("Ksztalt lisci");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(region);elementy.push_back(ksztalt);}
protected:
	Element *ksztalt;
private:
	vector<Element*>elementy;
};

class Assam : public Indyjska, public Lisc
{

public:
	bool czyLisc() {return 1;}
	Assam(){godzina_zerwania = new Element("Godzina zerwania");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(miesiac);elementy.push_back(godzina_zerwania);}
protected:
	Element *godzina_zerwania;
private:
	vector<Element*>elementy;
};


class Nilgiri : public Indyjska, public Lisc
{

public:
	bool czyLisc() {return 1;}
	Nilgiri(){dlugosc_lisci = new Element("Dlugosc lisci", "cm");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(miesiac);elementy.push_back(dlugosc_lisci);}
protected:
	Element *dlugosc_lisci;
private:
	vector<Element*>elementy;
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