#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
#include "graphworker.h"

#define BIND_PORT 10002
static const int16_t samplesSize = 4096;

class UDPWorker : public QObject
{
    Q_OBJECT
public:
    explicit UDPWorker(QObject *parent = nullptr);

    void initSocket();

signals:

private:
    QUdpSocket* socket;
    QByteArray dataArray;

    QVector<double> x, y;
    int16_t samples[samplesSize];

    GraphWorker* graphWorker;

    void pendingDatagram();
    void readDatagram(QNetworkDatagram datagram);

    int16_t findMax();
    int16_t findMedian();
    int16_t countPackages = 0;
};

#endif // UDPWORKER_H
