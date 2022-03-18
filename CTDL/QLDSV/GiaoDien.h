#include <iostream>
#include<conio.h>
#include<windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


#define ENTER 13 
#define ESC 27
#define DOWN 80
#define UP 72
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define TAB 9
#define INSERT 82
#define BACKSPACE 8
#define DLT 83
#define F5 63
#define F2 60 //Save
#define F4 62 //Edit

using namespace std;

void gotoXY(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

// Doi mau chu~
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// doi key -32 thanh cac so duong
int GetKey() {
	char key; 
	key = _getch();
	if (key == -32 || key == 0)
		return (_getch());
	else return key;
}

//==========Giao Dien Dung Chung=========

void GioiThieu() {
	TextColor(121); gotoXY(35, 2); cout << "                                                  ";
	gotoXY(35, 3); cout << "    CHUONG TRINH QUAN LY DIEM SINH VIEN           ";
	gotoXY(35, 4); cout << "                                                  ";
	TextColor(228);
	gotoXY(35, 0); cout << "               MANH BINH - DAI HAI                ";
	gotoXY(35, 1); cout << "             N17DCCN013 - N17DCCN042              ";
	gotoXY(35, 5); cout << "                                                  ";
	gotoXY(35, 2); cout << "  "; gotoXY(83, 2); cout << "  ";
	gotoXY(35, 3); cout << "  "; gotoXY(83, 3); cout << "  ";
	gotoXY(35, 4); cout << "  "; gotoXY(83, 4); cout << "  ";
	TextColor(14);
	
	int y = 5;

	char s[] = { "    CHUONG TRINH QUAN LY DIEM SINH VIEN      " };
	int m = strlen(s) - 1;	TextColor(121);
	while (!_kbhit()) {
		for (int i = m; i > 0; i--) {
			s[i] = s[i - 1];
			s[0] = s[m - 1];
		}
		gotoXY(38, 3);       cout << s;
		gotoXY(38, 3); cout << " ";	   Sleep(100);
	}
	TextColor(15);
}


int	 ThongBao_LuuFile() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << "     Ban Co Muon Luu Vao File!   ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

int	 ThongBao_HuyLTC() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << "     Ban Co Chac Huy LTC Nay?    ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

void GhiChu(string c, int x, int y, int color, int sleep)
{

	gotoXY(x, y);
	TextColor(color);
	cout << c;
	Sleep(sleep);
	gotoXY(x, y);
	TextColor(14);
	for (int j = 0; j <= c.length(); j++)
	{
		cout << ' ';
	}

}

void PhanTrang(int trang, int tongtrang, int x, int y) {
	TextColor(174);	gotoXY(x, y); cout << " Trang:        ";
	gotoXY(x + 8, y); cout << trang << "/" << tongtrang;
	TextColor(14);
}

//=============Giao Dien DSSV===========//


void MaLop_KhungNhap() {
	TextColor(228); gotoXY(33, 2); cout << "                              ";
	gotoXY(33, 3); cout << "                              ";
	gotoXY(33, 1); cout << "                              ";
	TextColor(192);	TextColor(116); gotoXY(33, 1); cout << "          NHAP MA LOP         ";
	TextColor(233); gotoXY(36, 3); cout << "Enter:";
	gotoXY(50, 3); cout << "ESC:";
	TextColor(228); gotoXY(43, 3); cout << "OK";
	gotoXY(55, 3); cout << "Exit";
	TextColor(14);	gotoXY(40, 2); cout << "               ";
}


void MaLop_KhungXuat() {
	gotoXY(0,5);
	cout << "\n\n\n\n\n                                    +---------------------+";
	cout << "\n                                    |    |                |";
	cout << "\n                                    |----+----------------+";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    |	 |                |";
	cout << "\n                                    +---------------------+";
	TextColor(236);	gotoXY(33, 6);	cout << "                              ";
	gotoXY(33, 7);	cout << "   THONG TIN CAC MA LOP HOC   ";
	gotoXY(33, 8);	cout << "                              ";
	TextColor(14);	gotoXY(38, 11);    cout << "STT";
	gotoXY(46, 11);	cout << "MA LOP";

}


void SinhVien_KhungNhap() {
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n\n   +--------------------------------------------------------------------------------";
	cout << "\n   |     |		 |		      |          |	    |              |                 ";
	cout << "\n   |-----+---------------+--------------------+----------+----------+--------------+";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |--------------------------------------------------------------------------------";
	cout << "\n   |                                                                               |";
	cout << "\n   +--------------------------------------------------------------------------------";
	TextColor(236);	gotoXY(33, 1);	cout << "                              ";
	gotoXY(33, 2);	cout << "     DANH SACH SINH VIEN      ";
	gotoXY(33, 3);	cout << "      LOP:                    ";
	gotoXY(33, 4);	cout << "                              ";
	TextColor(12);	gotoXY(5, 6);    cout << "STT";
	TextColor(14);
	gotoXY(12, 6);	cout << "MA SINH VIEN";
	gotoXY(28, 6);	cout << "HO";
	gotoXY(49, 6);	cout << "TEN";
	gotoXY(60, 6);	cout << "PHAI";
	gotoXY(71, 6);	cout << "SDT";
	
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(20, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": INSERT";
	gotoXY(36, 24); TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(50, 24); TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(64, 24); TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": DELETE";


	gotoXY(0, 27);
}

void DSDK_KhungXemSVDK() {
	gotoXY(0, 2);
	TextColor(14);
	cout << "\n\n\n\n\n   +--------------------------------------------------------------------------------";
	cout << "\n   |     |		 |		      |          |	    |              |                 ";
	cout << "\n   |-----+---------------+--------------------+----------+----------+--------------+";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |	 |               |       	      |          |          |              |                 ";
	cout << "\n   |--------------------------------------------------------------------------------";

	TextColor(236);	gotoXY(33, 3);	cout << "                              ";
	gotoXY(33, 4);	cout << "     DANH SACH SINH VIEN      ";
	gotoXY(33, 5);	cout << "                              ";
	TextColor(12);	gotoXY(5, 8);    cout << "STT";
	TextColor(14);
	gotoXY(12, 8);	cout << "MA SINH VIEN";
	gotoXY(28, 8);	cout << "HO";
	gotoXY(49, 8);	cout << "TEN";
	gotoXY(60, 8);	cout << "PHAI";
	gotoXY(71, 8);	cout << "SDT";
	gotoXY(0, 27);
}

void DSDK_KhungNhapDiem() {
	gotoXY(0, 7);
	TextColor(14);
	cout << "\n   +---------------------------------------------------------------+";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   +---------------------------------------------------------------+";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   |      |               |                     |        |         |";
	cout << "\n   +---------------------------------------------------------------+";
	TextColor(236);	gotoXY(33, 3);	cout << "                              ";
	gotoXY(33, 4);	cout << "     DANH SACH SINH VIEN      ";
	gotoXY(33, 5);	cout << "                              ";
	TextColor(12);	gotoXY(5, 9);    cout << "STT";
	TextColor(14);
	gotoXY(12, 9);	cout << "MA SINH VIEN";
	gotoXY(28, 9);	cout << "HO";
	gotoXY(50, 9);	cout << "TEN";
	gotoXY(60, 9);	cout << "DIEM";
	gotoXY(0, 27);
	gotoXY(85, 14);	TextColor(252);	cout << "ENTER";
	TextColor(14);	cout << ": OK";
	gotoXY(85, 16);	TextColor(252);	cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(85, 18);	TextColor(252);	cout << "PAGE UP";
	TextColor(14);		cout << ": UP";
	gotoXY(85, 20);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
}


void SinhVien_KhungThem() {
	TextColor(225);
	gotoXY(20, 8);		cout << "                NHAP THONG TIN SINH VIEN CAN THEM              ";
	TextColor(228);
	gotoXY(20, 9);		cout << "                                                               ";
	gotoXY(20, 10);    	cout << "                                                               ";

	gotoXY(25, 10);		cout << "MA SINH VIEN";
	gotoXY(40, 10);		cout << "HO";
	gotoXY(54, 10);		cout << "TEN";
	gotoXY(64, 10);		cout << "PHAI";
	gotoXY(71, 10);		cout << "SDT";
	gotoXY(20, 11);    	cout << "                                                               ";
	gotoXY(20, 12);    	cout << "                                                               ";
	gotoXY(20, 13);    	cout << "                                                               ";
	TextColor(245);
	gotoXY(20, 13);    	cout << "                                                               ";
	TextColor(12);

	gotoXY(24, 11);    	cout << "              ";
	gotoXY(40, 11);    	cout << "             ";
	gotoXY(54, 11);    	cout << "       ";
	gotoXY(64, 11);		cout << "    ";
	gotoXY(71, 11);		cout << "           ";
	
}


void SinhVien_KhungNhapMaSVSua() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Sinh Vien Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(12);	gotoXY(33, 14); cout << "                           ";
}


void SinhVien_KhungSuaThongTin() {
	
	TextColor(228); gotoXY(27, 13); cout << "            HO              TEN     PHAI     SDT      ";
	gotoXY(27, 14); cout << "  ";
	gotoXY(49, 14); cout << "  ";
	gotoXY(61, 14); cout << "  ";
	gotoXY(66, 14); cout << "  ";
	gotoXY(79, 14); cout << "  ";
	gotoXY(27, 15); cout << "                                                      ";
	gotoXY(27, 16); cout << "                                                      ";
	TextColor(228);
	gotoXY(30, 16); cout << "Enter:";
	gotoXY(50, 16); cout << "ESC:";
	TextColor(225);	gotoXY(37, 16); cout << "OK";
	gotoXY(55, 16); cout << "Exit";
	TextColor(14);	
	gotoXY(29, 14); cout << "                    ";
	gotoXY(51, 14); cout << "          ";
	gotoXY(63, 14); cout << "    ";

}

void SinhVien_KhungNhapMaSVXoa() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Sinh Vien Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(12);	gotoXY(33, 14); cout << "                           ";
}



