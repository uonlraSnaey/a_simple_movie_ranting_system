
#include<iostream>
#include"moive.h" //引用自定义的头文件"moive.h"
#include<fstream> //引用文件流库，用于文件的读写操作
#pragma once  //预处理指令，用于确保头文件只被编译一次
#define mFILENAME "moiveFile.txt" //定义了一个宏常量mFILENAME，表示电影文件的名称，该常量在代码中可以直接使用。
using namespace std;

//定义了一个名为mManager的类，用于管理电影信息
class mManager
{
public:
	mManager();//构造函数，初始化属性
	~mManager();//析构函数，释放堆区数据

	bool fileisempt;//判断文件是否为空(标志）
	int m_MoiNum;//记录电影数量
	Moive** m_MoiArray;//电影数组指针。一个指向电影对象的指针数组，每个指针指向一个 Moive 类型的对象。

	void add_moive();//增加电影
	void m_save();//保存数据（将电影写入文件中）
	void init_moi();//更新电影信息
	int get_moinum();//获得电影数量
	void show_moi();//显示电影
	void table();//电影表头
	void del_moi();//删除电影（电影名称）
	int is_exist(string m);//判断该电影是否存在(传入电影信息名称，国籍，类型)
	void sel_moi(string name);//查找电影(名称)
	void sel_type();//按类型查找电影
	void sel_nat();//按国籍查找电影
	void updata_moi();//更改一个电影信息（名称、编号）
	void gra_moi();//给电影评分


};
