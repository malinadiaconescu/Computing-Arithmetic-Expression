#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;
ifstream f("file.in");
string SwapString(string n)
{
    int i=0,j=n.length()-1;
    while(i<j)
    {
        char aux=n[i];
        n[i]=n[j];
        n[j]=aux;
        i++;
        j--;
    }
    return n;
}
int FormNumber(string n)
{
    int nr=0;
    for(int i=0; i<n.length(); i++)
    {
        nr=nr*10+n[i]-'0';
    }
    return nr;
}
class Expression
{
private:
    char expression[101];
    int length;
public:
    Expression(char s[101]);
    bool verify_expression();
    int get_length();
    char position(int i);
};
Expression::Expression(char s[101])
{
    strcpy(expression,s);
    length=strlen(s);
}
char Expression::position(int i)
{
    return expression[i];
}
int Expression::get_length()
{
    return strlen(expression);
}
bool Expression::verify_expression()
{
    stack<char> st;
     int i=0;
     while(i<length)
     {
         if(expression[i]=='(')
         {
             st.push('(') ;
             i++;
         }
         else if(expression[i]>='0'&&expression[i]<='9')
         {
             while(expression[i]>='0'&&expression[i]<='9')
                 i++;
             st.push('n');
         }
         else if(strchr("+-/*",expression[i]))
         {
             st.push('o');
             i++;
         }
         else if(expression[i]==')')
         {
             i++;
             if(!st.empty())
             {
                 char ultim=st.top();
                 st.pop();
                 char penultim=st.top();
                 st.pop();
                 char semn=st.top();
                 st.pop();
                 if(ultim=='n'&&penultim=='n'&&semn=='o'&&st.top()=='(')
                 {
                     st.pop();
                     st.push('n');
                 }
                 else
                     return 0;
             }

         }
         else if(expression[i]==' ')
             i++;
     }
     char rez=st.top();
     st.pop();
     if(rez=='n'&&st.empty())
         return 1;
     else
         return 0;
}
class Node
{
public:
    string val;
    Node* left;
    Node* right;
    Node(string value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
};
class ExpressionTree
{
private:
    Node* head;
public:
    ExpressionTree();
    void FormTree(Expression s);
    void Inorder(Node* n);
    void DisplayInorder();
    int Result();
    int Solve(Node* n);
};
ExpressionTree::ExpressionTree()
{
    this->head=NULL;
}
void ExpressionTree::FormTree(Expression s)
{
    stack<Node* > st;
    for(int i=s.get_length()-1; i>=0; i--)
    {
        if(s.position(i)>='0'&&s.position(i)<='9')
        {
            string aux;
            while(s.position(i)>='0'&&s.position(i)<='9')
            {
                aux+=s.position(i);
                i--;
            }
            i++;
            Node* t=new Node(SwapString(aux));
            st.push(t);
        }
        else if(strchr("+-*/",s.position(i)))
        {
            string aux;
            aux+=s.position(i);
            Node* t=new Node(aux);
            Node* t1;
            Node*t2;
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            t->right=t1;
            t->left=t2;
            st.push(t);
        }
    }
    this->head=st.top();
}
void ExpressionTree::Inorder(Node* n)
{
    if(n)
    {
        if(n->right)
            cout<<"(";
        Inorder(n->right);
        cout<<n->val;
        Inorder(n->left);
        if(n->left)
            cout<<")";
    }
}
void ExpressionTree::DisplayInorder()
{
    Inorder(this->head);
}
int ExpressionTree::Solve(Node* n)
{
    if(n)
    {
        string aux=n->val;
        if(aux[0]>='0'&&aux[0]<='9')
        {
            return FormNumber(aux);
        }
        if(aux=="+")
            return Solve(n->right)+Solve(n->left);
        if(aux=="-")
            return Solve(n->right)-Solve(n->left);
        if(aux=="/")
            return Solve(n->right)/Solve(n->left);
        if(aux=="*")
            return Solve(n->right)*Solve(n->left);
    }
}
int ExpressionTree::Result()
{
    return Solve(this->head);
}
int main()
{
    char s[101];
    f.getline(s,101);
    Expression a=Expression(s);
    if(a.verify_expression())
    {
        ExpressionTree* MyTree=new ExpressionTree();
        MyTree->FormTree(s);
        MyTree->DisplayInorder();
        cout<<endl<<MyTree->Result();
    }
    else
        cout<<"not ok";
    return 0;
}
