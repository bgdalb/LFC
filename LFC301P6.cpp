#include <iostream>
#include <string>
#include <vector>
using namespace std;

void prefixuri(string sir) {
	int boundary = 1;
	string aux;
	while (boundary < sir.size()) {
		for (int i = 0; i < boundary;i++) {
			aux = aux + sir[i];
		}
		cout << aux << endl;
		aux = "";
		boundary++;
	}
}


int main() {
	vector<string> cuvinte;
	string cuvant;
	int n;
	cout << "Cate cuvinte vreti sa introduceti? ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "Introdu un cuvant ";
		cin >> cuvant;
		cuvinte.push_back(cuvant);
		
	}

	for (int i = 0; i < n; i++) {
		prefixuri(cuvinte[i]);
		cout << endl;

	}


};