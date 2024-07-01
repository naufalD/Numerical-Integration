#ifndef PLOT_H
#define PLOT_H

#include <QwtPlotCurve>
#include <QwtPlot>

class Plot : public QwtPlot
{
public:
    Plot( QWidget *parent = NULL);
    void updateCurve(double t, double valTrap, double valSimp, double valMont, double valMona);
private:
    QPolygonF m_pointTrap;
    QPolygonF m_pointSimp;
    QPolygonF m_pointMont;
    QPolygonF m_pointMona;
    QwtPlotCurve *m_curveTrap;
    QwtPlotCurve *m_curveSimp;
    QwtPlotCurve *m_curveMont;
    QwtPlotCurve *m_curveMona;
};

#endif // PLOT_H
