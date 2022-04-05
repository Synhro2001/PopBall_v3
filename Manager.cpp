#include "Manager.h"
#include "math.h"

Manager* manager; // создаём динамический обьект 

using namespace System::Drawing;

Manager::Manager(int frameWidth, int frameHeight) {
	frameHeight_ = frameHeight;
	frameWidth_ = frameWidth;
	for(int i = 0; i < MAX_OBJECTS; i++) 
    popObjects_[i] = nullptr;
	
	

}

Manager::~Manager() {


	for (int i = 0; i < MAX_OBJECTS; i++) delete popObjects_[i];
}


void Manager::add(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (!popObjects_[i]) {
		popObjects_[i] = popObject;
		break;
	}
}



void Manager::drawFrame(Graphics^ graphics) {
	
	//чистый фон - рисуем прямоугольник с размерами рамки,
	Pen framePen(Color::Black, 3);
	graphics->FillRectangle(% SolidBrush(Color::White), 0, 0, frameWidth_, frameHeight_);
	graphics->DrawRectangle(% framePen, 0, 0, frameWidth_, frameHeight_);
	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i]) {
		popObjects_[i]->draw(graphics);
	}

}

PopObject* Manager::search(int x, int y) {
	int i;
	
	for (i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;



		float Xcentr = popObjects_[i]->getX();
		float Ycentr = popObjects_[i]->getY();

		float dist = sqrt(pow(x - Xcentr, 2) + pow(y - Ycentr, 2));

		if (dist < popObjects_[i]->getSize() + popObjects_[i]->getSize()) {
			return popObjects_[i];
		}
		
	}
	return nullptr;
	
}




bool Manager::objCollision(PopObject* firstBall, PopObject* secondBall) {
	
	
	/* Считаем растояние между обьектами исп теорему питагора 
	используем get что бы получить координаты первого обьекта и второга 
	pow - это возведение в степень метод библиотеки math.h
	В конце возравщаем значение bool таким способом сообщаем програме 
	что шарик близок к столкновению
	*/

	float firstX = firstBall->getX();
	float firstY = firstBall->getY();
	float secondX = secondBall->getX();
	float secondY = secondBall->getY();


	int dist = sqrt(pow(secondX - firstX, 2) + pow(secondY - firstY, 2));

	return (dist < firstBall->getSize() + secondBall->getSize());
	
}

void Manager::move() {
	int i, j;
	for (i = 0; i < MAX_OBJECTS; i++) {
		if(!popObjects_[i])continue;
		for (j = 0; j < MAX_OBJECTS; j++){
			if(!popObjects_[j] || popObjects_[i] == popObjects_[j])continue;

			bool coolision = objCollision(popObjects_[i], popObjects_[j]);
			if (coolision) {
			popObjects_[i]->interact(popObjects_[j]);
			popObjects_[i]->move();
			popObjects_[j]->move();
			}
		}
		popObjects_[i]->move();
	}
	
	//подчситать радиус  и сделать откалкивание от шарика !
	// удалять обьект при нажатие мышки
}


bool Manager::remove(PopObject* popObject) {

	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i] == popObject) {
		popObjects_[i] = nullptr;
		delete popObject;
		break;
	}
	return nullptr;
}