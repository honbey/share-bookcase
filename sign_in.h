#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>

namespace Ui {
class Sign_In;
}

class Sign_In : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_In(QWidget *parent = 0);
    ~Sign_In();

private slots:
    void on_buttonBox_accepted();

signals:
    void login_signal(QString st_ID);

private:
    Ui::Sign_In *ui;
};

#endif // SIGN_IN_H
