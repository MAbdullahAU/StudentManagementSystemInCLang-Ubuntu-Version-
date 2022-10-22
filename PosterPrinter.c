#include "PosterPrinter.h"
#include <stdio.h>
#include <stdlib.h>

void PosterPrinter(int selector)
{
	switch(selector)
	{
		case 0:
			printf("Welome To School Management Systems\n\n");
			break;
			
		case 1:
			printf("1. You Can Add a Student Record\n");
			printf("2. You Can Change a Student Record\n");
			printf("3. You Can Delete a Student Record\n");
			printf("4. To Exit the program\n");
			printf("\n");
			break;
			
		case 2:
			printf("Log: The Record has been Added Successfully\n");
			break;
		
		case 3:
			printf("Log: The Record Addition has been Failed\n");
			break;
		
		case 4:
			printf("Log: The Record has been Deleted Successfully\n");
			break;
			
		case 5:
			printf("Log: The Record Deletion has been Failed\n");
			break;
		
		case 6:
			printf("Log: The Record has been changed successfully\n");
			break;
		
		case 7:
			printf("Log: The Record changes has been failed\n");
			break;	
		
		case 8:
			printf("Thanks for using the Students Managent System\n");
			break;
			
		case 9:
			printf("Log: The Program has been Successfully Started\n");
			break;
			
		case 10:
			printf("Log: The Program has been Successfully Terminated\n");
			break;
		
		case 11:
			printf("Please Select the Option from the Manu : ");
			break;
			
			
		case 100:
			printf("**************************************************\n");
			printf("**************************************************\n");
			printf("**************************************************\n");
			printf("\n");
			break;
		
		case 101:
			printf("Log: Distrutor Failed");
			break;
			
		case 102:
			printf("Log: Samples Loading Failed");
			break;
	}
}

void TerminalClear(void)
{
	system("clear");
}



