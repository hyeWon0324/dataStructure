#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

/* C 언어 문법 확인 : 문제
가위, 바위, 보 게임: 가위(0), 바위(1), 보(2) 를 사용자가 선택하고
컴퓨터가 난수 생성 후에 비교하여 게임 성적, 승률을 구하여라
*/

int fight(int c, int u) {
	if (u == c) {
		return 0;
	}
	else if ((u + 1) % 3 == c) {
		return -1;
	}
	else {
		return 1;
	}
}


int main() {
	int computer;
	int user;
	int result;
	int winning = 0;
	int opportunity = 0;
	char* name[3] = { "가위", "바위", "보" }; // 가위바위보의 손의 문자열 표현
	srand((unsigned)time(NULL));//unsigned 를 붙여서 양수 8비트로도 충분히 표현 가능 
	computer = rand() % 3;
	//printf("%d\n", computer);

	printf("가위, 바위, 보 게임:\n");
	do {
		printf(" 가위(0), 바위(1), 보(2) , 종료(-1)  --> 숫자를 입력하세요 \n");

		scanf("%d", &user);

		if (user == -1) {
			return;
		}
		printf("컴퓨터: %s \n ", name[computer]);
		printf("사용자: %s \n ", name[user]);
		opportunity++;
		result = fight(computer, user);

		printf("결과 : ");
		if (result == 0) {
			printf("무승부\n");
		}
		else if (result == 1) {
			printf("이김\n");
			winning++;
		}
		else {
			printf("짐\n");
		}
		printf("승률 %d / %d: \n ", winning, opportunity);

	} while (1);

}

