#include <iostream>
#include <algorithm>

using namespace std;

void printPost(int s1, int e1, int s2, int e2);

vector<int> preorder, inorder;

int main(){
	
	int C, N, tmp;
	cin >> C;
	for(int i = 0; i< C; i++){
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> tmp;
			preorder.push_back(tmp);
		}
		for(int j = 0; j < N; j++){
			cin >> tmp;
			inorder.push_back(tmp);
		}
		printPost(0,N,0,N);
		cout << "\n";
		preorder.clear();
		inorder.clear();

	}


	return 0;
}

// s1 <= a < e1, s2 <= b < e2
void printPost(int s1, int e1, int s2, int e2){
	// printf("s1 : %d, e1 : %d, s2 : %d, e2 : %d\n",s1,e1,s2,e2);
	if(s1 == e1 and s2 == e2){
		return ;
	}

	const int root = preorder[s1];
	int L;
	for(int i = s2; i< e2; i++){
		// root랑 같으면 그 위치
		if(inorder[i] == root){
			L = i - s2;
			// printf("L = %d\n",L);
			break;
		}
	}

	printPost(s1+1, s1 + 1 + L, s2,  s2 + L );
	printPost(s1+L+1, e1, s2+L+1, e2);
	cout << root << " ";

}