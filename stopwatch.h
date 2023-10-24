#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject* parent = nullptr);

    ~Stopwatch();

    void startTimer();
    void clock();
    void stopTimer();
    int getLap();
    void setLap(int num);
    void startLap();
    int count_lap_time();
    int getMilli();
    int getSec();
    int getMin();
    QTimer* getTimer();
    bool isStart();
    void clear();


public:
    int milli;
    int sec;
    int min;
    int lap;
    int lap_time;
    int prev_sec;
    bool start = false;
    QTimer* timer;

signals:
    void sig_Clear();
    void sig_Lap();
};

#endif // STOPWATCH_H
