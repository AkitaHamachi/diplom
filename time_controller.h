#ifndef TIME_CONTROLLER_H
#define TIME_CONTROLLER_H


class Time_controller
{
private:
    int main_time;
    int extra_time;
    bool readyflag;
    int main_time_user;
    int extra_time_user;
    int name;
public:
    Time_controller();
    void set_main_time(int v){main_time=v;}
    void set_extra_time(int v){extra_time=v;}
    void set_main_time_user(int v){main_time_user=v;}
    void set_extra_time_user(int v){extra_time_user=v;}
    void set_readyflag(bool v){readyflag=v;}
    void set_name(int v){name=v;}
    int get_main_time(){return main_time;}
    int get_extra_time(){return extra_time;}
    int get_main_time_user(){return main_time_user;}
    int get_extra_time_user(){return extra_time_user;}
    bool get_readyflag(){return readyflag;}
    int get_name(){return name;}
};

#endif // TIME_CONTROLLER_H
