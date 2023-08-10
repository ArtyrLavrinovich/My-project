#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QWidget>

namespace Ui {
class Autorization;
}

class Autorization : public QWidget
{
    Q_OBJECT

public:
    explicit Autorization(QWidget *parent = nullptr);
    ~Autorization();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Autorization *ui;
};

#endif // AUTORIZATION_H
