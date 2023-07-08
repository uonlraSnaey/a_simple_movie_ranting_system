#include <iostream>
#include "pManager.h"
#include "mManager.h"
#include "manager.h"
#include "user.h"
#include <iomanip>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main() {
	pManager pm;//
	mManager mm;
	int choice;
	int ci = 0;
	string name;
	int loading = 7;

	string getTime();
	while (loading--)  // nvn
	{
		system("cls");
		cout << "\t\t\t\t------------���ڽ���ϵͳ�����Ե�-----------" << endl << endl;
		cout << "\t\t\t\t-----------------------------------------" << endl;
		cout << "\t\t\t\t";
		for (int i = 0; i < loading; i++)
		{
			cout << ">>>>>";
			Sleep(100);
		}
		cout << endl; 
		system("cls");
	}
	while (true)
	{
		pm.show_Menu();
		cout << "\t\t\tѡ��������:" << endl;
		cout << "\t\t\t";
		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			pm.exit_Menu();
			break;

		case 1:

			int log;
			pm.home_page();
			cin >> log;
			switch (log)
			{
			case 1: 
			pm.user_log();//�û���¼
			while (true)
			{
				pm.user_face();//��¼�ɹ����û��˵���
				cout << "\t\t\t ���������ѡ��:" << endl;
				cout << "\t\t\t";
				int choice2;
				cin >> choice2;
				system("cls");
				switch (choice2)
				{
				case 0://�˳�ϵͳ
					system("cls");
					pm.exit_Menu();
					break;
				case 1://������Ӱ
					int c;
					while (true)
					{
						pm.sel_face();
						cout << "\t\t\t ����������Ҫ������Ӱ�Ĳ���" << endl;
						cout << "\t\t\t";
						cin >> c;
						if (c == 4)
						{
							break;
						}
						switch (c)
						{
						case 1:
							mm.sel_moi(name);//����������
							system("pause");
							system("cls");
							break;
						case 2:
							mm.sel_type();//����������
							system("pause");
							system("cls");
							break;
						case 3:
							mm.sel_nat();//����������
							system("pause");
							system("cls");
							break;
						case 0:
							system("cls");
							pm.exit_Menu();
							return 0;
						default:
							system("cls");
							break;
						}
					}
					system("cls");
					continue;
				case 2://��Ӱ���
				{
					mm.table();
					mm.show_moi();
					mm.gra_moi();
					system("cls");
					ci++;
					continue;
				}

				case 3://�鿴���ļ�¼
				{
					
					time_t now = time(0);
					char* getTime = ctime(&now);

					if (ci != 0)
					{

						cout << "\t\t\t\t ---------------------------------------------- " << endl;
						cout << "\t\t\t\t|                                               |" << endl;
						cout << "\t\t\t\t|        �ϴ�����ʱ��Ϊ" << getTime<< "|" << endl;
						cout << "\t\t\t\t|                                               |" << endl;
						cout << "\t\t\t\t|                                               |" << endl;
						cout << "\t\t\t\t|                  ���Ĵ���Ϊ��          "<<ci<<"      |" << endl;
						cout << "\t\t\t\t -----------------------------------------------" << endl;
					}
					else
					{
						cout << "\t\t\t\t ---------------------------------------------- " << endl;
						cout << "\t\t\t\t|                                               |" << endl;
						cout << "\t\t\t\t|        ��ʱû�и��û���������Ϣ               |" << endl;
						cout << "\t\t\t\t|                                               |" << endl;
						cout << "\t\t\t\t -----------------------------------------------" << endl;
					}
					system("pause");
					system("cls");
					continue;
				}

				case 4://���ؽ���
					system("cls");
					break;
				default:
					system("cls");
					break;
				}
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			continue;
			case 2:
				pm.add_user();
				log = 1;
				system("cls");
				system("pause");
				continue;
			}
			break;
		case 2://����Ա��¼
			pm.manager_log();
			while (true)
			{
				pm.manage_face();
				cout << "\t\t\t ���������ѡ��:" << endl;
				cout << "\t\t\t";
				int choice3;
				cin >> choice3;
				if (choice3 == 9)
				{
					break;
				}
				switch (choice3)
				{
				case 1:
					pm.table();
					pm.show_per();
					system("pause");
					break;
				case 2:
					pm.add_user();
					system("pause");
					break;
				case 3:
				     pm.del_per();//ɾ���û�
					system("pause");
					break;
				case 4:
					pm.updata_per();//�޸��û�
					system("pause");
					break;
				case 5:
					mm.table();//��ӡ��Ӱ��ͷ
					mm.show_moi();
					system("pause");
					break;
				case 6:
					mm.add_moive();//��ӵ�Ӱ
					system("pause");
					break;
				case 7:
					mm.del_moi();//ɾ����Ӱ
					system("pause");
					break;
				case 8:
					mm.table();
					mm.show_moi();
					mm.updata_moi();//�ĵ�Ӱ
					system("pause");
					system("cls");
					break;
				default:
					system("cls");
					return 0;
				}
				system("cls");
				
			}
		

		default:
			system("cls");
			break;
		}	
	}
	system("pause");
}

