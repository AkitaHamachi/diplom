#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <math.h>

int gname;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller = new Time_controller();

    manager = new time_manager();
    for (int i=0;i<35 ;i++ ) {
        createblock(i,0,0,0,0,false);
    }
    ui->have_time->setValidator(new QIntValidator(-2147483647, 2147483647, this));
    ui->left_time->setValidator(new QIntValidator(-2147483647, 2147483647, this));
    ui->free_time->setValidator(new QIntValidator(-2147483647, 2147483647, this));
    for(int i=0;i<35;i++){
        X[i]=0;
        W[i]=0;
        XO[i]=0;
        WO[i]=0;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    breakpointsform.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    int name=0;
    gname=name;
    controller=manager->data(0);
    int main_time=controller->get_main_time();
    int extra_time=controller->get_extra_time();
    int main_time_user=controller->get_main_time_user();
    int extra_time_user=controller->get_extra_time_user();
    int readyflag=controller->get_readyflag();
    sett = new Settings;
    sett->show();
    connect(this,&MainWindow::signal_main_time,sett,&Settings::slot_main_time);
    connect(this,&MainWindow::signal_main_time_user,sett,&Settings::slot_main_time_user);
    connect(this,&MainWindow::signal_extra_time,sett,&Settings::slot_extra_time);
    connect(this,&MainWindow::signal_extra_time_user,sett,&Settings::slot_extra_time_user);
    connect(this,&MainWindow::signal_readyflaf,sett,&Settings::slot_readyflag);
    connect(sett,&Settings::signal_main_time,this,&MainWindow::slot_main_time);
    connect(sett,&Settings::signal_main_time_user,this,&MainWindow::slot_main_time_user);
    connect(sett,&Settings::signal_extra_time,this,&MainWindow::slot_extra_time);
    connect(sett,&Settings::signal_extra_time_user,this,&MainWindow::slot_extra_time_user);
    connect(sett,&Settings::signal_readyflag,this,&MainWindow::slot_readyflag);
    emit signal_main_time(main_time);
    emit signal_main_time_user(main_time_user);
    emit signal_extra_time(extra_time);
    emit signal_extra_time_user(extra_time_user);
    emit signal_readyflaf(readyflag);
    //qDebug()<<controller->get_main_time();
    //qDebug()<<controller->get_extra_time();
      //         qDebug()<<controller->get_main_time_user();
        //       qDebug()<<controller->get_extra_time_user();
          //     qDebug()<<controller->get_readyflag();
}

void MainWindow::slotForm(int name)
{
    ui->button0->setText(QString::number(name));


}

void MainWindow::slot_main_time(int time)
{

        int havetime=ui->have_time->text().toInt()+time-controller->get_main_time();
        ui->have_time->setText(QString::number(havetime));
        int freetime=ui->free_time->text().toInt()-time+controller->get_main_time();
        ui->free_time->setText(QString::number(freetime));


    controller->set_main_time(time);
}

void MainWindow::slot_extra_time(int time)
{
    int havetime=ui->have_time->text().toInt()+time-controller->get_extra_time();
    ui->have_time->setText(QString::number(havetime));
    int freetime=ui->free_time->text().toInt()-time+controller->get_extra_time();
    ui->free_time->setText(QString::number(freetime));
    controller->set_extra_time(time);
}

void MainWindow::slot_main_time_user(int time)
{
    int lefttime=ui->left_time->text().toInt()+time-controller->get_main_time_user();
    ui->left_time->setText(QString::number(lefttime));
    controller->set_main_time_user(time);
}

void MainWindow::slot_extra_time_user(int time)
{
    int lefttime=ui->left_time->text().toInt()+time-controller->get_extra_time_user();
    ui->left_time->setText(QString::number(lefttime));
    controller->set_extra_time_user(time);
}

void MainWindow::slot_readyflag(bool flag)
{
    controller->set_readyflag(flag);
    QString but="button"+QString::number(gname);
    QPushButton *button=findChild<QPushButton*>(but);
    if(flag==true){
    button->setText("r");
    button->setStyleSheet("background-color: rgba(255,255,255,0);"
                          "bordred: none;"
                          "color: green;}");
    }
    if(flag==false){
        if((gname==0)or(gname==5)or(gname==11)or(gname==12)or(gname==13)or(gname==20)or(gname==21)or(gname==22)or(gname==25)or(gname==26)or(gname==27)or(gname==28)or(gname==29)or(gname==33)or(gname==34)){
    button->setText("nr");
    button->setStyleSheet("background-color: rgba(255,255,255,0);"
                          "bordred: none;"
                          "color: red;}");
    }
        else{
            button->setText("nr");
            button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                  "bordred: none;"
                                  "color: yellow;}");
        }
    }
    if (flag==false){
        if((controller->get_main_time()<=controller->get_main_time_user())and(controller->get_extra_time()<=controller->get_extra_time_user())){
            button->setText("to");
            button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                  "bordred: none;"
                                  "color: red;}");
        }
    }
    //manager->change(controller,gname);

    changesize(flag);

    update();
}




