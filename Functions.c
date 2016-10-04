#include "Structures.h"
#include "functions.h"

void printHeader(void)
{
	printf("\n┌────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("│                       CSCE 1040 - Computer Science II                          │\n");
	printf("│                            Homework Assignment 1                               │\n");
	printf("│                             Zachary Eisenhauer                                 │\n");
	printf("│                        zacharyeisenhauer@my.unt.edu                            │\n");
	printf("└────────────────────────────────────────────────────────────────────────────────┘\n");
}


    /*  ######## ######## ########  ###### ###  ##		//Old ZTech logo (updated for readability and size)							  
			###     ###            ###     ###  ##                                    
		   ###      ###    ####### ###     #######                                    
		  ###       ###    ###     ###     ###  ##                                    
		 #######    ###    #######  ###### ###  ##                                    
	 									   ###   */
void printMenu(void)
{
	//prints the menu
    printf("\n╔════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║                                                                                ║\n"); 																				 
	printf("║            _____  __            __                                             ║\n");
	printf("║           /__  / / /____  _____/ /_                                            ║\n");
	printf("║             / / / __/ _ \\/ ___/ __ \\                                           ║\n");
	printf("║            / /_/ /_/  __/ /__/ / / /                                           ║\n");
	printf("║           /____\\__/\\___/\\___/_/ /_/                                            ║\n");
	printf("║      ,___                 _ _ _                                                ║\n");
	printf("║     /   /           /    ( / ) )                                        _/_    ║\n");
	printf("║    /  ___   __,  __/ _    / / / __,  _ _   __,  _,  _  _ _ _   _  _ _   /      ║\n");
	printf("║   (___// (_(_/(_(_/_(/_  / / (_(_/(_/ / /_(_/(_(_)_(/_/ / / /_(/_/ / /_(__     ║\n");
	printf("║                                                 /|                             ║\n");
	printf("║                                                (/                              ║\n");
	printf("║                         __,                                                    ║\n");
	printf("║                        (        //    _/_o           _                         ║\n");
	printf("║                         `.  __ // , , / ,  __ _ _   (                          ║\n");
	printf("║                       (___)(_)(/_(_/_(__(_(_)/ / /_/_)                         ║\n");
	printf("║                                                                                ║\n");
	printf("║                     	1) Add a new course                                      ║\n");
	printf("║                       2) Add a new student                                     ║\n");
	printf("║                       3) Add a student to a course                             ║\n");
	printf("║                       4) Add grades for a student in a course                  ║\n");
	printf("║                       5) Print a list of all grades for a student in a course  ║\n");
	printf("║                       6) Print a list of all students in a course              ║\n");
	printf("║                       7) Compute the average for a student in a course         ║\n");
	printf("║                       8) Print a list of all courses                           ║\n");
	printf("║                       9) Print a list of all students                          ║\n");
	printf("║                      10) Compute the average for a course                      ║\n");
	printf("║                      11) Store Grade book (to a disk file)                     ║\n");
	printf("║                      12) Load Grade book (from a disk file)                    ║\n");
	printf("║                      13) Help                                                  ║\n");
	printf("║                      14) Exit                                                  ║\n");
	printf("║                                                                                ║\n");
	printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
}
//adds a course
void addCourse(courses *courseArray)
{
	char testDepart[MAX_COURSE_SUBJECT], testCourse[MAX_COURSE_NAME], testID[4]; 
	int i;
	int valid = 0;
	
	if(courseArray->courseCount == (int)courseArray->courseCap)
	{
		course *temp;
		temp = (course *) realloc(courseArray->courseList, sizeof(course)* ((int)courseArray->courseCap + BUFFER));
		courseArray->courseCap += BUFFER;
		courseArray->courseList = temp;
	}
		
	printf("\nPlease enter the department abbrivation (up to 4 capital letters):: ");
	scanf("%4s", testDepart);
	for(i=0; i<strlen(testDepart);i++)
		testDepart[i] = toupper(testDepart[i]);
	
	strcpy((courseArray->courseList[courseArray->courseCount].department),testDepart);
	
	
	do{
		printf("\nPlease enter the 4 digit ID to correlate to your class:: ");
		scanf("%4s%*c", testID);
		for(i=0;i<4;i++)
		{
			if(isdigit(testID[i]))
				valid++;
		}
		if(valid = 4)
		{
			courseArray->courseList[courseArray->courseCount].ID = atoi(testID);
			valid++;
		}
		else
		{
			printf("\nSorry that wasn't a 4 digit number, please try again");
			valid = 0;
		}
	}while(valid < 4);
	
	printf("\nFinally, please enter a name for your course (limit is 20 characters):: ");
	scanf("%[^\n]s", courseArray->courseList[courseArray->courseCount].idName); 
	
	printf("\nCourse %s %d %s has been successfully added", courseArray->courseList[courseArray->courseCount].department, courseArray->courseList[courseArray->courseCount].ID, courseArray->courseList[courseArray->courseCount].idName);
	courseArray->courseCount += 1;
}
//adds a student
void addStudent(students *studentArray)
{
	char testName[MAX_STUDENT_NAME];
	int i;
	
	if(studentArray->studentCount == (int)studentArray->studentCap)
	{
		student *temp;
		temp = (student *) realloc(studentArray->studentList, sizeof(student) *((int)studentArray->studentCap + BUFFER));
		studentArray->studentCap += BUFFER;
		studentArray->studentList = temp;
	}
	
	//recieves the students name and gives the student an ID number
	printf("What is the students first name?:: ");
	scanf("%s", studentArray->studentList[studentArray->studentCount].fname);
	printf("What is the students last name?:: ");
	scanf("%s", studentArray->studentList[studentArray->studentCount].lname);
	studentArray->studentList[studentArray->studentCount].ID = STUDENT_ID + studentArray->studentCount; 
	studentArray->studentList[studentArray->studentCount].amountOfCourses = 0;
	
	printf("\nStudent %s %s has been added and has ID number %d", studentArray->studentList[studentArray->studentCount].fname, studentArray->studentList[studentArray->studentCount].lname, studentArray->studentList[studentArray->studentCount].ID);
	
	studentArray->studentCount += 1;
}
//adds a student to a certain course
void addStudentToCourse(courses *courseArray, students *studentArray, enrollments *enrollArray)
{
	int i, dup=0;
	//lets the user make a selection in the array
	if(courseArray->courseCount > 0 && studentArray->studentCount > 0)
	{
		int course = pickCourse(courseArray);
		int student = pickStudent(studentArray);
	
		for(i=0;i<(int)enrollArray->enrollCount; i++)
			{
				if(enrollArray->enrollList[i].courseID == courseArray->courseList[course].ID && enrollArray->enrollList[i].studentID == studentArray->studentList[student].ID)
					dup = 1;
			}
		
		//checks to see if student can still add classes
		if(dup == 0)
		{
			//if he/she can then enroll them (update all the variables)
			enrollArray->enrollList[enrollArray->enrollCount].studentID = studentArray->studentList[student].ID;
			enrollArray->enrollList[enrollArray->enrollCount].courseID = courseArray->courseList[course].ID;
			enrollArray->enrollList[enrollArray->enrollCount].gradeCount = 0;
			
			studentArray->studentList[student].amountOfCourses += 1;
			courseArray->courseList[course].studentsEnrolled += 1;
			(enrollArray->enrollCount)++;
			
			printf("\nStudent %s %s has been added to course %s %d %s", studentArray->studentList[student].fname, studentArray->studentList[student].lname, courseArray->courseList[course].department, courseArray->courseList[course].ID, courseArray->courseList[course].idName);
		}
		else
			printf("\nstudent %s %s is already enrolled", studentArray->studentList[student].fname, studentArray->studentList[student].lname);
	}
	else
		printf("\nCheck list of all courses using 8 on the menu or list of all students using 9. One of them is empty.");
	
}
//adds grades for a student in a certain course

//********Where I am******************//
void addGrades(courses *courseArray, students *studentArray, enrollments *enrollArray)
{
	int course = pickCourse(courseArray);
	
	if(courseArray->courseList[course].studentsEnrolled > 0)
	{
		int student = pickStudentInCourse(courseArray, course, studentArray, enrollArray);
		int numGrades, i, tempGrade;
		int enrollment = detEnroll(enrollArray, courseArray, studentArray, course, student);
		int gradeCount = enrollArray->enrollList[enrollment].gradeCount;
		
		printf("How many grades do you want to enter?:: ");
		scanf("%d", &numGrades);
		if(enrollArray->enrollList[enrollment].gradeCount == enrollArray->enrollList[enrollment].gradeCap)
		{
			int *tempGrades = (int *) realloc(enrollArray->enrollList[enrollment].gradeList, sizeof(int) *(enrollArray->enrollList[enrollment].gradeCap + numGrades));
			enrollArray->enrollList[enrollment].gradeCap += numGrades;
			enrollArray->enrollList[enrollment].gradeList = tempGrades;
		}
			//loops for each grade user wants to enter
			for(i=0;i<numGrades;i++)
			{
				printf("\nPlease enter a grade from 0 to 100:: ");
				scanf("%d%*c", &tempGrade);
				if(tempGrade >= 0 && tempGrade <= 100){
					enrollArray->enrollList[enrollment].gradeList[gradeCount++] = tempGrade;
					//enrollArray->enrollList[enrollment].gradeCount++;
				}
				else
				{
					printf("\nThat isn't a grade from 0 to 100.");
					i -= 1;
				}
			}
			//update the grade count
			enrollArray->enrollList[enrollment].gradeCount += numGrades;
			printf("Grades have been successfully added.");
	}
	else
		printf("\nNo students are enrolled in this course.");
}

void printGrades(courses *courseArray, students *studentArray, enrollments *enrollArray)
{
	int course = pickCourse(courseArray);
	
	if(courseArray->courseList[course].studentsEnrolled > 0)
	{
		int student = pickStudentInCourse(courseArray, course, studentArray, enrollArray);
		int enrollment = detEnroll(enrollArray, courseArray, studentArray, course, student);
		if(enrollArray->enrollList[enrollment].gradeCount > 0)
		{
			int i;
			 printf("\n╔════════════════════════════════════════════════════════════════════════════════╗\n");
			 printf("║                                                                                ║\n"); 																				 
			 printf("║                      _____               _                                     ║\n");
			 printf("║                     / ____|             | |                                    ║\n");
			 printf("║                    | |  __ _ __ __ _  __| | ___  ___                           ║\n");
			 printf("║                    | | |_ | '__/ _` |/ _` |/ _ \\/ __|                          ║\n");
			 printf("║                    | |__| | | | (_| | (_| |  __/\\__ \\                          ║\n");
			 printf("║                     \\_____|_|  \\__,_|\\__,_|\\___||___/                          ║\n");
			 printf("║                                                                                ║\n");							
			 printf("║ for student: %15s %15s in course: %20s   ║\n", studentArray->studentList[student].fname, studentArray->studentList[student].lname, courseArray->courseList[course].idName); 																				 
			 printf("╠════════════════════════════════════════════════════════════════════════════════╣\n");
			 printf("║                                                                                ║\n");
			 printf("║       Grades:                                                                  ║\n");
			 printf("║                                                                                ║\n");
			 
			 for(i=0;i<enrollArray->enrollList[enrollment].gradeCount;i++)
			 {
				
				printf("║    %2d) %3d                                                                     ║\n", i+1, enrollArray->enrollList[enrollment].gradeList[i]);
			 }
			 printf("║                                                                                ║\n");
			 printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
					
		}
		else
			printf("There are no grades to report!");
			
	}
	else
		printf("No students are enrolled in this course!");
}

//prints  the students enrolled in a certain course
void printStudentinCourse(courses *courseArray,int courseAddress,students *studentArray,enrollments *enrollArray)
{
	//int course = pickCourse(courses, courseCount);
	int student, i;
	
	printf("\n╔════════════════════════════════════════════════════════════════════════════════╗\n");
	 printf("║                                                                                ║\n"); 																				 
	 printf("║                     _____ _             _            _                         ║\n");
     printf("║                    / ____| |           | |          | |                        ║\n");
     printf("║                   | (___ | |_ _   _  __| | ___ _ __ | |_ ___                   ║\n");
     printf("║                    \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __/ __|                  ║\n");
     printf("║                    ____) | |_| |_| | (_| |  __/ | | | |_\\__ \\                  ║\n");
     printf("║                   |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|___/                  ║\n");
	 printf("║                                                                                ║\n");
	 printf("║                     for course: %20s                           ║\n", courseArray->courseList[courseAddress].idName); 																				 
	 printf("╠════════════════════════════════════════════════════════════════════════════════╣\n");
	 printf("║                                                                                ║\n");
	 printf("║         Name                                      ID                           ║\n");
	 printf("║                                                                                ║\n");
	 
	 for(i=0;i<(int)enrollArray->enrollCount;i++)
	 {
		 if(enrollArray->enrollList[i].courseID == courseArray->courseList[courseAddress].ID){
			student = enrollArray->enrollList[i].studentID - STUDENT_ID;
		printf("║    %3d) %-20s %-20s %-8d                     ║\n", i+1, studentArray->studentList[student].fname, studentArray->studentList[student].lname, studentArray->studentList[student].ID);
		}
	 }
	 printf("║                                                                                ║\n");
	 printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
	 
	 
}

//Calculates the average for a student in a certain class
void averageStudentGrade(courses *courseArray, students *studentArray, enrollments *enrollArray)
{
	int course = pickCourse(courseArray);
	if(courseArray->courseList[course].studentsEnrolled > 0)
	{
		int student = pickStudentInCourse(courseArray, course, studentArray, enrollArray);
		int enrollment = detEnroll(enrollArray, courseArray, studentArray, course, student);
		if(enrollArray->enrollList[enrollment].gradeCount > 0)
		{
			int i; 
			double sum = 0.0;
			double average;
			
			for(i=0;i<enrollArray->enrollList[enrollment].gradeCount;i++)
				sum += enrollArray->enrollList[enrollment].gradeList[i];
			average = sum / (double)enrollArray->enrollList[enrollment].gradeCount;
			
			printf("\nThe average for student %s %s in class %s is %.2f", studentArray->studentList[student].fname, studentArray->studentList[student].lname, courseArray->courseList[course].idName, average);
		}
		else
			printf("\nCannot average because there are no grades");
	}
	else
		printf("\nCannot average because no students are enrolled in a course");
}

//prints all of the courses
void printCourses(courses *courseArray)
{
	 int i;
	 printf("\n╔════════════════════════════════════════════════════════════════════════════════╗\n");
	 printf("║                                                                                ║\n"); 																				 
	 printf("║                       _____                                                    ║\n");
     printf("║                      / ____|                                                   ║\n");
     printf("║                     | |     ___  _   _ _ __ ___  ___  ___                      ║\n");
     printf("║                     | |    / _ \\| | | | '__/ __|/ _ \\/ __|                     ║\n");
     printf("║                     | |___| (_) | |_| | |  \\__ \\  __/\\__ \\                     ║\n");
     printf("║                      \\_____\\___/ \\__,_|_|  |___/\\___||___/                     ║\n");
	 printf("║                                                                                ║\n");
	 printf("║                                                                                ║\n"); 																				 
	 printf("╠════════════════════════════════════════════════════════════════════════════════╣\n");
	 printf("║                                                                                ║\n");
	 printf("║                  Department ID   Course Name                                   ║\n");
	 
	 for(i=0;i<courseArray->courseCount;i++)
	 {
		 printf("║              %2d) %-4s       %-4d %-20s                          ║\n", i+1, courseArray->courseList[i].department, courseArray->courseList[i].ID, courseArray->courseList[i].idName);
	 }
	 printf("║                                                                                ║\n");
	 printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
}
//prints all students
void printStudents(students *studentArray)
{
	 int i;
	 printf("\n╔════════════════════════════════════════════════════════════════════════════════╗\n");
	 printf("║                                                                                ║\n"); 																				 
	 printf("║                     _____ _             _            _                         ║\n");
     printf("║                    / ____| |           | |          | |                        ║\n");
     printf("║                   | (___ | |_ _   _  __| | ___ _ __ | |_ ___                   ║\n");
     printf("║                    \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __/ __|                  ║\n");
     printf("║                    ____) | |_| |_| | (_| |  __/ | | | |_\\__ \\                  ║\n");
     printf("║                   |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|___/                  ║\n");
	 printf("║                                                                                ║\n");
	 printf("║                                                                                ║\n"); 																				 
	 printf("╠════════════════════════════════════════════════════════════════════════════════╣\n");
	 printf("║                                                                                ║\n");
	 printf("║         Name                                      ID                           ║\n");
	 printf("║                                                                                ║\n");
	 
	 for(i=0;i<studentArray->studentCount;i++)
	 {
		 printf("║    %-3d) %-20s %-20s %-8d                     ║\n", i+1, studentArray->studentList[i].fname, studentArray->studentList[i].lname, studentArray->studentList[i].ID);
	 }
	 printf("║                                                                                ║\n");
	 printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
}
//Calculates the average for all grades in a course 
void courseAverage(courses *courseArray, enrollments *enrollArray)
{
	//lets the user pick a course
	int course = pickCourse(courseArray);
	
	//checks enrollment
	if(courseArray->courseList[course].studentsEnrolled > 0)
	{
		int i,j, gradeCounter = 0; 
		double sum = 0.0;
		
		//goes through every student and every grade and adds them up
		for(i=0;i<(int)enrollArray->enrollCount;i++)
		{
			if(enrollArray->enrollList[i].courseID == courseArray->courseList[course].ID && enrollArray->enrollList[i].gradeCount > 0)
			{
				for(j=0;j<enrollArray->enrollList[i].gradeCount;j++)
				{
					sum+= enrollArray->enrollList[i].gradeList[j];
					gradeCounter++;
				}
			}
		}
		//takes the average if a grade exists
		if(gradeCounter > 0)
		{
			double average = sum / gradeCounter;
			printf("\nThe average for course %s is %.2f", courseArray->courseList[course].idName, average);
		}
		else
			printf("\nThere are no grades in this course.");
	}
	else
		printf("\nThere are no students in this course.");
}
//saves gradebook
void storeGradebook(courses *courseArray, students *studentArray, enrollments *enrollArray)
{
	FILE* gradebook = fopen("gradebook.dat", "w");
	
	if(gradebook != NULL)
	{
		fprintf(gradebook, "%d %d %d", courseArray->courseCount, studentArray->studentCount, enrollArray->enrollCount);
		fwrite(courseArray->courseList, courseArray->courseCount, sizeof(course), gradebook);
		fwrite(studentArray->studentList, studentArray->studentCount, sizeof(student), gradebook);
		fwrite(enrollArray->enrollList, enrollArray->enrollCount, sizeof(enrollment), gradebook);
		printf("\nThe gradebook successfully saved to the file gradebook.dat\n");
	}
	else
		printf("Gradebook did not save. Please try again later");
	fclose(gradebook);
}
//loads previous save of gradebook
void loadGradebook(courses *courseArray, students *studentArray, enrollments *enrollArray)
{
	FILE* gradebook = fopen("gradebook.dat", "r");
	
	if(gradebook != NULL)
	{
		fscanf(gradebook, "%d %d %d", &courseArray->courseCount, &studentArray->studentCount, &enrollArray->enrollCount);
		fread(courseArray->courseList, courseArray->courseCount, sizeof(course), gradebook);
		fread(studentArray->studentList, studentArray->studentCount, sizeof(student), gradebook);
		fread(enrollArray->enrollList, enrollArray->enrollCount, sizeof(enrollment), gradebook);
		printf("\n The gradebook successfully loaded from the file gradebook.dat");
	}
	else
		printf("We are deeply sorry, the gradebook did not open or exit. Please try again later.");
	fclose(gradebook);
}

/* Extra Classes for easier tasks  */

//lets the user pick a course
int pickCourse(courses *courseArray)
{
	int temp = 0;
	printCourses(courseArray);
	printf("Pick a course from the above list using the number values:: ");
	scanf("%d%*c", &temp);
	if(temp <= courseArray->courseCount && temp > 0)
		return temp-1;
	else{
		printf("That isn't valid. Remember, pick the course with the number selection.");
		return pickCourse(courseArray);
	}
}
//lets the user pick a student
int pickStudent(students *studentArray)
{
	int temp;
	printStudents(studentArray);
	printf("Pick a student from the above list using the number values:: ");
	scanf("%d%*c", &temp);
	if(temp <= studentArray->studentCount && temp > 0)
		return temp-1;
	else{
		printf("That isn't valid. Remember, pick the student with the number selection.");
		return pickStudent(studentArray);
	}
}
//lets the user pick a student in a course
int pickStudentInCourse(courses *courseArray, int courseAddress, students *studentArray, enrollments *enrollArray)
{
	int temp;
	printStudentinCourse(courseArray, courseAddress, studentArray, enrollArray);
	
	printf("Pick a student from the above list using the number values:: ");
	scanf("%d%*c", &temp);
	if(temp <= (int)enrollArray->enrollCount && temp > 0)
		return temp-1;
	else{
		printf("That isn't valid. Remember, pick the student with the number selection.");
		return pickStudentInCourse(courseArray, courseAddress, studentArray, enrollArray);
	}
}
//detects the enrollment the user needs
int detEnroll(enrollments *enrollArray, courses *courseArray, students *studentArray, int courseAddress, int studentAddress)
{
	int i;
	for(i=0;i<enrollArray->enrollCount;i++)
	{
		if(enrollArray->enrollList[i].courseID == courseArray->courseList[courseAddress].ID && enrollArray->enrollList[i].studentID == studentArray->studentList[studentAddress].ID)
			return i;
	}
	return -1;
}


