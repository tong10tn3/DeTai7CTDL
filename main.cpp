#include <graphics.h> 
#include<fstream>
#include<math.h>
#include<conio.h>
#include<iostream>
#include<string.h>
#define mauvongtron 2
#define Rvongtron 25
using namespace std;
#define MauNenDoThi 7
#define MAX 100
#define mauxanhgiongaokhoaccrush 9

#define mauxanhlachuoi 10
#define mauxanhlacay 2

#define mauNutThoat 4
#define mauKhiChamNutThoat 12
#define soLuongDinhMax 15
#define nhanDinh 12
#define MaxMatrix 20
#define DENTA 15
#define VOCUNG 999

// ==================== KHAI BAO ======================

struct Dinh
{
	int toaDoX;
	int toaDoY;
	char name[2];
	
};
struct button
{
	int xdau;
	int ydau;
	int xcuoi;
	int ycuoi;
	string content;
	int mauButton= mauxanhlacay;
	int BGcolor=mauxanhlacay;
	bool isChangeColor=false;
	int mauKhiCham=mauxanhlachuoi;
	int doRongFont=1;
	bool click=false;
};
Dinh mainDinh[soLuongDinhMax]; int soLuongDinh=0;
int **matrix;

int truoc[MaxMatrix];

struct node
{
	int infor;
	node*pnext=NULL;
};

struct canh
{
	int dinhDau;
	int dinhCuoi;
};

// ====================================================

// =============== THIET LAP GIAO DIEN ================
		void setGiaoDien();
		void setMatrix();
		void setMenu();
		void setDoThi();
		void setThongTin();
// ====================================================

// ============ THIET LAP NUT CHUC NANG ===============
		void taoMangButton(button a[]);
		void doiMauButton(button a, int color);
		void setButton(button a);
		void setUpMenuChild(button menuChild[][13]);
		void drawMenuButton(button a[]);
		void drawMenuButtonTren(button a[]);
// ====================================================

// =================== HAM DINH ======================
		void ve1Dinh(Dinh a);
		void themVaoMainDinh(Dinh a);
		void xoaDinhTrongArray(int vt);
		void nhanVaoDinh(Dinh a);
		void nhanVaoDinhChonMau(Dinh a, int color);
		void xoa1DinhTrongMatrix(int vt);
		int viTriDinh(int x, int y);
		bool kiemTraTrungTenDinh(Dinh a);
		bool kiemTraTrungViTriDinh(int x, int y);
		bool kiemTraTrungViTriDinhNgoaiViTri(int x, int y, int vt);
		
		void taoDinh();
		void xoaDinh();
		void suaDinh();
		void diChuyenDinh();
		void huongDanDinh();
// ===================================================

// =================== HAM CANH ======================
		void ve1Canh(Dinh dau, Dinh cuoi, int trongso);
		void xoa1Canh(Dinh dau, Dinh cuoi);
		void veMuiTen(Dinh dau, Dinh cuoi, int color);
		void xoaMuiTen(Dinh x, Dinh y);
		
		void taoCanh();
		void xoaCanh();
		int nhapTrongSo();
		void suaTrongSo();
		void huongDanCanh();
// ===================================================

// ================= OTHER FUNCTION ===================
		void veMatrix();
		void khoiTaoMatrix(int n);
		void giaiPhongMatrix(int n);
		void veAllDoThi();
		void veChuThankYou();
// ===================================================

// ================= STACK FUNCTION ==================
		bool isEmptyStack(node* phead);
		bool inStack(node*phead, int n);
		void pushStack(node*&phead, int a);
		void popStack(node*&phead, int &a);
// ===================================================

// ================= QUEUE FUNCTION ==================
		bool isEmptyQueue(node*phead,node*plast);
		void pushQueue(node*&phead, node*&plast,int a);
		void popQueue(node*&phead,node*&plast,int &a);
// ===================================================

// ================ THUAT TOAN DFS ===================
		void DFS(int x);
		void thuatToanDFS();
// ===================================================

// ================ THUAT TOAN BFS ===================
		void BFS(int x, int a[], int &n);
		void thuatToanBFS();
// ===================================================

// ======== THUAT TOAN TIM DUONG DI NGAN NHAT ========
		void initXtoY(int G[][MaxMatrix]);
		void XtoY();
// ===================================================

// ============== THUAT TOAN DINH TRU ================
		bool kiemTraDoThiCoLaVoHuongKhong();
		void DFSDoThiVoHuong(bool chuaxet[], int x);
		void DFSDoThiVoHuongDinhTru(int x, int dinhBo, bool chuaxet[]);
		int timSoTPLTDoThiVoHuong();
		int timSoTPLTDoThiVoHuongDinhTru(bool chuaxet[]);
		void thuatToanDinhTru();
// ===================================================

// ============== THUAT TOAN DINH THAT ===============
		void BFSDINHTHAT(int k);
		bool kiemTraDinhThat();
		void thuatToanDinhThat();
// ===================================================

// =============== THUAT TOAN CANH CAU ===============
		int DFSDoThiVoHuongKhongLuuKQ(int x);
		void thuatToanCanhCau();
// ===================================================

// =============== THUAT TOAN HAMILTON ===============
		void Result(int &d, int B[]);
		void Hamilton(int *B, int *C, int i, int &d, int n, int A[][MaxMatrix]);
		void thuatToanHamilton();
// ===================================================

// ================ THUAT TOAN EULER =================
		void BFSEuler(bool chuaxet[]);
		bool kiemTraEC();
		void thuatToanEulerCycle();
// ===================================================

// ============== THUAT TOAN TOPOSORT ================
		void copyMatrix(int B[MaxMatrix][MaxMatrix]);
		void thuatToanTopoSort();
// ===================================================

// =============== THUAT TOAN TPLT ===================
		void strongConnect(int index[], int lowLink[],node*&phead,int &indexNumber, int Dinh, int &color, int&soThanhPhanLienThongManh);
		void TPLT();
// ===================================================

// ====================== FILE =======================
		void saveFile();
		void readFile();
		void tuDongLuuFileKhiThoat();
// ===================================================

// =============== BAT DIEU KIEN CHUOT ===============
		void batDkChuot(button &a, int x, int y,button menuChild[][13],button b[]);
		void batDkChuotMenuChild(button &a, int xchuot, int ychuot,button b[],button benNgoai);
		void batDkChuotMenuChildThuatToan(button &a, int xchuot, int ychuot,button b[]);
// ===================================================

// =============== CHAY CHUONG TRINH =================
		void xuLiChuot(button a[], button menuChild[][13]);
		void xuLi();
// ===================================================

// ==================== PHIM TAT =====================
		void taoDinhPhimTat(int xtam, int ytam);
		void xoaDinhPhimTat(int xtam, int ytam);
		void huongDanF1();
// ===================================================


int main()//int argc, char *argv[]
{
	initwindow(1280+8,720+12);
	setGiaoDien();
	
	khoiTaoMatrix(MaxMatrix);
	xuLi();

	getch();
	return 0;
}

// =============== THIET LAP GIAO DIEN ================
void setGiaoDien()
{
	setfillstyle(SOLID_FILL,MauNenDoThi);
	bar(0, 0, 1280, 720);
	
	setMatrix();
	setMenu();
	setDoThi();
	setThongTin();


}

void setMatrix()
{
	int xdau=5; 	int xcuoi=300;
	int ydau=400;	int ycuoi=715;
	setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
	bar(xdau,ydau,xcuoi,ycuoi);
	setfillstyle(0,MauNenDoThi);
	rectangle(xdau,ydau,xcuoi,ycuoi);

	line(xdau,ydau+50,xcuoi,ydau+50);
	int xgiua=(xdau+xcuoi)/2;
	int ygiua=(ydau+ydau+50)/2;
	char *s=new char[8];
	s="MA TRAN";
	setbkcolor(mauxanhgiongaokhoaccrush);
	settextstyle(DEFAULT_FONT,0, 2);
	outtextxy(xgiua-8-3*16,ygiua-8,s);
	settextstyle(DEFAULT_FONT,0,1);
	delete s;
}

void setMenu()
{
	int xdau=5;		int xcuoi=300;
	int ydau=5;		int ycuoi=395;
	setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
	bar(xdau,ydau,xcuoi,ycuoi);
	setfillstyle(0,MauNenDoThi);
	rectangle(xdau,ydau,xcuoi,ycuoi);
}

void setDoThi()
{
	int xdau=305;	int xcuoi=1275;
	int ydau=5;		int ycuoi=450;
	rectangle(xdau,ydau,xcuoi,ycuoi);
}

void setThongTin()
{
	int xdau=305;	int xcuoi=1120;
	int ydau=455;	int ycuoi=715;
	setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
	bar(xdau,ydau,xcuoi,ycuoi);
	setfillstyle(0,MauNenDoThi);
	rectangle(xdau,ydau,xcuoi,ycuoi);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(310,690,"F1:HUONG DAN LM:TAO DINH RM:XOA DINH F2:TAO CANH F3:XOA CANH F4:SUA TS F5:SUA DINH F6:DI CHUYEN DINH");
}

// ====================================================


// ============ THIET LAP NUT CHUC NANG ===============
void taoMangButton(button a[])
{
	a[0].xdau=25;		a[0].ydau=27;
	a[0].xcuoi=280;		a[0].ycuoi=97;
	a[0].content="DINH";
	
	a[1].xdau=25;		a[1].ydau=119;
	a[1].xcuoi=280;		a[1].ycuoi=189;
	a[1].content="CANH";
	
	a[2].xdau=25;		a[2].ydau=211;
	a[2].xcuoi=280;		a[2].ycuoi=281;
	a[2].content="THUAT TOAN";
	
	a[3].xdau=25;		a[3].ydau=303;
	a[3].xcuoi=280;		a[3].ycuoi=373;
	a[3].content="TEP";
	
	a[0].mauButton=a[1].mauButton=a[2].mauButton=a[3].mauButton= mauxanhlacay;
	a[0].BGcolor=a[1].BGcolor=a[2].BGcolor=a[3].BGcolor=mauxanhlacay;

	
	a[4].xdau=1125;		a[4].ydau=455;
	a[4].xcuoi=1275;	a[4].ycuoi=539;
	a[4].content="XOA HET";
	a[4].mauButton=mauxanhlacay;
	
	a[5].xdau=1125;		a[5].ydau=544;
	a[5].xcuoi=1275;	a[5].ycuoi=627;
	a[5].content="LUU";
	a[5].mauButton=mauxanhlacay;
	
	a[0].mauKhiCham=a[1].mauKhiCham=a[2].mauKhiCham=a[3].mauKhiCham=a[4].mauKhiCham=a[5].mauKhiCham= mauxanhlachuoi;
	
	a[6].xdau=1125;		a[6].ydau=632;
	a[6].xcuoi=1275;	a[6].ycuoi=715;
	a[6].content="THOAT";
	a[6].mauButton=mauNutThoat;
	a[6].BGcolor=mauNutThoat;
	a[6].mauKhiCham=mauKhiChamNutThoat;
	
	
	for(int i=0;i<=6;i++)
	{
		a[i].doRongFont=2;
	}
	//set nut khi cham
	a[7].xdau=25;		a[7].ydau=27;
	a[7].xcuoi=151;		a[7].ycuoi=97;
	a[7].content="Dinh";
	a[7].doRongFont=2;
	a[7].mauButton=mauxanhlacay;
	a[7].BGcolor=mauxanhlacay;
	a[7].mauKhiCham=mauxanhlachuoi;
	
	a[8].xdau=25;		a[8].ydau=119;
	a[8].xcuoi=151;		a[8].ycuoi=189;
	a[8].content="Canh";
	a[8].doRongFont=2;
	a[8].mauButton=mauxanhlacay;
	a[8].BGcolor=mauxanhlacay;
	a[8].mauKhiCham=mauxanhlachuoi;
	
	
	a[9].xdau=25;		a[9].ydau=211;
	a[9].xcuoi=151;		a[9].ycuoi=281;
	a[9].content="T.T";
	a[9].doRongFont=2;
	a[9].mauButton=mauxanhlacay;
	a[9].BGcolor=mauxanhlacay;
	a[9].mauKhiCham=mauxanhlachuoi;
	
	a[10].xdau=25;		a[10].ydau=303;
	a[10].xcuoi=151;	a[10].ycuoi=373;
	a[10].content="Tep";
	a[10].doRongFont=2;
	a[10].mauButton=mauxanhlacay;
	a[10].BGcolor=mauxanhlacay;
	a[10].mauKhiCham=mauxanhlachuoi;
}

