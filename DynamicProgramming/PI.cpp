#include <iostream>

using namespace std;

#define INF 100000;
string s;
int cache[10000];
// 완전 탐색으로 풀어보기
int piCount(int N);
int diff(int a, int b);
int main(){
	int C;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> s;
		cout << piCount(0) << "\n";
		memset(cache, 0, 10000);

	}
	

	return 0;
}
// a ~ b-1
int diff(int a, int b){
	printf("%d ~ %d\n",a,b-1);
	//1. 모두 숫자가 같은가?
	bool same = true;
	for(int i = a ; i< b-1; i++){
		if(s[i] != s[i+1]){
			same = false;
			break;
		}
	}
	if(same){
		printf("난이도 1\n");
		return 1;
	}
	// 2. 숫자가 1씩 단조 증가 or 단조 감소할때 + 등차수열일 때
	bool second = true;
	int flag = s[a+1] - s[a];
	// flag가 1또는 -1인 경우
	if(flag != 0){
		for(int i = a; i< b-1; i++){
			// 계속 flag랑 같은 값이 차이라면?
			if(s[i+1]-s[i] != flag){
				second = false;
				break;
			}
		}	
	}else{
		second = false;
	}
	if(second){
		if(flag == 1 || flag == -1){
			printf("난이도 2\n");
			return 2;
		}else{
			printf("난이도 5\n");
			return 5;
		}
	}

	// 3. 두 개의 숫자가 번갈아 나타날 때
	bool third = true;
	for(int i=a; i<b-2; i++){
		if(s[i] != s[i+2]){
			third = false;
			break;
		}
	}
	if(third){
		printf("난이도 4\n");
		return 4;
	}
	printf("난이도 10\n");
	return 10;
}

int min3(int x, int y, int z){
	if( x <= y && x <= z){
		return x;
	}else if(y <= x && y <= z){
		return y;
	}else if(z <= x && z <= y){
		return z;
	}

	return x;
}

// -1 : 불가능한 경우, 0 : 모름, 1 이상 : ret
int piCount(int pos){
	int& ret = cache[pos];
	printf("POS : %d, cache[%d] = %d\n", pos, pos, ret);

	// 0이 아니면 캐시에 저장되어있는거임
	if(ret != 0){
		printf("cache[%d] = %d\n", pos,ret);
		return ret;
	}
	if(s.size() == pos){
		printf("size == pos\n");
		return ret = 0;
	}
	if(s.size() < pos + 3){ // 남은 사이즈가 3보다 작은 경우 
		printf("size < pos +3 ret = -1\n");
		printf("cache[%d] = -1\n", pos);
		return ret = -1;
	}

	// 끝나지 않은 경우
	ret = INF;
	for(int end = 3; end<=5; end++){
		// 난이도 계산 (pos ~ pos+end-1) + (pos+end ~ )
		int tmp = piCount(pos+end);
		if(tmp != -1){
			ret = min(ret, diff(pos, pos+end) + tmp);
		}

	}
	// ret값이 그대로라면 if문에 못들어간거니까 -1
	if(ret == 100000){
		printf("cache[%d] = -1\n", pos);
		return ret = -1;	
	}
	printf("cache[%d] = %d\n", pos, ret);
	return ret;
}
/*
	3~5개 끊었을때 난이도 + 그 전까지의 난이도

*/