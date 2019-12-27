#ifndef SPEEDQUIZ_H
#define SPEEDQUIZ_H

#include <QWidget>
#include <vector>
#include <QTimeLine>



class Question{
public:
    void getQuestion(std::string, std::string, std::string, std::string, std::string, int);
    void askQuestion();

    std::string getQuestion_Text() const;

    std::string getAnswer_1() const;

    std::string getAnswer_2() const;

    std::string getAnswer_3() const;

    std::string getAnswer_4() const;

    int getCorrect_Answer() const;

private:
    std::string Question_Text;
    std::string answer_1;
    std::string answer_2;
    std::string answer_3;
    std::string answer_4;

    int Correct_Answer;
};

namespace Ui {
class SpeedQuiz;
}

class SpeedQuiz : public QWidget
{
    Q_OBJECT

public:
    explicit SpeedQuiz(QWidget *parent = nullptr);
    ~SpeedQuiz();

    void setQuestions();



private slots:
    void on_progressButton_clicked();
    void TimeIsUp();

    void on_Answer_1_clicked();

    void on_Answer_2_clicked();

    void on_Answer_3_clicked();

    void on_Answer_4_clicked();

    void on_GameOver_clicked();

    void on_Retry_clicked();

private:
    Ui::SpeedQuiz *ui;
    Question Question[25];
    QTimer* timer;
    QTimeLine* timeline;

    QPixmap win_image;
    QPixmap lose_image;
    QPixmap time_up_image;

    int player_answer = 0;
    int actual_answer = 0;

signals:
    void fatigueup();
    void moneyup();
};



#endif // SPEEDQUIZ_H
