#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>

namespace Ui {
class Sign_Up;
}

class Sign_Up : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_Up(QWidget *parent = 0);
    ~Sign_Up();

private:
    Ui::Sign_Up *ui;
};

#endif // SIGN_UP_H
