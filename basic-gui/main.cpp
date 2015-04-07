#include <QApplication>
#include <QLabel>
#include <QCheckBox>
#include <QSlider>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label("hello");
//    label.show();
//    label.setAlignment(Qt::AlignCenter);

    QCheckBox checkbox("like qt?");
//    checkbox.show();

    QSlider slider(Qt::Horizontal);
//    slider.show();

    /*
    QHBoxLayout hboxlayout;
    hboxlayout.addWidget(&label);
    hboxlayout.addWidget(&checkbox);
    hboxlayout.addWidget(&slider);

    QWidget hwindow;
    hwindow.setLayout(&hboxlayout);
    hwindow.show();
    */

    QGridLayout gridlayout;
    gridlayout.addWidget(&label, 0, 0);
    gridlayout.addWidget(&checkbox, 1, 3);
    gridlayout.addWidget(&slider, 2, 2);

    QWidget gwindow;
    gwindow.setLayout(&gridlayout);
    gwindow.show();



    return app.exec();
}