void doiMauButton(button a, int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	rectangle(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	
	int xgiua=(a.xdau+a.xcuoi)/2;
	int ygiua=(a.ydau+a.ycuoi)/2;
	setbkcolor(color);
	settextstyle(DEFAULT_FONT,0, a.doRongFont);
	
	char*s=new char [a.content.length()+1];
	for(int i=0;i<a.content.length();i++)
	{
		s[i]=a.content[i];
	}
	s[a.content.length()]='\0';
	int denta=a.content.length()/2;
	outtextxy(xgiua-a.doRongFont*4-denta*a.doRongFont*8,ygiua-a.doRongFont*4,s);
	delete s;
}

void setButton(button a)
{
	setfillstyle(SOLID_FILL,a.mauButton);
	bar(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	setfillstyle(SOLID_FILL,MauNenDoThi);
	rectangle(a.xdau,a.ydau,a.xcuoi,a.ycuoi);
	
	int xgiua=(a.xdau+a.xcuoi)/2;
	int ygiua=(a.ydau+a.ycuoi)/2;
	setbkcolor(a.BGcolor);
	settextstyle(DEFAULT_FONT,0, a.doRongFont);
	//chuyen string thanh char*
	char*s=new char [a.content.length()+1];
	for(int i=0;i<a.content.length();i++)
	{
		s[i]=a.content[i];
	}
	s[a.content.length()]='\0';
	int denta=a.content.length()/2;
	//
	outtextxy(xgiua-a.doRongFont*4-denta*a.doRongFont*8,ygiua-a.doRongFont*4,s);
	delete s;
}

void setUpMenuChild(button menuChild[][13])
{
	
	menuChild[0][0].content="TAO DINH";
	menuChild[0][1].content="SUA DINH";
	menuChild[0][2].content="XOA DINH";
	menuChild[0][3].content="DI CHUYEN";
	menuChild[0][4].content="HUONG DAN";
	
	menuChild[0][0].xdau=153;menuChild[0][0].ydau=27;
	menuChild[0][0].xcuoi=279;menuChild[0][0].ycuoi=97;
	
	menuChild[0][1].xdau=153;menuChild[0][1].ydau=98;
	menuChild[0][1].xcuoi=279;menuChild[0][1].ycuoi=166;
	
	menuChild[0][2].xdau=153;menuChild[0][2].ydau=167;
	menuChild[0][2].xcuoi=279;menuChild[0][2].ycuoi=235;
	
	menuChild[0][3].xdau=153;menuChild[0][3].ydau=236;
	menuChild[0][3].xcuoi=279;menuChild[0][3].ycuoi=304;
	
	menuChild[0][4].xdau=153;menuChild[0][4].ydau=305;
	menuChild[0][4].xcuoi=279;menuChild[0][4].ycuoi=373;
	
	
	//=============================================//
	
	menuChild[1][0].content="TAO CANH";
	menuChild[1][1].content="SUA TS";
	menuChild[1][2].content="XOA CANH";
	menuChild[1][3].content="HUONG DAN";
	
	menuChild[1][0].xdau=153;menuChild[1][0].ydau=119;
	menuChild[1][0].xcuoi=280;menuChild[1][0].ycuoi=183;
	
	menuChild[1][1].xdau=153;menuChild[1][1].ydau=184;
	menuChild[1][1].xcuoi=280;menuChild[1][1].ycuoi=246;
	
	menuChild[1][2].xdau=153;menuChild[1][2].ydau=247;
	menuChild[1][2].xcuoi=280;menuChild[1][2].ycuoi=309;
	
	menuChild[1][3].xdau=153;menuChild[1][3].ydau=310;
	menuChild[1][3].xcuoi=280;menuChild[1][3].ycuoi=373;
	//==============================================//
	
	
	menuChild[2][0].content="DFS";
	menuChild[2][1].content="BFS";
	menuChild[2][2].content="X->Y";
	menuChild[2][3].content="DINH TRU";
	menuChild[2][4].content="DINH THAT";
	menuChild[2][5].content="CANH CAU";
	menuChild[2][6].content="HAMILTON";
	menuChild[2][7].content="EULER";
	menuChild[2][8].content="TOPO";
	menuChild[2][9].content="TPLT";
//	menuChild[2][10].content="HUONG DAN";
//	menuChild[2][11].content="TRO LAI";
	
	
	menuChild[2][0].xdau=20;menuChild[2][0].ydau=20;
	menuChild[2][0].xcuoi=99;menuChild[2][0].ycuoi=98;
	
	menuChild[2][1].xdau=114;menuChild[2][1].ydau=20;
	menuChild[2][1].xcuoi=192;menuChild[2][1].ycuoi=98;
	
	menuChild[2][2].xdau=207;menuChild[2][2].ydau=20;
	menuChild[2][2].xcuoi=285;menuChild[2][2].ycuoi=98;
	
	menuChild[2][3].xdau=20;menuChild[2][3].ydau=114;
	menuChild[2][3].xcuoi=99;menuChild[2][3].ycuoi=192;
	
	menuChild[2][4].xdau=114;menuChild[2][4].ydau=114;
	menuChild[2][4].xcuoi=192;menuChild[2][4].ycuoi=192;
	
	menuChild[2][5].xdau=207;menuChild[2][5].ydau=114;
	menuChild[2][5].xcuoi=285;menuChild[2][5].ycuoi=192;
	
	
	menuChild[2][6].xdau=20;menuChild[2][6].ydau=207;
	menuChild[2][6].xcuoi=99;menuChild[2][6].ycuoi=285;
	
	menuChild[2][7].xdau=114;menuChild[2][7].ydau=207;
	menuChild[2][7].xcuoi=192;menuChild[2][7].ycuoi=285;
	
	menuChild[2][8].xdau=207;menuChild[2][8].ydau=207;
	menuChild[2][8].xcuoi=285;menuChild[2][8].ycuoi=285;
	
	menuChild[2][9].xdau=20;menuChild[2][9].ydau=300;
	menuChild[2][9].xcuoi=99;menuChild[2][9].ycuoi=378;
	
//	menuChild[2][10].xdau=114;menuChild[2][10].ydau=300;
//	menuChild[2][10].xcuoi=192;menuChild[2][10].ycuoi=378;
//	
//	menuChild[2][11].xdau=207;menuChild[2][11].ydau=300;
//	menuChild[2][11].xcuoi=285;menuChild[2][11].ycuoi=378;
	
	//==============================================//
	
	menuChild[3][0].content="LUU TEP"; 
	menuChild[3][1].content="MO TEP";

	
	menuChild[3][0].xdau=153;menuChild[3][0].ydau=303;
	menuChild[3][0].xcuoi=280;menuChild[3][0].ycuoi=338;
	
	menuChild[3][1].xdau=153;menuChild[3][1].ydau=339;
	menuChild[3][1].xcuoi=280;menuChild[3][1].ycuoi=373;

	//===================================================//
	
}

void drawMenuButton(button a[])
{
	for(int i=0;i<7;i++)
	{
		setButton(a[i]);
	}
}

void drawMenuButtonTren(button a[])
{
	for(int i=0;i<4;i++)
	{
		setButton(a[i]);
	}
}

// ====================================================

// =============== BAT DIEU KIEN CHUOT ===============
void batDkChuot(button &a,int x,int y, button menuChild[][13],button b[])
{
	if(ismouseclick(WM_LBUTTONUP))
	{
		int xtam; int ytam;
		getmouseclick(WM_LBUTTONUP,xtam,ytam);
		clearmouseclick(WM_LBUTTONUP);
		if(xtam>=25&&xtam<=280&&ytam>=211&&ytam<=281)//thuat toan
		{
			setMenu();
			for(int i=0;i<=9;i++)
			{
				setButton(menuChild[2][i]);
			}
			int xtam1,ytam1;
			getmouseclick(WM_MOUSEMOVE,xtam1,ytam1);
			while((xtam1<=300&&xtam1>=5&&ytam1<=395&&ytam1>=5)||(xtam1==-1&&ytam1==-1))
			{
				delay(1);
				for(int i=0;i<=11;i++)
				{
					batDkChuotMenuChildThuatToan(menuChild[2][i],xtam1, ytam1,b);
				}
				getmouseclick(WM_MOUSEMOVE,xtam1,ytam1);
			}
		}
		else if(xtam>=1125&&xtam<=1275&&ytam>=632&&ytam<=715)// nut thoat
		{
			tuDongLuuFileKhiThoat();
			giaiPhongMatrix(soLuongDinhMax);
			veChuThankYou();
			while(!kbhit());
			exit(0);
		}
		else if(xtam>=1125&&xtam<=1275&&ytam>=455&&ytam<=539)//nut clear
		{
			int xdau=305;int xcuoi=1275;
			int ydau=5;	int ycuoi=450;
			setfillstyle(SOLID_FILL,MauNenDoThi);
			bar(xdau,ydau,xcuoi,ycuoi);
			rectangle(xdau,ydau,xcuoi,ycuoi);
			soLuongDinh=0;
			giaiPhongMatrix(soLuongDinhMax);
			setMatrix();
			setDoThi();
			setThongTin();
			khoiTaoMatrix(soLuongDinhMax);
		}
		clearmouseclick(WM_LBUTTONUP);
	}
	if(ismouseclick(WM_LBUTTONDOWN))// click chuot tao dinh
	{
		int xtam; int ytam;
		getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
		clearmouseclick(WM_LBUTTONDOWN);
		if(xtam>305&&xtam<1275&&ytam>5&&ytam<450)
		{
			settextstyle(0,0,1);
			taoDinhPhimTat(xtam,ytam);
			setThongTin();
			drawMenuButtonTren(b);
			fflush(stdin);
		}
		clearmouseclick(WM_RBUTTONDOWN);
	
	}
	 if(ismouseclick(WM_RBUTTONDOWN))// click chuot xoa dinh
	{
		int xtam; int ytam;
		getmouseclick(WM_RBUTTONDOWN,xtam,ytam);
		clearmouseclick(WM_RBUTTONDOWN);
		if(xtam>305&&xtam<1275&&ytam>5&&ytam<450)
		{
			settextstyle(0,0,1);
			xoaDinhPhimTat(xtam,ytam);
			setThongTin();
			drawMenuButtonTren(b);
		}
		fflush(stdin);
	}
	 if(kbhit())
	{
		char a=getch();
		if(a==0)
		{
			char s=getch();
			settextstyle(0,0,1);
			setbkcolor(mauxanhgiongaokhoaccrush);
			fflush(stdin);
		
			if(s==60)//f2
			{
				setbkcolor(mauxanhgiongaokhoaccrush);
				taoCanh();
				setThongTin();
			}
			else if(s==59)//f1
			{
				huongDanF1();
			}
			else if(s==61)//f3
			{
				setbkcolor(mauxanhgiongaokhoaccrush);
				xoaCanh();
				setThongTin();
			}
			else if(s==62)//f4
			{
				setbkcolor(mauxanhgiongaokhoaccrush);
				suaTrongSo();
				setThongTin();
			}
			else if(s==63)//f5
			{
				suaDinh();
				
				setThongTin();
			}
			else if(s==64)//f6
			{
				diChuyenDinh();
				
				setThongTin();
			}
		}
		fflush(stdin);
	}
	if(x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi&&a.isChangeColor==false)// khi chuot dung yen thi khong can phai doi mau lai
   	{//&&(x!=-1&&y!=-1)
		a.isChangeColor=true;
		if(a.content=="DINH")
		{
			setMenu();
			doiMauButton(b[7],b[7].mauKhiCham);
			setButton(b[8]);
			setButton(b[9]);
			setButton(b[10]);
			for(int i=0;i<=4;i++)
			{
				setButton(menuChild[0][i]);
			}
			line(152,27,152,373); 
			
			if(x>=153&&x<=280&&y>=27&&y<=97)//tao dinh
			{
				doiMauButton(menuChild[0][0],menuChild[0][0].mauKhiCham);
			}
			int xchuot=x, ychuot=y;
	
			while((xchuot<=279&&xchuot>=153&&ychuot>=27&&ychuot<=373)||(xchuot<=151&&xchuot>=25&&ychuot<=97&&ychuot>=27)||(xchuot==-1&&ychuot==-1))// dieukien de chay vao while dau tien vi khi getmouseclick dau chuot no dung yen, ma no co chuyen dong trong pham vi button cung vao
			{																											
				delay(1);
				
				for(int i=0;i<=4;i++)
				{
					batDkChuotMenuChild(menuChild[0][i],xchuot, ychuot,b,a);
				}
				getmouseclick(WM_MOUSEMOVE,xchuot,ychuot);
			}
		}
		else if(a.content=="CANH")
		{
			setMenu();
			setButton(b[0]);
			doiMauButton(b[8],b[8].mauKhiCham);
			setButton(b[9]);
			setButton(b[10]);
			for(int i=0;i<=3;i++)
			{
				setButton(menuChild[1][i]);
			}
			line(152,119,152,373);
			
			if(x>=153&&x<=280&&y>=119&&y<=183)
			{
				doiMauButton(menuChild[1][0],menuChild[1][0].mauKhiCham);
			}
			int xchuot, ychuot;
			getmouseclick(WM_MOUSEMOVE,xchuot,ychuot);
		
			while((xchuot<=151&&xchuot>=25&&ychuot>=119&&ychuot<=189)||(xchuot<=280&&xchuot>=153&&ychuot<=373&&ychuot>=119)||(xchuot==-1&&ychuot==-1))
			{
				delay(1);
				for(int i=0;i<=3;i++)
				{
					batDkChuotMenuChild(menuChild[1][i],xchuot, ychuot,b,a);
				}
				getmouseclick(WM_MOUSEMOVE,xchuot,ychuot);
			}
		}
		else if(a.content=="THUAT TOAN")
		{
			doiMauButton(a,a.mauKhiCham);
		}
		else if(a.content=="TEP")
		{	
			doiMauButton(b[10],b[10].mauKhiCham);
			for(int i=0;i<=1;i++)
			{
				setButton(menuChild[3][i]);
			}
			line(152,303,152,373);
			
			if(x>=153&&x<=279&&y>=303&&y<=338)
			{
				doiMauButton(menuChild[3][0],menuChild[3][0].mauKhiCham);
			}
			else if(x>=153&&x<=279&&y>=339&&y<=373)
			{
				doiMauButton(menuChild[3][1],menuChild[3][1].mauKhiCham);
			}
			int xchuot, ychuot;
			getmouseclick(WM_MOUSEMOVE,xchuot,ychuot);
		
			while((xchuot>=25&&xchuot<=280&&ychuot>=303&&ychuot<=373)||(xchuot==-1&&ychuot==-1))
			{
				delay(1);
				
				for(int i=0;i<=1;i++) 
				{
					batDkChuotMenuChild(menuChild[3][i],xchuot, ychuot,b,a);
				}
				getmouseclick(WM_MOUSEMOVE,xchuot,ychuot);
			}
		}
		else if(a.content=="XOA HET")
		{
			doiMauButton(a,a.mauKhiCham);
		}
		else if(a.content=="LUU")
		{
			doiMauButton(a,a.mauKhiCham);
		}
		else if(a.content=="THOAT")
		{
			doiMauButton(a,a.mauKhiCham);
		}
	}

	else if(a.isChangeColor==true&&(x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi)==false&&(x!=-1&&y!=-1))//neu khong co su kien thi getmousclick tra ve x=-1, y=-1
	{ 					//neu khong co x=!=-1, y!=-1 thi khi t k di chuyen nua, chuot se tro lai -1,-1 khong thuoc button cho truoc(dinh,canh,...) nen k giu lai mau moi, ma doi lai mau cu 
						// co nghia la khi chuot dung yen tai button thi khong phai to mau lai cu, x=-1,y=-1 thoa (x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi)==false
						// chay vao button to mau, sau do con tro chuot dung tai do thi no se tra ve -1 -1. neu k co !=-1 thi  -1-1 thoa (x>=a.xdau&&x<=a.xcuoi&&y>=a.ydau&&y<=a.ycuoi)==false, nen no se to mau cu lai cho nut,mac du con tro chuot van nam trong do nhung gia tri tra ve cua no la -1 -1
						// khi dung o ngoai button va dung yen thi dong nay cung khong chay
						// nhung no se chay trong luc di chuyen con tro chuot di ra ngoai button, co nghia la con tro chuot dang di chuyen , nen getmouse tra ve gia tri nao do	
		a.isChangeColor=false;
		
		if (a.content=="DINH"||a.content=="CANH")
		{
			setMenu();
			drawMenuButtonTren(b);
		}
		else if(a.content=="TEP")
		{
			setButton(a);	
		}
		else if( a.content=="THUAT TOAN")
		{
			setMenu();
			drawMenuButton(b);
			
		}
		else
		{
			setButton(a);
		}
		fflush(stdin);
	}
	fflush(stdin);
}

void batDkChuotMenuChild(button &a, int xchuot, int ychuot,button b[],button benNgoai)
{
	if(ismouseclick(WM_LBUTTONUP))
	{
		int xtam; int ytam;
		getmouseclick(WM_LBUTTONUP,xtam,ytam);
		clearmouseclick(WM_LBUTTONUP);
		if(benNgoai.content=="DINH")
		{
			if(xtam>=153&&xtam<=279&&ytam>=27&&ytam<=97)//tao dinh
			{
				taoDinh();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=98&&ytam<=166)	//sua dinh
			{
				suaDinh();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=167&&ytam<=235)//xoa dinh
			{
				xoaDinh();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=236&&ytam<=304)// di chuyen
			{
				diChuyenDinh();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=305&&ytam<=373)// huong dan
			{
				huongDanDinh();
			}
		}
		else if(benNgoai.content=="CANH")
		{
			if(xtam>=153&&xtam<=279&&ytam>=119&&ytam<=183)
			{
				taoCanh();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=247&&ytam<=307)
			{
				xoaCanh();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=184&&ytam<=246)
			{
				suaTrongSo();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=310&&ytam<=373)
			{
				huongDanCanh();
			}
		}
		else if(benNgoai.content=="TEP")
		{
			if(xtam>=153&&xtam<=279&&ytam>=303&&ytam<=338)
			{
				saveFile();
			}
			else if(xtam>=153&&xtam<=279&&ytam>=339&&ytam<=373)
			{
				readFile();
			}
		}
		setThongTin();
		setMenu();
		drawMenuButtonTren(b);
		a.isChangeColor=false;
		clearmouseclick(WM_LBUTTONUP);
		return;
	}
	if(xchuot>=a.xdau&&xchuot<=a.xcuoi&&ychuot>=a.ydau&&ychuot<=a.ycuoi&&a.isChangeColor==false)
	{
		doiMauButton(a,a.mauKhiCham);
		a.isChangeColor=true;
	}
	else if(a.isChangeColor==true&&(xchuot>=a.xdau&&xchuot<=a.xcuoi&&ychuot>=a.ydau&&ychuot<=a.ycuoi)==false&&xchuot!=-1&&ychuot!=-1)// neu no dung yen thi khong can phai to mau cu lai
	{
		setButton(a);
		a.isChangeColor=false;
	}
	clearmouseclick(WM_LBUTTONUP);
}

void batDkChuotMenuChildThuatToan(button &a, int xchuot, int ychuot,button b[])
{
	if(ismouseclick(WM_LBUTTONDOWN))
	{
		int xtam; int ytam;
		getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
		clearmouseclick(WM_LBUTTONDOWN);
		if(xtam>=20&&xtam<=99&&ytam>=20&&ytam<=98)
		{
			thuatToanDFS();
			//InRaMatrix();
		}
		else if(xtam>=20&&xtam<=99&&ytam>=300&&ytam<=378)
		{
			cout<<"TIM THANH PHAN LIEN THONG"<<endl;
			TPLT();
		}
		else if(xtam>=20&&xtam<=99&&ytam>=114&&ytam<=192)
		{
			thuatToanDinhTru();
		}
		else if(xtam>=207&&xtam<=285&&ytam>=20&&ytam<=98)
		{
			XtoY();
		}
		else if(xtam>=20&&xtam<=99&&ytam>=207&&ytam<=285)
		{
			thuatToanHamilton();
		}
		else if(xtam>=114&&xtam<=192&&ytam>=20&&ytam<=98)
		{
			thuatToanBFS();
		}
		else if(xtam>=207&&xtam<=285&&ytam>=114&&ytam<=192)
		{
			thuatToanCanhCau();
		}
		else if(xtam>=114&&xtam<=192&&ytam>=114&&ytam<=192)
		{
			thuatToanDinhThat();
		}
		else if(xtam>=114&&xtam<=192&&ytam>=207&&ytam<=285)
		{
			thuatToanEulerCycle();
		}
		else if(xtam>=207&&xtam<=285&&ytam>=207&&ytam<=285)
		{
			thuatToanTopoSort();
		}
	}
	 if(xchuot>=a.xdau&&xchuot<=a.xcuoi&&ychuot>=a.ydau&&ychuot<=a.ycuoi&&a.isChangeColor==false)
	{
		doiMauButton(a,a.mauKhiCham);
		a.isChangeColor=true;
	}
	else if(a.isChangeColor==true&&(xchuot>=a.xdau&&xchuot<=a.xcuoi&&ychuot>=a.ydau&&ychuot<=a.ycuoi)==false&&xchuot!=-1&&ychuot!=-1)// neu no dung yen thi khong can phai to mau cu lai
	{
		setButton(a);
		a.isChangeColor=false;
	}
	clearmouseclick(WM_LBUTTONDOWN);
}

// ===================================================

// =============== CHAY CHUONG TRINH =================
void xuLiChuot(button a[], button menuChild[][13])
{
	int x=0,y=0;
	while(true)
	{
		delay(1);
		getmouseclick(WM_MOUSEMOVE,x,y);
		for(int i=0;i<=6;i++)
		{
			batDkChuot(a[i],x,y,menuChild, a);
		}
	}
}

void xuLi()
{
	button a[11];
	taoMangButton(a);
	button menuChild[4][13];
	setUpMenuChild(menuChild);
	drawMenuButton(a);
	xuLiChuot(a, menuChild);
}

// ===================================================

// ==================== PHIM TAT =====================
void taoDinhPhimTat(int xtam, int ytam)
{
	Dinh a;
	fflush(stdin);
	if(soLuongDinh==soLuongDinhMax)
	{
		outtextxy(355,480,"DAY ROI, VUI LONG XOA BOT DINH");
		while(!kbhit());
		fflush(stdin);
		setThongTin();
		return;
	}
	setThongTin();
	setbkcolor(mauxanhgiongaokhoaccrush);
	clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
			if(xtam>=305+Rvongtron&&xtam-Rvongtron<=1275&&ytam>=5+Rvongtron&&ytam<=450-Rvongtron&&kiemTraTrungViTriDinh(xtam,ytam)==false)
			{
				a.toaDoX=xtam;
				a.toaDoY=ytam;
				
				circle(xtam,ytam,Rvongtron);
				setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
				floodfill(xtam,ytam,15);
			}
			else return;
	fflush(stdin);
	clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
	
	setbkcolor(mauxanhgiongaokhoaccrush);
	fflush(stdin);
	outtextxy(355,495,"NHAP TEN DINH: ");

	fflush(stdin);
	char s;
	char c[2];
	c[0]='1';
	c[1]='\0';
	fflush(stdin);
	while(true)
	{
		//char s='0';
		if(kbhit())
		{
			s =getch();
			fflush(stdin);
			if(((s>=97&&s<=122)||(s>=65&&s<=90)))
			{
				if(s>=65&&s<=90)
				{
					c[0]= s;
				}
				else
				{
					c[0]= s-32;
				}
				outtextxy(475,495,c);
				fflush(stdin);
			}
			else if(s==8)
			{
				c[0]=' ';
				outtextxy(475,495,c);
				moveto(475,495);
				fflush(stdin);
			}
			else if(s==13&&(c[0]>=65&&c[0]<=90)==true)
			{
				fflush(stdin);
				break;
			}
		}
	}
	if(c[0]>=65&&c[0]<=90)
	{
		a.name[0]=c[0];
		a.name[1]='\0';
		if(kiemTraTrungTenDinh(a)==true)
		{
			setcolor(MauNenDoThi);
			setfillstyle(SOLID_FILL,MauNenDoThi);
			pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
			setcolor(15);
			outtextxy(355,495+15,"TRUNG TEN DINH ROI");
			//while(!kbhit());
			fflush(stdin);
			setThongTin();
			
		}
		else
		{
			themVaoMainDinh(a);
			ve1Dinh(a);
			veMatrix();
			setMenu();
			fflush(stdin);
		}
	}
	else
	{
		setcolor(MauNenDoThi);
		setfillstyle(SOLID_FILL,MauNenDoThi);
		pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
		setcolor(15);
	}
}

void xoaDinhPhimTat(int xtam, int ytam)
{
	clearmouseclick(WM_LBUTTONDOWN);
	int vitri=viTriDinh(xtam,ytam);
	if(vitri!=-1)
	{
		nhanVaoDinh(mainDinh[vitri]);
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,495,"NHAN DELETE DE XOA");
				
		int xdau=305;int xcuoi=1275;
		int ydau=5;	int ycuoi=450;
								
		setfillstyle(SOLID_FILL,MauNenDoThi);
		bar(xdau,ydau,xcuoi,ycuoi);
								
		rectangle(xdau,ydau,xcuoi,ycuoi);
		setDoThi();
								
		xoaDinhTrongArray(vitri);
		//xoa1DinhTrongMatrix(vitri);
		veMatrix();
		veAllDoThi();			
	}
	veMatrix();
}

void huongDanF1()
{
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO TUNG PHAN DE CO THE SU DUNG CHUC NANG ");
	outtextxy(355,480+15,"HOAC DUNG PHIM TAT ");
	outtextxy(355,480+30,"LM: Click chuot trai de tao dinh ");
	outtextxy(355,480+45,"RM: Click chuot phai de xoa dinh ");
	outtextxy(355,480+60,"F2: nhan F2 de tao canh ");
	outtextxy(355,480+75,"F3: nhan F3 de xoa canh ");
	outtextxy(355,480+90,"F4: nhan F4 de sua trong so ");
	outtextxy(355,480+105,"F5: nhan F5 de sua dinh ");
	outtextxy(355,480+120,"F6: nhan F6 de di chuyen dinh ");
	outtextxy(355,480+135,"NHAN NUT BAT KI");
	while(!kbhit());
	fflush(stdin);
	setThongTin();
}


// =================== HAM DINH ======================
void ve1Dinh(Dinh a)
{
	setcolor(mauvongtron);
	setfillstyle(SOLID_FILL,mauvongtron);
	pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
	setcolor(15);
	
	circle(a.toaDoX,a.toaDoY,Rvongtron);
	
	setbkcolor(mauvongtron);
	outtextxy(a.toaDoX-4,a.toaDoY-4,a.name);
}

void themVaoMainDinh(Dinh a)
{
	mainDinh[soLuongDinh]=a;
	for(int i=0;i<=soLuongDinh;i++)
	{
		matrix[i][soLuongDinh]=0;
		matrix[soLuongDinh][i]=0;
	}
	soLuongDinh++;
}

void xoaDinhTrongArray(int vt)
{	
	for(int i=vt;i<soLuongDinh-1;i++)
	{
		mainDinh[i]=mainDinh[i+1];
	}
	soLuongDinh--;
}

void xoa1DinhTrongMatrix(int vt)
{
	for (int i=vt;i<soLuongDinh-1;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			matrix[i][j]= matrix[i+1][j];
		}
	}
	//cho j la cot, i la hang
	for (int j=vt;j<soLuongDinh-1;j++)
	{
		for(int i=0;i<soLuongDinh;i++)
		{
			matrix[i][j]= matrix[i][j+1];
		}
	}
	soLuongDinh--;
}

