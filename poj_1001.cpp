#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Multiply function based on work of Aditya Kumar. Code found at:
//http://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/

//multiplies two strings together, returns the result
string multiply(string num1, string num2){
	if(num1[0]=='0'){
		num1.erase(0, 1);
	}
	if(num2[0]=='0'){
		num2.erase(0,1);
	}

	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 ==0){
		return "0";
	}

	//find and erase decimals
	size_t decimal1 = num1.find(".");
	size_t decimal2 = num2.find(".");
	size_t dad1 = 0, dad2 = 0; //digits after decimal for num1, num2
	if(decimal1!=string::npos){
		n1--;
		dad1 = n1-decimal1;
		num1.erase(decimal1,1);
	}
	if(decimal2!=string::npos){
		n2--;
		dad2 = n2-decimal2;
		num2.erase(decimal2,1);
	}



	//result stored in vector in reverse order
	vector<int> result(n1+n2, 0);

	//used to find positions in the result
	int i_n1 = 0;
	int i_n2 = 0;

	//go from right to left in num1
	for (int i = n1-1; i>=0;i--){
		int carry = 0;
		int n1 = num1[i] - '0'; //subtract zero char converts ascii char to integer equivalent

		//resets the position to left after each multiplication of digit
		//in num1 by all of num2
		i_n2 = 0;

		//go from right to left in num2
		for (int j = n2-1; j>=0; j--){
			int n2 = num2[j] - '0';

			//Multiply with current digit of first number and add result to previously stored
			//result at the current position
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;
			carry = sum/10; //carry for next iteration
			result[i_n1+i_n2] = sum % 10; //stores result
			i_n2++;
		}
		if (carry > 0)
			result[i_n1+i_n2] += carry; //story carry in next result

		i_n1++; //shift position to left after every multiplication of a digit in num1
	}

	//if there is a decimal point
	if(dad1+dad2!=0){
		result.insert(result.begin()+dad1+dad2, (int)'.'); //add decimal
	}

	//ignore '0's from the right, remember result is reversed, so these are leading '0's
	int i = result.size()-1;
	while(i>=0 && result[i] == 0)
		i--;

	if(i==-1)
		return "0";

	//generate the result string
	string s = "";
	while (i>=0)
		if(result[i]==46){ //if decimal point add decimal
			s+=".";
			i--;
		} else{
		s+=to_string(result[i--]);
		}

	return s;
}


int main() {
	string s;
	int n;
	while(cin>>s>>n){
		string result(s);
		for(int i = 1;i<n;i++){
			result = multiply(result, s);
		}
		cout<<result<<endl;
	}
	return 0;
}
