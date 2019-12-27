#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QWidget>
#include <QTimer>
#include "market.h"
#include "inventory.h"
#include "minigamebase.h"
#include "include/model/player.h"
#include "include/model/item.h"

// 추가한 헤더파일 5월 25일 23시 6분 __이준석
#include <QPushButton>
#include "fame_hall.h"

#include <QMessageBox>

namespace Ui {
class Game_window;
}

class Game_window : public QWidget
{
    Q_OBJECT

public:
    explicit Game_window(QWidget *parent = nullptr);
    ~Game_window();

    void setPushButtonIcon(QPushButton *btn, QString &img); // 버튼 이미지 설정, 사용안함
    void setPushButtonIcon2(QPushButton *btn, QString &img); // 버튼 이미지 설정, 사용안함
    void setPetImageFile(); // 펫 이미지 파일을 설정한다.
    void windowSignal(); // 맨 처음 이어하기 모드로 시작할 때, 불러온 값을 바로 적용하기 위한 함수이다.

    void printMsgBox(const char *text); // 메세지 박스를 띄우는 함수
    bool printYNBox(const char *text); // Yes No 메세지 박스를 띄우는 함수


    player *getUser() const;
    void setUser(player *value);

private slots:

    void on_quit_button_clicked();


    void setPetStat_show(); //펫의 스탯을 게임윈도우에서 보여준다.
    void DateFatigueMoney_show(); //펫의 상태, 날짜, 피로도, 돈을 게임윈도우에서 보여준다.

    /* Market */
    void on_market_clicked();

    void get_item(Item item, const char* msg);

    /* Inventory */
    void on_inventory_clicked();

    void on_mini_game_clicked();

    void use_item(int itemNum);


    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_save_button_clicked();

void getMessage(const char* msg);
    void resetMessage();

    /* mini game */
    void award();
signals:
    void goToMainWindow();

    void showCurrentStat(); // 펫의 현재 스탯을 보여주기 위한 시그널
    void showCurrentDateFatigueMoney(); // 펫의 상태, 날짜, 피로도, 돈을 보여주기 위한 시그널
private:
    Ui::Game_window *ui;

    market* Market;
    inventory* Inven;
    MiniGameBase * MGB;

    player* user;
 QTimer* timer;

};

#endif // GAME_WINDOW_H
