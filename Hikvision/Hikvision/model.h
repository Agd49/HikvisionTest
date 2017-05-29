#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*�����*/
typedef class Proxy {
public:
	int x;
	int y;
	string toString();
	Proxy(int x, int y);
	Proxy();
}Proxy;
/*ר��������ǵ�ͼ������㣬��Proxy��Ļ�����������ǰ�̽ڵ�*/
typedef class MapProxy :public Proxy {
public:
	Proxy beforeProxyByEnd;
	Proxy beforeProxyByStart;
	string toString();
}MapProxy;
/*ͨ��Ѱ�ҹ������м佻��ĵ�õ�·��*/
vector<Proxy> getPathByPoint(int x,int y,MapProxy** map);
/*��Ҫ��ŵ�����*/
typedef class Car {
public:
	/*�Ƿ���Ҫ���복��(����)*/
	bool isEnter;
	/*�������*/
	int id;
	/*�������ʱ��*/
	int tin;
	/*�����뿪ʱ��*/
	int tout;
	/*��ȴ�ʱ��t*/
	int longestTime;
	/*�����ȴ�ʱ��*/
	int relativeLongestTime;
	/*ʵ�ʽ���ʱ��*/
	int realTin;
	/*ʵ���뿪ʱ��*/
	int realTout;
	/*��������*/
	int weight;
	/*��������·��*/
	vector<Proxy> inPath;
	/*��������·��*/
	vector<Proxy> outPath;
	string toPathString(vector<Proxy> path);
}Car;
/*���񣬷�Ϊ����һ����Ҫ��Ž����⣬һ����Ҫ����*/
typedef class Task {
public:
	bool isIn;//�ж�����⻹�ǳ���
	Car car;//�����߳���ĳ���
}Task;
typedef class Robot {
public:
	/*�������Ƿ��Ѿ���ռ��*/
	bool isUsed;
	/*����������������õ�ʱ��*/
	int lastUsefulTime;
	/*�������������*/
	queue<Task> taskVector;
	/*������Ŀǰ����λ��*/
	Proxy currentProxy;
}Robot;
/*��ͼ*/
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
/*���еĳ�����*/
typedef class CarGroup {
public:
	int carNum;
	Car * carList;
	void print();
}CarGroup;
