#ifndef DIALOGLOG_H
#define DIALOGLOG_H

#include <QDialog>
#include <iostream>
#include <cstring>

namespace Ui {
class dialogLog;
}

class dialogLog : public QDialog
{
    Q_OBJECT

public:
    dialogLog(QWidget *parent = nullptr);
    ~dialogLog();

private:
    Ui::dialogLog *ui;

public slots:
  std::string getNom();
  void quit();
};

#endif // DIALOGLOG_H
