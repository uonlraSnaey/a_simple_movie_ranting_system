
#include<iostream>
#include"moive.h" //�����Զ����ͷ�ļ�"moive.h"
#include<fstream> //�����ļ����⣬�����ļ��Ķ�д����
#pragma once  //Ԥ����ָ�����ȷ��ͷ�ļ�ֻ������һ��
#define mFILENAME "moiveFile.txt" //������һ���곣��mFILENAME����ʾ��Ӱ�ļ������ƣ��ó����ڴ����п���ֱ��ʹ�á�
using namespace std;

//������һ����ΪmManager���࣬���ڹ����Ӱ��Ϣ
class mManager
{
public:
	mManager();//���캯������ʼ������
	~mManager();//�����������ͷŶ�������

	bool fileisempt;//�ж��ļ��Ƿ�Ϊ��(��־��
	int m_MoiNum;//��¼��Ӱ����
	Moive** m_MoiArray;//��Ӱ����ָ�롣һ��ָ���Ӱ�����ָ�����飬ÿ��ָ��ָ��һ�� Moive ���͵Ķ���

	void add_moive();//���ӵ�Ӱ
	void m_save();//�������ݣ�����Ӱд���ļ��У�
	void init_moi();//���µ�Ӱ��Ϣ
	int get_moinum();//��õ�Ӱ����
	void show_moi();//��ʾ��Ӱ
	void table();//��Ӱ��ͷ
	void del_moi();//ɾ����Ӱ����Ӱ���ƣ�
	int is_exist(string m);//�жϸõ�Ӱ�Ƿ����(�����Ӱ��Ϣ���ƣ�����������)
	void sel_moi(string name);//���ҵ�Ӱ(����)
	void sel_type();//�����Ͳ��ҵ�Ӱ
	void sel_nat();//���������ҵ�Ӱ
	void updata_moi();//����һ����Ӱ��Ϣ�����ơ���ţ�
	void gra_moi();//����Ӱ����


};
