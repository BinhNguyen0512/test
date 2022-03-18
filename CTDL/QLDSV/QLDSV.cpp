#include<iostream>

#include "GiaoDien.h"
#include "AllFunction.h"


using namespace std;


char MENUChinh[5][40] = {
	"  1.Quan Ly Lop Tin Chi ",
	"  2.Quan Ly Mon Hoc     ",
	"  3.Quan Ly Sinh Vien   ",
	"  4.Quan Ly Dang Ki     ",
	"  5.THOAT               ",
};
	
char MENUloptc[4][40] = {
	"  1. Xem Va Nhap Danh Sach Lop Tin Chi ",
	"  2. Nhap Diem Lop Tin Chi             ",
	"  3. Xem Diem Lop Tin Chi              ",
	"  4. Huy Lop Tin Chi                   "
}; 

char MENUdangki[2][40] = {
	"  1. Dang Ki Lop Tin Chi               ",
	"  2. Xem Danh Sach Dang Ki             "
	};

	
void ToMauMenuChinh(int color, int vitri)
{
	TextColor(color);
	gotoXY(0, 6 + vitri * 4); cout << "                        ";
	gotoXY(0, 7 + vitri * 4); cout << MENUChinh[vitri];
	gotoXY(0, 8 + vitri * 4); cout << "                        ";
}

void ToMauMenuCon(int color, char MENUCON[][40], int vitri)
{
	TextColor(color);
	gotoXY(28, 6 + (vitri + 1) * 4);	cout << "                                       ";
	gotoXY(28, 7 + (vitri + 1) * 4);	cout << MENUCON[vitri];
	gotoXY(28, 8 + (vitri + 1) * 4);	cout << "                                       ";
}

