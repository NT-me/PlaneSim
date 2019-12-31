#include "dialognote.h"
#include "ui_dialognote.h"

DialogNote::DialogNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNote)
{
    ui->setupUi(this);
}

DialogNote::~DialogNote()
{
    delete ui;
}
