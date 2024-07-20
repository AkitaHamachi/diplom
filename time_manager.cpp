#include "time_manager.h"

time_manager::time_manager()
{

}
void time_manager::add(Time_controller *value){//добавить данные

    Data = value;
    array.push_back(value);
}
Time_controller * time_manager::data(int i){
    return array[i];
}

void time_manager::change(Time_controller *value, int i)
{
    array[i]=value;
}


int time_manager::size(){
    return array.size();
}
