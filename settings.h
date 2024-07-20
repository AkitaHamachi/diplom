#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QIntValidator>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;


public slots:
    void slot(int name);
    void slot_main_time(int time);
    void slot_extra_time(int time);
    void slot_main_time_user(int time);
    void slot_extra_time_user(int time);
    void slot_readyflag(bool flag);
signals:
    void signalForm(int);
    void signal_main_time(int);
    void signal_extra_time(int);
    void signal_main_time_user(int);
    void signal_extra_time_user(int);
    void signal_readyflag(bool);
private slots:
    void on_pushButton_clicked();
};

#endif // SETTINGS_H
