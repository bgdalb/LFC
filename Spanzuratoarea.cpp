#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>

class Color {
public:
	Color(int desiredColor) {
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		color = desiredColor;
	}

	friend std::ostream& operator<<(std::ostream& ss, Color obj) {
		SetConsoleTextAttribute(obj.consoleHandle, obj.color);
		return ss;
	}
private:
	int color;
	HANDLE consoleHandle;
};

class Spanzuratoare {
	std::vector<std::string> cuvinte = {"contratenor","transplant","bibliografie","stigmatism","recreere","ciclism"};


public:

	void intrebare() {
		
		std::cout << Color(3);

		
		std::cout << "  ____  ____   _    _   _ ______   _ ____      _  _____ ___    _    ____  _____    _    " << std::endl;
		std::cout << " / ___||  _ \\ / \\  | \\ | |__  / | | |  _ \\    / \\|_   _/ _ \\  / \\  |  _ \\| ____|  / \\   " << std::endl;
		std::cout << " \\___ \\| |_) / _ \\ |  \\| | / /| | | | |_) |  / _ \\ | || | | |/ _ \\ | |_) |  _|   / _ \\  " << std::endl;
		std::cout << "  ___) |  __/ ___ \\| |\\  |/ /_| |_| |  _ <  / ___ \\| || |_| / ___ \\|  _ <| |___ / ___ \\ " << std::endl;
		std::cout << " |____/|_| /_/   \\_\\_| \\_/____|\\___/|_| \\_\\/_/   \\_\\_| \\___/_/   \\_\\_| \\_\\_____/_/   \\_\\" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Vrei sa ne jucam un joc?" << std::endl<<Color(7);
		
		std::cout << std::endl;
		std::string optiune;
		std::cin >> optiune;
		std::cout << std::endl;
		for (auto& c : optiune) 
			c = toupper(c);

		if (optiune.compare("DA") == 0)
			Spanzuratoare::incepeJoc();
		else
			std::exit;

	
	}

	void incepeJoc() {

		std::string cuvantDeGasit,cuvantSpanzuratoare;
		srand(time(NULL));
		int numarAleator=rand() % cuvinte.size();
		cuvantDeGasit = cuvinte[numarAleator];
		char litera;
		for (auto& c : cuvantDeGasit) {
			c = toupper(c);
			cuvantSpanzuratoare = cuvantSpanzuratoare + "_";
		}
		int numarGreseliAdmise = 6, numarGreseli=0,iterator;

	
	

		while (numarGreseli < numarGreseliAdmise) {
			iterator = -1;
			Spanzuratoare::desenInFunctieDeGreseli(numarGreseli);
			Spanzuratoare::afisareCuvantSpanzuratoare(cuvantSpanzuratoare);
			std::cout << std::endl;
			std::cout <<Color(3) <<"Introduceti o litera: "<<std::endl<<Color(7);
			std::cin >> litera;
			litera = toupper(litera);
			std::cout << std::endl;

			if (literaSeAflaInCuvant(cuvantDeGasit, litera)) {
				std::cout << "Litera " << litera << " apartine cuvantului." << std::endl;
				for (auto c: cuvantDeGasit) {
					iterator++;
					if (litera == c) {
						cuvantSpanzuratoare[iterator] = litera;
					}
				}
					
			}
			else
			{
				std::cout << "Litera " << litera << " nu apartine cuvantului." << std::endl;
				numarGreseli++;
				if (numarGreseli != 6)
					if(numarGreseli !=5)
						std::cout << "Mai aveti " << numarGreseliAdmise - numarGreseli << " incercari." << std::endl;
					else {
						std::cout << "Ultima incercare." << std::endl;
					}
				else {
					desenInFunctieDeGreseli(6);
					std::cout << "Jocul s-a terminat! Nu mai aveti incercari, mult noroc alta data! " << std::endl;
					std::cout << "Cuvantul era: " << Color(4) << cuvantDeGasit << Color(7) << std::endl;
					break;
				}
			}

			/*for (int i = 0; cuvantDeGasit.length(); i++) {
				if (litera == cuvantDeGasit[i]) {
					cuvantSpanzuratoare[i] = litera;
					std::cout << "Litera "<<litera<<" apartine cuvantului." << std::endl;
				}
				else
				{
					std::cout << "Litera " << litera << " nu apartine cuvantului." << std::endl;
					numarGreseli++;
					std::cout << "Mai aveti "<<numarGreseliAdmise-numarGreseli<<" incercari." << std::endl;
				}
			}*/


			
			
			if (Spanzuratoare::verificareCuvantGasitInTotalitate(cuvantSpanzuratoare, cuvantDeGasit)) {
				std::cout << Color(2);
				Spanzuratoare::desenInFunctieDeGreseli(numarGreseli);
				Spanzuratoare::afisareCuvantSpanzuratoare(cuvantSpanzuratoare);
				std::cout << Color(7) << std::endl;
				std::cout << "BRAVO, AI CASTIGAT!" << std::endl;
				std::cout << "Cuvantul era: " <<Color(2)<< cuvantDeGasit<<Color(7)<<std::endl;
				std::cout << "Ai gasit cuvantul avand " << numarGreseliAdmise - numarGreseli << " incercari ramase."<<std::endl;
				break;	
			}
		}
	
	}

