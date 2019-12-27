#ifndef ROULETTE_H
#define ROULETTE_H

#include <QWidget>
#include <QDialog>
#include <QtCore>
#include <QtGui>


namespace Ui {
class roulette;
}

class roulette : public QWidget
{
    Q_OBJECT

public:
    explicit roulette(QWidget *parent = nullptr);
    ~roulette();

signals:
    void moneyChange();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_Stop_clicked();
    void show_result();

    void on_Retry_Button_clicked();
    void on_Get_Out_Button_clicked();

    void on_ProgressButton_clicked();

private:
    Ui::roulette *ui;


    QTimer* timer;
    QTimer* game_end;

    int stop_point;
    int result;

    QPixmap win_image;
    QPixmap lose_image;
    QPixmap tie_image;
    QPixmap start;

};



#endif // ROULETTE_H
