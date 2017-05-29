#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*坐标点*/
typedef class Proxy {
public:
	int x;
	int y;
	string toString();
	Proxy(int x, int y);
	Proxy();
}Proxy;
/*专门用来标记地图的坐标点，在Proxy类的基础上增加了前继节点*/
typedef class MapProxy :public Proxy {
public:
	Proxy beforeProxyByEnd;
	Proxy beforeProxyByStart;
	string toString();
}MapProxy;
/*通过寻找过程中中间交汇的点得到路径*/
vector<Proxy> getPathByPoint(int x,int y,MapProxy** map);
/*需要存放的汽车*/
typedef class Car {
public:
	/*是否想要进入车库(泊车)*/
	bool isEnter;
	/*车辆编号*/
	int id;
	/*申请进入时间*/
	int tin;
	/*申请离开时间*/
	int tout;
	/*最长等待时间t*/
	int longestTime;
	/*相对最长等待时间*/
	int relativeLongestTime;
	/*实际进入时间*/
	int realTin;
	/*实际离开时间*/
	int realTout;
	/*汽车重量*/
	int weight;
	/*汽车进入路径*/
	vector<Proxy> inPath;
	/*汽车出库路径*/
	vector<Proxy> outPath;
	string toPathString(vector<Proxy> path);
}Car;
/*任务，分为两种一种是要存放进车库，一种是要出库*/
typedef class Task {
public:
	bool isIn;//判断是入库还是出库
	Car car;//入库或者出库的车辆
}Task;
typedef class Robot {
public:
	/*机器人是否已经被占用*/
	bool isUsed;
	/*机器人最近可以利用的时间*/
	int lastUsefulTime;
	/*机器人任务队列*/
	queue<Task> taskVector;
	/*机器人目前所在位置*/
	Proxy currentProxy;
}Robot;
/*地图*/
typedef class GarageMap {
private:
	queue<Proxy> startQue;
	queue<Proxy> endQue;
public:	
	int row;
	int column;
	Proxy start;
	Proxy end;
	char** map;
	void print();
	bool isMapCorrect();
	bool queryPathByStart(Proxy start, MapProxy ** map);
	bool queryPathByEnd(Proxy end, MapProxy ** map);
}GarageMap;
/*所有的车辆组*/
typedef class CarGroup {
public:
	int carNum;
	Car * carList;
	void print();
}CarGroup;
