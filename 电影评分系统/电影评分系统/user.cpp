#include<iostream>
#include"user.h"
#include<iomanip>
using namespace std;
//定义了一个名为 User 的类, Person 类的派生类
void User::showinfo()
{
	//格式化输出用户的编号、姓名和权限。
	//setw(16) 设置每个列的宽度为 16，setiosflags(ios::left) 设置对齐方式为左对齐，setfill(' ') 设置填充字符为空格。
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_access << endl;
}

//构造函数 User,用于初始化用户对象的成员变量,并将它们分别赋值给类的成员变量。
User::User(int no, string name, string access)
{
	this->p_no = no;
	this->p_name = name;
	this->p_access = access;
}

