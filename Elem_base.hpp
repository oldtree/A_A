#include <stdlib.h>
#include <vector>
#pragma once
class Base
{
public:
	Base()
		:x(0),y(0){
	}
	Base(int x_,int y_)
		:x(x_),y(y_){
	}
#if 0
	explicit Base(Base& other){
		this->f_value = other.f_value;
		this->high = other.high;
		this->open_close = other.open_close;
		this->speed = other.speed;
		this->x = other.x;
		this->y = other.y;
	}
#endif // 0

#if 0
	bool operator<(Base &other){
		return (this->f_value<other.f_value);
	}
	bool operator<=(Base &other){
		return (this->f_value<=other.f_value);
	}
	bool operator==(Base &other){
		return (this->f_value==other.f_value);
	}
	bool operator>(Base &other){
		return (this->f_value > other.f_value);
	}
#endif //

	Base& operator=( Base & other){
		this->f_value = other.f_value;
		this->high = other.high;
		this->open_close = other.open_close;
		this->speed = other.speed;
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	double speed;
	double high;
	int x;
	int y;
	bool open_close;
	double f_value;
};


class Map
{
public:
	Map() :width(10),heigh(10){                

		for (int i=0;i<10;i++)
		{
			Base_ptr.push_back(std::vector<Base>());
			for (int j=0;j<10;j++)
			{
				Base_ptr[i].push_back(Base(i,j));
				Base_ptr[i][j].high=0;
			}
		}
		std::vector<Base>::iterator x_iter =Base_ptr.begin()->begin();
		std::vector<Base>::iterator y_iter =Base_ptr.begin()->begin();
	}

	Map(const int x_w,const int y_h) :width(x_w),heigh(y_h){
	}
	void setPostion(int x ,int y,double speed, double high){
		Base_ptr[x][y].speed = speed;
		Base_ptr[x][y].high = high;

	}

	Base & getPostion(int x ,int y){
		return Base_ptr[x][y];
	}

	double get_positioin_high(int x,int y){
		return Base_ptr[x][y].high;
	}

	double get_positioin_speed(int x,int y){
		return Base_ptr[x][y].speed;
	}
	bool check_out_of_map(Base &position){
		if (position.x<0||position.y<0||position.x>=width||position.y>=heigh)
		{
			return false;
		}
		return true;
	}
protected:
private:
	int width;
	int heigh;
	std::vector< std::vector<Base> > Base_ptr;

};
