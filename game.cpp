#include "game.h"
#include "ui_game.h"

bool id_winnings2 = false;

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    QPixmap telephone_icon(":/resource/Resource/img/telephone.png"); //Иконка телефона
    ui->telephone_icon->setPixmap(telephone_icon.scaled(m,a,Qt::KeepAspectRatio));

    QPixmap fivenafive_icon(":/resource/Resource/img/50na50.png"); //Иконка 50 на 50
    ui->fivenafive_icon->setPixmap(fivenafive_icon.scaled(m,a,Qt::KeepAspectRatio));

    QPixmap piople_icon(":/resource/Resource/img/piople.png"); //Иконка люди
    ui->help_hall_icon->setPixmap(piople_icon.scaled(m,a,Qt::KeepAspectRatio));

    QPixmap fondyatimer(":/resource/Resource/img/fondyatimer.png"); //Фона таймера
    ui->fondyatimer->setPixmap(fondyatimer.scaled(m,a,Qt::KeepAspectRatio));

    QPixmap pix2(":/resource/Resource/img/fon.png"); //Фона
    int l = ui->fon->width();
    int o = ui->fon->height();
    ui->fon->setPixmap(pix2.scaled(l,o,Qt::KeepAspectRatio));

    ui->help_friends->setToolTip("Подсказка ''Помощь Друга''"); //При наведени выскакивает подсказка
    ui->fivenafine->setToolTip("Подсказка ''50 на 50''"); //При наведени выскакивает подсказка
    ui->help_hall->setToolTip("Подсказка ''Помощь Зала''"); //При наведени выскакивает подсказка

    QFile mFile(".//last_game.txt");
    if(mFile.size() > 1000){
       mFile.open(QFile::WriteOnly | QFile::Truncate); //Очистка данных о последних играх

    }
    mFile.close();

    QFile mFile2(".//player.txt");
    if(mFile2.open(QFile::ReadOnly | QFile::Text)) //Получение имени игрока и пресвоение его переменной name
    {
        QTextStream stream(&mFile2);
        QString buffer = stream.readAll();
        name = buffer;
    }
    mFile2.flush();
    mFile2.close();

    Main_menu *names = new Main_menu(id_names); //Передача переменной id_names в класс main_menu
    names -> Main_menu_names();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(TimerSlot())); //Код таймера
    timer->start(1000);

    id = 1; //Переменная отвечающая за все Раунды
    id_podraynds = 0; //Переменная отвечающая за все ПодРаунды
    money2 = "0"; //Баланс
    Rounds();
}

Game::~Game()
{
    delete ui;
}

void Game::Question_file() //Функция отвечающая за работу с файлами
{
    QString QString_id = QString::number(id); //Преобразование из int в QString

    QFile file(":/resource/Resource/questions_and_answers/rounds_"+QString_id+".txt"); //Путь к файлам

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QStringList lines = QString(file.readAll()).split("\n"); //Построчное считывание файла
    switch (id_podraynds) {
    case 1:
        ui->question->setText(lines.at(1)+'\n'+lines.at(2)+'\n'+lines.at(3));
        ui->answer_A->setText(lines.at(4));
        ui->answer_B->setText(lines.at(5));
        ui->answer_C->setText(lines.at(6));
        ui->answer_D->setText(lines.at(7));
        break;
    case 2:
        ui->question->setText(lines.at(9)+'\n'+lines.at(10)+'\n'+lines.at(11));
        ui->answer_A->setText(lines.at(12));
        ui->answer_B->setText(lines.at(13));
        ui->answer_C->setText(lines.at(14));
        ui->answer_D->setText(lines.at(15));
        break;
    case 3:
        ui->question->setText(lines.at(17)+'\n'+lines.at(18)+'\n'+lines.at(19));
        ui->answer_A->setText(lines.at(20));
        ui->answer_B->setText(lines.at(21));
        ui->answer_C->setText(lines.at(22));
        ui->answer_D->setText(lines.at(23));
        break;
    case 4:
        ui->question->setText(lines.at(25)+'\n'+lines.at(26)+'\n'+lines.at(27));
        ui->answer_A->setText(lines.at(28));
        ui->answer_B->setText(lines.at(29));
        ui->answer_C->setText(lines.at(30));
        ui->answer_D->setText(lines.at(31));
        break;
    case 5:
        ui->question->setText(lines.at(33)+'\n'+lines.at(34)+'\n'+lines.at(35));
        ui->answer_A->setText(lines.at(36));
        ui->answer_B->setText(lines.at(37));
        ui->answer_C->setText(lines.at(38));
        ui->answer_D->setText(lines.at(39));
        break;
    }
    file.flush();
    file.close();

}

