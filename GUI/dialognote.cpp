#include "dialognote.h"
#include "ui_dialognote.h"

DialogNote::DialogNote(QWidget *parent) :QDialog(parent), ui(new Ui::DialogNote), S(new systeme)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonMettreNote , SIGNAL(clicked()), this, SLOT(mettreNote())); // On quitte quand on appuie sur QUITTER SANS SAUVEGARDER

}

DialogNote::~DialogNote()
{
    delete ui;
}

int string_to_int(string enter){
  if (!enter.compare("1")){
    return 1;
  }
  else if (!enter.compare("2")){
      return 2;
    }
  else if (!enter.compare("3")){
      return 3;
    }
  else if (!enter.compare("4")){
      return 4;
    }
  else if (!enter.compare("5")){
      return 5;
    }
  else if (!enter.compare("6")){
      return 6;
    }
  else if (!enter.compare("7")){
      return 7;
    }
  else if (!enter.compare("8")){
      return 8;
    }
  else if (!enter.compare("9")){
      return 9;
    }
  else if (!enter.compare("10")){
      return 10;
    }
  else if (!enter.compare("0")){
      return 0;
    }
  else{
    return -1;
  }
}

void DialogNote::mettreNote(){
  string ni = ui->noteInput->text().toStdString();
  int res = string_to_int(ni);
  if (res != -1){
    this->done(res);
  }
  else{
    ui->noteInput->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); selection-background-color: rgb(233, 99, 0); }");
  }
}

void DialogNote::setSave(sauvegarde* s){
  ui->displayHistorique->append(QString::fromStdString(s->getHistorique()));
}
