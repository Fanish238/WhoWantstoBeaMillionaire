#include "help_friends_and_hall.h"
#include "ui_help_friends_and_hall.h"

int id2;
int id_podraynds2;
int id_help2;

Help_Friends::Help_Friends(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help_Friends)
{
    ui->setupUi(this);

    if(id_help2 == 0){
        setWindowIcon(QIcon(":/resource/Resource/img/telephone_2.png")); //Иконка приложения

        this->setWindowTitle("Помощь друга");

        QFile mFile(".//player.txt");
        if(mFile.open(QFile::ReadOnly | QFile::Text)) //Получение имени игрока и пресвоение его переменной name
        {
            QTextStream stream(&mFile);
            QString buffer = stream.readAll();
            name = buffer;
        }
        mFile.flush();
        mFile.close();

        ui->ok->hide();
        ui->progressBar_A->hide();
        ui->progressBar_B->hide();
        ui->progressBar_C->hide();
        ui->progressBar_D->hide();
        ui->_A->hide();
        ui->_B->hide();
        ui->_C->hide();
        ui->_D->hide();

        QPixmap friends_1(":/resource/Resource/img/friends.png"); //Иконка Первый друг
        int l = 450; //Высота иконок
        int o = 400; //Ширина иконок
        ui->friends_1->setPixmap(friends_1.scaled(l,o,Qt::KeepAspectRatio));

        QPixmap friends_2(":/resource/Resource/img/friends.png"); //Иконка Второй друг
        ui->friends_2->setPixmap(friends_2.scaled(l,o,Qt::KeepAspectRatio));

        QPixmap friends_3(":/resource/Resource/img/friends.png"); //Иконка Третий друг
        ui->friends_3->setPixmap(friends_3.scaled(l,o,Qt::KeepAspectRatio));

        NameFriends();
    }
    else if(id_help2 == 1){
        setWindowIcon(QIcon(":/resource/Resource/img/piople_2.png")); //Иконка приложения

        this->setWindowTitle("Помощь зала");

        ui->_1->hide();
        ui->_2->hide();
        ui->_3->hide();
        ui->fon_name_friends_1->hide();
        ui->fon_name_friends_2->hide();
        ui->fon_name_friends_3->hide();

        Help_Hall();
    }
}

Help_Friends::Help_Friends(int id, int id_podraynds,int id_help)
{
    this->id = id; //Получение переменных из game
    this->id_podraynds = id_podraynds;
    this->id_help = id_help;
    id2 = id; //Присвоение переменных полученных из game, глобальным переменным
    id_podraynds2 = id_podraynds;
    id_help2 = id_help;
}

int Help_Friends::Help_Friens_id()
{
    return id;
    return id_podraynds;
    return id_help;
}

Help_Friends::~Help_Friends()
{
    delete ui;
}

void Help_Friends::on_ok_clicked()
{
    this->close();
}

void Help_Friends::Help_Friends_file() //Функция отвечающая за работу с файлами
{
    QString QString_id = QString::number(id2); //Преобразование из int в QString

    QFile file(":/resource/Resource/help_friends/rounds_"+QString_id+".txt"); //Путь к файлам

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QStringList lines = QString(file.readAll()).split("\n"); //Построчное считывание файла
    switch (id_clicked_help_friends) {
    case 1:
        name_friends = lines.at(0);
        switch (id_podraynds2) {
        case 1:
            text_friends = "Привет "+name+lines.at(1);
            break;
        case 2:
            text_friends = "Привет "+name+lines.at(2);
            break;
        case 3:
            text_friends = "Привет "+name+lines.at(3);
            break;
        case 4:
            text_friends = "Привет "+name+lines.at(4);
            break;
        case 5:
            text_friends = "Привет "+name+lines.at(5);
            break;
        }
        file.flush();
        file.close();
        break;
    case 2:
        name_friends = lines.at(7);
        switch (id_podraynds2) {
        case 1:
            text_friends = "Привет "+name+lines.at(8);
            break;
        case 2:
            text_friends = "Привет "+name+lines.at(9);
            break;
        case 3:
            text_friends = "Привет "+name+lines.at(10);
            break;
        case 4:
            text_friends = "Привет "+name+lines.at(11);
            break;
        case 5:
            text_friends = "Привет "+name+lines.at(12);
            break;
        }
        file.flush();
        file.close();
        break;
    case 3:
        name_friends = lines.at(14);
        switch (id_podraynds2) {
        case 1:
            text_friends = "Привет "+name+lines.at(15);
            break;
        case 2:
            text_friends = "Привет "+name+lines.at(16);
            break;
        case 3:
            text_friends = "Привет "+name+lines.at(17);
            break;
        case 4:
            text_friends = "Привет "+name+lines.at(18);
            break;
        case 5:
            text_friends = "Привет "+name+lines.at(19);
            break;
        }
        file.flush();
        file.close();
        break;
    }

}

