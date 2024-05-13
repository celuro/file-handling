#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

using namespace std;

Student::Student()
{
	name = nullptr;
	age = 0;
	id = 0;
	grade = 'F';
}

Student::Student(const Student& other)
{
	if (other.name != nullptr) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	else {
		name = nullptr;
	}

	if (other.age > 0) {
		age = other.age;
	}
	else {
		age = 0;
	}

	if (other.id > 0) {
		id = other.id;
	}
	else {
		id = 0;
	}

	grade = other.grade;
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		delete[] name;
		id = other.id;
		age = other.age;
		grade = other.grade;

		if (other.name != nullptr) {
			name = new char[strlen(other.name) + 1];
			if (name != nullptr) {
				strcpy(name, other.name);
			}
			else {
				name = nullptr;
			}
		}
		else {
			name = nullptr;
		}
	}
	return *this;
}

Student::~Student()
{
	delete[] name;
}

std::istream& Student::read(std::istream& is)
{
	if (is.good()) {
		std::string tempName;
		is >> id;
		is.ignore(1);
		std::getline(is, tempName, ',');
		name = new char[tempName.length() + 1];
		if (name != nullptr) {
			strncpy(name, tempName.c_str(), tempName.length() + 1);
		}
		else {
			name = nullptr;
		}
		is >> age;
		is.ignore(1);
		is >> grade;
	}
	else {
		std::cout << "Error reading from file.\n";
	}
	return is;
}

void Student::display() const
{
	static int count = 0;
	count++;
	std::cout << count << "." << " ID | NAME | AGE | GRADE | \n";
	std::cout << std::setw(5) << id << ' ';
	std::cout << std::setw(7) << name << ' ';
	std::cout << std::setw(4) << age << ' ';
	std::cout << std::setw(6) << grade << ' ';
	std::cout << '\n';
}

void Student::setId(int studentId)
{
	if (studentId > 0) {
		this->id = studentId;
	}
	else {
		this->id = 0;
	}
}

void Student::setName(const char* name)
{
	if (name != nullptr) {
		this->name = new char[strlen(name) + 1];
		if (this->name != nullptr) {
			strcpy(this->name, name);
		}
		else {
			this->name = nullptr;
		}
	}
	else {
		this->name = nullptr;
	}
}

void Student::setAge(int age)
{
	if (age > 0) {
		this->age = age;
	}
	else {
		this->age = 0;
	}
}

void Student::setGrade(char grade)
{
	this->grade = grade;
}

int Student::getId() const
{
	return id;
}

const char* Student::getName() const
{
	return name;
}

int Student::getAge() const
{
	return age;
}

char Student::getGrade() const
{
	return grade;
}
