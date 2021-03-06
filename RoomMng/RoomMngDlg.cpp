
// RoomMngDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RoomMng.h"
#include "RoomMngDlg.h"
#include "afxdialogex.h"
#include "LoginDlg.h"
#include "CheckinDlg.h"
#include "Setroomdlg.h"
#include "FindRoomDlg.h"
#include "FindchechinDlg.h"
#include "CheckoutDlg.h"
#include "FindcheckoutDlg.h"
#include "SetpasswordDlg.h"
#include "AdduserDlg.h"
#include "RoomsaleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString loguserid;
extern CRoomMngApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenufindroom();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomMngDlg dialog



CRoomMngDlg::CRoomMngDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRoomMngDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRoomMngDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRoomMngDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_checkin, &CRoomMngDlg::OnMenucheckin)
	ON_COMMAND(ID_MENU_roomsetting, &CRoomMngDlg::OnMenuroomsetting)
	ON_BN_CLICKED(IDC_BTN_borrowroom, &CRoomMngDlg::OnBnClickedBtnborrowroom)
	ON_COMMAND(ID_MENU_findroom, &CRoomMngDlg::OnMenufindroom)
	ON_COMMAND(ID_MENU_querychekin, &CRoomMngDlg::OnMenuquerychekin)
	ON_BN_CLICKED(IDC_BTN_mainfind, &CRoomMngDlg::OnBnClickedBtnmainfind)
	ON_COMMAND(ID_MENU_chechout, &CRoomMngDlg::OnMenuchechout)
	ON_BN_CLICKED(IDC_BTN_returnroom, &CRoomMngDlg::OnBnClickedBtnreturnroom)
	ON_COMMAND(ID_MENU_querycheckout, &CRoomMngDlg::OnMenuquerycheckout)
	ON_COMMAND(ID_MENU_changepwd, &CRoomMngDlg::OnMenuchangepwd)
	ON_COMMAND(ID_MENU_adduser, &CRoomMngDlg::OnMenuadduser)
	ON_COMMAND(ID_MENU_salereport, &CRoomMngDlg::OnMenusalereport)
	ON_BN_CLICKED(IDC_BTN_daysummery, &CRoomMngDlg::OnBnClickedBtndaysummery)
    ON_BN_CLICKED(IDC_BTN_alert, &CRoomMngDlg::OnBnClickedBtnalert)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomMngDlg message handlers

BOOL CRoomMngDlg::OnInitDialog()
{
	LoginDlg dlg;

	if(IDOK==dlg.DoModal())
	{
	CDialogEx::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
	}
	//else 
	//	exit(0);
}

void CRoomMngDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRoomMngDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRoomMngDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRoomMngDlg::OnMenucheckin()
{
	// TODO: Add your command handler code here
	CheckinDlg mycheckindlg;
	mycheckindlg.DoModal();
}


void CRoomMngDlg::OnMenuroomsetting()
{
	// TODO: Add your command handler code here
	CSetroomdlg mysetroomdlg;
	mysetroomdlg.DoModal();
}


void CRoomMngDlg::OnBnClickedBtnborrowroom()
{
	// TODO: Add your control notification handler code here
	OnMenucheckin();
}


void CRoomMngDlg::OnMenufindroom()
{
	// TODO: Add your command handler code here
	CFindRoomDlg myfindroomdlg;
	myfindroomdlg.DoModal();
}


void CRoomMngDlg::OnMenuquerychekin()
{
	// TODO: Add your command handler code here
	CFindchechinDlg myfindcheckindlg;
	myfindcheckindlg.DoModal();
}


void CRoomMngDlg::OnBnClickedBtnmainfind()
{
	// TODO: Add your control notification handler code here
	OnMenuquerychekin();
}


void CRoomMngDlg::OnMenuchechout()
{
	// TODO: Add your command handler code here
	CCheckoutDlg mycheckoutdlg;
	mycheckoutdlg.DoModal();
}


void CRoomMngDlg::OnBnClickedBtnreturnroom()
{
	// TODO: Add your control notification handler code here
	OnMenuchechout();
}


void CRoomMngDlg::OnMenuquerycheckout()
{
	// TODO: Add your command handler code here
	CFindcheckoutDlg myfindcheckoutdlg;
	myfindcheckoutdlg.DoModal();
}


void CRoomMngDlg::OnMenuchangepwd()
{
	// TODO: Add your command handler code here
	CSetpasswordDlg mysetpassworddlg;
	mysetpassworddlg.DoModal();
}


void CRoomMngDlg::OnMenuadduser()
{
	// TODO: Add your command handler code here
	CAdduserDlg myadduserdlg;
	myadduserdlg.DoModal();
}


void CRoomMngDlg::OnMenusalereport()
{
	// TODO: Add your command handler code here
	CRoomsaleDlg myroomsaledlg;
	myroomsaledlg.DoModal();
}


void CRoomMngDlg::OnBnClickedBtndaysummery()
{
	// TODO: Add your control notification handler code here
	OnMenusalereport();
}


void CRoomMngDlg::OnBnClickedBtnalert()
{
    // TODO: Add your control notification handler code here
    OnMenufindroom();
}
