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

class Herbata;  //przednia definicja kass i funkcji
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
	execute();  //odpalenie programu
	return 0;
}



void execute()  //realizuje program
{
	Tui tui;

	Herbata herbata;    //tworzenie obiektow to ustanowienie struktury
	herbata.setprev(nullptr);   //ustawienie poprzednika
	tui.feed(herbata);  // dodanie do wektora w celu itercji

	Zielona zielona;
	zielona.setprev(herbata);
	tui.feed(zielona);

	Czarna czarna;
	czarna.setprev(herbata);
	tui.feed(czarna);

	Biala biala;
	biala.setprev(herbata);
	tui.feed(biala);


	Chinska chinska;
	chinska.setprev(zielona);
	tui.feed(chinska);

	Japonska japonska;
	japonska.setprev(zielona);
	tui.feed(japonska);

	Indyjska indyjska;
	indyjska.setprev(czarna);
	tui.feed(indyjska);

	Ceylon ceylon;
	ceylon.setprev(czarna);
	tui.feed(ceylon);

	Sencha sencha;
	sencha.setprev(japonska);
	tui.feed(sencha);

	Gunpowder gunpowder;
	gunpowder.setprev(japonska,chinska);
	tui.feed(gunpowder);

	Longjing longjing;
	longjing.setprev(chinska);
	tui.feed(longjing);

	Assam assam;
	assam.setprev(indyjska);
	tui.feed(assam);

	Nilgiri nilgiri;
	nilgiri.setprev(indyjska);
	tui.feed(nilgiri);


	tui.init(herbata);   //inicjalizacja
	Terminal terminal(tui);   //stworzenei terminala do tekstowego ui
	terminal.run();  //odpalenie terminala
}