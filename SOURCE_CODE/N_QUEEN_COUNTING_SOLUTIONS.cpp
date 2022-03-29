/*
*	N QUEENS PROBLEM
*	
*	TIME COMPLEXITY  :  O(n!)
*	SPACE COMPLEXITY :  O(n^2)
*
*/
#include "bits/stdc++.h"
using namespace std;

void N_QUEEN_PROBLEM_SOLUTION(int y,int n,vector<int> &column,vector<int> &diag1,vector<int> &diag2,int &cnt){
	if(y==n){
		cnt++;
		return;
	}
	for(int x=0;x<n;x++){
		if(column[x] || diag1[x+y] || diag2[n-x+y-1]){
			continue;
		}
		column[x] = diag1[x+y] = diag2[n-x+y-1] = 1;
		N_QUEEN_PROBLEM_SOLUTION(y+1,n,column,diag1,diag2,cnt);
		column[x] = diag1[x+y] = diag2[n-x+y-1] = 0;
	}
	return;
}

void IO(void){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		ios::sync_with_stdio(NULL);
		cin.tie(NULL);
}

int main(){
	IO();
	int n,cnt=0;
	cin>>n;
	vector<int> column(n,0),diag1(2*n,0),diag2(2*n,0);
	N_QUEEN_PROBLEM_SOLUTION(0,n,column,diag1,diag2,cnt);
	cout<<cnt<<"\n";
	return 0;
}