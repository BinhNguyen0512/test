#include <iostream>

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define MAXSV 5000
#define MAXLTC 10000


typedef struct XuLyKhongLuu{
	char Ma[15];
	
}XuLy;

typedef struct DSXuLyKhongLuu{
	int n;
	XuLy xuly[MAXSV];
	
}DSXuLy;


// Struct Sinh vien
typedef struct SinhVien{
	char MaSV[15];
	char Ho[15];
	char Ten[10];
	char Phai[10];
	char SDT[11];
	char MaLop[15];
	
}SV;

typedef struct DanhSachSV{
	int n = 0; 
	SinhVien nodes[MAXSV];
}DSSV;


//Struct Mon Hoc

typedef struct MonHoc{
	char MaMH[10];
	char TenMH[50];
	int STCLT;
	int STCTH;
}MH;

struct Node_MonHoc{
	MH info;
	Node_MonHoc *left;
	Node_MonHoc *right;
};
typedef struct Node_MonHoc *NODEPTR_MONHOC;

//sv dang ky--------ds lien ket don---------
typedef struct SinhVienDKLTC {
	char MaSV[12];
	float Diem;
	int TrangThaiDK = 1;
}SVDKLTC;


struct node_DSSVDK {
	SVDKLTC info;
	node_DSSVDK *next;
};

typedef struct node_DSSVDK *NODEPTR_DSSVDK;


// danh sach lop tin chi--- mang con tro

typedef struct LopTinChi{
	int MaLopTC;
	char MaMH[10];
	char NienKhoa[10];
	int HocKy;
	int Nhom;
	int SoSVMin;
	int SoSVMax;
	int TrangThaiLop;
	NODEPTR_DSSVDK DSSVDK = NULL;
}LTC;

typedef struct DanhSachLopTinChi{
	int n=0;
	LTC *node[MAXLTC];
}DSLTC;

void LTC_DocFile(DSLTC &dsltc); 
void DSDK_DocFile(DSLTC &dsltc);
void SinhVien_DocFile(DSSV &dssv);
void MH_DocFileDSMH(NODEPTR_MONHOC &npmh);

// Mon Hoc
void MH_LuuFile(NODEPTR_MONHOC npmh);
void Init(NODEPTR_MONHOC &npmh);
void Insert_NodeMH(NODEPTR_MONHOC &npmh, MH mh);
int MH_CheckTrungMMH(NODEPTR_MONHOC &npmh, char maMH[]);
int Check_MaMH_LTC(DSLTC dsltc, char maMH[]);
NODEPTR_MONHOC MH_ThongTin(NODEPTR_MONHOC &npmh, char maMH[]);
void remove_case_3(NODEPTR_MONHOC &x, NODEPTR_MONHOC &y);
void MH_XoaNode(NODEPTR_MONHOC &npmh, char maMH[]);
void MH_InorderLNR(ofstream &outfile, NODEPTR_MONHOC npmh);
int MH_SoLuongNode(NODEPTR_MONHOC npmh);
void MH_DuyetNLR(NODEPTR_MONHOC npmh, MH mh[], int &i);
void HoanViMH(MH &mh1, MH &mh2);
void SapXepMH(NODEPTR_MONHOC npmh, MH mh[] ,int dem);
//------------------------------------------------

// LOP TIN CHI

