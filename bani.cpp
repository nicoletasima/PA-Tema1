#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Task {
 public:
	void solve() {
		read_input();
        compute_solution();
		print_output();
	}

 private:
	int instruction_set, N;
	/*
	 Functie care calculeaza puterea unui numar natural
	*/
	int power(int base, int exponent) {
		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
            return base % mod;
        }
        int res = power(base, exponent / 2);
        if (exponent % 2 == 0) {
            return 1LL * res * res % mod;
        } else {
            return ((1LL * res * res % mod) * base) % mod;
        }
	}

	void read_input() {
		ifstream fin("bani.in");
		fin >> instruction_set >> N;		// N - numar bancnote care trebuie asezate
		fin.close();
	}

    int compute_solution() {
    	if (instruction_set == 1) {
    		return 1LL * (power(2, N - 1) % mod) * (5 % mod) % mod;
    	} else {
			vector<int> banc10(N);		// vectori in care retin numarul de bancnote
			vector<int> banc50(N);		// de un anumit tip la fiecare pas
			vector<int> banc100(N);
			vector<int> banc200(N);
			vector<int> banc500(N);

			banc10[0] = banc50[0] = banc100[0] = banc200[0] = banc500[0] = 1;
			for (int i = 1; i < N; i++) {
				banc10[i] = 1LL * (banc50[i - 1] % mod + banc100[i - 1]
					% mod) % mod;
				banc50[i] = 1LL * (banc10[i - 1] % mod + banc200[i - 1]
					% mod) % mod;
				banc100[i] = 1LL * (banc10[i - 1] % mod + banc100[i - 1]
					% mod) % mod;
				banc200[i] = 1LL * ((banc50[i - 1] % mod + banc100[i - 1]
				% mod) % mod + banc500[i - 1] % mod) % mod;
				banc500[i] = 1LL * (banc10[i - 1] % mod + banc200[i - 1]
					% mod) % mod;
			}
			return 1LL * ((((banc10[N - 1] % mod + banc50[N - 1] % mod) % mod +
				banc100[N - 1] % mod) % mod + banc200[N - 1] % mod) % mod +
				banc500[N - 1] % mod) % mod;
		}
	}

	void print_output() {
		ofstream fout("bani.out");
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
