#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    watch = new Stopwatch(this);

    ui->pb_timer->setText("СТАРТ");
    ui->l_time->setText("0:0:00");
    ui->pb_lap->setEnabled(true);

    QObject::connect(watch->getTimer(), &QTimer::timeout, this, &MainWindow::RcvStartSignal);
    QObject::connect(watch, &Stopwatch::sig_Clear, this, &MainWindow::RcvClear);
    QObject::connect(watch, &Stopwatch::sig_Lap, this, &MainWindow::RcvStartLap);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_clear_clicked()
{
    watch->clear();
}


void MainWindow::on_pb_timer_clicked()
{
    if (!(watch->isStart())) {
        watch->startTimer();
        ui->pb_lap->setEnabled(true);
        ui->pb_timer->setText("СТОП");
    }
    else {
        watch->stopTimer();
        ui->pb_lap->setEnabled(false);
        ui->pb_timer->setText("СТАРТ");
    }
}

void MainWindow::RcvStartSignal()
{
    watch->startTimer();
    ui->l_time->setText(QString::number(watch->getMin()) + " : "
                        + QString::number(watch->getSec()) + " : "
                        + QString::number(watch->getMilli()));
}


void MainWindow::RcvClear()
{
    ui->l_time->setText("0:0:00");
}

void MainWindow::RcvStartLap()
{
    ui->tb_show->append("Круг: " + QString::number(watch->lap) + " Время: " + QString::number(watch->count_lap_time()) + "сек. ");
    watch->prev_sec = watch->getSec();
    watch->setLap(watch->lap + 1);

}

void MainWindow::on_pb_lap_clicked()
{
    watch->startLap();
}

