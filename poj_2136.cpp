#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main(){
	string temp;
	vector<int> vect (26);
	for(int i = 0; i<4;i++){
		getline(cin, temp);
		for(unsigned int j = 0; j<temp.length(); j++){
			if(temp[j] >= 65 && temp[j]<=90){
				vect[temp[j]-65]++;
			}
		}
	}
	vector<int>::iterator max = max_element(vect.begin(), vect.end());
	vector<int>::iterator it;
	while(*max){
		for(it = vect.begin(); it!=vect.end(); it++){
			if(it<max){
				cout<<"  ";
			}
			else if (it==max){
				(*it)--;
				max = max_element(vect.begin(), vect.end());
				if((*it)+1>*max_element(it+1, vect.end()) || !(*max)){
					cout<<"*\n";
					break;
				}
				else{
					cout<<"* ";
				}
			}
		}
	}
	for(int i =0; i<25; i++){
		cout<<(char)(i+65)<<" ";
	}
	cout<<(char)(90);

}
