#include <stdio.h>
#include <iostream>
using namespace std;

class Egg
{
	public:
	int price;
	Egg(int p){
		price=p;
	}
	/*const int operator*(const int price){	//Egg*�۸� ��Ա����
		return this->price;
	}*/
};
class Milk
{
	public:
	int price;
	Milk(int p){
		price=p;
	}
	/*const int operator*(const int price){	//Milk*�۸� ��Ա����
		return this->price;
	}*/
};
class Cow
{
	public:
		int milkNum;
		int num;
		int income;
		Cow(Milk milk,int n){		//������n-ÿֻ��ţţ���ղ�����ǧ�ˣ�
			milkNum=n;
			income=milk.price;
		}	
		Cow* operator=(const int& n){	//Cow=int ��Ա����
			this->num=n;
			return this;
		}
};

class Hen
{
	public:
		int eggNum;
		int num;
		int income;
		Hen(Egg egg,int n){
			eggNum=n;
			income=egg.price;
		}
		Hen* operator=(const int& n){	//Hen=int ��Ա����
			this->num=n;
			return this;
		}
		/*const int operator+(Cow cow){		//Hen+Cow ��Ա����
			int month_income;
			month_income=(this->num*this->eggNum*this->income+cow.num*cow.milkNum*cow.income)*30;
			return month_income;
		}*/
		
};


const int operator*(Egg egg,const int price){	//Egg*�۸� �ǳ�Ա����
	return egg.price;
}
const int operator*(Milk milk,const int price){	//Milk*�۸� �ǳ�Ա����
	return milk.price;
}
const int operator+(Hen hen,Cow cow){		//Hen+Cow �ǳ�Ա����
	int month_income;
	month_income=(hen.num*hen.eggNum*hen.income+cow.num*cow.milkNum*cow.income)*30;
	return month_income;
}
int main(int argc, char *argv[])
{
	//Egg egg;
	//Milk milk;
	Egg egg(1);
	Milk milk(1);
	Hen hen(egg,1);		//ÿֻ��ƽ��һ���1������
	Cow cow(milk,30);	//ÿֻ��ţÿ���30ǧ��ţ��
	hen=100;	//100ֻĸ��
	cow=50;		//50ֻ��ţ
	cout<<"ÿ�������۸�Ϊ"<<egg*1<<"Ԫ"<<endl;
	cout<<"ÿǧ��ţ�̼۸�Ϊ"<<milk*1<<"Ԫ"<<endl;
	cout<<"������ţÿ�����ܲ���������Ϊ"<<(hen+cow)<<"Ԫ"<<endl;
	return 0;
}