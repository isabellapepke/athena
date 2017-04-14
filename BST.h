#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

#include "TreeNode.h"

using namespace std;

template<class T>

class BST
{
public:
	BST();
	~BST();

	void insert(T value);
	bool remove(int k);
	bool contains(T k);//find/serach method
	//TreeNode<T>* getMax();//get right most nodes
	T find(int id);//finds the student according to its id

	int getMax();
	int getMin();
	//void InOrder(TreeNode<T> key)

	void StudentInOrder(bool isStudent);
	//void FacultyInOrder(); 

	TreeNode<T> *getSuccessor(TreeNode<T> *d);

private:
	TreeNode<T>* root;

};

template<typename T>
BST<T>::BST()
{
	root = NULL;
}

template <typename T>
BST<T>::~BST()
{
	//iterate and delete
	//linear runtime 
}


template <typename T>
//TreeNode<T>* BST<T>::getMax() //does not need to be recursive 
int BST<T>::getMax()
{
	//need to traverse the tree 

	TreeNode<T>* current = root; //the root is never going to move but the current will

	//checks
	if(root == NULL)
	{
		return 0;
	}
	while(current->right != NULL)
	{
		current = current->right;
	}
	//return &(current->key); //or just return current;

	return current->key;
	//cout << "in get max in BST " << endl;

}


template <typename T>
int BST<T>::getMin()
{
	TreeNode<T>* current = root;

	//checks
	if(root == NULL)
	{
		return 0;
	}
	while(current->left != NULL)
	{
		current = current->left;
	}

	return current->key;
}


template <typename T>
void BST<T>::insert(T value)
{
	TreeNode<T> *node = new TreeNode<T>(value);
	//check if its empty or not
	if(root == NULL)
	{
		root = node;
	}
	else//non empty tree, a failed search first null
	{
		TreeNode<T> *current = root;
		TreeNode<T> *parent;
		while(true)
		{
			parent = current;
			//check left or right

			if((node->key)<(current->key)) //need to be able to check the Student ID number to see whether to go left or right
			{
				current = current->left;
				if(current == NULL)
				{
					parent->left = node;
					break;
				}
			}
			else
			{
				current = current->right;
				if(current == NULL)
				{
					parent->right = node;
					break;
				}

			}
		}

	}
}

template <typename T>
bool BST<T>::contains(T k)
{

	if(root == NULL)
	{
		return false;
	}

	else
	{
		//need to traverse the tree
		TreeNode<T>* current = root; 
		while(current->key != NULL)
		{
			if(k < current->key) //go left
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
			if(current == NULL) //we didnt find the value we were looking for 
			{
				return false;
			}
		}
	}
	return true; 
}


//key is id
template<typename T>
T BST<T>::find(int id)
{
	TreeNode<T> *current = root;
	while (current->key != -1)
	{
		if (id > current->key)
		{
			current = current->right;
		} 
		else if (id < current->key)
		{
			current = current->left;
		} 
		else
		{
			break;
		}
	}
	return current->value;
}







//DELETE: 0 childs(leaf), 1 child(left or right), 2 childs
//enters in an ID to remove, current->key is ID
template <typename T>
bool BST<T>::remove(int k)
{
	if(root == NULL) //empty tree 
	{
		return false;
	}


	TreeNode<T>* current = root;
	TreeNode<T>* parent = root; //or equal to NULL, doesnt matter 
	bool isLeft = true;
	
	//lets search for value we are looking for 


	while(current->key != k)
	{
		parent = current;
		if(k < current->key)
		{
			isLeft = true;
			current = current->left;
		}
		else
		{
			isLeft = false;
			current = current->right;
		}

		if(current == NULL) //key does not exist 
		{
			return false;
		}
	}
	 //we found what we are looking for 

	//case for 0 children 
	if(current->left == NULL && current->right == NULL) //means it is a leaf node 
	{
		if(current == root)
		{
			root = NULL;
		}
		else if(isLeft)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
		cout<<"DELETED WITH 0 CHILDREN"<<endl;

	}

//node with 1 child 
	else if(current->right == NULL) //left child 
	{
		if(current == root)
		{
			root= current->left;
		}
		else if(isLeft)
		{
			parent->left = current->left;
		}

		else
		{
			parent->right = current->left;
		}
		cout<<"DELETED WITH 1 CHILDREN"<<endl;

	}

	else if(current->left == NULL)//right child
	{
		if (current==root)
		{
			root = current->right;
		}
		else if(isLeft)
		{
			parent->left = current->right;//nulled out the child
		}
		else
		{
			parent->right = current->right;//nulled out the child
		}
		cout<<"DELETED WITH 1 CHILDREN right"<<endl;

	}

//two children 
	else
	{
		TreeNode<T>* successor = getSuccessor(current);
		if(current == root)
		{
			root = successor;
		}
		else if(isLeft)
		{
			parent->left = successor;
		}
		else
		{
			parent->right = successor;
		}

		successor->left = current->left;
		cout<<"DELETED WITH TWO CHILDREN"<<endl;

	}
	return true;
}



template <typename T>
TreeNode<T> *BST<T>::getSuccessor(TreeNode<T> *d) //node to be deleted 
{

	TreeNode<T>* sp = d; //successor parent
	TreeNode<T>* successor = d; //shouold be one right and all the way to the left
	TreeNode<T>* current = d->right; 

	while(current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}

	if(successor != d->right)//descendant of the right child 
	{
		sp->left = successor->right;
		successor->right = d->right; 
	}

	return successor;
}



template <typename T>
void BST<T>::StudentInOrder(bool isStudent) 
{
	TreeNode<T> *current = root;

	if (current != NULL)
	{
		StudentInOrder(current->left);
		if (isStudent)
		{
			//cout << current->value.printStudent() <<endl;
		}
		else
		{
			//cout << current->value.printFaculty() <<endl;
		}
		StudentInOrder(current->right);
	}
} 


/*

template <typename T>
void BST<Faculty>::FacultyInOrder() 
{
	TreeNode<Faculty> *current = root;

	if (current != NULL)
	{
		FacultyInOrder(current->left);
		cout << (current->value.printStudent()) <<endl;
		FacultyInOrder(current->right);
	}
} 

*/



#endif 
