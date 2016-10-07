#include "Structures.h"
#include "functions.h"

int main(void)
{
  int menuChoice, autoSave;
  char answer;

  students studentArray;
  courses courseArray;
  enrollments enrollArray;

  studentArray.studentCount = 0;
  courseArray.courseCount = 0;
  enrollArray.enrollCount = 0;
	
  studentArray.studentList = (student *) malloc (sizeof(student)* BUFFER);
  courseArray.courseList = (course *) malloc (sizeof(course)* BUFFER);
  enrollArray.enrollList = (enrollment *) malloc (sizeof(enrollment)* BUFFER);
	
  autoSave = 2;
	
  printHeader();
	
  do{
  //displays the program options to the user
  printMenu();
  //initiates an autosave toggle
  while(answer != 'n' && answer != 'y' && autoSave == 2)
  {
    printf("\nDo you want to enable autosave? (y or n):: ");
    scanf("%1s", &answer);
    if(answer == 'y')
    {
      autoSave = 1;
      printf("Autosave is enabled.");
    }
    else if(answer == 'n')
    {
      autoSave = 0;
      printf("Autosave is disabled.");
    }
    else
    {
      printf("\nSorry that wasn't valid. Try again.");
    }
  }
  //gives the answer a value not n or y (messes with while loop latter)
  answer = 'z';
  //saves work if autosave is toggled on
  if(autoSave == 1)
    storeGradebook(&courseArray, &studentArray, &enrollArray);
		
  //asks and takes a selection from the user
  printf("\nPlease select a number option from the above menu:: ");
  scanf("%d", &menuChoice);
	
  //connections the user choice to the task requested
  switch(menuChoice)
  {
    case 1:
    {
      addCourse(&courseArray);
			
      printf("\npress ENTER to continue:: ");
      scanf("%*c[\n]");
      break;
    }
    case 2:
    {
      addStudent(&studentArray);

      printf("\npress ENTER to continue:: ");
      scanf("%*c[\n]");
      break;
    }
    case 3:
    {
      addStudentToCourse(&courseArray, &studentArray, &enrollArray);

      printf("\npress ENTER to continue:: ");
      scanf("%*c[\n]");
      break;
    }
    case 4:
    {
      if(enrollArray.enrollCount > 0)
      addGrades(&courseArray, &studentArray, &enrollArray);
			else
				printf("\nSorry, grades cannot be added because no one is enrolled");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 5:
		{
			if(enrollArray.enrollCount > 0)
				printGrades(&courseArray, &studentArray, &enrollArray);
			else
				printf("\nSorry, grades cannot be printed because no one is enrolled");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 6:
		{
			if(enrollArray.enrollCount > 0){
				int course = pickCourse(&courseArray);
				printStudentinCourse(&courseArray, course, &studentArray, &enrollArray);
			}
			else
				printf("No students have been enrolled in a course");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 7:
		{
			if(enrollArray.enrollCount > 0)
				averageStudentGrade(&courseArray, &studentArray, &enrollArray);
			else
				printf("\nNo students are enrolled in courses.");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 8:
		{
			printCourses(&courseArray);
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 9:
		{
			printStudents(&studentArray);
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 10:
		{
			if(enrollArray.enrollCount > 0)
				courseAverage(&courseArray, &enrollArray);
			else
				printf("\nNo enrollments were made which means no grades exist!");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 11:
		{
			storeGradebook(&courseArray, &studentArray, &enrollArray);
			break;
		}
		case 12:
		{
			loadGradebook(&courseArray, &studentArray, &enrollArray);
			break;
		}
		case 13:
		{
			printf("\nHelp will be added in a later update. Thank-you for using ZTech Grade Management Solutions, where your grades, matter!");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
			break;
		}
		case 14:
		{
			while(answer!='n' && answer!='y')
			{
				printf("Do you want to save? (y or n):: ");
				scanf("%1s", &answer);
				if(answer == 'y')
					storeGradebook(&courseArray, &studentArray, &enrollArray);
			}
				
			printf("\nWe hope you enjoyed Ztech Gradebook Solutions.\n");
			break;
		}
		default:
		{
			printf("\nsorry, that is not a valid input, try again");
			printf("\npress ENTER to continue:: ");
			scanf("%*c[\n]");
		}
	}
	}while(menuChoice != 14);
	
	return 0;
}
