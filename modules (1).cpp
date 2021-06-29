#include<iostream>
#include<string>
#include<vector>
#include "libsqlite.hpp"

struct modules
{
    std::string module_name;
    int module_id;
  
};
std::vector<modules> Modules;
void read_modules();
int main()
{
    std::string user_input;
    std::cout << "module_name: ";
    std::cin >> user_input;
    read_modules();
    for(int i = 0; i < Modules.size(); i++)
    {
        if(user_input ==  Modules[i].module_name)
            std::cout <<  Modules[i].module_name << " " << Modules[i].module_id << " "  << std::endl;
    }
}
void read_modules()
{
    int i = 0;
    sqlite::sqlite db("timetable_final");
    
    auto cur = db.get_statement();
    cur->set_sql("select * from modules;");
    cur->prepare();
    
    while(cur -> step())
    {
        Modules.push_back(modules());
        Modules[i].module_name = (cur->get_text(0));
        Modules[i].module_id = (cur->get_int(1));
        i++;
    }
}