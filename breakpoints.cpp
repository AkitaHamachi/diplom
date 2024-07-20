#include "breakpoints.h"
#include "ui_breakpoints.h"

breakpoints::breakpoints(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::breakpoints)
{
    ui->setupUi(this);
}

breakpoints::~breakpoints()
{
    delete ui;
}
