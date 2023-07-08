// 对用户和管理员信息的管理

#include "pManager.h"
#include "person.h"
#include "manager.h"
#include "user.h"
#include "moive.h"
#include "iomanip"

//pManager 类的构造函数的实现,初始化 pManager 对象时，检查文件是否存在，如果文件不存在，则对对象的属性进行适当的初始化
pManager::pManager()
{ // 初始化属性
    // 1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 读文件
    if (!ifs.is_open())
    {
        cout << "\t\t\t ERROR！ 文件不存在！" << endl;
        // 初始化属性
        this->m_PerNum = 0;
        this->m_PerArray = NULL;
        this->fileisempt = true;
        ifs.close();
        return;
    }

    // 2.文件存在，但无数据
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "\t\t\t ERROR！ 文件数据为空！" << endl;
        // 初始化属性
        this->m_PerNum = 0;
        this->m_PerArray = NULL;
        this->fileisempt = true;
        ifs.close();
        return;
    }

    // 3.文件存在，且数据也存在
    int num = this->get_pernum();
    this->m_PerNum = num;                          // 更新人数
    this->fileisempt = false;                      // 更新文件为不空标志
    this->m_PerArray = new User * [this->m_PerNum]; // 将文件放入数组
    this->init_per();                              // 更新数据
}

void pManager::show_Menu()
{ // 登录菜单

    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|          欢迎使用电影评分系统        |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|----powered by Jiangjunferng 2023-----|\n";
    cout << "\t\t\t\t|——————————————————————————————————————|\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              1.用 户 登 录           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              2.管 理 员 登 录        |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              0.退 出 系 统           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << endl;
}

void pManager::exit_Menu()
{ // 退出系统
    cout << "\t\t\t  欢迎您的下次使用！" << endl;
    system("pause");
    exit(0);
}

void pManager::user_face()
{ // 用户登录成功界面

    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|                用户系统              |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|----powered by Jiangjunferng 2023-----|\n";
    cout << "\t\t\t\t|——————————————————————————————————————|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|              1.搜 索 电 影           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              2.电 影 评 分           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              3.查 看 评 阅 记 录     |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              4.返 回 主  界 面       |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              0.退 出 系 统           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << endl;
}

void pManager::sel_face()
{ // 用户搜索电影界面

    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|                搜索系统              |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|----powered by Jiangjunferng 2023-----|\n";
    cout << "\t\t\t\t|——————————————————————————————————————|\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              1.名 称 搜 查           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              2.类 型 搜 索           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              3.国 家 搜 索           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              4.返 回 上 个 界 面     |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              0.退 出 系 统           |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << endl;
}

void pManager::manage_face()
{ // 管理登录成功界面

    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|                信息管理系            |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|----powered by Jiangjunferng 2023-----|\n";
    cout << "\t\t\t\t|——————————————————————————————————————|\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              1.显示所有用户信息      |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              2.增加用户              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              3.删除用户              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              4.修改用户              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              5.显示所有电影信息      |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              6.增加电影              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              7.删除电影              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              8.修改电影              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              9.上一界面              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              0.退出系统              |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << endl;
}

void pManager::home_page()
{
    cout << "\t\t\t\t ---------------------------------------------- " << endl;
    cout << "\t\t\t\t|                 注册或者登录                 |" << endl;
    cout << "\t\t\t\t|----------powered by Jiangjunferng 2023-------|\n";
    cout << "\t\t\t\t|----------------------------------------------| " << endl;
    cout << "\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t|                  1. 登 录                    |" << endl;
    cout << "\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t|                  2. 注 册                    |" << endl;
    cout << "\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t -----------------------------------------------" << endl;
    cout << "\t\t\t";
}
void pManager::add_user()
{ // 管理员增加用户
    cout << "\t\t\t 请输入增加用户数量" << endl;
    cout << "\t\t\t";
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0)
    {
        //创建一个新的数组 newspace，大小为 m_PerNum + addnum，用于存储新增加的用中
        int newsize = this->m_PerNum + addnum;
        User** newspace = new User * [newsize];

        //如果原来的用户数组 m_PerArray 不为空，将原有用户的指针复制到 newspace 中
        if (this->m_PerArray != NULL)
        {
            for (int i = 0; i < this->m_PerNum; i++)
            {
                newspace[i] = this->m_PerArray[i];
            }
        }

        for (int i = 0; i < addnum; i++) // 通过循环添加新的数据
        {
            int no;
            string name;
            string access = "用户";
            cout << "\t\t\t第" << i + 1 << "个用户编号" << endl;
            cout << "\t\t\t";
            while (cin >> no)
            {
                int adjust = 0;
                for (int j = 0; j < this->m_PerNum; j++)
                {
                    if (this->m_PerArray[j]->p_no == no)
                    {
                        cout << "\t\t\t ERROR! 此编号已存在!请重新输入" << endl;
                        adjust = 1;
                    }
                }
                if (adjust == 0)
                {
                    break;
                }
            }
            cout << "\t\t\t第" << i + 1 << "个用户的姓名:" << endl;
            cout << "\t\t\t";
            cin >> name;
            User* u = NULL;
            u = new User(no, name, access);
            newspace[this->m_PerNum + i] = u; // 将创建的用户指针，保存到数组中
        }

        delete[] this->m_PerArray;   // 释放原有的空间
        this->m_PerArray = newspace; // 更改新空间的指向
        this->m_PerNum = newsize;    // 更新用户人数
        cout << "\t\t\t  成功添加" << addnum << "个新用户" << endl;
        this->p_save(); // 保存数据到文件中
    }
    else
    {
        cout << "\t\t\t ERROR! 输入数量无效，添加失败！" << endl;
    }
}

