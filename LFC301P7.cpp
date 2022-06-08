#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool subsirInSir(string subsir, string sir) {
	if (sir.find(subsir) != string::npos) return true;
	return false;


}


int main() {
	vector<string> cuvinte,cuvintenoi;
	string cuvant,subsir;
	int n;
	cout << "Care este subsirul?";
	cin >> subsir;
	cout << "Cate cuvinte vreti sa introduceti? ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Introdu un cuvant ";
		cin >> cuvant;
		cuvinte.push_back(cuvant);

	}

	for (int i = 0; i < n; i++) {
		if (subsirInSir(subsir, cuvinte[i])) {
			cuvintenoi.push_back(cuvinte[i]);
		}
		

	}

	for (int i = 0; i < cuvintenoi.size(); i++) {
		cout << cuvintenoi[i] <<" " ;
	
	}

};