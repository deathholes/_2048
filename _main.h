#ifndef _MAIN_H
#define _MAIN_H

#include <QMainWindow>
#include<QGridLayout>
#include<QtWidgets>
#include<QPushButton>

class _main : public QWidget
{
    Q_OBJECT
    
public:
    _main(QWidget *parent = 0);
    ~_main();

private:
    //QMainWindow *window;
    QGridLayout *layout;
    QPushButton **btn;
    int mat[4][4];

    void reset();
    void display();
    void add_new_element();
    void game_up();
    void move_up();
    void move_down();
    void move_left();
    void move_right();

protected:
    void keyPressEvent(QKeyEvent *);
};

#endif // _MAIN_H
