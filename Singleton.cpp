#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

class SingletonV1
{
public:
    static SingletonV1* GetInstance(){
        if(NULL==instance)
        {
            instance = new SingletonV1();
        }
        return instance; 
    }

    static void FreeInstance()
    {
        if(NULL!=instance)
        {
            delete instance;
            instance = NULL;
        }
    }

    void DoSomething() { printf("Do something: %d\n", status++); }

private:
    // disable constructor and destructor
    SingletonV1(){ status = 0; printf("default constructor\n"); }
    ~SingletonV1(){ printf("default destructor\n"); }

    // disable assignment constructor
    SingletonV1& operator=(const SingletonV1& rhs){}
    // disable copy constructor
    SingletonV1(const SingletonV1& rhs){}

    static SingletonV1* instance;
    int status;
};

SingletonV1* SingletonV1::instance = NULL;

int main(int argc, char* argv[])
{
    SingletonV1* s1 = SingletonV1::GetInstance();
    s1->DoSomething();
    s1->DoSomething();

    SingletonV1* s2 = SingletonV1::GetInstance();
    s2->DoSomething();
    s2->DoSomething();

    s1->DoSomething();

    // The drawback of "new" approach in constructor is, 
    //  user has to call "FreeInstance", otherwsise, memory leak
    SingletonV1::FreeInstance();
    
    // On thing more, you cannot stop user to call DoSomthing even after FreeInstance is called
    // it's not legal, but the error depends on system (in this case, the DoSomething still somehow works)
    s2->DoSomething();
    s2->DoSomething();
    s2->DoSomething();
    s2->DoSomething();

    return 0;
}

class SingletonV2
{
public:
    static SingletonV2* GetInstance(){
        return &instance; 
    }

    void DoSomething() { printf("Do something: %d\n", status++); }

private:
    // disable constructor and destructor
    SingletonV2(){ status = 0; printf("default constructor\n"); }
    ~SingletonV2(){ printf("default destructor\n"); }

    // disable assignment constructor
    SingletonV2& operator=(const SingletonV2& rhs){}
    // disable copy constructor
    SingletonV2(const SingletonV2& rhs){}

    static SingletonV2 instance;

    int status;
};

SingletonV2 SingletonV2::instance;

int main(int argc, char* argv[])
{
    printf("Main entry\n");

    SingletonV2* s1 = SingletonV2::GetInstance();
    s1->DoSomething();
    s1->DoSomething();

    SingletonV2* s2 = SingletonV2::GetInstance();
    s2->DoSomething();
    s2->DoSomething();
    
    // This approach provides no FreeInstance
    // however, the drawback is, it's early initialization
    // whenever the libraray is loaded, the Singleton is initialized
    // Is there a way I can get rid of this initialization?
    s1->DoSomething();
    
    printf("Main exit\n");

    return 0;
}

class SingletonV3
{
public:
    static SingletonV3* GetInstance(){
        if(NULL==instance)
        {
            instance = new SingletonV3;
        }
        return instance; 
    }

    void DoSomething() { printf("Do something: %d\n", status++); }

private:
    // disable constructor and destructor
    SingletonV3(){ status = 0; printf("default constructor\n"); }
    ~SingletonV3(){ printf("default destructor\n"); }

    // disable assignment constructor
    SingletonV3& operator=(const SingletonV3& rhs){}
    // disable copy constructor
    SingletonV3(const SingletonV3& rhs){}

    static SingletonV3* instance;

    int status;

    static void FreeInstance()
    { 
        if(NULL!=instance)
        {
            delete instance;
            instance = NULL;
        }
    }
private:
    class Delegate
    {
        public: 
        Delegate(){};
        ~Delegate(){ SingletonV3::FreeInstance(); }
    };

    static Delegate d;
};

SingletonV3* SingletonV3::instance = NULL;
SingletonV3::Delegate SingletonV3::d;

int main(int argc, char* argv[])
{
    printf("Main entry\n");

    SingletonV3* s1 = SingletonV3::GetInstance();
    s1->DoSomething();
    s1->DoSomething();

    SingletonV3* s2 = SingletonV3::GetInstance();
    s2->DoSomething();
    s2->DoSomething();
    
    // This approach provides no FreeInstance
    // however, the drawback is, it's early initialization
    // whenever the libraray is loaded, the Singleton is initialized
    // Is there a way I can get rid of this initialization?
    s1->DoSomething();
    
    printf("Main exit\n");
    return 0;
}



