
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_thread_clicked();

    void on_pushButton_Stop_thread_clicked();

    void HelloWorld();

    void AI_Center();

private:
    Ui::MainWindow *ui;

//    void HelloWorld();

//    void AI_Center();
};

#endif // MAINWINDOW_H
