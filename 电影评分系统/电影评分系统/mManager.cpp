// 对电影信息的管理

#include "manager.h"
#include "manager.h"
#include "user.h"
#include "iomanip"
#include "moive.h"
#include "mManager.h"

mManager::mManager()
{ // 初始化属性

    // 使用ifstream对象ifs打开名为mFILENAME的文件
    ifstream ifs;
    ifs.open(mFILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "\t\t\t ERROR! 文件不存在！" << endl;
        // 进行初始化，将电影数量m_MoiNum设为0，将电影数组m_MoiArray设为NULL，并将fileisempt标志设为true
        this->m_MoiNum = 0;
        this->m_MoiArray = NULL;
        this->fileisempt = true;
        ifs.close();
        return;
    }
    int num = this->get_moinum(); // 取电影数量：使用成员函数get_moinum()获取电影数量，并将其赋值给m_MoiNum。
    this->m_MoiNum = num;
    this->m_MoiArray = new Moive * [this->m_MoiNum]; // 分配电影数组内存，将文件放入数组
    this->init_moi();                               // 调用成员函数init_moi()来从文件中读取电影数据，进行数据更新
}

// 实现了mManager类的成员函数add_moive()，用于增加电影。
void mManager::add_moive()
{
    cout << "\t\t\t 请输入将要增加电影的数量" << endl;
    cout << "\t\t\t";
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0)
    {
        int newsize = this->m_MoiNum + addnum; // 创建新的电影数组空间
        Moive** newspace = new Moive * [newsize];
        if (this->m_MoiArray != NULL) // 原电影数组不为空，复制原有数据到新数组
        {
            for (int i = 0; i < this->m_MoiNum; i++)
            {
                newspace[i] = this->m_MoiArray[i];
            }
        }
        for (int i = 0; i < addnum; i++) // 循环遍历添加新的数据
        {
            int no;
            string name;
            string types;
            string nation;
            string actor;
            int data;
            double grade = 0;
            double sum = 0;
            int num = 0;
            cout << "\t\t\t第" << i + 1 << "个电影编号" << endl;
            cout << "\t\t\t";
            while (cin >> no)
            {
                int adjust = 0;
                for (int j = 0; j < this->m_MoiNum; j++)
                {
                    if (no == this->m_MoiArray[j]->m_no)
                    {
                        cout << "\t\t\t ERROR! 此电影编号已存在 请重新输入" << endl;
                        adjust = 1;
                    }
                }
                if (adjust == 0)
                {
                    break;
                }
            }
            cout << "\t\t\t第" << i + 1 << "个电影的名称:" << endl;
            cout << "\t\t\t";
            while (cin >> name)
            {
                int adjust = 0;
                for (int j = 0; j < this->m_MoiNum; j++)
                {
                    if (name == this->m_MoiArray[j]->m_name)
                    {
                        cout << "\t\t\t ERROR! 此电影已存在 请重新输入" << endl;
                        adjust = 1;
                    }
                }
                if (adjust == 0)
                {
                    break;
                }
            }
            cout << "\t\t\t请输入电影的类型:" << endl;
            cout << "\t\t\t";
            cin >> types;
            cout << "\t\t\t请输入电影的国家:" << endl;
            cout << "\t\t\t";
            cin >> nation;
            cout << "\t\t\t请输入电影的主演:" << endl;
            cout << "\t\t\t";
            cin >> actor;
            cout << "\t\t\t请输入电影的时长:" << endl;
            cout << "\t\t\t";
            cin >> data;
            Moive* m = NULL;
            // 创建新的Moive对象，并将其指针保存到新数组newspace的适当位置。
            m = new Moive(no, name, types, nation, actor, data, grade, sum, num);
            newspace[this->m_MoiNum + i] = m;
        }

        delete[] this->m_MoiArray;   // 释放原有的空间
        this->m_MoiArray = newspace; // 更改新空间的指向
        this->m_MoiNum = newsize;    // 更新电影数
        cout << "\t\t\t 成功添加" << addnum << "个新电影" << endl;
        this->m_save(); // 保存数据到文件中
    }
}

