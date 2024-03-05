#include <iostream>

using namespace std;

int Tile2(int width);
int Asymtiling();

int cache[101];
int N;
const int MOD = 1000000007;

int main(){
	
	cin >> N;

	printf("%d\n", Asymtiling());

	return 0;
}

int Asymtiling(){
	int ret = 0;
	// 홀수일 때
	if(N%2 == 1){
		ret = Tile2(N) - Tile2(N/2);	
	}else{
		ret = (ret - Tile2(N/2) + MOD) % MOD;
		ret = (ret - Tile2(N/2-1) + MOD) % MOD;
	}
	
	return ret;
}

int Tile2(int width){
	// printf("width = %d\n", width);
	if(width <= 1) return 1;

	int& ret = cache[width];
	if(ret != 0){
		// printf("ret = %d\n",ret);
		return ret;
	}
	ret = (Tile2(width-2) + Tile2(width-1)) % MOD;
	// printf("ret = %d\n",ret);
	return ret;
}