void SinhVien_KhungNhapMaLop() {
	TextColor(228); gotoXY(33, 2); cout << "                              ";
	gotoXY(33, 3); cout << "                              ";
	gotoXY(33, 4); cout << "                              ";
	gotoXY(33, 1); cout << "                              ";
	TextColor(192);	TextColor(116); gotoXY(33, 1); cout << "          NHAP MA LOP         ";
	TextColor(233); gotoXY(36, 3); cout << "Enter:";
	gotoXY(50, 3); cout << "ESC:";
	
	TextColor(228); gotoXY(43, 3); cout << "OK";
	gotoXY(55, 3); cout << "Exit";
	
	TextColor(14);	gotoXY(40, 2); cout << "               ";
}

//========================

//================Giao dien Mon Hoc=====


void MonHoc_KhungXuat() {
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n\n   +-----------------------------------------------------------------------------------+";
	cout << "\n   |     |		      |					       |       |       |";
	cout << "\n   |-----+--------------------+----------------------------------------+---------------|";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |-----------------------------------------------------------------------------------|";
	cout << "\n   |                                            	                       	       |";
	cout << "\n   +-----------------------------------------------------------------------------------+";
	TextColor(236);
	gotoXY(33, 2);	cout << "    DANH SACH MON HOC    ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(15, 6);	cout << "MA MON HOC";
	gotoXY(46, 6);	cout << "TEN MON HOC";
	gotoXY(73, 6);	cout << "STCLT";
	gotoXY(81, 6);	cout << "STCTH";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}


