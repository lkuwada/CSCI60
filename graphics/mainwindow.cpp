#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBasicTimer>
#include <cmath>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(500, 500);
    move(200, 0);
    setWindowTitle(tr("grapher"));

    //set clock
    seconds = 0;

    //set up timer to go off after 1 second
    duration = 1000;
    timer.start(duration, this); // micro-seconds

    // set up socket
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(ReadTime()));

    tcpSocket->connectToHost("64.90.182.55", 37); // NIST Internet Time Server
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == timer.timerId())
    {
        seconds = (seconds + 1) % 43200;
        timer.start(duration, this);
        update();
    }
    else
        QMainWindow::timerEvent(e);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(QColor("#880088"), 1)); // QPen(color, stroke width, type of line); QColor(#rrggbb)
    //painter.setViewport(0, 0, 500, 500); // restricts the amount of screen that is used...
    //painter.setWindow(-250, 250, 500, 500); //sets origin to the middle of the screen... rescales coordinate system...
    painter.setWindow(-50, -50, 100, 100);
    painter.drawEllipse(-50, -50, 100, 100);

    for (int i = 1; i <= 12; ++i)
    {
        painter.save();
        painter.rotate(30*i);
        painter.drawLine(0, -30, 0, -35);
        painter.drawText(-2, -40, QString::number(i));
        painter.restore();
    }

    //draw second hand
    painter.save();
    painter.setPen(QPen(Qt::red, 0.5));
    painter.rotate((seconds % 60) * 6);
    painter.drawLine(0, 0, 0, -30);
    painter.restore();

    //draw minutes hand
    painter.save();
    painter.setPen(QPen(Qt::green, 1.0));
    painter.rotate((seconds % 3600) / 10);
    painter.drawLine(0, 0, 0, -20);
    painter.restore();

    //draw hours hand
    painter.save();
    painter.setPen(QPen(Qt::blue, 3.0));
    painter.rotate(((17 * 3600) +seconds % 43200) / 120);
    painter.drawLine(0, 0, 0, -10);
    painter.restore();



    //painter.setWindow(-6.3, -1, 12.5, 2);

/*
    painter.drawLine(0, 0, 500, 500);

    painter.setBrush(QBrush("#ff0000", Qt::DiagCrossPattern));
    painter.drawRect(-250, -250, 250, 250);

    painter.drawPie(0, 0, 250, 250, 0, 90*16);
    painter.drawRoundRect(0, 0, 150, 150);
    painter.drawEllipse(0, 0, 250, 150);

    painter.drawLine(-250, 0, 250, 0);
    painter.drawLine(0, -250, 0, 250);
*/

//    for (double x = -6.3; x <= 6.3; x += 0.1)
//        painter.drawLine(QPointF(x, -sin(x)), QPointF(x+0.1, -sin(x+0.1)));
}