int MenuCha()
{

	int vitri = 0;
	while (1)
	{
		GioiThieu();
		char key = GetKey();
		if (key == ENTER || (key == RIGHT && vitri != 5)) // vitri!= 6 la ngay tai o Thoát
		{
			return vitri + 1;
		}
		switch (key)
		{
		case DOWN:
		{
			if (vitri == 4)
			{
				ToMauMenuChinh(240, vitri);
				vitri = 0;
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri++;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuChinh(240, vitri);
				vitri = (4);
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri--;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		}
	}
}

int MenuCon(int item, char MENUCON[][40])
{

	char key;
	int vitri = 0;	int color = 188; int color1 = 236;
	while (1)
	{
		GioiThieu();
		key = GetKey();
		if (key == ENTER)
			return vitri + 1;
		if (key == ESC || key == LEFT)
			return 0;
		switch (key)
		{
		case DOWN:
		{
			if (vitri == (item - 1))
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = 0;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri++;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = item - 1;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri--;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		}
	}
}

void MH_Them(NODEPTR_MONHOC &npmh, DSLTC &dsltc)
{
	int key, vitri = 0, x = 12, y = 14, checkMMH;
	MH mh;	mh.MaMH[0] = NULL;	mh.TenMH[0] = NULL;	mh.STCLT = 0;	mh.STCTH = 0;
	MonHoc_KhungThem(); gotoXY(x, y);
MAMH:
	while(1)
	{
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		TextColor(12); gotoXY(12 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			mh.MaMH[vitri] = char(key);
			mh.MaMH[vitri] = toupper(mh.MaMH[vitri]);
			cout << mh.MaMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12 + vitri, y);
			cout << " ";
			gotoXY(12 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.MaMH[vitri] = '\0';
			checkMMH = MH_CheckTrungMMH(npmh, mh.MaMH);
			if (checkMMH == 1) {
				TextColor(78);	gotoXY(10, 15);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(mh.TenMH);
			gotoXY(30 + vitri, y);
			goto TENMH;
		}

		if (key == ESC ) { return; }
	}
TENMH:
	while (1)
	{
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 50";
		TextColor(12); gotoXY(30 + vitri, y); //Ghi chú
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			mh.TenMH[vitri] = char(key);
			mh.TenMH[vitri] = toupper(mh.TenMH[vitri]);
			cout << mh.TenMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30 + vitri, y);
			cout << " ";
			gotoXY(30 + vitri, y);
		}
		if (key == SPACE && mh.TenMH[vitri - 1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(30 + vitri, y);
			cout << " ";
			mh.TenMH[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.TenMH[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TenMH[vitri] = '\0';
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		
		if (key == ESC ) { return; }
	}
STCLT:
	while (1)
	{
		char STCLT[1];
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (0-9 & .). Toi da: 1";
		TextColor(12); gotoXY(67 + vitri, y); // Ghi chú
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 1) )
		{
			STCLT[vitri] = char(key);
			STCLT[vitri] = toupper(STCLT[vitri]);
			cout << STCLT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67 + vitri, y);
			cout << " ";
			gotoXY(67 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			STCLT[vitri] = '\0';
			mh.STCLT = atoi(STCLT);
			vitri = 0;
			gotoXY(75 + vitri, y);
			goto STCTH;
		}
		if (key == ESC ) { return; }
	}
STCTH:
	while (1)
	{
		char STCTH[1];
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (0-9 & .). Toi da: 1";
		TextColor(12); gotoXY(75 + vitri, y); // Ghi chú
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 1) )
		{
			STCTH[vitri] = char(key);
			STCTH[vitri] = toupper(STCTH[vitri]);
			cout << STCTH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(75 + vitri, y);
			cout << " ";
			gotoXY(75 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			STCTH[vitri] = '\0';
			mh.STCTH = atoi(STCTH);
			Insert_NodeMH(npmh,mh);
			GhiChu("Them Mon Hoc Thanh Cong", 35, 27, 79, 1000);			
			return;
		}
		if (key == ESC ) { return; }
	}

}


void MH_Xoa(NODEPTR_MONHOC &npmh, DSLTC &dsltc)
{
	int key;
	int x = 33, y = 14;
	
	int checkMMH, vitri = 0;
	char MaMH[10];
	int check_MaMHLTC;
	MonHoc_KhungNhapMaMHXoa();
	gotoXY(x, y);
QuayLai:
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			MaMH[vitri] = char(key);
			MaMH[vitri] = toupper(MaMH[vitri]);
			cout << MaMH[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			MaMH[vitri] = '\0';			
			checkMMH = MH_CheckTrungMMH(npmh, MaMH);
			check_MaMHLTC = Check_MaMH_LTC(dsltc, MaMH);
			if (checkMMH == -1) {
				GhiChu("MA MON HOC KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				continue;
			}
			else {
				
				if(check_MaMHLTC != -1)
				{
					GhiChu("KHONG THE XOA VI MON HOC DA MO LOP TIN CHI!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					continue;
				}
				else
				{
					MH_XoaNode(npmh, MaMH);
					GhiChu("XOA THANH CONG MON HOC!", 20, 27, 79, 2000);
					return;
				}
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ESC) {
			return;
		}
	}
}

void MH_Sua(NODEPTR_MONHOC &npmh, DSLTC &dsltc)
{
	int key, vitri = 0, x = 33, y = 14,  checkMMH;
	NODEPTR_MONHOC vt;
	char tam[10];
	MonHoc mh;	mh.MaMH[0] = NULL;	mh.TenMH[0] = NULL;	mh.STCLT = 0;	mh.STCTH = 0;
	MonHoc_KhungNhapMaMHSua(); gotoXY(x, y);
	//dau tien phai tim vi tri cua ma mon
	
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			mh.MaMH[vitri] = char(key);
			mh.MaMH[vitri] = toupper(mh.MaMH[vitri]);
			cout << mh.MaMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.MaMH[vitri] = '\0';	//Ngat chuoi~
			
			checkMMH = MH_CheckTrungMMH(npmh, mh.MaMH); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (checkMMH == 1) {
				
				MonHoc_KhungSua();
				x = 12, y = 14;
				gotoXY(x, y);
				TextColor(14);
				vt = MH_ThongTin(npmh, mh.MaMH);
				strcpy(mh.TenMH, vt->info.TenMH);
				mh.STCLT = vt->info.STCLT;
				mh.STCTH = vt->info.STCTH;
				gotoXY(13, y); cout << mh.TenMH;
				gotoXY(56, y); cout << mh.STCLT;
				gotoXY(64, y); cout << mh.STCTH;
				vitri = strlen(mh.TenMH);
				goto TENMH;
				break;
				
			}
			else {
				GhiChu("Ma Mon Hoc Khong Ton Tai!", 35, 27, 79, 500);	TextColor(12);	gotoXY(33 + vitri, y);
			}
		}
		if (key == ESC) { return; }
	}
	
TENMH:
	while (1)
	{
		TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 50";
		TextColor(14); gotoXY(13 + vitri, y); //Ghi chú
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			mh.TenMH[vitri] = char(key);
			mh.TenMH[vitri] = toupper(mh.TenMH[vitri]);
			cout << mh.TenMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(13 + vitri, y);
			cout << " ";
			gotoXY(13 + vitri, y);
		}
		if (key == SPACE && mh.TenMH[vitri - 1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(13 + vitri, y);
			cout << " ";
			mh.TenMH[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.TenMH[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TenMH[vitri] = '\0';
			vitri = 0;
			gotoXY(56 + vitri, y);
			goto STCLT;
		}
		
		if (key == ESC) { return; }
	}
	
STCLT:
	while (1)
	{
		TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (0-9). Toi da: 1         ";
		TextColor(14); gotoXY(56 + vitri, y); // Ghi chú
		key = GetKey();
		char STCLT[1];
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			STCLT[vitri] = char(key);
			STCLT[vitri] = toupper(STCLT[vitri]);
			cout << STCLT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(56 + vitri, y);
			cout << " ";
			gotoXY(56 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			STCLT[vitri] = '\0';
			mh.STCLT = atoi(STCLT);
			vitri = 0;
			goto STCTH;		
		}
		if (key == ESC) { return; }
	}
STCTH:
	while (1)
	{
		TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (0-9). Toi da: 1         ";
		TextColor(14); gotoXY(64 + vitri, y); // Ghi chú
		key = GetKey();
		char STCTH[1];
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			STCTH[vitri] = char(key);
			STCTH[vitri] = toupper(STCTH[vitri]);
			cout << STCTH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64 + vitri, y);
			cout << " ";
			gotoXY(64 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			STCTH[vitri] = '\0';
			mh.STCTH = atoi(STCTH);
			vt->info = mh;
			vitri = 0;
			GhiChu("Sua Thong Tin Thanh Cong!!!", 40, 27, 228, 2000);	TextColor(12);
			return;	
		}
		if (key == ESC) { return; }
	}
}

void SinhVien_Them(DSSV &ds, DSLTC &dsltc, char maLop[], DSXuLy &dsxl)
{
	
	int demdongthemSV = 30;
	XuLy xuly;
	xuly.Ma[0] = NULL;
	int k =0;

QUAYLAI:	
	int key, vitri = 0, x = 24, y = 11;
	SV sv;	
	SinhVien_KhungThem(); gotoXY(x, y);
	sv.MaLop[0] = NULL; sv.MaSV[0]= NULL; sv.Ho[0]= NULL; sv.Ten[0]= NULL; sv.Phai[0]= NULL; sv.SDT[0]= NULL;
	strcpy(sv.MaLop, maLop);
	gotoXY(0,0); cout << sv.MaLop;
	int checkTrungMSV;
MASV:
	while(1)
	{
		TextColor(250);	gotoXY(20, 13);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10 ki tu !!! Ket Thuc: Chuoi Rong";
		TextColor(12); gotoXY(24 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			sv.MaSV[vitri] = char(key);
			sv.MaSV[vitri] = toupper(sv.MaSV[vitri]);
			cout << sv.MaSV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24 + vitri, y);
			cout << " ";
			gotoXY(24 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (FullDSSV(ds)) { continue; }
			sv.MaSV[vitri] = '\0';
			checkTrungMSV = CheckTrungMSV(ds,sv.MaSV);
			if (checkTrungMSV != -1) {
				TextColor(78);	gotoXY(24, 12);
				cout << "Trung Ma Sinh Vien. Nhap Lai!";
				Sleep(2000);
				TextColor(225);	gotoXY(24, 12);
				cout << "                             ";
				continue;
			}
			vitri = 0;
			
			goto HO;
		}
		if (key == ENTER && vitri == 0 )
		{ 
			TextColor(78);	gotoXY(20, 12);
			cout << "                  Qua trinh nhap ket thuc!!!                   ";
			Sleep(2000);
		 	return;
		}
		if (key == ESC)		
		{
			return;
		}
	}
HO:
	while(1)
	{
		TextColor(250);	gotoXY(20, 13);
		cout << "Ki tu: (A-Z). Toi da: 11 ki tu                                 ";
		TextColor(12); gotoXY(40 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 11))
		{
			sv.Ho[vitri] = char(key);
			sv.Ho[vitri] = toupper(sv.Ho[vitri]);
			cout << sv.Ho[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		
		if (key == SPACE && sv.Ho[vitri - 1] != ' ' && vitri > 0 && vitri < 11) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(40 + vitri, y);
			cout << " ";
			sv.Ho[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (sv.Ho[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			sv.Ho[vitri] = '\0';
			vitri = 0;
			goto TEN;
		}
	}
TEN:
	while(1)
	{
		TextColor(250);	gotoXY(20, 13);
		cout << "Ki tu: (A-Z). Toi da: 6 ki tu                                  ";
		TextColor(12); gotoXY(54 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 6))
		{
			sv.Ten[vitri] = char(key);
			sv.Ten[vitri] = toupper(sv.Ten[vitri]);
			cout << sv.Ten[vitri];
			vitri++;
		}
		
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			
			sv.Ten[vitri] = '\0';
			vitri = 0;
			goto PHAI;
		}
	}
PHAI:
	while(1)
	{
		TextColor(250);	gotoXY(20, 13);
		cout << "Ki tu: (A-Z). Toi da: 3 ki tu (NAM/NU)                         ";
		TextColor(12); gotoXY(64 + vitri, y);
		key = GetKey();
		if ((key == 'n' || key == 'a' || key == 'm' || key == 'u' ||key == 'N' || key == 'A' || key == 'M' || key == 'U' ) && (vitri < 3))
		{
			sv.Phai[vitri] = char(key);
			sv.Phai[vitri] = toupper(sv.Phai[vitri]);
			cout << sv.Phai[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64 + vitri, y);
			cout << " ";
			gotoXY(64 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.Phai[vitri] = '\0';
			if ((strcmp(sv.Phai,"NAM") != 0 && strcmp(sv.Phai,"NU") != 0))
			{
				TextColor(78);	gotoXY(24, 12);
				cout << "Dinh dang khong dung. Nhap Lai!";
				Sleep(1000);
				TextColor(225);	gotoXY(24, 12);
				cout << "                               ";
				continue;
			}
			
			
			TextColor(78);	gotoXY(20, 0);
			
			vitri = 0;
			goto SDT;
		}
	}
SDT:
	while(1)
	{
		TextColor(250);	gotoXY(20, 13);
		cout << "Ki tu: (0-9). Toi da: 10 so                                ";
		TextColor(12); gotoXY(71 + vitri, y);
		key = GetKey();
		if (( (key >= '0' && key <= '9')) && (vitri < 10))
		{
			sv.SDT[vitri] = char(key);
			sv.SDT[vitri] = toupper(sv.SDT[vitri]);
			cout << sv.SDT[vitri];
			vitri++;
		}
		
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(71 + vitri, y);
			cout << " ";
			gotoXY(71 + vitri, y);
		}
		if (key == ENTER && vitri == 10)
		{
			
			sv.SDT[vitri] = '\0';
			
			Insert_SV(ds,sv);
		
			gotoXY(2, 29);
			TextColor(14);
			cout << "====THONG TIN CAC SINH VIEN DA DUOC THEM====";
			gotoXY(2, demdongthemSV);
			cout << " MaLop:" << sv.MaLop;
			cout << " MaSV:" << sv.MaSV;
			strcpy(dsxl.xuly[k].Ma, sv.MaSV);
			cout << " Ho:" << sv.Ho;
			cout << " Ten:" << sv.Ten;
			cout << " Phai:" << sv.Phai;
			cout << " SDT:" << sv.SDT;
			demdongthemSV++;
			k++;
			dsxl.n++;
			cout << " So luong xu ly:"<<dsxl.n;

			TextColor(78);	gotoXY(20, 12);
			cout << "                  Them sinh vien thanh cong!!!                 ";
			Sleep(1000);
			goto QUAYLAI;
			
		}
	}
}
void SinhVien_Sua(DSSV &ds, DSLTC &dsltc,DSSV ds1)
{
	
	int key;
	int x = 33, y = 14;
	int vitri = 0, checkMSV, vitriSV;
	char MaSVMuonSua[10];
	SV sv;
	sv.MaSV[0]= NULL; sv.Ho[0]= NULL; sv.Ten[0]= NULL; sv.Phai[0]= NULL; sv.SDT[0]= NULL;
	SinhVien_KhungNhapMaSVSua();
	gotoXY(x, y);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 11))
		{
			sv.MaSV[vitri] = char(key);
			sv.MaSV[vitri] = toupper(sv.MaSV[vitri]);
			cout << sv.MaSV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.MaSV[vitri] = '\0';	
			checkMSV = CheckTrungMSV(ds1, sv.MaSV);
			vitriSV = checkMSV;
			if (checkMSV != -1)
			{
				
				x = 12; y = 14;
				SinhVien_KhungSuaThongTin();
				strcpy(sv.MaLop, ds1.nodes[vitriSV].MaLop);
				strcpy(sv.MaSV, ds1.nodes[vitriSV].MaSV);
				strcpy(sv.Ho, ds1.nodes[vitriSV].Ho);
				strcpy(sv.Ten, ds1.nodes[vitriSV].Ten);
				strcpy(sv.Phai, ds1.nodes[vitriSV].Phai);
				strcpy(sv.SDT, ds1.nodes[vitriSV].SDT);
				TextColor(12);
				gotoXY(29, y); cout << sv.Ho;
				gotoXY(51, y); cout << sv.Ten;
				gotoXY(63, y); cout << sv.Phai;
				gotoXY(68, y); cout << sv.SDT;
			
				vitri = strlen(sv.Ho);
				goto HO;
				TextColor(14);
				
				 //Tra ve con tro? sinh vien da tim` thay'
			}
			else {
				GhiChu("Ma Sinh Vien Khong Ton Tai!", 35, 27, 79, 500);
				TextColor(14);	gotoXY(33 + vitri, y);
			}
		}
		if (key == ESC ) { return; }
	}
HO:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (A-Z). Toi da: 11";
		TextColor(14); gotoXY(29 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 11))
		{
			sv.Ho[vitri] = char(key);
			sv.Ho[vitri] = toupper(sv.Ho[vitri]);
			cout << sv.Ho[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29 + vitri, y);
			cout << " ";
			gotoXY(29 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (sv.Ho[vitri - 1] == ' ') { vitri--; }	
			sv.Ho[vitri] = '\0';
			vitri = strlen(sv.Ten);
			gotoXY(51 + vitri, y);
			goto TEN;
		}
		if (key == SPACE && sv.Ho[vitri - 1] != ' ' && vitri > 0 && vitri < 20)
		{
			gotoXY(29 + vitri, y);
			cout << " ";
			sv.Ho[vitri] = ' ';
			vitri++;
		}
		
		if (key == ESC ) { return; }
	}
TEN:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (A-Z). Toi da: 6                 ";
		TextColor(14);  gotoXY(51 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 6))
		{
			sv.Ten[vitri] = char(key);
			sv.Ten[vitri] = toupper(sv.Ten[vitri]);
			cout << sv.Ten[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(51 + vitri, y);
			cout << " ";
			gotoXY(51 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.Ten[vitri] = '\0';
			vitri = strlen(sv.Phai);
			gotoXY(63 + vitri, y);
			goto PHAI;
		}
		if (key == ESC) { return; }
	}	
PHAI:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (A-Z). Toi da: 3 ki tu (NAM/NU)             ";
		TextColor(14); gotoXY(63 + vitri, y);
		key = GetKey();
		if ((key == 'n' || key == 'a' || key == 'm' || key == 'u' ||key == 'N' || key == 'A' || key == 'M' || key == 'U' ) && (vitri < 3))
		{
			sv.Phai[vitri] = char(key);
			sv.Phai[vitri] = toupper(sv.Phai[vitri]);
			cout << sv.Phai[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(63 + vitri, y);
			cout << " ";
			gotoXY(63 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.Phai[vitri] = '\0';
			if ((strcmp(sv.Phai, "NAM") == 0) || (strcmp(sv.Phai, "NU") == 0))
			{
				vitri = strlen(sv.SDT);
				gotoXY(68 + vitri, y);
				goto SDT;
			}
			else
			{
				TextColor(78);	gotoXY(35, 27);
				cout << "Dinh dang khong dung. Nhap Lai!";
			}
		
		}

		if (key == ESC ) { return; }
	}
SDT:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (0-9). Toi da: 10 so             ";
		TextColor(14);	gotoXY(68 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 10))
		{
			sv.SDT[vitri] = char(key);
			sv.SDT[vitri] = toupper(sv.SDT[vitri]);
			cout << sv.SDT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(68 + vitri, y);
			cout << " ";
			gotoXY(68 + vitri, y);
		}
		if (key == ENTER && vitri == 10)
		{
			sv.SDT[vitri] = '\0';
			checkMSV = CheckTrungMSV(ds, sv.MaSV);
			vitriSV = checkMSV;
			strcpy(ds.nodes[vitriSV].Ho, sv.Ho);
			strcpy(ds.nodes[vitriSV].Ten, sv.Ten);
			strcpy(ds.nodes[vitriSV].Phai, sv.Phai);
			strcpy(ds.nodes[vitriSV].SDT, sv.SDT);
			SapXepDSSV(ds);
			GhiChu("SUA THONG TIN SV THANH CONG!!", 35, 27, 79, 1000);
			SinhVien_LuuFile(ds);
			return;
			
		}
		if (key == ESC) { return; }
	}

	
}


void SinhVien_Xoa(DSSV &ds, DSLTC &dsltc, DSSV ds1  )
{
	int key;
	int x = 33, y = 14;
	int vitri = 0, checkMSV;
	char MaSVMuonXoa[10];
	int check_SV_LTC;
	SinhVien_KhungNhapMaSVXoa();
	gotoXY(x, y);
Reset:
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			MaSVMuonXoa[vitri] = char(key);
			MaSVMuonXoa[vitri] = toupper(MaSVMuonXoa[vitri]);
			cout << MaSVMuonXoa[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			MaSVMuonXoa[vitri] = '\0';		
	
			checkMSV = CheckTrungMSV(ds1, MaSVMuonXoa);
			gotoXY(0,0); cout << checkMSV;	
			check_SV_LTC = Check_SV_LTC(dsltc, MaSVMuonXoa);

			if (checkMSV == -1) {
				GhiChu("MA SINH VIEN KHONG CO TRONG DANH SACH!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				continue;
			}
			else if ( check_SV_LTC != -1)
			{
				GhiChu("KHONG XOA DUOC VI SINH VIEN DA DANG KY LTC!!!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				continue;
			}
			else
			{
				XoaSV(ds, MaSVMuonXoa);
				GhiChu("XOA SINH VIEN THANH CONG!", 35, 27, 79, 2000);
				SinhVien_LuuFile(ds);
				gotoXY(33 + vitri, y);
				break;
			}
		}
		
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ESC || key == DELETE) {
			return;
		}
	}
}


