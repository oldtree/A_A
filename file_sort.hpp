#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <list>
#include <time.h>


std::time_t time_run;

using namespace std;

#define NUM_ELEM 2048
int One[NUM_ELEM];
int Two[NUM_ELEM];
class Sample

{
public:
	Sample();
	~Sample();
	void operator<<(ostream &o){
		 o<<this->a<<" :: "<<this->b<<endl;
	}
	friend ostream& operator<<(ostream& o,const Sample& s){
		o<<s.a<<" :: "<<s.b<<endl;
		return o;
	}
private:
	int a ;
	int b;
};

Sample::Sample()
{
	this->a = 10;
	this->b = 20;
}

Sample::~Sample()
{
}

std::list<std::pair<string,int>> filelist;

void file_list(){
	for (int i = 0; i < 10 ;i++)
	{

	}
}

int str2int(const char *str){
	if (str == NULL)
	{
		return -1;
	}
	char * head = const_cast<char *>(str);
	int value = 0 ;
	while (*head!= '\0')
	{
		value = value*10+ *head-'0' ;
		head ++;
	}
	return value;
}

void output_resualt(string file_name,int * ptr){
	filebuf  buffer;
	ostream  output(&buffer);
	buffer.open(file_name,ios::in|ios::out|ios::trunc);
	for (int i = 0; i < NUM_ELEM; i++)
	{
		output<<ptr[i]<<endl;
	}
	output.clear();
	buffer.close();
}
void Sort(){

}

template<typename T ,int ELEM_NUM>
void insert_sort(T * ptr){
	if (ptr == NULL)
	{
		return ;
	}
	T temp;
	for (int i = 0; i < ELEM_NUM-1; i++)
	{
		for (int j = i+1; j >=0; j--)
		{
			if (ptr[j]<ptr[j-1])
			{
				temp = ptr [j];
				ptr [j] = ptr [j-1];
				ptr [j-1] = temp;
			} 
		}
	}
}

template<typename T , int ELEM_NUM>
void shell_sort(T * ptr ,int ELEM_NUM){
	int step = 0;
	for(int n =ELEM_NUM/2;n>1;n=n/2){
		for(int m  =0 ;m<n;m++){
			for(int l = m;l<ELEM_NUM;l=l+n)
			{
				for(int j = l+n;j<ELEM_NUM;j=j+n)
					if(ptr[l]>ptr[j])
						swap_func<T>(&ptr[l],&ptr[j]);
			}
		}
	}

}



template<typename T>
void swap_func(T * t1 , T * t2){
	if ((t1== NULL)||(t2==NULL))
	{
		return;
	}
	T temp ;

	temp = *t1;
	*t1 = *t2;
	*t2 =temp;

}
template<typename T >
void quick_sort(T * ptr,int left ,int right){
	
	if (left < right)
	{
		int mid = partition<T>(ptr,left,right);
		quick_sort(ptr,left,mid-1);
		quick_sort(ptr,mid+1,right);
	}
	 
}
template<typename T >
int partition(T * ptr,int left ,int right){

	int mid =  (right +left)/2 ;
	int store = left;
	swap_func<T>(ptr+mid,ptr+right);

	for (int i = left; i < right  ; i++)
	{
		if (ptr[i] < ptr[right])
		{
			swap_func<T>(ptr+i,ptr+store);
			store ++;
		}
	}

	swap_func<T>(ptr+store,ptr+right);
	return store;
}

template<typename T ,int SUM_SIZE>
void merge_two(T * ptr1,int ptr1_size,T * ptr2 ,int ptr2_size){
    if (ptr1 == nullptr|| ptr2 == nullptr)
    {
		return;

    }
	int i = 0;
	int j = 0;
	int n = 0;
	T End[SUM_SIZE]	= {};
	while (i< ptr1_size&& j< ptr2_size)
	{
	    End[n++] = *(ptr1+i) < *(ptr2+j)	 ?	*(ptr1+i++) :  *(ptr2+j++);
	}
	while (i< ptr1_size)
	{
		End[n++] = *(ptr1+i) ;
	}
	while (j< ptr2_size)
	{
		End[n++] = *(ptr2+j) ;
	}

}


void Merge_sort(){

}


void open_file(string filename ,int *ptr){
	 filebuf buffer;
	 ostream output(&buffer);
	 istream input(&buffer);
	 buffer.open(filename,ios::in|ios::out|ios::trunc);
	 //Sample s;
	 //s.operator<<(output);
	 //output<<s<<endl;
	 std::default_random_engine dre;
	 std::uniform_int_distribution<int> dint(0,10000000);
	 for (int i = 0; i < NUM_ELEM; i++)
	 {
		 //s.operator<<(output);
		 output<<dint(dre)<<endl;
	 }
	 input.seekg(ios::beg);
	 int i =0 ;
	 string str;
	 while (getline(input,str))//input.get(c))
	 {
	 	//cout.put(c);
		//One[i] = atoi(str.c_str());
		ptr[i] = str2int(str.c_str());
		i++;
	 }
	 input.clear();
	 output.clear();
	 //insert_sort<int ,NUM_ELEM>( ptr);
	 //quick_sort<int>( ptr,0 ,NUM_ELEM-1);
	 shell_sort<int ,NUM_ELEM>( ptr,NUM_ELEM);
	 output_resualt("resualt.txt",ptr);
	 buffer.close();
}


void sort_two_file(const string& file_one,const string& file_two,const string& file_target ){

	open_file(file_one ,One);
	open_file(file_two ,Two);

}