void Help_Friends::NameFriends() //Функция для обращения ко всем Помощь Друга
{
    switch (id2) {
    case 1:
        NameFriends_Round_1();
        break;
    case 2:
        NameFriends_Round_2();
        break;
    case 3:
        NameFriends_Round_3();
        break;
    case 4:
        NameFriends_Round_4();
        break;
    case 5:
        NameFriends_Round_5();
        break;
    case 6:
        NameFriends_Round_6();
        break;
    case 7:
        NameFriends_Round_7();
        break;
    case 8:
        NameFriends_Round_8();
        break;
    case 9:
        NameFriends_Round_9();
        break;
    case 10:
        NameFriends_Round_10();
        break;
    case 11:
        NameFriends_Round_11();
        break;
    case 12:
        NameFriends_Round_12();
        break;
    case 13:
        NameFriends_Round_13();
        break;
    case 14:
        NameFriends_Round_14();
        break;
    case 15:
        NameFriends_Round_15();
        break;
    }
}

void Help_Friends::NameFriends_Round_1() //Функция для имён и видов деятельностей Друзей Первого рауда
{
    ui->name_friends_1->setText(QString(" Преподаватель\n физкультуры"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Знакомый\n футболист"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Дима\n друг детства"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_2() //Функция для имён и видов деятельностей Друзей Второго рауда
{
    ui->name_friends_1->setText(QString(" Валера с\n пятиэтажки"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Маринка с\n факультета \n физики"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Вася\n друг детства"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_3() //Функция для имён и видов деятельностей Друзей Третьего рауда
{
    ui->name_friends_1->setText(QString(" Чат рулетка"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Вася\n одноклассник"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Вадим\n одногруппник"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_4() //Функция для имён и видов деятельностей Друзей Четвёртого рауда
{
    ui->name_friends_1->setText(QString(" Вика\n соседка "));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Дядя Петя\n охранник"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Знакомый\n по работе"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_5() //Функция для имён и видов деятельностей Друзей Пятого рауда
{
    ui->name_friends_1->setText(QString(" Наташа\n медсестра"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Вика \n соседка"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Влад \n одногруппник"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_6() //Функция для имён и видов деятельностей Друзей Шестого рауда
{
    ui->name_friends_1->setText(QString(" Преподователь\n истории"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Родной дед"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Лера\n подруга"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_7() //Функция для имён и видов деятельностей Друзей Седьмого рауда
{
    ui->name_friends_1->setText(QString(" Валерий\n Олегович\n друг родного деда"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Маринка с\n факультета \n физики"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Оператор\n БеларусБанка"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_8() //Функция для имён и видов деятельностей Друзей Восьмого рауда
{
    ui->name_friends_1->setText(QString(" Дима\n одногруппник"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Лилия\n Ивановна\nпродавец"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Оператор\n A1"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_9() //Функция для имён и видов деятельностей Друзей Девятого рауда
{
    ui->name_friends_1->setText(QString(" Рома\n одногруппник"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Дядя Петя\n охранник"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Павел\n сосед"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_10() //Функция для имён и видов деятельностей Друзей Десятого рауда
{
    ui->name_friends_1->setText(QString(" Юра\n сосед"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Ваня\n умняга"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Знакомый из\n России"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_11() //Функция для имён и видов деятельностей Друзей Одиннадцатого рауда
{
    ui->name_friends_1->setText(QString(" Артём\n одногруппник"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Паша\n одногруппник"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Олег\nОлегович\nродствениик"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_12() //Функция для имён и видов деятельностей Друзей Двенадцатого рауда
{
    ui->name_friends_1->setText(QString(" Виктория\n Шувакова\n преподаватель"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Карина с\n факультета \n истории"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Валера с\n пятиэтажки"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_13() //Функция для имён и видов деятельностей Друзей Тринадцатого рауда
{
    ui->name_friends_1->setText(QString(" Чат рулетка"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Вася\n одноклассник"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Вадим\n одногруппник"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_14() //Функция для имён и видов деятельностей Друзей Четырнадцатого рауда
{
    ui->name_friends_1->setText(QString(" Никита\n одногруппник"));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Вика\n соседка"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Женя\n знакомая"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::NameFriends_Round_15() //Функция для имён и видов деятельностей Друзей Пятнадцатого рауда
{
    ui->name_friends_1->setText(QString(" Максим\n одногруппник "));
    ui->name_friends_1->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_2->setText(QString(" Вика\n соседка"));
    ui->name_friends_2->setStyleSheet("color: rgb(255, 255, 255)");
    ui->name_friends_3->setText(QString(" Миша\n одногруппник"));
    ui->name_friends_3->setStyleSheet("color: rgb(255, 255, 255)");
}

void Help_Friends::Switch_id_podrounds()
{
    switch (id_podraynds2) {
    case 1:
        QMessageBox::about(this,name_friends, text_friends);
        close();
        break;
    case 2:
        QMessageBox::about(this,name_friends, text_friends);
        close();
        break;
    case 3:
        QMessageBox::about(this,name_friends, text_friends);
        close();
        break;
    case 4:
        QMessageBox::about(this,name_friends, text_friends);
        close();
        break;
    case 5:
        QMessageBox::about(this,name_friends, text_friends);
        close();
        break;
    }
}

void Help_Friends::on__1_clicked() //Кнопка звонка другу
{
    id_clicked_help_friends = 1;

    Help_Friends_file();
    switch (id2) {
    case 1:
        Switch_id_podrounds();
        break;
    case 2:
        Switch_id_podrounds();
        break;
    case 3:
        Switch_id_podrounds();
        break;
    case 4:
        Switch_id_podrounds();
        break;
    case 5:
        Switch_id_podrounds();
        break;
    case 6:
        Switch_id_podrounds();
        break;
    case 7:
        Switch_id_podrounds();
        break;
    case 8:
        Switch_id_podrounds();
        break;
    case 9:
        Switch_id_podrounds();
        break;
    case 10:
        Switch_id_podrounds();
        break;
    case 11:
        Switch_id_podrounds();
        break;
    case 12:
        Switch_id_podrounds();
        break;
    case 13:
        Switch_id_podrounds();
        break;
    case 14:
        Switch_id_podrounds();
        break;
    case 15:
        Switch_id_podrounds();
        break;
    }
}

void Help_Friends::on__2_clicked() //Кнопка звонка другу
{
    id_clicked_help_friends = 2;
    Help_Friends_file();
    switch (id2) {
    case 1:
        Switch_id_podrounds();
        break;
    case 2:
        Switch_id_podrounds();
        break;
    case 3:
        Switch_id_podrounds();
        break;
    case 4:
        Switch_id_podrounds();
        break;
    case 5:
        Switch_id_podrounds();
        break;
    case 6:
        Switch_id_podrounds();
        break;
    case 7:
        Switch_id_podrounds();
        break;
    case 8:
        Switch_id_podrounds();
        break;
    case 9:
        Switch_id_podrounds();
        break;
    case 10:
        Switch_id_podrounds();
        break;
    case 11:
        Switch_id_podrounds();
        break;
    case 12:
        Switch_id_podrounds();
        break;
    case 13:
        Switch_id_podrounds();
        break;
    case 14:
        Switch_id_podrounds();
        break;
    case 15:
        Switch_id_podrounds();
        break;
    }
}

void Help_Friends::on__3_clicked() //Кнопка звонка другу
{
    id_clicked_help_friends = 3;
    Help_Friends_file();
    switch (id2) {
    case 1:
        Switch_id_podrounds();
        break;
    case 2:
        Switch_id_podrounds();
        break;
    case 3:
        Switch_id_podrounds();
        break;
    case 4:
        Switch_id_podrounds();
        break;
    case 5:
        Switch_id_podrounds();
        break;
    case 6:
        Switch_id_podrounds();
        break;
    case 7:
        Switch_id_podrounds();
        break;
    case 8:
        Switch_id_podrounds();
        break;
    case 9:
        Switch_id_podrounds();
        break;
    case 10:
        Switch_id_podrounds();
        break;
    case 11:
        Switch_id_podrounds();
        break;
    case 12:
        Switch_id_podrounds();
        break;
    case 13:
        Switch_id_podrounds();
        break;
    case 14:
        Switch_id_podrounds();
        break;
    case 15:
        Switch_id_podrounds();
        break;
    }
}

void Help_Friends::Help_Hall(){
    switch (id2) {
    case 1:
        switch (id_podraynds2) {
        case 1:
            A = rand()%20+70; //Диапозона рандома от 70 до 90;
            B = rand()%10+0; //Диапозона рандома от 0 до 10;
            C = rand()%15+0; //Диапозона рандома от 0 до 15;
            D = 100-A-B-C;   //Остаток
            break;
        case 2:
            A = rand()%15+15; //Диапозона рандома от 15 до 30;
            B = rand()%15+15; //Диапозона рандома от 15 до 30;
            C = rand()%25+30; //Диапозона рандома от 30 до 55;
            D = 100-A-B-C;   //Остаток
            break;
        case 3:
            A = rand()%5+10; //Диапозона рандома от 10 до 15;
            B = rand()%10+70; //Диапозона рандома от 70 до 80;
            C = rand()%5+0; //Диапозона рандома от 0 до 5;
            D = 100-A-B-C;   //Остаток
            break;
        case 4:
            A = rand()%15+25; //Диапозона рандома от 25 до 40;
            B = rand()%15+45; //Диапозона рандома от 45 до 60;
            C = rand()%10+0; //Диапозона рандома от 0 до 10;
            D = 100-A-B-C;   //Остаток
            break;
        case 5:
            A = rand()%3+0; //Диапозона рандома от 0 до 3;
            B = rand()%3+0; //Диапозона рандома от 0 до 3;
            C = rand()%4+0; //Диапозона рандома от 0 до 4;
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 2:
        switch (id_podraynds2) {
        case 1:
            A = rand()%10+15; //Диапозона рандома от 15 до 25;
            B = rand()%5+10; //Диапозона рандома от 10 до 15;
            C = rand()%15+50; //Диапозона рандома от 50 до 65;
            D = 100-A-B-C;   //Остаток
            break;
        case 2:
            A = rand()%7+35; //Диапозона рандома от 35 до 42;
            B = rand()%5+20; //Диапозона рандома от 20 до 25;
            C = rand()%10+30; //Диапозона рандома от 30 до 40;
            D = 100-A-B-C;   //Остаток
            break;
        case 3:
            A = rand()%10+40; //Диапозона рандома от 40 до 50;
            B = rand()%10+0; //Диапозона рандома от 0 до 10;
            C = rand()%10+40; //Диапозона рандома от 40 до 50;
            D = 100-A-B-C;   //Остаток
            break;
        case 4:
            A = rand()%15+60; //Диапозона рандома от 60 до 75;
            B = rand()%8+0; //Диапозона рандома от 0 до 8;
            C = rand()%8+0; //Диапозона рандома от 0 до 8;
            D = 100-A-B-C;   //Остаток
            break;
        case 5:
            A = rand()%5+0; //Диапозона рандома от 0 до 5;
            B = rand()%5+0; //Диапозона рандома от 0 до 5;
            C = rand()%20+70; //Диапозона рандома от 70 до 90;
            D = 100-A-B-C;   //Остаток
            break;
        }
        break;
    case 3:
        switch (id_podraynds2) {
        case 1:
            A = rand()%10+20; //Диапозона рандома от 20 до 30;
            B = rand()%5+30; //Диапозона рандома от 30 до 35;
            C = rand()%20+5; //Диапозона рандома от 5 до 20;
            D = 100-A-B-C;   //Остаток
            break;
        case 2:
            A = rand()%25+10; //Диапозона рандома от 10 до 35;
            B = rand()%10+0; //Диапозона рандома от 0 до 10;
            C = rand()%15+20; //Диапозона рандома от 20 до 35;
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%10+10; //Диапозона рандома от 10 до 20;
            B = rand()%10+10; //Диапозона рандома от 10 до 20;
            C = rand()%10+30; //Диапозона рандома от 30 до 40;
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%10+0; //Диапозона рандома от 0 до 10;
            B = rand()%25+50; //Диапозона рандома от 50 до 75;
            C = rand()%10+5; //Диапозона рандома от 5 до 15;
            D = 100-A-B-C;   //Остаток
            break;
        case 5:
            A = rand()%20+30; //Диапозона рандома от 30 до 50
            B = rand()%15+5; //Диапозона рандома от 5 до 20
            C = rand()%5+25; //Диапозона рандома от 25 до 30
            D = 100-A-B-C;   //Остаток
            break;
        }
        break;
    case 4:
        switch (id_podraynds2) {
        case 1:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%10+10; //Диапозона рандома от 10 до 20
            C = rand()%5+0; //Диапозона рандома от 0 до 5
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%10+20; //Диапозона рандома от 20 до 30
            B = rand()%10+20; //Диапозона рандома от 20 до 30
            C = rand()%5+20; //Диапозона рандома от 20 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%35+60; //Диапозона рандома от 60 до 95
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%5+5; //Диапозона рандома от 5 до 10
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%15+30; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%25+65; //Диапозона рандома от 65 до 90
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 5:
        switch (id_podraynds2) {
        case 1:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%10+5; //Диапозона рандома от 5 до 15
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%10+15; //Диапозона рандома от 15 до 25
            B = rand()%15+22; //Диапозона рандома от 22 до 37
            C = rand()%20+14; //Диапозона рандома от 14 до 34
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%30+60; //Диапозона рандома от 60 до 90
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%20+5; //Диапозона рандома от 5 до 25
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%20+15; //Диапозона рандома от 15 до 35
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%25+20; //Диапозона рандома от 20 до 40
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 6:
        switch (id_podraynds2) {
        case 1:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%15+35; //Диапозона рандома от 35 до 50
            C = rand()%15+35; //Диапозона рандома от 35 до 50
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%10+0; //Диапозона рандома от 0 до 10
            B = rand()%10+30; //Диапозона рандома от 30 до 40
            C = rand()%5+25; //Диапозона рандома от 25 до 30
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%22+25; //Диапозона рандома от 25 до 47
            B = rand()%12+35; //Диапозона рандома от 35 до 47
            C = rand()%5+0; //Диапозона рандома от 0 до 5
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%5+30; //Диапозона рандома от 30 до 35
            B = rand()%15+0; //Диапозона рандома от 0 до 15
            C = rand()%15+5; //Диапозона рандома от 5 до 15
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%15+70; //Диапозона рандома от 70 до 85
            B = rand()%15+0; //Диапозона рандома от 0 до 15
            C = rand()%7+0; //Диапозона рандома от 0 до 7
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 7:
        switch (id_podraynds2) {
        case 1:
            A = rand()%10+40; //Диапозона рандома от 40 до 50
            B = rand()%10+10; //Диапозона рандома от 10 до 20
            C = rand()%5+10; //Диапозона рандома от 5 до 15
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%20+5; //Диапозона рандома от 5 до 25
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%20+10; //Диапозона рандома от 10 до 30
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%20+50; //Диапозона рандома от 50 до 70
            B = rand()%5+0; //Диапозона рандома от 0 до 5
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%15+0; //Диапозона рандома от 0 до 15
            C = rand()%30+50; //Диапозона рандома от 50 до 30
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 8:
        switch (id_podraynds2) {
        case 1:
            A = rand()%15+25; //Диапозона рандома от 25 до 40
            B = rand()%15+0; //Диапозона рандома от 0 до 15
            C = rand()%12+15; //Диапозона рандома от 15 до 27
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%20+25; //Диапозона рандома от 25 до 45
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%20+0; //Диапозона рандома от 0 до 20
            B = rand()%40+30; //Диапозона рандома от 30 до 70
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%20+10; //Диапозона рандома от 10 до 25
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%30+15; //Диапозона рандома от 15 до 45
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 9:
        switch (id_podraynds2) {
        case 1:
            A = rand()%15+5; //Диапозона рандома от 5 до 20
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%30+15; //Диапозона рандома от 15 до 40
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%40+15; //Диапозона рандома от 15 до 55
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%15+5; //Диапозона рандома от 5 до 20
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%20+15; //Диапозона рандома от 15 до 30
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%15+10; //Диапозона рандома от 10 до 25
            C = rand()%15+10; //Диапозона рандома от 10 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%15+5; //Диапозона рандома от 5 до 20
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%40+30; //Диапозона рандома от 30 до 70
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 10:
        switch (id_podraynds2) {
        case 1:
            A = rand()%10+15; //Диапозона рандома от 15 до 25
            B = rand()%10+0; //Диапозона рандома от 5 до 15
            C = rand()%5+20; //Диапозона рандома от 20 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%40+30; //Диапозона рандома от 30 до 70
            B = rand()%20+0; //Диапозона рандома от 0 до 20
            C = rand()%5+20; //Диапозона рандома от 20 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%25+30; //Диапозона рандома от 30 до 55
            B = rand()%15+0; //Диапозона рандома от 5 до 15
            C = rand()%15+20; //Диапозона рандома от 20 до 35
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%20+5; //Диапозона рандома от 5 до 25
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%20+35; //Диапозона рандома от 35 до 55
            B = rand()%40+40; //Диапозона рандома от 40 до 80
            C = rand()%5+5; //Диапозона рандома от 5 до 10
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 11:
        switch (id_podraynds2) {
        case 1:
            A = rand()%10+5; //Диапозона рандома от 5 до 10
            B = rand()%10+5; //Диапозона рандома от 5 до 10
            C = rand()%30+50; //Диапозона рандома от 5 до 10
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%10+25; //Диапозона рандома от 25 до 35
            B = rand()%10+5; //Диапозона рандома от 5 до 10
            C = rand()%20+15; //Диапозона рандома от 15 до 20
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%20+15; //Диапозона рандома от 15 до 35
            B = rand()%20+25; //Диапозона рандома от 25 до 45
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%15+0; //Диапозона рандома от 0 до 15
            C = rand()%10+10; //Диапозона рандома от 10 до 20
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%10+0; //Диапозона рандома от 0 до 10
            B = rand()%20+0; //Диапозона рандома от 0 до 20
            C = rand()%13+0; //Диапозона рандома от 0 до 13
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 12:
        switch (id_podraynds2) {
        case 1:
            A = rand()%60+20; //Диапозона рандома от 20 до 80
            B = rand()%10+5; //Диапозона рандома от 5 до 15
            C = rand()%25+10; //Диапозона рандома от 10 до 35
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%10+0; //Диапозона рандома от 0 до 10
            B = rand()%3+0; //Диапозона рандома от 0 до 3
            C = rand()%13+5; //Диапозона рандома от 5 до 18
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%20+10; //Диапозона рандома от 10 до 30
            B = rand()%30+40; //Диапозона рандома от 40 до 70
            C = rand()%5+10; //Диапозона рандома от 10 до 15
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%5+50; //Диапозона рандома от 50 до 55
            B = rand()%30+20; //Диапозона рандома от 20 до 50
            C = rand()%5+10; //Диапозона рандома от 10 до 15
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%20+5; //Диапозона рандома от 5 до 25
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 13:
        switch (id_podraynds2) {
        case 1:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%5+0; //Диапозона рандома от 0 до 5
            C = rand()%15+5; //Диапозона рандома от 5 до 20
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%20+40; //Диапозона рандома от 40 до 60
            B = rand()%10+10; //Диапозона рандома от 10 до 20
            C = rand()%30+0; //Диапозона рандома от 0 до 30
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%30+45; //Диапозона рандома от 45 до 75
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%12+0; //Диапозона рандома от 0 до 12
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%10+20; //Диапозона рандома от 20 до 30
            B = rand()%15+20; //Диапозона рандома от 20 до 35
            C = rand()%30+30; //Диапозона рандома от 30 до 60
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%15+5; //Диапозона рандома от 5 до 15
            B = rand()%50+15; //Диапозона рандома от 15 до 65
            C = rand()%10+0; //Диапозона рандома от 0 до 10
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 14:
        switch (id_podraynds2) {
        case 1:
            A = rand()%20+0; //Диапозона рандома от 0 до 20
            B = rand()%20+5; //Диапозона рандома от 5 до 20
            C = rand()%30+40; //Диапозона рандома от 40 до 70
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%5+10; //Диапозона рандома от 5 до 15
            B = rand()%20+20; //Диапозона рандома от 20 до 40
            C = rand()%30+30; //Диапозона рандома от 30 до 60
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%50+30; //Диапозона рандома от 30 до 80
            B = rand()%15+10; //Диапозона рандома от 10 до 25
            C = rand()%20+15; //Диапозона рандома от 15 до 35
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%10+0; //Диапозона рандома от 0 до 10
            B = rand()%10+15; //Диапозона рандома от 15 до 25
            C = rand()%15+15; //Диапозона рандома от 15 до 30
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%5+0; //Диапозона рандома от 0 до 5
            B = rand()%10+0; //Диапозона рандома от 0 до 10
            C = rand()%15+0; //Диапозона рандома от 0 до 15
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    case 15:
        switch (id_podraynds2) {
        case 1:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%10+10; //Диапозона рандома от 10 до 20
            C = rand()%25+15; //Диапозона рандома от 15 до 40
            D = 100-A-B-C; //Остаток
            break;
        case 2:
            A = rand()%50+30; //Диапозона рандома от 30 до 80
            B = rand()%7+0; //Диапозона рандома от 0 до 7
            C = rand()%13+0; //Диапозона рандома от 0 до 13
            D = 100-A-B-C; //Остаток
            break;
        case 3:
            A = rand()%10+5; //Диапозона рандома от 5 до 15
            B = rand()%5+0; //Диапозона рандома от 0 до 5
            C = rand()%15+60; //Диапозона рандома от 60 до 75
            D = 100-A-B-C; //Остаток
            break;
        case 4:
            A = rand()%20+5; //Диапозона рандома от 5 до 25
            B = rand()%20+5; //Диапозона рандома от 5 до 25
            C = rand()%20+5; //Диапозона рандома от 5 до 25
            D = 100-A-B-C; //Остаток
            break;
        case 5:
            A = rand()%20+30; //Диапозона рандома от 30 до 50
            B = rand()%15+20; //Диапозона рандома от 20 до 35
            C = rand()%20+20; //Диапозона рандома от 20 до 40
            D = 100-A-B-C; //Остаток
            break;
        }
        break;
    }
    ui->progressBar_A->setValue(A);
    ui->progressBar_B->setValue(B);
    ui->progressBar_C->setValue(C);
    ui->progressBar_D->setValue(D);
}
