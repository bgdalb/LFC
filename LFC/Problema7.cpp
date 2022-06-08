#include <iostream>
#include <string>
#include <vector>
#include <fstream>

bool contineSubsir(std::string s, std::string s1) {

	if (s.find(s1) != std::string::npos) {
		return true;
	}

	return false;
}

int main() {
	std::vector<std::string> vectorCuvinte, vectorCuvinteEvaluate;
	std::fstream f("cuvinte.txt");
	std::string auxiliar;
	while (getline(f, auxiliar)) {
		vectorCuvinte.push_back(auxiliar);
	}
	std::cout << "Subsir:";
	std::cin >> auxiliar;
	for (auto cuvant : vectorCuvinte) {
		if (contineSubsir(cuvant, auxiliar)) {
			vectorCuvinteEvaluate.push_back(cuvant);
		}
	}

	for (auto cuvant : vectorCuvinteEvaluate) {
	
		std::cout << cuvant << " ";
	
	}

	f.close();
}