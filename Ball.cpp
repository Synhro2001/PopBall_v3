#include <iostream>;
#include <math.h>;
#include "Ball.h"


Ball::Ball(int frameWidth, int frameHeight, int x, int y) {
    frameHeight_ = frameHeight;
    frameWidth_ = frameWidth;
    x_ = x;
    y_ = y;
    size_ = 15;
    color_ = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb(); //   Transparent red color.

    dX_ = (rand() % 10) - 10;
    dY_ = (rand() % 10) - 10;

}


void Ball::draw(Graphics^ graphics) {

    Pen ballPen(Color::Black, 1);
    SolidBrush brush(Color::FromArgb(color_));
    graphics->FillEllipse(% brush, x_ - size_, y_ - size_, size_ * 2.0, size_ * 2.0);
    graphics->DrawEllipse(% ballPen, x_ - size_, y_ - size_, size_ * 2.0, size_ * 2.0);


}

void Ball::interact(PopObject* popObject) {

   float dx2, dy2, x2, y2; //данные второго обьекта 
    x2 = popObject->getX(); 
    y2 = popObject->getY();
    dx2 = popObject->getdX();
    dy2 = popObject->getdY();
  
    
    //sides of the triangle
    float Dx = x_ - x2; // 
    float Dy = y_ - y2;
    float h = sqrt(Dx * Dx + Dy * Dy);  // hypotenuse
  
    if (h == 0) h = 0.01; // what was not was division by 0
     
    float sinV = Dx / h;
    float cosV = Dy / h;


    float vectorN = dx2 * sinV + dy2 * cosV;
    float vectorT = -dx2 * cosV + dy2 * sinV;




    float vectorSecondN = dX_ * sinV + dY_ * cosV;
    float vectorSecondT = -dX_ * cosV + dY_ * sinV;
   
    vectorSecondN = vectorN;
    
    dX_ = vectorSecondN * sinV - vectorSecondT * cosV;
    dY_ = vectorSecondN * cosV + vectorSecondT * sinV;
    dx2 = vectorN * sinV - vectorT * cosV;
    dy2 = vectorN * cosV + vectorT * sinV;


  
    
}

void Ball::setPos(int x, int y) {

    if (x <= size_) x = size_ + 1;
    if (x > frameWidth_ - size_) x = frameWidth_ - size_ - 1;

    if (y <= size_) y = size_ + 1;
    if (y > frameHeight_ - size_) y = frameHeight_ - size_ - 1;

    x_ = x;
    y_ = y;

}

float Ball::getX() {
    return x_;
}

float Ball::getY() {
    return y_;
}

float Ball::getdX() {
    return dX_;
}

float Ball::getdY() {
    return dY_;
}


int Ball::getSize() {
    return size_;
}

void Ball::setSpeed(float dX, float dY) {
    if (dX > 10) dX = 10;
    if (dX < -10) dX = -10;
    if (dY > 10) dY = 10;
    if (dY < -10) dY = -10;

    dX_ = dX;
    dY_ = dY;


}

void Ball::move() {

    if ((x_ <= size_) || (x_ > frameWidth_ - size_))
    {
        dX_ = -dX_;
    }
    if ((y_ <= size_) || (y_ > frameHeight_ - size_))
    {
        dY_ = -dY_;
    }

    x_ += dX_;
    y_ += dY_;
}

/*void Ball::centerCoord(int x, int y) {
    int  xCoord = size_ - x_;
    int  yCoord = size_ - y_;

    x = xCoord;
    y = yCoord;
}
*/

/*

bool Ball::hit(int x, int y) {
    return sqrt((x - x_) * (x - x_) + (y - y_) * (y - y_)) <= size_;
}

*/
/*
void Ball::setSize(int size) {



    if (size > 10 && size < 90) {
        size_ = size;
    }
    setPos(x_, y_);


}
*/






// Ne nado ispolzovatj followTO !!!
/*
void Ball::followTo(int x, int y) {

    // дл€ начало узнаЄм проекцию  скорости дл€ x , y 
    //ѕри большой скорости шарик при нажатие правой мыши вылетает за пол€ 

    float hor_speed = x - x_; // horizontal spped
    float ver_speed = y - y_; // vertical speed

    float speed = sqrt((dX_*dX_) + (dY_ * dY_));
    float angle = atan2(ver_speed, hor_speed); // берем значение чисел в модуль и считаем угол
   
    float dx ,dy;
    dx = speed * cos(angle);
    dy = speed * sin(angle);

    dX_ = dx;
    dY_ = dy;

    
   
}

*/



