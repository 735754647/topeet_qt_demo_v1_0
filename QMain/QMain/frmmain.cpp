#include "frmmain.h"
#include "ui_frmmain.h"
#include <QtGui>
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextCodec>
#include <QLabel>
#include <QImage>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QScreen>
#include <QRect>
#include <QStringList>
#include <QTime>
#include <QPixmap>


frmMain::frmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMain)
{
    passtime = 2;
    ui->setupUi(this);



    //printf("%d,%d\n",QApplication::desktop()->screenGeometry().width(),QApplication::desktop()->screenGeometry().height());

    depx = QApplication::desktop()->screenGeometry().width();
    depy = QApplication::desktop()->screenGeometry().height();


    this->weatherDisInit();
    this->InitDate();
    this->Initpath();
    this->InitStyle();

    appExecTimer = new QTimer(this);
    pic.setBrush(QPalette::Background,QBrush(QPixmap(":./image/main8.jpg").scaled(this->size())));
    this->setPalette(pic);

    this->InitForm();



}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::InitDate()
{
    helloLabel = new QLabel(this);
    topeetlabel = new QLabel(this);
    systime1 = new QLabel(this);
    systime2 = new QLabel(this);
    QFont font;//( "PangMenZhengDao");
//    QFrame* tab = new QFrame(this);

//    //system("ntpdate -u ntp.api.bz");
//    system("hwclock -w");
//    system("mv /etc/localtime /etc/localtime.bak");
//    system("ln -s /usr/share/zoneinfo/Asia/Hong_Kong  /etc/localtime");


    helloLabel->setGeometry(0,0,depx,depy/15);//设置标签最小尺寸
    font.setPixelSize((float)depy/20);
    helloLabel->setFont(font);
    helloLabel->setText(tr("欢迎来到迅为Linux社区"));
    helloLabel->setAlignment(Qt::AlignCenter);
    helloLabel->setStyleSheet("background-color: rgba(255, 255, 255, 20%);color:white");


//    tab->setGeometry(QRect(0,depy/15,depx,depy/15));
//    tab->setFrameShape(QFrame::HLine);
//    tab->setFrameShadow(QFrame::Sunken);
//    tab->raise();
//    tab->setStyleSheet("border-top: 2px solid black;background:transparent");


    //font.setFamily("PangMenZhengDao");
    font.setBold(true);

    //clock
    systime1->setGeometry(0,depy/7,depx/5,depy/6);//设置标签最小尺寸
    font.setPixelSize((float)depy/12);
    systime1->setFont(font);
    systime1->setAlignment(Qt::AlignRight);
    systime1->setStyleSheet("background:transparent;color:white");


    systime2->setGeometry(0,depy/4,depx/5,depy/12);//设置标签最小尺寸
    font.setPixelSize((float)depy/24);
    systime2->setFont(font);
    systime2->setAlignment(Qt::AlignRight);
    systime2->setStyleSheet("background:transparent;color:white");


    topeetlabel->setGeometry(0,depy-20,depx,20);//设置标签最小尺寸
    topeetlabel->setAlignment(Qt::AlignRight);
    topeetlabel->setStyleSheet("background:transparent;color:white");
    topeetlabel->setText(tr("www.topeetboard.com "));

    QTimer *CurrentTime = new QTimer(this);
    CurrentTime->start(1000);
    connect(CurrentTime,SIGNAL(timeout()),this,SLOT(timerUpDate()));


}

void frmMain::timerUpDate()
{
    QDateTime currentTime = QDateTime::currentDateTime();

    systime1->setText(currentTime.toString("hh:mm"));
    systime2->setText(currentTime.toString("yyyy年M月dd日"));

}