void nhanVaoDinh(Dinh a)
{
	setcolor(nhanDinh);
	setfillstyle(SOLID_FILL,nhanDinh);
	pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
	setcolor(15);
	
	circle(a.toaDoX,a.toaDoY,Rvongtron);
	
	setbkcolor(nhanDinh );
	outtextxy(a.toaDoX-4,a.toaDoY-4,a.name);
}

void nhanVaoDinhChonMau(Dinh a, int color)
{
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
	setcolor(15); 
	
	circle(a.toaDoX,a.toaDoY,Rvongtron);
	
	setbkcolor(color);
	outtextxy(a.toaDoX-4,a.toaDoY-4,a.name);
}

int viTriDinh(int x, int y)
{
	for(int i=0;i<soLuongDinh;i++)
	{
		if(pow(mainDinh[i].toaDoX-x,2)+pow(mainDinh[i].toaDoY-y,2)<=pow(Rvongtron,2))
		{
			return i;
		}
	}
	return -1;
}

bool kiemTraTrungTenDinh(Dinh a)
{
	for(int i=0;i<soLuongDinh;i++)
	{
		if(mainDinh[i].name[0]==a.name[0])
		{
			return true;
		}
	}
	return false;
}

bool kiemTraTrungViTriDinh(int x, int y)
{
	for(int i=0;i<soLuongDinh;i++)
	{
		if(pow((mainDinh[i].toaDoX-x),2)+pow((mainDinh[i].toaDoY-y),2)<=pow(Rvongtron+25+25,2))
		{
			return true;
		}
	}
	return false;
}

