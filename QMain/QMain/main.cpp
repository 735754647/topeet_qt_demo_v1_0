#include "frmmain.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


        //    qApp->setFont(QFont("wenquanyi",12));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")) ;
    a.setFont(QFont("wenquanyi", 12));

    frmMain w;


    w.show();

    return a.exec();
}
