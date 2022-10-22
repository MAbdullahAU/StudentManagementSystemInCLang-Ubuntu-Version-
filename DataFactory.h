#ifndef DATAFACTORY_H
#define DATAFACTORY_H

typedef struct
{
	int id;
	char* name;
	int age;
	int Class;
} Student;

//int TotalCount= 10;


void DeleteStudentRecord(Student* StudentsData, int StudentID);
void MakeNewStudnetRecord(Student* StudentsData);
void UpdateStudentRecord(Student* StudentsData, int StudentID);
Student* LoadDataFromFile(Student* StudentsData, char* FileName);
void CurrentStudentsList(Student* StudentsData);
void Distructor(Student* StudentsData);
void ReLoadDataToFile(Student* StudentsData, char* FileName);

#endif
