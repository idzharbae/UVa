#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 
int n,m,x_1,y_1,x_2,y_2;
int maze[50][50];
int path[50][50];
int mark[50][50];

bool solve(int x1,int y1, int x2, int y2, int step){
	path[x1][y1] = step;
	mark[x1][y1] = 1;
	if(x1==x2 and y1==y2) return true;
	if(maze[x1][y1-1] != -1 and maze[x1][y1-1] != 1 and maze[x1][y1-1] != 3 and !mark[x1][y1-1]){
		if(solve(x1,y1-1,x2,y2,step+1)) return true;
	}
	if(maze[x1-1][y1] != -1 and maze[x1-1][y1] != 2 and maze[x1-1][y1] != 3 and !mark[x1-1][y1]){
		if(solve(x1-1,y1,x2,y2,step+1)) return true;
	}
	if(maze[x1][y1+1] != -1 and maze[x1][y1] != 1 and maze[x1][y1] != 3 and !mark[x1][y1+1]){
		if(solve(x1,y1+1,x2,y2,step+1)) return true;
	}
	if(maze[x1+1][y1] != -1 and maze[x1][y1] != 2 and maze[x1][y1] != 3 and !mark[x1+1][y1]){
		if(solve(x1+1,y1,x2,y2,step+1)) return true;
	}
	path[x1][y1] = 0;
	return false;
}

int main(){
	cin>>n>>m>>x_1>>y_1>>x_2>>y_2;
	int mz = 1;
	while(n != 0 or m != 0 or x_1 != 0 or y_1 != 0 or x_2 != 0 or y_2 != 0){
		cout<<"Maze "<<mz++<<endl<<endl;
		memset(maze, -1, sizeof maze);
		memset(path, -1, sizeof path);
		memset(mark, 0, sizeof path);
		for(int i = 1; i <= n; i++) for (int j = 1; j <= m; j++ ) cin>>maze[i][j];
		solve(x_1,y_1,x_2,y_2,1);
			for(int i = 1; i <= n; i++){
				if(i == 1){for(int k = 0; k<m;k++) cout<<"+---"; cout<<"+\n";}
				else {for(int j = 1; j<=m;j++){ cout<<"+"; (maze[i-1][j]==2 or maze[i-1][j]==3)?cout<<"---":cout<<"   ";}cout<<"+\n";}
				for(int j = 1; j <= m; j++){
					(j==1)?cout<<"|":cout<<""; (path[i][j]==0)?cout<<"???":(path[i][j]==-1)?cout<<"   ":cout<<"  "<<path[i][j]; (maze[i][j] == 1 or maze[i][j]==3 or j==m)?cout<<"|":cout<<" ";
				}cout<<endl;
			}
			for(int k = 0; k<m;k++) cout<<"+---"; cout<<"+\n";
		
		cout<<endl<<endl;
		cin>>n>>m>>x_1>>y_1>>x_2>>y_2;	
	}
	return 0;
}



