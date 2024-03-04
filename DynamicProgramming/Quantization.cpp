#include <iostream>
#include <algorithm>

using namespace std;

int quantize(int start, int cnt);
int minq(int start, int end);

int N, n, s;
vector<int> A;

int cache[100][10];

int main(){
	
	cin >> N;
	
	for(int i = 0 ; i< N; i++){
		cin >> n >> s;
		for(int j = 0; j < n; j++){
			int tmp;
			cin >> tmp;
			A.push_back(tmp);
		}
		// 정렬하기
		sort(A.begin(), A.end());
		for(int j = 0; j < n; j++){
			printf(" %d",A[j]);
		}
		printf("\n");
		cout << quantize(0,s) << "\n";
		A.clear();
		memset(cache, 0, sizeof(cache));
	}

	return 0;
}

/*	
	sorting -> 

*/

// start ~ 최소 값 구하기
int quantize(int start, int cnt){
	// printf("quantize() -> start : %d, cnt : %d\n", start , cnt);
	int& ret = cache[start][cnt];

	// ret값이 1000000이면 안해본거임
	if(ret != 0){
		return ret;
	}
	ret = 1000000;
	// start+1 ~ n - cnt까지	
	for(int i = start + 1 ; i <= n - cnt; i++ ){
		// start ~ start + i 까지의 최솟값 + 나머지 계산 값의 최소를 구하기
		
		// cnt == 1이면 minq 한 번 계산하면 끝남 -> start ~ n-1 으로 계산
		if(cnt == 1){
			ret = min(ret , minq(start, n-1));
			break;
		}

		ret = min(ret , minq(start, i)+ quantize(i+1, cnt -1));
	}


	return ret;
}

// start ~ end
int minq(int start, int end){
	// printf("%d부터 %d까지 최소 오차 제곱 구하기\n",start, end);
	int ret = 1000*1000;
	// 오차값 기준 : i
	for(int i = A[start]; i<= A[end]; i++){
		int sum = 0;
		for(int j = start; j <= end; j++){
			sum += (A[j]-i)*(A[j]-i);
		}
		// printf("sum = %d\n",sum);
		ret = min(ret, sum);
		// printf("ret = %d\n",ret);
	}
	// printf("최종 ret = %d\n",ret);
	return ret;
}