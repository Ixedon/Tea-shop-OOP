class Terminal
{
public:
	Terminal(Tui &a){tui=&a;};
	void run()
	{
		string command,parameter,base;
		bool exit =0;
		while(!exit)
		{
			cout << tui->current->getTyp()<<"> ";
			getline(cin, command);
			int k=-1;
			base = parameter = "";
			for (int i = 0; i < command.size(); ++i)
			{
				if(command[i]==' ') { k=i; continue;}
				if(k<0)
				{
					base+=command[i];
				}
				else
				{
					parameter+=command[i];
				}
			}
			//cout << command <<" : "<<base<<" : "<<parameter<<"\n";
			if(base == "dir" && parameter == "")tui->dir();
			else if(base == "exit" && parameter == "")exit=1;
			else if(base == "cd" && tui->mapa_nazw.find(parameter) != tui->mapa_nazw.end() ) 
				tui->current = tui->mapa_nazw[parameter];
			else if(base == "mo" && parameter!=""&& tui->current->czyLisc())tui->mo(parameter);
			else if(base == "tree" && parameter=="")tui->tree();
			else cout << "Invalid command or parameter\n";
		}
	}
private:
	Tui* tui;
};