# Algorithmic-Problem

디버깅할때 .vscode에 있는 launch.json, tasks.json 가져가서 돌리기

vscode 디렉토리는 cpp파일, 디버깅 세팅파일보다 상위 디렉토리에서 실행할 것


1. BruteForce
### 모든 순열 만들기 
-> N! : N이 10을 넘어가면 다른 방법으로 생각
C++ STL 라이브러리 : next_permutation() 함수가 있는데 이게 순열을 순서대로 생성해주는 작업을 대신 해줌

모든 조합 만들기 -> nCr : n 개의 원소 중에 r개를 고르는 알고리즘

2^n가지 경우의 수 만들기 -> 2^n : n 개의 질문에 대하여 예/아니오 중의 하나가 답일 때

2. Divide-Conquer
카라츠바의 큰 수 빠른 곱셈