int CheckTrungLTC(DSLTC dsltc, int MaLTC);
int TangMaLTC(DSLTC &dsltc);
int Xoa_LTC(DSLTC &dsltc, int MaLTC);
void LTC_LuuFile(DSLTC dsltc);
void LTC_DocFile(DSLTC &dsltc);
int LTC_CheckTrung4Field(DSLTC dsltc, char MaMH[], char NienKhoa[], int HocKy, int Nhom );
int LTC_CheckTrungNienKhoaHocKy(DSLTC dsltc, char NienKhoa[], int HocKy);
void DSDK_LuuFile(DSLTC &dsltc);
void Insert_Oder(NODEPTR_DSSVDK &First, SVDKLTC svdk); // sap xep co thu tu
int Delete_First (NODEPTR_DSSVDK  &First);
int  Delete_after(NODEPTR_DSSVDK First, char MaSV[]);
int Delete_Tail(NODEPTR_DSSVDK p, NODEPTR_DSSVDK q);
int Delete_info(NODEPTR_DSSVDK &First, char MaSV[]);
int XoaSVDK(DSLTC &dsltc, char MaSV[], int vitriLTC);
int SVDK_DemSLDK(NODEPTR_DSSVDK dsdk);
void ArrTampLTC(DSLTC dsltc, DSLTC &dstamp, char NienKhoa[], int HocKy);
int checkSVDK_LTC1(DSLTC dsltc, int MaLTC, char MaSV[]);
int checkSVDK_MH1( DSLTC dsltc_DaDK, char MaMH[]);
int DemSoLuongSVDK(DSLTC dsltc, int vitri);
int Check_SV_LTC(DSLTC dsltc, char MaSV[]);
int SoSanhChuoi(char Str1[], char Str2[]);

//---------------------------------

//------Sinh vien
int EmptyDSSV(DSSV &ds);
int FullDSSV(DSSV ds);
void HoanViSV(SV &sv1, SV &sv2);
void SapXepDSSV(DSSV &ds);
int CheckTrungMSV(DSSV dssv, char MSV[]);
SV ThongTinSV(DSSV dssv, char MSV[]);
int CheckTrungMaLop(DSSV dssv, char MaLop[]);
int XoaSV(DSSV &dssv, char maSV[]);
int Insert_SV(DSSV &dssv,SV sv);
int SoLuongSV(DSSV dssv, char MaLop[]);
void SinhVien_LuuFile(DSSV dssv);


int SoSanhChuoi(char Str1[], char Str2[])
{
	return strcmp(Str1, Str2);
}


//=======MonHoc=========
void Init(NODEPTR_MONHOC &npmh)
{
	npmh = NULL;
}

//them 1 mon hoc vao trong cay
void Insert_NodeMH(NODEPTR_MONHOC &npmh, MH mh){
	if(npmh == NULL)
	{
		NODEPTR_MONHOC p = new Node_MonHoc;
		p->info = mh;
		p->left = p->right = NULL;
		npmh = p;
		return;
	}
	else
	{
		if( strcmp(mh.MaMH, npmh->info.MaMH) < 0)
		{
			Insert_NodeMH(npmh->left, mh);
		}
		else if ( strcmp(mh.MaMH, npmh->info.MaMH) > 0)
		{
			Insert_NodeMH(npmh->right,mh);
		}
	}
}


int MH_CheckTrungMMH(NODEPTR_MONHOC &npmh, char maMH[])
{
	
	if (npmh != NULL) {
		if (strcmp(maMH, npmh->info.MaMH) == 0)
		{
			return 1;
		}
		else if (strcmp(maMH, npmh->info.MaMH) < 0)
		{
			MH_CheckTrungMMH(npmh->left, maMH);
		}
		else
		{
			MH_CheckTrungMMH(npmh->right, maMH);
		}
	}
	else
	{
		return -1;
	}
}

int Check_MaMH_LTC(DSLTC dsltc, char maMH[])
{
	for(int i =0; i <dsltc.n; i++)
	{
		if(strcmp(dsltc.node[i]->MaMH, maMH) == 0 )
		{
			return i;
		}
	}
	return -1;
}

NODEPTR_MONHOC MH_ThongTin(NODEPTR_MONHOC &npmh, char maMH[])
{
	
	if (npmh != NULL) {
		if (strcmp(maMH, npmh->info.MaMH) == 0)
		{
			return npmh;
		}
		else if (strcmp(maMH, npmh->info.MaMH) < 0)
		{
			MH_ThongTin(npmh->left, maMH);
		}
		else
		{
			MH_ThongTin(npmh->right, maMH);
		}
	}

}

void remove_case_3(NODEPTR_MONHOC &x, NODEPTR_MONHOC &y) {
	if(y->left != NULL)
	{
		remove_case_3(x, y->left);// tim trai nhat cay con phai
	}
	else
	{
		x->info = y->info;
		x = y;
		y = y->right; 
	}
}



