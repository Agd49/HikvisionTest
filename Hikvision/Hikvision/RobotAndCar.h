#include<iostream>
#include<vector>
using namespace std;
typedef class Proxy {
public:
	int x;
	int y;
	string toString();
}Proxy;
typedef class Car {
public:
	/*是否想要进入车库(泊车)*/
	bool isEnter;
	/*车辆编号*/
	int number;
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
}Car;
typedef class Task {
public:
	bool isIn;
	Car car;
}Task;
typedef class Robot {
public:
	/*机器人是否已经被占用*/
	bool isUsed;
	/*机器人最近可以利用的时间*/
	int lastUsefulTime;
	/*机器人任务队列*/
	vector<Task> taskVector;
	/*机器人目前所在位置*/
	Proxy currentProxy;
}Robot;
