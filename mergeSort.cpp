#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right){
	vector<int> merged;
	while(!left.empty() || !right.empty()){
		if(!left.empty() && !right.empty()){
			if(left[0]<=right[0]){
				merged.push_back(left[0]);
				left.erase(left.begin());
			} else{
				merged.push_back(right[0]);
				right.erase(right.begin());
			}
		}
		else if(left.empty()){
			for(unsigned int i = 0; i<right.size(); i++){
				merged.push_back(right[i]);
			}
			right.erase(right.begin(), right.end());
		}else{
			for(unsigned int i = 0; i<left.size(); i++){
				merged.push_back(left[i]);
			}
			left.erase(left.begin(), left.end());
		}
	}
	return merged;
}
vector<int> mergeSort(vector<int> vect){
	if(vect.size()<=1)
		return vect;
	int mid = vect.size()/2;
	vector<int> left(vect.begin(), vect.begin()+mid);
	vector<int> right(vect.begin()+mid, vect.end());
	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
	}


int main() {
	vector<int> someVect;
	someVect.push_back(3);
	someVect.push_back(1);
	someVect.push_back(5);
	someVect.push_back(9);
	someVect.push_back(7);
	someVect.push_back(2);
	someVect.push_back(1);
	vector<int> sortedVect = mergeSort(someVect);
	for(unsigned int i = 0;i<sortedVect.size();i++){
		cout<<sortedVect[i]<<" ";
	}
}
