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

	//T key;
	T value;//my object
	int key;//have to call this.getID();
	TreeNode<T>* left;
	TreeNode<T>* right;



};

template<typename T>
TreeNode<T>::TreeNode()
{
	this->left = NULL;
	this->right = NULL;

}

template<typename T>
TreeNode<T>::TreeNode(T k)
{
	this->left = NULL;
	this->right = NULL;
	this->value = k;
	this->key = k.getID;

}
