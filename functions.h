void printHeader(void);
void printMenu(void);

void addCourse(courses *courseArray);
void addStudent(students *studentArray);
void addStudentToCourse(courses *courseArray, students *studentArray, enrollments *enrollArray);
void addGrades(courses *courseArray, students *studentArray, enrollments *enrollArray);
void printGrades(courses *courseArray, students *studentArray, enrollments *enrollArray);
void printStudentinCourse(courses *courseArray,int courseAddress,students *studentArray,enrollments *enrollArray);
void averageStudentGrade(courses *courseArray, students *studentArray, enrollments *enrollArray);
void printCourses(courses *courseArray);
void printStudents(students *studentArray);
void courseAverage(courses *courseArray, enrollments *enrollArray);
void storeGradebook(courses *courseArray, students *studentArray, enrollments *enrollArray);
void loadGradebook(courses *courseArray, students *studentArray, enrollments *enrollArray);

int pickCourse(courses *courseArray);
int pickStudent(students *studentArray);
int pickStudentInCourse(courses *courseArray, int courseAddress, students *studentArray, enrollments *enrollArray);
int detEnroll(enrollments *enrollArray, courses *courseArray, students *studentArray, int courseAddress, int studentAddress);
