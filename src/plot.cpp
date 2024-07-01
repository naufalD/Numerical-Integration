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
    m_curveMont->setSamples(m_pointMont);

    m_curveMona = new QwtPlotCurve();
    m_curveMona->setTitle("Monaco");
    m_curveMona->setPen(Qt::darkYellow, 1);
    m_curveMona-> setRenderHint( QwtPlotItem::RenderAntialiased, true );
    m_curveMona->setSamples(m_pointMona);

    m_curveTrap->attach(this);
    m_curveSimp->attach(this);
    m_curveMont->attach(this);
    m_curveMona->attach(this);
}

void Plot::updateCurve(double t, double valTrap, double valSimp, double valMont, double valMona){
    m_pointTrap << QPointF(t, valTrap);
    m_pointSimp << QPointF(t, valSimp);
    m_pointMont << QPointF(t, valMont);
    m_pointMona << QPointF(t, valMona);

    m_curveMont->setSamples(m_pointMont);
    m_curveMona->setSamples(m_pointMona);
    m_curveTrap->setSamples(m_pointTrap);
    m_curveSimp->setSamples(m_pointSimp);

    replot();
}