bool kiemTraTrungViTriDinhNgoaiViTri(int x, int y, int vt)
{
	for(int i=0;i<soLuongDinh&&i!=vt;i++)
	{
		if((pow((mainDinh[i].toaDoX-x),2)+pow((mainDinh[i].toaDoY-y),2)<=pow(Rvongtron+25+25,2)))
		{
			return true;
		}
	}
	return false;
}

		
void taoDinh()
{
	Dinh a;
	fflush(stdin);
	if(soLuongDinh==soLuongDinhMax)
	{
		outtextxy(355,480,"DAY ROI, VUI LONG XOA BOT DINH");
		while(!kbhit());
		fflush(stdin);
		setThongTin();
		return;
	}
	//setThongTin();
	setbkcolor(mauxanhgiongaokhoaccrush);
	clearmouseclick(WM_LBUTTONDOWN);
	outtextxy(355,480,"CLICK VAO VI TRI CAN TAO");
	fflush(stdin);
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam, ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			if(xtam>=305+Rvongtron&&xtam-Rvongtron<=1275&&ytam>=5+Rvongtron&&ytam<=450-Rvongtron&&kiemTraTrungViTriDinh(xtam,ytam)==false)
			{
				a.toaDoX=xtam;
				a.toaDoY=ytam;
				
				circle(xtam,ytam,Rvongtron);
				setfillstyle(SOLID_FILL,mauxanhgiongaokhoaccrush);
				floodfill(xtam,ytam,15);
				
				break;
			}
		}
	}
	fflush(stdin);
	clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
	
	setbkcolor(mauxanhgiongaokhoaccrush);
	fflush(stdin);
	outtextxy(355,495,"NHAP TEN DINH: ");

	fflush(stdin);
	char s;
	char c[2];
	c[0]='1';
	c[1]='\0';
	fflush(stdin);
	while(true)
	{
		
		if(kbhit())
		{
			s =getch();
			fflush(stdin);
			if(((s>=97&&s<=122)||(s>=65&&s<=90)))
			{
				if(s>=65&&s<=90)
				{
					c[0]= s;
				}
				else
				{
					c[0]= s-32;
				}
				outtextxy(475,495,c);
				fflush(stdin);
			}
			else if(s==8)
			{
				c[0]=' ';
				outtextxy(475,495,c);
				//moveto(475,495);
				fflush(stdin);
			}
			else if(s==13&&(c[0]>=65&&c[0]<=90)==true)
			{
				fflush(stdin);
				break;
			}
		}
	}
	if(c[0]>=65&&c[0]<=90)
	{
		a.name[0]=c[0];
		a.name[1]='\0';
		if(kiemTraTrungTenDinh(a)==true)
		{
			
			setcolor(MauNenDoThi);
			setfillstyle(SOLID_FILL,MauNenDoThi);
			pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
			
			setcolor(15);
			outtextxy(355,495+15,"TRUNG TEN DINH ROI");
			
			fflush(stdin);
			while(!kbhit());
			fflush(stdin);
			setThongTin();
		}
		else
		{
			themVaoMainDinh(a);
			ve1Dinh(a);
			veMatrix();
			setMenu();
			fflush(stdin);
		}
	}
	else
	{
		setcolor(MauNenDoThi);
		setfillstyle(SOLID_FILL,MauNenDoThi);
		pieslice(a.toaDoX,a.toaDoY,0,360,Rvongtron);
		setcolor(15);
	}
}

void xoaDinh()
{
	clearmouseclick(WM_LBUTTONDOWN);
	if(soLuongDinh==0)
	{
		
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"KHONG CO DINH DE XOA");
		outtextxy(355,480+15,"NHAN NUT BAT KI DE TRO LAI");
		fflush(stdin);
		while(!kbhit());
		fflush(stdin);
		return;
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO DINH");
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			int vitri=viTriDinh(xtam,ytam);
			if(vitri!=-1)
			{
				nhanVaoDinh(mainDinh[vitri]);
				setbkcolor(mauxanhgiongaokhoaccrush);
				outtextxy(355,495,"NHAN DELETE DE XOA");
				while(true)
				{
					if(kbhit())
					{
						char s=getch();
						if(s==83)// nut delete
						{
								int xdau=305;int xcuoi=1275;
								int ydau=5;	int ycuoi=450;
								
								setfillstyle(SOLID_FILL,MauNenDoThi);
								bar(xdau,ydau,xcuoi,ycuoi);
								
								rectangle(xdau,ydau,xcuoi,ycuoi);
								setDoThi();
								
								xoaDinhTrongArray(vitri);
								veMatrix();
								veAllDoThi();
							
								break;
						}
					}
				}
				break;
			}

		}
	}
	veMatrix();
	setThongTin();
}

void suaDinh()
{
	clearmouseclick(WM_LBUTTONDOWN);
	if(soLuongDinh==0)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"KHONG CO DINH DE SUA");
		while(!kbhit());
		return;
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO DINH");
	int vitri;
	char s;
	char c[2];
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri=viTriDinh(xtam,ytam);
			if(vitri!=-1)
			{
				nhanVaoDinh(mainDinh[vitri]);
				setbkcolor(mauxanhgiongaokhoaccrush);
				outtextxy(355,495,"TEN DINH: ");

				c[0]=mainDinh[vitri].name[0];
				c[1]='\0';
				setbkcolor(mauxanhgiongaokhoaccrush);
				outtextxy(427,495,c);
				fflush(stdin);
				while(true)
				{
					if(kbhit())
					{
						s =getch();
						fflush(stdin);
						if(s==8)
						{
							c[0]=' ';
							outtextxy(427,495,c);
							moveto(427,495);
							fflush(stdin);
						}
						else if(s==13&&(c[0]>=65&&c[0]<=90)==true)
						{
							fflush(stdin);
							break;
						}
						else if((s>=97&&s<=122)||(s>=65&&s<=90))
						{
							if(s>=65&&s<=90)
							{
								c[0]= s;
							}
							else
							{
								c[0]= s-32;
							}
							outtextxy(427,495,c);
							fflush(stdin);
						}
					}
				}
				break;
			}
		}
	}
	Dinh a;
	a.name[0]=c[0];
	a.name[1]='\0';
	if(kiemTraTrungTenDinh(a)==true)
	{
		setcolor(15);
		outtextxy(355,495+15,"TRUNG TEN DINH ROI");
		while(!kbhit());
		setMenu();
	}
	else
	{
		mainDinh[vitri].name[0]=a.name[0];
		mainDinh[vitri].name[1]=a.name[1];
		outtextxy(355,495+15,"THANH CONG");
	}
	ve1Dinh(mainDinh[vitri]);
	veMatrix();
	setThongTin();
}

void diChuyenDinh()
{
	clearmouseclick(WM_LBUTTONDOWN);
	if(soLuongDinh==0)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"KHONG CO DINH DE XOA");
		outtextxy(355,480+15,"NHAN NUT BAT KI DE TRO LAI");
		fflush(stdin);
		while(!kbhit());
		return;
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO DINH");
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			int vitri=viTriDinh(xtam,ytam);
			if(vitri!=-1)
			{
				nhanVaoDinh(mainDinh[vitri]);
				setbkcolor(mauxanhgiongaokhoaccrush);
				outtextxy(355,480+15,"CLICK VAO VI TRI CAN DI CHUYEN");
				while(true)
				{
					delay(1);
					if(ismouseclick(WM_LBUTTONDOWN))
					{
						int xtam1,ytam1;
						getmouseclick(WM_LBUTTONDOWN,xtam1,ytam1);
						if(kiemTraTrungViTriDinhNgoaiViTri(xtam1,ytam1,vitri)==false)
						{
							cout<<"xtam: "<<xtam<<endl;
							cout<<"ytam: "<<ytam<<endl;
							cout<<"xtam1: "<<xtam1<<endl;
							cout<<"ytam1: "<<ytam1<<endl;
							
							int xdau=305;int xcuoi=1275;
							int ydau=5;	int ycuoi=450;
								
							setfillstyle(SOLID_FILL,MauNenDoThi);
							bar(xdau,ydau,xcuoi,ycuoi);
								
							rectangle(xdau,ydau,xcuoi,ycuoi);
							setDoThi();
								
							mainDinh[vitri].toaDoX=xtam1;
							mainDinh[vitri].toaDoY=ytam1;
							
							veAllDoThi();
							
							break;
						}
					}
				}
				break;
			}
		}
	}
	veMatrix();
	setThongTin();
}

void huongDanDinh()
{
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO TUNG PHAN DE CO THE SU DUNG CHUC NANG ");
	outtextxy(355,480+15,"HOAC DUNG PHIM TAT ");
	outtextxy(355,480+30,"LM: Click chuot trai de tao dinh ");
	outtextxy(355,480+45,"RM: Click chuot phai de xoa dinh ");
	outtextxy(355,480+60,"F5: nhan F5 de sua dinh ");
	outtextxy(355,480+75,"F6: nhan F6 de di chuyen dinh ");
	outtextxy(355,480+90,"NHAN NUT BAT KI");
	while(!kbhit());
	fflush(stdin);
	setThongTin();
	
}

// ===================================================

// =================== HAM CANH ======================
void ve1Canh(Dinh dau, Dinh cuoi, int trongso)
{
	if(soLuongDinh<2)
	{
		return;
	}
	line(dau.toaDoX,dau.toaDoY,cuoi.toaDoX,cuoi.toaDoY);
	veMuiTen(dau,cuoi,15);

	int xgiua=(dau.toaDoX+cuoi.toaDoX)/2;
	int ygiua=(dau.toaDoY+cuoi.toaDoY)/2;
	setbkcolor(mauvongtron);
	if(trongso<10)
	{
		char c[2];
		c[0]=trongso+48;
		c[1]='\0';
		outtextxy(xgiua+15,ygiua+5,c);
	}
	else
	{
		char c[3];
		c[0]=trongso/10 +48;
		c[1]=trongso%10+48;
		c[2]='\0';
		outtextxy(xgiua+15,ygiua+5,c);
	}
}

void xoa1Canh(Dinh dau, Dinh cuoi)
{
	setcolor(MauNenDoThi);
	line(dau.toaDoX,dau.toaDoY,cuoi.toaDoX,cuoi.toaDoY);
	xoaMuiTen(dau,cuoi);
	int xgiua=(dau.toaDoX+cuoi.toaDoX)/2;
	int ygiua=(dau.toaDoY+cuoi.toaDoY)/2;
	setfillstyle(SOLID_FILL,MauNenDoThi);
	bar(xgiua+15-1,ygiua+7-2,xgiua+15+16+4,ygiua+7+8+4);

	setcolor(15);
}

