#include <iostream>

using namespace std;

vector<vector<int>> a;

int path(int y, int x, int sum);

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

int path(int y, int x, int sum){

	// 범위를 넘어선 좌표
	if(y == a.size() || x == a[y].size()){
		return sum;
	}
	// 가장 아래의 경로인 경우
	if(y+1 == a.size()){
		return sum + a[y][x];
	}
	int p1 = path(y+1,x,sum + a[y][x]);
	int p2 = path(y+1,x+1,sum + a[y][x]);

	return (p1 > p2) ? p1 : p2;
}