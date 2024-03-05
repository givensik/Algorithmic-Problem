#include <iostream>

/*
	세로로 채울 때 : 1칸만 차지함, 카운트 +1
	가로로 채울 때 : 2칸을 차지함, 카운트 +2
*/

using namespace std;

int Tile(int start);
int Tile2(int width);

int N;
const int MOD = 1000000007;
int cache[100];
int cache2[101];
int main(){
	
	cin >> N;
	
	cout << Tile(0) << "\n";
	cout << Tile2(N) << "\n";
	// cache 확인
	// for(int i = 0 ; i< N; i++){
	// 	printf(" %d",cache[i]);
	// }
	// printf("\n");
	return 0;
}

/*
	ret
	1. start+1까지 셀때 카운트(1) + start+1부터 센 카운트
	2. start+2까지 셀때 카운트(2) + start+2부터 센 카운트

	start는 0부터 시작한다고 생각
*/
int Tile(int start){
	// printf("start : %d\n", start);
	int& ret = cache[start];
	if(ret != 0){
		// printf("ret = %d\n",ret);
		return ret;
	}

	// start == N이면 다 센거임
	if(start == N){
		// printf("ret = 1\n");
		return ret = 1;
	}else if(start > N){ // start가 N보다 크면 셀 수 없는 상태임
		// printf("ret = -1\n");
		return ret = 0;
	}

	int T1 = Tile(start+1);
	int T2 = Tile(start+2);
	ret += T1 + T2;
	
	// printf("ret = %d\n",ret);
	return ret;

}

int Tile2(int width){
	// printf("width = %d\n", width);
	if(width <= 1) return 1;

	int& ret = cache2[width];
	if(ret != 0){
		// printf("ret = %d\n",ret);
		return ret;
	}
	ret = (Tile2(width-2) + Tile2(width-1)) % MOD;
	// printf("ret = %d\n",ret);
	return ret;
}