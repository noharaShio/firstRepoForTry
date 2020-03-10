#include<iostream>
#include"../src/myLine.h"
#include <ctime>
#include <vector>
#include <set>
#define random(x) rand()%(2*x)-x
using namespace std;

vector<Line> lineVector;
set<Dot> dotSet;
Line randomLine(int x) {
	return Line(random(x),random(x),random(x),random(x));
}
int main() {
	srand((int)time(0));
	int i, n;
	cout << "input number of test lines" << endl;
	cin >> n;
	cout << "input maxnum of one line" << endl;
	for (i = 0; i < n; i++) {
		Line l = randomLine(1000);
		for (auto it : lineVector) {
			if (it.parallel(l)) {
				continue;
			}
			else {
				Dot dot = it.intersect(l);
				dotSet.insert(dot);
			}
		}
	}
	cout << dotSet.size() << endl;
	return 0;
}