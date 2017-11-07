//============================================================================
// Name        : poj_1003.cpp
// Author      : Austin Keil
// Version     :
// Copyright   : January 2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	float c, sum;
	int n=2;
	cin>>c;
	while(c > 0.001){
		sum = 0;
		n = 2;
		while(sum<c){
			sum+=1.0/n;
			n++;
		}
		cout<<n-2<<" card(s)"<<endl;
		cin>>c;
	}
	return 0;
}
