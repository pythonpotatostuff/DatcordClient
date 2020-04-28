#include "mainwindow.h"
#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    msg = std::make_unique<Message>("127.0.0.1", 6969);
    connect(ui->inputMsg, &QLineEdit::returnPressed, this, &MainWindow::tempReturnPressed);
    connect(this, &MainWindow::tempSendData, msg.get(), &Message::sendData);
    connect(msg.get(), &Message::messageReady, this, &MainWindow::tempWriteMsg);
}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::tempReturnPressed()
{
    QString data = ui->inputMsg->text();
    ui->inputMsg->clear();
    emit tempSendData(data);
}


void MainWindow::tempWriteMsg(QString data)
{
    ui->boxMsg->setText(ui->boxMsg->text() + "\n" + data);
}