void MainWindow::on_init_clicked()
{
    if(ui->comboBox->currentIndex()==2){
    if(manager->size()==0){
        createblock(0,58,0,0,0,false);
        createblock(1,29,0,0,0,false);
        createblock(2,29,0,0,0,false);
        createblock(3,29,0,0,0,false);
        createblock(4,29,0,0,0,false);
        createblock(5,58,0,0,0,false);
        createblock(6,29,0,0,0,false);
        createblock(7,216,0,0,0,false);
        createblock(8,216,0,0,0,false);
        createblock(9,216,0,0,0,false);
        createblock(10,216,0,0,0,false);
        createblock(11,433,0,0,0,false);
        createblock(12,433,0,0,0,false);
        createblock(13,433,0,0,0,false);
        createblock(14,216,0,0,0,false);
        createblock(15,216,0,0,0,false);
        createblock(16,216,0,0,0,false);
        createblock(17,24,0,0,0,false);
        createblock(18,24,0,0,0,false);
        createblock(19,24,0,0,0,false);
        createblock(20,48,0,0,0,false);
        createblock(21,48,0,0,0,false);
        createblock(22,48,0,0,0,false);
        createblock(23,24,0,0,0,false);
        createblock(24,24,0,0,0,false);
        createblock(25,105,0,0,0,false);
        createblock(26,105,0,0,0,false);
        createblock(27,105,0,0,0,false);
        createblock(28,105,0,0,0,false);
        createblock(29,105,0,0,0,false);
        createblock(30,50,0,0,0,false);
        createblock(31,50,0,0,0,false);
        createblock(32,50,0,0,0,false);
        createblock(33,100,0,0,0,false);
        createblock(34,100,0,0,0,false);
        ui->have_time->setText("4211");
        ui->free_time->setText("13");
    }else{
        setblock(0,58,0,0,0,false);
        setblock(1,29,0,0,0,false);
        setblock(2,29,0,0,0,false);
        setblock(3,29,0,0,0,false);
        setblock(4,29,0,0,0,false);
        setblock(5,58,0,0,0,false);
        setblock(6,29,0,0,0,false);
        setblock(7,216,0,0,0,false);
        setblock(8,216,0,0,0,false);
        setblock(9,216,0,0,0,false);
        setblock(10,216,0,0,0,false);
        setblock(11,433,0,0,0,false);
        setblock(12,433,0,0,0,false);
        setblock(13,433,0,0,0,false);
        setblock(14,216,0,0,0,false);
        setblock(15,216,0,0,0,false);
        setblock(16,216,0,0,0,false);
        setblock(17,24,0,0,0,false);
        setblock(18,24,0,0,0,false);
        setblock(19,24,0,0,0,false);
        setblock(20,48,0,0,0,false);
        setblock(21,48,0,0,0,false);
        setblock(22,48,0,0,0,false);
        setblock(23,24,0,0,0,false);
        setblock(24,24,0,0,0,false);
        setblock(25,105,0,0,0,false);
        setblock(26,105,0,0,0,false);
        setblock(27,105,0,0,0,false);
        setblock(28,105,0,0,0,false);
        setblock(29,105,0,0,0,false);
        setblock(30,50,0,0,0,false);
        setblock(31,50,0,0,0,false);
        setblock(32,50,0,0,0,false);
        setblock(33,100,0,0,0,false);
        setblock(34,100,0,0,0,false);
        ui->have_time->setText("4211");
        ui->free_time->setText("13");
        checkflag();
    }
    }else if(ui->comboBox->currentIndex()==0){
        if(manager->size()==0){
    createblock(0,12,0,0,0,false);
    createblock(1,6,0,0,0,false);
    createblock(2,6,0,0,0,false);
    createblock(3,6,0,0,0,false);
    createblock(4,6,0,0,0,false);
    createblock(5,12,0,0,0,false);
    createblock(6,6,0,0,0,false);
    createblock(7,40,0,0,0,false);
    createblock(8,40,0,0,0,false);
    createblock(9,40,0,0,0,false);
    createblock(10,40,0,0,0,false);
    createblock(11,80,0,0,0,false);
    createblock(12,80,0,0,0,false);
    createblock(13,80,0,0,0,false);
    createblock(14,40,0,0,0,false);
    createblock(15,40,0,0,0,false);
    createblock(16,40,0,0,0,false);
    createblock(17,5,0,0,0,false);
    createblock(18,5,0,0,0,false);
    createblock(19,5,0,0,0,false);
    createblock(20,10,0,0,0,false);
    createblock(21,10,0,0,0,false);
    createblock(22,10,0,0,0,false);
    createblock(23,5,0,0,0,false);
    createblock(24,5,0,0,0,false);
    createblock(25,48,0,0,0,false);
    createblock(26,48,0,0,0,false);
    createblock(27,48,0,0,0,false);
    createblock(28,48,0,0,0,false);
    createblock(29,48,0,0,0,false);
    createblock(30,8,0,0,0,false);
    createblock(31,8,0,0,0,false);
    createblock(32,8,0,0,0,false);
    createblock(33,16,0,0,0,false);
    createblock(34,16,0,0,0,false);
    ////////////////////////////

    ui->have_time->setText("925");
    ui->free_time->setText("23");
        }else{
            setblock(0,12,0,0,0,false);
            setblock(1,6,0,0,0,false);
            setblock(2,6,0,0,0,false);
            setblock(3,6,0,0,0,false);
            setblock(4,6,0,0,0,false);
            setblock(5,12,0,0,0,false);
            setblock(6,6,0,0,0,false);
            setblock(7,40,0,0,0,false);
            setblock(8,40,0,0,0,false);
            setblock(9,40,0,0,0,false);
            setblock(10,40,0,0,0,false);
            setblock(11,80,0,0,0,false);
            setblock(12,80,0,0,0,false);
            setblock(13,80,0,0,0,false);
            setblock(14,40,0,0,0,false);
            setblock(15,40,0,0,0,false);
            setblock(16,40,0,0,0,false);
            setblock(17,5,0,0,0,false);
            setblock(18,5,0,0,0,false);
            setblock(19,5,0,0,0,false);
            setblock(20,10,0,0,0,false);
            setblock(21,10,0,0,0,false);
            setblock(22,10,0,0,0,false);
            setblock(23,5,0,0,0,false);
            setblock(24,5,0,0,0,false);
            setblock(25,48,0,0,0,false);
            setblock(26,48,0,0,0,false);
            setblock(27,48,0,0,0,false);
            setblock(28,48,0,0,0,false);
            setblock(29,48,0,0,0,false);
            setblock(30,8,0,0,0,false);
            setblock(31,8,0,0,0,false);
            setblock(32,8,0,0,0,false);
            setblock(33,16,0,0,0,false);
            setblock(34,16,0,0,0,false);
            ////////////////////////////

            ui->have_time->setText("925");
            ui->free_time->setText("23");
            checkflag();
        }
    }else if(ui->comboBox->currentIndex()==1){
        if(manager->size()==0){
        createblock(0,52,0,0,0,false);
        createblock(1,26,0,0,0,false);
        createblock(2,26,0,0,0,false);
        createblock(3,26,0,0,0,false);
        createblock(4,26,0,0,0,false);
        createblock(5,52,0,0,0,false);
        createblock(6,26,0,0,0,false);
        createblock(7,81,0,0,0,false);
        createblock(8,81,0,0,0,false);
        createblock(9,81,0,0,0,false);
        createblock(10,81,0,0,0,false);
        createblock(11,162,0,0,0,false);
        createblock(12,162,0,0,0,false);
        createblock(13,162,0,0,0,false);
        createblock(14,81,0,0,0,false);
        createblock(15,81,0,0,0,false);
        createblock(16,81,0,0,0,false);
        createblock(17,21,0,0,0,false);
        createblock(18,21,0,0,0,false);
        createblock(19,21,0,0,0,false);
        createblock(20,42,0,0,0,false);
        createblock(21,42,0,0,0,false);
        createblock(22,42,0,0,0,false);
        createblock(23,21,0,0,0,false);
        createblock(24,21,0,0,0,false);
        createblock(25,52,0,0,0,false);
        createblock(26,52,0,0,0,false);
        createblock(27,52,0,0,0,false);
        createblock(28,52,0,0,0,false);
        createblock(29,52,0,0,0,false);
        createblock(30,34,0,0,0,false);
        createblock(31,34,0,0,0,false);
        createblock(32,34,0,0,0,false);
        createblock(33,68,0,0,0,false);
        createblock(34,68,0,0,0,false);
        ui->have_time->setText("2016");
        ui->free_time->setText("24");
        }else{
            setblock(0,52,0,0,0,false);
            setblock(1,26,0,0,0,false);
            setblock(2,26,0,0,0,false);
            setblock(3,26,0,0,0,false);
            setblock(4,26,0,0,0,false);
            setblock(5,52,0,0,0,false);
            setblock(6,26,0,0,0,false);
            setblock(7,81,0,0,0,false);
            setblock(8,81,0,0,0,false);
            setblock(9,81,0,0,0,false);
            setblock(10,81,0,0,0,false);
            setblock(11,162,0,0,0,false);
            setblock(12,162,0,0,0,false);
            setblock(13,162,0,0,0,false);
            setblock(14,81,0,0,0,false);
            setblock(15,81,0,0,0,false);
            setblock(16,81,0,0,0,false);
            setblock(17,21,0,0,0,false);
            setblock(18,21,0,0,0,false);
            setblock(19,21,0,0,0,false);
            setblock(20,42,0,0,0,false);
            setblock(21,42,0,0,0,false);
            setblock(22,42,0,0,0,false);
            setblock(23,21,0,0,0,false);
            setblock(24,21,0,0,0,false);
            setblock(25,52,0,0,0,false);
            setblock(26,52,0,0,0,false);
            setblock(27,52,0,0,0,false);
            setblock(28,52,0,0,0,false);
            setblock(29,52,0,0,0,false);
            setblock(30,34,0,0,0,false);
            setblock(31,34,0,0,0,false);
            setblock(32,34,0,0,0,false);
            setblock(33,68,0,0,0,false);
            setblock(34,68,0,0,0,false);
            ui->have_time->setText("2016");
            ui->free_time->setText("24");
            checkflag();
        }
    }else if(ui->comboBox->currentIndex()==3){
        if(manager->size()==0){
        int time=ui->free_time->text().toInt();

        createblock(0,52*time/2040,0,0,0,false);
        createblock(1,26*time/2040,0,0,0,false);
        createblock(2,26*time/2040,0,0,0,false);
        createblock(3,26*time/2040,0,0,0,false);
        createblock(4,26*time/2040,0,0,0,false);
        createblock(5,52*time/2040,0,0,0,false);
        createblock(6,26*time/2040,0,0,0,false);
        createblock(7,81*time/2040,0,0,0,false);
        createblock(8,81*time/2040,0,0,0,false);
        createblock(9,81*time/2040,0,0,0,false);
        createblock(10,81*time/2040,0,0,0,false);
        createblock(11,162*time/2040,0,0,0,false);
        createblock(12,162*time/2040,0,0,0,false);
        createblock(13,162*time/2040,0,0,0,false);
        createblock(14,81*time/2040,0,0,0,false);
        createblock(15,81*time/2040,0,0,0,false);
        createblock(16,81*time/2040,0,0,0,false);
        createblock(17,21*time/2040,0,0,0,false);
        createblock(18,21*time/2040,0,0,0,false);
        createblock(19,21*time/2040,0,0,0,false);
        createblock(20,42*time/2040,0,0,0,false);
        createblock(21,42*time/2040,0,0,0,false);
        createblock(22,42*time/2040,0,0,0,false);
        createblock(23,21*time/2040,0,0,0,false);
        createblock(24,21*time/2040,0,0,0,false);
        createblock(25,52*time/2040,0,0,0,false);
        createblock(26,52*time/2040,0,0,0,false);
        createblock(27,52*time/2040,0,0,0,false);
        createblock(28,52*time/2040,0,0,0,false);
        createblock(29,52*time/2040,0,0,0,false);
        createblock(30,34*time/2040,0,0,0,false);
        createblock(31,34*time/2040,0,0,0,false);
        createblock(32,34*time/2040,0,0,0,false);
        createblock(33,68*time/2040,0,0,0,false);
        createblock(34,68*time/2040,0,0,0,false);
        int sumtime=0;
        for(int i=0;i<35;i++){
            sumtime+=manager->data(i)->get_main_time();
        }
        ui->free_time->setText(QString::number(time-sumtime));
        ui->have_time->setText(QString::number(sumtime));
        }else{
            int time=ui->free_time->text().toInt();

            setblock(0,52*time/2040,0,0,0,false);
            setblock(1,26*time/2040,0,0,0,false);
            setblock(2,26*time/2040,0,0,0,false);
            setblock(3,26*time/2040,0,0,0,false);
            setblock(4,26*time/2040,0,0,0,false);
            setblock(5,52*time/2040,0,0,0,false);
            setblock(6,26*time/2040,0,0,0,false);
            setblock(7,81*time/2040,0,0,0,false);
            setblock(8,81*time/2040,0,0,0,false);
            setblock(9,81*time/2040,0,0,0,false);
            setblock(10,81*time/2040,0,0,0,false);
            setblock(11,162*time/2040,0,0,0,false);
            setblock(12,162*time/2040,0,0,0,false);
            setblock(13,162*time/2040,0,0,0,false);
            setblock(14,81*time/2040,0,0,0,false);
            setblock(15,81*time/2040,0,0,0,false);
            setblock(16,81*time/2040,0,0,0,false);
            setblock(17,21*time/2040,0,0,0,false);
            setblock(18,21*time/2040,0,0,0,false);
            setblock(19,21*time/2040,0,0,0,false);
            setblock(20,42*time/2040,0,0,0,false);
            setblock(21,42*time/2040,0,0,0,false);
            setblock(22,42*time/2040,0,0,0,false);
            setblock(23,21*time/2040,0,0,0,false);
            setblock(24,21*time/2040,0,0,0,false);
            setblock(25,52*time/2040,0,0,0,false);
            setblock(26,52*time/2040,0,0,0,false);
            setblock(27,52*time/2040,0,0,0,false);
            setblock(28,52*time/2040,0,0,0,false);
            setblock(29,52*time/2040,0,0,0,false);
            setblock(30,34*time/2040,0,0,0,false);
            setblock(31,34*time/2040,0,0,0,false);
            setblock(32,34*time/2040,0,0,0,false);
            setblock(33,68*time/2040,0,0,0,false);
            setblock(34,68*time/2040,0,0,0,false);
            int sumtime=0;
            for(int i=0;i<35;i++){
                sumtime+=manager->data(i)->get_main_time();
            }
            ui->free_time->setText(QString::number(time-sumtime));
            ui->have_time->setText(QString::number(sumtime));
            checkflag();
        }
    }else if(ui->comboBox->currentIndex()==4) {
        if(manager->size()==0){
        for (int i=0;i<35 ;i++ ) {
            createblock(i,0,0,0,0,false);
        }
        }
        else{
            for (int i=0;i<35 ;i++ ) {
                setblock(i,0,0,0,0,false);
            }
            ui->have_time->setText("0");
            ui->left_time->setText("0");
            ui->free_time->setText("0");
            checkflag();
        }

}




}


