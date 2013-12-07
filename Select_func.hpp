#include <vector>
#include <thread>
#include "Elem_base.hpp"
#include <algorithm>
using namespace std;

//how to use  f(x,y) = h(x,y) + g(x,y)

class FGH_function
{
public:

	FGH_function()
	:source(Base(0,0)),target(Base(0,0)),step(0){

	}
	double function_h(int x,int y){
			return (abs(source.x-x)+abs(source.y-y));
	}

	double function_g(int x,int y){
		    return (abs(target.x-x)+abs(target.y-y));
	}

	double function_f(int x,int y){
			return (function_h(x,y)+function_g(x,y));
	}
	typedef double (*g)(int x,int y);
	typedef double (*h)(int x,int y);
	typedef double (*f)(int x,int y);
protected:
private:

  Base source;
  Base target;
  int step;
};



class Try_Way
{
public:
	Try_Way()
	{

	}
	void updata_openlist(){  
		for(auto itr =openlist.begin(),end=openlist.end(),[&](){this->select.function_f(b.x,b.y);})
		{

		}
		std::sort(openlist.begin(),openlist.end());
	}

	typedef int(*compare)(const void *,const void *) ;
	int compare_base(Base & first ,Base & second)
	{
		if ((!first.open_close)||(!second.open_close))
		{
			printf("param have trouble  %x = :",((!first.open_close)||(!second.open_close)));
			return 0;
		} 
		else
		{
			 first.f_value=select.function_f(first.x,first.y);
			 second.f_value=select.function_f(second.x,second.y);
			 return (first.f_value<=second.f_value);
		}
	}
protected:
private:
	std::vector<Base> openlist;
	std::vector<Base> closelist;
	FGH_function select;
	Map new_map;
};



