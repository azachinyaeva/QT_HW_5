#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject (parent)
{
    milli = 0;
    sec = 0;
    min = 0;
    lap = 1;
    lap_time = 0;
    prev_sec = 0;
    timer = new QTimer(this);

}

Stopwatch::~Stopwatch()
{

}

void Stopwatch::startTimer()
{
    start = true;
    timer->start(1);
    clock();
}

void Stopwatch::clock()
{

    milli++;
    if (milli >= 1000) {
        milli = 0;
        sec++;
    }
    if (sec >= 60) {
        sec = 0;
        min++;
    }
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

void Stopwatch::startLap()
{
    emit sig_Lap();
}

int Stopwatch::count_lap_time()
{
    lap_time = sec - prev_sec;
    return lap_time;
}

int Stopwatch::getMilli()
{
    return milli;
}

int Stopwatch::getSec()
{
    return sec;
}

int Stopwatch::getMin()
{
    return min;
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
    sec = 0;
    min = 0;
    lap = 1;
    lap_time = 0;
    prev_sec = 0;
    emit sig_Clear();
}


