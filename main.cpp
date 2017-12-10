#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <typeinfo>
#include <string>
using namespace std;

class Herbata;

#include "lisc.h"
#include "wezel.h"
#include "struktura.h"
#include "tui.h"

int main(int argc, char const *argv[])
{

	// virtual vector<Herbata*> Obiekt::prev;
	// virtual vector<Herbata*> Obiekt::next;

	Tui tui;

	Herbata herbata;
	herbata.setprev(nullptr);
	tui.feedgalaz(herbata);

	Zielona zielona;
	zielona.setprev(herbata);
	tui.feedgalaz(zielona);

	Czarna czarna;
	czarna.setprev(herbata);
	tui.feedgalaz(czarna);

	Biala biala;
	biala.setprev(herbata);
	tui.feedgalaz(biala);


	Chinska chinska;
	chinska.setprev(zielona);
	tui.feedgalaz(chinska);

	Japonska japonska;
	japonska.setprev(zielona);
	tui.feedgalaz(japonska);

	Indyjska indyjska;
	indyjska.setprev(czarna);
	tui.feedgalaz(indyjska);

	Ceylon ceylon;
	ceylon.setprev(czarna);
	tui.feedlisc(ceylon);

	Sencha sencha;
	sencha.setprev(japonska);
	tui.feedlisc(sencha);

	Gunpowder gunpowder;
	gunpowder.setprev(japonska,chinska);
	tui.feedlisc(gunpowder);

	Longjing longjing;
	longjing.setprev(chinska);
	tui.feedlisc(longjing);

	Assam assam;
	assam.setprev(indyjska);
	tui.feedlisc(assam);

	Nilgiri nilgiri;
	nilgiri.setprev(indyjska);
	tui.feedlisc(nilgiri);


	tui.init(herbata);
	tui.legenda();
	tui.dir();
	


	string s;
	cin >> s;

	return 0;
}