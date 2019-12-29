#include "mainwindow.h"
#include "fenetre.hh"


#include "QThread"
#include "QTimer"


fenetre::fenetre(QWidget *parent) : QMainWindow(parent), S(new systeme), ui(new Ui::MainWindow){
    ui->setupUi(this);

    MAJDisplayInfo();

    //~ QTimer::singleShot(0, this, SLOT(AfterUI()));


  QObject::connect(ui->buttonStop, SIGNAL(clicked()), qApp, SLOT(quit())); // On quitte quand on appuie sur QUITTER SANS SAUVEGARDER

  // bouton qui change l'etat d'une vanne
  QObject::connect(ui->buttonVT12, SIGNAL(clicked()), this, SLOT (changeStateVT12()));
  QObject::connect(ui->buttonVT23, SIGNAL(clicked()), this, SLOT (changeStateVT23()));
  QObject::connect(ui->buttonV12, SIGNAL(clicked()), this, SLOT (changeStateV12()));
  QObject::connect(ui->buttonV13, SIGNAL(clicked()), this, SLOT (changeStateV13()));
  QObject::connect(ui->buttonV23, SIGNAL(clicked()), this, SLOT (changeStateV23()));

	// bouton qui change l'etat d'une pompe
	QObject::connect(ui->buttonP11, SIGNAL(clicked()), this, SLOT (changeStateP11()));
	QObject::connect(ui->buttonP12, SIGNAL(clicked()), this, SLOT (changeStateP12()));
	QObject::connect(ui->buttonP21, SIGNAL(clicked()), this, SLOT (changeStateP21()));
	QObject::connect(ui->buttonP22, SIGNAL(clicked()), this, SLOT (changeStateP22()));
	QObject::connect(ui->buttonP31, SIGNAL(clicked()), this, SLOT (changeStateP31()));
	QObject::connect(ui->buttonP32, SIGNAL(clicked()), this, SLOT (changeStateP32()));

	// bouton qui declenche une panne dans les pompes
	QObject::connect(ui->buttonPanneP11, SIGNAL(clicked()), this, SLOT (createPanneP11()));
	QObject::connect(ui->buttonPanneP12, SIGNAL(clicked()), this, SLOT (createPanneP12()));
	QObject::connect(ui->buttonPanneP21, SIGNAL(clicked()), this, SLOT (createPanneP21()));
	QObject::connect(ui->buttonPanneP22, SIGNAL(clicked()), this, SLOT (createPanneP22()));
	QObject::connect(ui->buttonPanneP31, SIGNAL(clicked()), this, SLOT (createPanneP31()));
	QObject::connect(ui->buttonPanneP32, SIGNAL(clicked()), this, SLOT (createPanneP32()));

	// bouton qui declenche une vidange des reservoir
	QObject::connect(ui->buttonPanneT1, SIGNAL(clicked()), this, SLOT (createPanneT1()));
	QObject::connect(ui->buttonPanneT2, SIGNAL(clicked()), this, SLOT (createPanneT2()));
	QObject::connect(ui->buttonPanneT3, SIGNAL(clicked()), this, SLOT (createPanneT3()));
}

QString fenetre::motStatePompe(string nomPompe){
  bool res = S->getStatePompe(nomPompe);
  bool fail = S->getFailureStatePompe(nomPompe);

  if (res){
    return "<b>Marche</b>";
  }
  else {
    if (fail){
      return "<font color=\"red\">HS </font>";
    }
    else{
      return "<i>Eteinte</i>";
    }
  }
}

QString fenetre::motStateVanne(string nom){
  bool res = S->getStateVanne(nom);

  if (res){
    return "<b>Ouverte</b>";
  }
  else {
      return "<i>Fermée</i>";
  }
}

QString fenetre::motStateEngine(string nom){
  bool res = S->getStateEngine(nom);

  if (res){
    return "<b>Marche</b>";

  }
  else {
      return "<font color=\"red\"><b>Eteint</b></font>";
  }
}

QString fenetre::motStateTank(string nom){
  bool res = S->getStateTank(nom);

  if (res){
    return "<b>Remplit</b>";
  }
  else {
      return "Vide";
  }
}

void fenetre::MAJDisplayInfo(){
  QString finale = "";

  // Pompes
  finale = "<html> <body>";

  finale = finale + "P11 : ";
  finale = finale + motStatePompe("P11");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "P12 : ";
  finale = finale + motStatePompe("P12");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "P21 : ";
  finale = finale + motStatePompe("P21");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "P22 : ";
  finale = finale + motStatePompe("P22");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "P31  : ";
  finale = finale + motStatePompe("P31");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "P32  : ";
  finale = finale + motStatePompe("P32");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "<br>";
  finale = finale + "<br>";


  finale = finale + "VT12 : ";
  finale = finale + motStateVanne("V120");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "VT23 : ";
  finale = finale + motStateVanne("V230");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "V12 : ";
  finale = finale + motStateVanne("V12");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "V13 : ";
  finale = finale + motStateVanne("V13");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "V23 : ";
  finale = finale + motStateVanne("V23");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "<br>";
  finale = finale + "<br>";

  finale = finale + "T1 : ";
  finale = finale + motStateTank("T1");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "T2 : ";
  finale = finale + motStateTank("T2");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "T3 : ";
  finale = finale + motStateTank("T3");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "<br>";
  finale = finale + "<br>";

  finale = finale + "E1 : ";
  finale = finale + motStateEngine("E1");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "E2 : ";
  finale = finale + motStateEngine("E2");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "E3 : ";
  finale = finale + motStateEngine("E3");
  finale = finale + "&nbsp;&nbsp;&nbsp;&nbsp;";
  finale = finale + "<br>";
  finale = finale + "<br>";

  finale = finale + "</body> </html> ";


  std::string res = finale.toUtf8().constData();
  cout << res << endl;
  ui->InfoDisplayer->clear();
  ui->InfoDisplayer->setHtml(finale);
}

