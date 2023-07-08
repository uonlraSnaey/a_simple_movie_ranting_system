// �Ե�Ӱ��Ϣ�Ĺ���

#include "manager.h"
#include "manager.h"
#include "user.h"
#include "iomanip"
#include "moive.h"
#include "mManager.h"

mManager::mManager()
{ // ��ʼ������

    // ʹ��ifstream����ifs����ΪmFILENAME���ļ�
    ifstream ifs;
    ifs.open(mFILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "\t\t\t ERROR! �ļ������ڣ�" << endl;
        // ���г�ʼ��������Ӱ����m_MoiNum��Ϊ0������Ӱ����m_MoiArray��ΪNULL������fileisempt��־��Ϊtrue
        this->m_MoiNum = 0;
        this->m_MoiArray = NULL;
        this->fileisempt = true;
        ifs.close();
        return;
    }
    int num = this->get_moinum(); // ȡ��Ӱ������ʹ�ó�Ա����get_moinum()��ȡ��Ӱ�����������丳ֵ��m_MoiNum��
    this->m_MoiNum = num;
    this->m_MoiArray = new Moive * [this->m_MoiNum]; // �����Ӱ�����ڴ棬���ļ���������
    this->init_moi();                               // ���ó�Ա����init_moi()�����ļ��ж�ȡ��Ӱ���ݣ��������ݸ���
}

// ʵ����mManager��ĳ�Ա����add_moive()���������ӵ�Ӱ��
void mManager::add_moive()
{
    cout << "\t\t\t �����뽫Ҫ���ӵ�Ӱ������" << endl;
    cout << "\t\t\t";
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0)
    {
        int newsize = this->m_MoiNum + addnum; // �����µĵ�Ӱ����ռ�
        Moive** newspace = new Moive * [newsize];
        if (this->m_MoiArray != NULL) // ԭ��Ӱ���鲻Ϊ�գ�����ԭ�����ݵ�������
        {
            for (int i = 0; i < this->m_MoiNum; i++)
            {
                newspace[i] = this->m_MoiArray[i];
            }
        }
        for (int i = 0; i < addnum; i++) // ѭ����������µ�����
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
            cout << "\t\t\t��" << i + 1 << "����Ӱ���" << endl;
            cout << "\t\t\t";
            while (cin >> no)
            {
                int adjust = 0;
                for (int j = 0; j < this->m_MoiNum; j++)
                {
                    if (no == this->m_MoiArray[j]->m_no)
                    {
                        cout << "\t\t\t ERROR! �˵�Ӱ����Ѵ��� ����������" << endl;
                        adjust = 1;
                    }
                }
                if (adjust == 0)
                {
                    break;
                }
            }
            cout << "\t\t\t��" << i + 1 << "����Ӱ������:" << endl;
            cout << "\t\t\t";
            while (cin >> name)
            {
                int adjust = 0;
                for (int j = 0; j < this->m_MoiNum; j++)
                {
                    if (name == this->m_MoiArray[j]->m_name)
                    {
                        cout << "\t\t\t ERROR! �˵�Ӱ�Ѵ��� ����������" << endl;
                        adjust = 1;
                    }
                }
                if (adjust == 0)
                {
                    break;
                }
            }
            cout << "\t\t\t�������Ӱ������:" << endl;
            cout << "\t\t\t";
            cin >> types;
            cout << "\t\t\t�������Ӱ�Ĺ���:" << endl;
            cout << "\t\t\t";
            cin >> nation;
            cout << "\t\t\t�������Ӱ������:" << endl;
            cout << "\t\t\t";
            cin >> actor;
            cout << "\t\t\t�������Ӱ��ʱ��:" << endl;
            cout << "\t\t\t";
            cin >> data;
            Moive* m = NULL;
            // �����µ�Moive���󣬲�����ָ�뱣�浽������newspace���ʵ�λ�á�
            m = new Moive(no, name, types, nation, actor, data, grade, sum, num);
            newspace[this->m_MoiNum + i] = m;
        }

        delete[] this->m_MoiArray;   // �ͷ�ԭ�еĿռ�
        this->m_MoiArray = newspace; // �����¿ռ��ָ��
        this->m_MoiNum = newsize;    // ���µ�Ӱ��
        cout << "\t\t\t �ɹ����" << addnum << "���µ�Ӱ" << endl;
        this->m_save(); // �������ݵ��ļ���
    }
}

