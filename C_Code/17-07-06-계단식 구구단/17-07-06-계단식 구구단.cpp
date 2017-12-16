#include <iostream>
using namespace std;

void main(){
	int c = 0;
	for (int i = 1; i<11; i += c){
		for (int k = 1; k < 10; k++){
			for (int j = i; j <= i + c; j++){
				cout << j << " * " << k << " = " << j * k << "\t";
			}
			cout << endl;
		}
		c++;
		cout << endl;
	}
}

// 0 1 2 3 4 5
// 0 1 3 6 10 15

// 1 2 4 7