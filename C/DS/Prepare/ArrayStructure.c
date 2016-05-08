#include <stdio.h>
#include <string.h>
typedef struct {
	int stuNum;
	char* stuName;
}Student;

char* getStuName(char name[], int num) {
	char number[5];
	itoa(num, number, 10);
	strcat(name, number);
	return name;
}

void main() {
	Student stuArr[10];
	for (int i = 0; i < 10; i++) {
		stuArr[i].stuNum = i;
		char name[20] = "name";
		stuArr[i].stuName = getStuName(name, i);
		printf("stuNum=%d,stuName=%s\n", stuArr[i].stuNum, stuArr[i].stuName);
	} 
}