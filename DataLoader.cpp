#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
//#include <codecvt>
//#include <stdio.h>


// Загрузка преподавателей из файла
void DataLoader::loadTeachers(const std::string& filename, std::vector<Teacher>& teachers) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        Teacher teacher;
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            teacher.name = line.substr(0, pos);
            std::istringstream ss(line.substr(pos + 1));
            std::string course;

            while (std::getline(ss, course, ',')) {
                teacher.courses.push_back(course);
            }
            teachers.push_back(teacher);
        }
    }
    file.close();
}

// Загрузка групп из файла
void DataLoader::loadGroups(const std::string& filename, std::vector<Group>& groups) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        Group group;
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            group.name = line.substr(0, pos);

            std::istringstream ss(line.substr(pos + 1));
            std::string course;
            while (std::getline(ss, course, ',')) {
                group.courses.push_back(course);
            }
            groups.push_back(group);
        }
    }
    file.close();
}