void MH_XoaNode(NODEPTR_MONHOC &npmh, char maMH[])
{
	if ( npmh == NULL)
	{
		return;
	}
	else
	{
		if (strcmp(maMH, npmh->info.MaMH) < 0 )
		{
			MH_XoaNode(npmh->left, maMH);
		}
		else if (strcmp(maMH, npmh->info.MaMH) > 0)
		{
			MH_XoaNode(npmh->right, maMH);
		}
		else
		{
			NODEPTR_MONHOC rp = npmh;
			if( rp->left == NULL) npmh = npmh->right;
			else if (rp->right == NULL) npmh = npmh->left;
			else remove_case_3(rp,  npmh->right);
			delete rp;
		}
			
	}
}

void MH_InorderLNR(ofstream &outfile, NODEPTR_MONHOC npmh)
{
	if (npmh != NULL) 
	{
		MH_InorderLNR(outfile, npmh->left);
		outfile << npmh->info.MaMH << endl;
		outfile	<< npmh->info.TenMH << endl;
		outfile	<< npmh->info.STCLT << endl;
		outfile	<< npmh->info.STCTH << endl;
		MH_InorderLNR(outfile, npmh->right);
	}
}


void MH_LuuFile(NODEPTR_MONHOC npmh) {
	ofstream outfile;
	outfile.open("DSMH_DoAn.txt", ios::out);
	MH_InorderLNR(outfile, npmh);
	outfile.close();
}

void MH_DocFileDSMH(NODEPTR_MONHOC &npmh) {
	ifstream infile;
	string data;
	infile.open("DSMH_DoAn.txt", ios::in);
	if (!infile) { 
		cout << "Khong tim thay file";
		return; 
	} //Khong tim thay file
	while (infile.good())
	{
		MH mh;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(mh.MaMH, data.c_str());
		getline(infile, data);		strcpy(mh.TenMH, data.c_str());
		getline(infile, data);		mh.STCLT = atoi(data.c_str());
		getline(infile, data);		mh.STCTH = atoi(data.c_str());
		Insert_NodeMH(npmh, mh);
	}
	infile.close();
}

//Dem so nut cua cay nhi phan
int MH_SoLuongNode(NODEPTR_MONHOC npmh){
    if(npmh==NULL) return 0;
    else return (1 + MH_SoLuongNode(npmh->left) + MH_SoLuongNode(npmh->right));
}



void MH_DuyetNLR(NODEPTR_MONHOC npmh, MH mh[], int &i)
{
	if (npmh != NULL)
	{
		mh[i++] = npmh->info;
		MH_DuyetNLR(npmh->left, mh, i);
		MH_DuyetNLR(npmh->right, mh, i);
	}
}

void HoanViMH(MH &mh1, MH &mh2){
	MH tamp = mh1;
	mh1 = mh2;
	mh2 = tamp;
}

void SapXepMH(NODEPTR_MONHOC npmh, MH mh[] ,int dem)
{
	for (int i = 0; i < dem; i++)
	{
		for(int j = 0; j < dem; j++)
		{
			if( SoSanhChuoi(mh[i].TenMH, mh[j].TenMH) == -1)
			{
				HoanViMH(mh[i], mh[j]);
			}
		}
	}
}

//------------------------------------------

//================== xu ly lop tin chi 

int CheckTrungLTC(DSLTC dsltc, int MaLTC)
{
	for( int i = 0; i < dsltc.n; i++)
	{
		if (dsltc.node[i]->MaLopTC == MaLTC)
		{
			
			return i;
		}
	}
	
	return -1;
}



//tu dong tang ma lop tin chi
int TangMaLTC(DSLTC &dsltc)
{
	int i = 0;
	if(dsltc.n == 0) return i + 1;
	else return dsltc.node[dsltc.n-1]->MaLopTC + 1;
}

