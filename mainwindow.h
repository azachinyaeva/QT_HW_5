#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pb_clear_clicked();
    void on_pb_timer_clicked();
    void RcvTimerSignal(uint milli);
    void RcvClear();

private slots:
    void on_pb_lap_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch* watch;
};
#endif // MAINWINDOW_H
