#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int N;				//	# of stairs
int P[310];		//	P[i]: score earned when stepping on stair i
int check[310];

int sumIndex[4][4] = {
                {0, 1, 3}, 
                {0, 2, 3}, 
                {1, 3}, 
                {0, 2}
                };

int Solve(){

	int sol=0;
	memset(check, 0, sizeof check);
    cout << "After memset" << endl;
    sol += P[N-1];
    for (int i = N-2; i >= 4; i-=4) {
        
    }
	return sol;
}

void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> P[i];
	}
}

int main(){
    cout << "Start program:" << endl;
    freopen("input.inp", "r", stdin);
	InputData();					//	Input function
    cout << "N = " << N << endl;
	int sol = Solve();
	cout << sol << endl;		//	Answer output
	return 0;
}
