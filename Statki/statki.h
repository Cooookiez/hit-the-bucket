#ifndef STATKI_H
#define STATKI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Statki; }
QT_END_NAMESPACE

class Statki : public QMainWindow{

    Q_OBJECT

public:
    Statki(QWidget *parent = nullptr);
    ~Statki();

private slots:
    void on_btn_ready_clicked();

private:
    Ui::Statki *ui;

};

#endif // STATKI_H