int Insert_LTC(DSLTC &dsltc, LTC ltc)
{
	int size = dsltc.n;
	if (dsltc.n >= MAXLTC)
	{
		return 0;
	}
	
	//them vao cuoi danh sach
	dsltc.node[size] = new LTC;
	*dsltc.node[size] = ltc;
	dsltc.n++;
	return 1;
}

int Xoa_LTC(DSLTC &dsltc, int MaLTC){
	
   if(dsltc.n == 0) return 0;
   
   int i = CheckTrungLTC(dsltc, MaLTC);
   
   if (i ==-1) return -1;
   else  
   {
	 delete dsltc.node[i];
     for (int j=i; j < dsltc.n; j++)
       dsltc.node[j]=dsltc.node[j+1];
       
     dsltc.n--;  
	}
	return 1;
}

void LTC_LuuFile(DSLTC dsltc)
{
	ofstream outfile;
   	outfile.open("DSLTC_DoAn.txt",ios::out);
   	if(outfile.is_open()){
		for ( int i = 0; i < dsltc.n; i++ )
		{
			outfile << dsltc.node[i]->MaLopTC << endl;
			outfile << dsltc.node[i]->MaMH<< endl;
			outfile << dsltc.node[i]->NienKhoa << endl;
			outfile << dsltc.node[i]->HocKy << endl;
			outfile << dsltc.node[i]->Nhom << endl;
			outfile << dsltc.node[i]->SoSVMax << endl;
			outfile << dsltc.node[i]->SoSVMin << endl;
			outfile << dsltc.node[i]->TrangThaiLop << endl;
		}
	}
	
	outfile.close();
}

void LTC_DocFile(DSLTC &dsltc)
{
	string data;
	fstream infile; 
   	infile.open("DSLTC_DoAn.txt",ios::in);
   	
   	if (!infile) { 
		cout << "Khong tim thay file";
		return; 
	} //Khong tim thay file
	
	while (!infile.eof())
	{
		LTC ltc;
		getline(infile, data); 
		if (data.size() == 0) { break;} 
		ltc.MaLopTC = atoi(data.c_str());
		getline(infile, data);		strcpy(ltc.MaMH, data.c_str());
		getline(infile, data);		strcpy(ltc.NienKhoa, data.c_str());
		getline(infile, data);		ltc.HocKy = atoi(data.c_str());
		getline(infile, data);		ltc.Nhom = atoi(data.c_str());
		getline(infile, data);		ltc.SoSVMax = atoi(data.c_str());
		getline(infile, data);		ltc.SoSVMin = atoi(data.c_str());
		getline(infile, data);		ltc.TrangThaiLop = atoi(data.c_str());
		
		Insert_LTC(dsltc,ltc);
	}
	infile.close();
}

int LTC_CheckTrung4Field(DSLTC dsltc, char MaMH[], char NienKhoa[], int HocKy, int Nhom )
{
	int size = dsltc.n;
	for(int i = 0; i < size; i++)
	{
		if ( (strcmp(dsltc.node[i]->MaMH, MaMH) == 0) && (strcmp(dsltc.node[i]->NienKhoa, NienKhoa) == 0) && (dsltc.node[i]->HocKy == HocKy) &&(dsltc.node[i]->Nhom == Nhom))
		{
			return i;
		}
	}
	return -1;
}

int LTC_CheckTrungNienKhoaHocKy(DSLTC dsltc, char NienKhoa[], int HocKy)
{
	int size = dsltc.n;
	for(int i = 0; i < size; i++)
	{
		if ((strcmp(dsltc.node[i]->NienKhoa, NienKhoa) == 0) && (dsltc.node[i]->HocKy == HocKy))
		{
			return i;
		}
	}
	return -1;
}
//================ xu ly danh sach sinh vien dang ky lop tin chi===============


