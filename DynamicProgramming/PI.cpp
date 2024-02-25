#include <iostream>

using namespace std;

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
	}
	

	return 0;
}

int diff(int a, int b){
	printf("%d %d\n",a,b);
	//1. 모두 숫자가 같은가?
	bool same = true;
	for(int i = a ; i< b; i++){
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
		for(int i = a; i<b; i++){
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
	for(int i=a; i<b-1; i++){
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


int piCount(int pos){
	printf("POS : %d\n", pos);
	int& ret = cache[pos];
	
	if(ret == -1){
		printf("ret = -1\n");
		return ret;
	}

	// pos+1이랑 s의 크기랑 같으면 정확하게 끝난거임
	if(s.size() == pos){
		printf("size = pos ret = 0\n");
		return ret = 0;
	}else if(s.size() < pos + 3){ // 남은 사이즈가 3보다 작은 경우
		printf("size < pos +3 ret = -1\n");
		return ret = -1;
	}

	// 끝나지 않은 경우
	ret = 11;
	for(int i = 0; i<3; i++){
		if(pos+2+i == s.size()){
			break;
		}
		// 나머지 값이 -1 일때
		int tmp = piCount(pos+3+i);
		if(tmp == -1){
			continue;
		}
		int m1 = diff(pos, pos+2+i) + tmp;
		
		if(ret > m1){
			printf("ret > m1:%d\n",m1);
			ret = m1;
		}
	}
	if(ret == 11){
		return ret = -1;
	}
	return ret;
}