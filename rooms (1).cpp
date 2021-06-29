#include<iostream>
#include<string>
#include<vector>
#include "libsqlite.hpp"

struct rooms
{
    std::string room_no;
    int size_of_room;
   
};
std::vector<rooms> Rooms;
void read_rooms();
int main()
{
    std::string user_input;
    std::cout << "room_no : ";
    std::cin >> user_input;
    read_rooms();
    for(int i = 0; i < Rooms.size(); i++)
    {
        if(user_input ==  Rooms[i].room_no)
            std::cout <<  Rooms[i].room_no<< " " <<  Rooms[i].size_of_room<< std::endl;
    }
}
void read_rooms()
{
    int i = 0;
    sqlite::sqlite db("timetable_final");
    
    auto cur = db.get_statement();
    cur->set_sql("select * from rooms;");
    cur->prepare();
    
    while(cur -> step())
    {
        Rooms.push_back(rooms());
        Rooms[i].room_no = (cur->get_text(0));
        Rooms[i].size_of_room = (cur->get_int(1));
        i++;
    }
}