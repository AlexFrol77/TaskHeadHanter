#include "graphworker.h"
#include "ui_graphworker.h"

GraphWorker::GraphWorker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphWorker)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->xAxis->setRange(0, 4500);
    ui->customPlot->yAxis->setRange(-500, 4500);
    ui->customPlot->yAxis->ticker()->setTickCount(11);
    ui->customPlot->xAxis->ticker()->setTickCount(10);

    maxValueText = new QCPItemText(ui->customPlot);
    medianValueText = new QCPItemText(ui->customPlot);

    maxValueMarker = new QCPItemEllipse(ui->customPlot);
    medianLine = new QCPItemStraightLine(ui->customPlot);

    penMax = new QPen;
    penMax->setWidth(3);
    penMax->setColor(Qt::red);
    penMax->setStyle(Qt::SolidLine);
    maxValueText->setFont(QFont(font().family(), 11));
    maxValueMarker->setPen(*penMax);

    penMedian = new QPen;
    penMedian->setWidth(3);
    penMedian->setStyle(Qt::DashLine);
    penMedian->setColor(Qt::black);
    medianValueText->setFont(QFont(font().family(), 11));
    medianLine->setPen(*penMedian);

    ui->customPlot->setInteraction(QCP::iRangeZoom, true);
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);
}

GraphWorker::~GraphWorker()
{
    delete ui;
    delete maxValueText;
    delete medianValueText;
    delete medianLine;
    delete maxValueMarker;
}

void GraphWorker::makeGraph(QVector<double> x, QVector<double> y, int16_t maxValue, int16_t medianValue, int16_t countPackages)
{
    ui->customPlot->graph(0)->setData(x, y);

    int maxIndex = y.indexOf(maxValue);
    double maxX = x[maxIndex];
    double maxY = y[maxIndex];

    maxValueText->position->setCoords(maxX + 300, maxValue);

    maxValueText->setText(QString("Y: %1").arg(maxY) + "\n" + QString("X: %2").arg(maxX));
    maxValueMarker->topLeft->setCoords(maxX - 80, maxY - 90);
    maxValueMarker->bottomRight->setCoords(maxX + 80, maxY + 90);

    medianValueText->position->setCoords(1500, medianValue + 250);
    medianValueText->setText(QString("Median: %1").arg(medianValue));

    medianLine->point1->setCoords(0, medianValue);
    medianLine->point2->setCoords(4096, medianValue);

    ui->countPackages->setText(QString(" Receiver packages: %1").arg(countPackages) + QString("   Max : %2").arg(maxValue)
                             + QString("   Median : %3").arg(medianValue));

    ui->customPlot->replot();

    this->show();
}
