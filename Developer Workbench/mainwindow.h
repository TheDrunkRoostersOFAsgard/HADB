#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
using  namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Bsubmit_clicked();
    void on_BHelp_clicked();
    void on_BVisual_clicked();
    int sumCol(string req);
    int sumRows(string req);
    //int makeTable(int row, int col, string req);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
