//============================================================================
// Name        : poj_1806.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int temp;
	vector<int> scenarios;
	for(int i = 0;i<n;i++){
		cin>>temp;
		scenarios.push_back(temp);
	}
	for(int scen = 0; scen<n;scen++){
		int gas = scenarios[scen];
		int x_dist = gas*(-1);
		cout<<"Scenario #"<<scen+1<<":"<<endl;
		for(int slice = 1; slice<=2*gas+1;slice++){
			cout<<"slice #"<<slice<<":"<<endl;
			for(int y_dist = gas; y_dist>=gas*(-1);y_dist--){
				for(int z_dist = gas*(-1); z_dist <=gas; z_dist++){
					int total = abs(x_dist)+abs(y_dist)+abs(z_dist);
					if(total>gas){
						cout<<".";
					}
					else{
						cout<<total;
					}
				}
				cout<<"\n";
			}
			x_dist++;
		}
		cout<<"\n";
	}
	return 0;
}
