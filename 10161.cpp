#include <iostream>
#include <stdlib.h> 
#include <math.h>
using namespace std;

//UPDATE 4/3: Finished parser

void walk(int stops[100], char direction[6][10],int moves[6]){
	int i = 0;
	while(stops[i] !=0){
		cout << stops[i] << endl;
		i++;
	}
}

int main(void){
	char direction[6][10] = {"Up","Right","Down","Right","Up","Left"};
	int moves[6] = {1,1,1,1,2,2};
	int x = 1;
	int y = 1;
	int stop; 
	int stops[100];
	int i = 0;
	while(true){
		cin >> stop;
		if (stop != 0){
			stops[i] = stop;
			i++;
		}
		else {
			stops[i] = stop;
			walk(stops,direction,moves);
			break;
		}
	}
	return 0;
}