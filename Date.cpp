#include <iostream>
using namespace std;


int SoNgayTrongThang(int th, int n)
{
	int NgayTrongThang  =0;
	if (th==1 || th==3 || th== 5|| th==7 || th==8 || th==10 || th==12)
		NgayTrongThang=31;
	if ( th==4 || th==6 || th==9 ||th==11)
		NgayTrongThang=30;
	if (th==2)
	{
		if ((n%4==0 && n%100!=0) || n%400==0)
			NgayTrongThang=29;
		else
			NgayTrongThang=28;
	}
	return NgayTrongThang;

}

class Date
{
private:
	int ngay;
	int thang;
	int nam;
public:
	Date();
	Date(int ng, int t, int n);
	Date operator++(int);
	friend ostream & operator << (ostream &os, Date &r);
	friend istream & operator >>(istream &is, Date &r);
	Date AfterNDays(int a);

};

Date::Date()
{
	ngay=1;
	thang=1;
	nam=1990;
}

Date::Date(int ng, int t, int n)
{
	ngay=ng;
	thang=t;
	nam=n;
}


istream & operator >> (istream &is, Date &r)
{
	cout<<"nhap ngay: ";
	is>>r.ngay;
	cout<<"nhap thang: ";
	is>>r.thang;
	cout<<"nhap nam: ";
	is>>r.nam;
	return is;
}
ostream & operator << (ostream &os, Date &r)
{
	os<<r.ngay<<"/"<<r.thang<<"/"<<r.nam;
	return os;
}

Date Date::AfterNDays(int a)
{
	Date kq = *this;
	while(a!=0)
	{
		if (kq.ngay==SoNgayTrongThang(kq.thang,kq.nam))
		{
	        if (kq.thang==12)
	        {
	        	kq.ngay = 1;
	            kq.thang=1;
	            kq.nam++;
	        }
	        else
	        {
	        	kq.thang++;
	        	kq.ngay = 1;
			}
	    }
	    else
	        kq.ngay++;
	    a--;
	}
	return kq;
}

Date Date:: operator++(int)
{

	if (ngay==SoNgayTrongThang(thang,nam))
	{
        if (thang==12)
        {
            thang=1;
            nam++;
        }
        else
            thang++;
    }
    else
        ngay++;
    return *this;
    //cout<<ngay<<"-"<<thang<<"-"<<nam<<endl;
	//cout<<"so ngay:"<<SoNgayTrongThang(thang,nam)<<endl;
}


/*{
	if(ngay>31 and (thang==1 or thang ==3 or thang ==5 or thang ==7 or thang ==8 or thang ==10 ))
	{
		thang=thang+1;
		ngay=ngay-31;
	}
	if(ngay>30 and (thang==4 or thang ==6 or thang ==9 or thang ==11))
	{
			thang=thang+1;
		ngay=ngay-30;
	}
	if(ngay==31 and thang==12)
	{
		ngay=1;
		thang=1;
		nam++;

	}
}*/
int main()
{
	Date ng1, ng4(12,5,2019), ng5;
	int songay;
	//ng4++;
	Date temp = ng4.AfterNDays(365);
	cout<<ng4<<endl;
	
	cout<<temp;	
    return 0;
}
