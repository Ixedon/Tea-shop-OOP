class Terminal
{
friend void execute();
public:
	Terminal(Tui &a){tui=&a;};  //pobranie interfejsu
protected:
	void run()
	{
		string command,parameter,base;
		bool exit =0;
		while(!exit)  //petla glowna
		{
			cout << tui->getTyp()<<"> ";  //promt
			getline(cin, command);
			int k=-1;
			base = parameter = "";
			for (int i = 0; i < command.size(); ++i)
			{
				if(command[i]==' ') { k=i; continue;}  //szukanie spacji miedzy komenda a parametrem
				if(k<0)
				{
					base+=command[i];
				}
				else
				{
					parameter+=command[i];
				}
			}
			if(base == "dir" && parameter == "")tui->dir(0);   //odpalenie komend
			else if(base == "exit" && parameter == "")exit=1;
			else if(base == "cd" && tui->mapa_nazw.find(parameter) != tui->mapa_nazw.end() ) 
				tui->current = tui->mapa_nazw[parameter];
			else if(base == "mo" && parameter!=""&& tui->czyLisc())tui->mo(parameter);
			else if(base == "tree" && parameter=="")tui->tree();
			else if(base == "do" && parameter!="")tui->dob(parameter,1);
			else if(base == "show" && parameter!="")tui->show(parameter,0);
			else if(base == "mdo" && parameter!="")tui->mdo(parameter);
			else if(base == "save" && parameter=="")tui->save();
			else if(base == "read" && parameter=="")tui->read();
			else cout << "Invalid command or parameter\n";
		}
	}
private:
	Tui* tui;  //wskazni na tekstowy ui
};