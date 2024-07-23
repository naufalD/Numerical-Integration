#include "include/mainwindow.h"
#include "src/integration.cpp"

#include <QLabel>
#include <QLayout>
#include <cmath>

double theFunction(double x){
    return pow(x,2)+x+1;
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_start = 0;
    m_end = 1;

    m_labelTrap = new QLabel(this);
    m_labelTrap->setText("Trapezoid: "+QString::number(trapezoidIntegration(1, 0, 1, &theFunction)));

    m_labelSimp = new QLabel(this);
    m_labelSimp->setText("Simpsons: "+QString::number(simpsonsIntegration(1, 0, 1, &theFunction)));

    m_labelMont = new QLabel(this);
    m_labelMont->setText("Monte Carlo: "+QString::number(monteCarloIntegration(1, 0, 1, &theFunction)));

    unsigned int initial1[18] {0};
    Rng = new sobolDimension(1, initial1, true);
    m_labelSobol = new QLabel(this);
    m_labelSobol->setText("Sobol: "+QString::number(sobolIntegration(1, 0, 1, *Rng, &theFunction)));

    m_plot = new Plot();
    m_time = 1;
    QVBoxLayout* nums = new QVBoxLayout();
    nums->addWidget(m_labelTrap);
    nums->addWidget(m_labelSimp);
    nums->addWidget(m_labelMont);
    nums->addWidget(m_labelSobol);

    QHBoxLayout* layout = new QHBoxLayout( this );
    layout->addWidget(m_plot,80);
    layout->addLayout(nums,20);

    (void) startTimer(10);
}

void MainWindow::timerEvent( QTimerEvent* ){
    double resultTrap = trapezoidIntegration(m_time, m_start, m_end, &theFunction);
    double resultSimp = simpsonsIntegration(m_time, m_start, m_end, &theFunction);
    double resultMont = monteCarloIntegration(m_time, m_start, m_end, &theFunction);
    double resultSobol = sobolIntegration(m_time, m_start, m_end,*Rng, &theFunction);

    m_plot->updateCurve(m_time, resultTrap, resultSimp, resultMont, resultSobol);
    m_labelTrap->setText("Trapezoid: "+QString::number(resultTrap));
    m_labelSimp->setText("Simpsons: "+QString::number(resultSimp));
    m_labelMont->setText("Monte Carlo: "+QString::number(resultMont));
    m_labelSobol->setText("Sobol: "+QString::number(resultSobol));

    if (m_time>5000){(void) killTimer(m_idTimer);}

    ++m_time;
}
