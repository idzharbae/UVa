#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int bit = 0, arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			int diff = abs(arr[i] - arr[i-1])-1;
			if(i > 0 and diff >= 0) bit |= ( 1 << diff );
		}
		bit++;
		int x = (bit>> (int)(log(bit)/log(2)) );
		x = (x << (int)(log(bit)/log(2)) );
		if(bit == x) cout<<"Jolly\n"; else cout<<"Not jolly\n";
		bitset<32> y(bit);
		//cout<<bit<<' '<<x<<endl;
		//cout<<y<<endl;
	}
return 0;
}
