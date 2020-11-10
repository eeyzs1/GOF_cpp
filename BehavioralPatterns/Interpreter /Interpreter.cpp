#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <typeinfo>

using namespace std;


//zang141588761: thanks to https://blog.csdn.net/zang141588761/article/details/53483645
class Expression
{
public:
    virtual int interpreter(map<string, int>& var) = 0;
    virtual ~Expression(){};
};


//variable interpreter(Terminal Expression)
class VarExpression : public Expression
{
    string key;
public:
    VarExpression(string key)
    {
        this->key = key;
    }

    //get the variables from context
    int interpreter(map<string, int>& var)
    {
        return var[key];
    }

    ~VarExpression()
    {
        cout << "~VarExpression()" << endl;
    }
};

//for compute symbols, Nonterminal Expression
class SymbolExpression : public Expression
{
protected:
    Expression* left;
    Expression* right;
public:
    SymbolExpression(Expression* left, Expression* right)
    {
        this -> left = left;
        this -> right = right;
    }

    Expression* getLeft()
    {
        return left;
    }
    Expression* getRight()
    {
        return right;
    }
};

//+
class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression* left, Expression* right): SymbolExpression(left,right)
    {
    }

    int interpreter(map<string, int>& var)
    {
        return left->interpreter(var) + right ->interpreter(var);
    }
    ~AddExpression()
    {
        cout << "~AddExpression()" << endl;
    }
};

//-
class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression* left, Expression* right): SymbolExpression(left,right)
    {
    }

    int interpreter(map<string, int>& var)
    {
        return left->interpreter(var) - right ->interpreter(var);
    }

    ~SubExpression()
    {
        cout << "~SubExpression()" << endl;
    }
};

//*********************************Parser encapsulation class***************************************
//based on Demeter Principle, like Facade
class Calculator
{
private:
    Expression* expression;
public:

    Calculator(string expStr)
    {
        expression = NULL;

        //stack to store intermediate results
        stack<Expression*> stkExp;

        Expression* left  = NULL;
        Expression* right = NULL;

        /*interperte exp from left to right, like a+b-c£º
         *           -
         *         /   \
         *       +     c
         *     /   \
         *    a     b
        */
        for(unsigned int i = 0; i< expStr.length(); i++)
        {
            switch(expStr[i])
            {
            case '+':  
                //1.get left op num from stack
                left = stkExp.top();
                stkExp.pop();

                //2.get the right op num from exp£¬and generate terminal expression
                right = new VarExpression(expStr.substr(++i,1));

                //3.add left and right op nums and push to stack
                stkExp.push(new AddExpression(left, right));

                break;

            case '-': //same process as "add" except this time use "minus" 
                left = stkExp.top();
                stkExp.pop();
                right = new VarExpression(expStr.substr(++i,1));
                stkExp.push(new SubExpression(left, right));
                break;

            default:
                //get the variable on the far left
                stkExp.push(new VarExpression(expStr.substr(i,1)));
            }
        }

        //then what stored in stack is the final expression
        if(!stkExp.empty())
        {
            expression = stkExp.top();
            stkExp.pop();
        }
    }

    void deltree(Expression* expression)
    {
        SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expression);
        //leaf node
        if (branch == NULL)
        {
            delete expression;
        }
        else  //branch node
        {
            //left son tree
            deltree(branch->getLeft());

            //right son tree
            deltree(branch->getRight());

            //this node
            delete expression;
        }
    }

    ~Calculator()
    {
        deltree(expression);
        expression = NULL;
    }

    //calculate the result
    int run(map<string, int>& var)
    {
        return (expression == NULL) ? 0 : expression->interpreter(var);
    }
};

int main()
{
    string expStr = "a+b-c"; //use legal exp to simplify the process

    map<string, int> var;   //work as the context
    var["a"] = 100;
    var["b"] = 20;
    var["c"] = 40;

    Calculator cal(expStr);

    cout <<"Result is:" << expStr << " = " << cal.run(var) << endl;
    return 0;
}