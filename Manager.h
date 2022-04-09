#pragma once
#include "PopObject.h";
#define MAX_OBJECTS 100 // максимально количество обьектов которые декларированны в дерективе 
// контейнер, который хранит и обслуживает массив движущихся объектов 




class Manager
{
private:
	PopObject *popObjects_[MAX_OBJECTS];
	int frameWidth_, frameHeight_;


public:
	Manager(int frameWidth, int frameHeight);
	~Manager();
	void add(PopObject* popObject);
	void drawFrame(Graphics^ graphics);
	void move();
	bool remove(PopObject* popObject);
	PopObject* search(int x, int y);
	bool objCollision(PopObject* firstBall, PopObject* secondBall);
	void decreaseSpeed(PopObject* popObject);
	void increaseSpeed(PopObject* popObject);
};


extern Manager* manager;


/* Столкновение обьекта ! - создаем функцию которое будет возвращать bool значение
если шарики столкнулись мы передадим шарик который отскочить от другово шара
*/