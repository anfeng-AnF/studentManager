//如需扩展不同类型用户对成绩管理系统的不同操作，完成不同类型用户的类及其成员即可
//这是一个admin的待完成类

#pragma once
#include"StudentManager.h"
class Admin :public StudentManager
{
public:
	Admin(int _pwd, string _userName) :pwd(_pwd), userName(_userName) {}

	void initMenu()override;		//显示菜单

	void showAllInfo();				//查看所有学生信息

	void addStuInfo();				//添加学生信息

	void deleteInfo();				//移除学生信息

	void saveStuInfo();				//保存学生信息

	void changeStuCInfo();			//编辑学生信息

	void clearAllInfo();			//清空所有信息

	void renewAvgScore();			//更新均绩
private:

	int pwd;			//管理员密码
	string userName;	//管理员用户名

	void initData();	//初始化数据

	void showMenu();	//显示菜单界面

	void insereCourseInfo(iter it);//插入学生信息
};

