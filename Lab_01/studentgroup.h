#pragma once
#include "student.h"

class StudentGroup
{
private:
	string groupName;
	unsigned int groupID;
	unsigned int minAge = 0;
	double minRating = 0.0;
	const int MAX_STUDENTS = 20;

	vector<Student*> students;

	bool findStudent(Student* student);
	bool canInviteStudent(Student* student);

public:
	StudentGroup() = delete;

	StudentGroup(const string& _groupName, const unsigned int& _groupID) :
		groupName(_groupName), groupID(_groupID) {}

	const Student* getStudent(const string& _firstName, const string& _secondName);
	const string& getGroupName();
	const double& getMinRating();
	const size_t& getStudentsCount();
	const int& getGroupID();
	const int& getMinAge();

	void setGroupName(const string& _groupName);
	void setGroupID(const unsigned int& _groupID);
	void setMinAge(const unsigned int& _age);
	void setMinRating(const double& _rating);

	void addStudent(Student* student);
	void removeStudent(Student* student);
	void sortWithSecondName();
	void sortWithRating();
	void startSession();
	void printStudents();
};

