#include "sign_up.h"
#include "ui_sign_up.h"
#include "mainwindow.h"

Sign_Up::Sign_Up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_Up)
{
    ui->setupUi(this);
}

Sign_Up::~Sign_Up()
{
    delete ui;
}
