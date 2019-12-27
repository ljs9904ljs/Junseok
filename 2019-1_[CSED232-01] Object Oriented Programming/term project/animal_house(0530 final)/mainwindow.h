#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <iostream>

#include "game_window.h"
#include "fame_hall.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_new_start_button_clicked();

    void on_continue_button_clicked();

    void on_fame_hall_button_clicked();

    void showMainWindow();




private:
    Ui::MainWindow *ui;

    Game_window* game_window;


    QPixmap* title_img;
};

#endif // MAINWINDOW_H
