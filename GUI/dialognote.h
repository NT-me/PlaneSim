#ifndef DIALOGNOTE_H
#define DIALOGNOTE_H

#include <QDialog>
#include "fenetre.hh"
#include <cstring>


namespace Ui {
class DialogNote;
}

class DialogNote : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNote(QWidget *parent = nullptr);
    ~DialogNote();
    void setSave(sauvegarde* sauv);

private:
    Ui::DialogNote *ui;
    systeme *S;

public slots:
  void mettreNote();
};

#endif // DIALOGNOTE_H
