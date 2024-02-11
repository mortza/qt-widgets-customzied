//#include "widget.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}

#include <QGridLayout>
#include <QList>
#include <QTimer>
#include "switch.hpp"

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    QWidget container;
    QGridLayout mainLayout;
    QList<Switch*> switches;
    QTimer timer;
    container.setLayout(&mainLayout);
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            Switch* temp = new Switch;
            temp->setText(QString("%1 - %2").arg(i).arg(j));
            switches.append(temp);
            mainLayout.addWidget(temp, i, j);
        }
    }
    timer.setInterval(200);
    timer.setSingleShot(false);
    QObject::connect(&timer, &QTimer::timeout, [switches]() {
        for(int ii = 0; ii < switches.size(); ++ii) {
            //if (rand()%3 == 0)
            switches[ii]->setChecked(!switches[ii]->isChecked());
        }
    });

    container.show();
    timer.start();
    return application.exec();
}
