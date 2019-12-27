#include "include/model/player.h"

//5월 25일 23시 47분에 추가_ 이준석
#include <iostream>
#include <fstream>
#include <sstream>

player::player()
{
    pet = new Pet;
    fatigue = pet->getMAX_fatigue();
    play_time = 1;
    pet_level = 1; // 시작은 알이다.

    //2019_05_25_22시_이준석 수정
    money = 1000;

    /* 행동 5번 밖에 못하는 것을 지운다. 쓸모가 없다.
    for(int i=0;i<4;i++){
        action_limit[i] = 5;
    }
    */
}

player::~player()
{
    delete pet;
}

int player::STR_action()
{
    if(isFatigue())
        return 1;
    //if(action_limit[0] == 0)
    //    return 2;

    pet->STR_action();
    fatigue--;
    //action_limit[0]--;
}

int player::DEX_action()
{
    if(isFatigue())
        return 1;
    //if(action_limit[1] == 0)
    //    return 2;

    pet->DEX_action();
    fatigue--;
    //action_limit[1]--;
}

int player::INT_action()
{
    if(isFatigue())
        return 1;
    //if(action_limit[2] == 0)
    //    return 2;

    pet->INT_action();
    fatigue--;
    //action_limit[2]--;
}

int player::LUX_action()
{
    if(isFatigue())
        return 1;
    //if(action_limit[3] == 0)
    //    return 2;

    pet->LUX_action();
    fatigue--;
    //action_limit[3]--;
}

void player::setPetImageFile()
{
    std::string temp = "./image/animal/";
    temp += std::to_string(pet->getPet_kind());
    temp += ".png";
    QString img = temp.c_str();
    pet->setImage_file_name(img);
}

void player::saveMode()
{
    ofstream saveFile;

    saveFile.open("save_data.txt");
    if(!saveFile){
        std::cerr << "ERROR: Cannot Open File!" << std::endl;
        exit(1);
    }

    //돈, 피로도
    saveFile << money << " " << fatigue << " ";

    //행동력
    //for(int i=0;i<4;i++){
    //    saveFile << action_limit[i] << " ";
    //}

    //플레이타임, 펫 등급
    saveFile << play_time << " " << pet_level << " ";
    //펫 상태, 펫 종류, (펫 등급 별)최대 피로도
    saveFile << pet->getSick() << " " << pet->getPet_kind() << " "
             << pet->getMAX_fatigue() << " ";
    //힘, 덱, 인트, 럭스
    saveFile << pet->getStat().getSTR() << " " << pet->getStat().getDEX() << " "
             << pet->getStat().getINT() << " " << pet->getStat().getLUX() << " ";
    //펫 이미지 파일 이름
    saveFile << pet->getImage_file_name().toStdString() << std::endl;

    //아이템 보유 목록
    //아이템 번호, 아이템 이름, 아이템 가격, 치료, 힘, 덱, 인트, 럭스, 아이템 파일 이름, 아이템 보유 개수
    ItemVector::iterator iter;
    for(iter = ItemList.begin();iter != ItemList.end();++iter){
        saveFile << iter->first.itemNum << " " << iter->first.item_name << " "
                 << iter->first.price << " "
                 << iter->first.stat.getSTR() << " " << iter->first.stat.getDEX() << " "
                 << iter->first.stat.getINT() << " " << iter->first.stat.getLUX() << " "
                 //<< iter->first.image_file_name.toStdString() << " "
                 << iter->second << std::endl;
    }

}

void player::loadMode()
{
    ifstream loadFile;
    Ability_point petAp;
    int ap[4];
    string petImg;
    QString petImgFile;

    int number, value, s1, s2, s3, s4, ea;
    string itemName;

    loadFile.open("save_data.txt");

    int petSick, petKind, petMax_fati;

   loadFile >> money >> fatigue >> play_time
          >> pet_level >> petSick >> petKind >> petMax_fati
          >> ap[0] >> ap[1] >> ap[2] >> ap[3] >> petImg;

        pet->setSick(petSick);
        pet->setPet_kind(petKind);
        pet->setMAX_fatigue(petMax_fati);
        pet->setStat(Ability_point(ap[0],ap[1],ap[2],ap[3]));
        pet->setImage_file_name(petImg.c_str());



    std::cout<<"HAPPYfasdfsf"<<std::endl;
    std::cout<<money << " "
            << fatigue << " "
            << play_time << " "
            << pet_level << " "
            << petSick << " "
            << petKind << " "
            << petMax_fati << " "
            << ap[0] << " " << ap[1] << " " << ap[2] << " " << ap[3] << " "
            << petImg <<std::endl;
    std::cout<<"HAPPYfasdfsf"<<std::endl;
        // money, fatigue, play_time, pet_level, pet->setSick, pet->setPet_kind, pet->setMAX_fatigue
        // pet->setStat, pet->setImage_file_name

    if(!ItemList.empty()){
        ItemList.clear();
    }
        while(loadFile >> number >> itemName >> value >> s1 >> s2 >> s3 >> s4 >> ea)
        {
            Item temp(number, itemName, {s1, s2, s3, s4}, value);
            ItemPair theItem(temp,ea);
            ItemList.push_back(theItem);
        }
}

bool player::isFatigue()
{
    return (fatigue == 0);
}

