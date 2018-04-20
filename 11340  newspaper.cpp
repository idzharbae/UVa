#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	while(N--){
		int k;
		map<char,int> harga;
		cin>>k;
		while(k--){
			int value;
			char x; cin>>x>>value;
			harga[x] = value;
		}
		cin>>k;
		getchar();
		string line;
		double sum = 0;
		while(k--){
			getline(cin,line);
			//cout<<line<<endl;
			int len = line.length();
			for(int i = 0; i < len; i++){
				sum += harga[line[i]];
			}
		}
		printf("%.2f$\n",sum/100);
	}
return 0;
}
