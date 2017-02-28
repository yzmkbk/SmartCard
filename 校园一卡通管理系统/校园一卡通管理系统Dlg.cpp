
// 校园一卡通管理系统Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "校园一卡通管理系统Dlg.h"
#include "afxdialogex.h"

#include "查询余额.h"

#include "跑操查询.h"
#include "消费记录.h"
#include "学生快速充值.h"
#include "CUsers.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C校园一卡通管理系统Dlg 对话框



C校园一卡通管理系统Dlg::C校园一卡通管理系统Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_UserName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C校园一卡通管理系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
}

BEGIN_MESSAGE_MAP(C校园一卡通管理系统Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &C校园一卡通管理系统Dlg::On32771)
	ON_COMMAND(ID_32772, &C校园一卡通管理系统Dlg::On32772)
	ON_COMMAND(ID_32773, &C校园一卡通管理系统Dlg::On32773)
	ON_COMMAND(ID_32774, &C校园一卡通管理系统Dlg::On32774)
	ON_COMMAND(ID_32777, &C校园一卡通管理系统Dlg::On32777)
	ON_COMMAND(ID_32778, &C校园一卡通管理系统Dlg::On32778)
END_MESSAGE_MAP()


// C校园一卡通管理系统Dlg 消息处理程序

BOOL C校园一卡通管理系统Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C校园一卡通管理系统Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C校园一卡通管理系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}








void C校园一卡通管理系统Dlg::On32771()
{
	查询余额 dlg3;
	dlg3.m_balance = m_UserName;
	dlg3.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void C校园一卡通管理系统Dlg::On32772()
{
	跑操查询 dlg4;
	dlg4.m_Name = m_UserName;
	dlg4.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void C校园一卡通管理系统Dlg::On32773()
{
	消费记录 dlg5;
	dlg5.m_UserName = m_UserName;
	dlg5.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void C校园一卡通管理系统Dlg::On32774()
{
	学生快速充值 dlg6;
	dlg6.m_username = m_UserName;
	dlg6.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void C校园一卡通管理系统Dlg::On32777()
{
	CUsers user;
	user.SearchCardStatus(m_UserName);
	if(user.GetCardStatus() == "可用"){
		user.SetCardStatus(_T("不可用"));
		user.UpDateCardStatus(m_UserName);
		MessageBox(TEXT("挂失成功！"));
	}
	else
	{
		if (user.GetCardStatus() == "不可用")
			MessageBox(TEXT("此卡已经挂失！"));
	}
	// TODO: 在此添加命令处理程序代码
}


void C校园一卡通管理系统Dlg::On32778()
{
	// TODO: 在此添加命令处理程序代码
	CUsers user;
	user.SearchCardStatus(m_UserName);
	if (user.GetCardStatus() == "不可用") {
		user.SetCardStatus(_T("可用"));
		user.UpDateCardStatus(m_UserName);
		MessageBox(TEXT("解挂成功！"));
	}
	else
	{
		if (user.GetCardStatus() == "可用")
			MessageBox(TEXT("此卡尚未挂失！"));
	}
}
