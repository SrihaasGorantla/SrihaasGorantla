#include <iostream>
#include<string>
using namespace std;

#include "libsqlite.hpp"

int main()
{
    sqlite::sqlite db("timetable_final");
    
    auto cur = db.get_statement();
    cur->set_sql("select * from lecturers;");
    cur->prepare();
    
    while (cur->step())
        cout << cur->get_text(0)<<""<<cur->get_int(1)<<endl;
    
    
}