#include <stdio.h>
#include <malloc.h>
typedef struct StudentStruct{
	int stuNum;
	char* stuName;
	struct StudentStruct* next;
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

	Student stu2;
	stu2.stuNum = 2;
	tmpStuNum = (char *)malloc(6);
	initCharSpace(tmpStuNum, 6);
	tmpStuNum = "name2";
	stu2.stuName = tmpStuNum;

	stu1.next = &stu2;
	stu2.next = NULL;

	printf("stuNum=%d,stuName=%s,next=%p\n", stu1.stuNum, stu1.stuName, stu1.next);
	printf("stuNum=%d,stuName=%s,next=%p\n", stu2.stuNum, stu2.stuName, stu2.next);
	printf("stuNum=%d,stuName=%s,next=%p\n", stu1.next->stuNum, stu1.next->stuName, stu1.next->next);
}