#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::io_flag = 0;
int MainWindow::ui_flag = -1;
int MainWindow::op_flag = -1;
QString MainWindow::stno;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString kwd = "SELECT * FROM can_operate_book";
    search_query(kwd);

    sign_out.setText("Sign OUT");
    add_book.setText("Add Book");
    transcation.setText("Transaction");
    ui->verticalLayout_S->addWidget(&sign_out);
    ui->verticalLayout_S->addWidget(&add_book);
    ui->verticalLayout_S->addWidget(&transcation);
    usrn_info.setText("User Name: ");
    stID_info.setText("Student ID: ");
    sex_info.setText("Sex: ");
    prof_info.setText("Profession: ");
    loct_info.setText("Location: ");
    ui->verticalLayout_T->addWidget(&usrn_info);
    ui->verticalLayout_T->addWidget(&stID_info);
    ui->verticalLayout_T->addWidget(&sex_info);
    ui->verticalLayout_T->addWidget(&prof_info);
    ui->verticalLayout_T->addWidget(&loct_info);
    for(int i = 0 ; i < 5 ; i++)
        ui->verticalLayout_M->addWidget(&disp_info[i]);

    b_return.setText("Return");
    verify.setText("Verify");
    ui->verticalLayout_S->addWidget(&b_return);  
    bkn_info.setText("Book Name *: ");
    bka_info.setText("Book Author *: ");
    bks_info.setText("Borrow or sell? *: ");
    bkt_info.setText("Book Press Date : ");
    bkp_info.setText("Borrow Days : ");
    bkd_info.setText("Book Price : ");
    tip_info.setText("Please verify.");
    ui->verticalLayout_T->addWidget(&bkn_info);
    ui->verticalLayout_T->addWidget(&bka_info);
    ui->verticalLayout_T->addWidget(&bks_info);
    ui->verticalLayout_T->addWidget(&bkt_info);
    ui->verticalLayout_T->addWidget(&bkp_info);
    ui->verticalLayout_T->addWidget(&bkd_info);
    ui->verticalLayout_T->addWidget(&tip_info);
    for(int i = 0 ; i < 6 ; i++)
    {
        ui->verticalLayout_M->addWidget(&bk_scan[i]);
    }
    ui->verticalLayout_M->addWidget(&verify);

    bkOp.setText("Choose an operation.");  
    purchase.setText("Purchase");
    loan.setText("Borrow");
    bkID.setText("Please inter the BOOK ID.");
    ui->verticalLayout_M->addWidget(&bkOp);
    ui->verticalLayout_S->addWidget(&b_return);
    ui->verticalLayout_M->addWidget(&purchase);
    ui->verticalLayout_M->addWidget(&loan);
    ui->verticalLayout_T->addWidget(&bkID);
    ui->verticalLayout_T->addWidget(&bkID_edit);

    ui_hide();
    ui_flag = 1;
    ui_hide();
    ui_flag = 2;
    ui_hide();
    ui_flag = 0;
    connect(&W_Sin, SIGNAL(login_signal(QString)), this, SLOT(login_slot(QString)));
    connect(&sign_out, SIGNAL(clicked(bool)), this, SLOT(on_actionSign_Out_triggered()));
    connect(&add_book, SIGNAL(clicked(bool)), this, SLOT(on_actionAdd_Book_triggered()));
    connect(&transcation, SIGNAL(clicked(bool)), this, SLOT(on_actionTransaction_triggered()));
    connect(&b_return, SIGNAL(clicked(bool)), this, SLOT(b_return_slot()));
    connect(&verify, SIGNAL(clicked(bool)), this, SLOT(b_verify_slot()));
    connect(&purchase, SIGNAL(clicked(bool)), this, SLOT(b_purchase_slot()));
    connect(&loan, SIGNAL(clicked(bool)), this, SLOT(b_loan_slot()));
}

void MainWindow::on_Search_clicked()
{
    QString kwd = ui->kwdEdit->text().trimmed();
    search_query("SELECT * FROM can_operate_book WHERE Bk_Name LIKE '%"
                 + kwd
                 + "%' OR Bk_Author LIKE '%"
                 + kwd
                 + "%' OR Bk_No LIKE '%"
                 + kwd
                 + "%'");
}

void MainWindow::on_actionSign_In_triggered()
{
    W_Sin.show();
}

