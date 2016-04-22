#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>
#include <QtCore>
#include <QtGui>
#include <QPainter>
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
    void DrawCar(node * car);
    void trial();

private:
    Ui::MainWindow *ui;
    graph map;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
