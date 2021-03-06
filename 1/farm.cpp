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
	/*const int operator*(const int price){	//Egg*价格 成员函数
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
	/*const int operator*(const int price){	//Milk*价格 成员函数
		return this->price;
	}*/
};
class Cow
{
	public:
		int milkNum;
		int num;
		int income;
		Cow(Milk milk,int n){		//参数：n-每只奶牛牛奶日产量（千克）
			milkNum=n;
			income=milk.price;
		}	
		Cow* operator=(const int& n){	//Cow=int 成员函数
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
		Hen* operator=(const int& n){	//Hen=int 成员函数
			this->num=n;
			return this;
		}
		/*const int operator+(Cow cow){		//Hen+Cow 成员函数
			int month_income;
			month_income=(this->num*this->eggNum*this->income+cow.num*cow.milkNum*cow.income)*30;
			return month_income;
		}*/
		
};


const int operator*(Egg egg,const int price){	//Egg*价格 非成员函数
	return egg.price;
}
const int operator*(Milk milk,const int price){	//Milk*价格 非成员函数
	return milk.price;
}
const int operator+(Hen hen,Cow cow){		//Hen+Cow 非成员函数
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
	Hen hen(egg,1);		//每只鸡平均一天产1个鸡蛋
	Cow cow(milk,30);	//每只奶牛每天产30千克牛奶
	hen=100;	//100只母鸡
	cow=50;		//50只奶牛
	cout<<"每个鸡蛋价格为"<<egg*1<<"元"<<endl;
	cout<<"每千克牛奶价格为"<<milk*1<<"元"<<endl;
	cout<<"鸡和奶牛每个月能产生的收入为"<<(hen+cow)<<"元"<<endl;
	return 0;
}
