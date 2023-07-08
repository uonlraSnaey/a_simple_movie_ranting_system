#pragma once
#include<iostream>
#include<string>
using namespace std;

//定义person抽象类
class Person
{
public:
	//在派生类中实现 showinfo() 函数显示相关的信息
	virtual void showinfo() = 0;//纯虚函数，用于显示人物的信息

	int p_no;//用户编号
	string p_name;//用户姓名
	string p_access;//用户权限
};
