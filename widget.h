#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QString>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QLineEdit       *lineEdit;
    QGridLayout     *layout;
    QLabel          *label, *label_2, *label_3, *label_4, *label_5;
    QPushButton     *pushButton, *pushButton_2, *pushButton_3;
    QStack<QChar>   *stack_1, *stack_2;

private slots:
    void push();
    void display_stack_1();
    void display_stack_2();
};

#endif // WIDGET_H
