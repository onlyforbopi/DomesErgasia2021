#include <stdio.h>
#include <stdlib.h>   /*dilwsi vivliothikwn*/
#include <string.h>
#define N 100         /*megethos pinaka*/



///////////
// Name: foititis 
// Function: Basic structure to represent student
// Notes: All fields are represented by character arrays
//        except from the field 'am' which is supposed to
//        receive an incremental value on submitting. 
typedef struct foititis
{
 int am;
 char surname[20];
 char name[20];         /*Pedia einai ta stoixeia tou foititi*/
 char father_name[20];
 char mother_name[20];
 char home_address[20];
 char phone_landline[20];
 char phone_mobile[20];
 char choice_lesson[15];
}foititis; /*metavoli apo struct*/
/*Parousiasi sunolou foititwn me pinaka eggrafimatwn*/

/////////////
// Initialize Array of Structures of size N.
foititis students[N]; /*O pinakas periexei stoixeia typou struct*/

struct foititis found;
struct foititis *ptr;




/////////////
// Name: HandleMenu
// Function: Handles the user menu, displays choices.
// Input: Nothing
// Output: Selected choice <int>
// Usage: choice = HandleMenu();
// Notes: Modded to run on windows system, 'cls' will not work on linux
//        and will need to be replaced with 'clear'. Similarly, 'pause'
//        will not work and will need to be replaced with:
//        	read -p "pause"
//
//        Stores user input to a function, and returns it. 
int HandleMenu()
{
    int epilogi;
	system("cls");
    printf("Students Data:\n");
    printf("1 - Input New Student Data \n");
    printf("2 - Erase Student from Data \n");
    printf("3 - Search for Student \n");
    printf("5 - Display All Students \n");
    printf("4 - Exit \n");
    printf("Select one of the above: ");
    scanf("%d",&epilogi);
    return epilogi;
}



/////////////
// Name: displayStudent
// Function: Displays information of specific student struct.
// Input: <int>
// Output: <STDOUT>
// Usage: displayStudent(1);
// NOtes: Possible improvement, handling of multiline strings,
//        or preformatted strings with variable interpolations, if possible.
void displayStudent(int i)
{
   printf("Student data:\n"); /*typwnei stoixeia pou dothikan*/
   printf("- am: %d\n", students[i].am);
   printf("- surname: %s\n",students[i].surname);
   printf("- name: %s\n", students[i].name);
   printf("- father_name: %s\n", students[i].father_name);
   printf("- mitronimo: %s\n", students[i].mother_name);
   printf("- home_address: %s\n", students[i].home_address);
   printf("- phone_landline: %s\n", students[i].phone_landline);
   printf("- phone_mobile: %s\n", students[i].phone_mobile);
   printf("- choice_lesson:%s\n",students[i].choice_lesson);
   //system("cls");
}


/////////////
// Name: addStudent(int i)
// Function: Adds a student to the students array.
// Input: <int> => am
// Output: void
// Usage: addStudent(2)
// NOtes: Care to assign with scanf with & for scalers, and without &
//        for arrays, since an arrays name is the address to its first element.
//        This function asks the user for input to fill all struct fields
//        for the specific student, and assigns each value to the equivalent
//        structure, i of the students array.

void addStudent(int i)
{
   //system("cls");
   printf("***********************************\n");
   printf("Input data for Student: \n");	
   printf("Input AM: ");                  /*zita na dothoun ta stoixeia foititi*/
   scanf("%d",&students[i].am);
   printf("Input surname:");
   scanf("%s",students[i].surname);
   printf("Input name:");
   scanf("%s",students[i].name);
   printf("Input father name: ");
   scanf("%s",students[i].father_name);
   printf("Input mother name: ");
   scanf("%s",students[i].mother_name);
   printf("Input Home Address: ");
   scanf("%s",students[i].home_address);
   printf("Input Phone Landline: ");
   scanf("%s",students[i].phone_landline);
   printf("Input Phone Mobile: ");
   scanf("%s",students[i].phone_mobile);
   printf("Input Choice course first semester: ");
   scanf("%s",students[i].choice_lesson);
   printf("End of input. Student saved.\n");
   printf("------------------------------");
}




/////////////
// Name: displayAllStudents()
// Function: Displays all students stored in students array in preformatted
//           form.
// Input: Nothing
// Output: <STDOUT>
// Usage: displayAllStudents.
// NOtes: Clears the screen, then iterates over the student array, and prints
//        only those students that have an initialized am.
// Notes2: Possibly needing an init function for the 'am' of the entire array to
//         be 0. Tests did not appear to have problems.

void displayAllStudents()
{
	system("cls");
	printf("Displaying all students: \n");
	for (int i = 0; i < N; i++)
	{
		// If a student has been initialized, am!=0.
		if (students[i].am!=0)
		{
			printf("AM:%d|Surname:%s|Name:%s|Mathima:%s|\n", students[i].am,students[i].surname, students[i].name, students[i].choice_lesson);
		}
	}
	system("pause");
}



/////////////
// Name: delete_user(int j)
// Function: Deletes a specific user from the array.
// Input: <int j> => Real length of our data, how many students we actually
//                   have as values in the array, we do not need to iterate
//                   and check the others, since the given user value will
//                   have to be one of the entries.
// Output: <STDOUT>
// Usage: delete_user(j).
// NOtes: Waits for user input for 'am', then iterates over the first j elements
//        of the array, where j is the total number of students we ve added, if
//        it finds an 'am' that matches the user input, then it defaults the am
//        back to 0, which is our flag for inactive, and wont be printed by display.

