# include<iostream>
using namespace std;
class time
{
	short int hh,mm,ss;
	public:
		time()
		{
			hh= mm =ss =0;
		}
		void getdata(int i,int j,int k)
		{
			hh=i;
			mm=j;
			ss=k;
		}
		void prndata(void)
		{
			cout<<"\n time is "<<hh<<":"<<mm<<":"<<ss<<"\n";
			
		}
		
		
};
int main()
{
	time T1,*tptr;
	cout<<"initializing data members using the object,with values 12,22,,11\n";
	T1.getdata(12,22,11);
	cout<<"printing members using the object: ";
	T1.prndata();
	tptr=&T1;
	cout<<"printing members using object pointers";
	tptr->prndata();
	cout<<"\ninitializing data members using the object,with values 15,10,16";
	tptr->getdata(15,10,16);
	cout<<"printing members using the object: ";
	T1.prndata();
	cout<<"printing members using object pointers: ";
	tptr->prndata();
	return 0;
}