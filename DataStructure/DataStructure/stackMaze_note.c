#include <stdio.h>
#include <windows.h>

/****************************
* hero : 별이 이동되는 위치를 저장할 구조체
****************************/
typedef struct hero {
	short x;
	short y;
}HERO, * PHERO;



/****************************
* node : Stack 구조체(x,y좌표를 저장할 HERO 구조체 공간과
	 이전 stack의 주소를 저장할 link공간 한개)
****************************/
typedef struct stack
{
	HERO data;
	struct stack* link;
}Stack, * PStack;



/****************************
* GetNode : Heap 영역에 Stack 구조체 만들어서
		시작 주소값 return 해주는 함수
****************************/
Stack* GetNode()
{
	Stack* tmp;				/* Stack 구조체 주소를 저장할 Stack 포인터 변수 tmp 생성 */
	tmp = (Stack*)malloc(sizeof(Stack));	/* heap영역에 동적할당으로 Stack 구조체만큼 공간할당해서 시작주소 tmp에 저장 */
	tmp->link = NULL;			/* Stack 구조체의 link 공간을 NULL로 초기화 */
	return tmp;				/* Stack 구조체의 시작주소를 리턴 */
}



/****************************
* Push : Stack의 top 포인트 주소와 데이터(x,y좌표값)를 입력받아서
		Stack에 쌓아주는 함수
****************************/

void Push(Stack** top, HERO data)	/*main의 top변수 주소값, main의 hr구조체변수값 저장 */
{
	Stack* tmp;			/* Stack 구조체 주소를 저장할 Stack 포인터 변수 tmp 생성 */
	tmp = *top;			/* 매개변수로 받아온 top포인터가 가르키는 공간안에 있는 값을 tmp에 저장 */

	*top = GetNode();		/* GetNode함수로 Stack 구조체를 생성한 후 시작 주소값을 top포인터 변수에 저장 */
	(*top)->data.x = data.x;	/* top포인터변수가 가르키는 Heap영역의 data.x공간에 매개변수로 받아온 data.x(x좌표)를 저장 */
	(*top)->data.y = data.y;	/* top포인터변수가 가르키는 Heap영역의 data.y공간에 매개변수로 받아온 data.y(y좌표)를 저장 */
	(*top)->link = tmp;		/* top포인터변수가 가르키는 Heap영역의 link공간에 tmp에 저장해둔 주소값을 저장(이전 Stack의 시작주소) */
}


/****************************
* Pop : Stack의 top 포인트 주소를 입력받아서 Stack의 가장 위에
	저장된 data를 data 구조체변수에 저장 후 반환하는 함수
****************************/

HERO Pop(Stack** top)		/*main의 top변수 주소값 저장 */
{
	Stack* tmp;		/* Stack 구조체 주소를 저장할 Stack 포인터 변수 tmp 생성 */
	HERO data;		/* Data를 임시저장할 HERO 구조체 변수 선언 */
	if (*top == NULL)	/*main의 top변수값이 NULL인지 비교(NULL이면 Data없음)*/
	{
		data.x = -1;	/* Data가 없으면 data.x에 -1값 입력*/
		return data;	/* data 구조체 반환 */
	}			/* 매개변수로 입력받은 top포인터가 가르키는 공간의 값이 NULL이면 매개변수로
				   입력받은 data구조체의 x 공간에 -1 저장(좌표로 사용하지 않는 값) 후
				   data 구조체 반환하면서 Pop 함수 종료 */
	tmp = *top;		/* main의 top변수안에 있는 주소값 tmp변수에 저장 */
	data.x = tmp->data.x;	/* data.x(x좌표)에 tmp 포인터변수가 가르키는 Heap영역의 data.x 값을 저장 */
	data.y = tmp->data.y;	/* data.y(y좌표)에 tmp 포인터변수가 가르키는 Heap영역의 data.y 값을 저장 */
	*top = tmp->link;	/* tmp포인터가 가르키는 link공간의 주소값을 top포인터 변수에 저장 */
	free(tmp);		/* data를 모두 받아온 Heap 영역의 Stack구조체 하나 할당 해제 */
	return data;		/* data 구조체 반환 */
}



/****************************
* gotoxy : x,y좌표값을 매개변수로 입력받아
			콘솔의 커서를 이동시켜 주는 함수
****************************/

void gotoxy(int x, int y) {
	COORD Cur = { x,y };	/* x,y 좌표값을 저장하는 구조체(windows.h header파일에 포함) */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	/* 콘솔의 handle 값과 x,y좌표를 받아와서 커서를 이동해 주는 함수 */
}


/*****************************
* print_MAP : MAP 2차원배열과 별의 x,y좌표값을 입력받아
		  MAP을 그려주는 함수
******************************/

