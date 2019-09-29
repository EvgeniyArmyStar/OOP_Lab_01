#include "student.h"

const string & Student::getFirstName()
{
	return firstName;
}

const string & Student::getSecondName()
{
	return secondName;
}

const int & Student::getAge()
{
	return age;
}

const double & Student::getPersonalRating()
{
	return personalRating;
}

void Student::setAge(const unsigned int & _age)
{
	age = _age;
}

void Student::setFirstName(const string & _firstName)
{
	firstName = _firstName;
}

void Student::setSecondName(const string & _secondName)
{
	secondName = _secondName;
}

void Student::setPersonalRating(const double & _rating)
{
	personalRating = _rating;
}

void Student::increaseGroupJoins()
{
	groupJoins++;
}

void Student::decreaseGroupJoins()
{
	groupJoins--;
}
