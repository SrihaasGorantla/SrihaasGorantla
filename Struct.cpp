#include <iostream>
#include <string>
#include <vector>
#include "libsqlite.hpp"

struct timetable
{
    std::string modules;
    std::string classes;
    int students;
    std::string lectureres;
    std::string rooms;
    std::string days;
};
std::vector<timetable> Timetable;
void read_timetable();
int main()
{
    std::string user_input;
    std::cout << "Enter day ";
    std::cin >> user_input;
    read_timetable();
    for(int i = 0; i < Timetable.size(); i++)
    {
        if(user_input ==  Timetable[i].days)
            std::cout <<  Timetable[i].modules << " " <<  Timetable[i].classes << " " <<  Timetable[i].students << " " <<  Timetable[i].lectureres << " " <<  Timetable[i].rooms << " " <<  Timetable[i].days << std::endl;
    }
}
void read_timetable()
{
    int i = 0;
    sqlite::sqlite db("timetable_final");
    
    auto cur = db.get_statement();
    cur->set_sql("select * from timetable;");
    cur->prepare();
    
    while(cur -> step())
    {
        Timetable.push_back(timetable());
        Timetable[i].modules = (cur->get_text(0));
        Timetable[i].classes = (cur->get_text(1));
        Timetable[i].students = (cur->get_int(2));
        Timetable[i].lectureres = (cur->get_text(3));
        Timetable[i].rooms = (cur->get_text(4));
        Timetable[i].days = (cur->get_text(5));
        i++;
    }
}