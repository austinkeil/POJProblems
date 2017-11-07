#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
	int n = 0;
	int m = 0;
	int inv=0;

	cin >> n;
	cin >> m;
	vector<string> s;
	multimap<int, string> rankings;
	string temp="";
	for(int i = 0;i<m;i++){
		cin >> temp;
		s.push_back(temp);
	}
	for(unsigned int i = 0; i<s.size(); i++){
		inv = 0;
		for(unsigned int j = 0; j<s[i].length();j++){
			for(unsigned int k=j+1; k<s[i].length();k++){
				if (s[i][j]>s[i][k])
					inv++;
			}
		}
		rankings.insert(pair<int,string>(inv,s[i]));
	}
	for(multimap<int,string>::iterator it = rankings.begin(); it != rankings.end(); it++){
		cout<<it->second<<endl;
	}

	return 0;
}
