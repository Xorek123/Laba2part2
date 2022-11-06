#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "getinfowindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_window = new GetInfoWindow();
    connect(my_window, &GetInfoWindow::message, this, &MainWindow::getSlot);

    ui->tableWidget->setColumnCount(colums_count);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Отправленяется" << "Из города" << "Прибывает" << "В город");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete my_window;
}

void MainWindow::getSlot(QStringList data_line)
{
    for (int i = 0; i < colums_count; ++i){
        ui->tableWidget->setItem(rows_count, i, new QTableWidgetItem(data_line.at(i)));}
    ++rows_count;
}



void MainWindow::on_pushButton_clicked(){
    if (rows_count == 0){
        ui->tableWidget->setRowCount(1);
        my_window->show();
    }
    else{
        ui->tableWidget->insertRow(rows_count);
        my_window->show();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    int row = QInputDialog::getInt(this, tr("Какое позицию вы желаете удалить?"),
                            tr("Введите номер:"),0,0,100,0,&ok);
    --row;
    ui->tableWidget->removeRow(row);
    --rows_count;

}


void MainWindow::on_pushButton_5_clicked()
{

    QString filename = QFileDialog::getOpenFileName(nullptr,"","‪C:/Users/Xorek/Documents/QTlaba/","*.json");
    QJsonArray information_line;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i){
          QJsonObject information_item;
          for (int j = 0; j < colums_count; ++j){
              QString key = ui->tableWidget->horizontalHeaderItem(j)->text();
              information_item.insert(key,ui->tableWidget->item(i,j)->text());
          }
          information_line.append(information_item);
     }

     QFile JSonFile(filename);
     JSonFile.open(QFile::WriteOnly);
     QJsonDocument data(information_line);
     JSonFile.write(data.toJson());
     JSonFile.close();
}


void MainWindow::on_pushButton_2_clicked()
{

    QString filename = QFileDialog::getOpenFileName(nullptr,"","‪C:/Users/Xorek/Documents/QTlaba/","*.json");
    if(filename.isEmpty() == true){
        QMessageBox::warning(this,"", "Нет места записи");
    }
    QFile JsonFile(filename);
    JsonFile.open(QFile::ReadOnly);
    QJsonArray information_line = QJsonDocument::fromJson(JsonFile.readAll()).array();
    ui->tableWidget->setRowCount(information_line.size());

    for (int i=0; i < information_line.size(); i++){
        QJsonValueRef line = information_line[i];
        QJsonObject info_line(line.toObject());
        for (int j = 0; j < colums_count; ++j){
            QString key = ui->tableWidget->horizontalHeaderItem(j)->text();
            QTableWidgetItem* item = new QTableWidgetItem(info_line.value(key).toString());
            ui->tableWidget->setItem(i,j,item);
        }
    }

}

