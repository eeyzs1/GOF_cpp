//lazy:only create one instance when u need, not when u load
//lazy:not thread safe
class CSingleton
{
public:
    static CSingleton* GetInstance()
    {
        if (nullptr == m_pInstance) {//add lock to make it thread safe, influence the performance
            m_pInstance = new CSingleton();
        }        
        return m_pInstance;
    }
private:
    CSingleton() {};
    static CSingleton* m_pInstance;
};

//hungry:always has one instance when u load
//hungry 1:not thread safe
class CSingleton
{
private:
    CSingleton()
    {
    }
public:
    static CSingleton* GetInstance()
    {
        static CSingleton instance;
        return &instance;
    }
};

//hungry 2:should use this one 
class CMsBsGPSInfoStart
{
public:
    static CMsBsGPSInfoStart& GetInstance();
protected:

    CMsBsGPSInfoStart();
    ~CMsBsGPSInfoStart();

private:
    static CMsBsGPSInfoStart _instance;
};
CMsBsGPSInfoStart CMsBsGPSInfoStart::_instance;
CMsBsGPSInfoStart::CMsBsGPSInfoStart()
{
}

CMsBsGPSInfoStart::~CMsBsGPSInfoStart()
{
}

CMsBsGPSInfoStart& CMsBsGPSInfoStart::GetInstance()
{
    return _instance;
}


