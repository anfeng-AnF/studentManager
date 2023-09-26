#include"admin.h"


void Admin::initMenu() {
    this->initData();
    this->showMenu();
    cout << "Enter your choice: ";
    int choice;
    while (cin >> choice) {
        switch (choice) {
        case 1://添加学生
            this->addStuInfo();
            break;
        case 2: //查看所有学生信息
            this->showAllInfo();
            break;
        case 3: //移除学生
            this->deleteInfo();
            break;
        case 4://编辑学生信息
            changeStuCInfo();
            break;
        case 5://更新所有学生均绩

            break;
        case 6://保存学生信息
            this->saveStuInfo();
            break;
        case 7://清空学生信息 

            break;
        case 8://退出系统
            this->saveStuInfo(); //自动保存
            return;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        system("pause");
        system("cls");
        this->showMenu();
        cout << "Enter your choice: ";
    }
}

void Admin::showAllInfo()
{
    this->showInfo();
}

void Admin::addStuInfo()
{
    string name;
    int age,ID;
    cout << "请输入学生姓名：(不要输入空格及特殊字符)" << endl;
    cin >> name;
    cout << "请分别输入学生年龄; 学号;" << endl;
    cin >> age >> ID;
    if (!this->insertStudent(name, age, ID, 0, nullptr)) {
        return;
    };
    insereCourseInfo(this->find(ID));
}

void Admin::deleteInfo()
{
    char choose{};
    while (1)
    {
        system("cls");
        cout << "请选择你要进行的操作:" << endl;
        cout << "1,删除学生的全部信息" << endl;
        cout << "2,删除学生的课程信息" << endl;
        cout << "0,取消操作" << endl;
        cin >> choose;
        switch (choose)
        {
        case '1': {
            cout << "请依次输入学生的ID，姓名" << endl;
            int id;
            string name;
            cin >> id >> name;
            if (!this->deleteStuInfo(id, name)) {
                if(this->find(id)!=this->getEnd()){
                    cout << "请检查学生姓名ID是否匹配后重试" << endl;
                }
                else
                {
                    cout << "查无此人" << endl;
                }
                
            };
        }
            break;
        case '2': {
            cout << "请输入要修改的学生的ID:";
            int ID;
            cin >> ID;
            iter target = this->find(ID);
            if (target == this->getEnd()) {
                cout << "查无此人" << endl;
            }
            else
            {
                cout << "请输入要删除的课程名称/id:" << endl;
                string course;
                bool isInt=true;
                cin >> course;
                for (auto it : course) {
                    if (it > '9' || it < '0')isInt=false;
                }
                if (isInt) {
                    if (!this->deleteCourseInfo(stoi(course), target)) {
                        cout << "删除失败" << endl;
                    }
                    else
                    {
                        cout << "删除成功" << endl;
                    }
                }
                else
                {
                    if (!this->deleteCourseInfo(intToCourse(stoi(course)), target)) {
                        cout << "删除失败" << endl;
                    }
                    else
                    {
                        cout << "删除成功" << endl;
                    }
                }
            }
        }
            break;
        case '0':
            return;
        default:
            break;
        }

    }

}

void Admin::saveStuInfo()
{
    this->saveToFile();
}

void Admin::changeStuCInfo()
{
    cout << "请输入你要编辑的学生id:" << endl;
    int ID;
    cin >> ID;
    auto it = this->find(ID);
    if (it == this->getEnd()) {
        cout << "查无此人" << endl;
        return;
    }
    this->insereCourseInfo(it);
}

void Admin::initData()
{
    this->getDataFile();
}

void Admin::showMenu()
{
    // 实现管理员菜单
    cout << "             Welcome, Admin " << userName << "!" << endl;
    cout << "------------   1. 添加学生信息         ------------" << endl;
    cout << "------------   2. 查看所有学生信息     ------------" << endl;
    cout << "------------   3. 移除学生信息         ------------" << endl;
    cout << "------------   4. 编辑学生信息         ------------" << endl;
    cout << "------------   5. 更新所有学生均绩     ------------" << endl;
    cout << "------------   6. 保存学生信息         ------------" << endl;
    cout << "------------   7. 清空学生信息         ------------" << endl;
    cout << "------------   8. 退出系统             ------------" << endl;
}

void Admin::insereCourseInfo(iter it)
{
    vector<CourseInfo> vecCourse;
    course courseName;
    int temp,length;
    float score;
    int courseID;
    string teacherName;
    string teacherComment;

    cout << "需要写入学生的几节课程信息？" << endl;
    cin >> length;
    for (int i = 0; i < length; i++) {
        int j = 0;
        // 输入课程名称
        std::cout << "请选择课程名称: ";
        for (string s : couresNameArr) {
            cout << j++ << ":     " << s << endl;
        }
        std::cin >> temp;
        courseName = intToCourse(temp);

        // 输入学生得分
        std::cout << "请输入学生得分: ";
        std::cin >> score;

        // 输入课程号
        std::cout << "请输入课程号: ";
        std::cin >> courseID;

        // 输入课程老师的姓名
        std::cout << "请输入教师姓名: ";
        std::cin.ignore(); // 清除前一个输入后的换行符
        std::getline(std::cin, teacherName);

        // 输入记录教师评语
        std::cout << "请输入教师评语:（可选） ";
        std::getline(std::cin, teacherComment);
        vecCourse.push_back({ courseName, score, courseID, teacherName, teacherComment });
    }
    this->insertCouresinfo(it, vecCourse.size(), vecCourse.data());
}