void frmMain::Initpath()
{
    appPathStrList  <<"../QMusicPlayer/QMusicPlayer"
                    <<"../QMediaPlayer/QMediaPlayer"
                    <<"../QOnlineWeather/QOnlineWeather"
                    <<"../QWebBrowser/QWebBrowser"
                    <<"../QClock/QClock"
                    <<"../QFileView/QFileView"
                    <<"../QCamera/QCamera"
                    <<"../QPictureViewer/QPictureViewer"
                    <<"../QNotepad/QNotepad"
                    <<"../QCalculator/QCalculator"
                    <<"../QCalendar/QCalendar"
                    <<"../QRecorder/QRecorder"
                    <<"../QLed/QLed"
                    <<"../QTemperature/QTemperature"
                    <<"../QAutotest/QAutotest";


            appname     <<"音乐"
                    <<"媒体"
                    <<"天气"
                    <<"浏览器"
                    <<"时钟"
                    <<"文件"
                    <<"相机"
                    <<"相册"
                    <<"便签"
                    <<"计算器"
                    <<"日历"
                    <<"录音"
                    <<"LED"
                    <<"温度"
                    <<"测试";

            iconpath<<":./icon/1.png"
                    <<":./icon/2.png"
                    <<":./icon/3.png"
                    <<":./icon/4.png"
                    <<":./icon/5.png"
                    <<":./icon/6.png"
                    <<":./icon/7.png"
                    <<":./icon/8.png"
                    <<":./icon/9.png"
                    <<":./icon/10.png"
                    <<":./icon/11.png"
                    <<":./icon/12.png"
                    <<":./icon/13.png"
                    <<":./icon/14.png"
                    <<":./icon/15.png";
            weatherlist <<"冰雹"
                        <<"大雨"
                        <<"多云"
                        <<"多云转晴"
                        <<"雷阵雨"
                        <<"雷阵雨转晴"
                        <<"晴"
                        <<"沙尘暴"
                        <<"霜"
                        <<"雾霾"
                        <<"小雪"
                        <<"小雪转中雪"
                        <<"夜间多云"
                        <<"夜间多云转晴"
                        <<"夜间晴"
                        <<"阴"
                        <<"雨夹冰雹"
                        <<"雨夹雪"
                        <<"中雨"
                        <<"中雨转晴"
                       <<"未定义";


}

void frmMain::weatherDisInit(void) {

    QFont font;
    /* 城市 */
    displayCity = new QLabel(this);
    displayCity->setGeometry(0,depy*1/3,depx/5,depy/10);
    displayCity->setStyleSheet("QLabel {color: white;border-image: transparent}");
    displayCity->setAlignment(Qt::AlignCenter);
    displayCity->setText("加载中...");
    font.setPixelSize(depy/20);
    displayCity->setFont(font);

    /* 天气类型 */
    displayWeather = new QLabel(this);
    displayWeather->setGeometry(0,depy*13/30,depx/5,depy/5);
    displayWeather->setStyleSheet("QLabel {color: white;border-image: transparent}");
    displayWeather->setAlignment(Qt::AlignRight);
    displayWeather->setText("晴");
    font.setPixelSize(depy/15);
    displayWeather->setFont(font);

    /*icon*/
    weatherIcon = new QLabel(this);
    weatherIcon->setGeometry(0,depy*6/12,depx/5,depy/5);
    weatherIcon->setAlignment(Qt::AlignLeft);
    weatherIcon->setScaledContents(true);
    //           setScaleContents(true);
    weatherIcon->setPixmap(QPixmap(":./weatherIcon/7.png"));
    //weatherIcon->setStyleSheet("QLabel{border-image:url(./weatherIcon/7.png);}");
    weatherIcon->installEventFilter(this);

    /* 当前温度 */
    displayTemp = new QLabel(this);
    displayTemp->setGeometry(0,depy*2/3,depx/5,depy/8);
    displayTemp->setStyleSheet("QLabel { color: white;background: transparent;border-image:transparent}");
    displayTemp->setAlignment(Qt::AlignRight);
    displayTemp->setText("26℃");
    font.setPixelSize(depy/10);
    displayTemp->setFont(font);

    /* 当日温度最大值、最小值 */
    displayMinMaxTemp = new QLabel(this);
    displayMinMaxTemp->setGeometry(0,depy*8/10,depx/5,depy/20);
    displayMinMaxTemp->setStyleSheet("QLabel { color: white;border-image: transparent}");
    displayMinMaxTemp->setAlignment(Qt::AlignRight);
    displayMinMaxTemp->setText("20℃~28℃");
    font.setPixelSize(depy/25);
    displayMinMaxTemp->setFont(font);



    NAManager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    slotFinishedIpGetReply();


}

