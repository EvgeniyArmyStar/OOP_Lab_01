#include "studentgroup.h"

bool StudentGroup::findStudent(Student * student)
{
	for (auto i : students)
	{
		if (i == student)
			return true;
	}

	return false;
}

bool StudentGroup::canInviteStudent(Student * student)
{
	if (student->getAge() >= getMinAge() && student->getPersonalRating() >= getMinRating())
		return true;

	return false;
}

const Student * StudentGroup::getStudent(const string & _firstName, const string & _secondName)
{
	for (const auto i : students)
	{
		if (i->getFirstName() == _firstName && i->getSecondName() == _secondName)
			return i;
	}
	return nullptr;
}

const string & StudentGroup::getGroupName()
{
	return groupName;
}

const double & StudentGroup::getMinRating()
{
	return minRating;
}

const size_t & StudentGroup::getStudentsCount()
{
	return students.size();
}

const int & StudentGroup::getGroupID()
{
	return groupID;
}

const int & StudentGroup::getMinAge()
{
	return minAge;
}

void StudentGroup::setGroupName(const string & _groupName)
{
	groupName = _groupName;
}

void StudentGroup::setGroupID(const unsigned int & _groupID)
{
	groupID = _groupID;
}

void StudentGroup::setMinAge(const unsigned int & _age)
{
	minAge = _age;
}

void StudentGroup::setMinRating(const double & _rating)
{
	minRating = _rating;
}

void StudentGroup::addStudent(Student * student)
{
	if (getStudentsCount() >= MAX_STUDENTS)
		return;

	if (findStudent(student))
		return;

	if (!canInviteStudent(student))
		return;

	students.push_back(student);
	student->increaseGroupJoins();
}

void StudentGroup::removeStudent(Student * student)
{
	for (auto it = students.begin(); it < students.end(); ++it)
	{
		if (*it == student)
		{
			students.erase(it);
			student->decreaseGroupJoins();
			return;
		}
	}
}

void StudentGroup::sortWithSecondName()
{
	sort(students.begin(), students.end(), [](Student* s1, Student* s2)
	{
		return s1->getSecondName() < s2->getSecondName();
	});
}

void StudentGroup::sortWithRating()
{
	sort(students.begin(), students.end(), [](Student* s1, Student* s2)
	{
		return s1->getPersonalRating() > s2->getPersonalRating();
	});
}

void StudentGroup::startSession()
{
	for (auto i : students)
	{
		if (i->getAge() < getMinAge())
			removeStudent(i);

		if (i->getPersonalRating() < getMinRating())
			removeStudent(i);
	}
}

void StudentGroup::printStudents()
{
	cout << getGroupName() << " members: \n";
	for (auto i : students)
	{
		cout << i->getFirstName() << " " << i->getSecondName() << " age: " << i->getAge() << " rating: " << i->getPersonalRating() << endl;
	}
	cout << getStudentsCount() << " - students in this group. \n\n";
}