void MainWindow::on_button1_clicked()
{
    buttonconnect(1);
}


void MainWindow::on_button2_clicked()
{

    buttonconnect(2);
}


void MainWindow::on_button3_clicked()
{
    buttonconnect(3);
}


void MainWindow::on_button4_clicked()
{
    buttonconnect(4);
}


void MainWindow::on_button5_clicked()
{
    buttonconnect(5);
}


void MainWindow::on_button6_clicked()
{
    buttonconnect(6);
}


void MainWindow::on_button0_clicked()
{
    buttonconnect(0);
}

void MainWindow::buttonconnect(int name)
{
    gname=name;
    controller=manager->data(name);
    int main_time=controller->get_main_time();
    int extra_time=controller->get_extra_time();
    int main_time_user=controller->get_main_time_user();
    int extra_time_user=controller->get_extra_time_user();
    int readyflag=controller->get_readyflag();
    sett = new Settings;
    sett->show();
    connect(this,&MainWindow::signal_main_time,sett,&Settings::slot_main_time);
    connect(this,&MainWindow::signal_main_time_user,sett,&Settings::slot_main_time_user);
    connect(this,&MainWindow::signal_extra_time,sett,&Settings::slot_extra_time);
    connect(this,&MainWindow::signal_extra_time_user,sett,&Settings::slot_extra_time_user);
    connect(this,&MainWindow::signal_readyflaf,sett,&Settings::slot_readyflag);
    connect(sett,&Settings::signal_main_time,this,&MainWindow::slot_main_time);
    connect(sett,&Settings::signal_main_time_user,this,&MainWindow::slot_main_time_user);
    connect(sett,&Settings::signal_extra_time,this,&MainWindow::slot_extra_time);
    connect(sett,&Settings::signal_extra_time_user,this,&MainWindow::slot_extra_time_user);
    connect(sett,&Settings::signal_readyflag,this,&MainWindow::slot_readyflag);
    emit signal_main_time(main_time);
    emit signal_main_time_user(main_time_user);
    emit signal_extra_time(extra_time);
    emit signal_extra_time_user(extra_time_user);
    emit signal_readyflaf(readyflag);
}

