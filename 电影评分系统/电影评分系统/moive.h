#pragma once
#include<iostream>
#include<string>
using namespace std;

//定义 Moive 类
class Moive
{
public:
	//构造函数，用于创建 Moive 类的对象，并初始化成员变量。
	Moive(int no, string name, string types, string nation, string actor, int data,double grade,double m_sun,int m_num);
	//计算电影的评分，接受剧情流畅度、画面表现、演员表演和整体音乐的评分作为参数，根据权重计算总分，并返回总分。
	double score_movie(double a, double b, double c, double d);
	void showinfo();//显示电影的信息，将电影的各个属性按照一定的格式输出。

	int m_no;//电影编号
	string m_name;//电影名称
	string m_types;//电影类型
	string m_nation;//电影国籍
	string m_actor;//电影主演
	int m_data;//电影时长
	double m_grade = 0;//电影评分
	double m_sum=0;//评分总和
	int m_num=0;//评分次数
};
