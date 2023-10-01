#include "udpworker.h"

UDPWorker::UDPWorker(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    graphWorker = new GraphWorker;
}

void UDPWorker::initSocket()
{
    socket->bind(QHostAddress::LocalHost, BIND_PORT);
    connect(socket, &QUdpSocket::readyRead, this, &UDPWorker::pendingDatagram);
}

void UDPWorker::pendingDatagram()
{
    while (socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket->receiveDatagram();
        readDatagram(datagram);
    }
}

void UDPWorker::readDatagram(QNetworkDatagram datagram)
{
    dataArray = datagram.data();
    QDataStream inData(&dataArray, QIODevice::ReadOnly);
    countPackages++;
    for (int16_t i = 0; i < samplesSize; ++i) {
        inData >> samples[i];
    }

    x.clear();
    y.clear();

    for (int16_t i = 0; i < samplesSize; ++i) {
        x.append(i);
        y.append(samples[i]);
    }

    graphWorker->makeGraph(x, y, findMax(), findMedian(), countPackages);
}

int16_t UDPWorker::findMax()
{
    int16_t maxValue = *std::max_element(samples, samples + 4096);
    return maxValue;
}

int16_t UDPWorker::findMedian()
{
    int medianValue = -1;
    int samplesCount = sizeof(samples) / sizeof(samples[0]);
    std::sort(samples, samples + samplesCount);
    if (samplesCount % 2 == 0) {
        medianValue = (samples[samplesCount / 2 - 1] + samples[samplesCount / 2]) / 2;
    } else {
        medianValue = samples[samplesCount / 2];
    }
    return medianValue;
}
