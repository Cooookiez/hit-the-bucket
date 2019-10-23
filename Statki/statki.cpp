#include "statki.h"
#include "./ui_statki.h"
#include <cstdlib>
#include <iostream>

Statki::Statki(QWidget *parent): QMainWindow(parent), ui(new Ui::Statki){

    ui->setupUi(this);

}

Statki::~Statki(){

    delete ui;

}


void Statki::on_btn_ready_clicked(){

    std::cout << "btn ready pressed" << std::endl;

}
