#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
	
	std::string citta;
	double t0, t6, t12, t18;
	
	if (argc < 2) 
	{				//mi aspetto almeno 2 argomenti nella chiamata, se non accade errore
    std::cerr << "Errore: specificare il nome del file.\n";
    return 1;
	}
	
	std::ifstream fin(argv[1]);		//il secondo argomento sarà il file che passo in chiamata sulla bash
	
	if (!fin) {
    std::cerr << "Errore: impossibile aprire il file.\n";	//controllo che venga aperto, se non avviene esco
    return 1;
	}
	
	//da qua in poi posso eseguire la richiesta
	
	while (fin >> citta >> t0 >> t6 >> t12 >> t18) //finchè leggo dati che mi interessano della forma consona alla consegna
	{
		double media = 0;
        media = (t0 + t6 + t12 + t18) / 4.0;
        std::cout << citta << " " << media << "\n";
    }

    return 0;


}