void MonHoc_KhungThem() {
	TextColor(228);
	gotoXY(10, 13); cout << "     MA MON HOC                    TEN MON HOC          STCLT   STCTH ";
	gotoXY(10, 14); cout << "                                                                      ";
	gotoXY(10, 15); cout << "                                                                      ";
	TextColor(228);	gotoXY(58, 15); cout << "Enter:";
	gotoXY(70, 15); cout << "ESC:";
	TextColor(225);	gotoXY(65, 15); cout << "OK";
	gotoXY(75, 15); cout << "Exit";
	TextColor(12);
	gotoXY(12, 14); cout << "                ";
	gotoXY(30, 14); cout << "                                   ";
	gotoXY(67, 14); cout << "   ";
	gotoXY(75, 14); cout << "   ";
}


void MonHoc_KhungNhapMaMHSua() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Mon Hoc Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "                           ";
}

void MonHoc_KhungSua() {
	TextColor(228);
	gotoXY(12, 13); cout << "     TEN MON HOC                           STCLT   STCTH        ";
	gotoXY(12, 14); cout << "                                                                ";
	gotoXY(12, 15); cout << "                                                                ";
	TextColor(228);	gotoXY(53, 15); cout << "Enter:";
	gotoXY(65, 15); cout << "ESC:";
	TextColor(225);	gotoXY(60, 15); cout << "OK";
	gotoXY(70, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(17, 14); cout << "                                   ";
	gotoXY(56, 14); cout << "   ";
	gotoXY(64, 14); cout << "   ";
}

void MonHoc_KhungNhapMaMHXoa() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Mon Hoc Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);	gotoXY(33, 14); cout << "                           ";
}


