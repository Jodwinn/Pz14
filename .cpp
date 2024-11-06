#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <windows.h>;

using namespace std;

struct SubjectGrade {
    string subjectName;
    int grade;
};

unordered_map<string, double> averageGradePerSubject(const vector<SubjectGrade>& grades) {
    unordered_map<string, vector<int>> subjectGrades;  

    for (const auto& sg : grades) {
        subjectGrades[sg.subjectName].push_back(sg.grade);
    }

    unordered_map<string, double> subjectAverages;
    for (const auto& entry : subjectGrades) {
        const string& subject = entry.first;
        const vector<int>& gradesList = entry.second;

        double sum = 0;
        for (int grade : gradesList) {
            sum += grade;
        }
        subjectAverages[subject] = sum / gradesList.size();  
    }

    return subjectAverages;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<SubjectGrade> grades = {
        {"Математика", 90},
        {"Математика", 85},
        {"Фізика", 78},
        {"Фізка", 82},
        {"Англійська", 88},
        {"Англійська", 92},
        {"Математика", 80}
    };


    unordered_map<string, double> averages = averageGradePerSubject(grades);

    for (const auto& entry : averages) {
        cout << "Предмет: " << entry.first << ", Середній бал: " << entry.second << endl;
    }

    return 0;
}
