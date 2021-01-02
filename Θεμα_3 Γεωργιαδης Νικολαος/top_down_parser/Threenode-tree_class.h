#include <iostream>

using namespace std;

class ThreenodeTree  //A threenode-tree class in order to create our syntax tree
{
    public:
        ThreenodeTree(wchar_t k) //constructor that takes as parameter the key of the new node 
        {
            key = k; //set given key as current node's key

            leftnode = 0;
            middlenode = 0;
            rightnode = 0; //set all of three children pointers null
        }
            
        //RECURSIVE OUTPUT METHODS

        void Preorder_Output()
        {   //PREORDER OUTPUT OF KEYS  
            if (this) //If the caller pointer is not null
            {
                wcout << key << " "; //print node's key
                leftnode->Preorder_Output(); //then lie to the left sub-tree and repeat
                middlenode->Preorder_Output(); //then lie to the middle sub-tree repeat
                rightnode->Preorder_Output(); //then lie to the right sub-tree repeat
            }
        }

        //The rest output methods are similiar.The only difference is at when we print the key

        void Inorder_Output()
        {   //INORDER OUTPUT OF KEYS
            if (this)
            {
                leftnode->Inorder_Output();
                wcout << key << " "; //we print the key after we lie to the left subtree
                middlenode->Inorder_Output();
                rightnode->Inorder_Output();
            }
        }

        void Postorder_Output()
        {   //POSTORDER OUTPUT OF KEYS
            if (this)
            {
                leftnode->Postorder_Output();
                middlenode->Postorder_Output();
                rightnode->Postorder_Output();
                wcout << key << " "; //we print the key after we lie to all subtrees
            }
        }

        //Recursive search method that returns the pointer to the node we are going to expand.

        //The function takes as parameter the root of our tree and the key we want to find.
        //We begin from the root and we are searching in preorder the node with key k.
        //Also the node to be found, has to have all of its three children null, otherwise its not the one we want to expand.

        static ThreenodeTree *searchNewrootInpreorder(ThreenodeTree *root, wchar_t k) 
        {
            
            if (root) //if current node is not null
            {
                if (root->key == k && !(root->leftnode) && !(root->middlenode) && !(root->rightnode)) //if current node has key k and its children are null,return 
                return root;                                                                          //this node pointer
                    
                ThreenodeTree* p1 = searchNewrootInpreorder(root->leftnode, k); //save the pointer that left-subtree returns, in p1
                if (p1) //if p1 is not null, return p1
                    return p1;

                ThreenodeTree* p2 = searchNewrootInpreorder(root->middlenode, k); //save the pointer that middle-subtree returns, in p2
                if (p2) //if p2 is not null, return p2
                    return p2;

                ThreenodeTree* p3 = searchNewrootInpreorder(root->rightnode, k); //save the pointer that right-subtree returns, in p3
                if (p3) //if p3 is not null, return p3
                    return p3;

                return 0; //if all of p1,p2,p3 return null pointer, return null pointer to parent
            }
            else //otherwise return null pointer to parent
            {
                return 0;
            }
           	 
        }
       
        ThreenodeTree* leftnode;
        ThreenodeTree* middlenode;
        ThreenodeTree* rightnode; //pointers to children
        wchar_t key; //key of node
};
