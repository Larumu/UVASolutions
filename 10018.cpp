#include <iostream>
using namespace std;

typedef unsigned long ulong;

ulong reverse(ulong n){
	long reversedNumber = 0, remainder;
 	while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}

int main(){
	int cases;
	ulong save_cases[500];
	int i;
	int cases_2;
	ulong num;
	ulong num2;
	ulong comp;
	cin >> cases;
	cases_2 = cases;
	int j = 0;
	while(cases >0){
		cin >> save_cases[j];
		cases--;
		j++;
	}
	for(int h = 0;h<cases_2;h++){
		num = save_cases[h];
		i = 0;
		while(true){
			i++;
			int res = reverse(num);
			num += res;
			num2 = reverse(num);
			if(num == num2){
				cout << i <<" "<< num << "\n";
				break;
			}
		}
	}
	return 0;	
}