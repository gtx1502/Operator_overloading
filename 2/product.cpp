#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Product
{
	int count;
	double price;
	public:
	Product(int c,double p){
		count=c;
		price=p;
	}
	operator int(){
		return count;
	}
	operator double(){
		return price;
	}

};

int main(int argc, char *argv[])
{
	int count;
	double price;
	cout<<"�������Ʒ����"<<endl;
	cin>>count;
	cout<<"�������Ʒ�۸�"<<endl;
	cin>>price;
	Product product(count,price);
	cout<<"Count is "<<(int)product<<endl;
	cout<<"Price is "<<(double)product<<endl;
	return 0;
}