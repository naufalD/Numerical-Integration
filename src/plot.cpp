#include "include/plot.h"

#include <QwtPlotGrid>
#include <QwtLegend>

Plot::Plot(QWidget *parent) : QwtPlot(parent)
{
    setTitle( "Integral test" );
    setCanvasBackground( Qt::white );
    setMinimumSize(300,300);
    insertLegend(new QwtLegend);
    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->attach( this );



    m_curveTrap = new QwtPlotCurve();
    m_curveTrap->setTitle("Trapezpoid");
    m_curveTrap->setPen(Qt::red, 2);
    m_curveTrap-> setRenderHint( QwtPlotItem::RenderAntialiased, true );
    m_curveTrap->setSamples(m_pointTrap);

    m_curveSimp = new QwtPlotCurve();
    m_curveSimp->setTitle("Simpsons");
    m_curveSimp->setPen(Qt::blue, 1);
    m_curveSimp-> setRenderHint( QwtPlotItem::RenderAntialiased, true );
    m_curveSimp->setSamples(m_pointSimp);

    m_curveMont = new QwtPlotCurve();
    m_curveMont->setTitle("Monte Carlo");
    m_curveMont->setPen(Qt::green, 1);
    m_curveMont-> setRenderHint( QwtPlotItem::RenderAntialiased, true );
    m_curveMont->setSamples(m_pointSimp);

    m_curveTrap->attach(this);
    m_curveSimp->attach(this);
    m_curveMont->attach(this);
}

void Plot::updateCurve(double t, double valTrap, double valSimp, double valMont){
    m_pointTrap << QPointF(t, valTrap);
    m_pointSimp << QPointF(t, valSimp);
    m_pointMont << QPointF(t, valMont);

    m_curveMont->setSamples(m_pointMont);
    m_curveTrap->setSamples(m_pointTrap);
    m_curveSimp->setSamples(m_pointSimp);

    replot();
}

