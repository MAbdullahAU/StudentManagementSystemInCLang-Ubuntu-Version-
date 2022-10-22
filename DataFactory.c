#include "DataFactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int records = 0;

void DeleteStudentRecord(Student* StudentsData, int StudentID)
{
	int i,j ;
	for(i=0; i < records; i++)
	{
		if(StudentsData[i].id == StudentID)
		{
			
			for(j=i; j < records - 1; j++)
			{
				strcpy(StudentsData[j].name, StudentsData[j+1].name);
				StudentsData[j].id = StudentsData[j+1].id;
			    StudentsData[j].age = StudentsData[j+1].age;
			    StudentsData[j].Class = StudentsData[j+1].Class;
			}
			free(StudentsData[records - 1].name);
			records-- ;
			break;
		}
	}
}

void MakeNewStudnetRecord(Student* StudentsData)
{
	records++;
	StudentsData = (Student*)realloc(StudentsData, records * sizeof *StudentsData);
	
	StudentsData[records-1].name=(char*)malloc(sizeof(char*));
	   
    printf("Enter new student name : ");
    scanf("%s",StudentsData[records-1].name);

    printf("Enter new student id  : ");
    scanf("%d",&StudentsData[records-1].id);
    
	printf("Enter new student age  : ");
    scanf("%d",&StudentsData[records-1].age);
    
    printf("Enter new student Class : ");
    scanf("%d",&StudentsData[records-1].Class);	
}

void UpdateStudentRecord(Student* StudentsData, int StudentID)
{
	int i;
	for(i=0; i < records; i++)
	{
		if(StudentsData[i].id == StudentID)
		{
			printf("Enter updated student name : ");
		    scanf("%s",StudentsData[i].name);
		
		    printf("Enter updated student id  : ");
		    scanf("%d",&StudentsData[i].id);
		    
			printf("Enter updated student age  : ");
		    scanf("%d",&StudentsData[i].age);
		    
		    printf("Enter updated student Class : ");
		    scanf("%d",&StudentsData[i].Class);
		}
	}
}

void CurrentStudentsList(Student* StudentsData)
{
	int i;
	
	printf("SNO. Student Name		ID		Age		Class");
	for (i = 0; i < records; i++)
	    printf("\n %d	%s		%d		%d		%d ",i+1,StudentsData[i].name,StudentsData[i].id,StudentsData[i].age,StudentsData[i].Class);
	printf("\n\n");

}

Student* LoadDataFromFile(Student* StudentsData, char* FileName)
{
	
	//TotalCount = 2;

	//StudentsData = (Student*)realloc(StudentsData, TotalCount * sizeof *StudentsData);
	
//    StudentsData[0].name=(char*)malloc(sizeof(char*));
//    strcpy(StudentsData[0].name, "Saad");
//	StudentsData[0].id = 1;
//    StudentsData[0].age = 12;
//    StudentsData[0].Class = 7;
//    
//    StudentsData[1].name=(char*)malloc(sizeof(char*));
//    strcpy(StudentsData[1].name, "Sudais");
//	StudentsData[1].id = 2;
//    StudentsData[1].age = 17;
//    StudentsData[1].Class = 9;	

	FILE *file;
  
	char TempName[50];
  
	file = fopen(FileName, "r"); 
  
	if (file == NULL)
	{
		printf("Error opening file.\n");
  	}
  	
	//Student students[100];
	int read = 0;
  	
  	int i = 0;
  	
	do 
  	{
  		StudentsData[records].name=(char*)malloc(sizeof(char*));
  		
    	read = fscanf(file, "%49[^,],%d,%d,%d\n", TempName, &StudentsData[records].id, &StudentsData[records].age,  &StudentsData[records].Class);
	
		//printf("%s %d %d %d\n", TempName, StudentsData[i].id, StudentsData[i].age, StudentsData[i].Class);
  		i++;
		  //printf("\n");
  	
	  	strcpy(StudentsData[records].name,TempName);
		 
    	if (read == 4) records++;
    	
		if (read != 4 && !feof(file))
    	{
      		printf("Error Log : File format incorrect.\n");
      	}
    	
		if (ferror(file))
    	{
      		printf("Error Log : Error reading file.\n");
    	}

  	} while (!feof(file));
  
  	fclose(file);
  
  	//printf("\n%d records read.\n\n", records);
  
  	for (i = 0; i < records; i++)
    //	printf("%s %d %d %d\n", StudentsData[i].name, StudentsData[i].id, StudentsData[i].age, StudentsData[i].Class);
  	
	printf("\n");
  
  	//for (i = 0 ; i > 2; i--)
	//	free(students[i].name);
	
	return StudentsData;
  
}

void ReLoadDataToFile(Student* StudentsData, char* FileName)
{
	FILE *filePointer ;
	int i;
	char dataToBeWritten[100];
	char mystr[10];

	filePointer = fopen(FileName, "w+") ;
	
	if ( filePointer == NULL )
	{
		printf("Error Log : File not found");
	}
	else
	{
		
		
		for(i = 0; i < records; i++)
		{
			strcat(StudentsData[i].name,",");
			sprintf(mystr, "%d", StudentsData[i].id);
			strcat(StudentsData[i].name,mystr);
			strcat(StudentsData[i].name,",");
			sprintf(mystr, "%d", StudentsData[i].age);
			strcat(StudentsData[i].name,mystr);
			strcat(StudentsData[i].name,",");
			sprintf(mystr, "%d", StudentsData[i].Class);
			strcat(StudentsData[i].name,mystr);
			
			//printf("\nToFile-->>%s",StudentsData[i].name,mystr);
			
				
			if ( strlen ( StudentsData[i].name ) > 0 )
			{
				fputs(StudentsData[i].name, filePointer) ;
				fputs("\n", filePointer) ;
			}
		}
		
		fclose(filePointer) ;
	}
}

void Distructor(Student* StudentsData)
{
	int i;
	for (i = records-1 ; i > -1; i--)
		free(StudentsData[i].name);
	free(StudentsData);	
}


