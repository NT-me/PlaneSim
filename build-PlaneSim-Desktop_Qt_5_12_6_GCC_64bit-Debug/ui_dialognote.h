/********************************************************************************
** Form generated from reading UI file 'dialognote.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNOTE_H
#define UI_DIALOGNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogNote
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *displayHistorique;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *noteInput;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogNote)
    {
        if (DialogNote->objectName().isEmpty())
            DialogNote->setObjectName(QString::fromUtf8("DialogNote"));
        DialogNote->resize(400, 300);
        verticalLayoutWidget = new QWidget(DialogNote);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 382, 282));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        displayHistorique = new QTextBrowser(verticalLayoutWidget);
        displayHistorique->setObjectName(QString::fromUtf8("displayHistorique"));

        verticalLayout->addWidget(displayHistorique);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        noteInput = new QLineEdit(verticalLayoutWidget);
        noteInput->setObjectName(QString::fromUtf8("noteInput"));

        verticalLayout->addWidget(noteInput);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogNote);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogNote, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogNote, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogNote);
    } // setupUi

    void retranslateUi(QDialog *DialogNote)
    {
        DialogNote->setWindowTitle(QApplication::translate("DialogNote", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogNote", "Historique :", nullptr));
        label_2->setText(QApplication::translate("DialogNote", "Note (/10):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNote: public Ui_DialogNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNOTE_H