void pManager::p_save()
{ // 保存数据
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 写文件（将数据写入文件中）

    for (int i = 0; i < this->m_PerNum; i++)
    {
        // 将每个用户的信息写入文件中，每个用户的信息占据一行
        ofs << this->m_PerArray[i]->p_no << " "
            << this->m_PerArray[i]->p_name << " "
            << this->m_PerArray[i]->p_access << endl;
    }
    ofs.close(); // 关闭文件流，完成数据的保存
}

int pManager::get_pernum()
{ // 获得人数
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int no;
    string name;
    string access;
    int count = 0;
    while (ifs >> no && ifs >> name && ifs >> access)//使用输入操作符 >>每次读取一行
    {
        count++;
    }
    return count;
}

void pManager::init_per()
{ // 更新人员信息
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 读文件
    int no;
    string name;
    string access;
    int index = 0;
    while (ifs >> no && ifs >> name && ifs >> access)
    {
        User* u = NULL;//声明了一个名为 u 的指针变量，类型为 User*，并将其初始化为 NULL。
        u = new User(no, name, access);
        //将创建的 User 对象指针 u 保存到 m_PerArray 数组的相应位置
        this->m_PerArray[index] = u; // 保存在数组中，通过 index 变量确定位置
        index++; //当前数组的末位索引加1
    }
    ifs.close();
}

void pManager::show_per()
{ // 展示所有人员
    for (int i = 0; i < this->m_PerNum; i++)
    {
        cout << "\t\t\t";
        this->m_PerArray[i]->showinfo(); //this->m_PerArray[i]：访问到当前位置的人员对象指针，然后，调用 showinfo() 函数来显示该人员对象的信息。
    }
}
void pManager::table()
{ // 展示所有人表头
    cout << "\t\t\t";
    //通过使用 setw()、setiosflags() 和 setfill() 等控制输出格式的函数，对每个列名进行格式化处理。其中，setw(16) 设置每个列的宽度为 16，setiosflags(ios::left) 设置对齐方式为左对齐，setfill(' ') 设置填充字符为空格。
    cout << setw(16) << setiosflags(ios::left) << setfill(' ') << "编号" << setw(16) << setiosflags(ios::left) << setfill(' ') << "姓名" << setw(16) << setiosflags(ios::left) << setfill(' ') << "权限" << endl;
}

int pManager::is_exist(int no)
{ // 通过编号判断是否存在该用户
    int index = -1;
    for (int i = 0; i < this->m_PerNum; i++)
    {
        //将第 i 个用户对象 的 编号与传入的编号进行比较，判断它们是否相等
        if (this->m_PerArray[i]->p_no == no)
        {
            index = i;//设置索引
            break;
        }
    }
    return index;
}

void pManager::del_per()
{ // 删除人员
    if (this->fileisempt)//
    {
        cout << "\t\t\t ERROR! 文件为空" << endl;
    }
    else
    {
        cout << "\t\t\t  请输入你想删除的用户编号:" << endl;
        int no = 0;
        cout << "\t\t\t";
        cin >> no;
        int index = this->is_exist(no); // 判断需要删除的人员是否存在
        if (index != -1)
        {
            //从索引位置 index 开始，将数组中该位置之后的元素向前移动一位，覆盖需要删除的人员对象，实现删除操作。
            for (int i = index; i < this->m_PerNum - 1; i++)
            {
                this->m_PerArray[i] = this->m_PerArray[i + 1];
            }
            this->m_PerNum--; // 更新人员数量
            this->p_save();
            cout << "\t\t\t 删除成功！" << endl;
        }
        else
        {
            cout << "\t\t\t ERROR! 删除失败，未找到该用户！" << endl;
        }
    }
}

