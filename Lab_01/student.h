#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
private:
	string firstName;
	string secondName;
	double personalRating;
	unsigned int age;
	unsigned int groupJoins = 0;

public:
	Student() = delete;

	Student(const string& _firstName, const string& _secondName, const int& _age, const double& _personalRating) :
		firstName(_firstName), secondName(_secondName), age(_age), personalRating(_personalRating) {}

	const string& getFirstName();
	const string& getSecondName();
	const int& getAge();
	const double& getPersonalRating();

	void setAge(const unsigned int& _age);
	void setFirstName(const string& _firstName);
	void setSecondName(const string& _secondName);
	void setPersonalRating(const double& _rating);

	void increaseGroupJoins();
	void decreaseGroupJoins();
};

