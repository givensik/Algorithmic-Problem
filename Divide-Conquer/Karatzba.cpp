#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b);
void normalize(vector<int>& num);

int main(){
	vector<int> A,B;
	string s,t; 
	getline(cin, s);
	
	getline(cin, t);
	for(int i = s.size()-1; i >= 0 ; i--){
		A.push_back(s[i] - '0');
	}
	
	for(int i = t.size()-1; i >= 0; i--){
		B.push_back(t[i] - '0');
	}

	for(vector<int>::iterator itr = A.begin(); itr != A.end(); ++itr){
		cout << *itr;
	}
	cout << "\n";
	
	for(vector<int>::iterator itr = B.begin(); itr != B.end(); ++itr){
		cout << *itr;
	}
	cout << "\n";

	vector<int> C = multiply(A,B);

	for(vector<int>::iterator itr = C.end()-1; itr >= C.begin(); itr--){
		cout << *itr;
	}
	

	return 0;
}




vector<int> multiply(const vector<int>& a, const vector<int>& b){
	vector<int> c(a.size() + b.size() + 1, 0); // a,b 사이즈 + 1 만큼 0을 채우기

	for(int i=0; i < a.size(); i++){
		for(int j=0; j< b.size(); j++){
			c[i+j] += a[i] * b[j];
			printf("c[%d] = %d\n",i+j, c[i+j]);
		}
	}

	normalize(c);
	return c;
}

void normalize(vector<int>& num){// num이 넘어가서 바뀌어야하니까 레퍼런스로 넘기기
	num.push_back(0);

	for(int i = 0; i+1<num.size(); i++){
		if(num[i] >= 10){
			num[i+1] += num[i]/10;
			num[i] = num[i]%10;
		}
		printf("num[%d] = %d\n",i,num[i]);
	}


	while(num.size()>1 && num.back() == 0){
		num.pop_back();
	}
	
	
}


/*
				5 6 7 8
				1 2 3 4
				20  24  28  32
			15	18	21	24
		10	12	14	16	
	5	6	7	8
32 52 61 60 34 16 5 0
2  5  6  6  0  0  7


*/