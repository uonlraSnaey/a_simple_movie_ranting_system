#pragma once
#include<iostream>
#include"person.h"
using namespace std;

//������һ����Ϊ User ���࣬���� Person ��Ĺ���������

//ͨ��������������࣬���Դ���������û����󣬲����� showinfo() ��������ʾ�û�����Ϣ��
class User:public Person
{
private:
	
public:
	User(int no,string name,string access);
	void showinfo();


};

