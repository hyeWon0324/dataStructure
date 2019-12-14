#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

void swichGrade() {
	int grade;
	char result[2];
	printf("점수 입력: ");
	scanf("%d", &grade);
	switch (grade / 10) {
	case 10:
	case 9:
		strcpy(result, "A+");
		break;

	case 8:
	case 7:
		strcpy(result, "B");
		break;
	case 6:
	case 5:

		strcpy(result, "C");
		break;
	case 4:
	case 3:
		strcpy(result, "D");
		break;
	default:
		strcpy(result, "F");
		break;
	}

	printf("%s", result);

}
/*날짜를 입력 후 해당 날짜의 요일을 출력하시오 . 현재 달을 기준으로
*/

void swichMonth_Day() {
	//2019.12.14  Sat 
	int date;
	char day[10];
	printf("날짜 입력: ");
	scanf("%d", &date);

	switch (date %7) {
	case 1:
		strcpy(day, "일요일");
		break;
	case 2:
		strcpy(day, "월요일");
		break;
	case 3:
		strcpy(day, "화요일");
		break;
	case 4:
		strcpy(day, "수요일");
		break;
	case 5:
		strcpy(day, "목요일");
		break;
	case 6:
		strcpy(day, "금요일");
		break;
	case 0:
		strcpy(day, "토요일");
		break;
	default:
		strcpy(day, "  ");
		break;
	}

	printf("%s", day);
}
void DanglingEx() {
	//dangling else
   //else  는 가장 가까운 if 와 붙게된다 
   //블록을 확실하게 쓴다 
	int a = 2, b = 3;
	if (a < 2)
		if (a < 1) b = 5;
		else
			b = 6;//6이 출력이 안된다. 의도와 다르게 . 중첩되어 있는 조건문으로 인해서

}
/* 년도를 입력받아 윤년여부를 출력하시오 
  ifSwitch 중 어는 것 사용해도 됨. 4년마다 윤년, 100년 마다 평년 , 400년 마다 윤년 
*/
void  isLeapYr() {
	int year;

	printf("년도를 입력하시오 : ");
	scanf("%d", &year);
	if((year %4 == 0 && year %100 != 0 ) || (year % 400  == 0 ))
		printf("%d년은 윤년입니다.\n", year);

	else
		printf("%d년은 윤년이 아닙니다.\n", year);

}

int main() {

	//swichMonth_Day();

	isLeapYr();0
}
