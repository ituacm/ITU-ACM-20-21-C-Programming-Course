#include <stdio.h>
#include <ctype.h> //
#include <string.h> //Search


typedef struct student{
	char name [20]; 
	int grade; 
}STUDENT; 


typedef struct gradebook {
	STUDENT students[10]; 
	int numStudents; 
}GRADEBOOK; 

void menu ()
{
	printf("Welcome to The Gradebook. Please choose an option: \n");
	printf("L: List Students\n"); 
	printf("S: Search for a Student\n");
	printf("I: Insert a Student Record\n");
	printf("U: Update a Record \n");
	printf("D: Delete a Record\n");
	printf("Q: Quit\n");
}

int insert(GRADEBOOK * gb)//insert in abc order!!
{
	if(gb->numStudents < 10)
	{
		printf("Enter Name: ");
		scanf("%s", gb->students[gb->numStudents].name); 
		printf("Enter Grade: "); 
		scanf("%d", &gb->students[gb->numStudents].grade); 
		gb->numStudents++; 
		return 1; 
	}
	return 0; 
}

void list(GRADEBOOK * gb)
{
	for(int i = 0; i < gb->numStudents; i++)
	{
		printf("%d. %s %d\n", i, gb->students[i].name, gb->students[i].grade);
	}
}

int search(GRADEBOOK * gb)
{
	char key [20]; 
	int found = 0; 
	printf("Enter Search Key: "); 
	scanf("%s", key); 

	for(int i = 0; i < gb->numStudents; i++)
	{
		if(strncmp(gb->students[i].name, key, strlen(key)) == 0)
		{
			printf("%d. %s %d\n", i, gb->students[i].name, gb->students[i].grade);
			found++; 
		}
	}
	return found; 
}

int delete(GRADEBOOK * gb, int index)
{
	if(gb->numStudents == 0 || index > gb->numStudents)
	{
		return 0; 
	}
	if(index < gb->numStudents)
	{
		for(int i = index; i < gb->numStudents; i++)
		{
			memcpy(&gb->students[i], &gb->students[i+1], sizeof(STUDENT)); 
		}
		strcpy(gb->students[gb->numStudents].name, ""); 
		gb->students[gb->numStudents].grade = 0; 
		gb->numStudents--; 
		return 1; 
	}
	else //numstudents == index
	{
		strcpy(gb->students[gb->numStudents].name, ""); 
		gb->students[gb->numStudents].grade = 0; 
		gb->numStudents--; 
		return 1; 		
	}
}

int update(GRADEBOOK * gb, int index)
{
	char name [20]; 
	if(gb->numStudents == 0 || index > gb->numStudents)
	{
		return 0; 
	}
	printf("Enter Updated Name: "); 
	scanf("%s", name); 
	strcpy(gb->students[index].name, name); 

	printf("Enter Updated Grade: \n");
	scanf("%d", &gb->students[index].grade); 
	return 1; 
}

int main (int argc, char * argv[])
{
	//Initialize Variables
	char input; 
	char buffer [100]; 

	int result = 0; 
	int index = 0; 

	GRADEBOOK gb; 
	gb.numStudents = 0; 
	
	FILE * gbFile; 

	//File Open
	if(argc != 2)
	{
		printf("Please enter: \n");
		printf("%s\n", argv[0]);
		printf("Gradebook File Name\n");
		return 0; 
	}

	char * gbFileName = argv[1];  

	printf("Read from gradebook file started...\n");
	if(!(gbFile = fopen(gbFileName, "r")))
	{
		printf("Cannot open file. \n");
		return 0;
	}

	//File Read 
	while (!(feof(gbFile)) && index < 10)
	{
		fgets(buffer, sizeof(buffer), gbFile); 
		sscanf(buffer, "%s %d", gb.students[index].name, &gb.students[index].grade); 
		index++; 
		gb.numStudents++; 
	}

	fclose(gbFile); 

	//Gradebook Operations
	while(1)
	{
		menu(); 
		scanf("%s", &input); 
		//%c olarak deneyin
		//fflush(stdin); 

		switch(toupper(input))
		{
			case 'L': 
				printf("\n************************\nList\n************************\n\n"); 
				list(&gb); 
			break; 

			case 'S': 
				printf("\n************************\nSearch\n************************\n\n"); 
				result = search(&gb); 
				printf("Found %d matches.\n", result);
			break; 

			case 'I': 
				printf("\n************************\nInsert\n************************\n\n"); 
				result = insert(&gb); 
				if(result == 1)
				{
					printf("Student successfully created.\n"); 
				}
				else
				{
					printf("Student could not be created.\n"); 
				}
			break; 

			case 'U': 
				printf("\n************************\nUpdate\n************************\n\n"); 
				result = search(&gb); 
				printf("Found %d matches.\n", result);
				printf("Choose Index to Update: \n");
				scanf("%d", &index); 
				result = update(&gb, index); 
				if(result == 1)
				{
					printf("Student successfully updated. \n"); 
				}
				else
				{
					printf("Student could not be updated. \n"); 
				}
			break; 

			case 'D': 
				printf("\n************************\nDelete\n************************\n\n"); 
				result = search(&gb); 
				printf("Found %d matches.\n", result);
				printf("Choose Index to Delete: \n");
				scanf("%d", &index); 
				result = delete(&gb, index); 
				if(result == 1)
				{
					printf("Student successfully deleted. \n"); 
				}
				else
				{
					printf("Student could not be deleted. \n"); 
				}
			break; 

			case 'Q': 
			//File Write
			printf("\n************************\nQuit\n************************\n\n"); 
			if(!(gbFile = fopen(gbFileName, "w")))
			{
				printf("Cannot open file. \n");
				return 0;
			}
			printf("Writing to file... \n");
			for(int i = 0; i < gb.numStudents; i++)
			{
				fprintf(gbFile, "%s %d\n", gb.students[i].name, gb.students[i].grade); 
			}
			fclose(gbFile); 
			return 0; 
			break; 

			default: 
			printf("Please enter a valid command. \n\n"); 

		}
	}
	return 0; 
}