// ʵ����mManager��ĳ�Ա����get_moinum()�����ڻ�ȡ��Ӱ������
int mManager::get_moinum()
{ // ��Ӱ����
    ifstream ifs;
    ifs.open(mFILENAME, ios::in); // ��mFILENAME�ļ�
    int no;
    string name;
    string types;
    string nation;
    string star;
    int time;
    double grade;
    double sum;
    int num;
    int count = 0; // ��������ͼ�����

    // ʹ��ѭ�������ļ��а�˳���ȡ��Ӱ���ݡ�ÿ��ѭ����ȡһ�����ݣ�������Ӧ��ֵ������Ӧ�ı��� �Կո�Ϊ�жϱ�׼
    while (ifs >> no && ifs >> name && ifs >> types && ifs >> nation && ifs >> star && ifs >> time && ifs >> grade && ifs >> sum && ifs >> num)
    {
        count++;
    }
    return count;
}

// ʵ����mManager��ĳ�Ա����m_save()�����ڽ���Ӱ���ݱ��浽�ļ���
void mManager::m_save()
{ // �������ݣ�����Ӱд���ļ��У�
    ofstream ofs;
    ofs.open(mFILENAME, ios::out); // д��ģʽ

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
    ofs.close(); // �ر��ļ�
}

// ʵ����mManager��ĳ�Ա����init_moi()�����ڴ��ļ��ж�ȡ��Ӱ���ݲ����µ���Ӱ�����С�
void mManager::init_moi()
{ // ���µ�Ӱ����
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
    // ѭ����ȡ����
    while (ifs >> no && ifs >> name && ifs >> types && ifs >> nation && ifs >> actor && ifs >> data && ifs >> grade && ifs >> sum && ifs >> num)
    {
        Moive* m = NULL;
        m = new Moive(no, name, types, nation, actor, data, grade, sum, num);
        this->m_MoiArray[index] = m; // ������������
        index++;
    }
    ifs.close();
}

// ʵ����mManager��ĳ�Ա����show_moi()��������ʾ���е�Ӱ����Ϣ
void mManager::show_moi()
{
    for (int i = 0; i < this->m_MoiNum; i++)
    {
        this->m_MoiArray[i]->showinfo();
    }
}

// ������mManager��ĳ�Ա����table()�����������Ӱ��Ϣ�ı����⡣
void mManager::table()
{
    cout << setw(16) << setiosflags(ios::left) << setfill(' ') << "���"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "ʱ�������ӣ�"
       // << setw(16) << setiosflags(ios::left) << setfill(' ') << "�ۺϵ÷�"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "�ܼ�Ȩ�÷�"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "ƽ���÷�"
        << setw(16) << setiosflags(ios::left) << setfill(' ') << "���ִ���" << endl;
}
// ɾ����Ӱ
void mManager::del_moi()
{
    if (this->fileisempt)
    {
        cout << "\t\t\t ERROR! �ļ�Ϊ�գ�" << endl;
    }
    else
    {
        cout << "\t\t\t ����������Ҫɾ����Ӱ������:" << endl;
        cout << "\t\t\t";
        string name;
        cin >> name;
        int index = this->is_exist(name); // ����is_exist()�������ҵ�Ӱ�����������е�����
        if (index != -1)
        {
            for (int i = index; i < this->m_MoiNum - 1; i++)
            {
                this->m_MoiArray[i] = this->m_MoiArray[i + 1];
            }
            this->m_MoiNum--; // ���µ�Ӱ����
            this->m_save();   // ����m_save()���������º�ĵ�Ӱ��Ϣ���浽�ļ��С�
            cout << "\t\t\t ERROR ɾ���ɹ���" << endl;
        }
        else
        {
            cout << "\t\t\t ERROR! ɾ��ʧ�ܣ�δ�ҵ��õ�Ӱ��" << endl;
        }
    }
}