	void afisareCuvantSpanzuratoare(std::string cuvantSpanzuratoare) {
		for (auto c : cuvantSpanzuratoare) {
			std::cout << " " << c;
		}
		std::cout << std::endl;
	}

	bool verificareCuvantGasitInTotalitate(std::string cuvantSpanzuratoare, std::string cuvantDeGasit) {
		if (cuvantDeGasit.compare(cuvantSpanzuratoare) == 0) return true;
		else return false;
	}

	bool literaSeAflaInCuvant(std::string cuvantDeGasit, char litera) {
		for (auto c : cuvantDeGasit) {
			if (c == litera) return true;
			
		}
		return false;
	}

	void desenInFunctieDeGreseli(int numarGreseli){
		switch (numarGreseli) {
		case 0:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |         " << std::endl;
			std::cout << "     |       " << std::endl;
			std::cout << "     |        " << std::endl;
			std::cout << "     |      " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;
		case 1:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |    "<<Color(4)<<"O"<<Color(7)<<"     " << std::endl;
			std::cout << "     |       " << std::endl;
			std::cout << "     |         " << std::endl;
			std::cout << "     |      " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |    O     " << std::endl;
			std::cout << "     |   "<<Color(4)<<"/|"<<Color(7)<<"    " << std::endl;
			std::cout << "     |         " << std::endl;
			std::cout << "     |      " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |    O     " << std::endl;
			std::cout << "     |   /|"<<Color(4)<<"\\"<<Color(7)<<"    " << std::endl;
			std::cout << "     |         " << std::endl;
			std::cout << "     |     " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |    O     " << std::endl;
			std::cout << "     |   /|\\    " << std::endl;
			std::cout << "     |    "<<Color(4)<<"|"<<Color(7)<<"     " << std::endl;
			std::cout << "     |      " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |    O     " << std::endl;
			std::cout << "     |   /|\\    " << std::endl;
			std::cout << "     |    |     " << std::endl;
			std::cout << "     |  "<<Color(4)<<" /"<<Color(7)<<"    " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;
		case 6:
			std::cout << "  ___________   " << std::endl;
			std::cout << "     |/   |     " << std::endl;
			std::cout << "     |    " << Color(4) << "O" << Color(7) << "     " << std::endl;
			std::cout << "     |   " << Color(4) << "/|\\" << Color(7) << "    " << std::endl;
			std::cout << "     |    " << Color(4) << "|" << Color(7) << "     " << std::endl;
			std::cout << "     |   "<<Color(4)<<"/ \\"<<Color(7)<<"   " << std::endl;
			std::cout << "     |           " << std::endl;
			std::cout << "    _|___        " << std::endl;
			std::cout << std::endl;
			break;

		}
	
	}

};

int main() {
	Spanzuratoare spanzuratoare;
	spanzuratoare.intrebare();





}