#include <bits/stdc++.h>
using namespace std;

struct Object {		// structura in care retin perechi formate din
	int xStart;		// din capetele intervalelor
	int xEnd;

	Object(int _xStart, int _xEnd) : xStart(_xStart), xEnd(_xEnd) {}
};

bool cmp(Object &x1, Object &x2) {		// comparator folosit
	if (x1.xStart == x2.xStart) {		// pentru a ordona perechile
		return x1.xEnd > x2.xEnd;		// in functie de inceput si sfarsit
	}
	return x1.xStart < x2.xStart;
}

class Task {
 public:
	void solve() {
		read_input();
        compute_solution();
		print_output();
	}

 private:
	int N;
	vector<Object> coordinates;

	void read_input() {
		ifstream fin("gard.in");
		fin >> N;
		for (int i = 0, xStart, xEnd; i < N; i++) {
			fin >> xStart >> xEnd;
			coordinates.push_back(Object(xStart, xEnd));
		}
		fin.close();
	}
	/*
	In compute_solution se calculeaza rezultatul final
	In del se retine numarul de garduri eliminate, iar variabila
	index retine ultima bucata de gard valida
	*/
    int compute_solution() {
        int del = 0, index = 0;

        sort(coordinates.begin(), coordinates.end(), cmp);
            for (int i = 1; i < coordinates.size(); i++) {
        	if ((coordinates[i].xStart >= coordinates[index].xStart &&
        		coordinates[i].xEnd <= coordinates[index].xEnd)) {
        		del++;
        	} else {
        		index = i;
        	}
        }
		return del;
	}

	void print_output() {
		ofstream fout("gard.out");
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

