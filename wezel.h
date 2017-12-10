class Wezel
{
public:
	void setprev(nullptr_t nullp){/*prev.push_back(nullp);*/}
	void setprev(Herbata& a){prev.push_back(&a);}
	void setprev(Herbata& a,Herbata& b){prev.push_back(&a);prev.push_back(&b);}

	vector<Herbata*> getNext(){return  next;}
	vector<Herbata*> getPrev(){return  prev;}
	void addNext(Herbata* a) {next.push_back(a);}
	void addPrev(Herbata* a) {prev.push_back(a);}

	int index;
private:
	vector<Herbata*> prev;
	vector<Herbata*> next;

};