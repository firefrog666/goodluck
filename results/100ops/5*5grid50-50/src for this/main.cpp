//============================================================================
// Name        : goodLuck.cpp
// Author      : cheffer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "../header/ListAlgorithm.h"
#include "../header/Int4.h"
#include "../header/Node.h"
#include "../header/grid.h"
#include "..//header/plate.h"
#include "../header/edge.h"
#include "../header/ListAlgorithm.h"
#include "../header/randomSeq.h"
#include "../header/physicalDesign.h"
#include <iostream>

#include "../header/ILP.h"
#include "../header/Node.h"
//#include "../header/writeILP.h"
//#include "../header/sequenceGraph.h"
#include "../rapidxml-1.13/rapidxml.hpp"
#include <vector>
#include <fstream>

using namespace std;

typedef boost::shared_ptr<Node> Node_ptr;
typedef boost::shared_ptr<Edge> Edge_ptr;

int main(int   argc,
	     char *argv[]) {

#if 0
	setGap(0.1);
	setTime(120.0);
	map<string,int> results = ILP("temp.lp" );
#endif


/*
	if (argc < 2) {
			cout << "Usage: lp_c++ filename" << endl;
			return 1;
		}*/

#define physicalDesgin 0

#if physicalDesgin
	Grid inputGrid(2,2);
	/*for(Edge_ptr e:inputGrid.edges){
		e->isStorage = false;
	}*/
	inputGrid.edges[2]->isStorage = false;
	//inputGrid.edges[5]->isStorage =false;
	inputGrid.nodes[0]->isDev = true;
	//inputGrid.nodes[4]->isDev = true;
	//inputGrid.nodes[7]->isDev = true;

	PhysicalDesign p;

	p.inputGrid = inputGrid;
	p.fromGridToSqaures();
	p.genILP();

	return 0;
#endif

#if 0

	Grid inputGrid(2,2);
	//inputGrid.edges[2]->isStorage = false;
	//inputGrid.edges[5]->isStorage =false;

	PhysicalDesign p;

	p.inputGrid = inputGrid;
	p.fromGridToSqaures();
	p.genILP();

	return 0;
#endif

#if 1

	ListAlgorithm L;
#if 0
	//L.readFromXml("simpleStore.xml");
	//L.readFromXml("simple.xml");
	L.readFromXml("cpa20opsnosource.xml");
	//L.readFromXml("pcr.xml");
	//L.readFromXml("ivd.xml");
	//L.readFromXml("random30ops.xml");
	//L.readFromXml("150ops.xml");
	//L.readFromXml("70ops.xml");
#else
	RandomSeq seq;
	//vector<int> v {10,5,15,5,15,10,15,5,15,10,15,10}; //100 ops
	vector<int> v {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}; //narrow 100 ops
	//seq.genDevs(5);
	//vector<int> v {3,6,6};
	seq.genSeqByLayer(v);
	seq.genDevs(5);
	seq.drawOps();

	L.devices = seq.devices;
	L.ops = seq.ops;
#endif
	L.genILP();
	//return 0;
	//L.listAlgorithm();
	//L.writeTimeline();
	cout << "emmm" << endl;
	//return 0;
	setGap(0.1);
	setTime(600.0);
	map<string,int> results;

#if 1
	L.readResultFromFile();
	L.writeTimeline();
#else
	results = ILP("seq.lp" );
	L.writeResultToFile(results);
	L.readFromSolver(results);
	//return 0;
#endif
	//return 0;

	Plate plate = Plate();

	Grid g(5,5);
	plate.setGrid(g);
#define notarchitecutal 0
#if notarchitecutal
	//gen flow plan
	int step = 30;


	plate.getPartInfoFromList(L,step);
	plate.setChannelsTime();
	plate.devicePlacement();

	plate.channelStartEnd();
	plate.channelSimplePath();
	plate.channelFirstStoreLast();
	plate.channelTimeConfict();
	plate.objective();
	setGap(0.1);
	setTime(1200);
	plate.writeToFile("ilp.lp");
	results = ILP("ilp.lp");
	plate.writeDeviceLoc(results);
	plate.readFromSolver(results);
	plate.writeGraphFile();
	return 0;
	//simulation anealing
#else

	srand (time(NULL));
	vector<int> howManyEdges;
	int step = 20;
	/*for(int i = 0; i <= 10 ; i++){
		if( i > 0)
			step = 35;
			plate.constraintClear();
			plate.getPartInfoFromList(L,step);
			//plate.
			plate.setChannelsTime();
			plate.devicePlacement();

			plate.channelStartEnd();
			plate.channelSimplePath();
			plate.channelFirstStoreLast();
			plate.channelTimeConfict();
			plate.objective();
			plate.readDeviceLoc();
			if(i%2 == 0)
				plate.moveDeviceLoc();
			else
				plate.switchDeviceLoc();

			//plate.writeDevLocToILP();
			plate.writeToFile("arc.lp");
			setGap(0.1);
			if(i == 0)
			setTime(900);
			else
				setTime(1800);
			results = ILP("arc.lp");
			if(results.size()>0){
				plate.writeDeviceLoc(results);
				plate.readFromSolver(results);
				plate.writeGraphFile();
				int edgeUseNum = plate.calEdgeUseNum();
				howManyEdges.push_back(edgeUseNum);
			}
			else{
				plate.clearLastResult();
			}

		}*/
#endif

	step = 20;
	/*plate.constraintClear();
	plate.getPartInfoFromList(L,step);
				//plate.
	plate.setChannelsTime();
	plate.devicePlacement();

	plate.channelStartEnd();
	plate.channelSimplePath();
	plate.channelFirstStoreLast();
	plate.channelTimeConfict();
	plate.objective();
	plate.readDeviceLoc();
	plate.writeToFile("arc.lp");
		setGap(0.1);

		setTime(1800);
		results = ILP("arc.lp");
		if(results.size()>0){
			plate.writeDeviceLoc(results);
			plate.readFromSolver(results);
			plate.writeGraphFile();
			int edgeUseNum = plate.calEdgeUseNum();
			howManyEdges.push_back(edgeUseNum);
		}
		else{
			plate.clearLastResult();
		}*/
		step = 50;
	for(int i = 0; i <= 10; i++){
		if(i > 0)
			step = 50;
		plate.constraintClear();
		plate.getPartInfoFromList(L,step);
		//plate.genRandomDevLoc();
		plate.setChannelsTime();
		plate.devicePlacement();

		plate.channelStartEnd();
		plate.channelSimplePath();
		plate.channelFirstStoreLast();
		plate.channelTimeConfict();
		plate.objective();
		plate.readDeviceLoc();
		if(i%2 == 0)
			plate.moveDeviceLoc();
		else
			plate.switchDeviceLoc();

		plate.writeDevLocToILP();
		plate.writeToFile("sa.lp");
		setGap(0.1);
		if(i == 0)
		setTime(1800);
		else
			setTime(3600);
		results = ILP("sa.lp");
		if(results.size()>0){
			plate.writeDeviceLoc(results);
			plate.readFromSolver(results);
			int edgeUseNum = plate.calEdgeUseNum();
			howManyEdges.push_back(edgeUseNum);
		}

	}

	for(int num:howManyEdges){
		cout << "use " << num << " edges" << endl;
	}

	plate.writeGraphFile();



#endif



#if 0
	 //vector<int> v {10,5,15,5,15,10,15,5,15,10,15,10,15,10,10,5,15,5,15,10,15,5,15,10,15,10,15,10}; //100 ops, with parent maxmum 3
	vector<int> v {10,5,15,5,15,10,15,5,15,10,15,10};

	//vector<int> v {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
	//vector<int> v {10,5,15,5,15,10,15,5,15,10,15,10,15,10,10,5,15,5,15,10,15,5,15,10,15}; //200ops with maxParent 2
	//vector<int> v {20,20,30,10,30,20,15,10,30,20,20,20}; //200ops with maxParent 2, fat version

	//vector<int> v {10,5,15,5,15,10,15,5,15,10,15,10,15,10,10,5,15,5,15,10,15,5,15,10,15,
	//				10,5,15,5,15,10,15,5,15,10,15}; //300 ops with maxParent 2

	//vector<int> v {10,5,15,5,15,10,15,5,15,10,15,10,15,10,10,5,15,5,15,10,15,5,15,10,15,
	//					10,5,15,5,15,10,15,5,15,10,15,10,5,15,5,15,10,15,5,15,10,15}; //400 ops with maxParent 2

	//vector<int> v {15,15,45,35,25,30,45,20,45,30,20,30};//200 fat, 2 parent most likely
	//vector<int> v {30,30,50,50,45,30,50,60,45,30,20,30,20,45,30};//400 fat, 2 parent most likely
	//vector<int> v {3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6,3,6}; //200 ops
	//vector<int> v {10,5,15,5,15,10,15,5,15,10,10,5,15,5,15,10,15,5,15,10,10,5,15,5,15,10,15,5,15,10}; // 300 ops
	//vector<int> v {10,5,15,5,15,10,15,5,15,10,10,5,15,5,15,10,15,5,15,10,10,5,15,5,15,10,15,5,15,10,10,5,15,5,15,10,15,5,15,10};//400ops
	RandomSeq seq;
	seq.genSeqByLayer(v);
	seq.genDevs(5);
	seq.drawOps();
	ListAlgorithm L;
	L.devices = seq.devices;
	L.ops = seq.ops;
	L.genILP();
	setGap(0.0);
	setTime(400);
	map<string,int> results = ILP("seq.lp" );
	L.readFromSolver(results);
	Plate plate;
	//plate.setSequenceGraph(seq);
	for(int size = 5;; size++){

		//plate.getBindingFromList(L);
		int step = 20;
		bool finished = false;
		for(int i = 0; i<L.ops.size(); i += step){
			finished = false;
			if(i > 0)
				step = 130;

			plate.constraintClear();
			plate.setChipSize(size);
			plate.getPartInfoFromListByTime(L,step);
			plate.devicePlacementConstraint();
			plate.channelPlaceConstraint();
			plate.channeTimeConstraint();

			plate.ValveObject();
			plate.writeToFile();
			setGap(5.0);
			setTime(7200.0);
			map<string,int> results = ILP("ilp.lp");
			if(results.size() == 0){
				cout << "unfinished" <<endl;
				break;
			}
			plate.readFromSolverDevice(results);
			plate.writeGraphFile(-1);
			finished = true;
		}
		if(finished)
			break;
	}

	return 0 ;


#endif
#define switch 0
#if switch
	//SequenceGraph seq("data3ops_3devs_2concurrentchannel.xml");
	//SequenceGraph seq(argv[1]);
	ListAlgorithm L;
	//L.readFromXml("sequenceGraph16ops6devs.xml");
	//L.readFromXml("sequenceGraph.xml");
	//L.readFromXml("lostsops.xml");
	L.readFromXml("pcr.xml");
	//L.readFromXml("cpa5opswithsource.xml");
	L.listAlgorithm();
	Plate plate;
	//plate.setSequenceGraph(seq);

	//plate.getBindingFromList(L);
	int step =41;
	for(int i = 0; i<L.ops.size(); i += step){
		if(i > 0)
			step = 30;

		plate.constraintClear();

		plate.getPartInfoFromList(L,step);
		plate.devicePlacementConstraint();
		plate.channelPlaceConstraint();
		plate.channeTimeConstraint();

		plate.ValveObject();
		plate.writeToFile();
		map<string,int> results = ILP("ilp.lp");
		plate.readFromSolver(results);
		plate.writeGraphFile(-1);
	}
#endif
#if 0
	//SequenceGraph seq("data3ops_3devs_2concurrentchannel.xml");
		//SequenceGraph seq(argv[1]);
		ListAlgorithm L;
		//L.readFromXml("sequenceGraph16ops6devs.xml");
		L.readFromXml("sequenceGraph.xml");
		//L.readFromXml("lostsops.xml");
		//L.readFromXml("cpa5opsnosource.xml");
		L.listAlgorithm();
		Plate plate;
		//plate.setSequenceGraph(seq);

		//plate.getBindingFromList(L);
		int step = 16;
		for(int i = 0; i<L.ops.size(); i += step){

			plate.constraintClear();

			plate.getPartInfoFromList(L,step);
			plate.devicePlacementConstraint();
			plate.channelPlaceConstraint();
			plate.channeTimeConstraint();

			//plate.ValveObject();
			//plate.writeToFile();
			map<string,int> results = ILP("ilp.lp" );
			plate.readFromSolver(results);
			plate.writeGraphFile(-1);
		}
#endif

#if 0
	Plate plate;
	map<string,int> results = ILP("temp.lp");
	plate.readFromSolver(results);
#endif
	//ILP("temp.lp");


	/*plate p;
	p.placementConstraint();
	string *tmp = &(p.ILP.back());*/
	//cout<< *tmp << endl;

//	ofstream myfile;<fstream>
//	myfile.open ("example.txt");
//	myfile << "Writing this to a file.\n";
//	myfile.close();
//	//Foo f = Foo();
//	Int4 a = Int4(1,2,3,4);

	/*vector<string> varNames;
	vector<string> varTypes;
	varNames.push_back("AA");
	varNames.push_back("BB");
	varTypes.push_back("1");
	varTypes.push_back("0");
	writeILP write;
	write.writeVarNames(varNames,varTypes,"example.txt");*/

	//ILP(argv[1]);
//	Graph g = Graph(3,3);
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << a.hash() << endl;

	return 0;
}

