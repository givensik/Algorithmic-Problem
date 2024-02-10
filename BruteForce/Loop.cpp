// 중첩반복문 재귀함수로 대체하기
#include <vector>
#include <iostream>
#include <stdio.h>

void loop(int n){
	for(int i =0; i<n; i++){
		for(int j = i+1; j<n; j++){
			for(int k = j+1; k<n; k++){
				for(int l = k+1; l < n; l++){
					printf("i %d j %d k %d l %d\n", i,j,k,l ); 
				}
			}		
		}
	}
}

void RecurLoop(){

}


int main(){
	int n = 5;
	printf("그냥 중첩 반복문\n");
	loop(n);
	printf("재귀로 중첩 반복문 대체");
	std::vector<int> a;
	

	return 0;
}