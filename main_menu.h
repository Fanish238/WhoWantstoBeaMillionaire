#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <iostream>
#include <QInputDialog>
#include <QTime>
#include <QTimer>
#include <QIcon>
#include <QDebug>
#include <random>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QFile>
#include <QCloseEvent>
#include "game.h"
#include "help_friends_and_hall.h"
#include "winnings.h"

namespace Ui {
class Main_menu;
}

class Main_menu : public QWidget
{
    Q_OBJECT

public:
    explicit Main_menu(QWidget *parent = nullptr);
    ~Main_menu();
    Main_menu(bool id_names);
    bool Main_menu_names();
    bool id_names;
    int size_names;

private slots:
    void Entering_a_name();
    void on_Game_clicked();
    void on_About_the_game_clicked();
    void on_ExitMenu_clicked();
    void on_sprayka_clicked();
    void on_Last_Game_clicked();

private:
    Ui::Main_menu *ui;
};

#endif // MAIN_MENU_H
