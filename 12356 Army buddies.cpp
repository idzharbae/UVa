#include <bits/stdc++.h>
using namespace std;

int main(){
	int S, B;
	cin>>S>>B;
	while(S != 0 and B != 0){
		pair<int,int> buddies[S+2];
		for(int i = 1; i <= S; i++){
			buddies[i] = {i-1,(i+1)%(S+1)};
			// cout<<buddies[i].first<<" "<<buddies[i].second<<endl;
		}
		while(B--){
			int l,r;
			cin>>l>>r;
			if(l>0)
			buddies[buddies[l].first].second = buddies[r].second;
			if(r<=S)
			buddies[buddies[r].second].first = buddies[l].first;
			
			if(buddies[buddies[r].second].first <= 0) cout<<"* "; else cout<<buddies[buddies[r].second].first<<" ";
			if(buddies[buddies[l].first].second <= 0) cout<<"*\n"; else cout<<buddies[buddies[l].first].second<<"\n";
		}
		cout<<"-\n";
		cin>>S>>B;
	}
return 0;
}