void MainWindow::createblock(int name, int main_time, int extra_time, int main_time_user, int extra_time_user, bool flag)
{
    tmpcontroller = new Time_controller();
    tmpcontroller->set_main_time(main_time);
    tmpcontroller->set_extra_time(extra_time);
    tmpcontroller->set_name(name);
    tmpcontroller->set_extra_time_user(extra_time_user);
    tmpcontroller->set_main_time_user(main_time_user);
    tmpcontroller->set_readyflag(flag);
    manager->add(tmpcontroller);
}

void MainWindow::setblock(int name, int main_time, int extra_time, int main_time_user, int extra_time_user, bool flag)
{
    controller = manager->data(name);
    controller->set_main_time(main_time);
    controller->set_extra_time(extra_time);
    controller->set_extra_time_user(extra_time_user);
    controller->set_main_time_user(main_time_user);
    controller->set_readyflag(flag);
}

void MainWindow::checkflag()
{
    for(int i=0;i<34;i++){
        controller=manager->data(i);
        QString but="button"+QString::number(i);
        QPushButton *button=findChild<QPushButton*>(but);
        if(controller->get_readyflag()==true){
        button->setText("r");
        button->setStyleSheet("background-color: rgba(255,255,255,0);"
                              "bordred: none;"
                              "color: green;}");
        }
        if(controller->get_readyflag()==false){
            if((controller->get_name()==0)or(controller->get_name()==5)or(controller->get_name()==11)or(controller->get_name()==12)or(controller->get_name()==13)or(controller->get_name()==20)or(controller->get_name()==21)or(controller->get_name()==22)or(controller->get_name()==25)or(controller->get_name()==26)or(controller->get_name()==27)or(controller->get_name()==28)or(controller->get_name()==29)or(controller->get_name()==33)or(controller->get_name()==34)){
        button->setText("nr");
        button->setStyleSheet("background-color: rgba(255,255,255,0);"
                              "bordred: none;"
                              "color: red;}");
        }
            else{
                button->setText("nr");
                button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                      "bordred: none;"
                                      "color: yellow;}");
            }
        }
        if (controller->get_readyflag()==false){
            if((controller->get_main_time()<=controller->get_main_time_user())and(controller->get_extra_time()<=controller->get_extra_time_user())){
                button->setText("to");
                button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                      "bordred: none;"
                                      "color: red;}");
            }
        }
    }
}

