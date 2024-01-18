#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    
   Student(string name) {
        this->name = name;
    }
};

class TreeNode {
public:
    Student* student;
    TreeNode* left;
    TreeNode* right;
    
     TreeNode(Student* newStudent) {
        student = newStudent;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, Student* student) {
    if (root == NULL) {
        return new TreeNode(student);
    }
    if (student->name < root->student->name) {
        root->left = insert(root->left, student);
    } else if (student->name > root->student->name) {
        root->right = insert(root->right, student);
    } else {
        cout << "Duplicate student name not allowed: " << student->name << endl;
    }
    return root;
}

TreeNode* remove(TreeNode* root, string name) {
    if (root == NULL) return NULL;

    if (name < root->student->name) {
        root->left = remove(root->left, name);
    } else if (name > root->student->name) {
        root->right = remove(root->right, name);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->student = temp->student;
        root->right = remove(root->right, temp->student->name);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->student->name << endl;
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    
    while (true) {
        int choice;
        cout << "Menu: Examination Seat Allocation" << endl;
        cout << "1. Allocate Seat" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Display Seating According to alphabetical order" << endl;
        cout << "4. Exit" << endl;
        cout << "\n Enter your choice: \n";
        cin >> choice;
        
        switch (choice) {
            case 1:
            	{
				int num;
       cout << "Enter the number of Students for which you want to allocate the seat:";
           cin >> num;
       for (int i = 0; i < num; i++) {
                cout << "Enter student name: \n";
                string name;
               
                cin>> name;
                root = insert(root, new Student(name));
               
            }
             break;
        }
            case 2:
            	{
				string namedel;
                cout << "Enter student name to remove: ";
            
                 cin>>namedel;
                root = remove(root, namedel);
                break;
            }
            case 3:
            	{
				
                cout << "Seating Arrangement: \n" << endl;
                inorder(root);
                break;
            }
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
