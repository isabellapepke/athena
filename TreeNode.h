#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std; 

template<class T>

class TreeNode
{
public: 
	TreeNode();
	TreeNode(T data);//overloaded 
	//virtual ~TreeNode();//can define this later; polymorphism  
	~TreeNode();

	T data;//going to be student or faculty object
	TreeNode<T>* left;
	TreeNode<T>* right;
	int key;//going to be a random key


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
	data = k;
	srand(time(NULL));
	key = rand();

}

//every time we make an object we are going to use a random key



