#pragma once
// student.h

typedef enum
{
	min,		//0
	korean=min,	//0
	english,	//1
	math,		//2
	max=math,	//2
	count		//3

}Subject;

typedef struct STUDENT
{
	char* name;
	int score[count];
	int total;
	float average;

	void(*SetName)(struct STUDENT*);
	void(*SetKorean)(struct STUDENT*);
	void(*SetEnglish)(struct STUDENT*);
	void(*SetMath)(struct STUDENT*);
	void(*PrintScore)(struct STUDENT*);
}Student;

Student* Create();
void* Destory(Student const* const student);