//================

//================ Giao dien lop tin chi ==========

void LTC_KhungXuat() {	
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +-----------------------------------------------------------------------------------------+\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   +---------+---------+------------------------------------+------+---------+---------+-----+\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   |         |         |                                    |      |         |         |     |\n";
	cout << "   +-----------------------------------------------------------------------------------------+\n";
	cout << "   |                                                                                         |\n";
	cout << "   +-----------------------------------------------------------------------------------------+\n";
	gotoXY(24, 2);
	TextColor(236);
	cout << "       DANH SACH LOP TIN CHI        ";
	TextColor(14);
	gotoXY(5, 6); cout <<"Ma LTC";
	gotoXY(15, 6); cout <<"Ma MH";
	gotoXY(35, 6); cout <<"Ten Mon Hoc";
//	gotoXY(62, 6); cout <<"Nien Khoa";
//	gotoXY(74, 6); cout <<"Hoc Ky";
	gotoXY(62, 6); cout <<"Nhom";
	gotoXY(69, 6); cout <<"SL Min";
	gotoXY(79, 6); cout <<"SL MAX";
	gotoXY(89, 6); cout <<"TT";

	gotoXY(14, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(28, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(43, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(55, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(66, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void LTC_KhungXuatMH() {	
	gotoXY(0, 0);
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "                       +-----------------------------------------------------------------------------+\n";
	cout << "                       |  Ma MH  |   Ten Mon Hoc                      | Nien Khoa |  Hoc Ky |  Nhom  |\n";
	cout << "                       +---------+------------------------------------+-----------+---------+--------+\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       |         |                                    |           |         |        |\n";
	cout << "                       +-----------------------------------------------------------------------------+\n";
	cout << "                       |                                                                             |\n";
	cout << "                       +-----------------------------------------------------------------------------+\n";

	gotoXY(40, 7);
	TextColor(236);
	cout << "       DANH SACH CAC MON HOC DA MO      ";
	gotoXY(40, 28);
	cout << "       ENTER DE NHAP DU LIEU      ";



}


void LTC_KhungHuy() {	
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +--------------------------------------------------------------------------------------------+\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   +---------+---------+------------------------------------+------+---------+---------+--------+\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   |         |         |                                    |      |         |         |        |\n";
	cout << "   +--------------------------------------------------------------------------------------------+\n";
	cout << "   |                                                                                            |\n";
	cout << "   +--------------------------------------------------------------------------------------------+\n";
	gotoXY(24, 2);
	TextColor(236);
	cout << "       DANH SACH LOP TIN CHI        ";
	TextColor(14);
	gotoXY(5, 6); cout <<"Ma LTC";
	gotoXY(15, 6); cout <<"Ma MH";
	gotoXY(35, 6); cout <<"Ten Mon Hoc";
	gotoXY(62, 6); cout <<"Nhom";
	gotoXY(69, 6); cout <<"SL Min";
	gotoXY(79, 6); cout <<"SL MAX";
	gotoXY(90, 6); cout <<"Da DK";

	gotoXY(55, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(25, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": HUY";

	gotoXY(0, 27);


}

void LTC_KhungThem() {
	TextColor(225);
	gotoXY(7, 30);		cout << "                     NHAP THONG TIN LOP TIN CHI CAN THEM           ";
	TextColor(228);
	gotoXY(7, 31);		cout << "                                                                   ";
	gotoXY(7, 32);    	cout << "                                                                   ";
	gotoXY(10, 32);    	cout << "MA LOP TC";
	gotoXY(25, 32);		cout << "MA MON HOC";

	gotoXY(41, 32);		cout << "NHOM";
	gotoXY(48, 32);		cout << "SL MIN";
	gotoXY(59, 32);     cout << "SL MAX";
	gotoXY(7, 33);    	cout << "                                                                   ";
	gotoXY(7, 34);    	cout << "                                                                   ";
	gotoXY(7, 35);    	cout << "                                                                   ";
	TextColor(225);
	gotoXY(9, 35);    	cout << "                                                                 ";
	TextColor(15);
	gotoXY(9, 33);    	cout << "            ";
	gotoXY(24, 33);    	cout << "            ";

	gotoXY(41, 33);		cout << "    ";
	gotoXY(48, 33);		cout << "       ";
	gotoXY(59, 33);		cout << "       ";
}

void LTC_KhungXoa() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Lop Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(12);	gotoXY(33, 14); cout << "                           ";
}
void LTC_KhungNhapMaLTCHuy() {
	TextColor(228);
	gotoXY(98, 13); cout << "                      ";
	gotoXY(98, 14); cout << "                      ";
	gotoXY(98, 15); cout << "                      ";
	gotoXY(101, 13); cout << "Nhap Ma LTC Huy";
	TextColor(228); gotoXY(110, 15); cout << "Enter:";
	gotoXY(98, 15); cout << "ESC:";
	TextColor(225); gotoXY(117, 15); cout << "OK";
	gotoXY(102, 15); cout << "Exit";
	TextColor(12);	gotoXY(100, 14); cout << "                 ";
}


void LTC_KhungNhapMaLTC() {
	TextColor(228);
	gotoXY(30, 10); cout << "                                 ";
	gotoXY(30, 11); cout << "                                 ";
	gotoXY(30, 12); cout << "                                 ";
	gotoXY(33, 10); cout << "Nhap Ma Lop Tin Chi Can Sua";
	TextColor(228); gotoXY(33, 12); cout << "Enter:";
	gotoXY(51, 12); cout << "ESC:";
	TextColor(225); gotoXY(40, 12); cout << "OK";
	gotoXY(56, 12); cout << "Exit";
	TextColor(12);	gotoXY(33, 11); cout << "                           ";
}

void LTC_KhungSua() {
	TextColor(225);
	gotoXY(7, 8);		cout << "                     NHAP THONG TIN LOP TIN CHI CAN SUA                                     ";
	TextColor(228);
	gotoXY(7, 9);		cout << "                                                                                            ";
	gotoXY(7, 10);    	cout << "                                                                                            ";
	gotoXY(12, 10);    	cout << "MA LOP";
	gotoXY(25, 10);		cout << "MA MON HOC";
	gotoXY(41, 10);		cout << "NIEN KHOA";
	gotoXY(54, 10);		cout << "HOC KI";
	gotoXY(64, 10);		cout << "NHOM";
	gotoXY(71, 10);		cout << "SL MIN";
	gotoXY(81, 10);     cout << "SL MAX";
	gotoXY(92, 10);     cout << "TT";
	gotoXY(7, 11);    	cout << "                                                                                            ";
	gotoXY(7, 12);    	cout << "                                                                                            ";
	gotoXY(7, 13);    	cout << "                                                                                            ";
	TextColor(250);
	gotoXY(9, 13);    	cout << "                                                                                        ";
	TextColor(12);
	gotoXY(9, 11);    	cout << "            ";
	gotoXY(24, 11);    	cout << "            ";
	gotoXY(41, 11);    	cout << "         ";
	gotoXY(54, 11);    	cout << "      ";
	gotoXY(64, 11);		cout << "    ";
	gotoXY(71, 11);		cout << "       ";
	gotoXY(81, 11);		cout << "       ";
	gotoXY(91, 11);		cout << "    ";
}

//==================giao dien Danh sach dang ky lop tin chi================
void DSDKLTC_KhungNhapMSV_HocKy_NienKhoa() {
	TextColor(250);
	gotoXY(30, 0);		cout << "     NHAP THONG TIN DE TIEN HANH DANG KI     ";
	TextColor(228);
	gotoXY(30, 1);    	cout << "                                             ";
	gotoXY(34, 1);		cout << "MA SINH VIEN";
	gotoXY(49, 1);		cout << "NIEN KHOA";
	gotoXY(63, 1);		cout << "HOC KY ";
	gotoXY(30, 2);    	cout << "                                             ";
	gotoXY(30, 3);    	cout << "                                             ";
	TextColor(12);
	gotoXY(34, 2);    	cout << "            ";
	gotoXY(49, 2);    	cout << "          ";
	gotoXY(62, 2);    	cout << "        ";
}

void DSDKLTC_KhungNhap_NienKhoa_HocKy() {
	TextColor(250);
	gotoXY(30, 0);		cout << " NHAP THONG TIN DE TIEN HANH HUY LOP TIN CHI ";
	TextColor(228);
	gotoXY(30, 1);    	cout << "                                             ";

	gotoXY(39, 1);		cout << "NIEN KHOA";
	gotoXY(55, 1);		cout << "HOC KY ";
	gotoXY(30, 2);    	cout << "                                             ";
	gotoXY(30, 3);    	cout << "                                             ";
	TextColor(12);
	gotoXY(38, 2);    	cout << "          ";
	gotoXY(54, 2);    	cout << "        ";
}

void DSSVDK_KhungDangKyLTC() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +-----------------------------------------------------------------------------------+\n";
	cout << "   | MA LTC | MA MON HOC |         TEN MON HOC                | NHOM | DA DK | CON LAI |\n";
	cout << "   +--------+------------+------------------------------------+------+-------+---------+\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |        |            |                                    |      |       |         |\n";
	cout << "   |-----------------------------------------------------------------------------------|\n";
	cout << "   |                                                                                   |\n";
	cout << "   +-----------------------------------------------------------------------------------+\n";

	gotoXY(26, 2);
	TextColor(236);
	cout << "     DANH SACH LOP TIN CHI DANG KI     ";
	

	


}

void DSDKLTC_KhungDanhSachDangKy()
{
	TextColor(14);
	gotoXY(0,27);
	cout << "   +---------------------------------------------------------------------------\n";
	cout << "   | MA LTC | MA MON HOC |         TEN MON HOC                | STCLT | STCTH |\n";
	cout << "   +--------+------------+------------------------------------+-------+-------+\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |        |            |                                    |       |       |\n";
	cout << "   |--------------------------------------------------------------------------|\n";
	cout << "   |                                                                          |\n";
	cout << "   +--------------------------------------------------------------------------+\n";
	gotoXY(25, 43);		TextColor(252);		cout << "DELETE";
	TextColor(14);		cout << ": DELETE";
	gotoXY(4, 43);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": Exit";
	gotoXY(50, 43);		TextColor(252);		cout << "F2";
	TextColor(14);		cout << ": Save";
}


void DSDKLTC_KhungDangKy() {
	TextColor(244);
	gotoXY(90, 10); cout << "   NHAP LTC MUON DANG KI   ";
	TextColor(228);
	gotoXY(87, 11); cout << "                                ";
	gotoXY(87, 12); cout << "   MA LTC:                      ";
	gotoXY(87, 13); cout << "                                ";
	TextColor(14); 
	gotoXY(97, 12); cout << "             ";

}

void DSDKLTC_KhungXoa() {
	TextColor(244);
	gotoXY(84, 30); cout << "   NHAP LTC MUON XOA            ";
	TextColor(228);
	gotoXY(84, 31); cout << "                                ";
	gotoXY(84, 32); cout << "   MA LTC:                      ";
	gotoXY(84, 33); cout << "                                ";
	TextColor(14); 
	gotoXY(94, 32); cout << "             ";

}

void DSDKLTC_MMH_NK_HK_Nhom() {
	TextColor(244);
	gotoXY(30, 0);		cout << "       NHAP THONG TIN DE XEM DANH SACH DANG KI             ";
	TextColor(228);
	gotoXY(30, 1);    	cout << "                                                           ";
	gotoXY(34, 1);		cout << "MA MON HOC";
	gotoXY(50, 1);		cout << "NIEN KHOA ";
	gotoXY(67, 1);		cout << "HOC KY";
	gotoXY(80, 1);		cout << "NHOM";
	gotoXY(30, 2);    	cout << "                                                           ";
	gotoXY(30, 3);    	cout << "                                                           ";
	TextColor(12);
	gotoXY(34, 2);    	cout << "            ";
	gotoXY(49, 2);    	cout << "            ";
	gotoXY(66, 2);    	cout << "        ";
	gotoXY(78, 2);    	cout << "        ";
}



void KhungSuaDiem() {
	TextColor(228);
	gotoXY(62, 13); cout << "                    ";
	gotoXY(62, 14); cout << "                    ";
	gotoXY(62, 15); cout << "                    ";
	gotoXY(65, 13); cout << "DIEM";
	TextColor(12);
	gotoXY(64, 14); cout << "      ";
}



