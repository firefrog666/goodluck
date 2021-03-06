#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>



#include <boost/shared_ptr.hpp>

class Channel;
class Op;
using namespace std;

enum operationType {
	mix,
	heat,
	detect,
	filter,
	//source,
	last
};



class Device{
public:
	Device(int a, int b, int c, int d){
		x = a;
		y = b;
		s = c;
		t = d;
		startTime = 0;
		endTime	= 0;
		availeble = true;
	}

	Device(){
		x = 0;
		y = 0;
		s = 0;
		t = 0;
		startTime = 0;
		endTime	= 0;
		portXOffset = -1;
		portYOffset = -1;
		availeble = true;
	}
private:
	int x,y,s,t;

public:
	operationType type;
	bool injectingSth;
	bool ejectingSth;
	boost::shared_ptr<Op> runningOp;
	boost::shared_ptr<Channel> injectingChannel;
	boost::shared_ptr<Channel> ejectingChannel;
	bool injecting;
	bool ejecting;
	bool isRunning;
	bool availeble;
	string name;
	int id;
	int injectTime;
	int startTime;
	int endTime;
	int ejectTime;
	int sizeX,sizeY;
	int portXOffset;
	int portYOffset;

public:
	inline bool operator== (const Device& rhs) const{
				if(		this->name == rhs.name &&
						this->id == rhs.id &&
						this->sizeX == rhs.sizeX &&
						this->sizeY == rhs.sizeY &&
						this->startTime == rhs.startTime &&
						this->endTime == rhs.endTime &&
						this->type == rhs.type
						)
					return true;
				else
					return false;

			}


};

typedef boost::shared_ptr<Device> Dev_ptr;
//Operation in a sequence graph
class Op {
	typedef boost::shared_ptr<Op> Op_ptr;
public:
	Op(){
		startTime = 0;
		endTime = 0;
		done = false;
	}

	//compare each operation by startTime
		inline bool operator< ( const Op& rhs) const{
			if(this->startTime < rhs.startTime)
				return true;
			else
				return false;
		}
		inline bool operator> (const Op& rhs) const{ return rhs < *this; }
		inline bool operator<=(const Op& rhs) const{ return !(*this > rhs); }
		inline bool operator>=(const Op& rhs) const{ return !(*this < rhs); }
		inline bool operator== (const Op& rhs) const{
			if(		this->name == rhs.name &&
					this->bindDevice == rhs.bindDevice &&
					this->parents == rhs.parents &&
					this->children == rhs.children &&
					this->startTime == rhs.startTime &&
					this->endTime == rhs.endTime &&
					this->type == rhs.type
					)
				return true;
			else
				return false;

		}
public:
    bool done; //if all
    bool running;//if an operation is running

	operationType type;
	string name;
	Dev_ptr bindDevice;
	vector<Op_ptr> parents;
	vector<Op_ptr> children;
	int duration;
	int injecTime; //when to first inject liquid
	int ejectTime; // when to eject Time
	int startTime;
	int endTime;
	int parentSize;
	int childSize;
};

#endif
