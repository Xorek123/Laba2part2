 #ifndef GETINFOWINDOW_H
#define GETINFOWINDOW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class GetInfoWindow;
}

class GetInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GetInfoWindow(QWidget *parent = nullptr);
    ~GetInfoWindow();

private slots:
    void on_pushButton_clicked();

signals:
    void message(QStringList);

private:
    Ui::GetInfoWindow *my_window;
};

#endif // GETINFOWINDOW_H
