#include <iostream>
using namespace std;

// pass by value
int Maximum(int x, int y) {
	if (x>y) return x;
	return y;
}

// pass by reference
void Swap(int &x, int &y) {
	int i;
	i=x;
	x=y;
	y=i;
}

int main() {
	int test, a, b, r;
	cin >> test;
	cin >> a >> b;
  
	switch (test) {
	case 1:
		r = Maximum(a, b);
		cout << r;
		break;
	case 2:
		Swap(a, b);
		cout << a << " " << b;
		break;
	default:
		cout << "Invalid test option";
	}
	return 0;
}