void player::player_sleep()
{


    //진화 가능 여부를 확인하고, 진화할 수 있다면 진화한다. 졸업할 수 있다면 졸업한다.
    int condition = canEvolve();
    if(condition == -3){
        return;
    }
    if(condition == -2){
        ofstream endingFile;
        endingFile.open("./data/fame_hall_info.txt");
        if(!endingFile){
            std::cerr << "ERROR: Cannot Open File!" << std::endl;
            exit(1);
        }
        endingFile << pet->getPet_kind() << " " << pet->getStat().getSTR() << " "
                   << pet->getStat().getDEX() << " " << pet->getStat().getINT() << " "
                   << pet->getStat().getLUX() << " " << play_time << std::endl;
        QMessageBox temp;
        temp.setText("***펫이 졸업하였습니다!***");

        temp.exec();

        QWidget* t_w = new QWidget;
        t_w->resize(1000, 1000);



        QLabel* zolup_img = new QLabel(t_w);
        QPixmap z_img("./image/animal/zolup.jpg");
        zolup_img->setPixmap(z_img.scaled(1000, 1000,Qt::IgnoreAspectRatio));

        QLabel* text = new QLabel(zolup_img);
        text->setFont(QFont("메이플스토리",15,QFont::Thin));
        text->move(100,250);
        text->setText("우리들의 펫이 머나먼 곳으로 여행을 떠났어요!!!");


        t_w->show();



        return;
    }
    if(condition > 0) {

        switch(condition){
        case 20:
            pet_evolution_to_level2();
            pet->setPet_kind(20);
            break;
        case 21:
            pet_evolution_to_level2();
            pet->setPet_kind(21);
            break;
        case 22:
            pet_evolution_to_level2();
            pet->setPet_kind(22);
            break;
        case 30:
            pet_evolution_to_level3();
            pet->setPet_kind(30);
            break;
        case 31:
            pet_evolution_to_level3();
            pet->setPet_kind(31);
            break;
        case 32:
            pet_evolution_to_level3();
            pet->setPet_kind(32);
            break;
        case 33:
            pet_evolution_to_level3();
            pet->setPet_kind(33);
            break;
        case 34:
            pet_evolution_to_level3();
            pet->setPet_kind(34);
            break;
        case 35:
            pet_evolution_to_level3();
            pet->setPet_kind(35);
            break;
        case 40:
            pet_evolution_to_level4();
            pet->setPet_kind(40);
            break;
        case 41:
            pet_evolution_to_level4();
            pet->setPet_kind(41);
            break;
        case 42:
            pet_evolution_to_level4();
            pet->setPet_kind(42);
            break;
        case 43:
            pet_evolution_to_level4();
            pet->setPet_kind(43);
            break;

        default:
            break;
        }

        setPetImageFile();

        QMessageBox temp;
        temp.setText("***펫이 진화하였습니다!***");
        temp.exec();


    }


    fatigue = pet->getMAX_fatigue();
    play_time++;

}

int player::canEvolve() // -1은 진화를 못한다는 뜻
{

    if( (pet->getPet_kind() / 10) == 1){
        if(pet->getStat().getSTR() > 100){
            return 20;
        }
        else if(pet->getStat().getDEX() > 100){
            return 21;
        }
        else if(pet->getStat().getSTR()>50 && pet->getStat().getINT() > 50){
            return 22;
        }
        else{
            return -1;
        }
    }
    else if( (pet->getPet_kind() / 10) == 2){
        if(pet->getStat().getLUX() > 400){
            return 30;
        }
        else if(pet->getStat().getSTR() > 400){
            return 31;
        }
        else if(pet->getStat().getDEX() > 400){
            return 32;
        }
        else if((pet->getStat().getINT()+pet->getStat().getLUX()) > 700){
            return 33;
        }
        else if(pet->getStat().getLUX() > 400){
            return 34;
        }
        else if(pet->getStat().getINT() > 400){
            return 35;
        }
        else{
            return -1;
        }
    }
    else if( (pet->getPet_kind() / 10) == 3){
        if( (pet->getStat().getSTR() + pet->getStat().getDEX() +
             pet->getStat().getLUX() + pet->getStat().getINT()) > 2000 && pet->getStat().getINT() > 1000 ){
            return 40;
        }
        else if((pet->getStat().getSTR() + pet->getStat().getDEX() +
                 pet->getStat().getLUX() + pet->getStat().getINT()) > 2000 ){
            return 41;
        }
        else if(pet->getStat().getINT() > 1500){
            return 42;
        }
        else if(pet->getStat().getSTR() > 1500){
            return 43;
        }
        else{
            return -1;
        }
    }
    else if( (pet->getPet_kind() / 10) == 4){
        if((pet->getStat().getSTR() + pet->getStat().getDEX() + pet->getStat().getINT() + pet->getStat().getLUX())>2500)
            return -2; // 펫 졸업한다.
    }
    else{
        return -3; // we cannot know pet_kind
    }
}

void player::pet_evolution_to_level2()
{
    Pet* temp = new Pet_level_2(pet->getStat(), pet->getSick());
    delete pet;
    pet = temp;
    pet_level = 2;
}

void player::pet_evolution_to_level3()
{
    Pet* temp = new Pet_level_3(pet->getStat(), pet->getSick());
    delete pet;
    pet = temp;
    pet_level = 3;
}

void player::pet_evolution_to_level4()
{
    Pet* temp = new Pet_level_4(pet->getStat(), pet->getSick());
    delete pet;
    pet = temp;
    pet_level = 4;
}

int player::getMoney() const
{
    return money;
}

void player::setMoney(int value)
{
    money = value;
}

ItemVector* player::getItemList()
{
    return &ItemList;
}

Pet *player::getPet() const
{
    return pet;
}

void player::setPet(Pet *value)
{
    pet = value;
}

int player::getFatigue() const
{
    return fatigue;
}

void player::setFatigue(int value)
{
    fatigue = value;
}

int player::getPlay_time() const
{
    return play_time;
}

void player::setPlay_time(int value)
{
    play_time = value;
}
