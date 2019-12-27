#include "game_window.h"
#include "ui_game_window.h"
#include<QFontDatabase>

Game_window::Game_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_window)
{
    ui->setupUi(this);


    QFont content( "메이플스토리", 11, QFont::Thin);
            ui->market->setFont(content);
            ui->inventory->setFont(content);
            ui->mini_game->setFont(content);
            ui->save_button->setFont(content);
            ui->quit_button->setFont(content);
            ui->pushButton_4->setFont(content);
            ui->pushButton_5->setFont(content);
            ui->pushButton_6->setFont(content);
            ui->pushButton_7->setFont(content);
            ui->pushButton_8->setFont(content);
            ui->STR->setFont(content);
            ui->STR_2->setFont(content);
            ui->DEX->setFont(content);
            ui->DEX_2->setFont(content);
            ui->INT->setFont(content);
            ui->INT_2->setFont(content);
            ui->LUX->setFont(content);
            ui->LUX_2->setFont(content);

            content.setPointSize(10);
            ui->label_2->setFont(content);
            ui->label_3->setFont(content);
            ui->label_4->setFont(content);
            ui->label_5->setFont(content);
            ui->label_6->setFont(content);
            ui->label_8->setFont(content);
            ui->label_9->setFont(content);
            ui->label_10->setFont(content);

            //메뉴들 텍스트 설정
            ui->market->setText("상점");
            ui->inventory->setText("인벤토리");
            ui->mini_game->setText("미니게임");
            ui->save_button->setText("저장하기");
            ui->quit_button->setText("나가기");
            ui->pushButton_8->setText("잠자기");
            ui->pushButton_4->setText("STR");
            ui->pushButton_6->setText("DEX");
            ui->pushButton_7->setText("INT");
            ui->pushButton_5->setText("LUX");

    ui->message->setText("");
    user = new player;

        setPetImageFile(); // 펫의 이미지 파일을 게임 윈도우에서 보여준다.

           connect(this, SIGNAL(showCurrentStat()),this, SLOT(setPetStat_show()));
           connect(this, SIGNAL(showCurrentDateFatigueMoney()),this, SLOT(DateFatigueMoney_show()));
           //스탯, 상태, 날짜, 피로도, 돈을 게임 윈도우에 보여준다.
           emit showCurrentStat();
           emit showCurrentDateFatigueMoney();


    Inven = new inventory();
    Market = new market();
    connect(Inven, SIGNAL(sendItemToPet(int)), this, SLOT(use_item(int)));
    connect(Market, SIGNAL(buyItem(Item, const char*)), this, SLOT(get_item(Item, const char*)));

    connect(Market, SIGNAL(sendMessage(const char*)), this, SLOT(getMessage(const char*)));
    connect(Inven, SIGNAL(sendMessage(const char*)), this, SLOT(getMessage(const char*)));

    /* mini game */
    MGB = new MiniGameBase;
    connect(MGB, SIGNAL(awardgained()), this, SLOT(award()));

}

Game_window::~Game_window()
{
    delete ui;
}

void Game_window::setPushButtonIcon(QPushButton *btn, QString &img)
{
    int w, h;
    w = btn->width();
    h = btn->height();

    QPixmap temp_img(img);
    QIcon temp_icon(temp_img);
    btn->setIcon(temp_icon);
    if(img == ":/myWindow/image/window_images/sleep.png")
        btn->setIconSize(QSize(w,h));
    else
        btn->setIconSize(QSize(w,h));
}

void Game_window::setPushButtonIcon2(QPushButton *btn, QString &img)
{
    QPixmap temp_img(img);
    QIcon temp_icon(temp_img);
    btn->setIcon(temp_icon);
    btn->setIconSize(QSize(200,100));
}

void Game_window::setPetImageFile()
{
    QPixmap* petImage = new QPixmap;
    QString imgName = user->getPet()->getImage_file_name();
    petImage->load(imgName);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(petImage->scaled(w,h,Qt::KeepAspectRatio));
}

