#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    title_img = new QPixmap;
    title_img->load(":/myWindow/image/window_images/title.png");
    int w,h;
    w = title_img->width();
    h = title_img->height();
    ui->label->setPixmap(title_img->scaled(w/5,h/5,Qt::KeepAspectRatio));

    ui->centralWidget->setStyleSheet("QWidget {background: 'white'}");
    ui->statusBar->setStyleSheet("QStatusBar {background: 'white'}");
    ui->menuBar->setStyleSheet("QMenuBar {background: 'white'}");
    ui->mainToolBar->setStyleSheet("QToolBar {background: 'white'}");

    QFont content( "메이플스토리", 11, QFont::Thin);
    ui->continue_button->setFont(content);
    ui->fame_hall_button->setFont(content);
    ui->new_start_button->setFont(content);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_start_button_clicked() // new start
{
    game_window = new Game_window();
    /* delete the existing save file */
    game_window->show();
    this->hide();

    connect(game_window, SIGNAL(goToMainWindow()), this, SLOT(showMainWindow()));



}


void MainWindow::showMainWindow()
{
    this->show();
}


void MainWindow::on_continue_button_clicked()
{
    game_window = new Game_window();
    /* load the save file */
    game_window->getUser()->loadMode();
    game_window->setPetImageFile();
    game_window->windowSignal();


    game_window->show();
    this->hide();

    connect(game_window, SIGNAL(goToMainWindow()), this, SLOT(showMainWindow()));

}

void MainWindow::on_fame_hall_button_clicked()
{
    Fame_hall* hall = new Fame_hall();
    /* load the graudated animals from save file */


    hall->show();
    this->hide();
    connect(hall, SIGNAL(goToMainWindow()), this, SLOT(showMainWindow()));

}