void MainWindow::changesize(bool flag)
{
    if (controller->get_main_time()<=controller->get_main_time_user()){
        X[gname]=-(controller->get_main_time_user()-controller->get_main_time());
        W[gname]=(controller->get_main_time_user()-controller->get_main_time());
    }
    if ((controller->get_main_time()>controller->get_main_time_user())and(flag==true)){
        X[gname]=-(controller->get_main_time_user()-controller->get_main_time());
        W[gname]=(controller->get_main_time_user()-controller->get_main_time());
    }
    if(gname==0){
        for(int i=1;i<7;i++){
            XO[i]=-X[gname]/3;
            WO[i]=-W[gname]/3;
        }
    }
    if((gname==1)or(gname==2)or(gname==3)or(gname==4)){
        for(int i=5;i<7;i++){
            XO[i]=-X[gname]/2;
            WO[i]=-W[gname]/2;
        }
    }
    if(gname==5){
        for(int i=6;i<7;i++){
            XO[i]=-X[gname]/2;
            WO[i]=-W[gname]/2;
        }
    }
    if((gname==7)or(gname==8)or(gname==9)or(gname==10)){
        for(int i=11;i<17;i++){
            XO[i]=-X[gname]/2;
            WO[i]=-W[gname]/2;
        }
    }
    if((gname==11)or(gname==12)or(gname==13)){
        for(int i=14;i<17;i++){
            XO[i]=-X[gname]/4;
            WO[i]=-W[gname]/4;
        }
    }
    if((gname==17)or(gname==18)or(gname==19)){
        for(int i=20;i<25;i++){
            XO[i]=-X[gname]/2;
            WO[i]=-W[gname]/2;
        }
    }
    if((gname==20)or(gname==21)or(gname==22)){
        for(int i=22;i<25;i++){
            XO[i]=-X[gname]/2;
            WO[i]=-W[gname]/2;
        }
    }
    if((gname==30)or(gname==31)or(gname==32)){
        for(int i=33;i<35;i++){
            XO[i]=-X[gname]/2;
            WO[i]=-W[gname]/2;
        }
    }
}


