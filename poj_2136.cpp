#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <iterator>
#include <map>
using namespace std;

int main() {
	string temp;
	string perm;
	map<char, int> freq;
	vector<int> f;

	for(int i = 0;i<4;i++){
		getline(cin, temp);
		perm.append(temp);
	}

	for(unsigned int i = 0; i<perm.length(); i++){
		if(isalpha(perm[i])){
			freq[perm[i]]++;
		}
	}

	int max = 0;
	for(map<char,int>::iterator it = freq.begin(); it!=freq.end();it++){
		f.push_back(it->second);
		if(it->second>max){
			max = it->second;
		}
	}

	for(int j = 0; j<max; j++){
		unsigned int i = 0;
		while(i< f.size()){
			if(f[i]<*max_element(f.begin(), f.end())){
				i++;
				cout<<"  ";
			}
			else if(f[i]==*max_element(f.begin()+i+1, f.end())){
				f[i]--;
				i++;
				cout<<"* ";

			}
			else{
				f[i]--;
				cout<<"*\n";
				break;
			}
		}
	}

	for(unsigned int i =0;i<f.size()-1;i++){
		cout<<(char)(i+65)<<" ";
	}
	cout<<(char)(65+f.size()-1);
	return 0;
}
