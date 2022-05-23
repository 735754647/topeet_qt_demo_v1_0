#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <iostream>


#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QDesktopWidget>
#include <QLabel>
#include <QFileInfo>

#define   IP_QUERY_API_URL    "http://ip.ws.126.net/ipquery"
#define   WEATHER_GET_API_URL  "http://wthrcdn.etouch.cn/weather_mini?city="

namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();


private slots:
    void buttonClick();
    void timerUpDate();
    void quitclick();
    void slotFinishedIpGetReply();
    void slotFinishedIpQueryReply();
    void slotFinishedWeatherGetReply();
private:
    Ui::frmMain *ui;
    int depx;
    int depy;

    QPalette pic;
    QLabel *msgLable;
    void InitStyle();   //初始化无边框窗体
    void InitForm();    //初始化窗体数据
    void Initpath(); //
    void InitDate();
    void weatherDisInit();


    QString bg;
    QLabel          *systime1;               // 当前时间
    QLabel          *systime2;               // 当前时间
    QLabel      * helloLabel ;
    QLabel      * topeetlabel ;

    int passtime;
    QStringList     appPathStrList;                 // app路径定义
    QStringList     iconpath;                 // app路径定义
    QStringList     weatherlist;                 // app路径定义
    QStringList      appname;                   //app名称
    QTimer          *appExecTimer;                  // 用于进入程序后过滤误触的点

    /* 天气相关 */
    QLabel *weatherIcon;           //  天气图标
    QLabel *displayWeather;        //  显示天气
    QLabel *displayCity;           //  显示城市
    QLabel *displayTemp;           //  显示温度
    QLabel *displayMinMaxTemp;     //  显示当天的最大温度和最小温度
    QNetworkAccessManager *NAManager;  //请求句柄
    QString fengli;       //风力
    QString wendu;        //温度
    QString weather_type;  //天气类型
};

#endif // FRMMAIN_H
