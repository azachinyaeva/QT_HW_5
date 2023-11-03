#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject (parent)
{
    milli = 0;
    lap = 1;
    lap_time = 0;
    prev_sec = 0;
    timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, this, &Stopwatch::RcvTimer);

}

Stopwatch::~Stopwatch()
{

}

void Stopwatch::startTimer()
{
    start = true;
    timer->start(1);
}

void Stopwatch::stopTimer()
{
    timer->stop();
    start = false;
}

int Stopwatch::getLap()
{
    return lap;
}

void Stopwatch::setLap(int num)
{
    lap = num;
}

int Stopwatch::count_lap_time()
{
    lap_time = (milli/1000) - prev_sec;
    return lap_time;
}

uint Stopwatch::getMilli()
{
    return milli;
}


void Stopwatch::setPrevSec(uint seconds)
{
    prev_sec = seconds;
}

QTimer* Stopwatch::getTimer()
{
    return timer;
}

bool Stopwatch::isStart()
{
    return start;
}

void Stopwatch::clear()
{

    milli = 0;
    lap = 1;
    lap_time = 0;
    prev_sec = 0;
    emit sig_Clear();
}

void Stopwatch::RcvTimer()
{
    if (start)
    {
        milli++;
        emit sig_Timer(milli);
    }
}