void veMuiTen(Dinh dau, Dinh cuoi, int color)
{
	const int R = 12;
	const double PI = 3.14159265;
	Dinh d1, d2, d3, d;
	d.toaDoX = (dau.toaDoX+ cuoi.toaDoX) / 2;
	d.toaDoY = (dau.toaDoY + cuoi.toaDoY) / 2;
	setcolor(15);
	double result;
	double tanalpha = 0;
	struct arccoordstype h;
	if (cuoi.toaDoX > dau.toaDoX && cuoi.toaDoY < dau.toaDoY){
		
		tanalpha = 1.0*(dau.toaDoY - cuoi.toaDoY) / (cuoi.toaDoX - dau.toaDoX);
		result = atan(tanalpha) * 180 / PI;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, result + 90, R);
		setcolor(15);
		getarccoords(&h);
		
		d1.toaDoX = h.xend;
		d1.toaDoY = h.yend;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, result + 90, result + 90 + 180, R);
		
		getarccoords(&h);
		setcolor(15);
		d2.toaDoX = h.xend;
		d2.toaDoY = h.yend;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, result, R);
		
		getarccoords(&h);
		setcolor(15);
		d3.toaDoX = h.xend;
		d3.toaDoY = h.yend;
	}
	else if (cuoi.toaDoX < dau.toaDoX && cuoi.toaDoY > dau.toaDoY){
		tanalpha = 1.0*(cuoi.toaDoY - dau.toaDoY) / (dau.toaDoX - cuoi.toaDoX);
		result = atan(tanalpha) * 180 / PI;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, result + 90, R);
		
		getarccoords(&h);
		setcolor(15);
		d1.toaDoX = h.xend;
		d1.toaDoY = h.yend;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, result + 90, result + 90 + 180, R);
		
		getarccoords(&h);
		setcolor(15);
	//	getarccoords(&h);
		d2.toaDoX = h.xend;
		d2.toaDoY = h.yend;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, result, 180 + result, R);
		
		getarccoords(&h);
		setcolor(15);
		//getarccoords(&h);
		d3.toaDoX = h.xend;
		d3.toaDoY = h.yend;
	}
	else if (cuoi.toaDoX < dau.toaDoX && cuoi.toaDoY < dau.toaDoY){
		tanalpha = 1.0*(cuoi.toaDoY - dau.toaDoY) / (cuoi.toaDoX - dau.toaDoX);
		result = atan(tanalpha) * 180 / PI;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, 90 - result, R);
		
		getarccoords(&h);
		setcolor(15);
		//getarccoords(&h);
		d1.toaDoX = h.xend;
		d1.toaDoY = h.yend;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 90 - result, 90 - result + 180, R);
		
		getarccoords(&h);
		setcolor(15);
	//	getarccoords(&h);
		d2.toaDoX = h.xend;
		d2.toaDoY = h.yend;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, 180 - result, R);
		
		getarccoords(&h);
		setcolor(15);
		//getarccoords(&h);
		d3.toaDoX = h.xend;
		d3.toaDoY = h.yend;
	}
	else if (cuoi.toaDoX > dau.toaDoX && cuoi.toaDoY > dau.toaDoY){
		tanalpha = 1.0*(cuoi.toaDoY - dau.toaDoY) / (cuoi.toaDoX - dau.toaDoX);
		result = atan(tanalpha) * 180 / PI;
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, 90 - result, R);
		setcolor(15);
		
		getarccoords(&h);
		setcolor(15);
		
		d1.toaDoX = h.xend;
		d1.toaDoY = h.yend;
		
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 90 - result, 90 - result + 180, R);
		setcolor(15);
		
		getarccoords(&h);
	
		d2.toaDoX = h.xend;
		d2.toaDoY = h.yend;
		
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, -result, 0, R);
		setcolor(15);
		
		getarccoords(&h);

		d3.toaDoX = h.xstart;
		d3.toaDoY = h.ystart;
	}
	else if (dau.toaDoY == cuoi.toaDoY){
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, 90, R);
		getarccoords(&h);
		d1.toaDoX = h.xend;
		d1.toaDoY = h.yend;
		
		arc(d.toaDoX, d.toaDoY, 90, 90 + 180, R);
	
		getarccoords(&h);
		setcolor(15);
	//	getarccoords(&h);
		d2.toaDoX = h.xend;
		d2.toaDoY = h.yend;
		if (dau.toaDoX < cuoi.toaDoX)
		{
			setcolor(MauNenDoThi);
			arc(d.toaDoX, d.toaDoY, 0, 0, R);
			
			getarccoords(&h);
			setcolor(15);
		//	getarccoords(&h);
			d3.toaDoX = h.xstart;
			d3.toaDoY = h.ystart;
		}
		else
		{
			setcolor(MauNenDoThi);
			arc(d.toaDoX, d.toaDoY, 0, 180, R);
			setcolor(15);
			getarccoords(&h);
			d3.toaDoX = h.xend;
			d3.toaDoY = h.yend;
		}
	}
	else
	{
		setcolor(MauNenDoThi);
		arc(d.toaDoX, d.toaDoY, 0, 180, R);
		setcolor(15);
		getarccoords(&h);
		d1.toaDoX = h.xend;
		d1.toaDoY = h.yend;
		d2.toaDoX = h.xstart;
		d2.toaDoY = h.ystart;
		if (cuoi.toaDoY > dau.toaDoY)
		{
			setcolor(MauNenDoThi);
			arc(d.toaDoX, d.toaDoY, 0, 270, R);
			
			getarccoords(&h);
			setcolor(15);
			d3.toaDoX = h.xend;
			d3.toaDoY = h.yend;
		}
		else
		{
			setcolor(MauNenDoThi);
			arc(d.toaDoX, d.toaDoY, 0, 90, R);
			
			getarccoords(&h);
			setcolor(15);
			
			d3.toaDoX = h.xend;
			d3.toaDoY = h.yend;
		}
	}
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	int a[] = { d3.toaDoX, d3.toaDoY, d1.toaDoX, d1.toaDoY, d2.toaDoX, d2.toaDoY, d3.toaDoX, d3.toaDoY };
	fillpoly(4, a);
	
}

void xoaMuiTen(Dinh x, Dinh y)
{
	int xi= (x.toaDoX+y.toaDoX)/2;
	int yi=(x.toaDoY+y.toaDoY)/2;
	setcolor(MauNenDoThi);
	setfillstyle(SOLID_FILL,MauNenDoThi);
	pieslice(xi,yi,0,360,Rvongtron);
	setcolor(15);
}


void taoCanh()
{
	if(soLuongDinh<=1)
	{
		outtextxy(355,480,"KHONG DU DINH");
		return;
	}
	clearmouseclick(WM_LBUTTONDOWN);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO DINH DAU");
	int vitri1;
	int vitri2;
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN)==true)
		{
			int xtam;
			int ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri1=viTriDinh(xtam,ytam);
			if(vitri1!=-1)
			{
				nhanVaoDinh(mainDinh[vitri1]);
				break;
			}
		}
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480+15,"CLICK VAO DINH CUOI");
	
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN)==true)
		{
			int xtam;
			int ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri2=viTriDinh(xtam,ytam);
			if(vitri2!=-1)
			{
				nhanVaoDinh(mainDinh[vitri2]);
				break;
			}
		}
	}
	if(matrix[vitri1][vitri2]!=0)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480+15+15,"CANH DA TON TAI");
		ve1Dinh(mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
		while(!kbhit());
		return;
	}
	fflush(stdin);
	int trongso = nhapTrongSo();
	matrix[vitri1][vitri2]=trongso;

	if(matrix[vitri2][vitri1]==0)
	{
		ve1Canh(mainDinh[vitri1],mainDinh[vitri2], trongso);
		ve1Dinh(mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
	}
	else
	{
		int denta=DENTA;
		xoa1Canh(mainDinh[vitri2],mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
		ve1Dinh(mainDinh[vitri1]);
		
		Dinh tamdau;										Dinh tamcuoi;
		tamdau.toaDoX=mainDinh[vitri1].toaDoX;				tamcuoi.toaDoX=	mainDinh[vitri2].toaDoX;
		tamdau.toaDoY=mainDinh[vitri1].toaDoY-denta;			tamcuoi.toaDoY=	mainDinh[vitri2].toaDoY-denta;
		
		Dinh tamdau1;
		Dinh tamcuoi1;
		tamdau1.toaDoX=mainDinh[vitri2].toaDoX;					tamcuoi1.toaDoX=mainDinh[vitri1].toaDoX;
		tamdau1.toaDoY=mainDinh[vitri2].toaDoY+denta;			tamcuoi1.toaDoY=mainDinh[vitri1].toaDoY+denta;

		if(abs(tamdau.toaDoX-tamcuoi.toaDoX)<50)//abs(tamdau.toaDoX-tamcuoi1.toaDoX)<15&&
		{
			
			tamdau.toaDoX=mainDinh[vitri1].toaDoX-denta;			tamcuoi.toaDoX=	mainDinh[vitri2].toaDoX-denta;
			tamdau1.toaDoX=mainDinh[vitri2].toaDoX+denta;			tamcuoi1.toaDoX=mainDinh[vitri1].toaDoX+denta;
			
		}
	

		ve1Canh(tamdau,tamcuoi,matrix[vitri1][vitri2]);
		ve1Canh(tamdau1,tamcuoi1,matrix[vitri2][vitri1]);
		
		ve1Dinh(mainDinh[vitri1]); 
		ve1Dinh(mainDinh[vitri2]);
	}
	veMatrix();
	setThongTin();
}

void xoaCanh()
{
	if(soLuongDinh<2)
	{
		outtextxy(355,480,"KHONG CO CANH ");
		return;
	}
	clearmouseclick(WM_LBUTTONDOWN);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO DINH DAU");
	int vitri1;
	int vitri2;
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN)==true)
		{
			int xtam;
			int ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri1=viTriDinh(xtam,ytam);
			if(vitri1!=-1)
			{
				nhanVaoDinh(mainDinh[vitri1]);
				break;
			}
		}
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480+15,"CLICK VAO DINH CUOI");
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN)==true)
		{
			int xtam;
			int ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri2=viTriDinh(xtam,ytam);
			if(vitri2!=-1)
			{
				nhanVaoDinh(mainDinh[vitri2]);
				break;
			}
		}
	}
	matrix[vitri1][vitri2]=0;
	if(matrix[vitri2][vitri1]==0)
	{
		xoa1Canh(mainDinh[vitri1],mainDinh[vitri2]);
		ve1Dinh(mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
	}
	else
	{
		int denta=DENTA;

		Dinh tamdau;										Dinh tamcuoi;
		tamdau.toaDoX=mainDinh[vitri1].toaDoX;		tamcuoi.toaDoX=	mainDinh[vitri2].toaDoX;
		tamdau.toaDoY=mainDinh[vitri1].toaDoY-denta;				tamcuoi.toaDoY=	mainDinh[vitri2].toaDoY-denta;
		
		Dinh tamdau1;
		Dinh tamcuoi1;
		tamdau1.toaDoX=mainDinh[vitri2].toaDoX;				tamcuoi1.toaDoX=mainDinh[vitri1].toaDoX;
		tamdau1.toaDoY=mainDinh[vitri2].toaDoY+denta;			tamcuoi1.toaDoY=mainDinh[vitri1].toaDoY+denta;

		if(abs(tamdau.toaDoX-tamcuoi.toaDoX)<50)//abs(tamdau.toaDoX-tamcuoi1.toaDoX)<15&&
		{
			tamdau.toaDoX=mainDinh[vitri1].toaDoX-denta;		tamcuoi.toaDoX=	mainDinh[vitri2].toaDoX-denta;
			tamdau1.toaDoX=mainDinh[vitri2].toaDoX+denta;			tamcuoi1.toaDoX=mainDinh[vitri1].toaDoX+denta;
		}
		xoa1Canh(tamdau, tamcuoi);
		xoa1Canh(tamdau1,tamcuoi1);
	
		ve1Canh(mainDinh[vitri2],mainDinh[vitri1],matrix[vitri2][vitri1]);
		ve1Dinh(mainDinh[vitri1]); 
		ve1Dinh(mainDinh[vitri2]);
	}
	veMatrix();
	outtextxy(355,530+15,"THANH CONG");
	while(!kbhit);
}

int nhapTrongSo()
{
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,530,"NHAP TRONG SO: ");
	char c[2];
	int i=0;
	do
	{
		while(!kbhit());
		char s=getch();
		fflush(stdin);
		if(s!=13&&s!=8&&s-48>=0&&s-48<=9&&i<=1)
		{
			c[i]=s;
			char tam[2];
			tam[0]=s;
			tam[1]='\0';
			outtextxy(475+i*8,530,tam);
			i++;
		}
		else if(s==8&&i>0)
		{
			i--;
			outtextxy(475+i*8,530," ");
		}
		else if(s==13&&c[0]!='0'&&i>0)
		{
			break;
		}
		fflush(stdin);
	}
	while(true);
	int trongso=0;
	for(int j=0;j<i;j++)
	{
		trongso=trongso*10+(c[j]-48);
	}
	return trongso;
}

void suaTrongSo()
{
	if(soLuongDinh<2)
	{
		outtextxy(355,480,"KHONG CO CANH ");
		return;
	}
	clearmouseclick(WM_LBUTTONDOWN);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO DINH DAU");
	int vitri1;
	int vitri2;
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN)==true)
		{
			int xtam;
			int ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri1=viTriDinh(xtam,ytam);
			if(vitri1!=-1)
			{
				nhanVaoDinh(mainDinh[vitri1]);
				break;
			}
		}
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480+15,"CLICK VAO DINH CUOI");
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN)==true)
		{
			int xtam;
			int ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri2=viTriDinh(xtam,ytam);
			if(vitri2!=-1)
			{
				nhanVaoDinh(mainDinh[vitri2]);
				break;
			}
		}
	}
	int trongso = nhapTrongSo();
	
	matrix[vitri1][vitri2]=trongso;
	if(matrix[vitri2][vitri1]==0)
	{
		xoa1Canh(mainDinh[vitri1],mainDinh[vitri2]);
		ve1Canh(mainDinh[vitri1],mainDinh[vitri2],trongso);
		ve1Dinh(mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
	}
	else
	{
		int denta=DENTA;
		xoa1Canh(mainDinh[vitri2],mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
		ve1Dinh(mainDinh[vitri1]);
		
		Dinh tamdau;										Dinh tamcuoi;
		tamdau.toaDoX=mainDinh[vitri1].toaDoX;		tamcuoi.toaDoX=	mainDinh[vitri2].toaDoX;
		tamdau.toaDoY=mainDinh[vitri1].toaDoY-denta;				tamcuoi.toaDoY=	mainDinh[vitri2].toaDoY-denta;
		
		Dinh tamdau1;
		Dinh tamcuoi1;
		tamdau1.toaDoX=mainDinh[vitri2].toaDoX;				tamcuoi1.toaDoX=mainDinh[vitri1].toaDoX;
		tamdau1.toaDoY=mainDinh[vitri2].toaDoY+denta;			tamcuoi1.toaDoY=mainDinh[vitri1].toaDoY+denta;

		if(abs(tamdau.toaDoX-tamcuoi.toaDoX)<50)//abs(tamdau.toaDoX-tamcuoi1.toaDoX)<15&&
		{
			tamdau.toaDoX=mainDinh[vitri1].toaDoX-denta;		tamcuoi.toaDoX=	mainDinh[vitri2].toaDoX-denta;
			tamdau1.toaDoX=mainDinh[vitri2].toaDoX+denta;			tamcuoi1.toaDoX=mainDinh[vitri1].toaDoX+denta;
		}
		
		ve1Canh(tamdau,tamcuoi,matrix[vitri1][vitri2]);
		ve1Canh(tamdau1,tamcuoi1,matrix[vitri2][vitri1]);
		
		ve1Dinh(mainDinh[vitri1]); 
		ve1Dinh(mainDinh[vitri2]);
	}
	veMatrix();
}

void huongDanCanh()
{
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CLICK VAO TUNG PHAN DE CO THE SU DUNG CHUC NANG ");
	outtextxy(355,480+15,"HOAC DUNG PHIM TAT ");
	outtextxy(355,480+30,"F2: nhan F2 de tao canh ");
	outtextxy(355,480+45,"F3: nhan F3 de xoa canh ");
	outtextxy(355,480+60,"F4: nhan F4 de sua trong so ");
	outtextxy(355,480+75,"NHAN NUT BAT KI");
	while(!kbhit());
	fflush(stdin);
	setThongTin();
}

// ===================================================


// ====================== FILE =======================
void saveFile()
{
	char tenFile[35];
	int n=0;
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355, 460, "NHAP TEN FILE MUON LUU");
	outtextxy(355, 480, "TEN FILE: ");
	char s;
	while(true)
	{
		if(kbhit())
		{
		s=getch();
		fflush(stdin);
		if(((s<=57&&s>=48)||(s>=65&&s<=90)||(s>=97&&s<=122))&&n<30)
		{
			tenFile[n]=s;
			tenFile[n+1]='\0';
			n++;
			outtextxy(390+45, 480, tenFile);
		}
		else if(s==8&&n!=0)
		{
			tenFile[n-1]='\0';
			n--;
			outtextxy(390+45, 480, "                                           ");
			outtextxy(390+45, 480, tenFile);
		}
		else if(s==13)
		{
			break;
		}
		fflush(stdin);
		}
	}
		tenFile[n]='.';
		n++;
		tenFile[n]='t';
		n++;
		tenFile[n]='x';
		n++;
		tenFile[n]='t';
		tenFile[n+1]='\0';
		n++;

	ofstream fileOut;
	fileOut.open(tenFile,ios_base::out);
	if(fileOut.fail())
	{
		fflush(stdin);
		outtextxy(405, 495, "MO FILE THAT BAI!!!");
		while(!kbhit());
		fflush(stdin);
		setThongTin();
		return;
	}
	fileOut << soLuongDinh << endl;
	for(int i = 0; i<soLuongDinh; i++)
	{
		fileOut << mainDinh[i].name << " " << mainDinh[i].toaDoX << " " << mainDinh[i].toaDoY << endl;
	}
	for(int i=0;i< soLuongDinh; i++)
	{
		for(int j=0; j<soLuongDinh; j++)
		{
			if(matrix[i][j]!=0)
			{
				fileOut << i<<" "<<mainDinh[i].name << "\t";
				fileOut << j<<" "<<mainDinh[j].name <<"\t";
				fileOut	<<matrix[i][j]<<endl;
			}
		}
	}
	fileOut.close();
	outtextxy(405, 495, "DA LUU FILE!!");
	outtextxy(355,680,"NHAN NUT BAT KI");
	while(!kbhit());
	fflush(stdin);
}