void Game_window::windowSignal()
{
        emit showCurrentStat();
        emit showCurrentDateFatigueMoney();
}

void Game_window::printMsgBox(const char *text)
{
    QMessageBox msg;
    msg.setText(text);
    msg.exec();
    return;
}

bool Game_window::printYNBox(const char *text)
{
    QMessageBox msg;
    msg.setText(text);
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    if(msg.exec() == QMessageBox::Yes) return true;
    else return false;
}

player *Game_window::getUser() const
{
     return user;
}

void Game_window::setPetStat_show()
{
    ui->STR_2->setNum(user->getPet()->getStat().getSTR());
    ui->DEX_2->setNum(user->getPet()->getStat().getDEX());
    ui->INT_2->setNum(user->getPet()->getStat().getINT());
    ui->LUX_2->setNum(user->getPet()->getStat().getLUX());
}

void Game_window::DateFatigueMoney_show()
{
    if(user->getPet()->getSick() == 1){
        ui->label_6->setText("감기");
    }
    else if(user->getPet()->getSick() == 2){
        ui->label_6->setText("배탈");
    }
    else if(user->getPet()->getSick() == 3){
        ui->label_6->setText("몸살");
    }
    else if(user->getPet()->getSick() == 4){
        ui->label_6->setText("불면증");
    }
    else{
        ui->label_6->setText("건강함");
    }

    ui->label_8->setNum(user->getPlay_time());
    ui->label_9->setNum(user->getFatigue());
    ui->label_10->setNum(user->getMoney());
}

void Game_window::on_quit_button_clicked()
{
    this->hide();
    emit goToMainWindow();
}

void Game_window::on_market_clicked()
{
    Market->set_money(user->getMoney());
    Market->show();
}


void Game_window::get_item(Item item, const char* msg)
{
    // connected from signal 'buyitem', market widget
       // cout<<item.item_name<<endl;

        if(user->getMoney() - item.price < 0){
            // error message print
            printMsgBox("돈이 부족합니다.");
            return;
        }else{
            if(printYNBox("정말 구매하겠습니까?") == 1) ;
            else return;
        }

        bool check = 0;
        ItemVector* temp = user->getItemList();
        for(size_t i=0; i < temp->size(); i++){
            if(item.itemNum == (*temp)[i].first.itemNum){
                (*temp)[i].second++;
                check = true;
                break;
            }
        }

        if(check == false){
            ItemPair new_item(item, 1);
            user->getItemList()->push_back(new_item);
        }

        user->setMoney(user->getMoney()-item.price);
        Market->set_money(user->getMoney());
        Inven->set_money(user->getMoney());
        Inven->updateItemList(user->getItemList());
        getMessage(msg);

        //이준석 추가. 게임 화면에서 돈 바뀌는거
         emit showCurrentDateFatigueMoney();
}

void Game_window::on_inventory_clicked()
{
    Inven->set_money(user->getMoney()); // link money info
    Inven->updateItemList(user->getItemList());

    Inven->show();
}

