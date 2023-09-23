#include"StudentManager.h"

using student = StudentInfo<CourseInfo>;
using List = list<student>;
using iter = list<student>::iterator;
using iterCoures = list<CourseInfo>::iterator;

int main() {
    CourseInfo student1Courses[] = {
        CourseInfo(ComputerNetworks, 90, 101, "Teacher A", "1a"),
        CourseInfo(ComputerGraphics, 85, 102, "Teacher B", "1b"),
        CourseInfo(PrinciplesOfMarxism, 88, 103, "Teacher C", "1c")
    };

    CourseInfo student2Courses[] = {
        CourseInfo(IntroductionToComputerScience, 78, 201, "Teacher A", "2a"),
        CourseInfo(ComputerNetworks, 92, 202, "Teacher B", "2b"),
        CourseInfo(ComputerGraphics, 87, 203, "Teacher C", "2c")
    };

    CourseInfo student3Courses[] = {
        {MobileAppDevelopment, 95, 301, "Teacher A", "3a"},
        CourseInfo(PrinciplesOfMarxism, 91, 302, "Teacher B", "3b"),
        CourseInfo(ComputerNetworks, 89, 303, "Teacher C", "3c")
    };

    StudentManager& manager = StudentManager::getObject();

    manager.insertStudent("Student 1", 20, 1001, 3, student1Courses);
    manager.insertStudent("Student 2", 21, 2001, 3, student2Courses);
    manager.insertStudent("Student 3", 22, 3001, 3, student3Courses);
    manager.insertStudent("Student 1", 120, 11001, 3, student1Courses);
    manager.insertStudent("Student 2", 121, 22001, 3, student2Courses);
    manager.insertStudent("Student 3", 122, 33001, 3, student3Courses);
    manager.showInfo();
    
    if(manager.find(1001)!=manager.getEnd())manager.find(1001)->showList();
    manager.saveToFile();
    manager.getDataFile();
    cout << "#########################################################################" << endl;
    manager.showInfo();

    //CourseInfo student4Courses[] = {
    //CourseInfo(ComputerNetworks, 90, 101, "Teacher A", "Good job!"),
    //CourseInfo(ComputerGraphics, 85, 102, "Teacher B", "Excellent!"),
    //CourseInfo(PrinciplesOfMarxism, 88, 103, "Teacher C", "Well done!")
    //};

    //CourseInfo student5Courses[] = {
    //    CourseInfo(IntroductionToComputerScience, 78, 201, "Teacher A", "Keep it up!"),
    //    CourseInfo(ComputerNetworks, 92, 202, "Teacher B", "Great work!"),
    //    CourseInfo(ComputerGraphics, 87, 203, "Teacher C", "Impressive!")
    //};

    //CourseInfo student6Courses[] = {
    //    {MobileAppDevelopment, 95, 301, "Teacher A", "Outstanding!"},
    //    CourseInfo(PrinciplesOfMarxism, 91, 302, "Teacher B", "Fantastic!"),
    //    CourseInfo(ComputerNetworks, 89, 303, "Teacher C", "Bravo!")
    //};
    //student s3[] = {
    //    {"Student 4", 201, 10011, 3, student4Courses},
    //    {"Student 5", 213, 20011, 3, student5Courses},
    //    {"Student 6", 222, 30011, 3, student6Courses}
    //};

    //manager.insertNStudent(3, s3);
    //cout << "#########################################################################" << endl;
    //manager.showInfo();
    //cout << "#########################################################################" << endl;
    //manager.deleteStuInfo(222, "Student 6");
    //manager.deleteStuInfo(201, "Student 5");
    //manager.showInfo();
    //cout << "#########################################################################" << endl;
    //manager.saveToFile();
    //manager.getDataFile();
    //cout << "#########################################################################" << endl;
    //manager.showInfo();
    //manager.saveToFile();
	return 0;
}