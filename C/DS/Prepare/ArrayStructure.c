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
	int a[] = {1, 2};
	Student stuArr[10];
	for (int i = 0; i < 10; i++) {
		stuArr[i].stuNum = i;
		char* tmpStuNum = (char *)malloc(6);
		initCharSpace(tmpStuNum, 6);
		tmpStuNum = "name";
		*(tmpStuNum + 4) = i + '0';
		stuArr[i].stuName = tmpStuNum;
		printf("stuNum=%d,stuName=%s\n", stuArr[i].stuNum, stuArr[i].stuName);
	} 
}