// 实现了mManager类的成员函数get_moinum()，用于获取电影总数。
int mManager::get_moinum()
{ // 电影总数
    ifstream ifs;
    ifs.open(mFILENAME, ios::in); // 打开mFILENAME文件
    int no;
    string name;
    string types;
    string nation;
    string star;
    int time;
    double grade;
    double sum;
    int num;
    int count = 0; // 定义变量和计数器

    // 使用循环，从文件中按顺序读取电影数据。每次循环读取一行数据，并将相应的值赋给对应的变量 以空格为判断标准
    while (ifs >> no && ifs >> name && ifs >> types && ifs >> nation && ifs >> star && ifs >> time && ifs >> grade && ifs >> sum && ifs >> num)
    {
        count++;
    }
    return count;
}

// 实现了mManager类的成员函数m_save()，用于将电影数据保存到文件中
void mManager::m_save()
{ // 保存数据（将电影写入文件中）
    ofstream ofs;
    ofs.open(mFILENAME, ios::out); // 写入模式

    for (int i = 0; i < this->m_MoiNum; i++)
    {
        ofs << this->m_MoiArray[i]->m_no << " "
            << this->m_MoiArray[i]->m_name << " "
            << this->m_MoiArray[i]->m_types << " "
            << this->m_MoiArray[i]->m_nation << " "
            << this->m_MoiArray[i]->m_actor << " "
            << this->m_MoiArray[i]->m_data << " "
            //<< this->m_MoiArray[i]->m_grade << " "
            << this->m_MoiArray[i]->m_sum / this->m_MoiArray[i]->m_num << " "
            << this->m_MoiArray[i]->m_sum << " "
            << this->m_MoiArray[i]->m_num << endl;
    }
    ofs.close(); // 关闭文件
}

// 实现了mManager类的成员函数init_moi()，用于从文件中读取电影数据并更新到电影数组中。
void mManager::init_moi()
{ // 更新电影数据
    ifstream ifs;
    ifs.open(mFILENAME, ios::in);
    int no;
    int data;
    string name;
    string types;
    string nation;
    string actor;
    double grade;
    double sum = 0;
    int num = 0;
    int index = 0;
    // 循环读取数据
    while (ifs >> no && ifs >> name && ifs >> types && ifs >> nation && ifs >> actor && ifs >> data && ifs >> grade && ifs >> sum && ifs >> num)
    {
        Moive* m = NULL;
        m = new Moive(no, name, types, nation, actor, data, grade, sum, num);
        this->m_MoiArray[index] = m; // 保存在数组中
        index++;
    }
    ifs.close();
}

// 实现了mManager类的成员函数show_moi()，用于显示所有电影的信息
void mManager::show_moi()
{
    for (int i = 0; i < this->m_MoiNum; i++)
    {
        this->m_MoiArray[i]->showinfo();
    }
}

// 定义了mManager类的成员函数table()，用于输出电影信息的表格标题。
void mManager::table()
{
    cout << setw(16) << setiosflags(ios::left) << setfill(' ') << "编号"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "名称"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "类型"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "国家"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "主演"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "时长（分钟）"
       // << setw(16) << setiosflags(ios::left) << setfill(' ') << "综合得分"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "总加权得分"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "平均得分"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "评分次数" << endl;
}
// 删除电影
void mManager::del_moi()
{
    if (this->fileisempt)
    {
        cout << "\t\t\t ERROR! 文件为空！" << endl;
    }
    else
    {
        cout << "\t\t\t 请输入你想要删除电影的名称:" << endl;
        cout << "\t\t\t";
        string name;
        cin >> name;
        int index = this->is_exist(name); // 调用is_exist()函数查找电影名称在数组中的索引
        if (index != -1)
        {
            for (int i = index; i < this->m_MoiNum - 1; i++)
            {
                this->m_MoiArray[i] = this->m_MoiArray[i + 1];
            }
            this->m_MoiNum--; // 更新电影数量
            this->m_save();   // 调用m_save()函数将更新后的电影信息保存到文件中。
            cout << "\t\t\t ERROR 删除成功！" << endl;
        }
        else
        {
            cout << "\t\t\t ERROR! 删除失败，未找到该电影！" << endl;
        }
    }
}

