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
            this->deleteInfo();
            break;
        case 4://�༭ѧ����Ϣ
            changeStuCInfo();
            break;
        case 5://��������ѧ������

            break;
        case 6://����ѧ����Ϣ
            this->saveStuInfo();
            break;
        case 7://���ѧ����Ϣ 

            break;
        case 8://�˳�ϵͳ
            this->saveStuInfo(); //�Զ�����
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
    cout << "������ѧ��������(��Ҫ����ո������ַ�)" << endl;
    cin >> name;
    cout << "��ֱ�����ѧ������; ѧ��;" << endl;
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
        cout << "��ѡ����Ҫ���еĲ���:" << endl;
        cout << "1,ɾ��ѧ����ȫ����Ϣ" << endl;
        cout << "2,ɾ��ѧ���Ŀγ���Ϣ" << endl;
        cout << "0,ȡ������" << endl;
        cin >> choose;
        switch (choose)
        {
        case '1': {
            cout << "����������ѧ����ID������" << endl;
            int id;
            string name;
            cin >> id >> name;
            if (!this->deleteStuInfo(id, name)) {
                if(this->find(id)!=this->getEnd()){
                    cout << "����ѧ������ID�Ƿ�ƥ�������" << endl;
                }
                else
                {
                    cout << "���޴���" << endl;
                }
                
            };
        }
            break;
        case '2': {
            cout << "������Ҫ�޸ĵ�ѧ����ID:";
            int ID;
            cin >> ID;
            iter target = this->find(ID);
            if (target == this->getEnd()) {
                cout << "���޴���" << endl;
            }
            else
            {
                cout << "������Ҫɾ���Ŀγ�����/id:" << endl;
                string course;
                bool isInt=true;
                cin >> course;
                for (auto it : course) {
                    if (it > '9' || it < '0')isInt=false;
                }
                if (isInt) {
                    if (!this->deleteCourseInfo(stoi(course), target)) {
                        cout << "ɾ��ʧ��" << endl;
                    }
                    else
                    {
                        cout << "ɾ���ɹ�" << endl;
                    }
                }
                else
                {
                    if (!this->deleteCourseInfo(intToCourse(stoi(course)), target)) {
                        cout << "ɾ��ʧ��" << endl;
                    }
                    else
                    {
                        cout << "ɾ���ɹ�" << endl;
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
    cout << "��������Ҫ�༭��ѧ��id:" << endl;
    int ID;
    cin >> ID;
    auto it = this->find(ID);
    if (it == this->getEnd()) {
        cout << "���޴���" << endl;
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

void Admin::insereCourseInfo(iter it)
{
    vector<CourseInfo> vecCourse;
    course courseName;
    int temp,length;
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
        vecCourse.push_back({ courseName, score, courseID, teacherName, teacherComment });
    }
    this->insertCouresinfo(it, vecCourse.size(), vecCourse.data());
}
