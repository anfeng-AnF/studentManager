#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<Windows.h>
#include<string>
#include<vector>
#include<thread>
#include<mutex>
#include<future>
#include<unordered_map>




using namespace std;

//枚举：所有课程名称
enum course {
    IntroductionToComputerScience,
    DataStructuresAndAlgorithms,
    DatabaseManagementSystems,
    ComputerNetworks,
    OperatingSystems,
    SoftwareEngineering,
    ArtificialIntelligence,
    WebDevelopment,
    Cybersecurity,
    MachineLearning,
    ComputerGraphics,
    ComputerArchitecture,
    MobileAppDevelopment,
    GameDevelopment,
    EthicalHacking,
    CloudComputing,
    BigDataAnalytics,
    SoftwareTesting,

    // 通识课程
    IntroductionToPsychology,
    WorldHistory,
    IntroductionToPhilosophy,
    EnvironmentalScience,
    IntroductionToSociology,

    // 红课
    PrinciplesOfMarxism,
    ModernChineseHistory,
    IntroductionToMaoZedongThought,

    TotalCourses // 用于计算课程总数
};

//存储课程信息的数组 课程名称/课程学分
const string couresNameArr[] = {
    "Introduction to Computer Science",
    "Data Structures and Algorithms",
    "Database Management Systems",
    "Computer Networks",
    "Operating Systems",
    "Software Engineering",
    "Artificial Intelligence",
    "Web Development",
    "Cybersecurity",
    "Machine Learning",
    "Computer Graphics",
    "Computer Architecture",
    "Mobile App Development",
    "Game Development",
    "Ethical Hacking",
    "Cloud Computing",
    "Big Data Analytics",
    "Software Testing",

    "Introduction to Psychology",
    "World History",
    "Introduction to Philosophy",
    "Environmental Science",
    "Introduction to Sociology",

    "PrinciplesOfMarxism",
    "ModernChineseHistory",
    "IntroductionToMaoZedongThought"
};
const int courseCreditArr[] = {
    4, 4, 3, 3, 3, 4, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 4, 2, 2, 3, 3, 3
};
course intToCourse(int intValue);