void frmMain::slotFinishedIpGetReply()
{
    /* 获取ip地址 发送请求 */
    QNetworkRequest  ipQueryNRequest;
    ipQueryNRequest.setUrl(QUrl(IP_QUERY_API_URL));
    QNetworkReply *ipReply = NAManager->get(ipQueryNRequest);
    connect(ipReply, SIGNAL(finished()), this, SLOT(slotFinishedIpQueryReply()));

//    ipQueryNRequest.setUrl(QUrl(TIME_QUERY_API_URL)); //获取网络时间
//    QNetworkReply *timeReply = NAManager->get(ipQueryNRequest);
//    connect(timeReply, SIGNAL(finished()), this, SLOT(slotFinishedTimeGetReply()));
}

void frmMain::slotFinishedIpQueryReply(void)
{

//    static QFont font;
//    font.setPointSize(depy/20);
    QNetworkReply *reply = (QNetworkReply *)sender();
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString temp = codec->toUnicode(reply->readAll());
    reply->deleteLater();

    /* 判断字符串是否为空 */
    if (temp.isEmpty() ||
            temp.isNull()) {
//        displayCity->setFont(font);
        displayCity->setText("定位失败");
        return;
    }

    /* 提取city字段 */
    int length = temp.length(); // 得到字符串长度
    int startIndex = temp.indexOf("city:") + 6;  // city:广州市,
    int endIndex = -1;

    if (5 == startIndex) { // 表示不存在city字段 -1
//        displayCity->setFont(font);
        displayCity->setText("定位失败");
        return;
    }

    for (int i = startIndex; i < length; i++) {

        if (',' == temp.at(i)) {
            endIndex = i;
            break;
        }
    }

    if (-1 == endIndex) {
//        displayCity->setFont(font);
        displayCity->setText("定位失败");
        return;
    }

    /* 获取城市名 发送请求 */
    QString cityName = temp.mid(startIndex, endIndex - startIndex - 1);
    QNetworkRequest  weatherGetNRequest;
    weatherGetNRequest.setUrl(QUrl(WEATHER_GET_API_URL + cityName));
    QNetworkReply *newReply = NAManager->get(weatherGetNRequest);
    connect(newReply, SIGNAL(finished()), this, SLOT(slotFinishedWeatherGetReply()));
}

