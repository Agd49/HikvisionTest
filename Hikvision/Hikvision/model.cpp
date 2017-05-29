#include"model.h"
#include"string.h"
#include<stack>
#include<sstream>
using namespace std;
string Proxy::toString()
{
	stringstream ss;
	ss << '(' << x << ',' << y << ')';
	return ss.str();
}
Proxy::Proxy()
{
	x = 0;
	y = 0;
}
Proxy::Proxy(int x, int y)
{
	this->x = x;
	this->y = y;
}
string Car::toPathString(vector<Proxy> path)
{
	string ret = "";
	for (unsigned int i = 0; i < path.size(); i++ )
	{
		ret += path[i].toString();
	}
	/*for (vector<Proxy>::const_iterator it = path.cbegin(); it != path.cend(); it++)
	{
		ret = it->toString();
	}*/
	return ret;
}
string MapProxy::toString()
{
	return Proxy::toString() + "start��ʼ��ǰ�̽ڵ�: " + beforeProxyByStart.toString();
}
void GarageMap::print()
{
	cout << "row = " << row << "    " << "column = " << column << endl;
	for (int i = 0; i < GarageMap::row; i++)
	{
		for (int j = 0; j < GarageMap::column; j++)
		{
			cout << GarageMap::map[i][j];
		}
		cout << endl;
	}
}
vector<Proxy> getPathByPoint(int x, int y, MapProxy** map)
{
	stack<Proxy> stackProxy;
	MapProxy * p;
	p = &map[x][y];
	stackProxy.push(Proxy(x, y));
	while (p->beforeProxyByStart.x != -1 && p->beforeProxyByStart.y != -1)
	{
		stackProxy.push(Proxy(p->beforeProxyByStart.x, p->beforeProxyByStart.y));
		p = &map[p->beforeProxyByStart.x][p->beforeProxyByStart.y];
	}
	vector<Proxy> vec;
	while (!stackProxy.empty())
	{
		vec.push_back(stackProxy.top());
		stackProxy.pop();
	}
	p = &map[x][y];
	while (p->beforeProxyByEnd.x != -1 && p->beforeProxyByEnd.y != -1)
	{
		vec.push_back(Proxy(p->beforeProxyByEnd.x, p->beforeProxyByEnd.y));
		p = &map[p->beforeProxyByEnd.x][p->beforeProxyByEnd.y];
	}
	Car car;
	cout << "Ѱ�ҳ�����·��: " << car.toPathString(vec).c_str() << endl;
	return vec;
}
/*��start����Ѱ��һ���㣬������Proxy.y�Ѿ������Ϊ1��
start��end��������ͣ�������ڵ�·��������ͣ����*/
bool GarageMap::queryPathByStart(Proxy start, MapProxy** map)
{
	map[start.x][start.y].x = 1;
	/*���������Ѿ����յ�����ĵ���ʹ��Ļ�����˵���Ѿ��ҵ���Ŀ�ĵ�*/
	if (map[start.x][start.y].y == 1)
	{
		vector<Proxy> vec = getPathByPoint(start.x, start.y, map);
		return true;
	}
	/*���������û������Ѱ����·�ҵ�����·�Ļ���������Χ��ɢ*/
	if (start.x + 1 < GarageMap::row && GarageMap::map[start.x + 1][start.y] == 'X' && map[start.x + 1][start.y].x != 1)
	{
		map[start.x + 1][start.y].beforeProxyByStart.x = start.x;
		map[start.x + 1][start.y].beforeProxyByStart.y = start.y;
		GarageMap::startQue.push(Proxy(start.x + 1, start.y));
	}
	if (start.x - 1 >= 0 && GarageMap::map[start.x - 1][start.y] == 'X' && map[start.x - 1][start.y].x != 1)
	{
		map[start.x - 1][start.y].beforeProxyByStart.x = start.x;
		map[start.x - 1][start.y].beforeProxyByStart.y = start.y;
		GarageMap::startQue.push(Proxy(start.x - 1, start.y));
	}
	if (start.y + 1 < GarageMap::column && GarageMap::map[start.x][start.y + 1] == 'X' && map[start.x][start.y + 1].x != 1)
	{
		map[start.x][start.y + 1].beforeProxyByStart.x = start.x;
		map[start.x][start.y + 1].beforeProxyByStart.y = start.y;
		GarageMap::startQue.push(Proxy(start.x, start.y + 1));
	}
	if (start.y - 1 >= 0 && GarageMap::map[start.x][start.y - 1] == 'X' && map[start.x][start.y - 1].x != 1)
	{
		map[start.x][start.y - 1].beforeProxyByStart.x = start.x;
		map[start.x][start.y - 1].beforeProxyByStart.y = start.y;
		GarageMap::startQue.push(Proxy(start.x, start.y - 1));
	}
	return false;
}
/*��end����Ѱ��һ���㣬������Proxy.x�Ѿ������Ϊ1��
start��end��������ͣ�������ڵ�·��������ͣ����*/
bool GarageMap::queryPathByEnd(Proxy end, MapProxy** map)
{
	map[end.x][end.y].y = 1;
	/*���������Ѿ�����ʼ������ĵ���ʹ��Ļ�����˵���Ѿ��ҵ���Ŀ�ĵ�*/
	if (map[end.x][end.y].x == 1)
	{
		cout << "middle������end������Ѱ��·�б��ҵ�" << endl;
		vector<Proxy> vec = getPathByPoint(end.x, end.y, map);
		return true;
	}
	/*���������û������Ѱ����·�ҵ�����·�Ļ���������Χ��ɢ*/
	if (end.x + 1 < GarageMap::row && map[end.x+1][end.y].y != 1 && GarageMap::map[end.x+1][end.y] == 'X')
	{
		map[end.x + 1][end.y].beforeProxyByEnd.x = end.x;
		map[end.x + 1][end.y].beforeProxyByEnd.y = end.y;
		GarageMap::endQue.push(Proxy(end.x + 1, end.y));
	}
	if (end.x - 1 >= 0 && map[end.x - 1][end.y].y != 1 && GarageMap::map[end.x - 1][end.y] == 'X')
	{
		map[end.x - 1][end.y].beforeProxyByEnd.x = end.x;
		map[end.x - 1][end.y].beforeProxyByEnd.y = end.y;
		GarageMap::endQue.push(Proxy(end.x - 1, end.y));
	}
	if (end.y + 1 < GarageMap::column && map[end.x][end.y + 1].y != 1 && GarageMap::map[end.x][end.y + 1] == 'X')
	{
		map[end.x][end.y + 1].beforeProxyByEnd.x = end.x;
		map[end.x][end.y + 1].beforeProxyByEnd.y = end.y;
		GarageMap::endQue.push(Proxy(end.x, end.y + 1));
	}
	if (end.y - 1 >= 0 && map[end.x][end.y - 1].y != 1 && GarageMap::map[end.x][end.y - 1] == 'X')
	{
		map[end.x][end.y - 1].beforeProxyByEnd.x = end.x;
		map[end.x][end.y - 1].beforeProxyByEnd.y = end.y;
		GarageMap::endQue.push(Proxy(end.x, end.y - 1));
	}
	return false;
}
bool GarageMap::isMapCorrect()
{
	Proxy P1;
	for (int i = 0; i < GarageMap::row; i++)
	{
		for (int j = 0; j < GarageMap::column; j++)
		{
			if (GarageMap::map[i][j] == 'I')
			{
				GarageMap::start.x = i;
				GarageMap::start.y = j;
			}
			else if (GarageMap::map[i][j] == 'E')
			{
				GarageMap::end.x = i;
				GarageMap::end.y = j;
			}
			else if (GarageMap::map[i][j] == 'P')
			{
				P1.x = i;
				P1.y = j;
			}
		}
	}
		MapProxy ** mapProxyArray = new MapProxy*[GarageMap::row];
		for (int i = 0; i < GarageMap::row; i++)
		{
			mapProxyArray[i] = new MapProxy[GarageMap::column];
		}
		//???
		/*Ҫ��ȷ�����������ֹ��,���ǵ�ֵֻ����X*/
		Proxy isMapCorrectStart = GarageMap::start;
		Proxy isMapCorrectEnd = P1; 
		isMapCorrectEnd.x = 18;
		isMapCorrectEnd.y = 3;
		mapProxyArray[isMapCorrectStart.x][isMapCorrectStart.y].x = 1;
		mapProxyArray[isMapCorrectEnd.x][isMapCorrectEnd.y].y = 1;
		mapProxyArray[isMapCorrectStart.x][isMapCorrectStart.y].beforeProxyByStart.x = -1;
		mapProxyArray[isMapCorrectStart.x][isMapCorrectStart.y].beforeProxyByStart.y = -1;
		mapProxyArray[isMapCorrectEnd.x][isMapCorrectEnd.y].beforeProxyByEnd.x = -1;
		mapProxyArray[isMapCorrectEnd.x][isMapCorrectEnd.y].beforeProxyByEnd.y = -1;
		startQue.push(isMapCorrectStart);
		endQue.push(isMapCorrectEnd);
		while (!startQue.empty() && !endQue.empty())
		{
			if (queryPathByStart(startQue.front(), mapProxyArray))
			{
				break;
			}
			cout << startQue.front().toString().c_str() << endl;
			startQue.pop();
			if (queryPathByEnd(endQue.front(), mapProxyArray))
			{
				break;
			}
			endQue.pop();
		}	
		return false;
}
void CarGroup::print()
{
	cout << "carNum = " << CarGroup::carNum << endl;
	for (int i = 0; i < carNum; i++)
	{
		cout << carList[i].id << " " << carList[i].tin << " " << carList[i].tout
			<< " " << carList[i].longestTime << " " << carList[i].weight << endl;
	}
}