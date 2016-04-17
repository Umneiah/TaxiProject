#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>
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

private:
    Ui::MainWindow *ui;
    graph map;
};

#endif // MAINWINDOW_H