void Game::Rounds() //Функция для обращения ко всем Раундом
{
    switch (id) {
    case 1:
        id_podraynds = rand()%5+1; //Рандом от 1 до 5
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_1_Question_and_Answer();
        break;
    case 2:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_2_Question_and_Answer();
        break;
    case 3:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_3_Question_and_Answer();
        break;
    case 4:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_4_Question_and_Answer();
        break;
    case 5:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_5_Question_and_Answer();
        break;
    case 6:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_6_Question_and_Answer();
        break;
    case 7:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_7_Question_and_Answer();
        break;
    case 8:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_8_Question_and_Answer();
        break;
    case 9:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_9_Question_and_Answer();
        break;
    case 10:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_10_Question_and_Answer();
        break;
    case 11:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_11_Question_and_Answer();
        break;
    case 12:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_12_Question_and_Answer();
        break;
    case 13:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_13_Question_and_Answer();
        break;
    case 14:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_14_Question_and_Answer();
        break;
    case 15:
        id_podraynds = rand()%5+1;
        qDebug() << "Round: " << id << "\nNumber PodRounds: " << id_podraynds;
        Round_15_Question_and_Answer();
        break;
    }
}

void Game::Last_game() //Функция отвечающая за сбор данных и записи этих данных в тектовый файл, для последующего просмотра
{
    if(last_game_info == ""){
        last_game_info = "\nНи Одна из подсказок не была использована!";
    }

    QFile mFile(".//last_game.txt");
    if(mFile.open(QFile::Append | QFile::Text))
    {
        const QString Time = QDateTime::currentDateTime().toString("hh:mm");
        const QString Date = QDateTime::currentDateTime().toString("dd.MM.yyyy");
        QTextStream stream(&mFile);
        stream << "Имя игрока: " << name << '\n';
        stream << "Дата проведения игры: " << Date << '\n';
        stream << "Время проведения игры: " << Time << '\n';
        stream << "Дошёл до: Раунда " << id << '\n';
        stream << "Максимальный выигрыш: " << money2 << "РУБ.\n";
        stream << "Использованные подсказки: " << last_game_info << '\n';
        stream << "\n";
    }
    mFile.close();
}

void Game::Retry() //Функция спрашивающая, хочет ли игрок сново сыграть?
{
    QMessageBox::StandardButton reyly;
    reyly = QMessageBox::question(this,"Игра","Неудачно в этот раз,\nповторить?",QMessageBox::Yes | QMessageBox:: No);
    if(reyly == QMessageBox::Yes){
        delete window(); //Очищаю старую форму
        Game *window = new Game(); //Подгружаю её заного
        window->show();
    }
    else{
        Last_game();
        QMessageBox::information(this,"Игра","Имя игрока: "+name+"\nМаксимальный выигрыш: "+money2+"РУБ");
        delete window(); //Очищаю старую форму
        Main_menu *window = new Main_menu(); //Перехожу на окно Main_menu
        window->show();
    }
}

Game::Game(bool id_winnings)
{
    this->id_winnings = id_winnings; //Получаю переменную id_winnings из класса winnings
    id_winnings2 = id_winnings; //Присваиваю полученные данные глобальной переменной
}

bool Game::Winnings_id()
{
    return id_winnings;
}

void Game::Winnings() //Функция отвечающая за выдачу приза
{
    winnings *win_id = new winnings(id); //Передача переменной id в класс Winnings
    win_id -> winnings_id();

    winnings window; //Открытие окна с выдачей приза
    window.setModal(true);
    window.exec();
    if(id_winnings2 == true){
        Last_game();
        QMessageBox::information(this,"Игра",name+"\nИтоговый баланс: "+money2+"РУБ");
        this->deleteLater(); //Очищаю форму
        Main_menu *window = new Main_menu(); //Переход на окно Main_menu
        window->show();
    }

}

