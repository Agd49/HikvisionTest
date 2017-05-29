#include<iostream>
#include<fstream>
#include "model.h"
/*从文件中读*/
int readCaseInfo(char *szPath);
/*打印权值*/
void printWeight();
/*消耗的能量权值*/
static int energyWeight = 0;//k
/*超时权值*/
static int overtimeWeight = 0;//p
/*机器人权值*/
static int robotWeight = 0;//a
/*等待时间权值*/
static int waitWeight = 0;//b
/*存储地图*/
static GarageMap garageMap;
static CarGroup carGroup;
using namespace std;
int main() {
	/*走过的总路径长度*/
	int pathLength;//行驶里程（S）
	/*车辆总重量*/
	int carWeight;//车的质量（m）
	/*载车时能耗（W）*/
	int carConsume;//W = k * m * s;
	/*放弃停车车辆数量*/
	int overTimeCarNumber;//q
	/*超时消耗*/
	int overTimeConsume;//总罚时（T2）=罚时系数（p）*放弃停车车辆数（q）
	/*机器人数量*/
	int robotNumber;//n
	/*等待时间*/
	int waitTime;//T1 = （T-in＇）-（T-in）+（T-out＇）-(T-out)
	/*最后结果*/
	/*result = robotNumber * robotWeight
	+ waitWeight * waitTime
	+ overtimeWeight * overTimeCarNumber
	+ energyWeight * pathLength * carWeight */
	int result;//Z = n*a + b*∑T1 + p*q + k*∑m*s;
	char * fileName = "2.txt";
	readCaseInfo(fileName);
	/*printWeight();
	garageMap.print();
	carGroup.print();*/
	garageMap.isMapCorrect();
	system("pause");
	return 0;
}
int readCaseInfo(char *szPath)
{
	if (szPath == NULL)
	{
		return 0;
	}
	FILE    *pFile = fopen(szPath, "r");

	if (pFile == NULL)
	{
		return 0;
	}

	fscanf(pFile, "%d %d %d %d",
		&energyWeight,
		&overtimeWeight,
		&robotWeight,
		&waitWeight);
	fscanf(pFile, "%d %d", &garageMap.row, &garageMap.column);
	garageMap.map = new char*[garageMap.row];
	for (int i = 0; i < garageMap.row; i++)
	{
		garageMap.map[i] = new char[garageMap.row];
	}
	for (int i = 0; i < garageMap.row; i++)
	{
		for (int j = 0; j < garageMap.column; j++)
		{
			char szTmp[2] = { 0 };
			fscanf(pFile, "%s", szTmp);
			garageMap.map[i][j] = szTmp[0];
		}
	}
	//garageMap.print();
	// 读取车辆信息
	fscanf(pFile, "%d", &carGroup.carNum);
	carGroup.carList = new Car[carGroup.carNum];
	for (int i = 0; i < carGroup.carNum; i++)
	{
		Car car;
		fscanf(pFile, "%d %d %d %d %d",
			&car.id,
			&car.tin,
			&car.tout,
			&car.longestTime,
			&car.weight);
		carGroup.carList[i] = car;
		//carGroup.print();
	}
	return 1;
}
void printWeight()
{
	cout << "energyWeight = " << energyWeight << "\t" << "overtimeWeight = " << overtimeWeight << "\n"
		<< "robotWeight = " << robotWeight << "\t" << "waitWeight = " << waitWeight << endl;
}