void SinhVien_ThemXoaSuaDS(DSLTC &dsltc, DSSV &ds )
{
	DSXuLy dsxl;
	int key;
	int check_MaLop;
	int x = 40, y = 2, vitri = 0;
	
	SV sv;
	sv.MaLop[0] = NULL;
	SinhVien_KhungNhapMaLop();
	gotoXY(x, y); //Khoi tao rong~
				  //cai nay de tim ma lop
				  
	while (1)
	{
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			sv.MaLop[vitri] = char(key);
			sv.MaLop[vitri] = toupper(sv.MaLop[vitri]);
			cout << sv.MaLop[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			sv.MaLop[vitri] = '\0';
			TextColor(14);	system("cls");	break;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		if (key == ESC) { TextColor(14);	return; }
	}
	
	int trang = 0, tongtrang = 0;

	
	
	while(1)
	{
		system("cls");
		int tamp = 0;
		int soluongSV, dem = 0, demdong = 0;
		
		DSSV ds1;
		
		for ( int i = 0; i < ds.n; i++)
		{
			if (strcmp(ds.nodes[i].MaLop, sv.MaLop) == 0)
			{
				ds1.nodes[tamp] = ds.nodes[i];
				ds1.n++;
				tamp++;
			}
		}
		soluongSV = tamp;
		
		
		if (soluongSV < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongSV - 1) / 15 + 1);
		}
		SapXepDSSV(ds);
		SinhVien_KhungNhap();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongSV; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(12, 8 + demdong); cout << ds1.nodes[i].MaSV;
			gotoXY(27, 8 + demdong); cout << ds1.nodes[i].Ho;
			gotoXY(48, 8 + demdong); cout << ds1.nodes[i].Ten;
			gotoXY(60, 8 + demdong); cout << ds1.nodes[i].Phai;
			gotoXY(70, 8 + demdong); cout << ds1.nodes[i].SDT;		
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 73, 26);
		
	
		TextColor(236);
		gotoXY(43,3);
		cout<<sv.MaLop;
		TextColor(12);		gotoXY(81, 26); 
		TextColor(14); 
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT) && trang > 0) { trang--; }
		
		if (key == INSERT)
		{			
			
			SinhVien_Them(ds, dsltc, sv.MaLop, dsxl);
		}
		
		if (key == DLT)
		{
			SinhVien_Xoa(ds, dsltc, ds1);
		}
		
		if ( key == F4 )
		{
			SinhVien_Sua(ds, dsltc,ds1);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					SinhVien_LuuFile(ds);
					
					return;
			}
			if (tamp == 0) 
			{ 
				for ( int i = 0; i < dsxl.n; i++)
				{	
					if(CheckTrungMSV(ds, dsxl.xuly[i].Ma) != -1)
					{
						XoaSV(ds, dsxl.xuly[i].Ma);
					}
				}
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				return;
				
			}		
		}

		
		if(key==ESC) {
		system("cls");	 return;
		}
	}
}




void MH_ThemSuaXoaDS( DSLTC &dsltc, NODEPTR_MONHOC &npmh)
{
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongmh, dem = 0, demdong = 0;
	
	 
	while (1)
	{
		soluongmh = MH_SoLuongNode(npmh); 
		MH *mh = new MH[soluongmh];	 
		MH_DuyetNLR(npmh, mh, dem);
		SapXepMH(npmh, mh, dem); 
		if (soluongmh < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongmh - 1) / 15 + 1);
		}
		
	
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		MonHoc_KhungXuat();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongmh; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + demdong); cout << mh[i].MaMH;
			gotoXY(31, 8 + demdong); cout << mh[i].TenMH;
			gotoXY(72, 8 + demdong); cout << mh[i].STCLT;
			gotoXY(80, 8 + demdong); cout << mh[i].STCTH;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 73, 26);
		
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) 
		{ 
			trang++; 
		}
		if ((key == LEFT ) && trang > 0)
		{ 
		 	trang--;
		}
		
		if(key == F4)
		{
			MH_Sua(npmh,dsltc);
			MH_LuuFile(npmh);
		}
		
		if (key == INSERT)
		{			
			
			MH_Them(npmh, dsltc);
		}
		
		if(key == DLT)
		{
			MH_Xoa(npmh, dsltc);
			MH_LuuFile(npmh);
		}
		
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					MH_LuuFile(npmh);
					return;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				return;	
			}		
		}
		
		if(key == ESC)
		{
			return;
		}

	}
}

int Nhap_MSV_NienKhoa_HocKy(DSLTC dsltc, DSSV dssv, SVDKLTC &svdkltc, LTC &ltc)
{
	int x = 34, y = 2;
	int key;
	int vitri = 0;
	int checkMSV, checkNKHK; //kiem tra sinh vien
	svdkltc.MaSV[0] = NULL;
	DSDKLTC_KhungNhapMSV_HocKy_NienKhoa();

MASV:
	while (1) {
		TextColor(228); gotoXY(30, 3); cout << "                                      ";
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			svdkltc.MaSV[vitri] = char(key);
			svdkltc.MaSV[vitri] = toupper(svdkltc.MaSV[vitri]);
			cout << svdkltc.MaSV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			svdkltc.MaSV[vitri] = '\0';	
			checkMSV = CheckTrungMSV(dssv, svdkltc.MaSV); // ok co ton tai hay k
			if (checkMSV != -1) {
				vitri = 0;
				gotoXY(49 + vitri, y);
				goto NIENKHOA;
			}
			else{
				GhiChu("           MA SINH VIEN KHONG TON TAI !!!       ", 30, 4, 79, 500);
			}
		}
		if (key == ESC) { 	return -1; }
	}
NIENKHOA:
	while(1)
	{
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key <= '9' && key >= '0')) && (vitri < 9))
		{
			ltc.NienKhoa[vitri] = char(key);
			ltc.NienKhoa[vitri] = toupper(ltc.NienKhoa[vitri]);
			cout << ltc.NienKhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NienKhoa[0] - '0') * 1000 + (ltc.NienKhoa[1] - '0') * 100 + (ltc.NienKhoa[2] - '0') * 10 + (ltc.NienKhoa[3] - '0');
			int b = (ltc.NienKhoa[5] - '0') * 1000 + (ltc.NienKhoa[6] - '0') * 100 + (ltc.NienKhoa[7] - '0') * 10 + (ltc.NienKhoa[8] - '0');
			if (ltc.NienKhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
				continue;
			}
			else {
				ltc.NienKhoa[vitri] = '\0';
				vitri = 0;
				goto HOCKY;
			
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 700);
				gotoXY(49 + vitri, y);
				continue;
			}
		}
	
		if (key == ESC) { return -1; }
	}
HOCKY:
		while(1)
	{
		TextColor(14);
		gotoXY(65 + vitri, y);
		
		key = GetKey();
		char HocKy[1];
		if ((key >= '1' && key <= '3') && (vitri < 1))
		{
			HocKy[vitri] = char(key);
			HocKy[vitri] = toupper(HocKy[vitri]);
			cout << HocKy[vitri];
			ltc.HocKy = atoi(HocKy);
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(65 + vitri, y);
			cout << " ";
			gotoXY(65 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			HocKy[vitri] = '\0';	//Ngat chuoi~
			checkNKHK = LTC_CheckTrungNienKhoaHocKy(dsltc, ltc.NienKhoa, ltc.HocKy);
			if (checkNKHK != -1) {
				GhiChu("             DANG NHAP THANH CONG            ", 30, 4, 79, 700);
				system("cls");
				return checkMSV;		
			}
			else {
				GhiChu("             KHONG TON TAI LOP HOC           ", 30, 4, 79, 700);
				gotoXY(65 + vitri, y);
			}
		}
		if (key == ESC) {	return -1; }
	}
	
}

void DSSVDangKy_Xoa(DSLTC &dsltc, SVDKLTC svdk)
{
	int key;
	int x = 94, y = 32;
	int vitri = 0;
	char tamp[5];
	int vitriMaLTC;
	DSDKLTC_KhungXoa();
	gotoXY(x, y);
	
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
			tamp[vitri] = char(key);
			tamp[vitri] = toupper(tamp[vitri]);
			cout << tamp[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			tamp[vitri] = '\0';
			int MaLTC = atoi(tamp);
			vitriMaLTC = CheckTrungLTC(dsltc, MaLTC);	
			if(vitriMaLTC != -1)
			{
				if(XoaSVDK(dsltc, svdk.MaSV, vitriMaLTC) == 1)
				{
					GhiChu("XOA LOP TIN CHI THANH CONG!!!", 84, 34, 79, 2000);
					DSDK_LuuFile(dsltc);
					return;
				}
				else
				{
					GhiChu("LOP TIN CHI KHONG TON TAI SINH VIEN!!!", 80, 34, 79, 1000);
					gotoXY(94 + strlen(tamp), 32);
				}
				
			}
			else
			{
				GhiChu("KHONG TON TAI MA LOP TIN CHI NAY!!!", 80, 34, 79, 1000);
				gotoXY(94 + strlen(tamp), 32);	
			}
					
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(94 + vitri, y);
			cout << " ";
			gotoXY(94 + vitri, y);
		}
		if (key == ESC) {
			return;
		}
	}
	
}


