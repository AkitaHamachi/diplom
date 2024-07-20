#ifndef BREAKPOINTS_H
#define BREAKPOINTS_H

#include <QWidget>

namespace Ui {
class breakpoints;
}

class breakpoints : public QWidget
{
    Q_OBJECT

public:
    explicit breakpoints(QWidget *parent = nullptr);
    ~breakpoints();

private:
    Ui::breakpoints *ui;
};

#endif // BREAKPOINTS_H
