#include "tank.hh"
#include "engine.hh"
#include "vanne.hh"

using namespace std;

int test(){
	engine *e0 =  new engine();
	engine *e1 = new engine(1);
	engine *e2 = new engine(2, 0);
	
	cout << e0->getName() << endl;
	cout << e1->getName() << endl;
	cout << e2->getName() << endl;
	
	pompe *p0 = new pompe();
	pompe *p1 = new pompe(1);
	pompe *p2 = new pompe(2, 0);
	pompe *p3 = new pompe(3, 0, 'S');
	
	cout << p0->getName() << endl;
	cout << p1->getName() << endl;
	cout << p2->getName() << endl;
	cout << p3->getName() << endl;
	
	tank *t0 = new tank();
	tank *t1 = new tank(1);
	tank *t2 = new tank(2, 0);
	tank *t3 = new tank(3, 0, *p1, *p3);
	
	cout << t0->getName() << endl;
	cout << t1->getName() << endl;
	cout << t2->getName() << endl;
	cout << t3->getName() << endl;
	
	cout << "pas de bug" << endl;
	return 1;
}

int main() {
	test();
	return 0;
}
