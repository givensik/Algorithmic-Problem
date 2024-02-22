#include <iostream>
#include <string>

using namespace std;

string S, W;
int cache[101][101];

bool match(const string& w, const string& s);

bool match(int w, int s);

int main(){
	int C,N;
	cin >> C;
	for(int i=0; i < C; i++){
		cin >> W;
		cin >> N;
		
		for(int i=0; i<N;i++){
			cin >> S;
			if(match(W,S)){
				cout << S << "\n";
			}

			if(match(0,0)){

			}

		}
	}
}

bool match(int w, int s){
	
	// cache -> -1 : 계산하지 않음, 0 : 서로 대응 x, 1 : 서로 대응 됨
	int& ret = cache[w][s];
	
	if(ret != -1) return ret;

	while(s < S.size() && w < W.size() && (W[w]=='?' || W[w] == S[s])){
		++w;
		++s;
	}

	// 둘 다 같다면 true
	if(w == W.size()){
		return ret = (s == S.size());
	}

	// * 이라면 w의 다음 문자랑 같은 애가 있는지 확인해야함
	if(W[w]=='*'){
		for(int skip = 0; skip+s <= S.size(); ++skip){
			if(match(w, s+skip)){
				return ret = 1;
			}
		}
	}
	// 이외의 경우
	return ret = 0;


}

bool match(const string& w, const string& s){
	// cout << "match :" << w << s << "\n";
	int pos = 0;
	// w와 s의 크기가 pos랑 같으면 끝 + w와 s가 같거나 w가 ?인 경우 다음 문자를 조사
	while(w.size() > pos && s.size() > pos && (w[pos] == s[pos] || (w[pos] == '?'))){
		pos++;
	}
	// w와 s에 동시에 도착했다 -> true
	if(w.size()==pos && s.size()==pos){
		return true;
	}
	if(w[pos] == '*'){
		for(int i = pos; i<s.size(); i++){
			if(match(w.substr(pos+1), s.substr(i))){
				return true;
			}
		}
	}



	return false;
}