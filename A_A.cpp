#include "Select_func.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class A
{
public:
	A(){
		a =10;
		b=10;
	}
#if 0
	void operator<<(std::ostream& os){
		os.put(a).put(' ').put(b);
		os.flush();
	}  
#endif // 0

protected:
private:
	int a;
	int b;
};
int _tmain(int argc, _TCHAR* argv[])
{
	Try_Way t;
	A a;
	A b =a;
	source = Base(0,0);
	target = Base(9,9);
	t.find_the_best_way();
	std::system("pause");
	return 0;
}