void delete_user(int j)
{
	// Initialize variables
	int temp;
	int diagrafi = 0;

	// User input area
	printf("\nEpilekste Foititi Me AM: ");
	scanf("%d",&temp);
	printf("\nChoice is %d\n", temp);

	// Iterate j times, where j is the actual number of users.
	for(int i=0;i<j;i++)
	{
		//printf("Checking for entry: %d\n", i);
		if (students[i].am==temp)
		{
			printf("Found match for entry: %d\n", i);
			
			// A match was found, revert .am back to init value.
			students[i].am=0;
			diagrafi = 1;
			break;
		}
	}

	if (diagrafi == 1)
	{
		printf("Deletion of entry with id: %d\n", temp);
	}

	printf("End of delete\n");
	system("pause");
}




/////////////
// Name: search_student(int j)
// Function: Searches student array for a student that has a specific course.
// Input: <int j> => Real length of our data, how many students we actually
//                   have as values in the array, we do not need to iterate
//                   and check the others, since the given user value will
//                   have to be one of the entries.
// Output: <STDOUT>
// Usage: search_student(j).
// NOtes: Waits for user input for mathima epilogis, then iterates over the first j elements
//        of the array, where j is the total number of students we ve added, if
//        it finds an .choice_lesson that string compares to the user choice, then it
//        lists the equivalent entry on the screen.
// Notes: Possible improvement, store 'finds' in another array for further code process.
//        How: init array of size j (cant be more than max students), update with finds.

void search_student(int j, struct foititis *ptr)
{
	// Init character array
	char epilogis[20];

	// User input area
	printf("Eisagete mathima epilogis: \n");
	scanf("%s", epilogis);
	printf("Epilegmeno mathima: %s\n", epilogis);
	int count = 0;
	// Iterate j times, where j is the actual number of users.
	for (int i=0; i<j;i++)
	{
		int result;
		//printf("Checking for entry: %d\n", i);

		// String compare returns 0 if succesful, byte difference if unsuccesful
		// We only need to check for findings, so 0.
		result = strcmp(students[i].choice_lesson, epilogis);
		if (result==0)
		{
			printf("Count: %d", count);

			// Move results to pointer domi, with increment count
			// strcpy results in with increment i (the actual one), on (count) the found one.
			 //&(ptr+i)->am = students[i].name;
			(ptr + count)->am = students[i].am;
			strcpy((ptr+count)->name, students[i].name);
			strcpy((ptr+count)->surname, students[i].surname);
			strcpy((ptr+count)->father_name, students[i].father_name);
			strcpy((ptr+count)->mother_name, students[i].mother_name);
			strcpy((ptr+count)->choice_lesson, students[i].choice_lesson);
			strcpy((ptr+count)->phone_landline, students[i].phone_landline);
			strcpy((ptr+count)->phone_mobile, students[i].phone_mobile);
			strcpy((ptr+count)->home_address, students[i].home_address);
			//printf("Found match for\n");
			printf("AM: %d, Name: %s, Surname: %s, Mathima Epilogis: %s\n", students[i].am,students[i].name, students[i].surname, students[i].choice_lesson);
			printf("Pointers:AM: %d, Name: %s, Surname: %s, Mathima Epilogis: %s\n", (ptr + count)->am,(ptr + count)->name, (ptr + count)->surname, (ptr + count)->choice_lesson);
			
			count++;
		}
		//system("pause");
	}
	system("pause");
	printf("------------\n");
	printf("Accessing found results using pointer structure: %p\n", ptr);

	for (int i = 0; i < count; i++)
	{
		printf("%s|%s|%s|%s|%s\n", (ptr + i)->name, (ptr + i)->surname, (ptr + i)->father_name, (ptr + i)->home_address, (ptr + i)->choice_lesson);
	}
	system("pause");

}


int main()
{
	// Declare choice var, counters, tempvar.
	int choice;
	int i, j;
	int temp;
	int delete;
	
	ptr = (struct foititis*)malloc(N*sizeof(struct foititis));


	// i will hold the total number of entries
	i = 0;

	// Infinite loop for the text gui
	while(1)
	{
		// Display menu to the user - Prompt for choice
		choice = HandleMenu();
		printf("\nSelected choice: %d\n", choice);

		// Parse choice => option 1 (Input user)
		if (choice == 1)
		{
			int breakchoice;
			printf("Input student data\n");
			//i=0;

			// Do not let the user submit more than
			// the max defined amount of lines.
			while (i<N)
			{
				// Call add student to update array
				addStudent(i);

				// Display the added student
				displayStudent(i);

				// Increment the total number of students
				i++;
				system("pause");
				
				// Break to return to menu and force re-choice.
				break;				
			}
		} 
		else if (choice == 2)
		{
			//int diagrafi = 0;
			printf("Delete student data\n");
			displayAllStudents();
			//printf("I is: %d", i);

			// Call delete_user with parameter i to delete specific user.
			delete_user(i);

		}
		else if (choice == 3)
		{
			printf("Search student data\n");

			// Call search_student with i, results will be printed on screen.
			search_student(i, ptr);
		}
		else if (choice == 4)
		{
			printf("Exiting\n");
			exit(0);
		}
		else if (choice == 5)
		{
			// Display all student data.
			printf("Display student data\n");
			displayAllStudents();
		}
		else
		{
			printf("Invalid choice. Re-enter");
		}

	} 
	
	return 0;
}