// �жϸõ�Ӱ�Ƿ����(�����Ӱ��Ϣ���ƣ�����������)
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
// ����updata_moi��Ա���������ڸ��ĵ�Ӱ��Ϣ�����ơ���ţ�
// ���ʵ�ֱ���һ���޸�ȫ����Ϣ��������ɶ�ĳһ����޸ĵĲ���
void mManager::updata_moi()
{
    if (this->fileisempt)
    {
        cout << "\t\t\t ERROR �ļ�Ϊ��!" << endl;
    }
    else
    {
        cout << "\t\t\t��Ҫѡ����ĵ�Ӱ����:" << endl;
        cout << "\t\t\t";
        string n;
        cin >> n;
        int index = this->is_exist(n) - 1; // ����is_exist()�������ҵ�Ӱ�����������е����� ��-1 ����Ϊ���������Ǵ�0��ʼ��

        if (index != -2)
        {
            int no;
            string name;
            string types;
            string nation;
            string actor;
            int data;
            cout << "\t\t\t��������ĺ�ı��" << endl;
            cout << "\t\t\t";
            cin >> no;
            cout << "\t\t\t��������ĺ�ĵ�Ӱ����" << endl;
            cout << "\t\t\t";
            cin >> name;
            cout << "\t\t\t��������ĺ������" << endl;
            cout << "\t\t\t";
            cin >> types;
            cout << "\t\t\t��������ĺ�Ĺ���" << endl;
            cout << "\t\t\t";
            cin >> nation;
            cout << "\t\t\t��������ĺ������" << endl;
            cout << "\t\t\t";
            cin >> actor;
            cout << "\t\t\t��������ĺ��ʱ��" << endl;
            cout << "\t\t\t";
            cin >> data;
            this->m_MoiArray[index]->m_no = no;
            this->m_MoiArray[index]->m_name = name;
            this->m_MoiArray[index]->m_types = types;
            this->m_MoiArray[index]->m_nation = nation;
            this->m_MoiArray[index]->m_actor = actor;
            this->m_MoiArray[index]->m_data = data;
            this->m_save(); // �������ݺ󣬱��浽�ļ���
            cout << "\t\t\t nvn! ��Ϣ���ĳɹ�!" << endl;
        }
        else
        {
            cout << "\t\t\t ERROR ����Ҫ����ĵ��û�������" << endl;
        }
    }
}

// ������mManager��ĳ�Ա����sel_moi(string name)�������Ʋ��ҵ�Ӱ
void mManager::sel_moi(string name)
{
    int index = -1;
    cout << "\t\t\t ����������Ҫ���ҵĵ�Ӱ�����֣�";
    cout << "\t\t\t" << endl;
    while (index == -1)
    {
        cout << "\t\t\t";
        cin >> name; // 3
        // ����is_exist()�������ҵ�Ӱ�����������е����������������ֵ��index������
        index = this->is_exist(name);
        if (index != -1) // ѭ��������Ӱ����
        {
            for (int i = 0; i < this->m_MoiNum; i++)
            {
                while (this->m_MoiArray[i]->m_name == name)
                {
                    this->table(); // ����table()������ʾ��Ӱ��ͷ
                    this->m_MoiArray[i]->showinfo();
                    break;
                }
            }
        }
        else
        {
            cout << "\t\t\t ERROR! ����ҵĵ�Ӱ�����ڣ�����������:" << endl;
            continue; // �ص���3�����������û�����ĵ�Ӱ���ơ�
        }
    }
}

