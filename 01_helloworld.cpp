//01_helloworld.cpp

/* 
 �ּ�
  : ���α׷��Ӱ� �ڵ忡 �޸� �ϴ� ��, ������ �Ҷ� ��ó�� �ܰ迡�� �ּ��� �����ȴ�.
 */

// �����ּ� 
// �ȳ��ϼ���

/* ������ �ּ�
�������ṹ����
����ļ����ļļ */

/*
 ��� ---> ��ǻ�� : �Ұ���
 ��� ---> �뿪�� ---> ��ǻ��
         (Compiler)
  -��ǻ�ʹ� ���α׷��Ӱ� �ۼ��� �ڵ带 ������ �� ���� ������ ����� ��ȯ���־����.

  ���� 
  : ��ǻ�Ͱ� ���� �� �ִ� 2�� ����(0�� 1)�� �ۼ��� ��� , 0101011011

  ���α׷��� �ۼ��ϰ� �����ϴ� �ܰ�
  : �ڵ��ۼ� --> ������ --> ��ũ --> �ε�

*/
#include <stdio.h>
/* 
 #
 : pre-process �� ó��, �������� �����ϱ� ���� ���� ó���ϴ� ��ȣ

 include (�����ϴ�)
 : ������ ���� ~�� �����ϰ� �����϶�� ��

 stdio.h : ǥ�� ����� �Լ��� ������ �������
 - std : standard(ǥ��)
 - io : input / output (�Է� / ���)
 - .h : ������� Ȯ�����̸�

 ������� 
 : �Լ��� ��� �κи� ������ �ִ� ����

 
*/

/*
  �Լ�(function)
   : �ϳ��� ������ �۾��� �����ϵ��� ����� ���α׷� �ڵ��� ����
   
   main �Լ� : ���α׷��� ������ 
    - main�� ����Ǹ� ���α׷��� ����ȴ�. �ü���� ���� ��ó�� ȣ��ǰ� �ǳ��߿� ����ȴ�.

	��ȯ�� �Լ��̸� (�޴°�) <= �Լ��� ���
	{ <= �Լ��� ����

	�Լ��� ���

	} <=�Լ��� ��

	�޴°� : �Լ��� ȣ��� �� �޴°�
	  {}   : �Լ��� ���۰� ���� ��Ÿ���� ��ü�κ����� �Լ��� ������ ������ �ۼ��Ѵ�.
	��ȯ�� : �Լ��� ����ɱ� ��ȯ�ϴ� ��

	int main (void)
	{
	}
	: main�Լ��� ȣ���� �� void(�ƹ��͵� ��������)���� ������ �Լ��� ����ɋ� int(������) ���� ��ȯ�Ѵ�.
*/

// main �Լ�

int main(void)
{
	printf("hello world!!!!\n");
	// ���ڿ�
	// "����" : " "�ȿ� �ִ� ������ �������� ǥ���� �� ����Ѵ�.
	printf("hello world!!\n\n\n\n\n");
	// f : formatted(����ȭ��) �پ��� ���Ŀ� ���� ������ش�.
	/*
	Escape Sequence
	: \ �ڿ� �� ���ڳ� ���� �������� �ٹٲ�, Ư�� ���ڸ� ǥ���ҋ� ��� ex) \n, \t, \" ...
	*/
	printf("\thello world\n");
	printf("10\n");
	printf("%d\n", 10);
	printf("�÷��̾��� ü�� : %d\n", 10);
	printf("%d %d %d %d %d\n", 10, 20, 30, 40, 50); //���û�� ����
	printf("%f\n", 0.5);

	int a = 10;
	a += 10;
	printf("%d\n", a);

	/*
	%d ���� ��
	format specifier  vs  conversion specifier => �Ѵ� ������
	 ����    ������           ��ȯ      ������
	*/

	return 0; // 0�� ��ȯ�ϰ� main �Լ��� �����Ѵ�.
	//return�� ��ȯ�� ������ �ǹ̸� ����
}