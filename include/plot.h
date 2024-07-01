#ifndef PLOT_H
#define PLOT_H

#include <QwtPlotCurve>
#include <QwtPlot>

class Plot : public QwtPlot
{
public:
    Plot( QWidget *parent = NULL);
    void updateCurve(double t, double valTrap, double valSimp, double valMont);
private:
    QPolygonF m_pointTrap;
    QPolygonF m_pointSimp;
    QPolygonF m_pointMont;
    QwtPlotCurve *m_curveTrap;
    QwtPlotCurve *m_curveSimp;
    QwtPlotCurve *m_curveMont;
};

#endif // PLOT_H