void pManager::updata_per()
{ // 修改人员信息
    if (this->fileisempt)
    {
        cout << "\t\t\t ERROR! 文件为空！" << endl;
    }
    else
    {
        cout << "\t\t\t 你要选择更改用户的编号:" << endl;
        cout << "\t\t\t";
        int no = 0;
        cin >> no;
        //this-> 是一个指向当前对象的指针，this-> 来引用当前对象的成员变量或成员函数
        int index = this->is_exist(no);//调用 is_exist() 函数来查找与给定编号匹配的用户
        if (index != -1)
        {
            int newNo;
            string name;
            string access;
            cout << "\t\t\t  请输入更改后的编号：" << endl;
            cout << "\t\t\t";
            cin >> newNo;
            cout << "\t\t\t  请输入更改后的名字：" << endl;
            cout << "\t\t\t";
            cin >> name;
            cout << "\t\t\t  请输入更改的权限：" << endl;
            cout << "\t\t\t";
            cin >> access;
            this->m_PerArray[index]->p_name = name;
            this->m_PerArray[index]->p_access = access;

            this->p_save();
            cout << "\t\t\t  信息更改成功!" << endl;
        }
        else
        {
            cout << "\t\t\t ERROR! 修改失败，未找到该用户!" << endl;
        }
    }
}

void pManager::user_log()
{ // 用户登录
    string name;
    string password;
    while (true)
    {
        cout << "\t\t\t  请输入你的名字" << endl;
        cout << "\t\t\t";
        cin >> name;
        cout << "\t\t\t请输入你的密码:" << endl;
        cout << "\t\t\t";
        cin >> password;
        for (int i = 0; i < this->m_PerNum; i++)
        {
            while (1)
            {

                cout << "\t\t\t  登录成功，欢迎你" + name + "!!!" << endl;
               
                system("pause");
                system("cls");
                return;
            }
        }
       
    }
}
/*
void pManager::user_log()
{ // 用户登录

    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|          欢迎使用电影评分系统        |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|----powered by Jiangjunferng 2023-----|\n";
    cout << "\t\t\t\t|——————————————————————————————————————|\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              1. 登 录                |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|              2. 注 册                |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|                                      |\t\n";
    cout << "\t\t\t\t|--------------------------------------|\n";
    cout << endl;

    int choice;
    string name;
    int password;
    cin >> choice;
    switch (choice)
    {

    case 1:
        while (true)
        {

            cout << "\t\t\t  请输入你的名字" << endl;
            cout << "\t\t\t";
            cin >> name;
            cout << "\t\t\t";
            cout << "请输入你的密码:" << endl;
            cout << "\t\t\t";
            cin >> password;
            for (int i = 0; i < this->m_PerNum; i++)
            {
                while (1)
                {
                    cout << "\t\t\t  登录成功，欢迎你" + name + "!!!" << endl;

                    system("pause");
                    system("cls");
                   break;
                } 
                break;
            }

        }
    case 2:
        while (true)
        {

            cout << "\t\t\t  请输入你的名字" << endl;
            cout << "\t\t\t";
            cin >> name;
            cout << "\t\t\t";
            cout << "请输入你的密码:" << endl;
            cout << "\t\t\t";
            cin >> password;
            for (int i = 0; i < this->m_PerNum; i++)
            {
                while (1)
                {
                    cout << "\t\t\t  登录成功，欢迎你" + name + "!!!" << endl;

                    system("pause");
                    system("cls");
                    break;
                }
                break;
            }

        }

    }
    system("pause");
    system("cls");
    return;
}
*/

void pManager::manager_log()
{ // 管理员登录
    int password = 0;
    string name;
    while (true)
    {
        cout << "\t\t\t 请输入你要登录的名字:" << endl;
        cout << "\t\t\t";
        cin >> name;
        cout << "\t\t\t 请输入你要登录的密码:" << endl;
        cout << "\t\t\t";
        cin >> password;
        if (password == 114514)
        {
            cout << "\t\t\t 登录成功，欢迎你" + name + "!!!" << endl;
            system("pause");
            system("cls");
            return;
        }
        else
        {
            cout << "\t\t\t ERROR! 你输入的信息有误，请重新输入!" << endl;
        }
    }
    
}

pManager::~pManager()
{ // 释放堆区数据
}