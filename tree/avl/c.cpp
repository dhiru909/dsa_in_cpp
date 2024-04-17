//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if (!n)
        return 1;
    if (n->data <= lower || n->data >= upper)
        return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper);
}

pair<int, bool> isBalanced(Node *n)
{
    if (!n)
        return pair<int, bool>(0, 1);

    pair<int, bool> l = isBalanced(n->left);
    pair<int, bool> r = isBalanced(n->right);

    if (abs(l.first - r.first) > 1)
        return pair<int, bool>(0, 0);

    return pair<int, bool>(1 + max(l.first, r.first), l.second && r.second);
}

bool isBalancedBST(Node *root)
{
    if (!isBST(root, INT_MIN, INT_MAX))
        cout << "BST voilated, inorder traversal : ";

    else if (!isBalanced(root).second)
        cout << "Unbalanced BST, inorder traversal : ";

    else
        return 1;
    return 0;
}

void printInorder(Node *n)
{
    if (!n)
        return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}

// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution
{
public:
    int heightt(Node *root)
    {
        if (root == NULL)
            return 0;
        return root->height;
    }
    int isbalanced(Node *root)
    {
        if (root == NULL)
            return 0;
        int temp = heightt(root->left) - heightt(root->right);
        return temp;
    }
    Node *leftRotate(Node *root)
    {
        Node *x = root->right;
        Node *temp = x->left;
        x->left = root;
        root->right = temp;
        x->height = 1 + max(heightt(x->left),
                            heightt(x->right));
        root->height = 1 + max(heightt(root->left), heightt(root->right));
        return x;
    }
    Node *rightRotate(Node *root)
    {
        Node *x = root->left;
        Node *temp = x->right;
        x->right = root;
        root->left = temp;
        x->height = 1 + max(heightt(x->left), heightt(x->right));
        root->height = 1 + max(heightt(root->left), heightt(root->right));
        return x;
    }
    /*You are required to complete this method */
    Node *insertToAVL(Node *node, int data)
    {
        // Your code here
        if (node == NULL)
        {
            Node *temp = new Node(data);
            return temp;
        }
        if (data == node->data)
            return node;
        else if (data > node->data)
        {
            node->right = insertToAVL(node->right, data);
        }
        else
        {
            node->left = insertToAVL(node->left, data);
        }
        node->height = 1 + max(heightt(node->left), heightt(node->right));
        int balanced = isbalanced(node);

        if (balanced > 1 && data < node->left->data)
        {
            return rightRotate(node);
        }
        if (balanced > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanced < -1 && data > node->right->data)
        {
            return leftRotate(node);
        }
        if (balanced < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
};

//{ Driver Code Starts.

int main()
{
    int ip[MANX];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> ip[i];

        Node *root = NULL;
        Solution obj;
        for (int i = 0; i < n; i++)
        {
            root = obj.insertToAVL(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        printInorder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
