#include "DataFactory.h"
#include "PosterPrinter.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum ManuSelectorTest { YouCanAddStudentRecord, YouCanChangeStudentRecord, YouCanDeleteStudentRecord, ExitTheProgram};


int main(int argc, char *argv[]) {
	
	
	Student* StudentsData = (Student*)malloc(10 * sizeof *StudentsData);
	bool intialLoadedData = false;
	int SelectedStudent = 0;
	int ManuSelector = 0;
	char* FileName = "TheClassData.txt"; 
		
	while(ManuSelector != 4)
	{
		TerminalClear();
		PosterPrinter(0);
		PosterPrinter(100);
		
		if(!intialLoadedData)
		{
			//printf("\n404\n");
			StudentsData = LoadDataFromFile(StudentsData,FileName);
			intialLoadedData = true;
		}
			
		CurrentStudentsList(StudentsData);
		printf("\n\n");
		PosterPrinter(1);
		PosterPrinter(11);
		
		scanf("%d", &ManuSelector);
		
		TerminalClear();
		
		PosterPrinter(0);
		PosterPrinter(100);
		
		CurrentStudentsList(StudentsData);
		printf("\n\n");
			
		switch(ManuSelector)
		{
			case 1: //YouCanAddStudentRecord
				MakeNewStudnetRecord(StudentsData);
				//getch();
				break;
			
			case 2: //YouCanChangeStudentRecord
				SelectedStudent = 0;
				printf("PLease enter the ID of the Student you need to Update : ");
				scanf("%d", &SelectedStudent);
				UpdateStudentRecord(StudentsData, SelectedStudent);
				//getch();
				break;
				
			case 3: //YouCanDeleteStudentRecord
				SelectedStudent = 0;
				printf("PLease enter the ID of the Student you need to Delete : ");
				scanf("%d", &SelectedStudent);
				DeleteStudentRecord(StudentsData, SelectedStudent);
				//getch();
				break;
				
			case 4: //ExitTheProgram
				PosterPrinter(10);
				//exit(0);
				break;
		}
			
			
		
			
	}
	
	ReLoadDataToFile(StudentsData,FileName);
	Distructor(StudentsData);
}


/*

-----Lessons Learned------

1. C dont have try and catch
2. C dont have bool but you can inculde a libray to get the functionality that is stdbool















*/
