#include <iostream>

using namespace std;

class Fruit
{
public:
    virtual void sayname() = 0;
};

class Banana : public Fruit
{
public:
    void sayname()
    {
        cout<<"我是香蕉"<<endl;
    }
};

class Apple : public Fruit
{
    void sayname()
    {
        cout<<"我是苹果"<<endl;
    }
};


class AbstractFactory
{
public:
    virtual Fruit *CreateProduct() = 0;
};

class AppleFactory : public AbstractFactory
{
public:
    Fruit *CreateProduct()
    {
        return new Apple;
    }
};

class BananaFactory : public AbstractFactory
{
public:
    Fruit *CreateProduct()
    {
        return new Banana;
    }
};


//#######################################
//########## 添加新功能

class Pear : public Fruit
{
public:
    void sayname()
    {
        cout<<"我是梨子"<<endl;
    }
};

class PearFactory : public AbstractFactory
{
public:
    Fruit *CreateProduct()
    {
        return new Pear;
    }
};


int main()
{
    AbstractFactory *factory;
    Fruit *fruit;

    //生产香蕉
    factory = new BananaFactory;
    fruit   = factory->CreateProduct();
    fruit->sayname();


    delete factory;
    delete fruit;


    //生产苹果
    factory = new AppleFactory;
    fruit   = factory->CreateProduct();
    fruit->sayname();

    delete factory;
    delete fruit;

    //生产香蕉
    factory = new PearFactory;
    fruit   = factory->CreateProduct();
    fruit->sayname();

    delete factory;
    delete fruit;

    factory = NULL;
    fruit   = NULL;



    return 0;
}
