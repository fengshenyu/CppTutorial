#include <stdio.h>
typedef struct StudentStruct{
	int stuNum;
	char* stuName;
	struct StudentStruct* next;
}Student;

void main() {
	Student stu1;
	stu1.stuNum = 1;
	stu1.stuName = "name1";

	Student stu2;
	stu2.stuNum = 2;
	stu2.stuName = "name2";

	stu1.next = &stu2;
	stu2.next = NULL;

	printf("stuNum=%d,stuName=%s,next=%p\n", stu1.stuNum, stu1.stuName, stu1.next);
	printf("stuNum=%d,stuName=%s,next=%p\n", stu2.stuNum, stu2.stuName, stu2.next);
	printf("stuNum=%d,stuName=%s,next=%p\n", stu1.next->stuNum, stu1.next->stuName, stu1.next->next);
}