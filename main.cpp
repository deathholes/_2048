#include "_main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _main w;
    w.move(400,400);
    w.show();
    
    return a.exec();
}
