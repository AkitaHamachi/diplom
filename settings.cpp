#include "settings.h"
#include "ui_settings.h"
#include<QString>
#include <QTimer>
Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->extra_time_line->setValidator(new QIntValidator(-2147483647, 2147483647, this));
    ui->extra_time_user_line->setValidator(new QIntValidator(-2147483647, 2147483647, this));
    ui->main_time_user_line->setValidator(new QIntValidator(-2147483647, 2147483647, this));
    ui->maint_time_line->setValidator(new QIntValidator(-2147483647, 2147483647, this));
}

Settings::~Settings()
{
    delete ui;
}

void Settings::slot(int name)
{
    ui->label->setText(QString::number(name));
}

void Settings::slot_main_time(int time)
{
    ui->maint_time_line->setText(QString::number(time));
}

void Settings::slot_extra_time(int time)
{
    ui->extra_time_line->setText(QString::number(time));
}

void Settings::slot_main_time_user(int time)
{
    ui->main_time_user_line->setText(QString::number(time));
}

void Settings::slot_extra_time_user(int time)
{
    ui->extra_time_user_line->setText(QString::number(time));
}

void Settings::slot_readyflag(bool flag)
{

      ui->radioButton->setChecked(flag);

}

void Settings::on_pushButton_clicked()
{
    //emit signalForm((ui->lineEdit->text().toInt()));
    emit signal_main_time(ui->maint_time_line->text().toInt());
    emit signal_main_time_user(ui->main_time_user_line->text().toInt());
    emit signal_extra_time(ui->extra_time_line->text().toInt());
    emit signal_extra_time_user(ui->extra_time_user_line->text().toInt());
    emit signal_readyflag(ui->radioButton->isChecked());
    ui->change->setText("изменения \nвнесены");
}