void Game_window::use_item(int itemindex)
{
    // connect with SendItemToPet, Inventory.cpp
    cout<<"signal is received from Inventory" << endl;

    if(printYNBox("아이템을 사용하겠습니까?") == true) ;
    else return;

    ItemVector::iterator iter = user->getItemList()->begin() + itemindex;

    if((*iter).first.itemNum/10 == 0){ // 상태 아이템
        cout<<"status"<<endl;
        // pet 상태 회복
        if(user->getPet()->getSick() == (*iter).first.itemNum){
            user->getPet()->setSick(0);
        }
        else{
        // 잘못된 약을 처방함.

            printMsgBox("잘못된 약을 처방했습니다.");
            return;
        }

    }else{
        cout<<"stat"<<endl;
        // pet 스탯 변화
        user->getPet()->setPetALL((*iter).first.stat);
    }

    switch ((*iter).first.itemNum) {
    case 1:
        getMessage("'감기약'을 사용했다!");
        break;
    case 2:
        getMessage("'비타500'을 사용했다!");
        break;
    case 3:
        getMessage("'소화제'를 사용했다!");
        break;
    case 4:
        getMessage("'수면제'를 사용했다!");
        break;
    case 10:
        getMessage("'홍삼'을 사용했다!");
        break;
    case 11:
        getMessage("'자전거'를 사용했다!");
        break;
    case 12:
        getMessage("'노오력'을 했다!");
        break;
    case 13:
        getMessage("'네잎클로버'를 사용했다!");
        break;
    case 20:
        getMessage("'스테로이드'를 사용했다!");
        break;
    case 21:
        getMessage("'비행기'를 탔다!");
        break;
    case 22:
        getMessage("'전공서적'을 읽었다!");
        break;
    case 23:
        getMessage("'로또'에 당첨됐다!");
        break;
    case 30:
        getMessage("'명예P훈장'을 사용했다!");
        break;
    default:
        cout<<"error"<<endl;
        break;

    }

    // 아이템 수 감소
    if((*iter).second == 1){
        user->getItemList()->erase(iter);
    }else{
        (*iter).second--;
    }
    setPetStat_show();
    Inven->updateItemList(user->getItemList());
    emit showCurrentDateFatigueMoney();
}


void Game_window::on_mini_game_clicked()
{
    emit showCurrentStat(); // 펫의 현재 스탯을 보여주기 위한 시그널
    emit showCurrentDateFatigueMoney(); // 펫의 상태, 날짜, 피로도, 돈을 보여주기 위한 시그널
    MGB->show();
}



void Game_window::on_pushButton_4_clicked()
{
    int temp = user->STR_action();
    if(temp == 1){
        printMsgBox("피로도를 다 사용하였습니다.");
    }
    else if(temp == 2){
        printMsgBox("행동력을 다 사용하였습니다.");
    }
    emit showCurrentStat();
    emit showCurrentDateFatigueMoney();
}

void Game_window::on_pushButton_6_clicked()
{
    int temp = user->DEX_action();
    if(temp == 1){
        printMsgBox("피로도를 다 사용하였습니다.");
    }
    else if(temp == 2){
        printMsgBox("행동력을 다 사용하였습니다.");
    }
    emit showCurrentStat();
    emit showCurrentDateFatigueMoney();
}

void Game_window::on_pushButton_7_clicked()
{
    int temp = user->INT_action();
    if(temp == 1){
        printMsgBox("피로도를 다 사용하였습니다.");
    }
    else if(temp == 2){
        printMsgBox("행동력을 다 사용하였습니다.");
    }
    emit showCurrentStat();
    emit showCurrentDateFatigueMoney();
}

void Game_window::on_pushButton_5_clicked()
{
    int temp = user->LUX_action();
    if(temp == 1){
        printMsgBox("피로도를 다 사용하였습니다.");
    }
    else if(temp == 2){
        printMsgBox("행동력을 다 사용하였습니다.");
    }
    emit showCurrentStat();
    emit showCurrentDateFatigueMoney();
}

void Game_window::on_pushButton_8_clicked()
{
    user->player_sleep();
    setPetImageFile();
    emit showCurrentDateFatigueMoney();
}

void Game_window::on_save_button_clicked()
{
    user->saveMode();
}

void Game_window::getMessage(const char* msg)
{
    ui->message->setText(msg);

    timer = new QTimer;
    timer->start(2000);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(resetMessage()));

}

void Game_window::resetMessage(){
    ui->message->setText("");
    delete timer;
}

void Game_window::award()
{
    user->setMoney(user->getMoney()+100);
    emit showCurrentStat();
    emit showCurrentDateFatigueMoney();
}
