#include "widget.h"
#include "ui_widget.h"
#include <iostream>
using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    label = new QLabel("Введите символ");
    label_2 = new QLabel("Стек 1:");
    label_3 = new QLabel();
    label_4 = new QLabel("Стек 2:");
    label_5 = new QLabel();
    stack_1 = new QStack<QChar>;
    stack_2 = new QStack<QChar>;
    lineEdit = new QLineEdit();
    pushButton = new QPushButton("Добавить символ в стек");
    connect(pushButton, SIGNAL(clicked()), this, SLOT(push()));


    pushButton_2 = new QPushButton("Показать Стек 1");
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(display_stack_1()));

    pushButton_3 = new QPushButton("Показать Стек 2");
    connect(pushButton_3, SIGNAL(clicked()), this, SLOT(display_stack_2()));

    layout = new QGridLayout;
    layout->addWidget(label, 0,0);
    layout->addWidget(lineEdit,0,1);
    layout->addWidget(pushButton,0,2);
    layout->addWidget(label_2, 1,0);
    layout->addWidget(label_3, 1,1);
    layout->addWidget(pushButton_2,1,2);
    layout->addWidget(label_4, 2,0);
    layout->addWidget(label_5, 2,1);
    layout->addWidget(pushButton_3,2,2);
    this->setLayout(layout);
}

void Widget::push()
{
    QChar *qs = lineEdit->text().data();

    stack_1->push(*qs);
    lineEdit->setText("");
}



void Widget::display_stack_1()
{
    QString m = "";
    while (!stack_1->empty())
    {
        QString str = QString(stack_1->pop());
        QChar *qa = str.data();
        m = m + str;
        if (*qa >= 'A' && *qa <= 'Z' )
        {
            stack_2->push(*qa);
        }
    }
        label_3->setText(m);
}



void Widget::display_stack_2()
{
    QString m;
    while (!stack_2->empty())
    {
        QString str = QString(stack_2->pop());
        m = m + str;
    }
       label_5->setText(m);
}

Widget::~Widget()
{
    delete ui;
}
