#pragma once
#include<iostream>
#include<string>
using namespace std;

//����person������
class Person
{
public:
	//����������ʵ�� showinfo() ������ʾ��ص���Ϣ
	virtual void showinfo() = 0;//���麯����������ʾ�������Ϣ

	int p_no;//�û����
	string p_name;//�û�����
	string p_access;//�û�Ȩ��
};
