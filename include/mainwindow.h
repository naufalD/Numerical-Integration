#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include "plot.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    virtual void timerEvent( QTimerEvent* ) QWT_OVERRIDE;

private:
    QLabel *m_labelTrap;
    QLabel *m_labelSimp;
    QLabel *m_labelMont;
    Plot *m_plot;
    int m_start;
    int m_end;
    int m_time;
    int m_idTimer;

};

#endif // MAINWINDOW_H