void DSDK_LuuFile(DSLTC &dsltc)
{
	ofstream outfile;
   	outfile.open("DSSVDK_DoAn.txt",ios::out);
   	if(outfile.is_open()){
   		for(int i = 0; i < dsltc.n; i++)
   		{
   			if (dsltc.node[i]->DSSVDK != NULL)
   			{
			   	outfile << dsltc.node[i]->MaLopTC << endl;
	   			for (NODEPTR_DSSVDK p = dsltc.node[i]->DSSVDK; p != NULL; p = p->next )
				{
					outfile << p->info.MaSV << endl;
					outfile << p->info.Diem << endl;
					outfile << p->info.TrangThaiDK << endl;
				}
			}
		}	
	}
	
	
	outfile.close();
}

void Insert_Oder(NODEPTR_DSSVDK &First, SVDKLTC svdk) // sap xep co thu tu
{
	NODEPTR_DSSVDK p, t, s;
	p = new node_DSSVDK;
	p->info = svdk; 
	p->next = NULL;
	
	// tim phan tu co gia tri vua lon hon hoac bang x
	for( s = First; s!=NULL && (strcmp(svdk.MaSV, s->info.MaSV)  == 1); t = s, s=s->next) ;
	if( s == First)
	{
		p->next = First;
		First = p;
	}
	else
	{
		p->next = s;
		t->next = p;
	}
}


int Delete_First (NODEPTR_DSSVDK  &First)
{ 
	NODEPTR_DSSVDK p;
	if (First == NULL)
	     return 0;	
	p = First;    // nut can xoa la nut dau
	First = p->next;
	delete p; 
	return 1;
}
	
	
int  Delete_after(NODEPTR_DSSVDK First, char MaSV[])
{   
	NODEPTR_DSSVDK q, p;
	for(p = First; p->next != NULL && strcmp(p->info.MaSV, MaSV) != 0; q = p, p = p->next );
	q->next = p->next;
	p->next = NULL;
	delete p;
	return 1;
}


int Delete_Tail(NODEPTR_DSSVDK p, NODEPTR_DSSVDK q)
{
	q->next = NULL;
	p = NULL;
	delete p;
	return 1;
}


int Delete_info(NODEPTR_DSSVDK &First, char MaSV[])
{  
	NODEPTR_DSSVDK p = First;
	NODEPTR_DSSVDK q;
  	if (First==NULL ) 
	{
	  	return 0;
	}
  	if (strcmp(First->info.MaSV, MaSV) == 0) 
	{
        Delete_First(First); 
		return 1;
 	}
    
	for( p=First; p->next!=NULL && strcmp(p->info.MaSV, MaSV) != 0 ; q = p, p= p->next);
	
	if(p->next != NULL)
	{
//		cout << "\np->next khac null";
		Delete_after(First, MaSV);	
		return 1;
	}	
	if( p->next == NULL)
	{
//		cout << "\np->next == null";
		Delete_Tail(p, q);
		return 1;
	}

    return 0;
}

int XoaSVDK(DSLTC &dsltc, char MaSV[], int vitriLTC)
{
	NODEPTR_DSSVDK p;
	for( p = dsltc.node[vitriLTC]->DSSVDK; p != NULL  ; p = p->next)
	{
		if(strcmp(p->info.MaSV, MaSV) == 0)
		{
			Delete_info(dsltc.node[vitriLTC]->DSSVDK, MaSV);
			return 1;
		}
	}
	return 0;
}


int SVDK_DemSLDK(NODEPTR_DSSVDK dsdk)
{
	int dem = 0;
	for(NODEPTR_DSSVDK p = dsdk; p != NULL; p = p->next)
	{
		if( p->info.TrangThaiDK == 1)
		{
			dem++;
		}
	
	}
	return dem;
}
void ArrTampLTC(DSLTC dsltc, DSLTC &dstamp, char NienKhoa[], int HocKy)
{
	int size = dsltc.n;
	
	for(int i = 0; i < size; i++)
	{
		if((strcmp(dsltc.node[i]->NienKhoa, NienKhoa) == 0) && (dsltc.node[i]->HocKy == HocKy) && (dsltc.node[i]->TrangThaiLop == 1))
		{
			dstamp.node[dstamp.n] = new LopTinChi;
			dstamp.node[dstamp.n] = dsltc.node[i];
			dstamp.n++;
		}
	}
}

