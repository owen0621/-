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
		
		cout<<"要執行以下哪項動作?"<<endl;
		cout<<"1)記帳 2)觀看紀錄 3)結束程式 "; 
		cin>>choose;
		
		switch(choose){
		
			case 1:
				cout<<"紀錄 1)今日帳款 2)選擇日期 ";
				cin>>choose;
				if(choose==1)
				{
					t=time(NULL);
					local=localtime(&t);
					cout<<1900+local->tm_year<<"年 "<<1+local->tm_mon<<"月"
					<<local->tm_mday<<"日"<<endl;
					cout<<"分類: 1)食 2)衣 3)住 4)行 5)育 6)樂 7)其他 ";
					cin>>type;
					cout<<"金額: ";
					cin>>money;
					write_file(1900+local->tm_year,1+local->tm_mon,type,money);
					break;	
				}
				if(choose==2)
				{
					int get_year,get_month;
					cout<<"年份: ";
					cin>>get_year;
					cout<<"月份: ";
					cin>>get_month;
					cout<<"分類: 1)食 2)衣 3)住 4)行 5)育 6)樂 7)其他 ";
					cin>>type;
					cout<<"金額: ";
					cin>>money;
					write_file(get_year,get_month,type,money);
					break;
				}
			
			case 2:
				cout<<"欲查詢年份: ";
				cin>>year;
				cout<<"欲查詢月份(按0觀看整年紀錄) ";
				cin>>month;
				read_file(year,month);
				break;
				
			case 3:
				exit(0); 
				break;
				
			default:
				cout<<"無此選項"<<endl; 
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
		cout<<"檔案開啟失敗"<<endl;
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
		cout<<"檔案開啟失敗"<<endl;
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
	cout<<"年份: "<<year<<" 月份: "<<month<<endl;
	if(record[0]==0) cout<<"無此份資料"<<endl;
	else{
		cout<<"種類\t金額\t比例"<<endl;
		cout<<"============================================"<<endl;
		cout<<"總額\t"<<record[0]<<endl;
		cout<<"食\t"<<record[1]<<"\t"<<record[1]*100/record[0]<<"%"<<endl;
		cout<<"衣\t"<<record[2]<<"\t"<<record[2]*100/record[0]<<"%"<<endl;
		cout<<"住\t"<<record[3]<<"\t"<<record[3]*100/record[0]<<"%"<<endl;
		cout<<"行\t"<<record[4]<<"\t"<<record[4]*100/record[0]<<"%"<<endl;
		cout<<"育\t"<<record[5]<<"\t"<<record[5]*100/record[0]<<"%"<<endl;
		cout<<"樂\t"<<record[6]<<"\t"<<record[6]*100/record[0]<<"%"<<endl;
		cout<<"其他\t"<<record[7]<<"\t"<<record[7]*100/record[0]<<"%"<<endl; 
	}
	return;
	
}

