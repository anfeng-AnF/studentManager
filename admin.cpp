#include"admin.h"


void Admin::initMenu() {
    this->initData();
    this->showMenu();
    cout << "Enter your choice: ";
    int choice;
    while (cin >> choice) {
        switch (choice) {
        case 1://���ѧ��
            this->addStuInfo();
            break;
        case 2: //�鿴����ѧ����Ϣ
            this->showAllInfo();
            break;
        case 3: //�Ƴ�ѧ��
           
            break;
        case 4://�༭ѧ����Ϣ

            break;
        case 5://��������ѧ������

            break;
        case 6://����ѧ����Ϣ

            break;
        case 7://���ѧ����Ϣ 

            break;
        case 8://�˳�ϵͳ
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
    cout << "������ѧ��������" << endl;
    cin >> name;
    cout << "��ֱ�����ѧ������; ѧ��;" << endl;
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

    cout << "��Ҫд��ѧ���ļ��ڿγ���Ϣ��" << endl;
    cin >> length;
    for (int i = 0; i < length; i++) {
        int j = 0;
        // ����γ�����
        std::cout << "��ѡ��γ�����: ";
        for (string s : couresNameArr) {
            cout << j++ << ":     " << s << endl;
        }
        std::cin >> temp;
        courseName = intToCourse(temp);

        // ����ѧ���÷�
        std::cout << "������ѧ���÷�: ";
        std::cin >> score;

        // ����γ̺�
        std::cout << "������γ̺�: ";
        std::cin >> courseID;

        // ����γ���ʦ������
        std::cout << "�������ʦ����: ";
        std::cin.ignore(); // ���ǰһ�������Ļ��з�
        std::getline(std::cin, teacherName);

        // �����¼��ʦ����
        std::cout << "�������ʦ����:����ѡ�� ";
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
    // ʵ�ֹ���Ա�˵�
    cout << "             Welcome, Admin " << userName << "!" << endl;
    cout << "------------   1. ���ѧ����Ϣ         ------------" << endl;
    cout << "------------   2. �鿴����ѧ����Ϣ     ------------" << endl;
    cout << "------------   3. �Ƴ�ѧ����Ϣ         ------------" << endl;
    cout << "------------   4. �༭ѧ����Ϣ         ------------" << endl;
    cout << "------------   5. ��������ѧ������     ------------" << endl;
    cout << "------------   6. ����ѧ����Ϣ         ------------" << endl;
    cout << "------------   7. ���ѧ����Ϣ         ------------" << endl;
    cout << "------------   8. �˳�ϵͳ             ------------" << endl;
}