void readFile()
{
	//clear do thi
	int xdau=305;int xcuoi=1275;
	int ydau=5;	int ycuoi=450;
	setfillstyle(SOLID_FILL,MauNenDoThi);
	bar(xdau,ydau,xcuoi,ycuoi);
	rectangle(xdau,ydau,xcuoi,ycuoi);
	soLuongDinh=0;		
	setMatrix();
	setDoThi();
	setThongTin();
	//end clear
	char tenFile[35];
	int n=0;
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355, 460, "NHAP TEN FILE MUON MO");
	outtextxy(355, 480, "TEN FILE ");
	char s;
	while(true)
	{
		if(kbhit())
		{
		s=getch();
		fflush(stdin);
		if(((s<=57&&s>=48)||(s>=65&&s<=90)||(s>=97&&s<=122))&&n<30)
		{
			tenFile[n]=s;
			tenFile[n+1]='\0';
			n++;
			outtextxy(390+45, 480, tenFile);
		}
		else if(s==8&&n!=0)
		{
			tenFile[n-1]='\0';
			n--;
			outtextxy(390+45, 480, "                                           ");
			outtextxy(390+45, 480, tenFile);
		}
		else if(s==13)
		{
			break;
		}
		fflush(stdin);
		}
	}
		tenFile[n]='.';
		n++;
		tenFile[n]='t';
		n++;
		tenFile[n]='x';
		n++;
		tenFile[n]='t';
		tenFile[n+1]='\0';
		n++;	
	
	ifstream fileIn;
	fileIn.open(tenFile,ios_base::in);	
	if(fileIn.fail())
	{
		outtextxy(355, 495, "MO FILE THAT BAI!");
		while(!kbhit());
		fflush(stdin);
		return;
	}
	fileIn >> soLuongDinh;
	giaiPhongMatrix(soLuongDinhMax);
	khoiTaoMatrix(soLuongDinhMax);
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			matrix[i][j]=0;
		}
	}
	for(int i = 0; i<soLuongDinh; i++)
	{
		fileIn >> mainDinh[i].name;
		fileIn >> mainDinh[i].toaDoX; 
		fileIn >> mainDinh[i].toaDoY;
	}
	while(!fileIn.eof())
	{
		int vitri1, vitri2;
		int trongso;
		char tam;
		fileIn >> vitri1;
		fileIn>>tam;
		fileIn >> vitri2;
		fileIn>>tam;
		fileIn>>trongso;
		matrix[vitri1][vitri2]=trongso;
	}
	cout<<soLuongDinh<<endl;
	for(int i=0;i<soLuongDinh;i++)
	{
		cout<<mainDinh[i].name<<" "<<mainDinh[i].toaDoX<<" "<<mainDinh[i].toaDoY<<endl;
	}
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	fileIn.close();
	outtextxy(355, 495, "DA DOC FILE !");
	outtextxy(355,680,"NHAN NUT BAT KI");
	veAllDoThi();
	veMatrix();
}

void tuDongLuuFileKhiThoat()
{
	char tenFile[20]="dothivualam.txt";
	ofstream fileOut;
	fileOut.open(tenFile,ios_base::out);
	if(fileOut.fail())
	{
		outtextxy(405, 495, "MO FILE THAT BAI!!!");
		return;
	}
	fileOut << soLuongDinh << endl;
	for(int i = 0; i<soLuongDinh; i++)
	{
		fileOut << mainDinh[i].name << " " << mainDinh[i].toaDoX << " " << mainDinh[i].toaDoY << endl;
	}
	for(int i=0;i< soLuongDinh; i++)
	{
		for(int j=0; j<soLuongDinh; j++)
		{
			if(matrix[i][j]!=0)
			{
				fileOut << i<<" "<<mainDinh[i].name << "\t";
				fileOut << j<<" "<<mainDinh[j].name <<"\t";
				fileOut	<<matrix[i][j]<<endl;
			}
		}
	}
	fileOut.close();
}

// ===================================================


// ================= OTHER FUNCTION ===================
void veMatrix()
{
	setMatrix();
	if(soLuongDinh<=10)
	{
		int xdauconst=15; int ydauconst=460;
		for(int i=0;i<=soLuongDinh;i++)
		{
			for(int j=0;j<=soLuongDinh;j++)
			{
				int xdau= xdauconst + 25*j;
				int xcuoi=xdauconst+25+25*j;
				
				int ydau=ydauconst +22*i;
				int ycuoi=ydauconst+22+22*i;
			
				rectangle(xdau,ydau,xcuoi,ycuoi);
				
				if(i==0&&j!=0)
				{
					int xgiua=(xdau+xcuoi)/2;
					int ygiua=(ydau+ycuoi)/2;
					setbkcolor(mauxanhgiongaokhoaccrush);
					outtextxy(xgiua-4,ygiua-4,mainDinh[j-1].name);
				}
				else if(j==0&&i!=0)
				{
					int xgiua=(xdau+xcuoi)/2;
					int ygiua=(ydau+ycuoi)/2;
					setbkcolor(mauxanhgiongaokhoaccrush);
					outtextxy(xgiua-4,ygiua-4,mainDinh[i-1].name);
				}
				else if(i!=0&&j!=0)
				{
				
					int xgiua=(xdau+xcuoi)/2;
					int ygiua=(ydau+ycuoi)/2;
					if(matrix[i-1][j-1]<10)
					{
						char s[2];
						s[0]= matrix[i-1][j-1]+48;
						s[1]='\0';
						setbkcolor(mauxanhgiongaokhoaccrush);
						outtextxy(xgiua-4,ygiua-4,s);
					}
					else if(matrix[i-1][j-1]>=10&&matrix[i-1][j-1]<100)
					{
						char s[3];
						s[0]= matrix[i-1][j-1]/10 +48;
						s[1]= matrix[i-1][j-1]%10 +48;
						s[2]='\0';
						setbkcolor(mauxanhgiongaokhoaccrush);
						outtextxy(xgiua-4-4,ygiua-4,s);
					}
				}
			}
		}
	}
		
}

void khoiTaoMatrix(int n)
{
	matrix=new int*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new int[n];
	}
}

void giaiPhongMatrix(int n)
{
	for(int i=0;i<n;i++)
	{
		delete matrix[i];
	}
	delete matrix;
}

void veAllDoThi()
{
	bool a[soLuongDinh][soLuongDinh];
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			a[i][j]=0;
		}
	}
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			if(matrix[i][j]!=0&&matrix[j][i]==0)
			{
				ve1Canh(mainDinh[i],mainDinh[j],matrix[i][j]);
			}
			else if(matrix[i][j]!=0&&matrix[j][i]!=0&&a[i][j]==false&&a[j][i]==false)
			{
				int denta=DENTA;
				Dinh tamdau;										Dinh tamcuoi;
				tamdau.toaDoX=mainDinh[i].toaDoX;				tamcuoi.toaDoX=	mainDinh[j].toaDoX;
				tamdau.toaDoY=mainDinh[i].toaDoY-denta;			tamcuoi.toaDoY=	mainDinh[j].toaDoY-denta;
		
				Dinh tamdau1;
				Dinh tamcuoi1;
				tamdau1.toaDoX=mainDinh[j].toaDoX;				tamcuoi1.toaDoX=mainDinh[i].toaDoX;
				tamdau1.toaDoY=mainDinh[j].toaDoY+denta;		tamcuoi1.toaDoY=mainDinh[i].toaDoY+denta;

				if(abs(tamdau.toaDoX-tamcuoi.toaDoX)<50)
				{
					
					tamdau.toaDoX=mainDinh[i].toaDoX-denta;				tamcuoi.toaDoX=	mainDinh[j].toaDoX-denta;
					tamdau1.toaDoX=mainDinh[j].toaDoX+denta;			tamcuoi1.toaDoX=mainDinh[i].toaDoX+denta;
				}
				ve1Canh(tamdau,tamcuoi,matrix[i][j]);
				ve1Canh(tamdau1,tamcuoi1,matrix[j][i]);
				a[i][j]=a[j][i]=true;
			}
		}
	}
	for(int i=0;i<soLuongDinh;i++)
	{		
		ve1Dinh(mainDinh[i]);
	}
}

void veChuThankYou()
{
	int xgiua=640;
	int ygiua= 360;
	
	setfillstyle(SOLID_FILL,15);
	bar(0, 0, 1280, 720);
	
	settextstyle(0,0,5);
	setbkcolor(15);
	
	setcolor(5);
	outtextxy(xgiua-40+40*-4,ygiua-20,"T");
	setcolor(1);
	outtextxy(xgiua-40+40*-3,ygiua-20,"H");
	setcolor(4);
	outtextxy(xgiua-40+40*-2,ygiua-20,"A");
	setcolor(14);
	outtextxy(xgiua-40+40*-1,ygiua-20,"N");
	setcolor(2);
	outtextxy(xgiua-40,ygiua-20,"K");
	
	outtextxy(xgiua-40+40*1,ygiua-20," ");
	setcolor(2);
	outtextxy(xgiua-40+40*2,ygiua-20,"Y");
	setcolor(1);
	outtextxy(xgiua-40+40*3,ygiua-20,"O");
	setcolor(14);
	outtextxy(xgiua-40+40*4,ygiua-20,"U");
	setcolor(3);
	outtextxy(xgiua-40+40*5,ygiua-20,"!");
}

// ===================================================

// ================= STACK FUNCTION ==================
bool isEmptyStack(node* phead)
{
	if(phead==NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool inStack(node*phead, int n)
{
	for(node*k=phead;k!=NULL;k=k->pnext)
	{
		if(k->infor==n)
		{
			return true;
		}
	}
	return false;
}

void pushStack(node*&phead, int a)
{
	if(phead==NULL)	
	{
		node*p=new node;
		p->infor=a;
		phead=p;
	}
	else 
	{
		node*p=new node;
		p->infor=a;
		p->pnext=phead;
		phead=p;
	}
}

void popStack(node*&phead, int &a)
{
	if(phead==NULL)
	{
		a=-1;
		return;
	}		
	else
	{
		a=phead->infor;
		node*p=phead;
		phead=p->pnext;
		delete p;
	}
}

// ===================================================

// ================= QUEUE FUNCTION ==================
bool isEmptyQueue(node*phead,node*plast)
{
	if(phead==NULL)
	{
		return true;
	}
	return false;
}

void pushQueue(node*&phead, node*&plast,int a)
{
	if(isEmptyQueue(phead,plast)==true)
	{
		node*p=new node;
		p->infor=a;
		phead=plast=p;
	}
	else
	{
		node*p=new node;
		p->infor=a;
		plast->pnext=p;
		plast=p;
	}
}

void popQueue(node*&phead,node*&plast,int &a)
{
	if(isEmptyQueue(phead,plast)==true)
	{
		return;
	}
	else
	{
		a=phead->infor;
		node*p=phead;
		phead=phead->pnext;
		delete p;
	}
}

// ===================================================

// ================ THUAT TOAN DFS ===================
void DFS(int x, int a[], int &n)
{
	if(soLuongDinh==0)
	{
		return;
	}
	bool chuaxet[30];
	node*phead=NULL;	
	for(int i=0;i<30;i++)
	{
		chuaxet[i]=true;
	}
	pushStack(phead,x);
	a[n]=x;
	n++;
	chuaxet[x]=false;
	while(isEmptyStack(phead)==false)
	{
		int tam;
		popStack(phead,tam);
		for(int i=0;i<soLuongDinh;i++)
		{
			if(matrix[tam][i]!=0&&chuaxet[i]==true)
			{
				a[n]=i;
				n++;
				chuaxet[i]=false;
				pushStack(phead,tam);
				pushStack(phead,i);
				break;
			}
		}
	}
}

void thuatToanDFS()
{
	int a[30];
	int n=0;
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"NHAN VAO DINH CAN DFS");
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			int vitri=viTriDinh(xtam,ytam);
			if(vitri!=-1)
			{
				nhanVaoDinhChonMau(mainDinh[vitri],5);
				setbkcolor(mauxanhgiongaokhoaccrush);
				outtextxy(355,480+15,"DFS: ");
				
				DFS(vitri,a,n);
				
				for(int i=0;i<n;i++)
				{
					delay(690);
					nhanVaoDinh(mainDinh[a[i]]);
					setbkcolor(mauxanhgiongaokhoaccrush);
					outtextxy(355+5*8+i*24,480+15,mainDinh[a[i]].name);
					outtextxy(355+5*8+i*24+8,480+15,"->");
				}
				outtextxy(355+5*8+(n-1)*24+8,480+15,"  ");
			}
			break;
		}
	}
	outtextxy(355,680,"NHAN NUT BAT KI");
	while(!kbhit());
	setThongTin();
	for(int i=0;i<n;i++)
	{
		ve1Dinh(mainDinh[a[i]]);
	}
}

