#include <iostream>
#include <stdlib.h> 
#include <math.h>
using namespace std;

bool isPerfectSquare(long long n){
    long long squareRootN=(long long)round((sqrt(n)));

    if(squareRootN*squareRootN == n) {
        return true; 
    }
     else {
        return false; 
    }
}

int hanoi(int nt){
		bool inside = false;
		int towers[nt+1];
		int n = 1;
		for(int j = 1;j<=nt+1;j++){
			towers[j] = 0;
		}
		while(true){
			for(int i = 1; i<=nt;i++){
				inside = false;
				if(towers[i] == 0){
					towers[i] =n;
					n++;
					inside = true;
					break;
				}
				else if ( isPerfectSquare(n+towers[i])== true){
					towers[i] = n;
					n++;
					inside = true;
					break;
				}
			}
			if(inside == false){
				//cout << n-1 << endl;
				return n-1;
				break;
			}
		}
	}

int main(void){
	int cases;
	int nt;
	int res;
	int somebody[50];
	cin >> cases;
	int prints = 1;
	while(cases!=0){
		cin >> nt;
		somebody[prints] = hanoi(nt);
		cases--;
		prints++;
	}
	for(int h = 1;h<prints;h++){
		cout << somebody[h] << endl;
	}
	
	return 0;
}

