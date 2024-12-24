#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "teacher.h"
#include "group.h"

class DataLoader {
public:
    static void loadTeachers(const std::string& filename, std::vector<Teacher>& teachers);
    static void loadGroups(const std::string& filename, std::vector<Group>& groups);
};