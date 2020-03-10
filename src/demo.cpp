#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <vector>
#include "myLine.h"

using namespace std;

set<Dot> dotSet;
vector<Line> lineVector;
ifstream input;
ofstream output;
void inputOneLine() {

	char ch;
	input >> ch;
	if (ch == 'L') {
		
		int a, b, c, d;
		input >> a >> b >> c >> d;
		Line l(a, b, c, d);
		for (auto it : lineVector) {
			if (it.parallel(l)) {
				continue;
			}
			else {
				Dot dot = it.intersect(l);
				dotSet.insert(dot);
			}
		}
		//cout <<l.A<<" ** "<<l.B<<" ** " << l.C<<endl;
		lineVector.push_back(l);
		
	}
	else {
		cout << "error line format!" << endl;
		throw exception();
	}
}
int main(int argc, char* argv[]) {
	
	for (int i = 0; i < argc; i++) {
			//cout << "argv" << "[" << i << "] = " << argv[i] << endl;
		if (!(strncmp(argv[i], "-i", 2))) {
			input.open(argv[i + 1]);

			
		}
		else if (!(strncmp(argv[i], "-o", 2))) {
			output.open(argv[i + 1]);
		}
	}
	if (input.fail()) {
		cout << "input is  null" << endl;
	}
	int i, n;
	input >>n;
	
	for (i = 0; i < n; i++) {
		inputOneLine();
	}
	cout << dotSet.size() << endl;
	output<< dotSet.size();
	input.close();
	output.close();
	return 0;
}