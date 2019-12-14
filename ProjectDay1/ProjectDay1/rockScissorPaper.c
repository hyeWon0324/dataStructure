#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

/* C 언어 문법 확인 : 문제
가위, 바위, 보 게임: 가위(0), 바위(1), 보(2) 를 사용자가 선택하고
컴퓨터가 난수 생성 후에 비교하여 게임 성적, 승률을 구하여라
*/

int main() {

	int computer;
	int user;
	int result;
	int winCount , loseCount, totCount ;
	winCount = loseCount = totCount = 0; 
	srand((unsigned)time(NULL));//unsigned 를 붙여서 양수 8비트로도 충분히 표현 가능 

	//printf("%d\n", computer);

	printf("가위, 바위, 보 게임:\n");

	do {
		printf(" 가위(0), 바위(1), 보(2) , 종료(9)  --> 숫자를 입력하세요 \n");
		scanf("%d", &user);
		computer = rand() % 3;
		result = computer - user; 
		if (user ==0) {
			prinf(" 사용자 : 가위 \n");
		}
		else if (user == 1) {
			prinf("사용자 : 바위 \n");
		}
		else if (user == 2) {
			prinf("사용자 : 보 \n");
		}
		else if (user == 9) {
			prinf("사용자 : 종료 \n");
		}
		else {
			printf("제대로 입력하세요\n");
			continue;
		}

		if (computer == 0) {
			prinf("컴퓨터 : 가위 \n");
		}
		else if (computer == 1) {
			prinf("컴퓨터 : 바위 \n");
		}
		else if (computer == 2) {
			prinf("컴퓨터 : 보 \n");
		}
		
		totCount++;

		printf("결과 : ");
		if (result == 0) {
			printf("무승부\n");
		}
		else if (result == -1 || result == 2) {
			printf("user 이김\n");
			winCount++;
		}
		else {
			printf(" 컴퓨터 이김\n");
			loseCount++; 
		}

	} while ( user != 9);
	printf("%d전  %승  %패  승률: %.2f%% \n ", totCount, winCount, loseCount, (double)winCount / totCount * 100);
}