#include "dialoglog.h"
#include "ui_dialoglog.h"


using namespace std;

dialogLog::dialogLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogLog)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonInputNom , SIGNAL(clicked()), this, SLOT(getNom()));
    QObject::connect(ui->buttonInputNom , SIGNAL(clicked()), this, SLOT(quit()));

}

string dialogLog::getNom(){
  string ni = ui->inputNom->text().toStdString();
  return ni;
}

void dialogLog::quit(){
  if (ui->inputNom->text().toStdString() != ""){
    this->done(0);
  }
  else{
    ui->inputNom->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); selection-background-color: rgb(233, 99, 0); }");
  }
}

dialogLog::~dialogLog()
{
    delete ui;
}
