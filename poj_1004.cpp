//============================================================================
// Name        : poj_1004.cpp
// Author      : Austin Keil
// Version     :
// Copyright   : January 2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double temp;
	double sum;
	for(int i =0; i<12; i++){
		cin>>temp;
		sum+=temp;
	}

	cout<<fixed;
	cout.precision(2);
	cout<<"$"<<sum/12;

	return 0;
}
