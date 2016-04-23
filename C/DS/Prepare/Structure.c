#include <stdio.h>
#include <malloc.h>
typedef struct {
	int stuNum;
	char* stuName;
}Student;

void initCharSpace(char* address, int number) {
	for (int i = 0; i < number; i++) {
		*(address + i) = '\0';
	}
}

void main() {
	Student stu1;
	stu1.stuNum = 1;
	char* tmpStuNum = (char *)malloc(6);
	initCharSpace(tmpStuNum, 6);
	tmpStuNum = "name1";
	stu1.stuName = tmpStuNum;
	printf("stuNum=%d,stuName=%s\n", stu1.stuNum, stu1.stuName);

	Student stu2;
	stu2.stuNum = 2;
	tmpStuNum = (char *)malloc(6);
	initCharSpace(tmpStuNum, 6);
	tmpStuNum = "name2";
	stu2.stuName = tmpStuNum;
	printf("stuNum=%d,stuName=%s\n", stu2.stuNum, stu2.stuName);
}