#pragma once
#include<iostream>
#include<string>
using namespace std;

//���� Moive ��
class Moive
{
public:
	//���캯�������ڴ��� Moive ��Ķ��󣬲���ʼ����Ա������
	Moive(int no, string name, string types, string nation, string actor, int data,double grade,double m_sun,int m_num);
	//�����Ӱ�����֣����ܾ��������ȡ�������֡���Ա���ݺ��������ֵ�������Ϊ����������Ȩ�ؼ����ܷ֣��������ܷ֡�
	double score_movie(double a, double b, double c, double d);
	void showinfo();//��ʾ��Ӱ����Ϣ������Ӱ�ĸ������԰���һ���ĸ�ʽ�����

	int m_no;//��Ӱ���
	string m_name;//��Ӱ����
	string m_types;//��Ӱ����
	string m_nation;//��Ӱ����
	string m_actor;//��Ӱ����
	int m_data;//��Ӱʱ��
	double m_grade = 0;//��Ӱ����
	double m_sum=0;//�����ܺ�
	int m_num=0;//���ִ���
};
