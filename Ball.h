#pragma once
#include "PopObject.h"

class Ball : public PopObject
{
	private:
		float x_, y_; // ���������� ������ ���� 
		int color_; // ���� ����
		int size_; // ������ ���� (������)
		int frameWidth_, frameHeight_; // ������� �����, � ������� ����� ���������� ��� 

		float dX_, dY_;

	public:
		void draw(Graphics^ graphics) override;
		void interact(PopObject* popObject) override;
		void setPos(int x, int y) override;
		Ball(int frameWidth, int frameHeight, int x, int y);
		int getSize() override;
	//	void setSize(int size); // UBRATJ 
		float getdX()override;
		float getdY()override;
		float getX() override;
		float getY() override;
		void setSpeed(float dX, float dY)override;
		void move()override;
		//void centerCoord(int x, int y) override;
		//bool hit(int x, int y) override;
	//	void followTo(int x, int y);// UBRATJ
	};


// �������� ������ �������� � ����������� ���������� �2504 'PopObject': base class undefined