void Game::TimerSlot() //Функция таймера
{
    while(time>0){
        time--;
        ui->time_label->setText(QString::number(time)); //Отсчёт таймера от 30 до 0
        break;
    }
    switch (time) {
    case 0:
        timer->stop();
        QMessageBox::information(this,"Игра", "Время вышло!");
        Retry();
        break;
    }
}

void Game::closeEvent(QCloseEvent *event) //Функция отвечающая за закрытие приложения через крестик
{
    event->ignore();
    QMessageBox::StandardButton reyly;
    reyly = QMessageBox::question(this,"Выход","Вы уверены?",QMessageBox::Yes | QMessageBox:: No);
    if(reyly == QMessageBox::Yes){
        Last_game();
        event->accept();
    }
}

void Game::on_exit_to_menu_clicked() //Функция кнопки выхода
{
    QMessageBox::StandardButton reyly;
    reyly = QMessageBox::question(this,"Выход","Вы уверены?",QMessageBox::Yes | QMessageBox:: No);
    if(reyly == QMessageBox::Yes){
        Last_game();
        QMessageBox::information(this,"Игра",name+"\nИтоговый баланс: "+money2+"РУБ");
        delete window(); //Очистка формы
        Main_menu *window = new Main_menu(); //Переход на окно Main_menu
        window->show();
    }
}

void Game::on_help_hall_clicked() //Функция отвечающая за подсказку "Помощь зала"
{
    last_game_info = last_game_info+"\nПодсказка: ''Помощь зала''";

    id_help = 1;

    Help_Friends *Help_id = new Help_Friends(id,id_podraynds,id_help); //Перенос переменных из game в Help_Friends_and_Hall
    Help_id -> Help_Friens_id();

    timer->stop();

    Help_Friends window;
    window.setModal(true); //Переход на окно "Помощь зала"
    window.exec();

    QPixmap piople_icon(":/resource/Resource/img/piople_red.png"); //Иконка использованной подсказки "Помощь зала"
    ui->help_hall_icon->setPixmap(piople_icon.scaled(m,a,Qt::KeepAspectRatio));

    ui->help_hall->hide();

    timer->start();
}

void Game::on_help_friends_clicked() //Функция отвечающая за подсказку "Помощь Друга"
{
    last_game_info = last_game_info+"\nПодсказка: ''Помощь друга''";

    id_help = 0;

    Help_Friends *Help_id = new Help_Friends(id,id_podraynds,id_help); //Перенос переменных из game в Help_Friends_and_Hall
    Help_id -> Help_Friens_id();

    timer->stop();

    Help_Friends window;
    window.setModal(true); //Переход на окно "Помощь друга"
    window.exec();

    QPixmap telephone_icon(":/resource/Resource/img/telephone_red.png"); //Иконка использованной подсказки "Помощь друга"
    ui->telephone_icon->setPixmap(telephone_icon.scaled(m,a,Qt::KeepAspectRatio));

    ui->help_friends->hide();

    timer->start();
}

void Game::on_fivenafine_clicked() //Функция отвечающая за подсказку "50 на 50"
{
    last_game_info = last_game_info+"\nПодсказка: ''50 на 50''";

    QPixmap fivenafive_icon(":/resource/Resource/img/50na50_red.png"); //Иконка использованной подсказки "50 на 50"
    ui->fivenafive_icon->setPixmap(fivenafive_icon.scaled(m,a,Qt::KeepAspectRatio));

    ui->fivenafine->hide(); //Убирает кнопку 50 на 50 после использования

    switch (id) {
    case 1:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide(); //Убирает неправельные кнопки
            ui->answer_C->hide(); //Убирает неправельные кнопки
            break;
        case 2:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        }
        break;
    case 2:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 3:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 5:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        }
        break;
    case 3:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_B->hide();
            break;
        case 4:
            ui->answer_A->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 4:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 2:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        }
        break;
    case 5:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 2:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 6:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 5:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 7:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 4:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        }
        break;
    case 8:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 3:
            ui->answer_A->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 9:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 5:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 10:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 2:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 5:
            ui->answer_A->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 11:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 2:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 5:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        }
        break;
    case 12:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_C->hide();;
            break;
        case 2:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        }
        break;
    case 13:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 2:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 3:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_A->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    case 14:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 3:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_C->hide();
            break;
        case 5:
            ui->answer_A->hide();
            ui->answer_C->hide();
            break;
        }
        break;
    case 15:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 2:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        case 3:
            ui->answer_A->hide();
            ui->answer_B->hide();
            break;
        case 4:
            ui->answer_B->hide();
            ui->answer_D->hide();
            break;
        case 5:
            ui->answer_C->hide();
            ui->answer_D->hide();
            break;
        }
        break;
    }
}

