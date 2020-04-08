#include<iostream>
#include<fstream>
using namespace std;
int see(char,char,char);
int main(){
	int i,j,num;
	char ch[3][3],us;
	 for(i=0;i<3;i++)
	 	for(j=0;j<3;j++)
	 		ch[i][j]=' ';
	for(j=0;;j++)
	{
		for(i=0;i<3;i++)
		{
			cout<<"+-+-+-+\n";
			cout<<"|"<<ch[i][0]<<"|"<<ch[i][1]<<"|"<<ch[i][2]<<"l\n";
		}
		cout<<"+-+-+-+\n";
		if(j% 2) us='A';
		else us='B';
		cout<<"user "<<us<<" enter num¡G";
		cin>>num;
		if(ch[(num-1)/3][(num-1)% 3]==' ')
		{
			if(us=='A') ch[(num-1)/3][(num-1)% 3]='O';
			else ch[(num-1)/3][(num-1)% 3]='x';
		}
		else{
		 cout<<"already been choosen\n";
		 j--;;
		 continue;
    	}
    	if(j>=4)
    	{
    		for(i=0;i<3;i++)
			{
				if((see(ch[i][0],ch[i][1],ch[i][2])||
				   see(ch[0][i],ch[1][i],ch[2][i])||
				   see(ch[0][0],ch[1][1],ch[2][2])||
				   see(ch[0][2],ch[1][1],ch[2][0])))
				   {
				   	cout<<"user "<<us<<" win";
				   	i=-1;
				   	break;
				   }
			}	
		}
		if(j>=8)cout<<"flat\n";;
		if(i==-1)break;
    	
	}

	 
}
int see(char a,char b,char c)
	{
		if(a==b&&b==c&&a!=' ') return 1;
		else return 0;
	}
