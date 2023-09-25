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
           
            break;
        case 4://编辑学生信息

            break;
        case 5://更新所有学生均绩

            break;
        case 6://保存学生信息

            break;
        case 7://清空学生信息 

            break;
        case 8://退出系统
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
    int age,ID,length;
    vector<CourseInfo> vecCourse;
    cout << "请输入学生姓名：" << endl;
    cin >> name;
    cout << "请分别输入学生年龄; 学号;" << endl;
    cin >> age >> ID;
    if (!this->insertStudent(name, age, ID, 0, nullptr)) {
        system("pause");
        return;
    };
    course courseName;
    int temp;
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
        vecCourse.push_back({courseName, score, courseID, teacherName, teacherComment});
    }
    this->insertCouresinfo(this->find(ID), vecCourse.size(), vecCourse.data());
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