void Game::Correct_answer() //Функция отвечающая за правильное ответы
{
    QString QString_id = QString::number(id); //Преобразование из int в QString

    if(id == 5 || id == 10 || id == 15)
    {
        QMessageBox::information(this,"Раунд "+QString_id, "Правильно!\nБаланс: "+money+"РУБ");
        money2= money;
        Winnings();
        id++;
        Rounds();
    }
    else
    {
        QMessageBox::information(this,"Раунд "+QString_id, "Правильно!\nБаланс: "+money+"РУБ");
        money2= money;
        id++;
        Rounds();
    }
}

void Game::Wrong_answer() //Функция отвечающая за неправильные ответы
{
    QString QString_id = QString::number(id); //Преобразование из int в QString
    QMessageBox::critical(this,"Раунд "+QString_id, "Неправильно!");
    Retry();
}

void Game::on_answer_A_clicked() //Ответ А
{
    timer->stop();
    switch (id) {
    case 1:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 2:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 3:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 4:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 5:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 6:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 7:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 8:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 9:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 10:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 11:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 12:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 13:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 14:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 15:
        switch (id_podraynds) {
        case 1:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_A->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_A->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    }
}

void Game::on_answer_B_clicked() //Ответ В
{
    timer->stop();
    switch (id) {
    case 1:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 2:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 3:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 4:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 5:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 6:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 7:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 8:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 9:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 10:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 11:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 12:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 13:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 14:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 15:
        switch (id_podraynds) {
        case 1:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_B->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    }
}

void Game::on_answer_C_clicked() //Ответ С
{
    timer->stop();
    switch (id) {
    case 1:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 2:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 3:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 4:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 5:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 6:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 7:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 8:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 9:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 10:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 11:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 12:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 13:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 14:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 15:
        switch (id_podraynds) {
        case 1:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_C->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_C->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    }
}

void Game::on_answer_D_clicked() //Ответ D
{
    timer->stop();
    switch (id) {
    case 1:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 2:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 3:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 4:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 5:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 6:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 7:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 8:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 9:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 10:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 11:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 12:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 13:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    case 14:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(70, 209, 0); border: none");
            Correct_answer();
            break;
        }
        break;
    case 15:
        switch (id_podraynds) {
        case 1:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 2:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 3:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 4:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        case 5:
            ui->answer_D->setStyleSheet("background-color: rgb(227, 0, 0); border: none");
            Wrong_answer();
            break;
        }
        break;
    }
}

void Game::Personalizing_buttons() //Функция отвечающая за визуальную часть кнопок
{
    ui->answer_A->show();
    ui->answer_B->show();
    ui->answer_C->show();
    ui->answer_D->show();
    ui->question->setStyleSheet("color: rgb(255, 255, 255)");
    ui->answer_A->setStyleSheet("QPushButton { background-color: rgb(207, 207, 207); border: none;} QPushButton:hover { background-color: rgb(255, 170, 0); border: none;}");
    ui->answer_B->setStyleSheet("QPushButton { background-color: rgb(207, 207, 207); border: none;} QPushButton:hover { background-color: rgb(255, 170, 0); border: none;}");
    ui->answer_C->setStyleSheet("QPushButton { background-color: rgb(207, 207, 207); border: none;} QPushButton:hover { background-color: rgb(255, 170, 0); border: none;}");
    ui->answer_D->setStyleSheet("QPushButton { background-color: rgb(207, 207, 207); border: none;} QPushButton:hover { background-color: rgb(255, 170, 0); border: none;}");
}

void Game::Round_1_Question_and_Answer() // Раунд 1
{
    setWindowIcon(QIcon(":/resource/Resource/img/1_round.png"));
    setWindowTitle("Раунд 1");
    ui->time_label->setText(QString("20"));
    time=21;
    money = "500";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_2_Question_and_Answer() //Раунд 2
{
    setWindowIcon(QIcon(":/resource/Resource/img/2_round.png"));
    setWindowTitle("Раунд 2");
    ui->time_label->setText(QString("20"));
    time=21;
    timer->start();
    money = "1.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_3_Question_and_Answer() //Раунд 3
{
    setWindowIcon(QIcon(":/resource/Resource/img/3_round.png"));
    setWindowTitle("Раунд 3");
    ui->time_label->setText(QString("20"));
    time=21;
    timer->start();
    money = "2.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_4_Question_and_Answer() //Раунд 4
{
    setWindowIcon(QIcon(":/resource/Resource/img/4_round.png"));
    setWindowTitle("Раунд 4");
    ui->time_label->setText(QString("20"));
    time=21;
    timer->start();
    money = "3.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_5_Question_and_Answer() //Раунд 5,
{
    setWindowIcon(QIcon(":/resource/Resource/img/5_round.png"));
    setWindowTitle("Раунд 5");
    ui->time_label->setText(QString("20"));
    time=21;
    timer->start();
    money = "5.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_6_Question_and_Answer() //Раунд 6
{
    setWindowIcon(QIcon(":/resource/Resource/img/6_round.png"));
    setWindowTitle("Раунд 6");
    ui->time_label->setText(QString("30"));
    time=31;
    timer->start();
    money = "10.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_7_Question_and_Answer() //Раунд 7
{
    setWindowIcon(QIcon(":/resource/Resource/img/7_round.png"));
    setWindowTitle("Раунд 7");
    ui->time_label->setText(QString("30"));
    time=31;
    timer->start();
    money = "15.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_8_Question_and_Answer() //Раунд 8
{
    setWindowIcon(QIcon(":/resource/Resource/img/8_round.png"));
    setWindowTitle("Раунд 8");
    ui->time_label->setText(QString("30"));
    time=31;
    timer->start();
    money = "25.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_9_Question_and_Answer() //Раунд 9
{
    setWindowIcon(QIcon(":/resource/Resource/img/9_round.png"));
    setWindowTitle("Раунд 9");
    ui->time_label->setText(QString("30"));
    time=31;
    timer->start();
    money = "50.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_10_Question_and_Answer() //Раунд 10
{
    setWindowIcon(QIcon(":/resource/Resource/img/10_round.png"));
    setWindowTitle("Раунд 10");
    ui->time_label->setText(QString("30"));
    time=31;
    timer->start();
    money = "100.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_11_Question_and_Answer() //Раунд 11
{
    setWindowIcon(QIcon(":/resource/Resource/img/11_round.png"));
    setWindowTitle("Раунд 11");
    ui->time_label->setText(QString("40"));
    time=41;
    timer->start();
    money = "200.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_12_Question_and_Answer() //Раунд 12
{
    setWindowIcon(QIcon(":/resource/Resource/img/12_round.png"));
    setWindowTitle("Раунд 12");
    ui->time_label->setText(QString("40"));
    time=41;
    timer->start();
    money = "400.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_13_Question_and_Answer() //Раунд 13
{
    setWindowIcon(QIcon(":/resource/Resource/img/13_round.png"));
    setWindowTitle("Раунд 13");
    ui->time_label->setText(QString("40"));
    time=41;
    timer->start();
    money = "800.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_14_Question_and_Answer() //Раунд 14
{
    setWindowIcon(QIcon(":/resource/Resource/img/14_round.png"));
    setWindowTitle("Раунд 14");
    ui->time_label->setText(QString("40"));
    time=41;
    timer->start();
    money = "1.500.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}

void Game::Round_15_Question_and_Answer() //Раунд 15
{
    setWindowIcon(QIcon(":/resource/Resource/img/15_round.png"));
    setWindowTitle("Раунд 15");
    ui->time_label->setText(QString("40"));
    time=41;
    timer->start();
    money = "3.000.000";
    ui->money->setText(QString(money+"РУБ"));
    Question_file();
    Personalizing_buttons();
}
