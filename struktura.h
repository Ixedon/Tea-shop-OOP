class Herbata : public Wezel  //dziedziczenie ogolnej klasy
{
friend void execute(); //zapewnienie dostepu wybranym funkcjom i klasom
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Herbata(){roczne_plony= new Element("Roczne plony","kg");elementy.push_back(roczne_plony);}  //dodanie atrybutow do vectora wraz z human friendly nazwa
	virtual ~Herbata(){for (int i = 0; i < obiekty.size(); ++i)delete obiekty[i];
					   for (int i = 0; i < elementy.size(); ++i)delete elementy[i];}  //usuwanie atrubutow przy usuwaniu obiektu
protected:
	string getTyp() {string s= string(typeid(*this).name()); return s.substr(1,s.size()-1);}  //zwraca nazwe klasy
	virtual void setElementy(vector<Element*> a){elementy=a;} 
	virtual vector<Element*> getElementy(){return elementy;}
	virtual bool czyLisc(){return 0;}   //sprawdza czy jest lisciem
	
	vector<Herbata*> obiekty;   //vector elementow (przechowuje elementy tylko dla reprezentanat lisci)
	map<string,int> mapa_obiektow;  //mapa dla szybszego odwolywania

	Element *roczne_plony;  //element wlasny klasy
private:
	vector<Element*>elementy;  //vector atrybutow w celu iteracji po atrybutach
	string name;   //nazwa obiektu

};


class Zielona : protected Herbata 
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	Zielona(){czas_parzenia = new Element("Czas parzenia","min");   //okreslenie przedrostka i jednostki
elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);}
protected:
	Element *czas_parzenia;
private:
	vector<Element*>elementy;

	
};

class Biala : protected Herbata
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Biala(){smak = new Element( "Smak (jaki owoc)" );  //bez jednostki
	elementy.push_back(roczne_plony);elementy.push_back(smak);}
protected:
	bool czyLisc() {return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *smak;
private:
	vector<Element*>elementy;
};

class Czarna : protected Herbata
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	Czarna(){moc_parzenia = new Element("Moc zaparzonej herbaty","0-10");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);}
protected:
	Element *moc_parzenia ;
private:
	vector<Element*>elementy;
};


class Chinska : virtual protected Zielona  //wirtualne dziedziczenie zeby nie bylo duplikatow pol
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	Chinska(){region = new Element("Region pochodzenia");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(region);}
protected:
	Element *region;
private:
	vector<Element*>elementy;
};

class Japonska : virtual protected Zielona  //wirtualne dziedziczenie zeby nie bylo duplikatow pol
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	Japonska(){czas_dojrzewania = new Element("Czas dojrzewania","mce");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(czas_dojrzewania);}
protected:
	Element *czas_dojrzewania;
private:
	vector<Element*>elementy;
};

class Indyjska : protected Czarna
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	Indyjska(){miesiac = new Element("Miesiac zbiorow");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(miesiac);}
protected:
	Element *miesiac;
private:
	vector<Element*>elementy;
};


class Ceylon : protected Czarna
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Ceylon(){data_zerwania = new Element("Data zerwania");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(data_zerwania);}
protected:
	bool czyLisc() {return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *data_zerwania;
private:
	
	vector<Element*>elementy;
};

class Sencha : protected Japonska
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Sencha(){opiekun = new Element("Opiekun plantacji");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(czas_dojrzewania);elementy.push_back(opiekun);}
protected:
	bool czyLisc() {return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *opiekun;
private:
	vector<Element*>elementy;
};


class Gunpowder : protected Chinska, protected Japonska
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Gunpowder(){moc_wybuchu = new Element("Moc wybuchu","Mt");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);
	elementy.push_back(czas_dojrzewania);elementy.push_back(region);elementy.push_back(moc_wybuchu);}
protected:
	bool czyLisc(){return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *moc_wybuchu ;
private:
	vector<Element*>elementy;
};


class Longjing : protected Chinska
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Longjing(){ksztalt = new Element("Ksztalt lisci");
	elementy.push_back(roczne_plony);elementy.push_back(czas_parzenia);elementy.push_back(region);elementy.push_back(ksztalt);}
protected:
	bool czyLisc() {return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *ksztalt;
private:
	vector<Element*>elementy;
};

class Assam : protected Indyjska
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Assam(){godzina_zerwania = new Element("Godzina zerwania");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(miesiac);elementy.push_back(godzina_zerwania);}
protected:
	bool czyLisc() {return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *godzina_zerwania;
private:
	vector<Element*>elementy;
};


class Nilgiri : protected Indyjska
{
friend void execute();
friend Herbata* create_object(string);
friend class Tui;
public:
	
	Nilgiri(){dlugosc_lisci = new Element("Dlugosc lisci", "cm");
	elementy.push_back(roczne_plony);elementy.push_back(moc_parzenia);elementy.push_back(miesiac);elementy.push_back(dlugosc_lisci);}
protected:
	bool czyLisc() {return 1;}
	vector<Element*> getElementy(){return elementy;}
	void setElementy(vector<Element*> a){elementy=a;}
	Element *dlugosc_lisci;
private:
	vector<Element*>elementy;
};

Herbata* create_object(string a)  //tworzenie obiektu na podstawie stringa
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