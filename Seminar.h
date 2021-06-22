#ifndef INC_150_SEMINAR_H
#define INC_150_SEMINAR_H

#include <iostream>

class Seminar {
private:
    std::string name;
    std::string teacher;
    int groupId;
    int day;
    int auditory;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
public:
    Seminar(std::string name = "", std::string teacher = "", int groupId = 0, int day = 1, int auditory = 0, int startHour = 0, int startMinute = 0, int endHour = 0, int endMinute = 0);

    std::string getName() const;
    std::string getTeacher() const;
    int getGroupId() const;
    int getDay() const;
    int getAuditory() const;
    int getStartHour() const;
    int getEndHour() const;
    int getStartMinute() const;
    int getEndMinute() const;

    void input();
};

std::ostream& operator<<(std::ostream& out, const Seminar& seminar);

#endif //INC_150_SEMINAR_H
