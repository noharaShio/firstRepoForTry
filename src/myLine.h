#ifndef _MY_LINE_H
#define _MY_LINE_H
using namespace std;
	class Dot {
	public:
		float x;
		float y;
		Dot(float a, float b) {
			x = a;
			y = b;
		}
		bool operator<(const Dot& p)const {
			return (x < p.x) || (x == p.x && y < p.y);
		}
	};

	class Line {
	public:
		int A;
		int B;
		int C;
		Line(int x1, int y1, int x2, int y2);
		bool operator<(const Line& p)const {
			return (A < p.A) || 
				(A == p.A && B < p.A) || 
				(A == p.A && B == p.B && C < p.C);
		}
		bool parallel(Line l);
		Dot intersect(Line l);
	};

#endif
