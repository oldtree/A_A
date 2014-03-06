#include <string>
#include <iostream>
#include <exception>
#include "../GC/showException.hpp"
using namespace  std;



#define  MAX_CHAR 26

typedef struct  CharNode
{
	char nodeop;
	int count;
	CharNode *next[MAX_CHAR];
	int put_sort[MAX_CHAR];
}CharNode;
typedef struct TrieNode 
{
   CharNode * next[MAX_CHAR];

}TrieNode;



TrieNode * rootptr=nullptr;




void initNode(CharNode * node){
	node->count=0;
	for (int i = 0; i < MAX_CHAR; i++)
	{
		node->put_sort[i] = 0;
	}
	for (int i = 0; i < MAX_CHAR; i++)
	{
		 node->next[i] = nullptr; 
	}
}
bool initAll(TrieNode *root){
	 
	 if (!root)
	 {
		 return false;
	 }
	 for (unsigned int i = 0; i < MAX_CHAR; i++)
	 {
		 root->next[i]= new CharNode;
		 initNode(root->next[i]);

		 root->next[i]->nodeop = char('a'+(char)i);
	 }
	 for (unsigned int i = 0; i < MAX_CHAR; i++)
	 {
		 for (unsigned int j = 0; j < MAX_CHAR; j++)
		 {
			 root->next[i]->next[j] = root->next[j]; 
		 }
	 }
	 
	 return true;
}

CharNode * Pick_entry_node(TrieNode * root,char first){
     if (root == nullptr)
     {
		 return nullptr;
     }					
	 if (first>'z'||first<'a')
	 {
		 return nullptr;
	 }

	 return root->next[(int)(first-'a')];
}

void Read_disk(const string content ){
	 string test="help";
	 rootptr = new TrieNode;
	 CharNode* first = nullptr;
	 
	 if (!initAll(rootptr))
	 {
		 return ;
	 }

	 int n =0;
	 first = Pick_entry_node(rootptr,test[n]);
	 CharNode * first_temp = nullptr;
	 first->count++;
	 first_temp = first;
	 n++;
	 while (test[n]){
		first_temp = first_temp->next[(test[n]-'a')];
		first_temp->next[(test[n]-'a')]->count++ ;
		n++;
	 }
}






