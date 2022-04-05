#pragma once
#include "PopObject.h";
#define MAX_OBJECTS 10 // ����������� ���������� �������� ������� �������������� � ��������� 
// ���������, ������� ������ � ����������� ������ ���������� �������� 




class Manager
{
private:
	PopObject *popObjects_[MAX_OBJECTS];
	int frameWidth_, frameHeight_;
	int x_, y_;
	int size_;

public:
	Manager(int frameWidth, int frameHeight);
	~Manager();
	void add(PopObject* popObject);
	void drawFrame(Graphics^ graphics);
	void move();
	bool remove(PopObject* popObject);
	PopObject* search(int x, int y);
	bool objCollision(PopObject* firstBall, PopObject* secondBall);
};


extern Manager* manager;


/* ������������ ������� ! - ������� ������� ������� ����� ���������� bool ��������
���� ������ ����������� �� ��������� ����� ������� ��������� �� ������� ����
*/