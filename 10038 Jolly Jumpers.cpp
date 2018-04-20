#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, arr[3001];
	while(cin>>n){
		int mark[3001] = {0};
		for(int i = 0; i < n ; i++){
			cin>>arr[i];
			if(i > 0){
				int diff = abs(arr[i] - arr[i-1]) -1 ;
				if(diff >= 0 and diff < n)
					mark[diff] = 1;
			}
		}
		int flag = 1;
		for(int i = 0; i < n-1; i++){
			if(!mark[i]){
				cout<<"Not jolly\n";
				flag = 0;
				break;
			}
		}
		if(flag)
		cout<<"Jolly\n";
	}
return 0;
}
