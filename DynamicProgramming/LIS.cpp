#include <iostream>

using namespace std;

vector<int> S;

int N;
int cache[100];

int lis(const vector<int>& S);

int lis(int x); // -> 이거로 메모이제이션 적용

int main(){
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int tmp;
		cin >> tmp;
		S.push_back(tmp);
	}
	int l = lis(S);
	printf("%d\n", l);
	return 0;
}

int lis(const vector<int>& S){
	if(S.empty()){
		return 0;
	}

	int ret = 0;
	for(int i = 0; i < S.size(); i++){
		// printf("i : %d\n",i);
		vector<int> B;
		for(int j = i+1; j < S.size(); j++){
			// printf("j : %d\n",j);
			// i번쨰 원소보다 큰 애들만 B 벡터에 넣는다.
			if(S[i] <= S[j]){
				// printf("S[%d] <= S[%d]\n", i, j);
				B.push_back(S[j]);
			}
		} 
		ret = max(ret, 1 + lis(B));	
	}
	
	return ret;
}

int lis(int x){
	
	int& ret = cache[x];

	if(ret != -1){
		return ret;	
	}

	int cnt = 0;
	ret = 1;
	for(int i = x+1; i< S.size(); i++){
		if(S[x] < S[i]){
			ret = max(ret, lis(i)+1);
		}
	}
	return ret;
}