void DSDK_DocFile(DSLTC &dsltc)
{
	string data;
	fstream infile; 
	
	int checkMaLTC, MaLTC;
	int vitri = 0;
	char tamp[5];
   	infile.open("DSSVDK_DoAn.txt",ios::in);
   	
   	if (!infile) { 
		cout << "Khong tim thay file";
		return; 
	} //Khong tim thay file
	
	while (!infile.eof())
	{
		
		SVDKLTC svdk;
		
		getline(infile, data); 
		if (data.size() == 0) { break;} 
		strcpy(tamp, data.c_str());
		MaLTC = atoi(tamp);

		checkMaLTC = CheckTrungLTC(dsltc, MaLTC);
		cout << checkMaLTC << endl;
		if ( checkMaLTC != -1)
		{		
			vitri = checkMaLTC;
		}
		else
		{
			strcpy(svdk.MaSV, data.c_str());
			getline(infile, data);		svdk.Diem = atoi(data.c_str());	
			getline(infile, data);		svdk.TrangThaiDK = atoi(data.c_str());
			Insert_Oder(dsltc.node[vitri]->DSSVDK, svdk);
		}

		
	}
	infile.close();

}

int checkSVDK_LTC1(DSLTC dsltc, int MaLTC, char MaSV[])
{
	for(int i = 0; i < dsltc.n; i++)
	{
		if( dsltc.node[i]->MaLopTC == MaLTC)
		{
			for(NODEPTR_DSSVDK p = dsltc.node[i]->DSSVDK; p != NULL; p = p->next)
			{
				if( strcmp(p->info.MaSV, MaSV) == 0)
				{
					return i;
				}
			}
		}
	}	
	return -1;
}

int checkSVDK_MH1( DSLTC dsltc_DaDK, char MaMH[])
{
	int size = dsltc_DaDK.n;
	for( int i = 0; i < size; i++)
	{
		if( strcmp(dsltc_DaDK.node[i]->MaMH, MaMH) == 0)
		{
			return 1;
		}
	}
	return -1;
}

int DemSoLuongSVDK(DSLTC dsltc, int vitri)
{
	int dem = 0;
	for (NODEPTR_DSSVDK p = dsltc.node[vitri]->DSSVDK; p != NULL; p = p->next) 
	{ 
		dem++; 
	}
	return dem;
}
int Check_SV_LTC(DSLTC dsltc, char MaSV[])
{
	NODEPTR_DSSVDK dsdk;
	for(int i = 0; i < dsltc.n; i++)
	{
		for(dsdk = dsltc.node[i]->DSSVDK; dsdk != NULL; dsdk = dsdk->next)
		{
			if(strcmp(dsdk->info.MaSV, MaSV) == 0)
			{
				return i;
			}
			
		}
	}
	return -1;
}

//--------------Xu Ly Sinh Vien
int EmptyDSSV(DSSV &ds){
	return ds.n == 0;
}

int FullDSSV(DSSV ds){
	return ds.n == MAXSV;
}

void HoanViSV(SV &sv1, SV &sv2){
	SV tamp = sv1;
	sv1 = sv2;
	sv2 = tamp;
}


void SapXepDSSV(DSSV &ds){
	int size = ds.n;
	int checkTen, CheckHo;
	for (int i = 0; i < size - 1; i++)
	{
		for ( int j = i; j < size; j++)
		{
			checkTen = SoSanhChuoi(ds.nodes[i].Ten, ds.nodes[j].Ten);
			if ( checkTen == 1)
			{
				HoanViSV(ds.nodes[i], ds.nodes[j]);
			}
			else if (checkTen == 0){
				CheckHo = SoSanhChuoi(ds.nodes[i].Ho, ds.nodes[j].Ho);
				if(CheckHo == 1)
				{
					HoanViSV(ds.nodes[i], ds.nodes[j]);
				}
			}
		}
	}

	
}

int CheckTrungMSV(DSSV dssv, char MSV[])
{
	if (EmptyDSSV(dssv)) return -1;
	int size = dssv.n;

	for( int i = 0; i < size; i++)
	{
		if (strcmp(dssv.nodes[i].MaSV, MSV) == 0)
		{
			return i;
		}
	}
	
	return -1;
}

