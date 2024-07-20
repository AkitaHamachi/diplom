#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include<time_controller.h>
#include<QList>
class time_manager
{
private:
    QList<Time_controller*> array;
    Time_controller *Data;
public:
    time_manager();
    void add(Time_controller *value);//добавить данные
    int size();//вернуть размер
    Time_controller *data(int i);//возращает данные по индексу
    void change(Time_controller *value,int i);
};

#endif // TIME_MANAGER_H