void DSSVDangKy_LTC(DSLTC &dsltc, DSSV &dssv, NODEPTR_MONHOC npmh)
{
	SVDKLTC svdkltc;
	LTC ltc;
	NODEPTR_MONHOC  q;
	svdkltc.Diem = 0;
	int vitriSV = Nhap_MSV_NienKhoa_HocKy(dsltc, dssv, svdkltc, ltc);
	if (vitriSV == -1)
	{
		return;
	}
	int key, vitri = 0;
	
	int x = 34, y = 2;
	char tamp[5];
	int maLTC;
	int SLConLai, SLDaDK = 0;
	int demSL = 0;
	TextColor(14);
	
QUAYLAI1:
	vitri = 0;
	system("cls");
	DSLTC dstamp;
	DSLTC dsltc_DaDK;
	ArrTampLTC(dsltc, dstamp, ltc.NienKhoa, ltc.HocKy);
	gotoXY(0, 0); cout << "MA SV : " << svdkltc.MaSV;
	gotoXY(0, 1); cout << "HO TEN: " << dssv.nodes[vitriSV].Ho << " " << dssv.nodes[vitriSV].Ten;
	gotoXY(0, 2); cout << "Lop   : " << dssv.nodes[vitriSV].MaLop;
	gotoXY(0, 3); cout << "NIEN KHOA: " << ltc.NienKhoa;
	gotoXY(0, 4); cout << "HOC KY   : " << ltc.HocKy;
	DSDKLTC_KhungDangKy();
	DSDKLTC_KhungDanhSachDangKy();
	DSSVDK_KhungDangKyLTC();	
	TextColor(14);
	int dem = 0;
	
	for (int i = 0; i < dstamp.n; i++)
	{
		if( dstamp.node[i]->TrangThaiLop == 1)
		{
			gotoXY(7, 8 + dem); cout << dstamp.node[i]->MaLopTC;
			gotoXY(14, 8 + dem); cout << dstamp.node[i]->MaMH;
			q = MH_ThongTin(npmh, dstamp.node[i]->MaMH);
			gotoXY(28, 8 + dem); cout << q->info.TenMH;
			gotoXY(65, 8 + dem); cout << dstamp.node[i]->Nhom;
			gotoXY(73, 8 + dem); cout << SVDK_DemSLDK(dstamp.node[i]->DSSVDK);
			gotoXY(81, 8 + dem); cout << dstamp.node[i]->SoSVMax - SVDK_DemSLDK(dstamp.node[i]->DSSVDK);
			SLConLai =dstamp.node[i]->SoSVMax - SVDK_DemSLDK(dstamp.node[i]->DSSVDK);
			dem++;	
		}
			
	}
	dem = 0;
	
	for (int i = 0; i < dstamp.n; i++)
	{
		
		for (NODEPTR_DSSVDK p = dstamp.node[i]->DSSVDK; p != NULL ; p= p->next)
		{
			if(strcmp(p->info.MaSV, svdkltc.MaSV) == 0 )
			{
			gotoXY(7, 30 + dem); cout << dstamp.node[i]->MaLopTC << " ";			
			gotoXY(14, 30 + dem); cout << dstamp.node[i]->MaMH;
			q = MH_ThongTin(npmh, dstamp.node[i]->MaMH);
			gotoXY(28, 30 + dem); cout << q->info.TenMH << "    ";
			gotoXY(65, 30 + dem); cout << q->info.STCLT;
			gotoXY(74, 30 + dem); cout << q->info.STCTH;
			dsltc_DaDK.node[dsltc_DaDK.n] = new LopTinChi; 
			dsltc_DaDK.node[dsltc_DaDK.n] = dstamp.node[i];
			dsltc_DaDK.n++;
			dem++;
			}

		}
	}

	while(1)
	{
		
		gotoXY(97 + vitri, 12);
		key = GetKey();
		
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
		tamp[vitri] = char(key);
		tamp[vitri] = toupper(tamp[vitri]);
		cout << tamp[vitri];
		vitri++;
		}
		
		if (key == ENTER && vitri != 0)
		{
			
			tamp[vitri] = '\0';
			maLTC = atoi(tamp);
			int checkTrungMaTC = CheckTrungLTC(dstamp, maLTC);

			if(checkTrungMaTC == -1)
			{
				GhiChu("MA LOP TIN CHI KHONG DUNG!", 93, 15, 79, 1500);
				continue;
			}
			int checkSVDK_LTC = checkSVDK_LTC1(dstamp, maLTC, svdkltc.MaSV);
			if(checkSVDK_LTC != -1)
			{
				GhiChu("SINH VIEN DA DANG KY MA LTC NAY!", 88, 14, 79, 1500);
				continue;
			}
			
			int checkSVDK_MH = checkSVDK_MH1(dsltc_DaDK, dstamp.node[checkTrungMaTC]->MaMH);
			if (checkSVDK_MH != -1)
			{
				GhiChu("DANG KY TRUNG MON HOC!!!", 88, 14, 79, 2000);

				continue;
			}
			if( SLConLai == 0)
			{
				GhiChu("DA HET SLOT!", 88, 14, 79, 1500);
				continue;
			}
		
			if (checkTrungMaTC != -1)
			{
				for(int i = 0; i < dsltc.n; i++)
				{	
					if( dsltc.node[i]->MaLopTC == maLTC)
					{
						Insert_Oder(dsltc.node[i]->DSSVDK,svdkltc);
						GhiChu("DANG KY THANH CONG!", 93, 15, 79, 2000);	
						goto QUAYLAI1;
					}
				}
			}
		}
		
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { goto QUAYLAI1; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					DSDK_LuuFile(dsltc);
					return;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				return;	
			}		

			
		}
		
		if(key == DLT)
		{
			DSSVDangKy_Xoa(dsltc, svdkltc);
			goto QUAYLAI1;
			
		}
		
		
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(97 + vitri, 12);
			cout << " ";
			gotoXY(97 + vitri, 12);
		}
		if(key == ESC)
		{
			return;
		}
	}
}

void XemDanhSachSVDK(DSLTC &dsltc, DSSV &dssv, NODEPTR_MONHOC npmh)
{
	int key;
	int x = 34, y = 2;
	int vitri = 0, vitriLTC;
	int SoLuongSVDK, demSL =0;
	int STT = 1;
	int dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	NODEPTR_MONHOC q;
	while(1)
	{
		if (dsltc.n < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((dsltc.n - 1) / 15 + 1);
		}
		
		system("cls");
		LTC_KhungXuatMH();
		DSDKLTC_MMH_NK_HK_Nhom();
		TextColor(236);
		TextColor(14);
		dem = 0, demdong = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < dsltc.n; i++)
		{
				TextColor(14);
				gotoXY(25, 12 + demdong); cout << dsltc.node[i]->MaMH;
				q = MH_ThongTin(npmh, dsltc.node[i]->MaMH);
				gotoXY(37, 12 + demdong); cout << q->info.TenMH;
				gotoXY(96, 12 + demdong); cout << dsltc.node[i]->Nhom;
				gotoXY(72, 12 + demdong); cout << dsltc.node[i]->NienKhoa;
				gotoXY(87, 12 + demdong); cout << dsltc.node[i]->HocKy;
	
				demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 73, 32);
		gotoXY(73, 32);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ENTER) {
			break;
		}
	}
	dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	DSDKLTC_MMH_NK_HK_Nhom();
	LopTinChi ltc;
	ltc.MaMH[0] = NULL; ltc.NienKhoa[0] = NULL;
	char HocKy[1], Nhom[3];
	HocKy[0] = NULL, Nhom[0] = NULL;
	gotoXY(x, y);
MaMH:
	while(1)
	{
		TextColor(228);
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MaMH[vitri] = char(key);
			ltc.MaMH[vitri] = toupper(ltc.MaMH[vitri]);
			cout << ltc.MaMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MaMH[vitri] = '\0';	//Ngat chuoi~
			int checkMaMH = Check_MaMH_LTC(dsltc, ltc.MaMH);
			if (checkMaMH != -1) {
				vitri = strlen(ltc.NienKhoa);
				gotoXY(49 + vitri, y);
				goto NIENKHOA;
			}
			else{
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				gotoXY(34 + vitri, y);
				continue;
			}
		}
		if (key == ESC) { 	return; }
	}
NIENKHOA:
	while(1) 
	{
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key >= '0' && key <= '9')) && (vitri < 9))
		{
			ltc.NienKhoa[vitri] = char(key);
			ltc.NienKhoa[vitri] = toupper(ltc.NienKhoa[vitri]);
			cout << ltc.NienKhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NienKhoa[0] - '0') * 1000 + (ltc.NienKhoa[1] - '0') * 100 + (ltc.NienKhoa[2] - '0') * 10 + (ltc.NienKhoa[3] - '0');
			int b = (ltc.NienKhoa[5] - '0') * 1000 + (ltc.NienKhoa[6] - '0') * 100 + (ltc.NienKhoa[7] - '0') * 10 + (ltc.NienKhoa[8] - '0');
			if (ltc.NienKhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 4, 79, 1000);
				continue;
			}
			else if (b - a != 1 ) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 35, 4, 79, 1000);
				continue;
			}
			else {
				ltc.NienKhoa[vitri] = '\0';
				vitri = 0;
				gotoXY(49 + vitri, y);
				goto HOCKY;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 1000);
				continue;
			}
		}
		if (key == ESC) {return; }
	}
HOCKY:
	while(1)
	{
		TextColor(228); 
		TextColor(14);
		gotoXY(66 + vitri, y);
		key = GetKey();
		if ((key >= '1' && key <='3') && (vitri < 1))
		{
			HocKy[vitri] = char(key);
			HocKy[vitri] = toupper(HocKy[vitri]);
			cout << HocKy[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(66 + vitri, y);
			cout << " ";
			gotoXY(66 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			HocKy[vitri] = '\0';	//Ngat chuoi~
			ltc.HocKy = atoi(HocKy);
			vitri = 0;
			goto NHOM;
		}
		if (key == ESC) {return; }
	}
NHOM:
	while (1) {
		TextColor(14);
		gotoXY(78 + vitri, y);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			Nhom[vitri] = toupper(Nhom[vitri]);
			cout << Nhom[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(78 + vitri, y);
			cout << " ";
			gotoXY(78 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';	//Ngat chuoi~
			ltc.Nhom = atoi(Nhom);
			int check4Field = LTC_CheckTrung4Field(dsltc, ltc.MaMH, ltc.NienKhoa, ltc.HocKy, ltc.Nhom);
			vitriLTC = check4Field;
			if (check4Field == -1) {
				GhiChu("         LOP TIN CHI NAY KHONG TON TAI     ", 35, 6, 79, 1000);
				vitri = strlen(ltc.MaMH);
				gotoXY(34 + vitri, y);
				goto MaMH;
			}
			else {
				GhiChu("         DANG NHAP THANH CONG     ", 40, 5, 79, 2000);
				break;
			}
		}
		if (key == ESC) { return; }
	}
	
	TextColor(14);

	SoLuongSVDK = DemSoLuongSVDK(dsltc, vitriLTC);
	SinhVien *sv = new SinhVien[SoLuongSVDK];
	SinhVien tamp;
	for(NODEPTR_DSSVDK p = dsltc.node[vitriLTC]->DSSVDK; p != NULL; p = p->next)
	{
		if (p->info.TrangThaiDK == 1)
		{
			tamp = ThongTinSV(dssv, p->info.MaSV);
			sv[demSL] = tamp;
			demSL++;
		}
	}
	
 	trang = 0, tongtrang = 0;
	dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv

	if (SoLuongSVDK < 15)
	{
		tongtrang = 1;
		trang = 0;
	}
	else {
		tongtrang = ((SoLuongSVDK - 1) / 15 + 1);
	}
	
	while(1)
	{
		TextColor(14);	system("cls");
		gotoXY(1, 0); cout << "MA MON HOC:" << ltc.MaMH;
		q = MH_ThongTin(npmh, ltc.MaMH);
		gotoXY(1, 1); cout << "TEN MON HOC:" << q->info.TenMH;
		gotoXY(1, 2); cout << "NIEN KHOA:" << ltc.NienKhoa;
		gotoXY(1, 3); cout << "HOC KI:" << ltc.HocKy;
		gotoXY(1, 4); cout << "NHOM:" << ltc.Nhom;
		DSDK_KhungXemSVDK();
		dem = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < SoLuongSVDK; i++)
		{
			TextColor(12); gotoXY(6, 10 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(11, 10 + dem); cout << sv[i].MaSV;
			gotoXY(27, 10 + dem); cout << sv[i].Ho;
			gotoXY(49, 10 + dem); cout << sv[i].Ten;
			gotoXY(61, 10 + dem); cout << sv[i].Phai;
			gotoXY(70, 10 + dem); cout << sv[i].SDT;
			dem++;
		}
		PhanTrang(trang + 1, tongtrang, 73, 26);
		gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT ) && trang > 0) { trang--; }
		if (key == ESC)
		{
			system("cls");	delete(sv); return;
		}
	}
}