// �û�����Ӱ����
void mManager::gra_moi()
{
    int index = 0;
    string name;
    while (index == 0)
    {
        cout << "\t\t\t �������������ֵĵ�Ӱ������" << endl;
        cout << "\t\t\t";
        cin >> name;
        index = this->is_exist(name); // ����is_exist()�������ҵ�Ӱ�����������е�����
        while (index != -1)
        {
            double a, b, c, d;
            double score = 0.0;
            cout << "\t\t\t �����Ӱ��֣������0-10��:" << endl;
            cout << "\t\t\t����������:";
            cin >> a;
            cout << "\t\t\t������֣�";
            cin >> b;
            cout << "\t\t\t��Ա����:";
            cin >> c;
            cout << "\t\t\t��������:";
            cin >> d;
            for (int i = 0; i < this->m_MoiNum; i++) // ������Ӱ����
{
    while (this->m_MoiArray[i]->m_no == this->is_exist(name)) // index = this->is_exist(name);
    {
        if (this->m_MoiArray[i]->m_grade == 0) // û�����ֹ�
        {
            this->m_MoiArray[i]->m_num++; // ���ִ���+1
            this->m_MoiArray[i]->m_grade = score;
        }
        else
        {
            this->m_MoiArray[i]->m_num++; // ���ִ���+1
            this->m_MoiArray[i]->m_grade = ((this->m_MoiArray[i]->score_movie(a, b, c, d) + 
                this->m_MoiArray[i]->m_sum) / 
                this->m_MoiArray[i]->m_num);
        }
        this->m_MoiArray[i]->m_sum = this->m_MoiArray[i]->m_sum + this->m_MoiArray[i]->score_movie(a, b, c, d);
        i++; // ��������i��ֵ���Լ���������һ��Ԫ��
        break;
    }
}


            /*for (int i = 0; i < this->m_MoiNum; i++) // ������Ӱ����
            {
                while (this->m_MoiArray[i]->m_no == this->is_exist(name)) // index = this->is_exist(name);
                {
                    if (this->m_MoiArray[i]->m_grade == 0) // û�����ֹ�
                    {
                        this->m_MoiArray[i]->m_num++; // ���ִ���+1
                        this->m_MoiArray[i]->m_grade = score;
                    }
                    else
                    {
                        this->m_MoiArray[i]->m_num++; // ���ִ���+1
                        this->m_MoiArray[i]->m_grade = (this->m_MoiArray[i]->score_movie(a, b, c, d) + this->m_MoiArray[i]->m_sum) / this->m_MoiArray[i]->m_num;
                    }
                    this->m_MoiArray[i]->m_sum = this->m_MoiArray[i]->m_sum + this->m_MoiArray[i]->score_movie(a, b, c, d);
                    break;
                }
            }*/
            // ��������
            score = this->m_MoiArray[index]->score_movie(a, b, c, d);
            cout << "\t\t\t";
            cout << "�����Ӱ" << name << "������Ϊ��" << score << endl;
            cout << "\t\t\t";
            //cout << "��Ӱ" << name << "��һ�ε�����Ϊ" << this->m_MoiArray[index]->m_grade;

            cout << "\t\t\t" << endl;
            cout << "\t\t\t  ���ֳɹ� ��" << endl;
            this->m_save();
            system("pause"); // ������ֳɹ�����ʾ��Ϣ����ͣ�����ִ��
            return;
        }
        cout << "\t\t\t ERROR�� �Ҳ�����Ҫ���ֵĵ�Ӱ" << endl;
        break;
    }
}

// �����Ͳ��ҵ�Ӱ
void mManager::sel_type()
{
    string type;
    cout << "\t\t\t ��������Ҫ���ҵĵ�Ӱ����:";
    cout << "\t\t\t" << endl;
    int index = -1;
    while (index == -1)
    {
        cout << "\t\t\t";
        cin >> type;
        index = this->is_exist(type); // ����is_exist()�������ҵ�Ӱ�����������е�����
        if (index != -1)
        {
            this->table(); // ��ӡ��Ӱ��ͷ
            // ������Ӱ���鲢��ʾ��ָ������ƥ��ĵ�Ӱ��Ϣ��
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
            cout << "\t\t\t ERROR�� ����ҵĵ�Ӱ�඼û�У�����������:" << endl;
            continue;
        }
    }
}
// �����Ҳ���
void mManager::sel_nat()
{
    string nation;
    cout << "\t\t\t ��������Ҫ���ҵĵ�Ӱ����:";
    cout << endl;
    int index = -1;
    while (index == -1)
    {
        cin >> nation;
        index = this->is_exist(nation); // �����ڹ��������е�����
        if (index != -1)
        {
            this->table();
            // ������Ӱ���鲢��ʾ��ָ������ƥ��ĵ�Ӱ��Ϣ��
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
            cout << "\t\t\t ERROR m����ҵĵ�Ӱ����������������:" << endl;
            continue;
        }
    }
}

mManager::~mManager() {} // �ǵ�Ӱ���������������������ʱ�Զ����ã��������������ռ�õ���Դ��ִ�б�Ҫ�����������
