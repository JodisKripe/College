#include <bits/stdc++.h>
using namespace std;

int prec_s(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix_s(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }

        else
        {
            while (!st.empty() && prec_s(s[i]) < prec_s(st.top()) ||
                   !st.empty() && prec_s(s[i]) == prec_s(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

struct node_s
{
    char data;
    struct node_s *left;
    struct node_s *right;
};
typedef struct node_s node_s;

node_s *return_tree_s(string exp)
{
    stack<char> stack;
    node_s *root = new node_s;
    root->data = 'N';
    int only_operator = 0;
    for (int i = 0; i < exp.size(); i++)
    {
        if (only_operator == 1)
        {
            root->data = exp[i];
            only_operator = 0;
        }
        else if (exp[i] != '+')
        {
            stack.push(exp[i]);
        }
        else
        {
            if (root->data == 'N')
            {
                node_s *new_node_s_l = new node_s;
                new_node_s_l->data = stack.top();
                stack.pop();
                node_s *new_node_s_r = new node_s;
                new_node_s_r->data = stack.top();
                stack.pop();
                root->data = exp[i];
                root->left = new_node_s_l;
                root->right = new_node_s_r;
            }
            else if (stack.size() == 1)
            {
                node_s *new_node_s_r = new node_s;
                new_node_s_r->data = stack.top();
                stack.pop();
                node_s *new_node_s = new node_s;
                new_node_s->data = exp[i];
                new_node_s->left = root;
                new_node_s->right = new_node_s_r;
                root = new_node_s;
            }
            else
            {
                node_s *new_node_s_l = new node_s;
                new_node_s_l->data = stack.top();
                stack.pop();
                node_s *new_node_s_r = new node_s;
                new_node_s_r->data = stack.top();
                stack.pop();

                node_s *new_node_s = new node_s;
                new_node_s->data = exp[i];
                new_node_s->left = new_node_s_l;
                new_node_s->right = new_node_s_r;

                node_s *temp = new node_s;
                temp->data = 'N';
                temp->left = root;
                temp->right = new_node_s;

                root = temp;

                only_operator = 1;
            }
        }
    }
    return root;
}

void postorder_s(node_s *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder_s(root->left);
        postorder_s(root->right);
        printf("%c ", root->data);
    }
}
void preorder_s(node_s *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%c ", root->data);
        preorder_s(root->left);
        preorder_s(root->right);
    }
}
void inorder_s(node_s *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder_s(root->left);
        printf("%c ", root->data);
        inorder_s(root->right);
    }
}

void printTree_s(node_s *root, int space = 0, int height = 10)
{
    if (root == nullptr)
        return;

    space += height;

    printTree_s(root->right, space, height);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";

    cout << root->data << "\n";

    printTree_s(root->left, space, height);
}

int semantic(string exp)
{
    exp = exp.substr(exp.find("=") + 1);
    cout << infixToPostfix_s(exp) << endl;

    node_s *root = return_tree_s(infixToPostfix_s(exp));

    preorder_s(root);
    cout << endl;
    postorder_s(root);
    cout << endl;
    inorder_s(root);
    cout << endl;

    printTree_s(root);
    return 0;
}