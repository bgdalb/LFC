#include <iostream>
#include <string>
#include <string.h>
using namespace std;


void numarSiCuvinte(string sir) {
	string aux;
	int contor = 1;
	for (int i = 0; i < sir.size(); i++) {
		
		if (sir[i] == ' ') {
			cout <<contor<<". "<< aux << endl;
			aux = "";
			contor++;
		} 
		else {
			if (isalpha(sir[i])) aux =  aux + sir[i];
		}
	
	}
	cout <<contor<<". "<< aux;


};


int main() {
	string sir;
	cout << "Introduceti sirul: ";
	getline(cin,sir);
	
	
	numarSiCuvinte(sir);




};