#ifndef GRAPHWORKER_H
#define GRAPHWORKER_H

#include <QWidget>
#include <QCloseEvent>
#include "qcustomplot.h"

namespace Ui {
class GraphWorker;
}

class GraphWorker : public QWidget
{

    Q_OBJECT

public:

    explicit GraphWorker(QWidget *parent = nullptr);
    ~GraphWorker();

    void makeGraph(QVector<double> x, QVector<double> y, int16_t maxValue, int16_t medianValue, int16_t countPackages);

signals:


private:

    Ui::GraphWorker *ui;

    QWidget* graphWindow;
    QLabel* countPackages;

    QCPItemText* maxValueText;
    QCPItemText* medianValueText;

    QCPItemEllipse *maxValueMarker;
    QCPItemStraightLine* medianLine;

    QPen* penMax;
    QPen* penMedian;

};

#endif // GRAPHWORKER_H
