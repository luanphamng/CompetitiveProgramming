#include <iostream>
using namespace std;

int N;				//	# of stairs
int P[310];		//	P[i]: score earned when stepping on stair i
bool selected[310];
int maxValue;

int calculate() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (selected[i]) result += P[i];
	}
	return result;
}

void gen(int step) {
    cout << "Gen(" << step << ")" << endl;
	if (step == N) {
		if (selected[N-1]) {
			int value = calculate();
			if (value > maxValue)
				maxValue = value;
		}
		return;
	}
	
	if (step > 1 && selected[step-1] && selected[step-2]) {
		selected[step] = false;
		gen(step + 1);
	} else if (step > 0 && !selected[step-1]) {
		selected[step] = true;
		gen(step + 1);
	} else {
		for (int i = 0; i < 2; ++i) {
			selected[step] = i == 1;
			gen(step + 1);
		}
	}
}

int Solve(){
	gen(0);
	return maxValue;
}

void InputData(){
    freopen("ResearchHealthyProject.inp", "r", stdin);
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> P[i];
	}
}

int main(){
	
	InputData();					//	Input function

	int sol = Solve();

	cout << sol << endl;		//	Answer output
	return 0;
}
