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
	/*�Ƿ���Ҫ���복��(����)*/
	bool isEnter;
	/*�������*/
	int number;
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
}Car;
typedef class Task {
public:
	bool isIn;
	Car car;
}Task;
typedef class Robot {
public:
	/*�������Ƿ��Ѿ���ռ��*/
	bool isUsed;
	/*����������������õ�ʱ��*/
	int lastUsefulTime;
	/*�������������*/
	vector<Task> taskVector;
	/*������Ŀǰ����λ��*/
	Proxy currentProxy;
}Robot;
