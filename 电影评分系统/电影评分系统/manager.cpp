#include<iostream>
#include"manager.h"
#include<iomanip>
using namespace std;

//Manager�����������Ա������ʵ�֡�

//showinfo������һ�����г�Ա������������ʾ����Ա��Ϣ
void Manager::showinfo()
{
	//cout << "��Ա��ţ�" << this->p_no
	//	<< "\t���֣�" << this->p_name
	//	<<"\tȨ�ޣ�"<<this->p_access<< endl;
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_access << endl;
}
//Manager��Ĺ��캯�������ڳ�ʼ������Ա��������ݳ�Ա
Manager::Manager(int no, string name, string access)
{
	this->p_no = no;
	this->p_name = name;
	this->p_access = access;
}