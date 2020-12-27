#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

struct Object {		// structura pentru a reprezenta capetele
	int start;		// intervalelor
	int end;

	Object(int _start, int _end) : start(_start), end(_end) {}
};

class Task {
 public:
	void solve() {
		read_input();
        compute_solution();
		print_output();
	}

 private:
	int N, M;
	vector<Object> probl;		// vector de structuri in care retin
								// informatiile pentru fiecare elev
	void read_input() {
		ifstream fin("bomboane.in");
		fin >> N >> M;			// N - numarul de elevi, M - nr de bomboane
		for (int i = 0, start, end; i < N; i++) {
			fin >> start >> end;
			probl.push_back(Object(start, end));		// adaugare in vector
		}
		fin.close();
	}

    int compute_solution() {
    	vector< vector<int> > dp(N + 1, vector<int>(M + 1, 0));
    	/* caz de baza */
    	for (int i = probl[0].start; i <= probl[0].end && i <= M; i++) {
				dp[1][i] = 1;
    	}

    	for (int i = 2; i <= N; i++) {		// completez matricea pe linii si coloane
    		for (int j = probl[i - 1].start; j <= M; j++) {
    			if (probl[i - 1].end > M) {
    				probl[i - 1].end = M;
	   			}
    			for (int k = probl[i - 1].start; k <= probl[i - 1].end
    				&& (j - k) >= 0; k++) {
    				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
    			}
    		}
    	}
    	// rezultatul se gaseste pe ultima linie si ultima coloana
    	return dp[N][M];
    }

	void print_output() {
		ofstream fout("bomboane.out");
		fout << compute_solution();
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}

