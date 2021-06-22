#include "Seminar.h"
using namespace std;

std::string Seminar::getName() const {
    return name;
}

std::string Seminar::getTeacher() const {
    return teacher;
}

int Seminar::getGroupId() const {
    return groupId;
}

int Seminar::getDay() const {
    return day;
}

int Seminar::getAuditory() const {
    return auditory;
}

int Seminar::getStartHour() const {
    return startHour;
}

int Seminar::getEndHour() const {
    return endHour;
}

int Seminar::getStartMinute() const {
    return startMinute;
}

int Seminar::getEndMinute() const {
    return endMinute;
}

Seminar::Seminar(std::string name, std::string teacher, int groupId, int day, int auditory, int startHour, int startMinute, int endHour, int endMinute): name(name), teacher(teacher), groupId(groupId), day(day), auditory(auditory), startHour(startHour), startMinute(startMinute), endHour(endHour), endMinute(endMinute) {}

void Seminar::input() {
    std::string Vname, Vteacher;
    int VgroupId, Vday, Vauditory;
    int VstartHour, VstartMinute, VendHour, VendMinute;


    cin >> Vname >> Vteacher >> VgroupId >> Vday >> Vauditory >> VstartHour >> VstartMinute >> VendHour >> VendMinute;

    name = Vname;
    teacher = Vteacher;
    groupId = VgroupId;
    day = Vday;
    auditory = Vauditory;
    startHour = VstartHour;
    startMinute = VstartMinute;
    endHour = VendHour;
    endMinute = VendMinute;
}

std::ostream& operator<<(std::ostream& out, const Seminar& seminar) {
    out << "Pair: " << seminar.getName() << endl << "Teacher: " << seminar.getTeacher() << endl << "Group #: " << seminar.getGroupId() << endl << "Day: " << seminar.getDay() << endl << "Auditory: " << seminar.getAuditory() << endl << "Start time: " << seminar.getStartHour() << ":" << seminar.getStartMinute() << endl << "End time: " << seminar.getEndHour() << ":" << seminar.getEndMinute();
}