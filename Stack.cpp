#include <stdio.h>

/*˳���ʵ��ջ*/

typedef int ElemType;
typedef struct {
	ElemType data[50];
	int top;
}Sqstack;

void InitStack(Sqstack& s) {		//��ʼ��ջ
	s.top = -1;
}

bool IsEmpty(Sqstack s) {           //�п�
	if (s.top == -1)
		return true;
	else
		return false;
}

bool Push_Stack(Sqstack &s,ElemType e) {        //ѹջ
	if (s.top < 50) {
		s.data[++s.top] = e;
		return true;
	}
	else
		return false;
}

bool Pop_Stack(Sqstack &s) {			 //��ջ
	if (IsEmpty(s))
		return false;
	else {
		--s.top;
		return true;
	}
}

bool GetTop(Sqstack s) {				//��ȡջ��Ԫ��
	if (IsEmpty(s))
		return false;
	else {
		ElemType a = s.data[s.top];
		printf("ջ��Ԫ����%d\n", a);
		return true;
	}
}

void PrtStack(Sqstack s) {            //��ջ�׵�ջ����ӡջ
	for (int j = 0; j <= s.top; j++) {
		printf("��%d��Ԫ����%d\n", j + 1, s.data[j]);
	}
		
}

//int main() {
//	Sqstack s;
//	InitStack(s);
//	if(IsEmpty(s))
//		printf("�Ǹ���ջ\n");
//	Push_Stack(s,2);
//	if (IsEmpty(s))
//		printf("�Ǹ���ջ\n");
//	Push_Stack(s, 3);       //ѹջ
//	Push_Stack(s, 4);
//	Push_Stack(s, 5);
//
//	PrtStack(s);
//	GetTop(s);
//	Pop_Stack(s);
//	Pop_Stack(s);
//	Pop_Stack(s);
//	PrtStack(s);
//	Pop_Stack(s);
//	//PrtStack(s);
//}