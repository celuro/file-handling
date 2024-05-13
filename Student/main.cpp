#include <iostream>
#include <fstream>
#include "Student.h"

int main() {

	Student s[10];
	std::fstream file("student.csv");

	if (file.is_open()) {
		for (int i = 0; i < 10; i++) {
			s[i].read(file);
			s[i].display();
		}
	}
	else {
		std::cout << "Can't open file.\n";
	}
}