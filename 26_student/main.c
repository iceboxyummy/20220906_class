 // main.cpp

#include <stdio.h>
#include <stdlib.h>
#include "student/student.h"

int main()
{
	Student* student = Create();
	if (student != NULL)
	{
		student->SetName(student);
		student->SetKorean(student);
		student->SetEnglish(student);
		student->SetMath(student);
		student->PrintScore(student);

		student = Destory(student);
	}
	return 0;
}