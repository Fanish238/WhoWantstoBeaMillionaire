#ifndef WINNINGS_H
#define WINNINGS_H

#include <QDialog>
#include "main_menu.h"

namespace Ui {
class winnings;
}

class winnings : public QDialog
{
    Q_OBJECT

public:
    explicit winnings(QWidget *parent = nullptr);
    ~winnings();
    winnings(int id);
    int winnings_id();
    bool id_winnings;
    int id;

private:
    Ui::winnings *ui;
    int m = 382;
    int a = 233;
    QSequentialAnimationGroup* animationGroup;
    QSequentialAnimationGroup* animationGroup2;

private slots:
    void on_Yes_clicked();
    void on_No_clicked();
};

#endif // WINNINGS_H
