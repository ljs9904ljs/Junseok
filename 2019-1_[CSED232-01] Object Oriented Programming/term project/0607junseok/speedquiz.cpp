#include "speedquiz.h"
#include "ui_speedquiz.h"
#include <stdlib.h>
#include <time.h>
#include <QTimer>


SpeedQuiz::SpeedQuiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpeedQuiz)
{
    ui->setupUi(this);

    win_image.load("./image/mini_game/win_image.jpg");
    lose_image.load("./image/mini_game/lose_image.jpg");
    time_up_image.load("./image/mini_game/time_up_image.png");

    QFont title( "메이플스토리", 12, QFont::Bold);
    QFont content( "메이플스토리", 11, QFont::Thin);
    ui->progressButton->setFont(content);
    ui->GameOver->setFont(content);
    ui->Retry->setFont(content);
    ui->Answer_1->setFont(content);
    ui->Answer_2->setFont(content);
    ui->Answer_3->setFont(content);
    ui->Answer_4->setFont(content);
    ui->Answer_1_text->setText("");
    ui->Answer_2_text->setText("");
    ui->Answer_3_text->setText("");
    ui->Answer_4_text->setText("");

    ui->Answer_1->setVisible(false);
    ui->Answer_2->setVisible(false);
    ui->Answer_3->setVisible(false);
    ui->Answer_4->setVisible(false);

    ui->label->setFont(title);
    ui->label_2->setFont(content);
    ui->label->setText("스피드 퀴즈에 오신 것을 환영합니다!");
    ui->label_2->setText("\n\n\n\n\n\n\n\n문제를 맞추시는 분에게 총 500원의 보상을 드립니다!\n\n 준비 되셨으면 밑에 버튼을 눌러주세요!!");

    ui->progressBar->setVisible(false);
    ui->progressBar->setRange(0,150);

    timeline = new QTimeLine;
    timeline->setFrameRange(0, 150);
    timeline->setDuration(5000); // update every second
    timeline->setLoopCount(0);

    timer = new QTimer(this);
    timer->setSingleShot(1);

    ui->GameOver->setVisible(false);
    ui->Retry->setVisible(false);

    connect(timer, SIGNAL(timeout()), this, SLOT(TimeIsUp()));
    connect(timeline, SIGNAL(frameChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(timeline, SIGNAL(finished()), timeline, SLOT(deleteLater()));

}

SpeedQuiz::~SpeedQuiz()
{
    delete ui;
}



void SpeedQuiz::on_progressButton_clicked()
{
    setQuestions();
    timer->start(5000);
    timeline->start();
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(true);

    ui->progressButton->setVisible(false);
    ui->label->setText("");


    ui->Answer_1->setVisible(true);
    ui->Answer_2->setVisible(true);
    ui->Answer_3->setVisible(true);
    ui->Answer_4->setVisible(true);

    srand(time(NULL));
    auto problem_number = rand() % 25;

    actual_answer = Question[problem_number].getCorrect_Answer();

    ui->label_2->setText(QString::fromStdString(Question[problem_number].getQuestion_Text()));
    ui->Answer_1_text->setText("1. " +QString::fromStdString(Question[problem_number].getAnswer_1()));
    ui->Answer_2_text->setText("2. " +QString::fromStdString(Question[problem_number].getAnswer_2()));
    ui->Answer_3_text->setText("3. " +QString::fromStdString(Question[problem_number].getAnswer_3()));
    ui->Answer_4_text->setText("4. " +QString::fromStdString(Question[problem_number].getAnswer_4()));

}

void Question::getQuestion(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, int correct)
{
        Question_Text = q;
        answer_1 = a1;
        answer_2 = a2;
        answer_3 = a3;
        answer_4 = a4;

        Correct_Answer = correct;
}

std::string Question::getQuestion_Text() const
{
    return Question_Text;
}


std::string Question::getAnswer_1() const
{
    return answer_1;
}

std::string Question::getAnswer_2() const
{
    return answer_2;
}

std::string Question::getAnswer_3() const
{
    return answer_3;
}

std::string Question::getAnswer_4() const
{
    return answer_4;
}

int Question::getCorrect_Answer() const
{
    return Correct_Answer;
}


void SpeedQuiz::setQuestions()
{

    Question[0].getQuestion
            ("What command prints something to the screen?",
             "cin",
             "cout",
            "char",
            "print",
            4);

        Question[1].getQuestion("Which of the following categories does C++ belong to?",
            "Operating System",
            "High-level programming language",
            "low-level programming language",
            "Compiler",
            2);

        Question[2].getQuestion("Which command is correctly written?",
            "cout >>",
            "cin <<",
            "cout <>",
            "cin >>",
            4);

        Question[4].getQuestion("What is this called, <iostream>?",
            "directive",
            "pre-processor directive",
            "file",
            "command",
            2);

        Question[5].getQuestion("What punctuation ends most lines of code?",
            " . ",
            " ; ",
            " : ",
            " ' ",
            2);

        Question[6].getQuestion("Which of the following is a correct comment?",
            "*/ Comments */",
            "** Comment **",
            "/* Comment */",
            "{ Comment }",
            3);

        Question[7].getQuestion("Which of the following is the boolean operator for logical-and?",
            "&",
            "|",
            "&&",
            "|&",
            3);

        Question[8].getQuestion("Which of the following shows the correct syntax for an if statement?",
            "if expression",
            "if {expression",
            "if (expression)",
            "expression if",
            3);

        Question[9].getQuestion("How many times is a do while loop guaranteed to loop?",
            "1",
            "0",
            "Infinitely",
            "Variable",
            1);

        Question[10].getQuestion("A subscipt is a(n) __________ .",
            "element in an array",
            "alternate name for an array",
            "number that represents the highest value stored within an array",
            "number that indicates the position of the particular item in an array",
            4);

        Question[11].getQuestion("Which of the following correctly declares an array?",
            "int anarray[10];",
            "int anarray",
            "anarray{10};",
            "array anarray[10];",
            1);

        Question[12].getQuestion("What is the index number of the last element of an array with 29 elements?",
            "29",
            "28",
            "0",
            "Programmer-defined",
            1);

        Question[13].getQuestion("Which is not a loop structure?",
            "for",
            "do while",
            "while",
            "repeat until",
            4);

        Question[14].getQuestion("When does the code block following while(x < 100) execute?",
            "When x is less than one hundred",
            "When x is greater than one hundred",
            "When x is equal to one hundred",
            "While it wishes",
            1);

        Question[15].getQuestion("Most programmers use a for loop __________ .",
            "for every loop they write",
            "when a loop will not repeat",
            "when they do not know the exact number of times a loop will repeat",
            "when they know the exact number of times a loop will repeat",
            4);

        Question[16].getQuestion("Adding 1 to a  variable is also called __________ it.",
            "digesting",
            "incrementing",
            "decrementing",
            "resetting",
            2);

        Question[17].getQuestion("What is required to avoid falling through from one case to the next?",
            "end;",
            "break;",
            "Stop;",
            "A semicolon",
            2);

        Question[18].getQuestion("A __________ is a variable that you set to indicate whether some event has occured.",
            "subscript",
            "banner",
            "counter",
            "flag",
            4);

        Question[19].getQuestion("Identify the C++ compiler of Linux.",
            "cpp",
            "g++",
            "Borland",
            "vc++",
            2);

        Question[20].getQuestion("What is the size of 'int'? ",
            "2",
            "4",
            "8",
            "Compiler dependent",
            4);

        Question[21].getQuestion("Which data type can be used to hold a wide character in C++?",
            "unsigned char;",
            "int",
            "wchar",
            "none of the above.",
            3);

        Question[22].getQuestion("C++ does not support the following",
            "Multilevel inheritance",
            "Hierarchical inheritance",
            "Hybrid inheritance",
            "None of the above.",
            4);

        Question[23].getQuestion("Which is not a protection level provided by classes in C++?",
            "protected",
            "hidden",
            "private",
            "public",
            2);

        Question[24].getQuestion("What purpose do classes serve?",
            "data encapsulation",
            "providing a convenient way of modeling real-world objects",
            "simplifying code reuse",
            "all of the above",
            4);

}

void SpeedQuiz::TimeIsUp()
{
    ui->Answer_1_text->setVisible(false);
    ui->Answer_2_text->setVisible(false);
    ui->Answer_3_text->setVisible(false);
    ui->Answer_4_text->setVisible(false);

    ui->Answer_1->setVisible(false);
    ui->Answer_2->setVisible(false);
    ui->Answer_3->setVisible(false);
    ui->Answer_4->setVisible(false);

    ui->progressBar->setVisible(false);

    ui->label->setText("!시간 만료!");
    ui->label_2->setText("아쉽게도 이번에는 시간이 다 지났네요 ㅠㅠ");

    const int w = ui->image->width();
    const int h = ui->image->height();
    ui->image->setPixmap(time_up_image.scaled(w,h,Qt::KeepAspectRatio));

    ui->image->setVisible(true);
    ui->Retry->setVisible(true);
    ui->GameOver->setVisible(true);

}

void SpeedQuiz::on_Answer_1_clicked()
{
    player_answer = 1;
    timer->stop();
    ui->progressBar->setVisible(false);
    ui->GameOver->setVisible(true);
    ui->Retry->setVisible(true);

    ui->Answer_1->setVisible(false);
    ui->Answer_2->setVisible(false);
    ui->Answer_3->setVisible(false);
    ui->Answer_4->setVisible(false);

    ui->Answer_1_text->setText("");
    ui->Answer_2_text->setText("");
    ui->Answer_3_text->setText("");
    ui->Answer_4_text->setText("");

    ui->image->setVisible(true);

    if(player_answer == actual_answer)
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!정답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("축하합니다.\n 500원을 획득하셨습니다!");
        for(int i = 0; i<5; i++)
            emit moneyChange();

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(win_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    else
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!오답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("아쉽지만 다음에 다시 도전해주세요~");

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(lose_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    player_answer = 0;
    actual_answer = 0;

}

void SpeedQuiz::on_Answer_2_clicked()
{
    player_answer = 2;
    timer->stop();
    ui->progressBar->setVisible(false);
    ui->GameOver->setVisible(true);
    ui->Retry->setVisible(true);

    ui->Answer_1->setVisible(false);
    ui->Answer_2->setVisible(false);
    ui->Answer_3->setVisible(false);
    ui->Answer_4->setVisible(false);

    ui->Answer_1_text->setText("");
    ui->Answer_2_text->setText("");
    ui->Answer_3_text->setText("");
    ui->Answer_4_text->setText("");

    ui->image->setVisible(true);

    if(player_answer == actual_answer)
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!정답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("축하합니다.\n 500원을 획득하셨습니다!");
        for(int i = 0; i<5; i++)
            emit moneyChange();

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(win_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    else
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!오답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("아쉽지만 다음에 다시 도전해주세요~");

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(lose_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    player_answer = 0;
    actual_answer = 0;
}

void SpeedQuiz::on_Answer_3_clicked()
{
    player_answer = 3;
    timer->stop();
    ui->progressBar->setVisible(false);
    ui->GameOver->setVisible(true);
    ui->Retry->setVisible(true);

    ui->Answer_1->setVisible(false);
    ui->Answer_2->setVisible(false);
    ui->Answer_3->setVisible(false);
    ui->Answer_4->setVisible(false);

    ui->Answer_1_text->setText("");
    ui->Answer_2_text->setText("");
    ui->Answer_3_text->setText("");
    ui->Answer_4_text->setText("");

    ui->image->setVisible(true);

    if(player_answer == actual_answer)
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!정답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("축하합니다.\n 500원을 획득하셨습니다!");
        for(int i = 0; i<5; i++)
            emit moneyChange();

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(win_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    else
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!오답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("아쉽지만 다음에 다시 도전해주세요~");

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(lose_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    player_answer = 0;
    actual_answer = 0;
}

void SpeedQuiz::on_Answer_4_clicked()
{
    player_answer = 4;
    timer->stop();
    ui->progressBar->setVisible(false);
    ui->GameOver->setVisible(true);
    ui->Retry->setVisible(true);

    ui->Answer_1->setVisible(false);
    ui->Answer_2->setVisible(false);
    ui->Answer_3->setVisible(false);
    ui->Answer_4->setVisible(false);

    ui->Answer_1_text->setText("");
    ui->Answer_2_text->setText("");
    ui->Answer_3_text->setText("");
    ui->Answer_4_text->setText("");

    ui->image->setVisible(true);

    if(player_answer == actual_answer)
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!정답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("축하합니다.\n 500원을 획득하셨습니다!");
        for(int i = 0; i<5; i++)
            emit moneyChange();

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(win_image.scaled(w,h,Qt::KeepAspectRatio));

    }

    else
    {
        ui->label->setText("!!!!!!!!!!!!!!!!!!오답입니다!!!!!!!!!!!!!!!!!!!!!");
        ui->label_2->setText("아쉽지만 다음에 다시 도전해주세요~");

        const int w = ui->image->width();
        const int h = ui->image->height();
        ui->image->setPixmap(lose_image.scaled(w,h,Qt::KeepAspectRatio));
    }

    player_answer = 0;
    actual_answer = 0;
}

void SpeedQuiz::on_GameOver_clicked()
{
    this->close();
}

void SpeedQuiz::on_Retry_clicked()
{
    //피로도 올리는 거 구현해야!!!!!!!!!!!!!!!!!!

    ui->GameOver->setVisible(false);
    ui->Retry->setVisible(false);
    ui->image->setVisible(false);

    setQuestions();
    timer->start(10000);
    timeline->setCurrentTime(0);
    timeline->start();
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(true);

    ui->progressButton->setVisible(false);
    ui->label->setText("");


    ui->Answer_1->setVisible(true);
    ui->Answer_2->setVisible(true);
    ui->Answer_3->setVisible(true);
    ui->Answer_4->setVisible(true);

    srand(time(NULL));
    auto problem_number = rand() % 25;

    actual_answer = Question[problem_number].getCorrect_Answer();

    ui->Answer_1_text->setVisible(true);
    ui->Answer_2_text->setVisible(true);
    ui->Answer_3_text->setVisible(true);
    ui->Answer_4_text->setVisible(true);
    ui->label_2->setVisible(true);

    ui->label_2->setText(QString::fromStdString(Question[problem_number].getQuestion_Text()));
    ui->Answer_1_text->setText("1. " +QString::fromStdString(Question[problem_number].getAnswer_1()));
    ui->Answer_2_text->setText("2. " +QString::fromStdString(Question[problem_number].getAnswer_2()));
    ui->Answer_3_text->setText("3. " +QString::fromStdString(Question[problem_number].getAnswer_3()));
    ui->Answer_4_text->setText("4. " +QString::fromStdString(Question[problem_number].getAnswer_4()));
}
