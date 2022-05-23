#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,QApplication::desktop()->screenGeometry().width(),QApplication::desktop()->screenGeometry().height());
    //this->setGeometry(0,0,800,480);
    this->setStyleSheet("border-image:url(Resource/background/main.jpg)");
    this->setWindowFlags(Qt::FramelessWindowHint);

    QFont font;
    font.setPixelSize((float)15/800*this->geometry().width());

    /*                      测试网络                  */
    netTextBrowser = new QTextBrowser(this);
    netTextBrowser->setGeometry((float)100/800*this->geometry().width(),(float)80/480*this->geometry().height(),
                                (float)200/800*this->geometry().width(),(float)310/480*this->geometry().height());
    netTextBrowser->setFrameShape(QTextBrowser::NoFrame);
    QPalette pal1;
    pal1.setColor(QPalette::Base, QColor(40,40,40,255));//改变背景色
    netTextBrowser->setPalette(pal1);
    netTextBrowser->verticalScrollBar()->setStyleSheet(VERTICAL_STYLE);
    netTextBrowser->setStyleSheet("color:white;border-image:transparent");
    netTextBrowser->setFont(font);

    netProcess = new QProcess(this);
    connect(netProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(np_readyReadStandardOutput()));

    /* 优化滚动效果 */
    netVscroll = new Vscroll(this);
    netVscroll->setObjectScrollBar(netTextBrowser->verticalScrollBar()); //指定优化的对象
    netVscroll->setObjectList(netTextBrowser);//指定对象列表
    connect(netTextBrowser,SIGNAL(cursorPositionChanged()),this,SLOT(tb_selectClear()));

    /*                      测试ap3216                 */
    ap3216TextBrowser = new QTextBrowser(this);
    ap3216TextBrowser->setGeometry((float)300/800*this->geometry().width(),(float)80/480*this->geometry().height(),
                                   (float)200/800*this->geometry().width(),(float)310/480*this->geometry().height());
    ap3216TextBrowser->setFrameShape(QTextBrowser::NoFrame);
    ap3216TextBrowser->setFont(font);
    QPalette pal2;
    pal2.setColor(QPalette::Base, QColor(40,40,40,255));//改变背景色
    ap3216TextBrowser->setPalette(pal2);
    ap3216TextBrowser->verticalScrollBar()->setStyleSheet(VERTICAL_STYLE);
    ap3216TextBrowser->setStyleSheet("color:white;border-image:transparent");

    ap3216Process = new QProcess(this);
    connect(ap3216Process,SIGNAL(readyReadStandardOutput()),this,SLOT(ap_readyReadStandardOutput()));
    /* 优化滚动效果 */
    ap3216Vscroll = new Vscroll(this);
    ap3216Vscroll->setObjectScrollBar(ap3216TextBrowser->verticalScrollBar()); //指定优化的对象
    ap3216Vscroll->setObjectList(ap3216TextBrowser);//指定对象列表
    connect(ap3216TextBrowser,SIGNAL(cursorPositionChanged()),this,SLOT(tb_selectClear()));

    /*                      测试mpu6050                */
    mpu6050TextBrowser = new QTextBrowser(this);
    mpu6050TextBrowser->setGeometry((float)500/800*this->geometry().width(),(float)80/480*this->geometry().height(),
                                     (float)200/800*this->geometry().width(),(float)310/480*this->geometry().height());
    mpu6050TextBrowser->setFrameShape(QTextBrowser::NoFrame);
    mpu6050TextBrowser->setFont(font);
    QPalette pal3;
    pal3.setColor(QPalette::Base, QColor(40,40,40,255));//改变背景色
    mpu6050TextBrowser->setPalette(pal3);
    mpu6050TextBrowser->verticalScrollBar()->setStyleSheet(VERTICAL_STYLE);
    mpu6050TextBrowser->setStyleSheet("color:white;border-image:transparent");

    mpu6050Process = new QProcess(this);
    //    mpu6050Process->start("./Resource/cmd/mpu6050autotest.sh");
    connect(mpu6050Process,SIGNAL(readyReadStandardOutput()),this,SLOT(ic_readyReadStandardOutput()));
    /* 优化滚动效果*/
    mpu6050Vscroll = new Vscroll(this);
    mpu6050Vscroll->setObjectScrollBar(mpu6050TextBrowser->verticalScrollBar()); //指定优化的对象
    mpu6050Vscroll->setObjectList(mpu6050TextBrowser);//指定对象列表
    connect(mpu6050TextBrowser,SIGNAL(cursorPositionChanged()),this,SLOT(tb_selectClear()));

    enterexitanimation = new Enterexitanimation(this);
    enterexitanimation->setGeometry(this->geometry().width()-48,0,48,48); //设置位置
    enterexitanimation->setAnimationObject(this);//设置动画对象

    timer = new QTimer(this);
    timer->start(1000); // 1s后才开启进程

    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));
}

void MainWindow::np_readyReadStandardOutput()
{
    QByteArray bytes = netProcess->readAll();
    QTextCodec *tc = QTextCodec::codecForName("GBK");//避免中文乱码
    QString tmpQStr = tc->toUnicode(bytes);
    netTextBrowser->insertPlainText(tmpQStr);
    netTextBrowser->moveCursor(QTextCursor::End);//自动滑动到最后一行
}

void MainWindow::ap_readyReadStandardOutput()
{
    QByteArray bytes = ap3216Process->readAll();
    QTextCodec *tc = QTextCodec::codecForName("GBK");//避免中文乱码
    QString tmpQStr = tc->toUnicode(bytes);
    ap3216TextBrowser->setText(tmpQStr);
    ap3216TextBrowser->moveCursor(QTextCursor::End);//自动滑动到最后一行
}

void MainWindow::ic_readyReadStandardOutput()
{
    QByteArray bytes = mpu6050Process->readAll();
    QTextCodec *tc = QTextCodec::codecForName("GBK");//避免中文乱码
    QString tmpQStr = tc->toUnicode(bytes);
    mpu6050TextBrowser->setText(tmpQStr);
    mpu6050TextBrowser->moveCursor(QTextCursor::End);//自动滑动到最后一行
}

void MainWindow::tb_selectClear()
{
    netTextBrowser->textCursor().clearSelection();//清除选择的文本
}

void MainWindow::timerTimeOut()
{
    timer->stop();
    mpu6050Process->start("./Resource/cmd/mpu6050test.sh");
    netProcess->start("./Resource/cmd/netautotest.sh");
    ap3216Process->start("./Resource/cmd/ap3216autotest.sh");
}

MainWindow::~MainWindow()
{
    netProcess->kill();
    mpu6050Process->kill();
    ap3216Process->kill();
    delete ui;
}

