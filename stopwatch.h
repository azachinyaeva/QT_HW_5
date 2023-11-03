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
    void stopTimer();
    int getLap();
    void setLap(int num);
    int count_lap_time();
    uint getMilli();
    void setPrevSec(uint seconds);
    QTimer* getTimer();
    bool isStart();
    void clear();


private:
    uint milli;
    int lap;
    uint lap_time;
    int prev_sec;
    bool start = false;
    QTimer* timer;

private slots:
    void RcvTimer();

signals:
    void sig_Clear();
    void sig_Timer(uint);
};

#endif // STOPWATCH_H