void LTC_Them(DSLTC &dsltc, NODEPTR_MONHOC npmh, char NienKhoa[], int HocKy)
{
	
	int key, vitri = 0, x = 24, y = 33;
	LTC ltc;	
	LTC_KhungThem(); gotoXY(x, y);
	ltc.MaLopTC = 0; ltc.MaMH[0] = NULL; ltc.HocKy = HocKy; ltc.Nhom = 0; ltc.SoSVMax = 0; ltc.SoSVMin = 0; ltc.TrangThaiLop = 1;
	strcpy(ltc.NienKhoa, NienKhoa);
	int checkTrungMMH, checkTrungField;
MALTC:
	while (1)
	{
		TextColor(14);
		gotoXY(31 + vitri, y);
		ltc.MaLopTC = TangMaLTC(dsltc);
		gotoXY(14, 33); cout << ltc.MaLopTC;
		gotoXY(24 + vitri, y);
		
		goto MAMH;
	}
MAMH:
	while(1)
	{
		TextColor(250);
		gotoXY(19, 35); cout << "Ki tu so & chu: (A-Z) && (0-9). Toi da 10 ki tu!";
		TextColor(14);
		gotoXY(24 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MaMH[vitri] = char(key);
			ltc.MaMH[vitri] = toupper(ltc.MaMH[vitri]);
			cout << ltc.MaMH[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MaMH[vitri] = '\0';
			
			checkTrungMMH = MH_CheckTrungMMH(npmh, ltc.MaMH);
			if (checkTrungMMH == 1) {
				vitri = 0;
				gotoXY(41 + vitri, y);
				goto NHOM;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI!!!", 35, 36, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24 + vitri, y);
			cout << " ";
			gotoXY(24 + vitri, y);
		}
		if (key == ESC)
		{
			return;
		}
	}

NHOM:
	while(1)
	{
		TextColor(250);
		gotoXY(19, 35); cout << "Ki tu so: (1-4). Toi da 1 ki tu!                      ";
		TextColor(14);
		gotoXY(41 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char Nhom[3];
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			Nhom[vitri] = toupper(Nhom[vitri]);
			cout << Nhom[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';
			checkTrungField = LTC_CheckTrung4Field(dsltc, ltc.MaMH, ltc.NienKhoa, ltc.HocKy, atoi(Nhom));
			if (checkTrungField == -1) {
				vitri = 0;
				ltc.Nhom = atoi(Nhom);
				gotoXY(48 + vitri, y);
				goto SLMIN;
			}
			else {
				GhiChu("THONG TIN 4 FIELD MAMH, NIEN KHOA, HOC KY, NHOM KHONG DUOC TRUNG!!!", 20, 37, 79, 2000);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(41 + vitri, y);
			cout << " ";
			gotoXY(41 + vitri, y);
		}
		if (key == ESC )
		{
			return;
		}
	}
SLMIN:
	while(1)
	{
		TextColor(250);
		gotoXY(19, 35); cout << "Ki tu so : (0-9). Toi da 500 sinh vien!";
		TextColor(14);
		gotoXY(48 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char SLMin[3];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			SLMin[vitri] = char(key);
			SLMin[vitri] = toupper(SLMin[vitri]);
			cout << SLMin[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			SLMin[vitri] = '\0';
			ltc.SoSVMin = atoi(SLMin);
			vitri = 0;
			gotoXY(59 + vitri, y);
			goto SLMAX;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(48 + vitri, y);
			cout << " ";
			gotoXY(48 + vitri, y);
		}
		if (key == ESC)
		{
			return;
		}
	}
SLMAX:
	while(1)
	{
		TextColor(250);
		gotoXY(19, 35); cout << "Ki tu so : (0-9). Toi da 500 sinh vien!";
		TextColor(14);
		gotoXY(59 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char SLMAX[3];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			SLMAX[vitri] = char(key);
			SLMAX[vitri] = toupper(SLMAX[vitri]);
			cout << SLMAX[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.SoSVMax = atoi(SLMAX);
			if (ltc.SoSVMax <= ltc.SoSVMin) 
			{
				GhiChu("So luong sinh vien MAX >= So luong sinh vien Min", 35, 36, 79, 1000);
				vitri = 0;
				continue;
			}
			else
			{
				SLMAX[vitri] = '\0';
				Insert_LTC(dsltc, ltc);
				GhiChu("THEM LOP TIN CHI THANH CONG!!!", 40, 36, 228, 1000);
				return;
			}

		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(59 + vitri, y);
			cout << " ";
			gotoXY(59 + vitri, y);
		}
		if (key == ESC)
		{
			return;
		}
	}
	
}

void LTC_Xoa(DSLTC &dsltc, DSLTC dstamp ,NODEPTR_MONHOC npmh)
{
	int key;
	int x = 33, y = 14;
	int vitri = 0, checkMaLTC;
	char MaLTC[5];
	LTC_KhungXoa();
	gotoXY(x, y);
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
			MaLTC[vitri] = char(key);
			MaLTC[vitri] = toupper(MaLTC[vitri]);
			cout << MaLTC[vitri];
			
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			MaLTC[vitri] = '\0';
			int maltc = atoi(MaLTC);
			checkMaLTC = CheckTrungLTC(dstamp, maltc);
			if (checkMaLTC == -1) {
				GhiChu("MA LOP TIN CHI KHONG TON TAI!!!!", 35, 27, 79, 700);
				gotoXY(33 + vitri, y);
				continue;
			}
			else {
				if (dsltc.node[checkMaLTC]->DSSVDK != NULL) {
					GhiChu("LOP TIN CHI DA CO SINH VIEN. KHONG THE XOA!", 35, 27, 79, 700);
					gotoXY(33 + vitri, y);
					continue;
				}
				else
				{
					
					Xoa_LTC(dsltc, maltc);
					LTC_LuuFile(dsltc);	
					GhiChu("XOA THANH CONG LOP TIN CHI", 35, 27, 79, 2000);
					return;
				}

			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ESC ) {
			return;
		}
	}
}

void LTC_Sua(DSLTC &dsltc, DSLTC dstamp,NODEPTR_MONHOC npmh, char NienKhoa[], int HocKy)
{
	int key, vitri = 0, x = 33, y = 11;
	LTC ltc;	
	LTC_KhungNhapMaLTC(); gotoXY(33, 11);
	ltc.MaMH[0] = NULL; ltc.HocKy = HocKy; ltc.Nhom = 0; ltc.SoSVMax = 0; ltc.SoSVMin = 0; ltc.TrangThaiLop = 1;
	strcpy(ltc.NienKhoa, NienKhoa);
	int checkTrungMMH, checkTrung4Field;
	int checkTrungMaLTC, k;
	char MaLTC[5];
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
			MaLTC[vitri] = char(key);
			MaLTC[vitri] = toupper(MaLTC[vitri]);
			cout << MaLTC[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			MaLTC[vitri] = '\0';
			ltc.MaLopTC = atoi(MaLTC);
			checkTrungMaLTC = CheckTrungLTC(dstamp, ltc.MaLopTC);
			k = checkTrungMaLTC;
			if (checkTrungMaLTC == -1) {
				GhiChu("LOP TIN CHI KHONG TON TAI!!!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, 11);
				TextColor(14);
				continue;
			}
			else {
				vitri = 0;
				gotoXY(9, y);
				LTC_KhungSua();
				TextColor(14);
				
				ltc.MaLopTC = dstamp.node[k]->MaLopTC;
				strcpy(ltc.MaMH, dstamp.node[k]->MaMH);
				ltc.Nhom = dstamp.node[k]->Nhom;
				ltc.SoSVMin = dstamp.node[k]->SoSVMin;
				ltc.SoSVMax = dstamp.node[k]->SoSVMax;
				ltc.TrangThaiLop = dstamp.node[k]->TrangThaiLop;
				
				gotoXY(9, y); cout << ltc.MaLopTC;
				gotoXY(24, y); cout << ltc.MaMH;
				gotoXY(41, y); cout << ltc.NienKhoa;
				gotoXY(54, y); cout << ltc.HocKy;
				gotoXY(64, y); cout << ltc.Nhom;
				gotoXY(71, y); cout << ltc.SoSVMin;
				gotoXY(81, y); cout << ltc.SoSVMax;
				gotoXY(92, y); cout << ltc.TrangThaiLop;
				vitri = strlen(ltc.MaMH);
				goto MAMH;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, 11);
			cout << " ";
			gotoXY(33 + vitri, 11);
		}
		if (key == ESC)
		{
			return;
		}
	}
MAMH:
	while(1)
	{
		TextColor(250);
		gotoXY(15, 13); cout << "Ki tu so & chu: (A-Z) && (0-9). Toi da 10 ki tu! ";
		TextColor(14);
		gotoXY(24 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MaMH[vitri] = char(key);
			ltc.MaMH[vitri] = toupper(ltc.MaMH[vitri]);
			cout << ltc.MaMH[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MaMH[vitri] = '\0';
			checkTrungMMH = MH_CheckTrungMMH(npmh, ltc.MaMH);
			if (checkTrungMMH == 1) {
				char flag[10];
				vitri = strlen(itoa(ltc.Nhom, flag, 10));
				gotoXY(64 + vitri, y);
				goto NHOM;
			}
			else {
				GhiChu("MA MON HOC KHONG TON TAI!!", 35, 27, 79, 1000);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24 + vitri, y);
			cout << " ";
			gotoXY(24 + vitri, y);
		}
		if (key == ESC )
		{
			return;
		}
	}
NHOM:
	while (1)
	{
		TextColor(250);
		gotoXY(15, 13); cout << "Ki tu so: (1-4). Toi da 1 ki tu!                          ";
		TextColor(14);
		gotoXY(64 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char Nhom[3];
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			Nhom[vitri] = toupper(Nhom[vitri]);
			cout << Nhom[vitri];
			ltc.Nhom = atoi(Nhom);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';
			
			char flag[10];
			checkTrung4Field = LTC_CheckTrung4Field(dsltc, ltc.MaMH, ltc.NienKhoa, ltc.HocKy, ltc.Nhom);
			if (checkTrung4Field == -1) {
				vitri = strlen(itoa(ltc.SoSVMin, flag, 10));
				gotoXY(71 + vitri, y);
				goto SLMIN;
			}
			else {
				GhiChu("THONG TIN 4 FIELD MAMH, NIEN KHOA, HOC KY, NHOM KHONG DUOC TRUNG!!!", 20, 27, 79, 2000);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64 + vitri, y);
			cout << " ";
			gotoXY(64 + vitri, y);
		}
		if (key == ESC )
		{
			return;
		}
	}
SLMIN:
	while (1)
	{
		TextColor(250);
		gotoXY(15, 13); cout << "Ki tu so : (0-9). Toi da 999 sinh vien!";
		TextColor(14);
		gotoXY(71 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char SLMin[3];
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			SLMin[vitri] = char(key);
			SLMin[vitri] = toupper(SLMin[vitri]);
			cout << SLMin[vitri];
			ltc.SoSVMin = atoi(SLMin);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			SLMin[vitri] = '\0';
			char flag[10];
			vitri = strlen(itoa(ltc.SoSVMax, flag, 10));
			gotoXY(81 + vitri, y);
			goto SLMAX;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(71 + vitri, y);
			cout << " ";
			gotoXY(71 + vitri, y);
		}
		
		if (key == ESC)
		{
			return;
		}
	}
SLMAX:
	while (1)
	{
		TextColor(250);
		gotoXY(15, 13); cout << "Ki tu so : (0-9). Toi da 999 sinh vien!";
		TextColor(14);
		gotoXY(81 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char SLMax[3];
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			SLMax[vitri] = char(key);
			SLMax[vitri] = toupper(SLMax[vitri]);
			cout << SLMax[vitri];
			ltc.SoSVMax = atoi(SLMax);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			SLMax[vitri] = '\0';
			if (ltc.SoSVMin >= ltc.SoSVMax) {
				GhiChu("SO SV MAX PHAI LON HON SO SV MIN!!!", 35, 27, 79, 1000);
				vitri = 0;
				continue;
			}
			else {						
				vitri = 1;
				goto TRANGTHAILOP;
				
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(81 + vitri, y);
			cout << " ";
			gotoXY(81 + vitri, y);
		}
		if (key == ESC)
		{
			return;
		}
	}
TRANGTHAILOP:
	while(1)
	{
		TextColor(250);
		gotoXY(15, 13); cout << "Ki tu so : (0-1). 0: Huy | 1: Duoc Mo!!!";
		TextColor(14);
		gotoXY(92 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char TrangThaiLop[1];
		if ((key >= '0' && key <= '1') && (vitri < 1))
		{
			TrangThaiLop[vitri] = char(key);
			TrangThaiLop[vitri] = toupper(TrangThaiLop[vitri]);
			cout << TrangThaiLop[vitri];
			ltc.TrangThaiLop = atoi(TrangThaiLop);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{	
			TrangThaiLop[vitri] = '\0'; // cai nay de ngat chuoi, chuyen sang ben phai hoac trai nhap tiep
			checkTrungMaLTC = CheckTrungLTC(dsltc, ltc.MaLopTC);
			k = checkTrungMaLTC;
			dsltc.node[k]->MaLopTC = ltc.MaLopTC;
			strcpy(dsltc.node[k]->MaMH, ltc.MaMH);
			strcpy(dsltc.node[k]->NienKhoa, ltc.NienKhoa);	
			dsltc.node[k]->HocKy = ltc.HocKy;
			dsltc.node[k]->Nhom = ltc.Nhom;
			dsltc.node[k]->SoSVMin = ltc.SoSVMin;
			dsltc.node[k]->SoSVMax = ltc.SoSVMax;
			dsltc.node[k]->TrangThaiLop = ltc.TrangThaiLop;
			for(NODEPTR_DSSVDK p = dsltc.node[k]->DSSVDK; p != NULL ; p = p->next)
			{
				p->info.TrangThaiDK = 1;
			}
			LTC_LuuFile(dsltc);	
			DSDK_LuuFile(dsltc);
			GhiChu("SUA THONG TIN LOP TIN CHI THANH CONG!!!!", 35, 27, 79, 2000);				
			return;
				
			
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(92 + vitri, y);
			cout << " ";
			gotoXY(92 + vitri, y);
		}
		if (key == ESC)
		{
			return;
		}
	}
}


void LTC_ThemSuaXoaDS(DSLTC &dsltc, NODEPTR_MONHOC npmh)
{
	
	system("cls");
	int x = 38, y = 2;
	int key;
	int vitri = 0;
	int checkNKHK; //kiem tra sinh vien
	LTC ltc;
	ltc.NienKhoa[0] = NULL;
	char HocKy[1];
	DSDKLTC_KhungNhap_NienKhoa_HocKy();
NIENKHOA:
	while(1)
	{
		TextColor(14);
		gotoXY(38 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key <= '9' && key >= '0')) && (vitri < 9))
		{
			ltc.NienKhoa[vitri] = char(key);
			ltc.NienKhoa[vitri] = toupper(ltc.NienKhoa[vitri]);
			cout << ltc.NienKhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(38 + vitri, y);
			cout << " ";
			gotoXY(38 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NienKhoa[0] - '0') * 1000 + (ltc.NienKhoa[1] - '0') * 100 + (ltc.NienKhoa[2] - '0') * 10 + (ltc.NienKhoa[3] - '0');
			int b = (ltc.NienKhoa[5] - '0') * 1000 + (ltc.NienKhoa[6] - '0') * 100 + (ltc.NienKhoa[7] - '0') * 10 + (ltc.NienKhoa[8] - '0');
			if (ltc.NienKhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
				continue;
			}
			else {
				ltc.NienKhoa[vitri] = '\0';
				vitri = 0;
				goto HOCKY;
			
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 700);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
	
		if (key == ESC) { return ; }
	}
HOCKY:
	while(1)
	{
		TextColor(14);
		gotoXY(54 + vitri, y);
		
		key = GetKey();
		char HocKy[1];
		if ((key >= '1' && key <= '3') && (vitri < 1))
		{
			HocKy[vitri] = char(key);
			HocKy[vitri] = toupper(HocKy[vitri]);
			cout << HocKy[vitri];
			ltc.HocKy = atoi(HocKy);
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			HocKy[vitri] = '\0';	//Ngat chuoi~

				GhiChu("             DANG NHAP THANH CONG            ", 30, 4, 79, 700);
				system("cls");
				break;		

		}
		if (key == ESC) {	return ; }
	}
	
	

	int dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	int SoLuongLTC;
	NODEPTR_MONHOC vt;
	
	
	while(1)
	{
		DSLTC dstamp;
		SoLuongLTC = dsltc.n;
		for(int i = 0; i < SoLuongLTC; i++)
		{
			if ((strcmp(dsltc.node[i]->NienKhoa, ltc.NienKhoa) == 0) && (dsltc.node[i]->HocKy == ltc.HocKy))
			{
				dstamp.node[dstamp.n] = new LopTinChi;
				dstamp.node[dstamp.n] = dsltc.node[i];
				dstamp.n++;
			}
		}
		
		
		if (dstamp.n < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((dstamp.n - 1) / 15 + 1);
		}
		
		system("cls");
		LTC_KhungXuat();
		TextColor(236);
		gotoXY(24, 3); cout << "  Nien Khoa: " << ltc.NienKhoa << " | Hoc Ky: " << ltc.HocKy << "  "; 
		TextColor(14);
		gotoXY(0,0); cout << " " << SoLuongLTC;
		dem = 0, demdong = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < dstamp.n; i++)
		{
				TextColor(14);
				gotoXY(7, 8 + demdong);  cout << dstamp.node[i]->MaLopTC;
				gotoXY(15, 8 + demdong); cout << dstamp.node[i]->MaMH;
				vt = MH_ThongTin(npmh, dstamp.node[i]->MaMH);
				gotoXY(26, 8 + demdong); cout << vt->info.TenMH;
				gotoXY(63, 8 + demdong); cout << dstamp.node[i]->Nhom;
				gotoXY(71, 8 + demdong); cout << dstamp.node[i]->SoSVMin;
				gotoXY(81, 8 + demdong); cout << dstamp.node[i]->SoSVMax;
				if(dstamp.node[i]->TrangThaiLop == 1)
				{
					gotoXY(89, 8 + demdong); cout << "Mo";
				}
				else
				{
					gotoXY(89, 8 + demdong); cout << "Huy";
				}
					
				demdong++;
		}
		

		PhanTrang(trang + 1, tongtrang, 73, 26);
		gotoXY(73, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		
		if(key == INSERT)
		{
			LTC_Them(dsltc, npmh, ltc.NienKhoa, ltc.HocKy);
		}
		
		if (key == F2)
		{
			
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { return; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					LTC_LuuFile(dsltc);
					return;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				return;	
			}		
		}
		
		if ( key == DLT)
		{
			LTC_Xoa(dsltc, dstamp, npmh);
		}
		
		if (key == F4)
		{
			LTC_Sua(dsltc, dstamp,npmh, ltc.NienKhoa, ltc.HocKy);
		}
		if ( key== ESC)
		{
			return;
		}
	}
}

void HuyLTC(DSLTC &dsltc, DSLTC &dstamp)
{
	int key;
	int x = 105, y = 14;
	int vitri = 0, checkMaLTC, vitriLTC;
	char MaLTC[5];
	LTC_KhungNhapMaLTCHuy();
	gotoXY(x, y);
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
			MaLTC[vitri] = char(key);
			MaLTC[vitri] = toupper(MaLTC[vitri]);
			cout << MaLTC[vitri];
			
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			MaLTC[vitri] = '\0';
			int maltc = atoi(MaLTC);
			checkMaLTC = CheckTrungLTC(dstamp, maltc);
			if (checkMaLTC == -1) {
				GhiChu("MA LOP TIN CHI KHONG TON TAI TRONG NIEN KHOA NAY!!!!", 35, 27, 79, 1500);
				gotoXY(105 + vitri, y);
				continue;
			}
			else
			{
				int tamp = ThongBao_HuyLTC();
				if (tamp == -1) { return; }
				if (tamp == 1) {
					vitriLTC = CheckTrungLTC(dsltc, maltc);
					dsltc.node[vitriLTC]->TrangThaiLop = 0;
					for(NODEPTR_DSSVDK p = dsltc.node[vitriLTC]->DSSVDK; p != NULL; p = p->next)
					{
						p->info.TrangThaiDK = 0;
					}
					GhiChu("HUY LOP TIN CHI THANH CONG!!!!", 35, 27, 79, 2000);
					return;
				}
				if (tamp == 0) 
				{ 
					GhiChu("HUY LOP TIN CHI KHONG THANH CONG!!!", 35, 27, 79, 2000);
					return;	
				}		
				
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(105 + vitri, y);
			cout << " ";
			gotoXY(105 + vitri, y);
		}
		if (key == ESC ) {
			return;
		}
	}
}



void LTC_Huy(DSLTC &dsltc, NODEPTR_MONHOC npmh)
{
	system("cls");
	int x = 38, y = 2;
	int key;
	int vitri = 0;
	int checkNKHK; //kiem tra sinh vien
	LTC ltc;
	ltc.NienKhoa[0] = NULL;
	char HocKy[1];
	DSDKLTC_KhungNhap_NienKhoa_HocKy();
NIENKHOA:
	while(1)
	{
		TextColor(14);
		gotoXY(38 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key <= '9' && key >= '0')) && (vitri < 9))
		{
			ltc.NienKhoa[vitri] = char(key);
			ltc.NienKhoa[vitri] = toupper(ltc.NienKhoa[vitri]);
			cout << ltc.NienKhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(38 + vitri, y);
			cout << " ";
			gotoXY(38 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NienKhoa[0] - '0') * 1000 + (ltc.NienKhoa[1] - '0') * 100 + (ltc.NienKhoa[2] - '0') * 10 + (ltc.NienKhoa[3] - '0');
			int b = (ltc.NienKhoa[5] - '0') * 1000 + (ltc.NienKhoa[6] - '0') * 100 + (ltc.NienKhoa[7] - '0') * 10 + (ltc.NienKhoa[8] - '0');
			if (ltc.NienKhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
				continue;
			}
			else {
				ltc.NienKhoa[vitri] = '\0';
				vitri = 0;
				goto HOCKY;
			
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 700);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
	
		if (key == ESC) { return ; }
	}
HOCKY:
	while(1)
	{
		TextColor(14);
		gotoXY(54 + vitri, y);
		
		key = GetKey();
		char HocKy[1];
		if ((key >= '1' && key <= '3') && (vitri < 1))
		{
			HocKy[vitri] = char(key);
			HocKy[vitri] = toupper(HocKy[vitri]);
			cout << HocKy[vitri];
			ltc.HocKy = atoi(HocKy);
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			HocKy[vitri] = '\0';	//Ngat chuoi~
			checkNKHK = LTC_CheckTrungNienKhoaHocKy(dsltc, ltc.NienKhoa, ltc.HocKy);
			if (checkNKHK != -1) {
				GhiChu("             DANG NHAP THANH CONG            ", 30, 4, 79, 700);
				system("cls");
				break;		
			}
			else {
				GhiChu("             KHONG TON TAI LOP HOC           ", 30, 4, 79, 700);
				gotoXY(54 + vitri, y);
			}
		}
		if (key == ESC) {	return ; }
	}
	

	while(1)
	{
		system("cls");
		TextColor(236);
		gotoXY(24, 3); cout << "  Nien Khoa: " << ltc.NienKhoa << " | Hoc Ky: " << ltc.HocKy << "  "; 
		TextColor(14);
		LTC_KhungHuy();
		DSLTC dstamp;
		ArrTampLTC(dsltc, dstamp, ltc.NienKhoa, ltc.HocKy);
		int dem = 0;
		int demdong = 0, trang = 0, tongtrang = 0;
		NODEPTR_MONHOC q;
		

		int SoLuongLTC = dstamp.n;
			
		if (SoLuongLTC < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((SoLuongLTC - 1) / 15 + 1);
		}
		
		for (int i = trang * 15; i < 15 + trang * 15 && i < SoLuongLTC; i++)
		{	 
			int SoLuongSVDaDK = SVDK_DemSLDK(dstamp.node[i]->DSSVDK);
			if( (dstamp.node[i]->TrangThaiLop == 1) && (SoLuongSVDaDK < dstamp.node[i]->SoSVMin))
			{
				gotoXY(7, 8 + dem); cout << dstamp.node[i]->MaLopTC;
				gotoXY(14, 8 + dem); cout << dstamp.node[i]->MaMH;
				q = MH_ThongTin(npmh, dstamp.node[i]->MaMH);
				gotoXY(25, 8 + dem); cout << q->info.TenMH;
				gotoXY(63, 8 + dem); cout << dstamp.node[i]->Nhom;
				gotoXY(71, 8 + dem); cout << dstamp.node[i]->SoSVMin;
				gotoXY(81, 8 + dem); cout << dstamp.node[i]->SoSVMax;
				gotoXY(91, 8 + dem); cout << SoLuongSVDaDK;
				dem++;	
			}
		}
		PhanTrang(trang + 1, tongtrang, 73, 26);
		gotoXY(84, 26);
		
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if ( key == ESC ) {return;}
		if ( key == DLT) 
		{
			HuyLTC(dsltc, dstamp);
		}
		
		if (key == F2)
		{
			
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					LTC_LuuFile(dsltc);
					DSDK_LuuFile(dsltc);
					return;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				return;	
			}		
		}
		
	}
	
}

void LTC_NhapDiem(DSLTC &dsltc, DSSV &dssv ,NODEPTR_MONHOC npmh)
{
	int key;
	int x = 34, y = 2;
	int vitri = 0, vitriLTC;
	int SoLuongSVDK, demSL =0;
	int STT = 1;
	
	int dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	NODEPTR_MONHOC q;
	while(1)
	{
		if (dsltc.n < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((dsltc.n - 1) / 15 + 1);
		}
		
		system("cls");
		LTC_KhungXuatMH();
		DSDKLTC_MMH_NK_HK_Nhom();
		TextColor(236);
		TextColor(14);
		dem = 0, demdong = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < dsltc.n; i++)
		{
				TextColor(14);
				gotoXY(25, 12 + demdong); cout << dsltc.node[i]->MaMH;
				q = MH_ThongTin(npmh, dsltc.node[i]->MaMH);
				gotoXY(37, 12 + demdong); cout << q->info.TenMH;
				gotoXY(96, 12 + demdong); cout << dsltc.node[i]->Nhom;
				gotoXY(72, 12 + demdong); cout << dsltc.node[i]->NienKhoa;
				gotoXY(87, 12 + demdong); cout << dsltc.node[i]->HocKy;
	
				demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 73, 32);
		gotoXY(73, 32);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ENTER) {
			break;
		}
	}
	
	dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	
	LopTinChi ltc;
	ltc.MaMH[0] = NULL; ltc.NienKhoa[0] = NULL;
	char HocKy[1], Nhom[3];
	HocKy[0] = NULL, Nhom[0] = NULL;
	
	DSDKLTC_MMH_NK_HK_Nhom();
	gotoXY(x, y);
	TextColor(244);
	gotoXY(30, 0);		cout << "       NHAP THONG TIN DE NHAP DIEM CHO SINH VIEN           ";
MaMH:
	while(1)
	{
		TextColor(228);
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MaMH[vitri] = char(key);
			ltc.MaMH[vitri] = toupper(ltc.MaMH[vitri]);
			cout << ltc.MaMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MaMH[vitri] = '\0';	//Ngat chuoi~
			int checkMaMH = Check_MaMH_LTC(dsltc, ltc.MaMH);
			if (checkMaMH != -1) {
				vitri = strlen(ltc.NienKhoa);
				gotoXY(49 + vitri, y);
				goto NIENKHOA;
			}
			else{
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				gotoXY(34 + vitri, y);
				continue;
			}
		}
		if (key == ESC) { 	return; }
	}
NIENKHOA:
	while(1) 
	{
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key >= '0' && key <= '9')) && (vitri < 9))
		{
			ltc.NienKhoa[vitri] = char(key);
			ltc.NienKhoa[vitri] = toupper(ltc.NienKhoa[vitri]);
			cout << ltc.NienKhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NienKhoa[0] - '0') * 1000 + (ltc.NienKhoa[1] - '0') * 100 + (ltc.NienKhoa[2] - '0') * 10 + (ltc.NienKhoa[3] - '0');
			int b = (ltc.NienKhoa[5] - '0') * 1000 + (ltc.NienKhoa[6] - '0') * 100 + (ltc.NienKhoa[7] - '0') * 10 + (ltc.NienKhoa[8] - '0');
			if (ltc.NienKhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 4, 79, 1000);
				continue;
			}
			else if (b - a != 1 ) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 35, 4, 79, 1000);
				continue;
			}
			else {
				ltc.NienKhoa[vitri] = '\0';
				vitri = 0;
				gotoXY(49 + vitri, y);
				goto HOCKY;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 1000);
				continue;
			}
		}
		if (key == ESC) {return; }
	}
