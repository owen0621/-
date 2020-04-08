#include <iostream>
#include <fstream>
using namespace std;

char* encode(char*);
char* decode(char*);

int main()
{
	char word[80];
	int key;
	cout<<"請輸入字串:";
	gets(word);
	cout<<"您要 1)encode 2)decode :";
	cin>>key;
	if(key==1)
		cout<<"After encode : "<<encode(word);
	else if(key==2)
		cout<<"After decode : "<<decode(word);
	else 
		cout<<"Unknown input";
	return 0;
}

char* encode(char* str)
{
	int i;
	for(i=0;!(*(str+i)=='\0');i++)
		*(str+i)=*(str+i)+13;
	return str;
}

char* decode(char* str)
{
	int i;
	for(i=0;!(*(str+i)=='\0');i++)
		*(str+i)=*(str+i)-13;
	return str;
}
