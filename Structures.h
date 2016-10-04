//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//data constants
#define STUDENT_MAX 100
#define COURSES_MAX 25
#define STUDENT_MAX_COURSES 4
#define GRADES_MAX 10
#define COURSES_MAX_STUDENTS 20
#define MAX_STUDENT_NAME 20
#define MAX_COURSE_SUBJECT 4
#define MAX_COURSE_NAME 20
#define STUDENT_ID 10000001 
#define BUFFER 2



typedef struct
{
	int ID;
	char fname[MAX_STUDENT_NAME]; //first and last name of the student
	char lname[MAX_STUDENT_NAME];
	int amountOfCourses;
	struct stu *next;
	
}student;

typedef struct
{
	char department[MAX_COURSE_SUBJECT];
	int ID;
	char idName[MAX_COURSE_NAME];
	int studentsEnrolled;
	struct course *next;
}course;

typedef struct
{
 int studentID;
 int courseID;
 int gradeCount;
 int gradeCap;
 int *gradeList; 
 struct enroll *next;
}enrollment;

//dynamic memory allocation setup
typedef struct{
	int studentCount;	
	int *studentCap;
	student *studentList;
}students;

typedef struct{
	int courseCount;	
	int *courseCap;
	course *courseList;
}courses;

typedef struct{
	int enrollCount;	
	int *enrollCap;
	enrollment *enrollList;
}enrollments;
