#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "main_menu.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    int id;
    int id_podraynds;
    int id_help;
    bool id_winnings;
    bool id_names = true;
    Game(bool id_winnings);
    bool Winnings_id();

private:
    Ui::Game *ui;
    QTimer *timer;
    int time;
    QString money;
    QString money2;
    int m = 680; //Высота иконок
    int a = 480; //Ширина иконок
    QString name;
    QString last_game_info;

private slots:
    void Winnings();
    void Retry();
    void TimerSlot();
    void Rounds();
    void Personalizing_buttons();
    void Question_file();
    void Wrong_answer();
    void Correct_answer();
    void Last_game();
    void closeEvent(QCloseEvent *event);

    void Round_1_Question_and_Answer();
    void Round_2_Question_and_Answer();
    void Round_3_Question_and_Answer();
    void Round_4_Question_and_Answer();
    void Round_5_Question_and_Answer();
    void Round_6_Question_and_Answer();
    void Round_7_Question_and_Answer();
    void Round_8_Question_and_Answer();
    void Round_9_Question_and_Answer();
    void Round_10_Question_and_Answer();
    void Round_11_Question_and_Answer();
    void Round_12_Question_and_Answer();
    void Round_13_Question_and_Answer();
    void Round_14_Question_and_Answer();
    void Round_15_Question_and_Answer();

    void on_exit_to_menu_clicked();
    void on_help_friends_clicked();
    void on_fivenafine_clicked();
    void on_help_hall_clicked();

    void on_answer_A_clicked();
    void on_answer_B_clicked();
    void on_answer_C_clicked();
    void on_answer_D_clicked();
};

#endif // GAME_H
