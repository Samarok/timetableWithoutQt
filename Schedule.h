#pragma once
#include <vector>
#include <string>


class Schedule {
public:
    Schedule();
    Schedule(int groups);
    std::vector <std::vector<std::vector<std::pair<std::string, std::string>>>> timetable;
    // Расписание timetable[group][day][time].first=дисциплина/second=преподователь

};