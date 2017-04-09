#include <iostream>
#include <string>

using namespace std; 

template<class T>

class TreeNode
{
public: 
	TreeNode();
	TreeNode(T key);//overloaded 
	//virtual ~TreeNode();//can define this later; polymorphism  
	~TreeNode();

	T key;
	TreeNode<T>* left;
	TreeNode<T>* right;


};

template<typename T>
TreeNode<T>::TreeNode()
{
	left = NULL;
	right = NULL;

}

template<typename T>
TreeNode<T>::TreeNode(T k)
{
	left = NULL;
	right = NULL;
	key = k;
}
