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

    QObject::connect(watch, &Stopwatch::sig_Timer, this, &MainWindow::RcvTimerSignal);
    QObject::connect(watch, &Stopwatch::sig_Clear, this, &MainWindow::RcvClear);

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

void MainWindow::RcvTimerSignal(uint milli)
{
    watch->startTimer();
    ui->l_time->setText(QString::number(milli/60000) + " : "
                        + QString::number(milli/1000) + " : "
                        + QString::number(watch->getMilli()).remove(0, 1));
}


void MainWindow::RcvClear()
{
    ui->l_time->setText("0:0:00");
}


void MainWindow::on_pb_lap_clicked()
{
    ui->tb_show->append("Круг: " + QString::number(watch->getLap()) + " Время: " + QString::number(watch->count_lap_time()) + "сек. ");
    watch->setPrevSec(watch->getMilli()/1000);
    watch->setLap(watch->getLap() + 1);
}