// 判断该电影是否存在(传入电影信息名称，国籍，类型)
int mManager::is_exist(string m)
{
    int index = -1;
    for (int i = 0; i < this->m_MoiNum; i++)
    {
        if (this->m_MoiArray[i]->m_name == m ||
            this->m_MoiArray[i]->m_nation == m ||
            this->m_MoiArray[i]->m_types == m)
        {
            index = this->m_MoiArray[i]->m_no;
            break;
        }
    }
    return index;
}
// 定义updata_moi成员函数，用于更改电影信息（名称、编号）
// 这个实现必须一次修改全部信息，不能完成对某一项单独修改的操作
void mManager::updata_moi()
{
    if (this->fileisempt)
    {
        cout << "\t\t\t ERROR 文件为空!" << endl;
    }
    else
    {
        cout << "\t\t\t你要选择更改电影名称:" << endl;
        cout << "\t\t\t";
        string n;
        cin >> n;
        int index = this->is_exist(n) - 1; // 调用is_exist()函数查找电影名称在数组中的索引 （-1 是因为数组索引是从0开始）

        if (index != -2)
        {
            int no;
            string name;
            string types;
            string nation;
            string actor;
            int data;
            cout << "\t\t\t请输入更改后的编号" << endl;
            cout << "\t\t\t";
            cin >> no;
            cout << "\t\t\t请输入更改后的电影名称" << endl;
            cout << "\t\t\t";
            cin >> name;
            cout << "\t\t\t请输入更改后的类型" << endl;
            cout << "\t\t\t";
            cin >> types;
            cout << "\t\t\t请输入更改后的国籍" << endl;
            cout << "\t\t\t";
            cin >> nation;
            cout << "\t\t\t请输入更改后的主演" << endl;
            cout << "\t\t\t";
            cin >> actor;
            cout << "\t\t\t请输入更改后的时长" << endl;
            cout << "\t\t\t";
            cin >> data;
            this->m_MoiArray[index]->m_no = no;
            this->m_MoiArray[index]->m_name = name;
            this->m_MoiArray[index]->m_types = types;
            this->m_MoiArray[index]->m_nation = nation;
            this->m_MoiArray[index]->m_actor = actor;
            this->m_MoiArray[index]->m_data = data;
            this->m_save(); // 更新数据后，保存到文件中
            cout << "\t\t\t nvn! 信息更改成功!" << endl;
        }
        else
        {
            cout << "\t\t\t ERROR ！你要求更改的用户不存在" << endl;
        }
    }
}

// 定义了mManager类的成员函数sel_moi(string name)，按名称查找电影
void mManager::sel_moi(string name)
{
    int index = -1;
    cout << "\t\t\t 请输入你想要查找的电影的名字：";
    cout << "\t\t\t" << endl;
    while (index == -1)
    {
        cout << "\t\t\t";
        cin >> name; // 3
        // 调用is_exist()函数查找电影名称在数组中的索引，并将结果赋值给index变量。
        index = this->is_exist(name);
        if (index != -1) // 循环遍历电影数组
        {
            for (int i = 0; i < this->m_MoiNum; i++)
            {
                while (this->m_MoiArray[i]->m_name == name)
                {
                    this->table(); // 调用table()函数显示电影表头
                    this->m_MoiArray[i]->showinfo();
                    break;
                }
            }
        }
        else
        {
            cout << "\t\t\t ERROR! 你查找的电影不存在，请重新输入:" << endl;
            continue; // 回到第3步继续让收用户输入的电影名称。
        }
    }
}