// ===================================================

// ================ THUAT TOAN BFS ===================
void BFS(int x, int a[], int &n)
{
	
	if(soLuongDinh==0)
	{
		return;
	}
	bool chuaxet[soLuongDinhMax];
	for(int i=0;i<soLuongDinh;i++)
	{
		chuaxet[i]=true;
	}
	node*phead=NULL;
	node*plast=NULL;
	pushQueue(phead,plast,x);
	
	chuaxet[x]=false;
	while(isEmptyQueue(phead,plast)==false)
	{
		int s;
		popQueue(phead,plast,s);
		
		a[n]=s;
		n++;
		for(int i=0;i<soLuongDinh;i++)
		{
			
			if(matrix[s][i]!=0&&chuaxet[i]==true)
			{
				pushQueue(phead,plast,i);
				chuaxet[i]=false;
			}
		
		}
	
	}
}

void thuatToanBFS()
{
	int a[30];
	int n=0;
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"NHAN VAO DINH CAN BFS");
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			int vitri=viTriDinh(xtam,ytam);
			if(vitri!=-1)
			{
				nhanVaoDinhChonMau(mainDinh[vitri],5);
				setbkcolor(mauxanhgiongaokhoaccrush);
				outtextxy(355,480+15,"BFS: ");
				
				BFS(vitri,a,n);
				
				for(int i=0;i<n;i++)
				{
					delay(690);
					nhanVaoDinh(mainDinh[a[i]]);
					setbkcolor(mauxanhgiongaokhoaccrush);
					outtextxy(355+5*8+i*24,480+15,mainDinh[a[i]].name);
					outtextxy(355+5*8+i*24+8,480+15,"->");
				}
				outtextxy(355+5*8+(n-1)*24+8,480+15,"  ");
			}
			break;
		}
	}
	while(!kbhit());
	outtextxy(355,680,"NHAN NUT BAT KI");
	setThongTin();
	for(int i=0;i<n;i++)
	{
		ve1Dinh(mainDinh[a[i]]);
	}
}

// ===================================================


// =============== THUAT TOAN TPLT ===================
void strongConnect(int index[], int lowLink[],node*&phead,int &indexNumber, int Dinh, int &color,int &soThanhPhanLienThongManh)
{
	index[Dinh]=indexNumber;
	lowLink[Dinh]=indexNumber;
	indexNumber++;
	pushStack(phead,Dinh);
	for(int i=0;i<soLuongDinh;i++)
	{
		if(matrix[Dinh][i]!=0&&index[i]==9999)
		{
			strongConnect(index,lowLink,phead,indexNumber,i,color,soThanhPhanLienThongManh);
			lowLink[Dinh]=lowLink[Dinh]>lowLink[i]?lowLink[i]:lowLink[Dinh];
		}
		else if(matrix[Dinh][i]!=0&&inStack(phead,i)==true)
		{
			lowLink[Dinh]=lowLink[Dinh]>index[i]?index[i]:lowLink[Dinh];
		}
	}
	if(lowLink[Dinh]==index[Dinh])
	{
		soThanhPhanLienThongManh++;
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,465+15*soThanhPhanLienThongManh,"TPLT: ");
		int mangTam[MaxMatrix];
		int slMT=0;
		int w=-1;
		while(w!=Dinh)
		{
			popStack(phead,w);
			mangTam[slMT]=w;
			slMT++;
		}
		
		for(int i=slMT-1;i>=0;i--)
		{
			nhanVaoDinhChonMau(mainDinh[mangTam[i]],color);
			setbkcolor(mauxanhgiongaokhoaccrush);
			outtextxy(355+6*8+(slMT-1-i)*24,465+15*soThanhPhanLienThongManh,mainDinh[mangTam[i]].name);
			outtextxy(355+6*8+(slMT-1-i)*24+8,465+15*soThanhPhanLienThongManh,"  ");
		}
		color++;
	}
}

void TPLT()
{
	int index[soLuongDinh];
	int lowLink[soLuongDinh];
	int soThanhPhanLienThongManh=0;
	int color=1;
	for(int i=0;i<soLuongDinh;i++)
	{
		index[i]=9999;
		lowLink[i]=9999;
	}
	int indexNumber=1;
	
	node*phead=NULL;
	
	for(int i=0;i<soLuongDinh;i++)
	{
		if(index[i]==9999)
		{
			strongConnect(index,lowLink,phead,indexNumber,i,color,soThanhPhanLienThongManh);
		}
	}
	
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,650,"NHAN NUT BAT KI");
	while(!kbhit());
	fflush(stdin);
	for(int i=0;i<soLuongDinh;i++)
	{
		ve1Dinh(mainDinh[i]);
	}
	setThongTin();
}

// ==================================================//

// ======== THUAT TOAN TIM DUONG DI NGAN NHAT ========
void initXtoY(int G[][MaxMatrix])
{
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			if(matrix[i][j]!=0)
			{
				G[i][j]=matrix[i][j];
			}
			else
			{
				G[i][j]=VOCUNG;
			}
		}
	
	}
}

void XtoY()
{
	clearmouseclick(WM_LBUTTONDOWN);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"NHAN VAO DINH DAU");
	int vitri1;
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri1=viTriDinh(xtam,ytam);
			if(vitri1!=-1)
			{
				nhanVaoDinh(mainDinh[vitri1]);
				break;
			}
		}
	}
	clearmouseclick(WM_LBUTTONDOWN);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,495,"NHAN VAO DINH SAU");
	int vitri2;
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			clearmouseclick(WM_LBUTTONDOWN);
			vitri2=viTriDinh(xtam,ytam);
			if(vitri2!=-1)
			{
				nhanVaoDinh(mainDinh[vitri2]);
				break;
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
	}
	if(vitri2==vitri1)
	{
		outtextxy(355,510,"HAI DINH KHONG DUOC TRUNG NHAU");
		while(!kbhit());
		setThongTin();
		ve1Dinh(mainDinh[vitri1]);
		return;
	}
	clearmouseclick(WM_LBUTTONDOWN);
	
	int d[MaxMatrix];
	int truoc[MaxMatrix];
	int G[MaxMatrix][MaxMatrix];

	
	initXtoY(G);
	d[vitri1]=0;
	truoc[vitri1]=vitri1;
	// khoi tao
	for(int i=0;i<soLuongDinh;i++)
	{
		d[i]=G[vitri1][i];
		truoc[i]=vitri1;
	}
	//lap
	int K=1;
	d[vitri1]=0;
	while(K<=soLuongDinh-2)
	{
		for(int i=0;i<soLuongDinh;i++)//&&i!=vitri1
		{
			for(int j=0;j<soLuongDinh;j++)
			{
				if(d[i]>d[j]+G[j][i])
				{
					d[i]=d[j]+G[j][i];
					truoc[i]=j;
				}
			}
		}
		K++;
	}
	if(d[vitri2]==VOCUNG)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,525,"KHONG CO DUONG DI");
		outtextxy(355,540, "NHAN NUT BAT KY");
		while(!kbhit());
		setThongTin();
		ve1Dinh(mainDinh[vitri1]);
		ve1Dinh(mainDinh[vitri2]);
	}
	else
	{
		int kq[MaxMatrix];
		int sl=0;
		kq[sl]=vitri2;
		sl++;
		int tam=truoc[vitri2];
		while(tam!=vitri1)
		{
			kq[sl]=tam;
			sl++;
			tam=truoc[tam];
		}
		kq[sl]=vitri1;
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,525,"DUONG DI: ");
		for(int i=sl;i>=0;i--)
		{	
			nhanVaoDinhChonMau(mainDinh[kq[i]],5);
			setbkcolor(2);
			outtextxy(355+8*10+(sl-i)*24,525,mainDinh[kq[i]].name);
			outtextxy(355+8*10+(sl-i)*24+8,525,"=>");
			delay(690);
		}
		outtextxy(355+8*10+sl*24+8,525,"  ");
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,525+20,"NHAN NUT BAT KI");
		while(!kbhit());
		setThongTin();
		for(int i=sl;i>=0;i--)
		{
			ve1Dinh(mainDinh[kq[i]]);
		}
	}
}

// ===================================================

// ============== THUAT TOAN DINH TRU ================
bool kiemTraDoThiCoLaVoHuongKhong()
{
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=0;j<soLuongDinh;j++)
		{
			if(matrix[i][j]!=0&&matrix[j][i]==0)
			{
				return false;
			}
		}
	}
	return true;
}
		
void DFSDoThiVoHuong(bool chuaxet[], int x)
{
	if(soLuongDinh==0)
	{
		return;
	}
	node*phead=NULL;	
	pushStack(phead,x);
	chuaxet[x]=false;
	while(isEmptyStack(phead)==false)
	{
		int tam;
		popStack(phead,tam);
		for(int i=0;i<soLuongDinh;i++)
		{
			if(matrix[tam][i]!=0&&chuaxet[i]==true)
			{
				chuaxet[i]=false;
				pushStack(phead,tam);
				pushStack(phead,i);
				break;
			}
		}
	}
}

void DFSDoThiVoHuongDinhTru(int x, int dinhBo, bool chuaxet[])
{
	if(soLuongDinh==0)
	{
		return;
	}
	node*phead=NULL;	
	
	pushStack(phead,x);
	chuaxet[x]=false;
	while(isEmptyStack(phead)==false)
	{
		int tam;
		popStack(phead,tam);
		for(int i=0;i<soLuongDinh&&i!=dinhBo;i++)
		{
			if(matrix[tam][i]!=0&&chuaxet[i]==true)
			{
				chuaxet[i]=false;
				pushStack(phead,tam);
				pushStack(phead,i);
				break;
			}
		}
	}
}

int timSoTPLTDoThiVoHuong()
{
	int soTPLT=0;
	bool chuaxet[soLuongDinh];
	for(int i=0;i<soLuongDinh;i++)
	{
		chuaxet[i]=true;
	}
	for(int i=0;i<soLuongDinh;i++)
	{
		if(chuaxet[i]==true)
		{
			soTPLT++;
			DFSDoThiVoHuong(chuaxet,i);
		}
	}
	return soTPLT;
}

int timSoTPLTDoThiVoHuongDinhTru(bool chuaxet[])
{
	int soTPLT= timSoTPLTDoThiVoHuong();
	for(int i=0;i<soLuongDinh;i++)
	{
		if(chuaxet[i]==true)
		{
			soTPLT = soTPLT +1;
			return soTPLT;
		}
	}
	return soTPLT;
}

void thuatToanDinhTru()
{
	if(kiemTraDoThiCoLaVoHuongKhong()==false)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"DO THI KHONG LA VO HUONG");
		while(!kbhit());
		setThongTin();
		return ;
	}
	int dinhTru[30];
	int soLuongDT=0;
	int soTPLTCoDinh=timSoTPLTDoThiVoHuong();
	
	bool chuaxet[soLuongDinh];
	for(int i=0;i<soLuongDinh;i++)
	{
		chuaxet[i]=true;
	}
	for(int i=0;i<soLuongDinh;i++)
	{
		int dem=0;
		chuaxet[i]= false;
		int v=i+1; if(v>soLuongDinh) v=0;
		for(int u= 0; u< soLuongDinh; u++)
		{
			if(matrix[i][u]!=0)
				dem += 1;
		}
		if(dem>1)
		{
			DFSDoThiVoHuong(chuaxet, v);
			if(timSoTPLTDoThiVoHuongDinhTru(chuaxet)>soTPLTCoDinh)
			{
				dinhTru[soLuongDT]=i;
				soLuongDT++;
			}
			for(int i=0;i<soLuongDinh;i++)
			{
				chuaxet[i]=true;
			}
		}
	}
	if(soLuongDT==0)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"DO THI KHONG CO DINH TRU");
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,680,"NHAN NUT BAT KI");
		while(!kbhit());
		setThongTin();
		return ;
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"DINH TRU: ");
	for(int i=0;i<soLuongDT;i++)
	{
		nhanVaoDinh(mainDinh[dinhTru[i]]);
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355+80+i*32,480,mainDinh[dinhTru[i]].name);
		outtextxy(355+80+i*32+8,480," , ");
	}
	outtextxy(355+80+(soLuongDT-1)*32+8,480,"    ");
	while(!kbhit());
	for(int i=0;i<soLuongDT;i++)
	{
		ve1Dinh(mainDinh[dinhTru[i]]);
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,680,"NHAN NUT BAT KI");
	setThongTin();
}

// ===================================================

// ============== THUAT TOAN DINH THAT ===============
void BFSDINHTHAT(int k)
{
	bool chuaxet[MaxMatrix];
	for(int i=0; i< soLuongDinh; i++)
	{
		chuaxet[i]= true;
	}
	int queue[soLuongDinh], low =0, high =0, u, v;
	queue[low]= 0; chuaxet[0] = false; chuaxet[k] = false;
	while(low<=high)
	{
		u = queue[low]; low +=1;
		for(v=0; v< soLuongDinh; v++)
		{
			if(matrix[u][v] && chuaxet[v])
			{
				high = high + 1;
				queue[high] = v;
				truoc[v] = u;
				chuaxet[v] = false;
			}
		}
	}
}

