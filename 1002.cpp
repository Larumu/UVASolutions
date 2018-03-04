#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	int n,i,j,temp;
	while (cin>>i>>j){
		int x,y;
		x=i;
		y=j;
		if(i>j)
		{
			temp = j;
			j=i;
			i=temp;
		}
		int ans = 0;
		int counter;
		while(i>=j){
			n=i;
			counter =1;
			while(1)
			{
				if (n==1)
					break;
				else if (n%2 !=0)
					n = (3*n)+1;
				else
					n = n/2;
				counter++;
			}
			if(counter>ans)
				ans=counter;
			i++;
			}
		cout<<x<<" "<<y<<" "<<ans<<endl;
		}

		return 0;
	}