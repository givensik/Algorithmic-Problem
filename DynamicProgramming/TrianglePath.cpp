#include <iostream>

using namespace std;

vector<vector<int>> a;

int path(int y, int x, int sum);

int cache[100][100];

int main(){
	int N;

	cin >> N;
	
	for(int i =0; i< N; i++){
		vector<int> v;
		for(int j = 0 ; j<= i ; j++){
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		a.push_back(v);
	}

	printf("%d\n", path(0,0,0));
	
	return 0;
}

int path(int y, int x){
	// 가장 아래의 경로인 경우
	if(y+1 == a.size()){
		return a[y][x];
	}

	int& ret = cache[y][x];
	
	if(ret != -1){
		return ret;
	}

	return ret = max(path(y+1,x),path(y+1,x+1)) + a[y][x];
	
}