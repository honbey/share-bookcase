#include "sign_in.h"
#include "ui_sign_in.h"
#include "mainwindow.h"

Sign_In::Sign_In(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_In)
{
    ui->setupUi(this);
}

void Sign_In::on_buttonBox_accepted()
{
    int sign_flag = 0;
    QSqlQuery query;
    if(query.exec("SELECT St_No, St_Password FROM student"))
    {
        while(query.next())
        {
            QString St_No = query.value(0).toString().trimmed();
            QString St_Password = query.value(1).toString().trimmed();
            if((ui->UsrEdit->text().trimmed() == St_No) && (ui->PwdEdit->text().trimmed() == St_Password))
                sign_flag = 1;
        }
    }

    if(sign_flag)
    {
        accept();
        emit login_signal(ui->UsrEdit->text().trimmed());
        QMessageBox::information(this, tr("Tip Box"), tr("Login Successfully"), QMessageBox::Yes);
    }
    else
    {
           QMessageBox::critical(this, tr("Error"), tr("Incorrect username or password! "), QMessageBox::Yes);
           ui->UsrEdit->clear();
           ui->PwdEdit->clear();
           ui->UsrEdit->setFocus();
    }
}

Sign_In::~Sign_In()
{
    delete ui;
}
