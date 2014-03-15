#include "_main.h"

_main::_main(QWidget *parent)
    : QWidget(parent)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            mat[i][j]=0;
    }
    this->grabKeyboard();
    this->setFocus();
    srand(unsigned(time(0)));
    reset();
}

_main::~_main()
{
    
}

void _main::reset()
{
    layout = new QGridLayout;
    add_new_element();
    btn = new QPushButton * [4];
    for(int i=0;i<4;i++)
    {
        btn[i] = new QPushButton [4] ;
        for(int j=0;j<4;j++)
        {
            btn[i][j].setFlat(true);
            if(mat[i][j])
                btn[i][j].setText(QString::number(mat[i][j]));
            else
                btn[i][j].setText(" ");
            btn[i][j].setFixedSize(80,80);
            layout->addWidget(&btn[i][j],i,j);
        }
    }
    setLayout(layout);
}

void _main::add_new_element()
{
    int count=0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(mat[i][j]==0)
                count++;
    }

    if(count==0)
    {
        game_up();
    }
    int pos = rand()%count;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(!pos && !mat[i][j])
            {
                mat[i][j] = (rand()%3==0)?4:2;
                return;
            }
            if(!mat[i][j])
                pos--;
        }
    }
}

void _main::game_up()
{
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setText("Game up");
    msgbox->show();
}

void _main::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
        move_left();
        break;
    case Qt::Key_Right:
        move_right();
        break;
    case Qt::Key_Up:
            move_up();
        break;
    case Qt::Key_Down:
        move_down();
        break;
    default:
        break;
    }
    add_new_element();
    display();
}

void _main::move_up()
{
    int i,j,k;
    for(j=0;j<4;j++)
    {
        for(i=3;i>0;i--)
        {
            if((mat[i-1][j]==0)&&(mat[i][j]!=0))
            {
                mat[i-1][j] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }

    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
            if(mat[i+1][j] == mat[i][j])
            {
                mat[i][j]+=mat[i+1][j];
                for(k=i+1;k<3;k++)
                {
                    mat[k][j] = mat[k+1][j];
                }
                mat[3][j]=0;
            }
        }
    }
}

void _main::move_down()
{
    int i,j,k;
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
            if((mat[i+1][j]==0)&&(mat[i][j]!=0))
            {
                mat[i+1][j] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }

    for(j=0;j<4;j++)
    {
        for(i=3;i>0;i--)
        {
            if(mat[i-1][j] == mat[i][j])
            {
                mat[i][j]+=mat[i-1][j];
                for(k=0;k<i-1;k++)
                {
                    mat[k+1][j] = mat[k][j];
                }
                mat[0][j]=0;
            }
        }
    }

}

void _main::move_left()
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
        {
            if(mat[i][j-1]==0 && mat[i][j])
            {
                mat[i][j-1]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mat[i][j] == mat[i][j+1])
            {
                mat[i][j] += mat[i][j+1];
                for(k=j+1;k<3;k++)
                {
                    mat[i][k] = mat[i][k+1];
                }
                mat[i][3]=0;
            }
        }
    }
}

void _main::move_right()
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mat[i][j+1]==0 && mat[i][j])
            {
                mat[i][j+1] = mat[i][j];
                mat[i][j] = 0;
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
        {
            if(mat[i][j]==mat[i][j-1])
            {
                mat[i][j]*=2;
                for(k=j-1;k>0;k--)
                {
                    mat[i][k] = mat[i][k-1];
                }
                mat[i][0] = 0;
            }
        }
    }
}

void _main::display()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j])
                btn[i][j].setText(QString::number(mat[i][j]));
            else
                btn[i][j].setText(" ");
        }
    }
}