bool kiemTraDinhThat()
{
	int j = soLuongDinh-1;
	while(truoc[j]!=1)
	{
		if(truoc[j]==0)
		{
			return true;
		}
		j = truoc[j];
	}
	return false;
}

void thuatToanDinhThat()
{
	int dinhThat[30];
	int soLuongDT=0;
	bool chuaxet[MaxMatrix];
	bool flag = false;
	for(int i=1; i< soLuongDinh-1; i++)
	{
		BFSDINHTHAT(i);
		if(kiemTraDinhThat() == true)
		{
			dinhThat[soLuongDT] = i;
			soLuongDT++;
			flag = true;
		}
		for(int j=0; j< soLuongDinh; j++)
		{
			chuaxet[j]=true;
		}
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355, 480, "THUAT TOAN DINH THAT!");
	if(flag == false )
	{
		outtextxy(355, 495, "KHONG CO DINH THAT!");
		outtextxy(355, 510, "NHAN NUT BAT KI !");
		while(!kbhit());
		setThongTin();
	}
	else
	{
		outtextxy(355, 495, "DINH THAT: ");
		for(int i= 0; i< soLuongDT; i++)
		{
			delay(690);
			nhanVaoDinh(mainDinh[dinhThat[i]]);
			setbkcolor(mauxanhgiongaokhoaccrush);
			outtextxy(355+90+i*32, 495, mainDinh[dinhThat[i]].name);
			outtextxy(355+90+i*32+8, 495, " , ");
		}
		outtextxy(355+90+(soLuongDT-1)*32+8, 495, "    ");
		outtextxy(355, 510, "NHAN NUT BAT KI !");
		while(!kbhit());
		for(int i= 0; i< soLuongDT; i++)
		{
			ve1Dinh(mainDinh[dinhThat[i]]);
		}
		setThongTin();
	}
}

// ===================================================

// =============== THUAT TOAN CANH CAU ===============
int DFSDoThiVoHuongKhongLuuKQ(int x)
{
	if(soLuongDinh==0)
	{
		return -1;
	}
	bool chuaxet[soLuongDinh];
	for(int i=0;i<soLuongDinh;i++)
	{
		chuaxet[i]=true;
	}
	node*phead=NULL;
	pushStack(phead,x);
	int soLuongDinhDaDuyet=0;
	soLuongDinhDaDuyet++;
	chuaxet[x]=false;
	while(isEmptyStack(phead)==false)
	{
		int tam;
		popStack(phead,tam);
		for(int i=0;i<soLuongDinh;i++)
		{
			if(matrix[tam][i]!=0&&chuaxet[i]==true)
			{
				chuaxet[i]=false;
				soLuongDinhDaDuyet++;
				pushStack(phead,tam);
				pushStack(phead,i);
				break;
			}
		}
	}
	return soLuongDinhDaDuyet;
}

void thuatToanCanhCau()
{
	if(kiemTraDoThiCoLaVoHuongKhong()==false)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"DO THI KHONG LA VO HUONG");
		while(!kbhit());
		
		setThongTin();
		return ;
	}
	canh canhCau[100];
	int soLuongCC=0;
	int soLuongDinhDaDuyet = DFSDoThiVoHuongKhongLuuKQ(1);
	for(int i=0;i<soLuongDinh;i++)
	{
		for(int j=i+1;j<soLuongDinh;j++)
		{
			if(matrix[i][j]!=0)
			{
				int tam1=matrix[i][j];
				int tam2=matrix[j][i];
				matrix[i][j]=matrix[j][i]=0;
				int soLuongDinhDuyetDFSQua=DFSDoThiVoHuongKhongLuuKQ(1);
				matrix[i][j]=tam1;
				matrix[j][i]=tam2;
				
				canh tam;
				tam.dinhDau=i;
				tam.dinhCuoi=j;
				if(soLuongDinhDuyetDFSQua!=soLuongDinhDaDuyet)
				{
					canhCau[soLuongCC]=tam;
					soLuongCC++;
				}
			}
		}
	}
	if(soLuongCC==0)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480,"DO THI KHONG CO CANH CAU");
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,680,"NHAN NUT BAT KI");
		while(!kbhit());
		setThongTin();
		return ;
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"CANH CAU: ");
	for(int i=0;i<soLuongCC;i++)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355+80+i*32,480,mainDinh[canhCau[i].dinhDau].name);
		outtextxy(355+80+i*32+8,480,"-");
		outtextxy(355+80+i*32+16,480,mainDinh[canhCau[i].dinhCuoi].name);
		outtextxy(355+80+i*32+24,480,"  ");
		nhanVaoDinh(mainDinh[canhCau[i].dinhDau]);
		delay(690);
		nhanVaoDinh(mainDinh[canhCau[i].dinhCuoi]);
		setbkcolor(mauxanhgiongaokhoaccrush);
	}
	outtextxy(355+80+(soLuongCC-1)*32+24,480,"    ");
	outtextxy(355,480+50,"NHAN NUT BAT KI ");
	while(!kbhit());
	for(int i=0; i< soLuongCC; i++)
	{
		ve1Dinh(mainDinh[canhCau[i].dinhDau]);
		ve1Dinh(mainDinh[canhCau[i].dinhCuoi]);
	}
	setThongTin();
}

// ===================================================

// =============== THUAT TOAN HAMILTON ===============
void Result(int &d, int B[])
{
	
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480+15,"CHU TRINH HAMILTON: ");
  	for(int i=0; i<=soLuongDinh; i++)
   	{
   		delay(500);
   		setbkcolor(mauxanhgiongaokhoaccrush);
  		outtextxy(355+15+20*8+i*24,480+15,mainDinh[B[i]-1].name);
   		outtextxy(355+15+20*8+i*24+8,480+15,"=>");
 		nhanVaoDinhChonMau(mainDinh[B[i]-1],5);
	}
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355+15+20*8+soLuongDinh*24+8,480+15,"  ");
   	d++;
   	outtextxy(355,480+15+20,"NHAN NUT BAT KI");
   	
   	fflush(stdin);
	char s=getch();
	fflush(stdin);
	
   	for(int i=0;i<=soLuongDinh;i++)
   	{
   		ve1Dinh(mainDinh[B[i]-1]);
	}
	setThongTin();
	fflush(stdin);
	
   
}

void Hamilton(int *B, int *C, int i, int &d, int n, int A[][MaxMatrix])
{
	int j;
 	for(j=1; j<=n; j++)
	{
    	if(A[B[i-1]][j]==1 && C[j]==0)
		{
      		B[i]=j; C[j]=1;
      		if(i<n) Hamilton(B, C, i+1,d,n,A);
      		
      		else if(B[i]==B[0])
			{
				Result(d,B);
			}
      		C[j]=0;
    	}
  	}
}

void thuatToanHamilton()
{
	clearmouseclick(WM_LBUTTONDOWN);
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355,480,"NHAN VAO DINH");
	int vitri1;
	while(true)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int xtam,ytam;
			getmouseclick(WM_LBUTTONDOWN,xtam,ytam);
			vitri1=viTriDinh(xtam,ytam);
			if(vitri1!=-1)
			{
				nhanVaoDinh(mainDinh[vitri1]);
				break;
			}
		}
	}
	int B[MaxMatrix];
	B[0]=vitri1+1;
	int i=1;
	int d=0;
	
	int A[MaxMatrix][MaxMatrix];
	int n=soLuongDinh;
	
	int C[MaxMatrix];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(matrix[i-1][j-1]!=0)
			{
				A[i][j]=1;
			}
			else 
			{
				A[i][j]=0;
			}
		}
		C[i]=0;
	}
	
	Hamilton(B,C,i,d,n,A);
	
	
	if (d==0)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355,480+15,"KHONG CO CHU TRINH HAMILTON");
		outtextxy(355,480+15+20,"NHAN NUT BAT KI");
		while(!kbhit());
		setThongTin();
		ve1Dinh(mainDinh[vitri1]);
	}
	else
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		setThongTin();
	}
}

// ===================================================

// ================ THUAT TOAN EULER =================
void BFSEuler(bool chuaxet[])
{
	
	int queue[soLuongDinh], low =0, high =0, u, v;
	queue[low]= 0; chuaxet[0] = false;
	while(low<=high)
	{
		u = queue[low]; low +=1;
		for(v=0; v< soLuongDinh; v++)
		{
			if(matrix[u][v] && chuaxet[v])
			{
				high = high + 1;
				queue[high] = v;
				chuaxet[v] = false;
			}
		}
	}
}
bool kiemTraEC()
{
	bool chuaxet[MaxMatrix];
	for(int i=0; i<soLuongDinh; i++)
	{
		chuaxet[i]=true;
	}
	BFSEuler(chuaxet);
	for(int i=0; i<soLuongDinh; i++)
	{
		if(chuaxet[i]==true)
			return false;
	}
	int i, j;
	
	for(i=0; i< soLuongDinh; i++)
	{
		int a= 0,b= 0;
		for(j=0; j< soLuongDinh; j++)
		{
			if(matrix[i][j]!= 0)
				a++;
			if(matrix[j][i]!= 0)
				b++;
		}
		if(a!=b)	return false;
	}
	return true;
}

void thuatToanEulerCycle(){
	int x, high=1, dCE;
	int stack[MaxMatrix], CE[MaxMatrix], B[MaxMatrix][MaxMatrix];
	int kq[MaxMatrix];
	bool flag=true;
	stack[high]=0;dCE=0;
	copyMatrix(B);
	if(kiemTraEC() == false)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355, 480, "DO THI KHONG CO CHU TRINH EULER!");
		outtextxy(355, 495, "BAM NUT BAT KY DE TIEP TUC!");
		while(!kbhit());
		setThongTin();
		return ;
	}
	while(high!=0)
	{
		flag = false;
		int s = stack[high];
		for(int i=0; i< soLuongDinh; i++)
		{
			if(B[s][i]!=0)
			{
				high++;
				stack[high]=i;
				B[s][i]=0;
				flag = true;break;
			}
		}
		if(flag!=true)
		{
			CE[dCE]=s;
			dCE++;
			high--;
		}
	}
	for(int i=0; i< dCE; i++)
	{
		kq[i]= CE[dCE-1-i];
	}
	
	setbkcolor(mauxanhgiongaokhoaccrush);
	outtextxy(355, 480, "CHU TRINH EULER!");
	outtextxy(355, 495, "THU TU: ");
	for(int i=0; i< dCE; i++)
	{
		delay(690);
		nhanVaoDinh(mainDinh[kq[i]]);
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355+40+(i+1)*32, 495, mainDinh[kq[i]].name);
		outtextxy(355+40+(i+1)*32+8, 495, " , ");
	}
	outtextxy(355+40+(dCE)*32+8, 495, "   ");
	outtextxy(355, 510, "BAM NUT BAT KY DE TIEP TUC!");
	while(!kbhit());
	setThongTin();
	setDoThi();
	for(int i=0;i< soLuongDinh;i++)
	{
		ve1Dinh(mainDinh[i]);
	}
}

// ===================================================

// ============== THUAT TOAN TOPOSORT ================
void copyMatrix(int B[MaxMatrix][MaxMatrix])
{
	for(int i=0; i< soLuongDinh; i++)
	{
		for(int j=0; j< soLuongDinh; j++)
		{
			B[i][j]=matrix[i][j];
		}
	}
}

void thuatToanTopoSort()
{
	bool chuaxet[MaxMatrix];
	for(int i=0; i< soLuongDinh; i++)
	{
		chuaxet[i]= true;
	}
	int B[MaxMatrix][MaxMatrix];
	copyMatrix(B);
	int L[MAX];
	int S[MAX];
	int high=1, low=1, dem, temp, i;
	int Lp=-1;
	for(int i=0; i< soLuongDinh; i++)
	{
		dem=0;
		for(int j=0; j< soLuongDinh; j++)
		{
			if(B[j][i]!=0)
				dem++;
		}
		if(dem==0)
		{
			S[high] = i;
			high++;
			chuaxet[i] = false;
		}
	}
	high--;
	while(low<=high)
	{
		Lp++;
		L[Lp]= S[low];
		int u = S[low];
		low++;
		for(int i=0; i< soLuongDinh; i++)
		{
			if(B[u][i]!=0)
				B[u][i]=0;
			dem = 0;
			for(int j=0; j< soLuongDinh; j++)
			{
				if(B[j][i]!=0)
					dem++;
			}
			if(dem==0 && chuaxet[i]== true)
			{
				high++;
				S[high]=i;
				chuaxet[i]=false;
			}
		}
	}
	bool flag = true;
	for(int i=0; i< soLuongDinh; i++)
	{
		for(int j=0; j< soLuongDinh; j++)
		{
			if(B[i][j]!=0)
			{
				flag= false;
				break;
			}
		}
		if(flag == false)
			break;
	}
	cout << endl;
	if(flag == false)
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355, 480, "KHONG CO THU TU SAP XEP TOPO");
	}
	else
	{
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(355, 480, "THUAT TOAN TOPO");
		outtextxy(355, 495, "THU TU: ");
		for(i=0; i<= Lp; i++)
		{
			//cout << L[i] << " ";
			delay(500);
			nhanVaoDinh(mainDinh[L[i]]);
			setbkcolor(mauxanhgiongaokhoaccrush);
			outtextxy(355+40+(i+1)*32, 495, mainDinh[L[i]].name);
			outtextxy(355+40+(i+1)*32+8, 495, " , ");
		}
	}
	outtextxy(355+40+(i)*32+8, 495, "   ");
	outtextxy(355, 510, "BAM NUT BAT KY DE TIEP TUC");
	while(!kbhit());
	setThongTin();
	setDoThi();
	for(int i=0;i< soLuongDinh;i++)
	{
		ve1Dinh(mainDinh[i]);
	}
}

// ===================================================


