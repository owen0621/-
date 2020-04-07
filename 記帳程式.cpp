#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
using namespace std;

void write_file(int,int,int,int);
void read_file(int,int);

int main()
{
	int choose;
	int type;
	int money;
	int year;
	int month;
	time_t t;
	struct tm *local;
	
	while(1){
		
		cout<<"�n����H�U�����ʧ@?"<<endl;
		cout<<"1)�O�b 2)�[�ݬ��� 3)�����{�� "; 
		cin>>choose;
		
		switch(choose){
		
			case 1:
				cout<<"���� 1)����b�� 2)��ܤ�� ";
				cin>>choose;
				if(choose==1)
				{
					t=time(NULL);
					local=localtime(&t);
					cout<<1900+local->tm_year<<"�~ "<<1+local->tm_mon<<"��"
					<<local->tm_mday<<"��"<<endl;
					cout<<"����: 1)�� 2)�� 3)�� 4)�� 5)�| 6)�� 7)��L ";
					cin>>type;
					cout<<"���B: ";
					cin>>money;
					write_file(1900+local->tm_year,1+local->tm_mon,type,money);
					break;	
				}
				if(choose==2)
				{
					int get_year,get_month;
					cout<<"�~��: ";
					cin>>get_year;
					cout<<"���: ";
					cin>>get_month;
					cout<<"����: 1)�� 2)�� 3)�� 4)�� 5)�| 6)�� 7)��L ";
					cin>>type;
					cout<<"���B: ";
					cin>>money;
					write_file(get_year,get_month,type,money);
					break;
				}
			
			case 2:
				cout<<"���d�ߦ~��: ";
				cin>>year;
				cout<<"���d�ߤ��(��0�[�ݾ�~����) ";
				cin>>month;
				read_file(year,month);
				break;
				
			case 3:
				exit(0); 
				break;
				
			default:
				cout<<"�L���ﶵ"<<endl; 
		}
	}
	return 0;
}

void write_file(int year,int month,int type,int money)
{

	ofstream myfile;
	myfile.open("data.txt",ios::out|ios::app);
	if(!myfile.is_open())
	{
		cout<<"�ɮ׶}�ҥ���"<<endl;
		return; 
	}
	myfile<<year<<" "<<month<<" "<<type<<" "<<money<<endl;
	myfile.close();
	return;	
}

void read_file(int year,int month)
{
	int read_year,read_month,read_type,read_money;
	int record[8]={0};
	ifstream myfile;
	myfile.open("data.txt");
	if(!myfile.is_open())
	{
		cout<<"�ɮ׶}�ҥ���"<<endl;
		return; 
	}
	while(myfile>>read_year>>read_month>>read_type>>read_money)
	{
		if(read_year==year&&(read_month==month||read_month==0))
		{
			record[0]=record[0]+read_money;
			record[read_type]=record[read_type]+read_money;
		}
	}
	cout<<"�~��: "<<year<<" ���: "<<month<<endl;
	if(record[0]==0) cout<<"�L�������"<<endl;
	else{
		cout<<"����\t���B\t���"<<endl;
		cout<<"============================================"<<endl;
		cout<<"�`�B\t"<<record[0]<<endl;
		cout<<"��\t"<<record[1]<<"\t"<<record[1]*100/record[0]<<"%"<<endl;
		cout<<"��\t"<<record[2]<<"\t"<<record[2]*100/record[0]<<"%"<<endl;
		cout<<"��\t"<<record[3]<<"\t"<<record[3]*100/record[0]<<"%"<<endl;
		cout<<"��\t"<<record[4]<<"\t"<<record[4]*100/record[0]<<"%"<<endl;
		cout<<"�|\t"<<record[5]<<"\t"<<record[5]*100/record[0]<<"%"<<endl;
		cout<<"��\t"<<record[6]<<"\t"<<record[6]*100/record[0]<<"%"<<endl;
		cout<<"��L\t"<<record[7]<<"\t"<<record[7]*100/record[0]<<"%"<<endl; 
	}
	return;
	
}

