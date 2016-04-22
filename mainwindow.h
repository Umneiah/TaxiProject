#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>
#include <QtCore>
#include <QtGui>
#include <QPainter>
#include <QRectF>
#include <QColor>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initial();
    void DrawPath(list<node *>path);
    void DrawCar();
    void trial();

private:
    Ui::MainWindow *ui;
    graph map;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
