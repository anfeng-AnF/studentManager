#pragma once
#include"head.h"
#define FILE_NAME "StudentInfo.csv"



//��¼ĳһ��Ŀ�ĳɼ�		�������������
struct CourseInfo
{
	course courseName;			//�γ�����
	float score;				//ѧ���÷�

	int courseID;				//�γ̺�
	string teacherName;			//�γ���ʦ������
	string teacherComment;		//��¼��ʦ����
	
	CourseInfo() :CourseInfo(TotalCourses, -1, -1, "tea name","_tComment") {};						//Ĭ�ϳ�ʼ��Ϊ���Կγ̷���
	CourseInfo(course _cName, float _score, int _cID, string _tName, string _tComment) :
		courseName(_cName), score(_score), courseID(_cID), teacherName(_tName), teacherComment(_tComment) {};

	//���ظ����������������
	friend ostream& operator<<(ostream& os, const CourseInfo& obj) {
		cout << "-----------------------------------------" << endl;
		os << "course name:" << couresNameArr[obj.courseName] << endl;
		os << "score:" << obj.score << endl;
		os << "course ID:" << obj.courseID << endl;
		os << "teacherName:" << obj.teacherName << endl;
		os << "teacherComment:" << obj.teacherComment << endl;
		//cout << "-----------------------------------------" << endl;
		return os;
	}
};


//��¼ѧ����Ϣ		����һ��������
template<typename listType>
class StudentInfo
{
	using scoreList = list<listType>;

	friend class StudentManager;			//������Ԫ�Ա���studentmanager���ж�����й���
private:
	string name;				//ѧ������
	int ID;						//ѧ��
	int age;					//����

	float avgScore=-1;				//����

	scoreList scoresObj;		//��������

public:
	StudentInfo() :StudentInfo("test", -1, -1, scoreList()) {}				//Ĭ�Ϲ���

	StudentInfo(string _name, int _ID, int _age, listType _lt)
		:name(_name), ID(_ID), age(_age), scoresObj(scoreList(_lt)) {}

	StudentInfo(string _name, int _ID, int _age, int length, listType* _Ltype)
		: name(_name), ID(_ID), age(_age), scoresObj(_Ltype, _Ltype + length) {}

	void showList();							//��ʾ�����д洢����Ϣ
};


//ѧ��������
class StudentManager {

protected:
	using student		=	StudentInfo<CourseInfo>;
	using List			=	list<student>;
	using iter			=	list<student>::iterator;
	using iterCoures	=	list<CourseInfo>::iterator;

	List stuList;			//�洢һ��list����

	unordered_map<int, iter> hashMapSumScore;		//����ѧ�ſ��ٲ���ѧ��

public:
	//��ȡһ��Ψһ�Ĺ��������
	static StudentManager& getObject();

	//���ѧ����Ϣ   ��������
	void showInfo();

protected:
	//������Ϣ����
	bool insertStudent(string _name,int _age,int _ID,int length,CourseInfo*arr);		//����1��ѧ����Ϣ
	void insertNStudent(int n,student*arr);												//����n��ѧ����Ϣ
	bool insertCouresinfo(iter target, int n,const CourseInfo* cInfo);						//��targetѧ��д��n�ڿγ���Ϣ

	iter find(int ID);																		//����ID����ѧ�� �Ƽ� o(1)
	iter find(string name);																	//������������ѧ��    o(n) nΪѧ������		
	iterCoures find(int courseID, iter target,iterCoures begin,iterCoures end);				//����������ָ��ѧ���Ŀγ̣����տγ�ID��ѯ
	iterCoures find(course courseName, iter target, iterCoures begin, iterCoures end);		//����ָ��ѧ���Ŀγ̣����տγ����Ʋ�ѯ

	bool deleteStuInfo(int ID, string name);					//ɾ��ָ��ѧ������Ϣ��Ϊ��ֹ���������Ҫͬʱ����id��name

	bool deleteCourseInfo(course courseName, iter target);		//ɾ��ָ��ѧ���Ŀγ���Ϣ ���տγ�����
	bool deleteCourseInfo(int courseID,iter target);			//ɾ��ָ��ѧ���Ŀγ���Ϣ ���տγ�ID

	void saveToFile();											//������д���ļ�
	void getDataFile();											//���ļ��ж�ȡ����

	iter getEnd();							//��ȡĩβ������

	void culaAvgScore(iter target);		//�������

	StudentManager();
	StudentManager(const StudentManager&) = delete;
	StudentManager operator=(const StudentManager&) = delete;

	void cleanAll();					//�������

public:
	//�麯����

	virtual void initMenu();	//��ʼ���˵�
};

template<typename listType>
void StudentInfo<listType>::showList()
{
	for (auto it =this->scoresObj.begin(); it != this->scoresObj.end(); it++) {
		cout << *it << endl;
	}
}
