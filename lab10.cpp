#include<iostream>
#include<string>
using namespace std;
class StudentBST;
class StudentNode
{
	friend class StudentBST;
private:
	int rollNo; // Student’s roll number (must be unique)
	string name; // Student’s name
	double cgpa; // Student’s CGPA
	StudentNode* left; // Pointer to the left subtree of a node
	StudentNode* right; // Pointer to the right subtree of a node
public:
	StudentNode() {
		left = right = NULL;
	}
	StudentNode* getright()
	{
		return right;
	}
	StudentNode* getleft()
	{
		return left;
	}
	double getcgpa()
	{
		return cgpa;
	}
	int getroll()
	{
		return rollNo;
	}
	string getname()
	{
		return name;
	}
	~StudentNode()
	{
		if (left != NULL)
		{
			delete left;
			left = nullptr;
		}
		if (right != NULL)
		{
			delete right;
			right = nullptr;
		}
	}
	StudentNode(int rollNo, string name, double cgpa)
	{
		this->rollNo = rollNo;
		this->cgpa = cgpa;
		this->name = name;
		this->left = NULL;
		this->right = NULL;
	}
};
class StudentBST
{
private:
	StudentNode* root; // Pointer to the root node of the BST
public:
	void setroot(StudentNode* n)
	{
		root = n;
	}
	StudentBST() // Default constructor
	{
		root = nullptr;
	}
	~StudentBST()
	{
		if (root != NULL)
		{
			delete root;
			root = NULL;
		}
	}
	StudentNode* getroot()
	{
		return root;
	}
	bool insert(int rn, string n, double c)
	{
		return insert(rn, n, c, root);
	}
	bool insert(int rn, string n, double c, StudentNode*& root)
	{
		if (!root)
		{
			root = new StudentNode(rn, n, c);
			return true;
		}
		if (root->rollNo == rn)
		{
			cout << "Tried to enter duplicate entry\n";
			return false;
		}
		else if (root->rollNo < rn)
		{
			return insert(rn, n, c, root->right);
		}
		else
		{
			return insert(rn, n, c, root->left);
		}
	}
	bool search(int rn)
	{
		return search(rn, root);
	}
	bool search(int rn, StudentNode* root)
	{
		if (!root)
		{
			return false;
		}
		if (root->rollNo == rn)
		{
			cout << "Entry Founded\n";
			cout << root->rollNo << " " << root->name << " " << root->cgpa << endl;
			return true;
		}
		else if (root->rollNo < rn)
		{
			return search(rn, root->right);
		}
		else
		{
			return search(rn, root->left);
		}
	}
	void inOrder(StudentNode* s) // private member function of StudentBST class
	{
		if (!s)
		{
			return;
		}
			inOrder(s->left);
			cout << s->rollNo << " " << s->name << " " << s->cgpa << endl;
			inOrder(s->right);
	}
	bool remove(int rollno)
	{
		return remove(rollno, root);
	}
	bool remove(int rollno, StudentNode*&root)
	{
		if (!root)
		{
			return false;
		}
		if (root->rollNo < rollno)
		{
			return remove(rollno, root->right);
		}
	    if (root->rollNo > rollno)
		{
			return remove(rollno, root->left);
		}
		if(root->rollNo==rollno)
		{
			if (root->left ==NULL && root->right== NULL) 
			{
				delete root;
				root = NULL;
				return true;
			}
			else if (root->right == NULL)
			{
				root->cgpa = root->left->cgpa;
				root->name = root->left->name;
				root->rollNo = root->left->rollNo;
				return remove(root->left->rollNo, root->left);
			}
			else if (root->left == NULL)
			{
				root->cgpa = root->right->cgpa;
				root->name = root->right->name;
				root->rollNo = root->right->rollNo;
				return remove(root->right->rollNo, root->right);
			}
			if (root->right && root->left)
			{
				StudentNode*temp = root->right;
				while (temp->left != NULL)
				{
					temp = temp->left;
				}
				root->cgpa = temp->cgpa;
				root->name = temp->name;
				root->rollNo = temp->rollNo;
				if (temp->right)
				{
					temp->cgpa = temp->right->cgpa;
					temp->name = temp->right->name;
					temp->rollNo = temp->right->rollNo;
					return remove(temp->right->rollNo, temp->right);
				}
				else
					return remove(temp->rollNo,temp);
			}
		}
		return root;
	}
	void inOrder()
	{
		inOrder(root);
	}
};
int maxDepth(StudentNode* root)
{
	if (!root)
		return 0;
	else if (!root->getleft() && !root->getright())
		return 0;
	else
	{
		return max(maxDepth(root->getleft()), maxDepth(root->getright())) + 1;
	}
}
int maxdepth(StudentBST& root)
{
	return maxDepth(root.getroot());
}
int main()
	{
		StudentBST tree; //the key and value both are of type int

		tree.insert(500, "Ali", 2.5);
		tree.insert(1000, "Ahsan", 3.2);
		tree.insert(1, "Ahmed", 1.2);
		tree.insert(600, "Abd", 2.2);
		tree.insert(700, "Sohail", 3.1);
		tree.insert(10, "Sami", 3.2);
		tree.insert(30, "Abuzar", 3.3);
		tree.insert(9000, "Leena", 3.4);
		tree.insert(50000, "Kubra", 3.5);
		tree.insert(20, "Arsalan", 3.6);
		cout << "Before deletion\n";
		//tree.inOrder();
		//tree.remove(20);
		//cout << "After removing 20\n";
		//tree.inOrder();
		//tree.remove(500);
		//cout << "After removing 500\n";
		//tree.inOrder();
		//tree.remove(1000);
		//cout << "After removing 1000\n";
		tree.inOrder();
		cout << "Max Depth " << maxdepth(tree);
		cout << endl;
		int sum = 0;
		//tree.leafSum(tree.getroot(), sum);*/

		return 0;
}