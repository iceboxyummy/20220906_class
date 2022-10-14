#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "student.h"

// �������� ���� �Լ����� static Ű���带 �ٿ� �ܺ������� ���´�.
static void SetName(Student* const student)
{
	char name[100] = { 0 };

	printf("�л��̸� : ");
	scanf_s("%s", name, (unsigned int)sizeof(name));

	int const count = strlen(name) + sizeof(char);

	student->name = calloc(count, sizeof(char));

	if (student->name == NULL) return;
	strcpy_s(student->name, count, name);
}

static void SetScore(Student* const student, Subject const subject)
{
	printf("���� : ");
	scanf_s("%d", &student->score[subject]);
}
static void SetKorean(Student* const student)
{
	printf("���� ");
	SetScore(student,korean);
}
static void SetEnglish(Student* const student)
{
	printf("���� ");
	SetScore(student, english);
}
static void SetMath(Student* const student)
{
	printf("���� ");
	SetScore(student, math);
}
static void PrintScore(Student* const student)
{
	student->total = 0;

	for (int i = min; i <= max; i++)
		student->total += student->score[i];

	student->average = student->total / (float)count;
	
	printf("�л� �̸� : %s\n", student->name);
	printf("���� ���� : %u\n", student->score[korean]);
	printf("���� ���� : %u\n", student->score[english]);
	printf("���� ���� : %u\n", student->score[math]);
	printf("�ջ� ���� : %u\n", student->total);
	printf("��� ���� : %.2f\n", student->average);
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