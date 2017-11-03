//============================================================================
// Name        : poj_2140.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//1 = 1 (1)
//2 = 1 (2)
//3 = 2 (1+2) (3)
//4 = 1 (4)
//5 = 2	(2+3) (5)
//6 = 2 (1+2+3), (6)
//7 = 2 (3+4) (7)
//8 = 1 (8)
//9 = 3 (4+5) (2+3+4) (9)
//10 = 2 (1+2+3+4) (10)
//11 = 2 (11) (5+6)
//12 = 2 (12) (3+4+5)

int main() {
	int n = 0;
	cin>>n;
	int sum=0;
	int count=0;
	int i = 1;
	for(int start = 1; start<=n;start++){
		sum = start;
		i = start + 1;
		while (sum<n){
			sum += i;
			i++;
		}
		if(sum==n){
			count++;
		}
	}
	cout<<count;

	return 0;
}
