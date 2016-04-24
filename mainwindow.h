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
    void DrawPath(list<node *>path, int choose);
    void DrawCar();
    void DrawTextt(vector<node *> nodeList);
    void trial();
    void DrawLocation(node* n, QString s);


private slots:
    void on_ShowAll_button_clicked();

    void on_AddCars_button_clicked();

    void on_Start_button_clicked();

    void on_getCar_clicked();

    void on_Run_clicked();


private:
    Ui::MainWindow *ui;
    graph map;
    QPixmap pixmap;
    string Start;
    string Des;
    list<node*> meh;
    list<node*> heh;
};

#endif // MAINWINDOW_H
