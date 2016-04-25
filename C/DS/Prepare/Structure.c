#include <stdio.h>
#include <string.h>
typedef struct {
	int stuNum;
	char* stuName;
}Student;

void main() {
	Student stu1;
	stu1.stuNum = 1;
	stu1.stuName = "name1";
	printf("stuNum=%d,stuName=%s\n", stu1.stuNum, stu1.stuName);

	Student stu2;
	stu2.stuNum = 2;
	stu2.stuName = "name2";
	printf("stuNum=%d,stuName=%s\n", stu2.stuNum, stu2.stuName);
}