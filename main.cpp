#include "wizard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Wizard wizard;

    wizard.setWindowTitle("iFluid Wizard");
    wizard.setFixedSize(500,500);
    wizard.show();

    return a.exec();
}
