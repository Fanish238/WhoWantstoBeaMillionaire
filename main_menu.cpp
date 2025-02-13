#include "main_menu.h"
#include "ui_main_menu.h"
#include "winnings.h"

bool id_names2;

Main_menu::Main_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_menu)
{
    ui->setupUi(this);

    setWindowTitle("Кто хочет стать миллионером?");

    setWindowIcon(QIcon(":/resource/Resource/img/lagatip.png")); //Иконка приложения

    QPixmap pix(":/resource/Resource/img/lagatip.png"); //Картинка логотипа
    int w = 237;
    int h = 235;
    ui->lagatip->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix2(":/resource/Resource/img/fon.png"); //Фон
    int l = ui->fon->width();
    int o = ui->fon->height();
    ui->fon->setPixmap(pix2.scaled(l,o,Qt::KeepAspectRatio));

    if(id_names2 == false){
        Entering_a_name();
        while(size_names > 18){
            QMessageBox::critical(this,"Имя","Вы превысили лимит в 18 символов!");
            Entering_a_name();
        }
    }
    else{
        QFile mFile(".//player.txt");

        if(mFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream(&mFile);
            QString buffer = stream.readAll();
            ui->name_players->setText(QString("Добро пожаловть: "+buffer));
        }

        mFile.flush();
        mFile.close();
    }
}

Main_menu::~Main_menu()
{
    delete ui;
}

Main_menu::Main_menu(bool id_names)
{
    this-> id_names = id_names;
    id_names2 = id_names;
}

bool Main_menu::Main_menu_names()
{
    return id_names;
}

void Main_menu::Entering_a_name() //Функция для ввода имени
{
    bool ok;
    QString text = QInputDialog::getText(this,tr("Имя"),
                                         tr("Введите имя:"), QLineEdit::Normal,"",&ok);
    if(ok && !text.isEmpty()){
        size_names = text.size();
        ui->name_players->setText(QString("Добро пожаловать: "+text));
    }
    else{
        text = "Игрок";
        size_names = text.size();
        ui->name_players->setText(QString("Добро пожаловать: "+text));
    }

    QFile mFile(".//player.txt");
    if(mFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream stream(&mFile);
        stream << text;
    }

    mFile.close();
}

void Main_menu::on_ExitMenu_clicked()
{
    QMessageBox::StandardButton reyly;
    reyly = QMessageBox::question(this,"Выход","Вы уверены?",QMessageBox::Yes | QMessageBox:: No);
    if(reyly == QMessageBox::Yes){
        QApplication::exit();
    }
}

void Main_menu::on_About_the_game_clicked() //Об игре
{
    QMessageBox::information(this,"Об игре","Вспомните все, что знаете, и сорвите джекпот, избегая коварных вопросов! Вас ждут 15 вопросов, которые будут становиться все сложнее и сложнее, а призовой фонд будет расти.\nЗдесь есть всё, чтобы заставить игрока понервничать!");
}

void Main_menu::on_Game_clicked() //Переход на форму игры
{
    this->close();
    Game *window = new Game();
    window->show(); //Переход на саму игру
}

void Main_menu::on_sprayka_clicked() //Справка
{
    QMessageBox::information(this,"Справка","Приложение: Кто хочет стать миллионером?\nВерсия: 1.0\nСоздатель: Коновальчик Михаил\nГруппа: ПСк-21");
}

void Main_menu::on_Last_Game_clicked() //Информация о последней игре
{
    QFile mFile(".//last_game.txt");

    if(mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream stream(&mFile);
        QString buffer = stream.readAll();
        QMessageBox::information(this,"Информация о последних играх",buffer);
    }

    mFile.flush();
    mFile.close();
}
