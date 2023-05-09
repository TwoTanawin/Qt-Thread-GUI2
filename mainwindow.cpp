#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <thread>

bool thread1Running = false;
bool thread2Running = false;

// Function to be executed by thread 1
void thread1Func(MainWindow* window) {
    thread1Running = true;
    while (thread1Running){
        QMetaObject::invokeMethod(window, "HelloWorld", Qt::AutoConnection);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // sleep for 10 ms
    }
}

// Function to be executed by thread 2
void thread2Func(MainWindow* window) {
    thread2Running = true;
    while (thread2Running){
        QMetaObject::invokeMethod(window, "AI_Center", Qt::AutoConnection);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // sleep for 10 ms
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HelloWorld(){
    ui->textBrowser->append("Hello World");
}

void MainWindow::AI_Center(){
    ui->textBrowser->append("AI-Center");
}

void MainWindow::on_pushButton_start_thread_clicked()
{
    // Create thread 1
    std::thread thread1(thread1Func, this);

    // Create thread 2
    std::thread thread2(thread2Func, this);

    // Detach threads
    thread1.detach();
    thread2.detach();
}

void MainWindow::on_pushButton_Stop_thread_clicked()
{
    thread1Running = false;
    thread2Running = false;
}
