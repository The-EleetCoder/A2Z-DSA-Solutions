#include<iostream>
using namespace std;

int main() {
	string n;
	cin >> n;

	int i=0, even=0, odd=0;
	
  while(i < n.size()) {
		if (n[i]%2 == 0){
			even += (n[i] - '0');
		}
		else{
			odd += (n[i] - '0');
		}
		i++;
	}
	cout << even << " " << odd;
}
