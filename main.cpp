#include <iostream>
using namespace std;
class USAPlug
{
public:
    virtual void desc() = 0;
};

class USAHole
{
public:
    void fits(USAPlug *uPlug)
    {
        uPlug->desc();
    }
};

class EuropePlug
{
public:
    void desc()
    {
        cout << "this is europe plug" << endl;
    }
};

class EuropePlugAdapter : public USAPlug
{
    EuropePlug *plug;

public:
    EuropePlugAdapter(EuropePlug *p)
    {
        this->plug = p;
    }
    void desc() override
    {
        if (plug != NULL)
        {
            this->plug->desc();
        }
        else
        {
            cout << "you dont have plugger" << endl;
        }
    }
};
int main()
{
    USAHole *hole = new USAHole;
    EuropePlug *ePlug = new EuropePlug;
    // hole->fits(ePlug); // this isn't works.
    USAPlug *plugadapter = new EuropePlugAdapter(ePlug);
    hole->fits(plugadapter);
    return 0;
}