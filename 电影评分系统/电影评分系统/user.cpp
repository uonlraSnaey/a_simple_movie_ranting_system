#include<iostream>
#include"user.h"
#include<iomanip>
using namespace std;
//������һ����Ϊ User ����, Person ���������
void User::showinfo()
{
	//��ʽ������û��ı�š�������Ȩ�ޡ�
	//setw(16) ����ÿ���еĿ��Ϊ 16��setiosflags(ios::left) ���ö��뷽ʽΪ����룬setfill(' ') ��������ַ�Ϊ�ո�
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_access << endl;
}

//���캯�� User,���ڳ�ʼ���û�����ĳ�Ա����,�������Ƿֱ�ֵ����ĳ�Ա������
User::User(int no, string name, string access)
{
	this->p_no = no;
	this->p_name = name;
	this->p_access = access;
}

