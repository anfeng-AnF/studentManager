#pragma once
#include"head.h"
#define FILE_NAME "StudentInfo.csv"



//记录某一科目的成绩		链表二层数据域
struct CourseInfo
{
	course courseName;			//课程名称
	float score;				//学生得分

	int courseID;				//课程号
	string teacherName;			//课程老师的姓名
	string teacherComment;		//记录教师评语
	
	CourseInfo() :CourseInfo(TotalCourses, -1, -1, "tea name","_tComment") {};						//默认初始化为测试课程分数
	CourseInfo(course _cName, float _score, int _cID, string _tName, string _tComment) :
		courseName(_cName), score(_score), courseID(_cID), teacherName(_tName), teacherComment(_tComment) {};

	//重载该类的输出左移运算符
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


//记录学生信息		链表一层数据域
template<typename listType>
class StudentInfo
{
	using scoreList = list<listType>;

	friend class StudentManager;			//声明友元以便在studentmanager类中对其进行管理
private:
	string name;				//学生姓名
	int ID;						//学号
	int age;					//年龄

	float avgScore=-1;				//均绩

	scoreList scoresObj;		//二层链表

public:
	StudentInfo() :StudentInfo("test", -1, -1, scoreList()) {}				//默认构造

	StudentInfo(string _name, int _ID, int _age, listType _lt)
		:name(_name), ID(_ID), age(_age), scoresObj(scoreList(_lt)) {}

	StudentInfo(string _name, int _ID, int _age, int length, listType* _Ltype)
		: name(_name), ID(_ID), age(_age), scoresObj(_Ltype, _Ltype + length) {}

	void showList();							//显示链表中存储的信息
};


//学生管理类
class StudentManager {

protected:
	using student		=	StudentInfo<CourseInfo>;
	using List			=	list<student>;
	using iter			=	list<student>::iterator;
	using iterCoures	=	list<CourseInfo>::iterator;

	List stuList;			//存储一个list链表

	unordered_map<int, iter> hashMapSumScore;		//按照学号快速查找学生

public:
	//获取一个唯一的管理类对象
	static StudentManager& getObject();

	//输出学生信息   测试用例
	void showInfo();

protected:
	//增加信息操作
	bool insertStudent(string _name,int _age,int _ID,int length,CourseInfo*arr);		//插入1个学生信息
	void insertNStudent(int n,student*arr);												//插入n个学生信息
	bool insertCouresinfo(iter target, int n,const CourseInfo* cInfo);						//给target学生写入n节课程信息

	iter find(int ID);																		//按照ID查找学生 推荐 o(1)
	iter find(string name);																	//按照姓名查找学生    o(n) n为学生个数		
	iterCoures find(int courseID, iter target,iterCoures begin,iterCoures end);				//查找区间内指定学生的课程，按照课程ID查询
	iterCoures find(course courseName, iter target, iterCoures begin, iterCoures end);		//查找指定学生的课程，按照课程名称查询

	bool deleteStuInfo(int ID, string name);					//删除指定学生的信息，为防止误操作，需要同时输入id和name

	bool deleteCourseInfo(course courseName, iter target);		//删除指定学生的课程信息 按照课程名称
	bool deleteCourseInfo(int courseID,iter target);			//删除指定学生的课程信息 按照课程ID

	void saveToFile();											//将数据写入文件
	void getDataFile();											//从文件中读取数据

	iter getEnd();							//获取末尾迭代器

	void culaAvgScore(iter target);		//计算均绩

	StudentManager();
	StudentManager(const StudentManager&) = delete;
	StudentManager operator=(const StudentManager&) = delete;

	void cleanAll();					//清空数据

public:
	//虚函数：

	virtual void initMenu();	//初始化菜单
};

template<typename listType>
void StudentInfo<listType>::showList()
{
	for (auto it =this->scoresObj.begin(); it != this->scoresObj.end(); it++) {
		cout << *it << endl;
	}
}
