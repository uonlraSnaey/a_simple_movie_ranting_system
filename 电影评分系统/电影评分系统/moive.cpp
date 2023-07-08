#include <iostream>
using namespace std;
#include "moive.h" //�����Զ����ͷ�ļ�"moive.h"
#include "iomanip" //Ԥ����ָ����ڰ���ͷ�ļ� iomanip���ṩ���������������һЩ��ʽ���ƺ���

// Moive ��Ĺ��캯��������һ���Ѿ���ʼ�������Ե� Moive ����
Moive::Moive(int no, string name, string types, string nation, string actor, int data, double grade, double sum, int num)
{

    this->m_no = no; // �����յ� no ������ֵ������� m_no ��Ա����
    this->m_name = name;
    this->m_types = types;
    this->m_nation = nation;
    this->m_actor = actor;
    this->m_data = data;
    this->m_grade = grade;
    this->m_sum = sum;
    this->m_num = num;
}
// Moive ��ĳ�Ա������������ʾ��Ӱ����Ϣ
// ʹ�� cout ������͸��������ʽ���Ʒ�����ʽ�������Ӱ�ĸ������ԡ�
void Moive::showinfo()
{
    cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_no
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_name
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_types
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_nation
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_actor
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_data
        //<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_grade
        //<< setw(16) << setiosflags(ios::left) << setprecision(2) << setfill(' ') << this->m_grade
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_sum
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_sum / this->m_num
        << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_num << endl;
        
}
// Moive ��ĳ�Ա���������ڼ����Ӱ�İ�������������
double Moive::score_movie(double a, double b, double c, double d)
{
    double a1 = a * 0.30;
    double b1 = b * 0.25;
    double c1 = c * 0.25;
    double d1 = d * 0.20;
    double sum = a1 + b1 + c1 + d1;
    return sum;
}