void print_MAP(int MAP[10][10], HERO hr) {
	int i, j;					/* 2차원배열의 index 변수 */
	gotoxy(0, 0);					/*콘솔창의 가장 처음부분으로 커서 이동 */
	for (i = 0; i < 10; i++) {				/* 2차원 배열 첨자 */
		for (j = 0; j < 10; j++) {			/* 1차원 배열 첨자 */
			if (MAP[i][j] == 0) {		/* 벽 출력 */
				printf("■");
			}
			else if (MAP[i][j] == 1) {	/* 길 출력 */
				printf("□");
			}
			else if (MAP[i][j] == 2) {	/* 한번 지나온 길 출력 */
				printf("＊");
			}
		}
		printf("\n");				/* 하나의 1차원 배열 출력 후 줄 개행 */
	}
	gotoxy(hr.x, hr.y);				/* 별의 현재 좌표로 커서 이동 */
	printf("☆");					/* 별 출력 */
}


/*****************************
* main 함수
******************************/

int main() {
	HERO hr;			/* 별의 이동 좌표를 저장할 구조체 변수 */
	PStack top = 0;			/* Heap영역에 만들어지는 Stack Node의 주소를 저장할 포인터 변수*/
	HERO data;			/* 출력할 좌표를 저장할 구조체 변수 */

	int MAP[10][10] = {		/* MAP을 표현할 2차원배열 선언 및 초기화 */
		{0,1,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,1,1,1,0,0},
		{0,0,1,0,1,1,0,1,0,0},
		{0,0,1,1,1,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	hr.x = 2;			/* 별이 처음 나타날 x좌표 지정 */
	hr.y = 0;			/* 별이 처음 나타날 y좌표 지정 */
	print_MAP(MAP, hr);		/* MAP을 화면에 출력 */

								/* 별을 자동으로 이동 시켜줄 반복문 시작 */
	while (1) {						/* 화면에 출력될 특수문자가 2byte기때문에  */
		Push(&top, hr);				/* Stack에 Data 저장 */
		if (MAP[hr.y][(hr.x / 2) - 1] == 1) {			/* 현재 별이있는 위치에서 왼쪽의 배열값이 1인지 비교 */
			MAP[hr.y][(hr.x / 2)] = 2;		/* 현재 별이 있는 위치의 배열값을 2로 변경 */
			hr.x -= 2;				/* 별의 위치를 왼쪽으로 한칸 이동(특수문자가 2byte이기때문에 -2) */
		}
		else if (MAP[hr.y][(hr.x / 2) + 1] == 1) {		/* 현재 별이있는 위치에서 오른쪽의 배열값이 1인지 비교 */
			MAP[hr.y][(hr.x / 2)] = 2;		/* 현재 별이 있는 위치의 배열값을 2로 변경 */
			hr.x += 2;				/* 별의 위치를 오른쪽으로 한칸 이동(특수문자가 2byte이기때문에 +2) */
		}
		else if (MAP[hr.y + 1][(hr.x / 2)] == 1) {		/* 현재 별이있는 위치에서 아래쪽의 배열값이 1인지 비교 */
			MAP[hr.y][(hr.x / 2)] = 2;		/* 현재 별이 있는 위치의 배열값을 2로 변경 */
			hr.y += 1;				/* 별의 위치를 아래쪽으로 한칸 이동 */
		}
		else if (MAP[hr.y - 1][(hr.x / 2)] == 1) {		/* 현재 별이있는 위치에서 위쪽의 배열값이 1인지 비교 */
			MAP[hr.y][(hr.x / 2)] = 2;		/* 현재 별이 있는 위치의 배열값을 2로 변경 */
			hr.y -= 1;				/* 별의 위치를 위쪽으로 한칸 이동 */
		}
		else						/* 이동이 모두 끝나면 반복문 종료 */
			break;

		print_MAP(MAP, hr);				/* MAP 다시 출력 */
		Sleep(100); 					/* MAP 출력 후 잠시 멈춰 줌 */
	}



	/****************
	* Stack 출력
	*****************/

	hr.x = 25;						/* 출력할 위치 x 좌표 지정 */
	hr.y = 0;						/* 출력할 위치 y 좌표 지정 */
								/* Stack이 비워질 때 까지 Data를 하나씩 꺼내올 반복문 시작 */
	while (1)
	{
		data = Pop(&top);				/* Stack에 저장된 좌표 하나씩 꺼내 오기 */
		gotoxy(hr.x, hr.y);				/* 좌표를 출력할 위치로 이동 */
		if (data.x == -1)				/* Stack이 비어있는지 검사 */
		{
			printf("Stack is EMPTY\n");
			break;					/* Stack이 비어있으면 반복문 종료 */
		}
		printf("%2d . %2d\n", data.x, data.y);		/* x.y 좌표출력 */
		hr.y++;						/* 출력할 위치 y 좌표 1씩 증가 */
		Sleep(300);					/* 좌표 출력 후 잠시 멈춰 줌 */
	}

	system("pause");					/* 프로그램 종료 전 일시 정지(실행파일로 실행할때) */
	return 0;
}