HOCKY:
	while(1)
	{
		TextColor(228); 
		TextColor(14);
		gotoXY(66 + vitri, y);
		key = GetKey();
		if ((key >= '1' && key <='3') && (vitri < 1))
		{
			HocKy[vitri] = char(key);
			HocKy[vitri] = toupper(HocKy[vitri]);
			cout << HocKy[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(66 + vitri, y);
			cout << " ";
			gotoXY(66 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			HocKy[vitri] = '\0';	//Ngat chuoi~
			ltc.HocKy = atoi(HocKy);
			vitri = 0;
			goto NHOM;
		}
		if (key == ESC) {return; }
	}
NHOM:
	while (1) {
		TextColor(14);
		gotoXY(78 + vitri, y);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			Nhom[vitri] = toupper(Nhom[vitri]);
			cout << Nhom[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(78 + vitri, y);
			cout << " ";
			gotoXY(78 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';	//Ngat chuoi~
			ltc.Nhom = atoi(Nhom);
			int check4Field = LTC_CheckTrung4Field(dsltc, ltc.MaMH, ltc.NienKhoa, ltc.HocKy, ltc.Nhom);
			vitriLTC = check4Field;
						
			if (check4Field == -1) {
				GhiChu("         LOP TIN CHI NAY KHONG TON TAI     ", 35, 6, 79, 1000);
				vitri = strlen(ltc.MaMH);
				gotoXY(34 + vitri, y);
				goto MaMH;
			}			
			else {
				break;
			}
		}
		if (key == ESC) { return; }
	}
	TextColor(14);

	SoLuongSVDK = DemSoLuongSVDK(dsltc, vitriLTC);
	if (SoLuongSVDK == 0)
	{
		GhiChu("         LOP TIN CHI NAY CHUA CO SINH VIEN DK!!!     ", 35, 6, 79, 1000);
		vitri = strlen(ltc.MaMH);
		gotoXY(34 + vitri, y);
		goto MaMH;
	}
	else
	{
		GhiChu("         DANG NHAP THANH CONG     ", 40, 5, 79, 2000);
	}
	SinhVien *sv = new SinhVien[SoLuongSVDK];
	SVDKLTC *svdk = new SinhVienDKLTC[SoLuongSVDK];
	SinhVien tamp;
	for(NODEPTR_DSSVDK p = dsltc.node[vitriLTC]->DSSVDK; p != NULL; p = p->next)
	{
		if (p->info.TrangThaiDK == 1)
		{
			tamp = ThongTinSV(dssv, p->info.MaSV);
			sv[demSL] = tamp;
			svdk[demSL] = p->info;			
			demSL++;
		}
	}

	trang = 0, tongtrang = 0;
	dem = 0;	

	if (SoLuongSVDK < 15)
	{
		tongtrang = 1;
		trang = 0;
	}
	else {
		tongtrang = ((SoLuongSVDK - 1) / 15 + 1);
	}
	
	while(1)
	{
		TextColor(14);	system("cls");
		
		gotoXY(0, 0); cout << "MA MON HOC:" << ltc.MaMH;
		q = MH_ThongTin(npmh, ltc.MaMH);
		gotoXY(0, 1); cout << "TEN MON HOC:" << q->info.TenMH;
		gotoXY(0, 2); cout << "NIEN KHOA:" << ltc.NienKhoa;
		gotoXY(0, 3); cout << "HOC KI:" << ltc.HocKy;
		gotoXY(0, 4); cout << "NHOM:" << ltc.Nhom;
		DSDK_KhungNhapDiem();
		dem = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < SoLuongSVDK; i++)
		{
			TextColor(12); gotoXY(6, 11 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(12, 11 + dem); cout << sv[i].MaSV;
			gotoXY(28, 11 + dem); cout << sv[i].Ho;
			gotoXY(50, 11 + dem); cout << sv[i].Ten;
			gotoXY(60, 11 + dem); cout << svdk[i].Diem;
			dem++;
		}
		PhanTrang(trang + 1, tongtrang, 50, 27);
		gotoXY(60, 27);
		

		if ((key == RIGHT) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT ) && trang > 0) { trang--; }

		char flag[2];	
		int demsl = 0, dem1 = 0, check = 0;
		vitri = strlen(itoa(svdk[demsl].Diem, flag, 10));
		x = 60, y = 11;
		char Diem[2];
		
		while(1)
		{
			
			
			TextColor(252);				//Chu thich
			gotoXY(15, 28); cout << " DIEM SINH VIEN: TU 1 -> 10 DIEM.            ";
			gotoXY(15, 29); cout << " CHU Y: F2 DE LUU SAU KHI NHAP DIEM XONG !!! ";
			TextColor(14);
			gotoXY(60 + vitri, y);
			key = GetKey();	
			
			if ((key >= '0' && key <= '9')  && (vitri < 2))
			{
				Diem[vitri] = char(key);
				Diem[vitri] = toupper(Diem[vitri]);
				cout << Diem[vitri];
				vitri++;
				check = 1;
			}
			if (key == ENTER && vitri != 0)
			{
				Diem[vitri] = '\0';	
				if ( check == 0)
				{
					itoa(svdk[demsl].Diem, Diem, 10);
				}
				else
				{
					svdk[demsl].Diem = atoi(Diem);
					check = 0;
				}
				
				
				if(svdk[demsl].Diem > 10)
				{
					GhiChu("DIEM SINH VIEN KHONG DUOC LON HON 10 !!!", 70, 23, 14, 1500);
					continue;
				}
				y++;
				demsl++;
				char flag[2];	
				vitri = strlen(itoa(svdk[demsl].Diem, flag, 10));
				gotoXY(60 + vitri, y);
				if(SoLuongSVDK == demsl)
				{
					GhiChu("BAN DA NHAP DU DIEM SINH VIEN CHO TRANG NAY!!!", 70, 23, 14, 1500);
					goto LUU;
				}
			}
			if (key == UP && demsl != 0)
			{
				if(check == 1)
				{
					svdk[demsl].Diem = atoi(Diem);
					check == 0;
				}
				y--;
				demsl--;
				char flag[2];		
				vitri = strlen(itoa(svdk[demsl].Diem, flag, 10));
				itoa(svdk[demsl].Diem, Diem, 10);
				gotoXY(60 + vitri, y);
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(60 + vitri, y);
				cout << " ";
				gotoXY(60 + vitri, y);
			}
			if(key == F2)
			{
			LUU:
				int tamp = ThongBao_LuuFile();
				if (tamp == -1) { continue; }
				if (tamp == 1) {
					demsl = 0;
					for(NODEPTR_DSSVDK p = dsltc.node[vitriLTC]->DSSVDK; p != NULL; p = p->next)
					{
						p->info.Diem = svdk[demsl].Diem;
						demsl++;
					}	
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 3000);
					DSDK_LuuFile(dsltc);
					break;
				}
				if (tamp == 0) 
				{ 
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
					return;
				}		
			}

			if (key == ESC)
			{
				system("cls");	delete(sv); delete(svdk); return;
			}
		}

		
	}
}


