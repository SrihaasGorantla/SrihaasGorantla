#include<iostream>
#include<string>
#include<vector>
#include "libsqlite.hpp"

struct students
{
    std::string sname;
    int student_id;
    std::string course;
  
};
std::vector<students> Students;
void read_students();
int main()
{
    std::string user_input;
    std::cout << "student name:";
    std::cin >> user_input;
    read_students();
    for(int i = 0; i < Students.size(); i++)
    {
        if(user_input ==  Students[i].sname)
            std::cout << "student id: "<< Students[i].student_id << ", course: " <<  Students[i].course << std::endl;
    }
}
void read_students()
{
    int i = 0;
    sqlite::sqlite db("timetable_final");
    
    auto cur = db.get_statement();
    cur->set_sql("select * from students;");
    cur->prepare();
    
    while(cur -> step())
    {
        Students.push_back(students());
        Students[i].sname = (cur->get_text(0));
        Students[i].student_id = (cur->get_int(1));
        Students[i].course = (cur->get_text(2));
        i++;
    }
}