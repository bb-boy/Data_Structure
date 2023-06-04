#include <stdio.h>

/*顺序表实现栈*/

typedef int ElemType;
typedef struct {
	ElemType data[50];
	int top;
}Sqstack;

void InitStack(Sqstack& s) {		//初始化栈
	s.top = -1;
}

bool IsEmpty(Sqstack s) {           //判空
	if (s.top == -1)
		return true;
	else
		return false;
}

bool Push_Stack(Sqstack &s,ElemType e) {        //压栈
	if (s.top < 50) {
		s.data[++s.top] = e;
		return true;
	}
	else
		return false;
}

bool Pop_Stack(Sqstack &s) {			 //出栈
	if (IsEmpty(s))
		return false;
	else {
		--s.top;
		return true;
	}
}

bool GetTop(Sqstack s) {				//获取栈顶元素
	if (IsEmpty(s))
		return false;
	else {
		ElemType a = s.data[s.top];
		printf("栈顶元素是%d\n", a);
		return true;
	}
}

void PrtStack(Sqstack s) {            //从栈底到栈顶打印栈
	for (int j = 0; j <= s.top; j++) {
		printf("第%d个元素是%d\n", j + 1, s.data[j]);
	}
		
}

//int main() {
//	Sqstack s;
//	InitStack(s);
//	if(IsEmpty(s))
//		printf("是个空栈\n");
//	Push_Stack(s,2);
//	if (IsEmpty(s))
//		printf("是个空栈\n");
//	Push_Stack(s, 3);       //压栈
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