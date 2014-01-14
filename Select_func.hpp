#include <vector>
#include <thread>
#include "Elem_base.hpp"
#include <algorithm>
#include <list>
#include <iostream>
#include <math.h>
#include <deque>
using namespace std;

//how to use f(x,y) = h(x,y) + g(x,y)


Base source;
Base current;
Base target;
int step;


double function_h(Base & now){
	//return (abs(source.x-now.x)+abs(source.y-now.y));
	//return sqrt(abs(source.x-now.x)*abs(source.x-now.x)+abs(source.y-now.y)*abs(source.y-now.y));
	return 0;
}

double function_g(Base & now){
	return sqrt(abs(target.x-now.x)*abs(target.x-now.x)+abs(target.y-now.y)*abs(target.y-now.y));
	//return (target.x-now.x)+(target.y-now.y);
}

void updata_current(Base & now){
	current.f_value = now.f_value;
	current.high = now.high;
	current.open_close = now.open_close;
	current.speed = now.speed;
	current.x = now.x;
	current.y = now.y;

}
double function_f(Base & now){
	//updata_current(now);
	return (function_h(now)+function_g(now));
}
#if 0
typedef double (*g)(int x,int y);
typedef double (*h)(int x,int y);
typedef double (*f)(int x,int y);
#endif // 0

bool compare_two_base(const Base& first,const Base &second){
	if ((first.f_value<second.f_value))
	{
		return true;
	}
	return false;
}

class Compare
{
public:
	bool operator()(const Base& first,Base& second){
		if ((first.f_value<second.f_value))
		{
			return true;
		}
		return false;
	}
protected:
private:
};
class Try_Way
{
public:
	Try_Way()
		:new_map(Map())
	{
		 new_map.print_map();
	}
	void updata_openlist(){
		for(auto itr =openlist.begin(),end=openlist.end();itr != end;itr++)
		{
			itr->f_value= function_f(*itr);

		}
		std::sort(openlist.begin(),openlist.end(),compare_two_base);
	}


	bool find_in_openlist(Base  find){
		//std::find(openlist.begin(),openlist.end(),find);
		for(auto itr =openlist.begin(),end=openlist.end();itr != end;itr++)
		{
			if((itr->x==find.x)&&(itr->y==find.y))
			{
				return true;
			}
		}
		return false;
	}
	bool find_in_closelist(Base  find){
		for(auto itr =closelist.begin(),end=closelist.end();itr != end;itr++)
		{
			if((itr->x==find.x)&&(itr->y==find.y))
			{
				return true;
			}
		}
		return false;

	}

#if 0
	typedef int(*compare)(const void *,const void *) ;




	int compare_base(Base & first ,Base & second)
	{
		if ((!first.open_close)||(!second.open_close))
		{
			printf("param have trouble %x = :",((!first.open_close)||(!second.open_close)));
			return 0;
		}
		else
		{
			first.f_value=function_f(first.x,first.y);
			second.f_value=function_f(second.x,second.y);
			return (first.f_value<=second.f_value);
		}
	}
#endif // 0
	void Generate_next_step(Base now){
		Base now_up(now.x,now.y-1);
		if (new_map.check_out_of_map(now_up)&&(new_map.get_positioin_high(now.x,now.y-1)!=1))
		{
			now_up.f_value=function_f(now_up);
			if (!find_in_openlist(now_up))
			{
				if (!find_in_closelist(now_up))
				{
					now_up.open_close = true;
					openlist.push_back(now_up);
				}
			}
		}
		Base now_down(now.x,now.y+1);
		if (new_map.check_out_of_map(now_down)&&(new_map.get_positioin_high(now.x,now.y+1)!=1))
		{
			now_down.f_value=function_f(now_down);
			if (!find_in_openlist(now_down))
			{
				if (!find_in_closelist(now_down))
				{
					now_down.open_close = true;
					openlist.push_back(now_down);
				}
			}
		}
		Base now_left(now.x-1,now.y);
		if (new_map.check_out_of_map(now_left)&&(new_map.get_positioin_high(now.x-1,now.y)!=1))
		{
			now_left.f_value=function_f(now_left);
			if (!find_in_openlist(now_left))
			{
				if (!find_in_closelist(now_left))
				{
					now_left.open_close = true;
					openlist.push_back(now_left);
				}
			}
		}
		Base now_right(now.x+1,now.y);
		if (new_map.check_out_of_map(now_right)&&(new_map.get_positioin_high(now.x+1,now.y)!=1))
		{
			
			now_right.f_value=function_f(now_right);
			if (!find_in_openlist(now_right))
			{
				if (!find_in_closelist(now_right))
				{
					now_right.open_close = true;
					openlist.push_back(now_right);
				}
			}
		}


		return;


	}
	bool check_equal(Base & first,Base & second){
		if ((first.x==second.x)&&(first.y==second.y))
		{
			return true;
		}
		return false;
	}



	void find_the_best_way(){
		if (!new_map.check_out_of_map(current))
		{
			return;
		}
		if (!new_map.check_out_of_map(source))
		{
			return;
		}
		if (!new_map.check_out_of_map(target))
		{
			return;
		}
		current = source;
		cout<<"target :("<<target.x<<" , "<<target.y<<")"<<endl;
		while (!check_equal(current,target))
		{
			cout<<"current :("<<current.x<<" , "<<current.y<<")"<<endl;
#if 0
			if (!find_in_closelist(current))
			{

			}
			else
			{
				closelist.push_back(current);
			}
#endif // 0
			
			closelist.push_back(current);
			Generate_next_step(current);
			updata_openlist();
			if (openlist.empty())
			{
				cout<<"no effective node to step in!"<<endl; ;
				break;
			} 
			else
			{
				current = *(openlist.begin());
			}
			
			current.open_close = false;
			openlist.clear();
		}
		closelist.push_back(target);
		cout<<closelist.size()<<endl;

	}


protected:
private:
	std::deque<Base> openlist;//准备探索的路线
	std::deque<Base> closelist;//已经确定的路线
	Map new_map;//主要起限定作用
};