void MainWindow::on_actionSign_Up_triggered()
{
    W_Sup.show();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionSign_Out_triggered()
{
    io_flag = 0;
    ui_flag = 0;
    QMessageBox::information(this,tr("Info"), tr("You have logged out! "), QMessageBox::Yes);
    qApp->exit(773);
}

void MainWindow::on_actionAdd_Book_triggered()
{
    if(io_flag)
    {
        ui_hide();
        ui_flag = 1;
        ui_show();
    }
    else QMessageBox::critical(this, tr("Error"), tr("Please sign in first."), QMessageBox::Yes);
}

void MainWindow::on_actionTransaction_triggered()
{
    if(io_flag)
    {
        ui_hide();
        ui_flag = 2;
        ui_show();
        //connect(&b_return, SIGNAL(clicked(bool)), this, SLOT(b_return_slot()));
    }
    else QMessageBox::critical(this, tr("Error"), tr("Please sign in first."), QMessageBox::Yes);
}

void MainWindow::login_slot(QString st_ID)
{
    io_flag = 1;
    stno = st_ID;
    qDebug()<<"User: " + stno;
    ui->actionUser->setText("User: " + st_ID);
    ui->textBrowser->hide();
    ui->Sign_In->hide();
    ui->Sign_Up->hide();
    ui_hide();
    ui_flag = 0;
    ui_show();
    search_query("SELECT book.Bk_No, Bk_Name, Bk_Author, Bk_Status, Bk_Press, Bk_Date, Op_Price FROM book, operate WHERE book.Bk_No = operate.Bk_No AND St_No='" + st_ID + "'");
}

void MainWindow::search_query(QString kwd)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QSqlQuery query = model->query();
    model->setQuery(kwd);
    model->setHeaderData(0, Qt::Horizontal, tr("Book NO"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Author"));
    model->setHeaderData(3, Qt::Horizontal, tr("Status"));
    model->setHeaderData(4, Qt::Horizontal, tr("Press"));
    model->setHeaderData(5, Qt::Horizontal, tr("Press Date"));
    model->setHeaderData(6, Qt::Horizontal, tr("Price"));
}

void MainWindow::ui_hide()
{
    if(ui_flag == 1)
    {
        add_book.hide();
        b_return.hide();
        verify.hide();
        bkn_info.hide();
        bka_info.hide();
        bks_info.hide();
        bkt_info.hide();
        bkp_info.hide();
        bkd_info.hide();
        tip_info.hide();
        for(int i = 0 ; i < 6 ; i++)
            bk_scan[i].hide();
    }
    else if(ui_flag == 2)
    {
        transcation.hide();
        b_return.hide();
        bkID.hide();
        bkOp.hide();
        bkID_edit.hide();
        purchase.hide();
        loan.hide();
    }
    else
    {
        sign_out.hide();
        usrn_info.hide();
        stID_info.hide();
        sex_info.hide();
        prof_info.hide();
        loct_info.hide();
        for(int i = 0 ; i < 5 ; i++)
            disp_info[i].hide();
    }
}

void MainWindow::ui_show()
{
    if(ui_flag == 1)
    {
        b_return.show();
        bkn_info.show();
        bka_info.show();
        bks_info.show();
        bkt_info.show();
        bkp_info.show();
        bkd_info.show();
        tip_info.show();
        for(int i = 0 ; i < 6 ; i++)
        {
            bk_scan[i].show();
        }
        verify.show();
    }
    else if(ui_flag == 2)
    {
        b_return.show();
        bkOp.show();
        purchase.show();
        loan.show();
        bkID.show();
        bkID_edit.show();
    }
    else
    {
        sign_out.show();
        add_book.show();
        transcation.show();
        usrn_info.show();
        stID_info.show();
        sex_info.show();
        prof_info.show();
        loct_info.show();
        QString str = QString("SELECT St_Name, St_No, St_Sex, St_Profession, St_Building FROM student WHERE St_No='%1'")
                .arg(stno);
        QSqlQuery query;
        query.exec(str);
        query.first();
        for(int i = 0 ; i < 5 ; i++)
        {
            disp_info[i].setText(query.value(i).toString());
            disp_info[i].show();
        }
    }
}

void MainWindow::b_return_slot()
{
    ui_hide();
    ui_flag = 0;
    ui_show();
}

void MainWindow::b_verify_slot()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    QString bkno = QString::number(qrand() % (999999 - 100000) + 100000);
    //qDebug()<<bkno;
    QString in_book = QString("INSERT INTO book(Bk_No, Bk_Name, Bk_Author, Bk_Status, Bk_Date) VALUE ('%1', '%2', '%3', %4, '%5')")
            .arg(bkno)
            .arg(bk_scan[0].text().trimmed())
            .arg(bk_scan[1].text().trimmed())
            .arg(bk_scan[2].text().trimmed())
            .arg(bk_scan[3].text().trimmed());
    QString in_operate = QString("INSERT INTO operate VALUE('%1', '%2', '%3', '%4')")
            .arg(stno)
            .arg(bkno)
            .arg(bk_scan[4].text().trimmed())
            .arg(bk_scan[5].text().trimmed());
    QSqlQuery in;
    in.exec(in_book);
    in.exec(in_operate);
}

void MainWindow::b_purchase_slot()
{
    op_flag = 1;
    //qDebug()<<op_flag;
    update_rd();
}

void MainWindow::b_loan_slot()
{
    op_flag = 0;
    //qDebug()<<op_flag;
    update_rd();
}

void MainWindow::update_rd()
{
    QSqlQuery in, in_rd;
    QString sel = QString("SELECT St_No, Bk_Status FROM operate, book WHERE operate.Bk_No=book.Bk_No AND operate.Bk_No='%1'")
            .arg(bkID_edit.text().trimmed());
    in.exec(sel);
    QString st_S;
    QString st_O;
    while(in.next())
    {
        st_S = in.value(0).toString();
        st_O = in.value(1).toString();
    }
    QDateTime time = QDateTime::currentDateTime();
    QString now = time.toString("yyyy-MM-dd hh:mm:ss");
    //qDebug()<<str;
    QString in_record;
    if(op_flag == 0)
    {
        QString st_N = QString::number(op_flag);
        in.exec("UPDATE book SET Bk_Status=0 WHERE Bk_No='" + bkID_edit.text().trimmed() + "'");
        in.exec("UPDATE operate SET Op_Day = NULL WHERE Bk_No='" + bkID_edit.text().trimmed() + "'");
        in.exec("UPDATE operate SET Op_Price = NULL WHERE Bk_No='" + bkID_edit.text().trimmed() + "'");
        in.exec("UPDATE operate SET St_No='" + stno + "' WHERE Bk_No='" + bkID_edit.text().trimmed() + "'");
        QDateTime time_end = QDateTime::currentDateTime();
        QString end = time_end.addDays(30).toString("yyyy-MM-dd");
        in_record = QString("INSERT INTO record(Bk_No,St_No_S,St_No_C,Rd_Time,Bk_Status_O,Bk_Status_N,Rd_Time_End) VALUE ('%1','%2','%3','%4',%5,%6,'%7')")
                .arg(bkID_edit.text().trimmed())
                .arg(st_S)
                .arg(stno)
                .arg(now)
                .arg(st_O)
                .arg(st_N)
                .arg(end);
    }
    else if(op_flag == 1)
    {
        QString st_N = QString::number(op_flag);
        in.exec("UPDATE book SET Bk_Status=1 WHERE Bk_No='" + bkID_edit.text().trimmed() + "'");
        in.exec("UPDATE operate SET St_No='" + stno + "' WHERE Bk_No='" + bkID_edit.text().trimmed() + "'");
        in_record = QString("INSERT INTO record(Bk_No,St_No_S,St_No_C,Rd_Time,Bk_Status_O,Bk_Status_N) VALUE ('%1','%2','%3','%4',%5,%6)")
                .arg(bkID_edit.text().trimmed())
                .arg(st_S)
                .arg(stno)
                .arg(now)
                .arg(st_O)
                .arg(st_N);
    }
    in_rd.exec(in_record);
}

void MainWindow::on_actionReport_Bug_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("Please send the bug to hubzhang@qq.com."), QMessageBox::Yes);
}

void MainWindow::on_actionConnect_with_us_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("My e-mail address is hubzhang@qq.com."), QMessageBox::Yes);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("Share your books! "), QMessageBox::Yes);
}

void MainWindow::on_actionShare_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("Thanks! "), QMessageBox::Yes);
}

void MainWindow::on_actionUser_Guideline_triggered()
{
    QString str;
	str = QString("<h1><i>User</i> <font color = red>Guideline!</font></h1><h2>Please visit: <a href=\"http://120.79.74.191:5000/database/userguideline.html\">GUIDELINE </a></h2>");
    QLabel *lab = new QLabel(str);
    lab->setOpenExternalLinks(true);
    lab->setWindowTitle("User Guideline");
    lab->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
