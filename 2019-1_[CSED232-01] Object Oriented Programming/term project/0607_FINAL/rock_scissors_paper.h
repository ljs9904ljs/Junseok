#ifndef ROCK_SCISSORS_PAPER_H
#define ROCK_SCISSORS_PAPER_H

#include <QWidget>
#include <QPixmap>
#include <QIcon>

namespace Ui {
class Rock_Scissors_Paper;
}

class Rock_Scissors_Paper : public QWidget
{
    Q_OBJECT

public:
    explicit Rock_Scissors_Paper(QWidget *parent = nullptr);
    ~Rock_Scissors_Paper();

signals:
    void moneyChange();

private slots:
    void on_ProgressButton_clicked();
    void change_opponent_image();

    void on_Rock_clicked();

    void on_Scissors_clicked();

    void on_Paper_clicked();

    void win_event();
    void lose_event();
    void tie_event();

    void on_Retry_Button_clicked();

    void on_Get_out_Button_clicked();

private:
    Ui::Rock_Scissors_Paper *ui;

    QPixmap pix;
    QPixmap rock;
    QPixmap scissors;
    QPixmap paper;
    QPixmap opponent;

    QPixmap win_image;
    QPixmap lose_image;
    QPixmap tie_image;


    QTimer* timer;
    QTimer* win;
    QTimer* tie;
    QTimer* lose;

    int i=0;

};

#endif // ROCK_SCISSORS_PAPER_H
