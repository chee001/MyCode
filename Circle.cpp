#include <iostream>
using namespace std;


//class Hinhtron
class Hinhtron
{
protected:
    int bankinh;
public:       
    Hinhtron();
    Hinhtron(int bk);
    void DatBankinh(int bk);
    int LayBankinh();
    int LayDuongkinh();
    float LayDientich();
};

Hinhtron::Hinhtron ()
{
	bankinh=0;
}
Hinhtron::Hinhtron(int bk)
{
	bankinh=bk;
}

void Hinhtron::DatBankinh(int bk)
{
	bankinh=bk;	
}
int Hinhtron::LayBankinh()
{
	return bankinh;
}
int Hinhtron::LayDuongkinh()
{
	return bankinh*2;
}
float Hinhtron::LayDientich()
{
	
}
	
//class Hinhcau
class Hinhcau : public Hinhtron
{
public:
    Hinhcau();
    Hinhcau(int bk);
    float LayThetich();
};

Hinhcau::Hinhcau()
{
	bankinh=0;	
}
Hinhcau::Hinhcau(int bk)
{
	bankinh=bk;
}
float Hinhcau::LayThetich()
{
	return 3.14*bankinh*bankinh*bankinh*(4.0/3.0);
}

int main()
{
	Hinhcau a();
	Hinhcau b(5);
	cout<<b.LayThetich()<<endl;
	return 0;
}






