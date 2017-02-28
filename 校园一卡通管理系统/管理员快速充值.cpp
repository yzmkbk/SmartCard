// 管理员快速充值.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "管理员快速充值.h"
#include "afxdialogex.h"

#include "CUsers.h"




// 管理员快速充值 对话框

IMPLEMENT_DYNAMIC(管理员快速充值, CDialogEx)

管理员快速充值::管理员快速充值(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_username(_T(""))
	, m_ChongZhi(0)
{

}

管理员快速充值::~管理员快速充值()
{
}

void 管理员快速充值::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_ChongZhi);
}


BEGIN_MESSAGE_MAP(管理员快速充值, CDialogEx)
	ON_BN_CLICKED(IDOK, &管理员快速充值::OnBnClickedOk)
END_MESSAGE_MAP()


// 管理员快速充值 消息处理程序


void 管理员快速充值::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CUsers user;
	user.SearchBalance(m_username);
	user.SetBalance(user.GetBalance() + m_ChongZhi);
	user.UpDateBalance(m_username);
	MessageBox(TEXT("充值成功！"));
	CDialogEx::OnOK();
}
