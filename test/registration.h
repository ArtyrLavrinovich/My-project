#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QFrame>

namespace Ui {
class Registration;
}

class Registration : public QFrame
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
