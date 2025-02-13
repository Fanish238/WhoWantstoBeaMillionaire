#ifndef HELP_FRIENDS_AND_HALL_H
#define HELP_FRIENDS_AND_HALL_H

#include <QDialog>
#include "main_menu.h"

namespace Ui {
class Help_Friends;
}

class Help_Friends : public QDialog
{
    Q_OBJECT

public:
    explicit Help_Friends(QWidget *parent = nullptr);
    ~Help_Friends();
    Help_Friends(int id,int id_podraynds,int id_help);
    int Help_Friens_id();
    int id;
    int id_podraynds;
    int id_help;

private:
    int id_clicked_help_friends;
    int A,B,C,D;
    QString Answer;
    QString name;
    QString name_friends;
    QString text_friends;

private slots:
    void NameFriends();

    void NameFriends_Round_1();
    void NameFriends_Round_2();
    void NameFriends_Round_3();
    void NameFriends_Round_4();
    void NameFriends_Round_5();
    void NameFriends_Round_6();
    void NameFriends_Round_7();
    void NameFriends_Round_8();
    void NameFriends_Round_9();
    void NameFriends_Round_10();
    void NameFriends_Round_11();
    void NameFriends_Round_12();
    void NameFriends_Round_13();
    void NameFriends_Round_14();
    void NameFriends_Round_15();

    void on__1_clicked();
    void on__2_clicked();
    void on__3_clicked();

    void Switch_id_podrounds();
    void Help_Hall();
    void Help_Friends_file();
    void on_ok_clicked();

private:
    Ui::Help_Friends *ui;
};

#endif // HELP_FRIENDS_AND_HALL_H
