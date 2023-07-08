#include <iostream>
using namespace std;
#include "moive.h" //引用自定义的头文件"moive.h"
#include "iomanip" //预处理指令，用于包含头文件 iomanip，提供输入输出流操作的一些格式控制函数

// Moive 类的构造函数，创建一个已经初始化了属性的 Moive 对象。
Moive::Moive(int no, string name, string types, string nation, string actor, int data, double grade, double sum, int num)
{

    this->m_no = no; // 将接收的 no 参数赋值给对象的 m_no 成员变量
    this->m_name = name;
    this->m_types = types;
    this->m_nation = nation;
    this->m_actor = actor;
    this->m_data = data;
    this->m_grade = grade;
    this->m_sum = sum;
    this->m_num = num;
}
// Moive 类的成员函数，用于显示电影的信息
// 使用 cout 输出流和各种输出格式控制符来格式化输出电影的各个属性。
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
// Moive 类的成员函数，用于计算电影的按规则计算分数。
double Moive::score_movie(double a, double b, double c, double d)
{
    double a1 = a * 0.30;
    double b1 = b * 0.25;
    double c1 = c * 0.25;
    double d1 = d * 0.20;
    double sum = a1 + b1 + c1 + d1;
    return sum;
}