void MainWindow::on_button7_clicked()
{
    buttonconnect(7);
}


void MainWindow::on_button8_clicked()
{
    buttonconnect(8);
}


void MainWindow::on_button9_clicked()
{
    buttonconnect(9);
}


void MainWindow::on_button10_clicked()
{
    buttonconnect(10);
}


void MainWindow::on_button11_clicked()
{
    buttonconnect(11);
}


void MainWindow::on_button12_clicked()
{
    buttonconnect(12);
}


void MainWindow::on_button13_clicked()
{
    buttonconnect(13);
}


void MainWindow::on_button14_clicked()
{
    buttonconnect(14);
}


void MainWindow::on_button15_clicked()
{
    buttonconnect(15);
}


void MainWindow::on_button16_clicked()
{
    buttonconnect(16);
}


void MainWindow::on_button17_clicked()
{
    buttonconnect(17);
}


void MainWindow::on_button18_clicked()
{
    buttonconnect(18);
}


void MainWindow::on_button19_clicked()
{
    buttonconnect(19);
}


void MainWindow::on_button20_clicked()
{
    buttonconnect(20);
}


void MainWindow::on_button21_clicked()
{
    buttonconnect(21);
}


void MainWindow::on_button22_clicked()
{
    buttonconnect(22);
}


