#include <iostream>
using namespace std;

int main()
{	
	int num;
	int i,j;
	cout<<"�п�J�Ʀr:";
	cin>>num;
	for(j=1;j<num-2;j++)
	{
		for(i=num-3;i>j;i--)
		{
			cout<<" ";
		}
		for(i=0;i<j;i++)
		{
			cout<<"*";
		}
		for(i=1;i<j;i++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	for(j=1;j<num-3;j++)
	{
		for(i=0;i<j;i++)
		{
			cout<<" ";
		}
		for(i=num-3;i>j;i--)
		{
			cout<<"*";
		}
		for(i=num-4;i>j;i--)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
