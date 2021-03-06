#include<iostream>

using namespace std;

struct node{        // creating node structure

    int data;
    node *left;
    node *right;
};

node *root;     // globally pointer root variable declared

class tree{     // class

    public :

        tree(){       // constructor

            root = NULL;
        }

        node *insert_data( node *root , int data ){     // insert function

            node *temp;
            temp = new node;
            temp->data = data;

            if( root == NULL ){

                root = temp;
                temp->left = NULL;
                temp->right = NULL;
            }else if( root->data == data ){

                cout << endl << "Element already in the tree " << endl;
            }else if( data < root->data ){

                root->left = insert_data( root->left , data );      // use of recursion
            }else if( data > root->data ){

                root->right = insert_data( root->right , data );        // use of recursion
            }

            return root;
        }

        void preorder( node *root ){     // display in preorder function

            if( root != NULL ){

                cout << root->data << " ";
                preorder( root->left );      // use of recursion
                preorder( root->right );     // use of recursion
            }
        }
};

int main()      // main function
{
    tree t;     // object declared
    int n , data;

    root = NULL;

    cout << endl << "Enter number of nodes : ";
    cin >> n;

    cout << endl << "Enter data : " << endl << endl;
    for( int i=0; i<n; i++ ){

        cin >> data;
        root = t.insert_data( root , data );        // call of insertion function
    }

    cout << endl << "Postorderly sorted : ";
    t.preorder( root );      // call of preorder function
    cout << endl;
}
