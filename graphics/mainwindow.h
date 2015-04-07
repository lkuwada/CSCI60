#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QTcpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void resizeEvent(QResizeEvent *)
    {
        int side = qMin(width(), height());
        QRegion maskedRegion(width()/2 - side/2, height()/2 - side/2, side, side, QRegion::Ellipse);
        setMask(maskedRegion);
    }

public slots:
    void ReadTime()
    {
        QDataStream in(tcpSocket);
        in >> seconds;
        tcpSocket->close();
    }
    
private:
    Ui::MainWindow *ui;
    uint seconds, duration;
    QBasicTimer timer;

    QTcpSocket *tcpSocket;
};

#endif // MAINWINDOW_H