void frmMain::slotFinishedWeatherGetReply(void)
{
    int i;
    //font.setPointSize(depy/20);
    QNetworkReply *reply = (QNetworkReply *)sender();
    QString temp = reply->readAll();
    reply->deleteLater();
    //qDebug() << temp << endl;

    if (temp.isEmpty() ||
            temp.isNull() ) {
        displayCity->setText("定位失败");
        //displayCity->setFont(font);
        return;
    }

    /* 创建Json相关对象 */
    QJsonParseError error;
    QJsonObject jsonObj;
    QJsonDocument jsonDocument;
    QString data;

//    font.setPointSize(depy/20);
    /* 解析Jason字符串 获取天气预告信息 */
    jsonDocument = QJsonDocument::fromJson(temp.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {

        if (jsonDocument.isNull() || jsonDocument.isEmpty()) {
            displayCity->setText("定位失败");
//            displayCity->setFont(font);
        }
        else {
            //displayCity->setFont(font);
            if (jsonDocument.isObject()) {
                jsonObj = jsonDocument.object();
                jsonObj = jsonObj.value("data").toObject();

                data = jsonObj.value("city").toString();
                displayCity->setText(data);

                data = jsonObj.value("wendu").toString() + "℃";
                displayTemp->setText(data);

                QJsonArray forecast1 = jsonObj.value("forecast").toArray();
                QJsonObject object = forecast1.at(0).toObject();
                data = object.value("low").toString().mid(3, 3) + "~";
                data += object.value("high").toString().mid(3, 3);

                //font.setPointSize(depy/20);
                displayMinMaxTemp->setText(data);

                data = object.value("type").toString();
                displayWeather->setText(data);
                for(i=0;i<20;i++){
                    if(data ==weatherlist[i])
                    {
                        data = ":./weatherIcon/" + QString::number(i+1) + ".png";
                        break;
                    }
                    if(i == 19)
                        data = ":./weatherIcon/21.png";
                }
                weatherIcon->setPixmap(QPixmap(data));
            }
            else {
                displayCity->setText("定位失败");
            }
        }
    }
    else {
        displayCity->setText("定位失败");
    }

    system("/usr/sbin/ntpdate -u ntp.api.bz");
    system("/sbin/hwclock -w");
    system("mv /etc/localtime /etc/localtime.bak");
    system("ln -s /usr/share/zoneinfo/Asia/Hong_Kong  /etc/localtime");
}

void frmMain::InitStyle()
{
    //this->mousePressed = false;
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->showMaximized();

}

void frmMain::InitForm()
{
    int i;
    QFont fonts;
    QHBoxLayout * hlayout[3];
    hlayout[0]= new QHBoxLayout ;
    hlayout[1]= new QHBoxLayout ;
    hlayout[2]= new QHBoxLayout ;
    QVBoxLayout * vlayout = new QVBoxLayout;

    this->setLayout(vlayout);

    QPushButton *quit;
    fonts.setPixelSize(depy/30);
    quit = new QPushButton(this);
    quit->setText(tr("quit"));
    //quit->setIconSize(QSize(depx/10,depy/24));
    quit->setGeometry(0,depy*23/24,depx/10,depy/24);
    quit->setFont(fonts);
    quit->setStyleSheet("color: white;background-color: rgba(255, 255, 255, 20%);");
    quit->setFocusPolicy(Qt::NoFocus);
    quit->show();
    connect(quit,SIGNAL(clicked()), this, SLOT(quitclick()));

    vlayout->setContentsMargins(depx/5,depy/12,depx/30,depy/12);
    /*app*/
    for( i=0; i<15; i++){

        QToolButton *action[i];
        action[i] = new QToolButton(this);
        action[i]->setIcon(QIcon(iconpath[i]));
        action[i]->setText(appname[i]);
        action[i]->setObjectName(appname[i]);
        hlayout[i/5]->addWidget(action[i]);
        if(i%5==4)
            vlayout->addLayout(hlayout[i/5]);
    }



    QList<QToolButton *> btns = this->findChildren<QToolButton *>();
    foreach (QToolButton * btn, btns) {
        QPalette pal;
        pal.setColor(QPalette::ButtonText,QColor(255,255,255));
        QFont font;
        font.setPointSize(depy/48);
        btn->setPalette(pal);
        btn->setIconSize(QSize(depx*15/128,depy*20/128));
        btn->setStyleSheet("border-style:none;");
        btn->setFocusPolicy(Qt::NoFocus);
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }
}

void frmMain::quitclick()
{
    this->close();
}

void frmMain::buttonClick()
{
    QToolButton *btn = (QToolButton *)sender();
    QString objName = btn->objectName();
    int i;
    for( i=0; i<15; i++) {
        if (objName == appname[i]) {
            break;
        }
    }

//    printf("i=%d\n",i);

    this->hide();
    appExecTimer->start(200);      // 程序退出1s后，过滤掉阻塞掉的点击事件，防止再次进入
    QProcess appProcess;
    appProcess.setParent(this);
    appProcess.start(appPathStrList[i]);
    appProcess.waitForFinished(-1);
    appExecTimer->start(1000);      // 程序退出1s后，过滤掉阻塞掉的点击事件，防止再次进入

    QCursor cursor;
    cursor.setPos(depx,depy);
    this->show();
    i = 15;
}
