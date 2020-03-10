#include<iostream>
#include"../src/myLine.h"
#include <ctime>
#define random(x) rand()%(2*x)-x
using namespace std;
Line randomLine(int x) {
	return Line(random(x), random(x), random(x), random(x));
}
int main() {
	srand((int)time(0));
	int n;
	cout << "input maxnumber of line" << endl;
	cin >> n ;
	Line l1 = randomLine(n);
	Line l2 = randomLine(n);
	if (l1.parallel(l2)) {
		cout << "parallel lines!" << endl;
	}
	else {
		Dot dot = l1.intersect(l2);
		cout << "x = "<<dot.x << "y = " << dot.y << endl;
	}

	
	return 0;
}