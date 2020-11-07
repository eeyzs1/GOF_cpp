#include <iostream>
using namespace std;

// �﷨������ϵͳ
class CSyntaxParser
{
public:
    void SyntaxParser()
    {
        cout << "Syntax Parser" << endl;
    }
};

// �����м������ϵͳ
class CGenMidCode
{
public:
    void GenMidCode()
    {
        cout << "Generate middle code" << endl;
    }
};

// ���ɻ�������ϵͳ
class CGenAssemblyCode
{
public:
    void GenAssemblyCode()
    {
        cout << "Generate assembly code" << endl;
    }
};

// �������ɿ�ִ��Ӧ�ó�������ϵͳ
class CLinkSystem
{
public:
    void LinkSystem()
    {
        cout << "Link System" << endl;
    }
};

class Facade
{
public:
    void Compile()
    {
        CSyntaxParser syntaxParser;
        CGenMidCode genMidCode;
        CGenAssemblyCode genAssemblyCode;
        CLinkSystem linkSystem;
        syntaxParser.SyntaxParser();
        genMidCode.GenMidCode();
        genAssemblyCode.GenAssemblyCode();
        linkSystem.LinkSystem();
    }
};

 �ͻ���
int main()
{
    Facade facade;
    facade.Compile();
}