void fenetre::foo(){
	std::cout << "coucou" << endl;
}
// change state vanne
void fenetre::changeStateVT12(){
    S->changeStateVanne("V120");
    std::cout << "V120" << endl;
    std::cout << S->getStateVanne("V120") << endl;
    MAJDisplayInfo();
}

void fenetre::changeStateVT23(){
    S->changeStateVanne("V230");
    std::cout << "V230" << endl;
    std::cout << S->getStateVanne("V230") << endl;
    MAJDisplayInfo();
}

void fenetre::changeStateV12(){
    S->changeStateVanne("V12");
    std::cout << "V12" << endl;
    std::cout << S->getStateVanne("V12") << endl;
    MAJDisplayInfo();
}

void fenetre::changeStateV13(){
    MAJDisplayInfo();
    S->changeStateVanne("V13");
    std::cout << "V13" << endl;
    std::cout << S->getStateVanne("V13") << endl;
    MAJDisplayInfo();
}

void fenetre::changeStateV23(){
    S->changeStateVanne("V23");
    std::cout << "V23" << endl;
    std::cout << S->getStateVanne("V23") << endl;
    MAJDisplayInfo();
}

// change state pompe

void fenetre::changeStateP11() {
	S->changeStatePompe("P11");
	std::cout << "P11" << endl;
	std::cout << S->getStatePompe("P11") << endl;
  MAJDisplayInfo();
}
void fenetre::changeStateP12() {
	S->changeStatePompe("P12");
	std::cout << "P12" << endl;
	std::cout << S->getStatePompe("P12") << endl;
  MAJDisplayInfo();
}
void fenetre::changeStateP21() {
	S->changeStatePompe("P21");
	std::cout << "P21" << endl;
	std::cout << S->getStatePompe("P21") << endl;
  MAJDisplayInfo();

}
void fenetre::changeStateP22() {
	S->changeStatePompe("P22");
	std::cout << "P22" << endl;
	std::cout << S->getStatePompe("P22") << endl;
  MAJDisplayInfo();
}
void fenetre::changeStateP31() {
  S->changeStatePompe("P31");
	std::cout << "P31" << endl;
	std::cout << S->getStatePompe("P31") << endl;
  MAJDisplayInfo();
}
void fenetre::changeStateP32() {
	S->changeStatePompe("P32");
	std::cout << "P32" << endl;
	std::cout << S->getStatePompe("P32") << endl;
  MAJDisplayInfo();
}


// create panne pompe

void fenetre::createPanneP11() {
	S->breakPompe("P11");
	std::cout << "P11" << endl;
	std::cout << S->getStatePompe("P11") << endl;
  MAJDisplayInfo();
}

void fenetre::createPanneP12() {
	S->breakPompe("P12");
	std::cout << "P12" << endl;
	std::cout << S->getStatePompe("P12") << endl;
  MAJDisplayInfo();
}
void fenetre::createPanneP21() {
  S->breakPompe("P21");
	std::cout << "P21" << endl;
	std::cout << S->getStatePompe("P21") << endl;
  MAJDisplayInfo();
}

void fenetre::createPanneP22() {
	S->breakPompe("P22");
	std::cout << "P22" << endl;
	std::cout << S->getStatePompe("P22") << endl;
  MAJDisplayInfo();
}
void fenetre::createPanneP31() {
	S->breakPompe("P31");
	std::cout << "P31" << endl;
	std::cout << S->getStatePompe("P31") << endl;
  MAJDisplayInfo();
}

void fenetre::createPanneP32() {
	S->breakPompe("P32");
	std::cout << "P32" << endl;
	std::cout << S->getStatePompe("P32") << endl;
  MAJDisplayInfo();
}

// create panne tank

void fenetre::createPanneT1() {
	S->emptyTank("T1");
	std::cout << "T1" << endl;
	std::cout << S->getStateTank("T1") << endl;
  MAJDisplayInfo();
}
void fenetre::createPanneT2() {
	S->emptyTank("T2");
	std::cout << "T2" << endl;
	std::cout << S->getStateTank("T2") << endl;
  MAJDisplayInfo();
}
void fenetre::createPanneT3() {
	S->emptyTank("T3");
	std::cout << "T3" << endl;
	std::cout << S->getStateTank("T3") << endl;
  MAJDisplayInfo();
}

fenetre::~fenetre()
{
    delete ui;
}
