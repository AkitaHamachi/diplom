#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <breakpoints.h>
#include <settings.h>
#include<time_controller.h>
#include <time_manager.h>
#include <math.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *)
        {
            QPainter painter(this);
            QPen pen;
            pen.setWidth(5);
            painter.setPen(pen);
            painter.drawLine(0 , 394, 1500, 394);
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(118, 50, 118, 660);
            painter.setPen(pen);
            painter.drawLine(250, 50, 250, 660);
            pen.setStyle(Qt::DashDotLine);
            painter.setPen(pen);
            painter.drawLine(170, 110, 170, 660);
            painter.drawLine(327, 110, 327, 660);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
            painter.drawLine(290, 230, 290, 660);
            pen.setStyle(Qt::DashDotLine);
            painter.setPen(pen);
            painter.drawLine(410, 280, 410, 660);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
            painter.drawLine(501, 220, 501, 660);
            painter.drawLine(631, 320, 631, 660);
            pen.setStyle(Qt::DashDotLine);
            painter.setPen(pen);
            painter.drawLine(711, 250, 711, 660);
            painter.drawLine(746, 350, 746, 660);
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
            painter.drawLine(816 , 300, 816, 660);
            painter.drawLine(866 , 350, 866, 660);
            painter.drawLine(1051 , 370, 1051, 660);
            pen.setStyle(Qt::DashDotLine);
            painter.setPen(pen);
            painter.drawLine(916 , 230, 916, 660);

            /////////////////////////////////////////////////////////////

            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
            painter.drawLine(125, 111, 150, 111);//
            painter.drawLine(180, 111, 230, 111);//
            painter.drawLine(125, 80, 150, 80);//
            painter.drawLine(180, 80, 230, 80);//
            painter.drawLine(260, 190, 310, 190);//
            painter.drawLine(310, 220, 350, 220);//
            painter.drawLine(260, 265, 295, 265);//
            painter.drawLine(450, 265, 485, 265);//
            painter.drawLine(430, 280, 540, 280);//
            painter.drawLine(660, 280, 900, 280);//
            painter.drawLine(655, 305, 690, 305);//
            painter.drawLine(505, 305, 535, 305);//
            painter.drawLine(645, 325, 670, 325);//
            painter.drawLine(760, 325, 800, 325);//
            painter.drawLine(760, 355, 800, 355);
            painter.drawLine(825, 355, 850, 355);

            ///////////////////////////////
            QBrush brush;
            brush.setColor(Qt::black);
            brush.setStyle(Qt::SolidPattern);
            QPolygon pol;
            pol<<QPoint(125,80)<<QPoint(130,87)<<QPoint(130,73);
            painter.setBrush(brush);
            painter.drawPolygon(pol);
            QPolygon pol1;
            pol1<<QPoint(150,111)<<QPoint(145,118)<<QPoint(145,104);
            painter.setBrush(brush);
            painter.drawPolygon(pol1);
            QPolygon pol2;
            pol2<<QPoint(180,111)<<QPoint(185,118)<<QPoint(185,104);
            painter.setBrush(brush);
            painter.drawPolygon(pol2);
            QPolygon pol3;
            pol3<<QPoint(230,80)<<QPoint(225,87)<<QPoint(225,73);
            painter.setBrush(brush);
            painter.drawPolygon(pol3);
            QPolygon pol4;
            pol4<<QPoint(310,190)<<QPoint(305,197)<<QPoint(305,183);
            painter.setBrush(brush);
            painter.drawPolygon(pol4);
            QPolygon pol5;
            pol5<<QPoint(310,220)<<QPoint(315,227)<<QPoint(315,213);
            painter.setBrush(brush);
            painter.drawPolygon(pol5);
            QPolygon pol6;
            pol6<<QPoint(260,265)<<QPoint(265,272)<<QPoint(265,258);
            painter.setBrush(brush);
            painter.drawPolygon(pol6);
            QPolygon pol7;
            pol7<<QPoint(485,265)<<QPoint(480,272)<<QPoint(480,258);
            painter.setBrush(brush);
            painter.drawPolygon(pol7);
            QPolygon pol8;
            pol8<<QPoint(430,280)<<QPoint(435,287)<<QPoint(435,273);
            painter.setBrush(brush);
            painter.drawPolygon(pol8);
            QPolygon pol9;
            pol9<<QPoint(900,280)<<QPoint(895,287)<<QPoint(895,273);
            painter.setBrush(brush);
            painter.drawPolygon(pol9);
            QPolygon pol10;
            pol10<<QPoint(690,305)<<QPoint(685,298)<<QPoint(685,312);
            painter.setBrush(brush);
            painter.drawPolygon(pol10);
            QPolygon pol11;
            pol11<<QPoint(505,305)<<QPoint(510,298)<<QPoint(510,312);
            painter.setBrush(brush);
            painter.drawPolygon(pol11);
            QPolygon pol12;
            pol12<<QPoint(645,325)<<QPoint(650,318)<<QPoint(650,332);
            painter.setBrush(brush);
            painter.drawPolygon(pol12);
            QPolygon pol13;
            pol13<<QPoint(800,325)<<QPoint(795,318)<<QPoint(795,332);
            painter.setBrush(brush);
            painter.drawPolygon(pol13);
            QPolygon pol14;
            pol14<<QPoint(760,355)<<QPoint(765,348)<<QPoint(765,362);
            painter.setBrush(brush);
            painter.drawPolygon(pol14);
            QPolygon pol15;
            pol15<<QPoint(850,355)<<QPoint(845,348)<<QPoint(845,362);
            painter.setBrush(brush);
            painter.drawPolygon(pol15);
            ////////////////////
            painter.drawLine(650, 252, 660, 252);
            painter.drawLine(660, 252, 660, 30);
            painter.drawLine(190, 30, 660, 30);
            painter.drawLine(190, 30, 190, 45);
            QPolygon pol16;
            pol16<<QPoint(190,45)<<QPoint(183,40)<<QPoint(197,40);
            painter.setBrush(brush);
            painter.drawPolygon(pol16);
            painter.drawLine(650, 252, 700, 252);
            painter.drawLine(700, 252, 700, 60);
            painter.drawLine(680, 60, 700, 60);
            painter.drawLine(660, 50, 680, 60);
            painter.drawLine(640, 60, 660, 50);
            painter.drawLine(265, 60, 640, 60);
            painter.drawLine(265, 60, 265, 140);
            QPolygon pol17;
            pol17<<QPoint(265,140)<<QPoint(272,135)<<QPoint(258,135);
            painter.setBrush(brush);
            painter.drawPolygon(pol17);
            painter.drawLine(850, 252, 870, 252);
            painter.drawLine(870, 252, 870, 100);
            painter.drawLine(720, 100, 870, 100);
            painter.drawLine(700, 90, 720, 100);
            painter.drawLine(680, 100, 700, 90);
            painter.drawLine(660, 90, 680, 100);
            painter.drawLine(640, 100, 660, 90);
            painter.drawLine(410, 100, 640, 100);
            painter.drawLine(410, 100, 410, 140);
            QPolygon pol18;
            pol18<<QPoint(410,140)<<QPoint(417,135)<<QPoint(403,135);
            painter.setBrush(brush);
            painter.drawPolygon(pol18);
            painter.drawLine(950, 280, 980, 280);
            painter.drawLine(980, 280, 980, 150);
            painter.drawLine(890, 150, 980, 150);
            painter.drawLine(870, 140, 890, 150);
            painter.drawLine(850, 150, 870, 140);

            painter.drawLine(720, 150, 850, 150);
            painter.drawLine(700, 140, 720, 150);
            painter.drawLine(680, 150, 700, 140);
            painter.drawLine(660, 140, 680, 150);
            painter.drawLine(640, 150, 660, 140);
            painter.drawLine(430, 150, 640, 150);
            painter.drawLine(430, 200, 430, 150);
            QPolygon pol19;
            pol19<<QPoint(430,200)<<QPoint(437,195)<<QPoint(423,195);
            painter.setBrush(brush);
            painter.drawPolygon(pol19);
            //////////////////////////
            painter.drawLine(0, 440, 1500, 440);
            painter.drawLine(0, 480, 1500, 480);
            painter.drawLine(0, 530, 1500, 530);
            painter.drawLine(0, 570, 1500, 570);
            painter.drawLine(0, 610, 1500, 610);
            //////////////////
            pen.setCapStyle(Qt::RoundCap);
            if(X[0]>-10){
            painter.drawRect(128+X[0],410,32+W[0]*2,15);
            }
            else{
                painter.drawRect(128-10,410,32+10*2,15);
            }
            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if(X[1]+X[2]+X[3]+XO[4]+XO[1]+XO[2]+XO[3]+XO[4]>-10){
            painter.drawRect(180+X[1]+X[2]+X[3]+XO[4]+XO[1]+XO[2]+XO[3]+XO[4],410,220+(W[1]+W[2]+W[3]+W[4]+WO[1]+WO[2]+WO[3]+WO[4])*2,15);
            }
            else{
                painter.drawRect(180-10,410,220+10*2,15);
            }

            brush.setColor(Qt::black);
            painter.setBrush(brush);
            if(X[5]+XO[5]>-9){
            painter.drawRect(418+X[5]+XO[5],410,74+(W[5]+WO[5])*2,15);
            }
            else{
                painter.drawRect(418-9,410,74+9*2,15);
            }

            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if(X[6]+XO[6]>-10){
            painter.drawRect(510+X[6]+XO[6],410,110+(W[6]+WO[6])*2,15);
            }
            else{
                painter.drawRect(510-10,410,110+10*2,15);
            }

            //brush.setColor(Qt::black);
            //painter.setBrush(brush);
            //painter.drawRect(840,410,70,15);
            //brush.setColor(Qt::gray);
            //painter.setBrush(brush);
            //painter.drawRect(930,410,100,15);
            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if(X[7]+X[8]+X[9]+X[10]+XO[7]+XO[8]+XO[9]+XO[10]>-10){
            painter.drawRect(190+X[7]+X[8]+X[9]+X[10]+XO[7]+XO[8]+XO[9]+XO[10],451,200+(W[7]+W[8]+W[9]+W[10]+WO[7]+WO[8]+WO[9]+WO[10])*2,15);
            }
            else{
                painter.drawRect(190-10,451,200+10*2,15);
            }

            brush.setColor(Qt::black);
            painter.setBrush(brush);
            if(X[11]+X[12]+X[13]+XO[11]+XO[12]+XO[13]>-10){
            painter.drawRect(432+X[11]+X[12]+X[13]+XO[11]+XO[12]+XO[13],451,250+(W[11]+W[12]+W[13]+WO[11]+WO[12]+WO[13])*2,15);
            }
            else{
                painter.drawRect(432-10,451,250+10*2,15);
            }

            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if(X[14]+X[15]+X[16]+XO[14]+XO[15]+XO[16]>-10){
            painter.drawRect(725+X[14]+X[15]+X[16]+XO[14]+XO[15]+XO[16],451,125+(W[14]+W[15]+W[16]+WO[14]+WO[15]+WO[16])*2,15);
            }
            else{
                painter.drawRect(725-10,451,125+10*2,15);
            }
            if(X[17]+X[18]+X[19]+XO[17]+XO[18]+XO[19]>-10){
            painter.drawRect(360+X[17]+X[18]+X[19]+XO[17]+XO[18]+XO[19],491,240+(W[17]+W[18]+W[19]+WO[17]+WO[18]+WO[19])*2,15);
            }
            else{
                painter.drawRect(360-10,491,240+10*2,15);
            }

            brush.setColor(Qt::black);
            painter.setBrush(brush);
            if(X[20]+X[21]+X[22]+XO[20]+XO[21]+XO[22]>-10){
            painter.drawRect(650+X[20]+X[21]+X[22]+XO[20]+XO[21]+XO[22],491,145+(W[20]+W[21]+W[22]+WO[20]+WO[21]+WO[22])*2,15);
            }
            else{
                painter.drawRect(650-10,491,145+10*2,15);
            }

            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if(X[23]+X[24]+XO[23]+XO[24]>-10){
            painter.drawRect(835+X[23]+X[24]+XO[23]+XO[24],491,65+(W[23]+W[24]+WO[23]+WO[24])*2,15);
            }
            else{
                painter.drawRect(835-10,491,65+10*2,15);
            }

            brush.setColor(Qt::black);
            painter.setBrush(brush);
            if(X[25]+X[26]+X[27]+X[28]+X[29]>-10){
            painter.drawRect(650+X[25]+X[26]+X[27]+X[28]+X[29],543,250+(W[25]+W[26]+W[27]+W[28]+W[29])*2,15);
            }
            else{
                painter.drawRect(650-10,543,250+10*2,15);
            }

            //brush.setColor(Qt::gray);
            //painter.setBrush(brush);
            //painter.drawRect(930,543,100,15);
            brush.setColor(Qt::gray);
            painter.setBrush(brush);
            if(X[30]+X[31]+X[32]+XO[30]+XO[31]+XO[32]>-10){
            painter.drawRect(670+X[30]+X[31]+X[32]+XO[30]+XO[31]+XO[32],581,120+(W[30]+W[31]+W[32]+WO[30]+WO[31]+WO[32])*2,15);
            }
            else{
                painter.drawRect(670-10,581,120+10*2,15);
            }

            brush.setColor(Qt::black);
            painter.setBrush(brush);
            if(X[33]+X[34]+XO[33]+XO[34]>-10){
            painter.drawRect(840+X[33]+X[34]+XO[33]+XO[34],581,60+(W[33]+W[34]+WO[33]+WO[34])*2,15);
            }
            else{
                painter.drawRect(840-10,581,60+10*2,15);
            }

            //////////////////
            painter.drawLine(0, 660, 1500, 660);
        }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_init_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button0_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_button10_clicked();

    void on_button11_clicked();

    void on_button12_clicked();

    void on_button13_clicked();

    void on_button14_clicked();

    void on_button15_clicked();

    void on_button16_clicked();

    void on_button17_clicked();

    void on_button18_clicked();

    void on_button19_clicked();

    void on_button20_clicked();

    void on_button21_clicked();

    void on_button22_clicked();

    void on_button23_clicked();

    void on_button24_clicked();

    void on_button25_clicked();

    void on_button26_clicked();

    void on_button27_clicked();

    void on_button28_clicked();

    void on_button29_clicked();

    void on_button30_clicked();

    void on_button31_clicked();

    void on_button32_clicked();

    void on_button33_clicked();

    void on_button34_clicked();

    void on_in_clicked();

    void on_out_clicked();

    void on_have_time_textChanged(const QString &arg1);

    void on_left_time_textChanged(const QString &arg1);

    void on_free_time_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    breakpoints breakpointsform;
    Settings *sett;
    Time_controller *controller;
    Time_controller *tmpcontroller;
    Time_controller *tmpcontroller1;
    time_manager *manager;
public:
    void buttonconnect(int name);
    void createblock (int name, int main_time, int extra_time, int main_time_user, int extra_time_user,bool flag);
    void setblock (int name, int main_time, int extra_time, int main_time_user, int extra_time_user,bool flag);
    void checkflag();
    void changesize(bool flag);
signals:
    void signal(int);
    void signal_main_time(int);
    void signal_main_time_user(int);
    void signal_extra_time(int);
    void signal_extra_time_user(int);
    void signal_readyflaf(bool);
public slots:
    void slotForm(int name);
    void slot_main_time(int time);
    void slot_extra_time(int time);
    void slot_main_time_user(int time);
    void slot_extra_time_user(int time);
    void slot_readyflag(bool flag);
private:
    int X[35];
    int W[35];
    int XO[35];
    int WO[35];
};
#endif // MAINWINDOW_H
