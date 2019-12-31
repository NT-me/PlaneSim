/********************************************************************************
** Form generated from reading UI file 'dialoglog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOG_H
#define UI_DIALOGLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialogLog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *inputNom;
    QPushButton *buttonInputNom;

    void setupUi(QDialog *dialogLog)
    {
        if (dialogLog->objectName().isEmpty())
            dialogLog->setObjectName(QString::fromUtf8("dialogLog"));
        dialogLog->resize(400, 86);
        formLayout = new QFormLayout(dialogLog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(dialogLog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        inputNom = new QLineEdit(dialogLog);
        inputNom->setObjectName(QString::fromUtf8("inputNom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, inputNom);

        buttonInputNom = new QPushButton(dialogLog);
        buttonInputNom->setObjectName(QString::fromUtf8("buttonInputNom"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, buttonInputNom);


        retranslateUi(dialogLog);

        QMetaObject::connectSlotsByName(dialogLog);
    } // setupUi

    void retranslateUi(QDialog *dialogLog)
    {
        dialogLog->setWindowTitle(QApplication::translate("dialogLog", "Dialog", nullptr));
        label->setText(QApplication::translate("dialogLog", "Votre Nom", nullptr));
        buttonInputNom->setText(QApplication::translate("dialogLog", "Valider votre nom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogLog: public Ui_dialogLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOG_H