SV ThongTinSV(DSSV dssv, char MSV[])
{
	int size = dssv.n;
	for( int i = 0; i < size; i++)
	{
		if (strcmp(dssv.nodes[i].MaSV, MSV) == 0)
		{
			return dssv.nodes[i];
		}
	}
}

int CheckTrungMaLop(DSSV dssv, char MaLop[])
{
	if (EmptyDSSV(dssv)) return -1;
	int size = dssv.n;
	for( int i = 0; i < size; i++)
	{
		if (strcmp(dssv.nodes[i].MaLop, MaLop) == 0)
		{
			return i;
		}
	}
	
	return -1;
}



int XoaSV(DSSV &dssv, char maSV[]){
	
   if(EmptyDSSV(dssv)) return 0;
   int i = CheckTrungMSV(dssv, maSV) ;
   if (i ==-1) return -1;
   else  
   {
     for (int j=i; j <dssv.n; j++)
       dssv.nodes[j]=dssv.nodes[j+1];
    	dssv.n--;  
	}
	return 1;
}

int Insert_SV(DSSV &dssv,SV sv){
	
	if (FullDSSV(dssv) ) return 0;
	int viTriThem = dssv.n;
	int size = dssv.n;
	
	for(int i = 0; i<size; i++)
	{
		int SoSanhTen = SoSanhChuoi(sv.Ten, dssv.nodes[i].Ten);
		if (SoSanhTen == -1){
			viTriThem = i;
			break;
		}
		else if (SoSanhTen == 0)
		{
			int SoSanhHo = SoSanhChuoi(sv.Ho, dssv.nodes[i].Ho);
			if (SoSanhHo == -1){
			viTriThem = i;
			break;
		}
		}
	}
	
	for (int i = dssv.n - 1 ; i >= viTriThem; i--)
	{
		dssv.nodes[i+1] = dssv.nodes[i];
	}
	
	dssv.nodes[viTriThem] = sv;
	dssv.n++;
	
	return 1;
	
}

int SoLuongSV(DSSV dssv, char MaLop[])
{
	if (EmptyDSSV(dssv)) return -1;
	int dem = 0;
	int size = dssv.n;
	for ( int i = 0; i < size; i++)
	{
		if (strcmp(dssv.nodes[i].MaLop, MaLop) == 0)
		{
			dem++;
		}
	}
	return dem;
}

void SinhVien_LuuFile(DSSV dssv)
{
	ofstream outfile;
   	outfile.open("DSSV_DoAn.txt",ios::out);
   	if(outfile.is_open()){
		for ( int i = 0; i < dssv.n; i++ )
		{
			outfile << dssv.nodes[i].MaLop << endl;
			outfile << dssv.nodes[i].MaSV << endl;
			outfile << dssv.nodes[i].Ho << endl;
			outfile << dssv.nodes[i].Ten << endl;
			outfile << dssv.nodes[i].Phai << endl;
			outfile << dssv.nodes[i].SDT << endl;
		}
	}
	outfile.close();
}

void SinhVien_DocFile(DSSV &dssv)
{
	string data;
	fstream infile; 
   	infile.open("DSSV_DoAn.txt",ios::in);
   	
   	if (!infile) { 
		cout << "Khong tim thay file";
		return; 
	} //Khong tim thay file
	
	while (!infile.eof())
	{
		SinhVien sv;
		getline(infile, data); 
		if (data.size() == 0) { break;} 
		strcpy(sv.MaLop,data.c_str());
		getline(infile, data);		strcpy(sv.MaSV, data.c_str());
		getline(infile, data);		strcpy(sv.Ho, data.c_str());
		getline(infile, data);		strcpy(sv.Ten, data.c_str());
		getline(infile, data);		strcpy(sv.Phai, data.c_str());
		getline(infile, data);		strcpy(sv.SDT, data.c_str());
		Insert_SV(dssv,sv);
	}
	infile.close();
}




