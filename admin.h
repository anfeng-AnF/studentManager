//������չ��ͬ�����û��Գɼ�����ϵͳ�Ĳ�ͬ��������ɲ�ͬ�����û����༰���Ա����
//����һ��admin�Ĵ������

#pragma once
#include"StudentManager.h"
class Admin :public StudentManager
{
public:
	Admin(int _pwd, string _userName) :pwd(_pwd), userName(_userName) {}

	void initMenu()override;		//��ʾ�˵�

	void showAllInfo();				//�鿴����ѧ����Ϣ

	void addStuInfo();				//���ѧ����Ϣ

private:

	int pwd;			//����Ա����
	string userName;	//����Ա�û���

	void initData();	//��ʼ������

	void showMenu();
};

