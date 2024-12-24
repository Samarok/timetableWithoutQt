#include <iostream>
#include "Schedule.h"
#include "teacher.h"
#include "group.h"
#include "DataLoader.h"
#include <locale.h>
#include <windows.h>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#define coln ";" <<


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "Hello World!\n";
    std::vector<Teacher> teachers;
    std::vector<Group> groups;
    DataLoader::loadTeachers("teachers.txt", teachers);
    DataLoader::loadGroups("groups.txt", groups);

    Schedule main_table(groups.size());
    if (!groups.empty()) {
        std::cout << "The data from the file was read successfully\n";
        std::cout << "Groups found: "<< groups.size();
        std::cout << "\nTeachers found: " << teachers.size();
    }
    else {
        std::cout << "No data is read from the file or 0 groups are entered\n";
        return 0;
    }

    bool check;
    for (int t = 0; t < groups.size(); t++)
    {
        for (int j = 0; j < groups[t].courses.size(); j++)
        {
            check = 0;
            for (int i = 0; i < 48; i++)
                if (main_table.timetable[t][(i) % 6][(i) / 6].first.empty())
                {
                    for (int q = 0; q < teachers.size(); q++)
                    {
                        for (int w = 0; w < teachers[q].courses.size(); w++)
                        {
                            if (teachers[q].courses[w] == groups[t].courses[j])
                            {
                                for (int r = 0; r <= t /*groups.size()*/; r++)
                                {
                                    if (teachers[q].name == main_table.timetable[r][(i) % 6][(i) / 6].second)
                                    {
                                        check = 0;
                                        break;
                                    }
                                    else check = 1;
                                }
                                break;
                            }
                        }
                        if (check)
                        {
                            main_table.timetable[t][(i) % 6][(i) / 6].second = teachers[q].name;
                            main_table.timetable[t][(i) % 6][(i) / 6].first = groups[t].courses[j];
                            break;
                        }
                    }
                    if (check) break;
                }
            if (!check) {
                std::cout << "\n\nIt's impossible to make a timetable\n";
                return 0;
            }
        }
    }
    std::cout << "\nThe timetable is compiled and recorded in the file Schudule.csv\n";

    
    for (int i = 0; i < groups.size(); i++)
    {
        std::ofstream outFile("Schedule.csv");
        outFile << coln "#" << coln "Monday" << coln "Tuesday" << coln "Wednesday" << coln "Thursday" << coln "Friday" << coln "Saturday" << std::endl;
        for (int j = 0; j < 8; j++)
        {
            outFile << coln j << coln main_table.timetable[i][0][j].first << coln main_table.timetable[i][1][j].first
                << coln main_table.timetable[i][2][j].first << coln main_table.timetable[i][3][j].first
                << coln main_table.timetable[i][4][j].first << coln main_table.timetable[i][5][j].first << std::endl;
            outFile << coln j << coln main_table.timetable[i][0][j].second << coln main_table.timetable[i][1][j].second
                << coln main_table.timetable[i][2][j].second << coln main_table.timetable[i][3][j].second
                << coln main_table.timetable[i][4][j].second << coln main_table.timetable[i][5][j].second << std::endl;
        }
    }
        

}