void MainWindow::on_button23_clicked()
{
    buttonconnect(23);
}


void MainWindow::on_button24_clicked()
{
    buttonconnect(24);
}


void MainWindow::on_button25_clicked()
{
    buttonconnect(25);
}


void MainWindow::on_button26_clicked()
{
    buttonconnect(26);
}


void MainWindow::on_button27_clicked()
{
    buttonconnect(27);
}


void MainWindow::on_button28_clicked()
{
    buttonconnect(28);
}


void MainWindow::on_button29_clicked()
{
    buttonconnect(29);
}


void MainWindow::on_button30_clicked()
{
    buttonconnect(30);
}


void MainWindow::on_button31_clicked()
{
    buttonconnect(31);
}


void MainWindow::on_button32_clicked()
{
    buttonconnect(32);
}


void MainWindow::on_button33_clicked()
{
    buttonconnect(33);
}


void MainWindow::on_button34_clicked()
{
    buttonconnect(34);
}


void MainWindow::on_in_clicked()
{
    QFile file("D:/oop/diplom/save.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    QString tmp;

    for(int i=0;i<manager->size();i++){
        controller=manager->data(i);
        tmp="";
        tmp+=QString::number(controller->get_name())+" ";
        tmp+=QString::number(controller->get_main_time())+" ";
        tmp+=QString::number(controller->get_main_time_user())+" ";
        tmp+=QString::number(controller->get_extra_time())+" ";
        tmp+=QString::number(controller->get_extra_time_user())+" ";
        tmp+=QVariant(controller->get_readyflag()).toString();
        tmp+="\n";
        out<<tmp;
    }
    out<<ui->have_time->text();
    out<<'\n';
    out<<ui->left_time->text();
    out<<'\n';
    out<<ui->free_time->text();
    out<<'\n';
       file.close();


}


void MainWindow::on_out_clicked()
{
    qDebug()<<manager->size();
    QFile file("D:/oop/diplom/save.txt"); // создаем объект класса QFile
        QString data; // Создаем объект класса QByteArray, куда мы будем считывать данные
        if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
            qDebug()<<manager->size();
            // если это сделать невозможно, то завершаем функцию
        file.open(QIODevice::ReadOnly);
        data = file.readAll(); //считываем все данные с файла в объект data
        //qDebug()<<data;
    if(manager->size()==0){

        int j=0;
        QString tmp;
        QString tst=" ";
        for(int i=0;i<=34;i++){

            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }

            j++;
            tmpcontroller = new Time_controller();
            tmpcontroller->set_name(tmp.toInt());

            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            tmpcontroller->set_main_time(tmp.toInt());
            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            tmpcontroller->set_main_time_user(tmp.toInt());
            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            tmpcontroller->set_extra_time(tmp.toInt());
            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            tmpcontroller->set_extra_time_user(tmp.toInt());
            tmp="";
            while(data[j]!='\n'){
                tmp+=data[j];

                j++;
            }
            j+=1;


            tmpcontroller->set_readyflag(QVariant(tmp).toBool());

            manager->add(tmpcontroller);
        }
        tmp="";
        while(data[j]!='\n'){
            tmp+=data[j];

            j++;
        }
        j+=1;
        ui->have_time->setText(tmp);
        tmp="";
        while(data[j]!='\n'){
            tmp+=data[j];

            j++;
        }
        j+=1;
        ui->left_time->setText(tmp);
        tmp="";
        while(data[j]!='\n'){
            tmp+=data[j];

            j++;
        }
        j+=1;
        ui->free_time->setText(tmp);
        file.close();
    }else{
        int j=0;
        QString tmp;
        QString tst=" ";
        for(int i=0;i<=34;i++){

            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }

            j++;
            controller = manager->data(i);
            controller->set_name(tmp.toInt());

            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            controller->set_main_time(tmp.toInt());
            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            controller->set_main_time_user(tmp.toInt());
            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            controller->set_extra_time(tmp.toInt());
            tmp="";
            while(data[j]!=' '){
                tmp+=data[j];
                j++;
            }
            j++;
            controller->set_extra_time_user(tmp.toInt());
            tmp="";
            while(data[j]!='\n'){
                tmp+=data[j];

                j++;
            }
            j+=1;


            controller->set_readyflag(QVariant(tmp).toBool());

            //manager->add(controller);
        }
        tmp="";
        while(data[j]!='\n'){
            tmp+=data[j];

            j++;
        }
        j+=1;
        ui->have_time->setText(tmp);
        tmp="";
        while(data[j]!='\n'){
            tmp+=data[j];

            j++;
        }
        j+=1;
        ui->left_time->setText(tmp);
        tmp="";
        while(data[j]!='\n'){
            tmp+=data[j];

            j++;
        }
        j+=1;
        ui->free_time->setText(tmp);
        file.close();
        for(int i=0;i<34;i++){
            controller=manager->data(i);
            QString but="button"+QString::number(i);
            QPushButton *button=findChild<QPushButton*>(but);
            if(controller->get_readyflag()==true){
            button->setText("r");
            button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                  "bordred: none;"
                                  "color: green;}");
            }
            if(controller->get_readyflag()==false){
                if((controller->get_name()==0)or(controller->get_name()==5)or(controller->get_name()==11)or(controller->get_name()==12)or(controller->get_name()==13)or(controller->get_name()==20)or(controller->get_name()==21)or(controller->get_name()==22)or(controller->get_name()==25)or(controller->get_name()==26)or(controller->get_name()==27)or(controller->get_name()==28)or(controller->get_name()==29)or(controller->get_name()==33)or(controller->get_name()==34)){
            button->setText("nr");
            button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                  "bordred: none;"
                                  "color: red;}");
            }
                else{
                    button->setText("nr");
                    button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                          "bordred: none;"
                                          "color: yellow;}");
                }
            }
            if (controller->get_readyflag()==false){
                if((controller->get_main_time()<=controller->get_main_time_user())and(controller->get_extra_time()<=controller->get_extra_time_user())){
                    button->setText("to");
                    button->setStyleSheet("background-color: rgba(255,255,255,0);"
                                          "bordred: none;"
                                          "color: red;}");
                }
            }
        }
    }

}


void MainWindow::on_have_time_textChanged(const QString &arg1)
{
    if(arg1.toInt()<0){
        ui->time_error->setText("время \nотрицательно");
    }
    if(arg1.toInt()>=0){
        ui->time_error->setText("");
    }
}


void MainWindow::on_left_time_textChanged(const QString &arg1)
{
    if(arg1.toInt()<0){
        ui->time_error->setText("время \nотрицательно");
    }
    if(arg1.toInt()>=0){
        ui->time_error->setText("");
    }
}


void MainWindow::on_free_time_textChanged(const QString &arg1)
{
    if(arg1.toInt()<0){
        ui->time_error->setText("время \nотрицательно");
    }
    if(arg1.toInt()>=0){
        ui->time_error->setText("");
    }
}

