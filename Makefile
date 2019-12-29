all:
	cd GUI/; make
	cd GUI/;./PlaneSim

class_test_hh:
	g++ class/engine.hh
	g++ class/pompe.hh
	g++ class/tank.hh
	g++ class/vanne.hh
	rm class/*.hh.gch

class_test_cc:
	g++ class/*.cc
	rm a.out

class_test_all:
	g++ class/*.hh
	g++ class/*.cc
	rm class/*.hh.gch
	rm a.out