void LTC_XemDiem(DSLTC &dsltc, DSSV &dssv ,NODEPTR_MONHOC npmh)
{
	int key;
	int x = 34, y = 2;
	int vitri = 0, vitriLTC;
	int SoLuongSVDK, demSL =0;
	int STT = 1;
	int dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	NODEPTR_MONHOC q;
	while(1)
	{
		if (dsltc.n < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((dsltc.n - 1) / 15 + 1);
		}
		
		system("cls");
		LTC_KhungXuatMH();
		DSDKLTC_MMH_NK_HK_Nhom();
		TextColor(236);
		TextColor(14);
		dem = 0, demdong = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < dsltc.n; i++)
		{
				TextColor(14);
				gotoXY(25, 12 + demdong); cout << dsltc.node[i]->MaMH;
				q = MH_ThongTin(npmh, dsltc.node[i]->MaMH);
				gotoXY(37, 12 + demdong); cout << q->info.TenMH;
				gotoXY(96, 12 + demdong); cout << dsltc.node[i]->Nhom;
				gotoXY(72, 12 + demdong); cout << dsltc.node[i]->NienKhoa;
				gotoXY(87, 12 + demdong); cout << dsltc.node[i]->HocKy;
	
				demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 73, 32);
		gotoXY(73, 32);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ENTER) {
			break;
		}
	}
	
	dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	LopTinChi ltc;
	ltc.MaMH[0] = NULL; ltc.NienKhoa[0] = NULL;
	char HocKy[1], Nhom[3];
	HocKy[0] = NULL, Nhom[0] = NULL;
	DSDKLTC_MMH_NK_HK_Nhom();
	gotoXY(x, y);
	TextColor(244);
	gotoXY(30, 0);		cout << "       NHAP THONG TIN DE NHAP DIEM CHO SINH VIEN           ";
