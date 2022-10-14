#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "student.h"

// 공개하지 않을 함수들은 static 키워드를 붙여 외부접근을 막는다.
static void SetName(Student* const student)
{
	char name[100] = { 0 };

	printf("학생이름 : ");
	scanf_s("%s", name, (unsigned int)sizeof(name));

	int const count = strlen(name) + sizeof(char);

	student->name = calloc(count, sizeof(char));

	if (student->name == NULL) return;
	strcpy_s(student->name, count, name);
}

static void SetScore(Student* const student, Subject const subject)
{
	printf("점수 : ");
	scanf_s("%d", &student->score[subject]);
}
static void SetKorean(Student* const student)
{
	printf("국어 ");
	SetScore(student,korean);
}
static void SetEnglish(Student* const student)
{
	printf("영어 ");
	SetScore(student, english);
}
static void SetMath(Student* const student)
{
	printf("수학 ");
	SetScore(student, math);
}
static void PrintScore(Student* const student)
{
	student->total = 0;

	for (int i = min; i <= max; i++)
		student->total += student->score[i];

	student->average = student->total / (float)count;
	
	printf("학생 이름 : %s\n", student->name);
	printf("국어 점수 : %u\n", student->score[korean]);
	printf("영어 점수 : %u\n", student->score[english]);
	printf("수학 점수 : %u\n", student->score[math]);
	printf("합산 점수 : %u\n", student->total);
	printf("평균 점수 : %.2f\n", student->average);
}

Student* Create() 
{
	Student* const student = calloc(1, sizeof(Student));

	if (student == NULL)	return NULL;

	student->SetName = SetName;
	student->SetKorean = SetKorean;
	student->SetEnglish = SetEnglish;
	student->SetMath = SetMath;
	student->PrintScore = PrintScore;

	return student;
}

void* Destory(Student const* const student) 
{
	free(student->name);
	free(student);

	return NULL;
}