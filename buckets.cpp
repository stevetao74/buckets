#include<iostream>
using namespace std;
#include<stack>

int main(){
	string str[100];
	stack<char> sc;
	int n=0,m=n;
	do cin>>n;
	while(n<1||n>100);
	m=n;
	while(m--)
		cin>>str[m];
	while(n--){
		int len=str[n].length();
		int temp=len;
		int xpos=0;
		while(len--){
			if((str[n])[temp-len-1]=='('||(str[n])[temp-len-1]=='['||
				(str[n])[temp-len-1]==')'||(str[n])[temp-len-1]==']')
			{		sc.push((str[n])[temp-len-1]);
			if(len<=temp-2){
			if(
				(sc.top()==')'&&(str[n])[temp-len-2]=='(')||
				(sc.top()==']'&&(str[n])[temp-len-2]=='[')||
				(sc.top()==')'&&(str[n])[temp-len-2-xpos]=='(')||
				(sc.top()==']'&&(str[n])[temp-len-2-xpos]=='[')
			){sc.pop();sc.pop();xpos+=2;}
			}
		 }	
		}
		if(sc.empty()) cout<<"Yes"<<endl;
		else {cout<<"No"<<endl;
		while(!sc.empty()) sc.pop();}
	}
return 0;
}
