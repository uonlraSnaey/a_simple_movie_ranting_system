#pragma once
#include<iostream>
#include"person.h"
using namespace std;

//定义了一个名为 User 的类，它是 Person 类的公有派生类

//通过这个公有派生类，可以创建具体的用户对象，并调用 showinfo() 函数来显示用户的信息。
class User:public Person
{
private:
	
public:
	User(int no,string name,string access);
	void showinfo();


};

