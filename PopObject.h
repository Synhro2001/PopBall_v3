#pragma once
 using namespace System::Drawing;



class PopObject
{


public: 
	virtual void draw(Graphics^ graphics) = 0;
	virtual void interact(PopObject* popObject) = 0;
	virtual void setPos(int x, int y) = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual int getSize() = 0;
	virtual float getdX() = 0;
	virtual float getdY() = 0;
	virtual void setSpeed(float dX, float dY) = 0;
	virtual void move() = 0;
	//virtual void centerCoord(int x, int y) = 0;
//	virtual bool hit(int x, int y) = 0;

	

};



/*
float firstX = firstBall->GetX()
float firstY = firstBall->GetY()
float secondX = secondBall->GetX()
float secondY = secondBall->GetY()



*/