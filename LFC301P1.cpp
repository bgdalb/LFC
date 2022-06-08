

#include <iostream>
#include <string>
using namespace std;

int repetareCaracterInSir(string sir, char caracter) {
	int valoare = 0;
	for (int i = 0; i < sir.size(); i++) {
		if (sir[i] == caracter) 
		{ 
			valoare++;
		};
	}
	return valoare;
};


int main()
{
	string sir;
	char caracter;
	cout << "Introduceti sirul: ";
	cin >> sir;
	cout << "Introduceti caracterul: ";
	cin >> caracter;
	cout << "Numarul de repetari ale caracterului '" << caracter << "' in sirul '" << sir << "' este " << repetareCaracterInSir(sir, caracter);
	cout << "";
}

