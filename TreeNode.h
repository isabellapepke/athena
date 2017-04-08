class TreeNode
{
	TreeNode();
	TreeNode(int key);//can be anything
	virtual ~TreeNode();//will define it in the subclass, use it to do red black about tree

	int key;
	TreeNode* left;
	TreeNode* right;


};

TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;

}

TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
	key = k;
}

class BST
{
public:
	BST();
	~BST();

	void insert(int value);
	bool delete(int value);
	bool contains(int value);//find/serach method
	TreeNode* getMax();//get right most nodes
private:
	TreeNode* root;

};

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	//iterate and delete
	//linear
}

TreeNode* BST::getMax()
{
	TreeNode* current = root;//start at root

	if(root == NULL)
		return NULL;
	while(current->right !=NULL)
	{
		current = current->right;
	}

	return &(current->key); //or return(current); maybe with templates might require the first one who knows
}

void BST::insert(int value)
{
	TreeNode* node = new TreeNode(value);
	//check if its empty or not
	if(root == NULL)
	{
		root = node;
	}
	else//non empty tree, a failed search first null
	{
		TreeNode* current = root;
		TreeNode* parent;
		while(true)
		{
			parent = current;
			//check left or right
			if(value<current->key)
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


bool BST::contains(int k)
{
	if(root==NULL)
	{
		return false
	}
	else
	{
		TreeNode* node = root;

		while(current->key !=NULL)
		{
			//determine whetehr lef to or right
			if(k<current->key)
			{
				//go left
				current->left;
			}
			else
			{
				current->right;
			}
			if(current==NULL)
			{
				//didnt find it
				return false;
			}
		}
	}
	return true;
}

//DELETE: 0 childs(leaf), 1 child(left or right), 2 childs
bool BST::delete(int k)
{
	if(root ==NULL)
	{
		return false;//empyt tree nothing to delete
	}
	else
	{//partent to null out pointers, when you serach you can return a pointer to that node


		TreeNode* current = root;
		TreeNode* parent = NULL;
		bool isLeft = true;
		while(current->key != k)
		{
			parent = current;
		}

		if(k< current->key)
		{

		}
		else
		{
			isLeft = false;
		}

		if(current == NULL)//key DNE
		{
			return false;
		}
	}
	//we found what we are looking for
	
	//case for 0 children

	if((current->left ==NULL) && (current->right==NULL))
	{
		//we need to check if that current is the root
		if(current == root)
		{
			root = NULL;
		}
		//now right and left nullment
		else if(isLeft)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}

	//case for 1 child, need to check if its a right or lfet child

	else if(current->right == NULL)//left child
	{
		if (current==root)
		{
			root = current->left;
		}
		else if(isLeft)
		{
			parent->left = current->left;//nulled out the child
		}

		else
		{
			parent->right = current->left;//nulled out the child
		}
	}
	else if(current->left == NULL)//right childe
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
	}

}
