#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include "message.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::unique_ptr<Message> msg;

private:
    Ui::MainWindow *ui;

private slots:
    void tempReturnPressed();
    void tempWriteMsg(QString data);
signals:
    void tempSendData(QString data);
};


#endif
