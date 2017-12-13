class Wezel
{
friend class Tui;
friend void execute();
protected:
	void setprev(nullptr_t nullp){}     //konstruktor dla korzenia
	void setprev(Herbata& a){prev.push_back(&a);}   //konstruktor dla pojedynczego przodka
	void setprev(Herbata& a,Herbata& b){prev.push_back(&a);prev.push_back(&b);} //konstruktor dla podwojnego przodka

	vector<Herbata*> getNext(){return  next;}
	vector<Herbata*> getPrev(){return  prev;}
	void addNext(Herbata* a) {next.push_back(a);}
	void addPrev(Herbata* a) {prev.push_back(a);}

	int index;  //index obiektu
private:
	vector<Herbata*> prev;  //tablica prodkow
	vector<Herbata*> next; //tablica potomkow

};