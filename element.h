class Element
{
public:
	Element( string a1,  string a2) {nazwa=a1;jednostka=a2;typ = 0;} //konstruktor dla float
	Element( string a1) {nazwa=a1;typ = 1;} //konstruktor dla string
	string nazwa;
	string jednostka;
	bool typ;

	float wartosc_f;   //wartosc jesli float
	string wartosc_s;  //wartosc jesli string

};