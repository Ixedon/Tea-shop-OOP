class Element
{
public:
	Element( string a1,  string a2) {nazwa=a1;jednostka=a2;typ = 0;} //float
	Element( string a1) {nazwa=a1;typ = 1;} //string
	string nazwa;
	string jednostka;
	bool typ;

	float wartosc_f;
	string wartosc_s;

};