#include<iostream>
#include<string>
using namespace std;
class StudentBST;
class StudentNode {
	friend class StudentBST;
private:
	int rollNo; // Student’s roll number (must be unique)
	string name; // Student’s name
	double cgpa; // Student’s CGPA
	StudentNode* left; // Pointer to the left subtree of a node
	StudentNode* right; // Pointer to the right subtree of a node
	StudentNode(int rn, string name, double c) {
		this->rollNo = rn;
		this->name = name;
		this->cgpa = c;
		this->left = NULL;
		this->right = NULL;
	}
	~StudentNode() {
		if (left)
			delete left;
		if (right)
			delete right;
	}
};
class StudentBST {
private:
	StudentNode* root; // Pointer to the root node of the BST
	void inOrder(StudentNode* s) {
		if (!s)
			return;
		inOrder(s->left);
		cout << "---------------------------------------\n";
		cout << s->rollNo << " " << s->name << " " << s->cgpa << endl;
		cout << "---------------------------------------\n";
		inOrder(s->right);


	}
public:
	StudentBST() // Default constructor
	{
		root = NULL;
	}
	bool insert(int rn, string n, double c) {
		return insert(rn, n, c, root);
	}
	bool insert(int rn, string n, double c, StudentNode*& root) {
		if (!root) {
			root = new StudentNode(rn, n, c);
			return true;
		}
		if (root->rollNo == rn)
			return false;
		else if (root->rollNo < rn) {
			return insert(rn, n, c, root->right);
		}
		else {
			return insert(rn, n, c, root->left);
		}
	}
	bool search(int rn) {
		return search(rn, root);
		
	}
	bool search(int rn, StudentNode* root) {
		if (!root)
			return false;
		if (root->rollNo == rn)
		{
			cout << "---------------------------------------\n";
			cout << root->rollNo << " " << root->name << " " << root->cgpa << endl;
			cout << "---------------------------------------\n";
			return true;
		}
		else if (root->rollNo < rn) {
			return search(rn, root->right);
		}
		else {
			return search(rn, root->left);
		}
	}
	void inOrder() {
		inOrder(root);
	}

	~StudentBST() {
		if (root)
			delete root;
	}

};

int main() {
	StudentBST bst;
	while (1) 
	{
		cout << "1.Add student\n2.print all students\n3.Print specific student\n4.Exit\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			int rn;
			string name;
			double gpa;
			cout << "Enter RollNumber: ";
			cin >> rn;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin,name);
			cout << "Enter CGPA: ";
			cin >> gpa;
			bst.insert(rn, name, gpa);
		}
		else if (choice == 2) {
			bst.inOrder();
		}
		else if (choice == 3) {
			int rn;
			cout << "Enter RollNumber: ";
			cin >> rn;
			if (bst.search(rn)) {}
			else
				cout << "---------------------------------------\nNo student found!\n---------------------------------------\n";
		}
		else if (choice == 4)
			break;
	}
	

}