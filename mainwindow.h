#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QTime>
#include <QDateTime>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QProcess>
#include <QSqlQueryModel>
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "sign_in.h"    //use user name and password to login in
#include "sign_up.h"    //use e-mail and user name to create a user

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static int io_flag;
    static int ui_flag;
    static int op_flag;
    static QString stno;

private slots:

    void on_actionSign_In_triggered();

    void on_actionSign_Up_triggered();

    void on_actionExit_triggered();

    void on_Search_clicked();

    void login_slot(QString st_ID);

    void on_actionSign_Out_triggered();

    void on_actionAdd_Book_triggered();

    void on_actionTransaction_triggered();

    void search_query(QString kwd);

    void ui_show();

    void ui_hide();

    void b_return_slot();

    void b_verify_slot();

    void b_purchase_slot();

    void b_loan_slot();

    void update_rd();

    void on_actionReport_Bug_triggered();

    void on_actionConnect_with_us_triggered();

    void on_actionAbout_triggered();

    void on_actionShare_triggered();

    void on_actionUser_Guideline_triggered();

private:
    Ui::MainWindow *ui;
    Sign_In W_Sin;
    Sign_Up W_Sup;

    QPushButton sign_out;
    QPushButton add_book;
    QPushButton transcation;
    QPushButton b_return;
    QLabel usrn_info;
    QLabel stID_info;
    QLabel sex_info;
    QLabel prof_info;
    QLabel loct_info;
    QLabel disp_info[5];

    QPushButton verify;
    QLabel bkn_info;
    QLabel bka_info;
    QLabel bks_info;
    QLabel bkt_info;
    QLabel bkp_info;
    QLabel bkd_info;
    QLabel tip_info;
    QLineEdit bk_scan[6];

    QLabel bkID;
    QLabel bkOp;
    QLineEdit bkID_edit;
    QPushButton purchase;
    QPushButton loan;
};

#endif // MAINWINDOW_H
