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

//ö�٣����пγ�����
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

    // ͨʶ�γ�
    IntroductionToPsychology,
    WorldHistory,
    IntroductionToPhilosophy,
    EnvironmentalScience,
    IntroductionToSociology,

    // ���
    PrinciplesOfMarxism,
    ModernChineseHistory,
    IntroductionToMaoZedongThought,

    TotalCourses // ���ڼ���γ�����
};

//�洢�γ���Ϣ������ �γ�����/�γ�ѧ��
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

