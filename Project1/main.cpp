#include "BiTree.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {

	std::ifstream file("file.txt");
	std::string elem;
	char symble;
	std::cin >> symble;
	BiTree arr;
	system_clock::time_point start = system_clock::now();
	if (file.is_open()) {
		while (!file.eof()) {
			file >> elem;
			if (elem[0] == symble) {
				std::cout << elem << std::endl;
			}
		}
	}
	file.close();
	system_clock::time_point end = system_clock::now();
	std::cout << "Time to file" << std::endl;
	std::cout << duration_cast<nanoseconds>(end - start).count() << std::endl;
		
	system_clock::time_point starte = system_clock::now();
	std::ifstream files("file.txt");
	if (files.is_open()) {
		while (!files.eof()) {
			files >> elem;
			arr.add(elem);
		}
	}
	arr.FoundSymbol(symble);
	arr.show();
	system_clock::time_point ende = system_clock::now();
	std::cout << "Time to tree" << std::endl;
	std::cout << duration_cast<nanoseconds>(ende - starte).count() << std::endl;
	

}
