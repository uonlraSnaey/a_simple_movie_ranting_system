#pragma once
#include<iostream>
#include"person.h"
#include<string>
using namespace std;

//������һ����ΪManager���࣬�����м̳���Person�ࡣ
class Manager:public Person
{
public:
	Manager(int no, string name, string access);//Manager����һ�����캯����������������
	
	//��Person���У�showinfo����������Ϊ�麯����������������Manager��Ҳ��Ҫʹ��virtual�ؼ���������������
	virtual void showinfo(); //Manager����д��Person���е��麯��showinfo���ú���������ʾ����Ա����
};

