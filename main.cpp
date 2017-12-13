#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <typeinfo>
#include <string>
#include <fstream>
#include <stdlib.h> 

using namespace std;

class Herbata;
class Tui;
void execute();
#include "lisc.h"
#include "wezel.h"
#include "element.h"
#include "struktura.h"
#include "tui.h"
#include "terminal.h"

int main(int argc, char const *argv[])
{
	execute();
	return 0;
}



void execute()  //realizuje program
{
	Tui tui;

	Herbata herbata;    //tworzenie obiektow to ustanowienie struktury
	herbata.setprev(nullptr);   //ustawienie poprzednika
	tui.feedgalaz(herbata);  // dodanie do wektora w celu itercji

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


	tui.init(herbata);   //inicjalizacja
	Terminal terminal(tui);   //stworzenei terminala do tekstowego ui
	terminal.run();
}