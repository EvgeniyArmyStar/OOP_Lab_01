#include <iostream>
#include "studentgroup.h"

int main()
{
	StudentGroup* english = new StudentGroup("English #1", 2222);
	english->setMinAge(16);
	english->setMinRating(3);

	Student* mike = new Student("Mike", "Johnson", 18, 4.3);
	Student* andrew = new Student("Andrew", "Jonss", 22, 2.3);
	Student* michel = new Student("Michel", "Anos", 16, 5);
	Student* anthony = new Student("Anthony", "Grey", 17, 4);
	Student* trevor = new Student("Trevor", "Turner", 25, 3.5);

	english->addStudent(mike); 
	english->addStudent(andrew); // low rating
	english->addStudent(michel);
	english->addStudent(anthony);
	english->addStudent(trevor);

	english->printStudents();

	english->sortWithRating();

	english->printStudents();

	english->sortWithSecondName();

	english->printStudents();

	StudentGroup* musical = new StudentGroup("Music #2", 5431);
	musical->setMinAge(14);
	musical->setMinRating(2.5);

	musical->addStudent(mike);
	musical->addStudent(andrew); // low rating
	musical->addStudent(michel);
	musical->addStudent(anthony);
	musical->addStudent(trevor);

	musical->sortWithRating();
	musical->printStudents();

	musical->setMinRating(4);
	musical->startSession();

	musical->printStudents(); // kick trevor from group

	delete mike, andrew, michel, anthony, trevor;
	delete english;

	cin.get();
}