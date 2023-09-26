#include"StudentManager.h"
using student = StudentInfo<CourseInfo>;
using List = list<student>;
using iter = list<student>::iterator;
using iterCoures = list<CourseInfo>::iterator;

StudentManager& StudentManager::getObject()
{
	static StudentManager smObj;
	return smObj;
}

void StudentManager::showInfo()
{
	for (auto it : this->stuList) {
		cout << "name:" << it.name << endl;
		cout << "ID:" << it.ID << endl;
		cout << "age:" << it.age << endl;
		cout << "average socre:" << it.avgScore << endl;
		it.showList();
	}
}


iter StudentManager::getEnd()
{
	return this->stuList.end();
}

StudentManager::StudentManager()
{
}

void StudentManager::initMenu()
{
}

bool StudentManager::insertStudent(string _name, int _age, int _ID, int length,CourseInfo* arr)
{
	if (this->find(_ID) == this->stuList.end()) {
		this->stuList.push_front({ _name,_age,_ID,length,arr });//将学生及其信息加入链表，头插法以提高效率
		this->hashMapSumScore.insert({ _ID,this->stuList.begin() });
		this->culaAvgScore(stuList.begin());
		return true;
	}
	else
	{
		cout << "ID为： " << _ID << "  学生已经存在" << endl;
		return false;
	}
}

void StudentManager::insertNStudent(int n, student* arr)
{
	for (int i = 0; i < n; i++) {
		//不允许学号重复
		if (this->find(arr[i].ID)==this->stuList.end()) {
			this->stuList.push_front(arr[i]);
			this->culaAvgScore(stuList.begin());
			this->hashMapSumScore.insert({ arr[i].ID,this->stuList.begin() });
		}
		else
		{
			cout<<"ID为： " << arr[i].ID << "  学生已经存在" << endl;
		}
	}
}

bool StudentManager::insertCouresinfo(iter target, int n,const CourseInfo* cInfo)
{
	if (target == this->stuList.end()) {
		cout << "目标错误" << endl;
		return false;
	}
	for (int i = 0; i < n; i++) {
		target->scoresObj.push_front(cInfo[i]);
	}
	this->culaAvgScore(target);
	return true;
}

iter StudentManager::find(int ID)
{
	if (!this->hashMapSumScore.count(ID)) {
		return this->stuList.end();
	}
	else
	{
		return this->hashMapSumScore[ID];
	}
}

iter StudentManager::find(string name)
{
	for (auto it = this->stuList.begin(); it != this->stuList.end(); it++) {
		if (it->name == name)return it;
	}
	return this->stuList.end();
}

iterCoures StudentManager::find(int courseID, iter target, iterCoures begin, iterCoures end)
{
	for (auto it = begin; it !=end; it++)
	{
		if (it->courseID == courseID)return it;
	}
	return end;
}

iterCoures StudentManager::find(course courseName, iter target, iterCoures begin, iterCoures end)
{
	for (auto it = begin; it != end; it++)
	{
		if (it->courseName == courseName)return it;
	}
	return end;
}



bool StudentManager::deleteStuInfo(int ID, string name)
{
	iter target = this->find(ID);
	if (target != this->stuList.end() && target->name == name) {
		this->stuList.erase(target);
		return true;
	}
	return false;
}

bool StudentManager::deleteCourseInfo(course courseName, iter target)
{
	iterCoures course = target->scoresObj.begin(),
		end = target->scoresObj.end();
	bool isDelete = false;
	while (course!=end)
	{
		course = this->find(courseName, target, course, end);
		if (course != end) {
			course = target->scoresObj.erase(course);
			isDelete = true;
		}
	}
	return isDelete;
}

bool StudentManager::deleteCourseInfo(int courseID, iter target)
{
	iterCoures course = target->scoresObj.begin(),
		end = target->scoresObj.end();
	bool isDelete = false;
	while (course != end)
	{
		course = this->find(courseID, target, course, end);
		if (course != end) {
			course = target->scoresObj.erase(course);
			isDelete = true;
		}
	}
	return isDelete;
}

void StudentManager::saveToFile()
{
	ofstream ofs;
	ofs.open(FILE_NAME, ios::out);
	if (!ofs.is_open()) {
		cout << "文件打开错误" << endl;
		return;
	}
	ofs << "studentName~,ID~,age~,avgscore~,courseName~,score~,courseID~,teacherName~,teacherComment~," << endl;

	for (auto itStu = this->stuList.begin(); itStu != this->stuList.end(); itStu++) {
		ofs << itStu->name << "," << itStu->ID << "," << itStu->age << "," << itStu->avgScore << ",";
		for (auto itCourse = itStu->scoresObj.begin(); itCourse != itStu->scoresObj.end(); itCourse++) {
			ofs << itCourse->courseName << "," 
				<< itCourse->score << "," 
				<< itCourse->courseID<< "," 
				<< itCourse->teacherName<< ","
				<< itCourse->teacherComment<< ",";
		}
		ofs << endl;
	}
	ofs.close();
	cout << "文件保存成功!" << endl;
}

void StudentManager::getDataFile()
{
	ifstream ifs;

	ifs.open(FILE_NAME);
	if (!ifs.is_open()) {
		cout << "文件打开错误" << endl;
		return;
	}

	string strInfo;
	getline(ifs, strInfo);//丢弃第一行用于直接编辑文件的提示语

	size_t start = 0, pos = 0;
	string stuName, teacherName, teacherComment;
	int ID{}, age{}, courseName{}, courseID{};
	float score{}, avgScore{};

	while (getline(ifs, strInfo)) {
		//cout << strInfo << endl;
		start = 0;
		pos = 0;

		//先提取每个学生的基础信息
		pos = strInfo.find(",", start);
		stuName = strInfo.substr(start, pos - start);//获取学生姓名 ...
		start = pos + 1;
		pos = strInfo.find(",", start);
		ID = stoi(strInfo.substr(start, pos - start));
		start = pos + 1;
		pos = strInfo.find(",", start);
		age = stoi(strInfo.substr(start, pos - start));
		start = pos + 1;
		pos = strInfo.find(",", start);
		avgScore = stof(strInfo.substr(start, pos - start));
		start = pos + 1;

		if(!this->insertStudent(stuName, ID, age, 0, nullptr))continue;
		iter stu = this->stuList.begin();
		//提取每个学生的课程信息
		while (start < strInfo.size())
		{
			pos = strInfo.find(",", start);
			courseName = stoi(strInfo.substr(start, pos - start));
			start = pos + 1;

			pos = strInfo.find(",", start);
			score = stof(strInfo.substr(start, pos - start));
			start = pos + 1;

			pos = strInfo.find(",", start);
			courseID = stoi(strInfo.substr(start, pos - start));
			start = pos + 1;

			pos = strInfo.find(",", start);
			teacherName = strInfo.substr(start, pos-start);
			start = pos + 1;

			pos = strInfo.find(",", start);
			teacherComment = strInfo.substr(start, pos - start);
			start = pos + 1;
			CourseInfo temp = { intToCourse(courseName),score,courseID,teacherName,teacherComment };
			this->insertCouresinfo(stu, 1, &temp);
		}
	}

	ifs.close();

}



void StudentManager::culaAvgScore(iter target)
{
	int credit = 0;
	float sum = 0;
	for (auto info : target->scoresObj) {
		sum += info.score *courseCreditArr[info.courseName];
		credit += courseCreditArr[info.courseName];
	}
	target->avgScore = sum / credit;
}




