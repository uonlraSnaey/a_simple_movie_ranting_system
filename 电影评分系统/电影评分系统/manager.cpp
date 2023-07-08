#include<iostream>
#include"manager.h"
#include<iomanip>
using namespace std;

//Manager的类的两个成员函数的实现。

//showinfo函数是一个公有成员函数，用于显示管理员信息
void Manager::showinfo()
{
	//cout << "人员编号：" << this->p_no
	//	<< "\t名字：" << this->p_name
	//	<<"\t权限："<<this->p_access<< endl;
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_access << endl;
}
//Manager类的构造函数，用于初始化管理员对象的数据成员
Manager::Manager(int no, string name, string access)
{
	this->p_no = no;
	this->p_name = name;
	this->p_access = access;
}