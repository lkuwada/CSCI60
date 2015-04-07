#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QLabel>


const int SIZE = 50;
int fx(3), fy(3);

class myLabel: public QLabel
{
public:

    void mouseReleaseEvent(QMouseEvent *event)
    {
        int cx = x() / SIZE;
        int cy = y() / SIZE;

        if (std::abs(cx - fx) + std::abs(cy - fy) == 1)
        {
            move(fx*SIZE, fy*SIZE);
            fx = cx;
            fy = cy;
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QWidget window;
    int num[15];
    QPixmap pixmap [15];

    for (int i = 0; i < 15; ++i)
        num[i] = i;

    for (int i = 0; i < 15; ++i)
    {
        char name[20];
        sprintf(name, "mission_%d.jpg", i);
        pixmap[i] = QPixmap(name);
    }

    QLabel tile[15];

    for (int i = 0; i < 15; ++i)
    {
        tile[i].setParent(&window);
        tile[i].setText(QString::number(num[i]));
        tile[i].setFont(QFont("Times", 12, QFont::Bold));
        tile[i].setAlignment(Qt::AlignCenter);
        tile[i].setGeometry((i%4)*SIZE, (i/4)*SIZE, SIZE, SIZE);
        tile[i].setFrameStyle(QFrame::Box | QFrame::Sunken);

        tile[i].setPixmap(pixmap[num[i]]);
    }

    window.show();


    return a.exec();
}