// 用户给电影评分
void mManager::gra_moi()
{
    int index = 0;
    string name;
    while (index == 0)
    {
        cout << "\t\t\t 请输入你想评分的电影的名字" << endl;
        cout << "\t\t\t";
        cin >> name;
        index = this->is_exist(name); // 调用is_exist()函数查找电影名称在数组中的索引
        while (index != -1)
        {
            double a, b, c, d;
            double score = 0.0;
            cout << "\t\t\t 请给电影打分，各板块0-10分:" << endl;
            cout << "\t\t\t剧情流畅度:";
            cin >> a;
            cout << "\t\t\t画面表现：";
            cin >> b;
            cout << "\t\t\t演员表演:";
            cin >> c;
            cout << "\t\t\t整体音乐:";
            cin >> d;
            for (int i = 0; i < this->m_MoiNum; i++) // 遍历电影数组
{
    while (this->m_MoiArray[i]->m_no == this->is_exist(name)) // index = this->is_exist(name);
    {
        if (this->m_MoiArray[i]->m_grade == 0) // 没有评分过
        {
            this->m_MoiArray[i]->m_num++; // 评分次数+1
            this->m_MoiArray[i]->m_grade = score;
        }
        else
        {
            this->m_MoiArray[i]->m_num++; // 评分次数+1
            this->m_MoiArray[i]->m_grade = ((this->m_MoiArray[i]->score_movie(a, b, c, d) + 
                this->m_MoiArray[i]->m_sum) / 
                this->m_MoiArray[i]->m_num);
        }
        this->m_MoiArray[i]->m_sum = this->m_MoiArray[i]->m_sum + this->m_MoiArray[i]->score_movie(a, b, c, d);
        i++; // 更新索引i的值，以继续遍历下一个元素
        break;
    }
}


            /*for (int i = 0; i < this->m_MoiNum; i++) // 遍历电影数组
            {
                while (this->m_MoiArray[i]->m_no == this->is_exist(name)) // index = this->is_exist(name);
                {
                    if (this->m_MoiArray[i]->m_grade == 0) // 没有评分过
                    {
                        this->m_MoiArray[i]->m_num++; // 评分次数+1
                        this->m_MoiArray[i]->m_grade = score;
                    }
                    else
                    {
                        this->m_MoiArray[i]->m_num++; // 评分次数+1
                        this->m_MoiArray[i]->m_grade = (this->m_MoiArray[i]->score_movie(a, b, c, d) + this->m_MoiArray[i]->m_sum) / this->m_MoiArray[i]->m_num;
                    }
                    this->m_MoiArray[i]->m_sum = this->m_MoiArray[i]->m_sum + this->m_MoiArray[i]->score_movie(a, b, c, d);
                    break;
                }
            }*/
            // 保存数据
            score = this->m_MoiArray[index]->score_movie(a, b, c, d);
            cout << "\t\t\t";
            cout << "你给电影" << name << "的评分为：" << score << endl;
            cout << "\t\t\t";
            //cout << "电影" << name << "上一次的评分为" << this->m_MoiArray[index]->m_grade;

            cout << "\t\t\t" << endl;
            cout << "\t\t\t  评分成功 ！" << endl;
            this->m_save();
            system("pause"); // 输出评分成功的提示信息，暂停程序的执行
            return;
        }
        cout << "\t\t\t ERROR！ 找不到你要评分的电影" << endl;
        break;
    }
}

// 按类型查找电影
void mManager::sel_type()
{
    string type;
    cout << "\t\t\t 请输入你要查找的电影类型:";
    cout << "\t\t\t" << endl;
    int index = -1;
    while (index == -1)
    {
        cout << "\t\t\t";
        cin >> type;
        index = this->is_exist(type); // 调用is_exist()函数查找电影类型在数组中的索引
        if (index != -1)
        {
            this->table(); // 打印电影表头
            // 遍历电影数组并显示与指定类型匹配的电影信息。
            for (int i = 0; i < this->m_MoiNum; i++)
            {
                while (this->m_MoiArray[i]->m_types == type)
                {

                    this->m_MoiArray[i]->showinfo();
                    break;
                }
            }
        }
        else
        {
            cout << "\t\t\t ERROR！ 你查找的电影类都没有，请重新输入:" << endl;
            continue;
        }
    }
}
// 按国家查找
void mManager::sel_nat()
{
    string nation;
    cout << "\t\t\t 请输入你要查找的电影国家:";
    cout << endl;
    int index = -1;
    while (index == -1)
    {
        cin >> nation;
        index = this->is_exist(nation); // 查找在国家数组中的所有
        if (index != -1)
        {
            this->table();
            // 遍历电影数组并显示与指定类型匹配的电影信息。
            for (int i = 0; i < this->m_MoiNum; i++)
            {
                while (this->m_MoiArray[i]->m_nation == nation)
                {
                    this->m_MoiArray[i]->showinfo();
                    break;
                }
            }
        }
        else
        {
            cout << "\t\t\t ERROR m你查找的电影国籍，请重新输入:" << endl;
            continue;
        }
    }
}

mManager::~mManager() {} // 是电影管理类的析构函数，销毁时自动调用，用于清理对象所占用的资源和执行必要的清理操作。
