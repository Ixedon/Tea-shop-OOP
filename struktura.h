class Herbata : public Wezel
{
public:
	//virtual bool lisc () = 0;
	//string getTyp() {return typ_herbaty;}
	string getTyp() {string s= string(typeid(*this).name()); return s.substr(1,s.size()-1);}
	
	virtual bool czyLisc(){return 0;}

private:
	int roczne_plony;


protected:
	 string typ_herbaty = "Herbata"; 
};


class Zielona : public Herbata 
{
public:
protected:
	 string typ_herbaty = "Zielona"; 	
	
};

class Biala : public Herbata, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
	 string typ_herbaty = "Biala"; 	
};

class Czarna : public Herbata
{
public:
protected:
	 string typ_herbaty = "Czarna"; 	
};


class Chinska : virtual public Zielona
{
public:
protected:
	 string typ_herbaty = "Chinska"; 
};

class Japonska : virtual public Zielona
{
public:
protected:
	 string typ_herbaty = "Japonska"; 	
};

class Indyjska : public Czarna
{
public:
protected:
	 string typ_herbaty = "Indyjska"; 	
};


class Ceylon : public Czarna, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
	string typ_herbaty = "Ceylon"; 
};

class Sencha : public Japonska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
	string typ_herbaty = "Sencha"; 	
};


class Gunpowder : public Chinska, public Japonska,  public Lisc
{
public:
	bool czyLisc(){return 1;}
protected:
	string typ_herbaty = "Gunpowder"; 	
};


class Longjing : public Chinska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
	string typ_herbaty = "Longjing"; 	
};

class Assam : public Indyjska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
	string typ_herbaty = "Assam"; 	
};


class Nilgiri : public Indyjska, public Lisc
{
public:
	bool czyLisc() {return 1;}
protected:
	string typ_herbaty = "Nilgiri"; 	
};