#include<cstring>
#include <iostream>
using namespace std;

class Sach
{
	protected:
		char TenSach[30];
		char TacGia[30];
		int NamXB;
		float GiaSach;
	public:
		void Nhap();
		void Xuat();
		char * Sapxep()
		{
		 return TenSach;
		}
		int LietKe(){
			return NamXB;
		}
		int Tinh_Gia_Sach(){
			return GiaSach;
		}
};
void Sach::Nhap()
{
	  fflush(stdin);
	  cout<<"\nTen sach: ";
	  cin.get(TenSach,30);
	  
	  fflush(stdin);
	  cout<<"Tac gia: ";
	  cin.get(TacGia,30);
	  fflush(stdin);
	  cout<<"Nam xuat ban: ";
	  cin>>NamXB;
	  cout<<"Gia: ";
	  cin>>GiaSach;
}

void Sach::Xuat()
{
	cout<<"\t\t -Ten sach: "<<TenSach<<endl<<"\t\t\t   +Tac gia: "<<TacGia<<endl<<"\t\t\t   +Nam xuat ban: "<<NamXB<<endl<<"\t\t\t   +Gia: "<<GiaSach<<" VND"<<endl;
}

class QuanLy:public Sach{
	private:
		Sach sach[100];
		int n;
	public:
		void Nhap(){
			cout<<"Nhap so luong sach: ";
			cin>>n;
			
			cout<< "\nNhap danh sach sach: \n";
			for(int i=0;i<n;i++){
				sach[i].Nhap();
			}
		}
		
		void Xuat(){
				for(int i=0;i<n;i++){
				sach[i].Xuat();
				cout<<endl;
			}
		}
		void Sapxep()
		{
			char temp[30];
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
				   if(strcmp(sach[i].Sapxep(),sach[j].Sapxep() )>0)
				  {
					strcpy(temp,sach[i].Sapxep());
            		strcpy(sach[i].Sapxep(),sach[j].Sapxep());
            		strcpy(sach[j].Sapxep(),temp);
				  }
				}
				sach[i].Xuat();
				cout<<endl;
			} 
			
		}
		int LietKe(int tukhoa){
			for(int i=0;i<n;i++){
				if(sach[i].LietKe()==tukhoa){
					sach[i].Xuat();
					cout<<endl;
				}
			}
			
		}
		int Tinh_Gia_Sach(){
			float GiaSachSauThue;
			for(int i=0;i<n;i++){
				sach[i].Xuat();
				GiaSachSauThue=sach[i].Tinh_Gia_Sach()*0.1+sach[i].Tinh_Gia_Sach();
				cout<<"\t\t\t   +Gia sach sau thue: "<<GiaSachSauThue<<" VND";
				cout<<endl;
			}
		}
};
int main()
{
	QuanLy ql;
	int tukhoa;
	ql.Nhap();
	cout<< "\nDanh sach sach vua nhap la: \n";
	ql.Xuat();
	cout<< "\nSap xep sach theo thu tu abc: \n";
	ql.Sapxep();
	cout<<"\nSach sau khi tinh thue: \n";
	ql.Tinh_Gia_Sach();
	cout<<"\nNhap vao nam xuat ban:";
	cin>>tukhoa;
	ql.LietKe(tukhoa);

}
