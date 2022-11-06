#include "getinfowindow.h"
#include "ui_getinfowindow.h"


GetInfoWindow::GetInfoWindow(QWidget *parent) :
    QDialog(parent),
    my_window(new Ui::GetInfoWindow)
{
    my_window->setupUi(this);
}

GetInfoWindow::~GetInfoWindow()
{
    delete my_window;
}

void GetInfoWindow::on_pushButton_clicked()
{
    QString time_departure = my_window->lineEdit->text();
    QString point_A = my_window->lineEdit_2->text();
    QString time_arrival = my_window->lineEdit_3->text();
    QString point_B = my_window->lineEdit_4->text();

    QStringList line_data = {time_departure, point_A, time_arrival, point_B};
    emit message(line_data);

    close();
}
