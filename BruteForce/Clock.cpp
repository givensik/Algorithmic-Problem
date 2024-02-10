#include <stdio.h>

int **Clock;

const int Button[10][5] = {
	{0, 1, 2, -1, -1}, 
	{3, 7, 9, 11, -1}, 
	{4, 10, 14, 15, -1}, 
	{0, 4, 5, 6, 7}, 
	{6, 7, 8, 10, 12}, 
	{0, 2, 14, 15, -1}, 
	{3, 14, 15, -1, -1},
	{4, 5, 7, 14, 15}, 
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

int res = 2000000;


int Min(int a, int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}

// 12시가 맞추어졌는지 확인하는 함수
bool isSync(int** Clock){
	for(int i =0; i<4; i++){
		for(int j = 0; j<4; j++){
			if(Clock[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

// ButtonNum에 해당하는 시계들 다 + 6 하고 12시면 0으로 바꾸기, N번 반복해서 누르기
void clickButton(int** Clock, int ButtonNum, int N){
	// 0번 반복이면 그냥 종료
	if(N == 0){
		return;
	}
	
	for(int i = 0; i < 5; i++){
		if(Button[ButtonNum][i] == -1){
			return;
		}
		int row = Button[ButtonNum][i] / 4 ;
		int col = Button[ButtonNum][i] % 4 ;

		Clock[row][col] = (Clock[row][col] + 1 * N) % 4;
	}
}

// reset은 +3을 하면 -1이랑 같은 효과임
void resetButton(int** Clock, int ButtonNum, int N){
	// 0번 반복이면 그냥 종료
	if(N == 0){
		return;
	}
	
	for(int i = 0; i < 5; i++){
		if(Button[ButtonNum][i] == -1){
			return;
		}
		int row = Button[ButtonNum][i] / 4 ;
		int col = Button[ButtonNum][i] % 4 ;

		Clock[row][col] = (Clock[row][col] + 3 * N) % 4;
	}
}


// 초기값 Clock, 0, 
void ClockSync(int **Clock, int ButtonNum, int cnt){
	if(ButtonNum == 10) return ;
	// 버튼을 0~3번 누르기
	for(int i = 0; i < 4 ; i++){
		// ButtonNum번의 버튼을 i번 누르기
		clickButton(Clock, ButtonNum, i);
		cnt += i;
		// 동기화가 되었다면?
		if(isSync(Clock)){
			printf("sync complete\n");
			res = Min(res, cnt);
			return ;
		}
		ClockSync(Clock, ButtonNum+1, cnt);			
		resetButton(Clock, ButtonNum, i);
		cnt -= i;
	}

}

/*
	0: 0, 1, 2
	1 :  3, 7, 9, 11
	2 : 4, 10, 14, 15
	3 : 0, 4, 5, 6, 7
	4 : 6, 7, 8, 10, 12
	5 : 0, 2, 14, 15
	6 : 3, 14, 15
	7 : 4, 5, 7, 14, 15
	8 : 1, 2, 3, 4, 5
	9 : 3, 4, 5, 9, 13


	input : 
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
*/




int main(){
	int tmp;

	int** Clock = new int*[4];

	for(int i =0; i<4; i++){
		Clock[i] = new int[4];
	}
	
	// 입력	
	for(int i=0; i<4 ; i++){
		for(int j =0; j<4; j++){
			scanf("%d",&tmp);
			Clock[i][j] = (tmp/3)%4 ; // 이래야 0,1,2,3 으로 나옴
		}
	}

	for(int i=0; i<4 ; i++){
		for(int j =0; j<4; j++){
			printf("%d ", Clock[i][j]);	
		}
		printf("\n");
	}

	ClockSync(Clock, 0, 0);
	printf("%d\n", res);
	


	return 0;
}