MaMH:
	while(1)
	{
		TextColor(228);
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MaMH[vitri] = char(key);
			ltc.MaMH[vitri] = toupper(ltc.MaMH[vitri]);
			cout << ltc.MaMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MaMH[vitri] = '\0';	//Ngat chuoi~
			int checkMaMH = Check_MaMH_LTC(dsltc, ltc.MaMH);
			if (checkMaMH != -1) {
				vitri = strlen(ltc.NienKhoa);
				gotoXY(49 + vitri, y);
				goto NIENKHOA;
			}
			else{
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				gotoXY(34 + vitri, y);
				continue;
			}
		}
		if (key == ESC) { 	return; }
	}
NIENKHOA:
	while(1) 
	{
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key >= '0' && key <= '9')) && (vitri < 9))
		{
			ltc.NienKhoa[vitri] = char(key);
			ltc.NienKhoa[vitri] = toupper(ltc.NienKhoa[vitri]);
			cout << ltc.NienKhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NienKhoa[0] - '0') * 1000 + (ltc.NienKhoa[1] - '0') * 100 + (ltc.NienKhoa[2] - '0') * 10 + (ltc.NienKhoa[3] - '0');
			int b = (ltc.NienKhoa[5] - '0') * 1000 + (ltc.NienKhoa[6] - '0') * 100 + (ltc.NienKhoa[7] - '0') * 10 + (ltc.NienKhoa[8] - '0');
			if (ltc.NienKhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 4, 79, 1000);
				continue;
			}
			else if (b - a != 1 ) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 35, 4, 79, 1000);
				continue;
			}
			else {
				ltc.NienKhoa[vitri] = '\0';
				vitri = 0;
				gotoXY(49 + vitri, y);
				goto HOCKY;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 1000);
				continue;
			}
		}
		if (key == ESC) {return; }
	}
HOCKY:
	while(1)
	{
		TextColor(228); 
		TextColor(14);
		gotoXY(66 + vitri, y);
		key = GetKey();
		if ((key >= '1' && key <='3') && (vitri < 1))
		{
			HocKy[vitri] = char(key);
			HocKy[vitri] = toupper(HocKy[vitri]);
			cout << HocKy[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(66 + vitri, y);
			cout << " ";
			gotoXY(66 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			HocKy[vitri] = '\0';	//Ngat chuoi~
			ltc.HocKy = atoi(HocKy);
			vitri = 0;
			goto NHOM;
		}
		if (key == ESC) {return; }
	}
NHOM:
	while (1) {
		TextColor(14);
		gotoXY(78 + vitri, y);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			Nhom[vitri] = toupper(Nhom[vitri]);
			cout << Nhom[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(78 + vitri, y);
			cout << " ";
			gotoXY(78 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';	//Ngat chuoi~
			ltc.Nhom = atoi(Nhom);
			int check4Field = LTC_CheckTrung4Field(dsltc, ltc.MaMH, ltc.NienKhoa, ltc.HocKy, ltc.Nhom);
			vitriLTC = check4Field;
			if (check4Field == -1) {
				GhiChu("         LOP TIN CHI NAY KHONG TON TAI     ", 35, 6, 79, 1000);
				vitri = strlen(ltc.MaMH);
				gotoXY(34 + vitri, y);
				goto MaMH;
			}
			else {
				GhiChu("         DANG NHAP THANH CONG     ", 40, 5, 79, 2000);
				break;
			}
		}
		if (key == ESC) { return; }
	}
	TextColor(14);

	SoLuongSVDK = DemSoLuongSVDK(dsltc, vitriLTC);
	SinhVien *sv = new SinhVien[SoLuongSVDK];
	SVDKLTC *svdk = new SinhVienDKLTC[SoLuongSVDK];
	SinhVien tamp;
		for(NODEPTR_DSSVDK p = dsltc.node[vitriLTC]->DSSVDK; p != NULL; p = p->next)
		{
			if (p->info.TrangThaiDK == 1)
			{
				tamp = ThongTinSV(dssv, p->info.MaSV);
				sv[demSL] = tamp;
				svdk[demSL] = p->info;			
				demSL++;
			}
		}

	trang = 0, tongtrang = 0;
	dem = 0;	

	if (SoLuongSVDK < 15)
	{
		tongtrang = 1;
		trang = 0;
	}
	else {
		tongtrang = ((SoLuongSVDK - 1) / 15 + 1);
	}
	
	while(1)
	{
		
		system("cls");
		DSDK_KhungNhapDiem();
		TextColor(236);	gotoXY(33, 3);	cout << "                              ";
		gotoXY(33, 4);	cout << "    DANH SACH DIEM SINH VIEN  ";
		gotoXY(33, 5);	cout << "                              ";
		TextColor(14);
		gotoXY(0, 0); cout << "MA MON HOC:" << ltc.MaMH;
		q = MH_ThongTin(npmh, ltc.MaMH);
		gotoXY(0, 1); cout << "TEN MON HOC:" << q->info.TenMH;
		gotoXY(0, 2); cout << "NIEN KHOA:" << ltc.NienKhoa;
		gotoXY(0, 3); cout << "HOC KI:" << ltc.HocKy;
		gotoXY(0, 4); cout << "NHOM:" << ltc.Nhom;
		
		dem = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < SoLuongSVDK; i++)
		{
			TextColor(12); gotoXY(6, 11 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(12, 11 + dem); cout << sv[i].MaSV;
			gotoXY(28, 11 + dem); cout << sv[i].Ho;
			gotoXY(50, 11 + dem); cout << sv[i].Ten;
			gotoXY(60, 11 + dem); cout << svdk[i].Diem;
			dem++;
		}
		PhanTrang(trang + 1, tongtrang, 50, 27);
		gotoXY(60, 27);
		key = GetKey();

		if ((key == RIGHT) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT ) && trang > 0) { trang--; }
		if(key == ESC) 
		{
			delete(sv); delete(svdk); return;
		}
		
	}
}


void ChonMENU(DSLTC &dsltc, NODEPTR_MONHOC &npmh, DSSV &dssv)
{
	int chonMenuCon;
	while (1)
	{
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			if (i == 0) { TextColor(228); }
			else { TextColor(240); }
			gotoXY(0, 6 + i * 4); cout << "                        ";
			gotoXY(0, 7 + i * 4); cout << MENUChinh[i];
			gotoXY(0, 8 + i * 4); cout << "                        ";
		}
		gotoXY(24, 7);
		int chon = MenuCha();
		switch (chon)
		{
			case 1:
			{
				for (int i = 0; i < 4; i++)
				{
					if (i == 0) { TextColor(236); }
					else { TextColor(252); }
					gotoXY(28, 6 + (i + 1) * 4);	cout << "                                       ";
					gotoXY(28, 7 + (i + 1) * 4);	cout << MENUloptc[i];
					gotoXY(28, 8 + (i + 1) * 4);	cout << "                                       ";
				}
				chonMenuCon = MenuCon(4, MENUloptc);
				TextColor(14);
				system("cls");
				switch (chonMenuCon)
				{
					case 1: {	LTC_ThemSuaXoaDS(dsltc, npmh); break;}
					case 2:  {	LTC_NhapDiem(dsltc, dssv,npmh);     break;}
					case 3:  {	LTC_XemDiem(dsltc, dssv,npmh);     break;}
					case 4: {   LTC_Huy(dsltc, npmh);       ;break;}
					
				}
				break;
			}
	
			case 2:
			{
				system("cls");
				MH_ThemSuaXoaDS(dsltc, npmh);
				break;	
			}
			case 3:
			{
				system("cls");
				SinhVien_ThemXoaSuaDS(dsltc, dssv);
				break;
			}
	
			case 4:
			{
				for (int i = 0; i < 2; i++)
				{
					if (i == 0) { TextColor(236); }
					else { TextColor(252); }
					gotoXY(28, 6 + (i + 1) * 4);	cout << "                                       ";
					gotoXY(28, 7 + (i + 1) * 4);	cout << MENUdangki[i];
					gotoXY(28, 8 + (i + 1) * 4);	cout << "                                       ";
				}
				chonMenuCon = MenuCon(2, MENUdangki);
				TextColor(14);
				system("cls");
				switch (chonMenuCon)
				{
					case 1: {  DSSVDangKy_LTC(dsltc, dssv, npmh); break; }
					case 2: {   XemDanhSachSVDK(dsltc, dssv, npmh); break;}
				}
				break;
	
			}
			case 5: {
				
				TextColor(14);	break;
			}
		}	
	}
}



int main()
{
	DSSV dssv;
	NODEPTR_MONHOC npmh = NULL;
	DSLTC dsltc;	
	SinhVien_DocFile(dssv);
	MH_DocFileDSMH(npmh);
	LTC_DocFile(dsltc);
	DSDK_DocFile(dsltc);
	ChonMENU(dsltc, npmh, dssv);
	return 0;
}














