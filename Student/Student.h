#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

//extern const char* g_filename = "student.csv";

class Student
{
private:
	int id;
	char* name;
	int age;
	char grade;
public:
	Student();
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();
	std::istream& read(std::istream&);
	void display() const;

	void setId(int studentId);
	void setName(const char* name);
	void setAge(int age);
	void setGrade(char age);

	int getId() const;
	const char* getName() const;
	int getAge() const;
	char getGrade() const;
};

#endif