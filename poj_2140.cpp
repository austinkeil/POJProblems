#include <iostream>
using namespace std;
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
