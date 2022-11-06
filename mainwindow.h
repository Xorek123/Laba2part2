#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QInputDialog>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QLabel>

#include "getinfowindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int rows_count = 0;
    const int colums_count = 4;


public slots:
    void getSlot(QStringList);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    GetInfoWindow *my_window;
};
#endif // MAINWINDOW_H
