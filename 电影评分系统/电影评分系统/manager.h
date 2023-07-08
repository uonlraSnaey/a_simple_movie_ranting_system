#pragma once
#include<iostream>
#include"person.h"
#include<string>
using namespace std;

//定义了一个名为Manager的类，它公有继承自Person类。
class Manager:public Person
{
public:
	Manager(int no, string name, string access);//Manager类有一个构造函数，接受三个参数
	
	//在Person类中，showinfo函数被声明为虚函数，所以在派生类Manager中也需要使用virtual关键字来进行声明。
	virtual void showinfo(); //Manager类重写了Person类中的虚函数showinfo，该函数用于显示管理员的信
};

