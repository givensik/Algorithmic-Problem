#include <iostream>
#include <algorithm>

using namespace std;

int N;
int root = 0;

void printPost(const vector<int> pre, const vector<int> inord);
vector<int> slice(const vector<int> &vec, int a, int b);

int main(){
	vector<int> preorder, inorder;
	int C, tmp;
	cin >> C;
	cin >> N;
	for(int i = 0; i< C; i++){
		for(int j = 0; j < N; j++){
			cin >> tmp;
			preorder.push_back(tmp);
		}
		for(int j = 0; j < N; j++){
			cin >> tmp;
			inorder.push_back(tmp);
		}
	}
	// int root = preorder[0];
	// const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	// printf("L : %d\n",L);
	// printf("size : %zu\n", slice(preorder,1, L+1).size());

	printPost(preorder, inorder);
	
	cout << "\n";



	return 0;
}

// pre, inorder를 넣었을 때 후위 순회로 출력하는 함수
// 왼쪽, 오른쪽, 루트 순으로 출력함 -> 이런식으로 순서가 있는 경우 분할정복이면 좋다.
void printPost(const vector<int> pre, const vector<int> inord){
	const int N = pre.size();
	// printf("pre size : %d\n",N);
	// pre가 비어있으면 종료
	if(pre.empty()){
		return ;
	}
	int root = pre[0];
	// root랑 같은 값 위치 찾기
	const int L = find(inord.begin(), inord.end(), root) - inord.begin();
	// 왼쪽 먼저
	printPost(slice(pre, 1, L+1), slice(inord, 0, L));
	printPost(slice(pre, L+1, N),slice(inord, L+1, N));
	cout << root << " ";

}

vector<int> slice(const vector<int> &vec, int a, int b){
	return vector<int>(vec.begin()+a, vec.begin()+b);
}



/*
1
7
27 16 9 12 54 36 72
9 12 16 27 36 54 72

12 9 16 36 72 54 27
*/