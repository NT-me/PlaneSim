#ifndef DIALOGNOTE_H
#define DIALOGNOTE_H

#include <QDialog>
#include "fenetre.hh"


namespace Ui {
class DialogNote;
}

class DialogNote : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNote(QWidget *parent = nullptr);
    ~DialogNote();

private:
    Ui::DialogNote *ui;
    systeme *S;

public slots:
};

#endif // DIALOGNOTE_H
