#include <iostream>
#include <map>

using namespace std;
bool isIn(int x, int y);
void removeIn(int x, int y);

map<int, int> Nerd;

int main(){
	int C,N;
	int party = 0, total = 0;

	cin >> C;
	for(int i = 0; i< C; i++){
		total =0;
		cin >> N;
		for(int j = 0 ; j < N ; j++){
			int p, q;
			scanf("%d %d",&p, &q);
			// 포함되는 경우 -> 다음 애를 뽑기
			if(isIn(p,q)){
				continue;
			}
			Nerd[p]=q;
			removeIn(p,q);
			total += Nerd.size();
		}
		printf("total : %d\n", total);

	}

	return 0;
}

bool isIn(int x, int y){
	// x 이상인 키 중 가장 작은 값
	map<int,int>::iterator it = Nerd.lower_bound(x); 

	if(it == Nerd.end()){
		return false;
	}

	return y < it->second;
}
void removeIn(int x, int y){
	map<int,int>::iterator it = Nerd.lower_bound(x); 
	if(it == Nerd.begin()){
		return ;
	}	
	it--;
	while(true){
		if(it->second > y){
			break;
		}
		// 첫번째 원소면 그거만 지우고 끝
		if(it == Nerd.begin()){
			return ;
		}else{
			map<int,int>::iterator jt = it;
			jt--;
			Nerd.erase(it);
			it = jt;
		}
		
	}

}

/*


2
4
72 50
57 67
74 55
64 60
5
1 5
2 4
3 3
4 2
5 1


8
5
*/