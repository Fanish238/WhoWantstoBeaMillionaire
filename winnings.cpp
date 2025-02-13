#include "winnings.h"
#include "ui_winnings.h"

int id3;

winnings::winnings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::winnings)
{
    ui->setupUi(this);

    setWindowTitle("Кто хочет стать миллионером");

    setWindowIcon(QIcon(":/resource/Resource/img/lagatip.png")); //Иконка приложения

    ui->text->hide();

    QFile mFile(".//player.txt");

    if(mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream stream(&mFile);
        QString buffer = stream.readAll();
        ui->name->setText(buffer);
    }

    mFile.flush();
    mFile.close();

    QPixmap winnings_fon(":/resource/Resource/img/fon"); //Фон
    int q = 1200; //Высота иконок
    int e = 600; //Ширина иконок
    ui->fon->setPixmap(winnings_fon.scaled(q,e,Qt::KeepAspectRatio));

    if(id3 == 5){
        QPixmap winnings_5000_png(":/resource/Resource/img/win_5000.png"); //Картинка телефона
        ui->ticket->setPixmap(winnings_5000_png.scaled(m,a,Qt::KeepAspectRatio));
    }
    else if(id3 == 10){
        QPixmap winnings_10000_png(":/resource/Resource/img/win_100000.png"); //Картинка телефона
        ui->ticket->setPixmap(winnings_10000_png.scaled(m,a,Qt::KeepAspectRatio));
    }
    else if(id3 == 15){
        QPixmap winnings_10000_png(":/resource/Resource/img/win_3000000.png"); //Картинка телефона
        ui->ticket->setPixmap(winnings_10000_png.scaled(m,a,Qt::KeepAspectRatio));
        ui->Yes->hide();
        ui->No->setText(QString("Выход"));
        ui->text->show();
    }

    // Создадим группу анимации
    animationGroup = new QSequentialAnimationGroup(this);
    animationGroup2 = new QSequentialAnimationGroup(this);

    // Создадим анимацию справа на лево
    QPropertyAnimation* animation_bilet = new QPropertyAnimation(ui->ticket, "geometry");
    animation_bilet->setDuration(1500); // Длительность анимации
    animation_bilet->setStartValue(ui->ticket->geometry()); // Стартовая позиция и геометрия анимации
    animation_bilet->setEndValue(ui->ticket->geometry().translated(-300, 0)); // Конечная позиция и геометрия анимации
    animationGroup->addAnimation(animation_bilet); // Добавим анимацию в группу

    QPropertyAnimation* animation_name = new QPropertyAnimation(ui->name, "geometry");
    animation_name->setDuration(1500);
    animation_name->setStartValue(ui->name->geometry());
    animation_name->setEndValue(ui->name->geometry().translated(-300, 0));
    animationGroup2->addAnimation(animation_name);

    QPropertyAnimation* animation_date = new QPropertyAnimation(ui->date, "geometry");
    animation_date->setDuration(1500); // Длительность анимации
    animation_date->setStartValue(ui->date->geometry()); // Стартовая позиция и геометрия анимации
    animation_date->setEndValue(ui->date->geometry().translated(-300, 0)); // Конечная позиция и геометрия анимации
    animation_date->start(); //Запуск анимации

    QPropertyAnimation* animation_yes = new QPropertyAnimation(ui->Yes, "geometry");
    animation_yes->setDuration(500);
    animation_yes->setStartValue(ui->Yes->geometry());
    animation_yes->setEndValue(ui->Yes->geometry().translated(-326, 0));
    animationGroup->addAnimation(animation_yes);

    QPropertyAnimation* animation_no = new QPropertyAnimation(ui->No, "geometry");
    animation_no->setDuration(500);
    animation_no->setStartValue(ui->No->geometry());
    animation_no->setEndValue(ui->No->geometry().translated(326, 0));
    animationGroup2->addAnimation(animation_no);

    animationGroup->start();
    animationGroup2->start();

    const QString dateTime = QDateTime::currentDateTime().toString("dd/MM/yy");
    ui->date->setText(QString(dateTime));

}

winnings::~winnings()
{
    delete ui;
}

winnings::winnings(int id)
{
    this->id = id;
    id3 = id;
}

int winnings::winnings_id()
{
    return id;
}

void winnings::on_Yes_clicked()
{
    this->close();
    id_winnings = false;
    Game *win_id = new Game(id_winnings);
    win_id -> Winnings_id();
}

void winnings::on_No_clicked()
{
    this->close();
    id_winnings = true;
    Game *win_id = new Game(id_winnings);
    win_id -> Winnings_id();
}

