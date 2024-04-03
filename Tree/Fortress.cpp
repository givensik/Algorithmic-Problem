#include <iostream>
#include <cmath>

using namespace std;

typedef struct circle{
	int x, y, r;
}circle;

typedef struct node{
	node* parent;
	circle c;
	vector<node*> child;
}node;

typedef struct Tree{
	node* root;
}Tree;

void insertNode(Tree* Tree, node *node);
int Cinclude(circle A, circle B);
void printTree(node* root);
int getHeight(node* root);
int solve(node* root);


int longest;


int main(){
	int C,N;
	Tree* tree = new struct Tree;
	node* n = new struct node;
	n->c.x = 0;
	n->c.y = 0;
	n->c.r = 1000;
	tree->root = n;
	cin >> C;
	for(int i = 0 ; i < C ; i++ ){
		longest = 0;
		cin >> N;	
		for(int j = 0 ; j < N; j++){
			node* tmp = new struct node;	
			cin >> tmp->c.x >>  tmp->c.y >> tmp->c.r;
			insertNode(tree, tmp);
		}
		printTree(tree->root);
		printf("%d\n",solve(tree->root)-1);
	}

}

// 0 : 안겹침, 1 : 	A가 B를 포함함, 2: B가 A를 포함함
int Cinclude(circle A, circle B){
	double d = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	// 둘이 포함 관계가 아님
	if(d > A.r + B.r){
		return 0;
	}else{ // 겹치는 경우는 없으므로 둘 중 반지름 큰게 포함하는거임 
		if(A.r > B.r){
			return 1;
		}else{
			return 2;
		}
	}

}

void insertNode(Tree* Tree, node *n){
	// printf("%d %d %d\n", n->c.x, n->c.y, n->c.r);
	node* pnode = Tree->root;
	// root노드의 자식이 없다면 n을 자식 노드로 넣기
	// if(pnode->child.empty()){
	// 	printf("root노드의 자식이 없다.\n");
	// 	pnode->child.push_back(n);
	// 	return ;
	// }
 
	int flag = 0;
	while(true){
		if(pnode->child.empty()){
			printf("root 노드의 자식이 없다.\n");
			pnode->child.push_back(n);
			return ;
		}
		for(int i = 0 ; i < pnode->child.size(); i++){
			printf("pnode child size() %zu\n", pnode->child.size());
			int result = Cinclude(pnode->child[i]->c, n->c);
			printf("%d번째 자식과 관계 : %d\n",i, result); 
			// pnode의 자식이 n을 포함한다면 그 자식을 기준으로 다시 해봐야함
			if( result == 1 ){
				pnode = pnode->child[i];
				flag = 1;
				break;
			}// n이 pnode의 자식을 포함한다면?
			else if(result == 2){
				n->parent = pnode;
				n->child.push_back(pnode->child[i]);
				pnode->child.erase(pnode->child.begin()+i); // pnode에서 자식 제거
			}else if(result == 0 && i+1 == pnode->child.size()){ // pnode의 자식으로 추가
				printf("아무것도 포함하지 않음\n");
				pnode->child.push_back(n);
				break;
			}
			// 다 아니면 해당 자식이랑 안겹치는거
		}
		// pnode의 자식을 기준으로 pnode가 바뀐 경우 -> flag = 1, 아니면 0 이니까 그때면 자리가 찾아진거니까 멈추기
		if(flag == 0){
			// printf("flag =1 \n");
			break;
		}else{
			// printf("flag = 0\n");
			flag = 0;
		}
	}
}

void printTree(node* root){
	
	for(int i = 0 ; i < root->child.size(); i++){
		printTree(root->child[i]);
		// printf("i : %d\n",i);
	}

	printf("%d %d %d\n", root->c.x, root->c.y, root->c.r);

}

// 서브트리의 root 노드에서 높이 구하기
int getHeight(node* root){

	if(root->child.empty()){
		return 0;
	}
	int max = 0, max2 = 0;
	for(int i = 0 ; i < root->child.size(); i++){
		int h = getHeight(root->child[i]);
		if(max < h){
			max = h;
		}
	}
	return max+1;
}


int solve(node* root){

	int h = getHeight(root);
	printf("(%d, %d, %d)일때 h = %d\n", root->c.x, root->c.y, root->c.r, h);
	return max(longest, h);
}
/*


2
3
5 5 15
5 5 10
5 5 5
8
21 15 20
15 15 10
13 12 5
12 12 3
19 19 2
30 24 5
32 10 7
32 9 4
*/