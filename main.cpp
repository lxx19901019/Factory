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
        cout<<"�����㽶"<<endl;
    }
};

class Apple : public Fruit
{
    void sayname()
    {
        cout<<"����ƻ��"<<endl;
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
//########## ����¹���

class Pear : public Fruit
{
public:
    void sayname()
    {
        cout<<"��������"<<endl;
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

    //�����㽶
    factory = new BananaFactory;
    fruit   = factory->CreateProduct();
    fruit->sayname();


    delete factory;
    delete fruit;


    //����ƻ��
    factory = new AppleFactory;
    fruit   = factory->CreateProduct();
    fruit->sayname();

    delete factory;
    delete fruit;

    //�����㽶
    factory = new PearFactory;
    fruit   = factory->CreateProduct();
    fruit->sayname();

    delete factory;
    delete fruit;

    factory = NULL;
    fruit   = NULL;



    return 0;
}
