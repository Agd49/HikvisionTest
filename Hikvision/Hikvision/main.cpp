#include<iostream>
#include<fstream>
#include "model.h"
/*���ļ��ж�*/
int readCaseInfo(char *szPath);
/*��ӡȨֵ*/
void printWeight();
/*���ĵ�����Ȩֵ*/
static int energyWeight = 0;//k
/*��ʱȨֵ*/
static int overtimeWeight = 0;//p
/*������Ȩֵ*/
static int robotWeight = 0;//a
/*�ȴ�ʱ��Ȩֵ*/
static int waitWeight = 0;//b
/*�洢��ͼ*/
static GarageMap garageMap;
static CarGroup carGroup;
using namespace std;
int main() {
	/*�߹�����·������*/
	int pathLength;//��ʻ��̣�S��
	/*����������*/
	int carWeight;//����������m��
	/*�س�ʱ�ܺģ�W��*/
	int carConsume;//W = k * m * s;
	/*����ͣ����������*/
	int overTimeCarNumber;//q
	/*��ʱ����*/
	int overTimeConsume;//�ܷ�ʱ��T2��=��ʱϵ����p��*����ͣ����������q��
	/*����������*/
	int robotNumber;//n
	/*�ȴ�ʱ��*/
	int waitTime;//T1 = ��T-in����-��T-in��+��T-out����-(T-out)
	/*�����*/
	/*result = robotNumber * robotWeight
	+ waitWeight * waitTime
	+ overtimeWeight * overTimeCarNumber
	+ energyWeight * pathLength * carWeight */
	int result;//Z = n*a + b*��T1 + p*q + k*��m*s;
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
	// ��ȡ������Ϣ
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