// 余额修改.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "余额修改.h"
#include "afxdialogex.h"
#include "CUsers.h"


// 余额修改 对话框

IMPLEMENT_DYNAMIC(余额修改, CDialogEx)

余额修改::余额修改(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CZ_yuexiugai, pParent)
	, m_username(_T(""))
	, m_yu_e(0)
{

}

余额修改::~余额修改()
{
}

void 余额修改::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_yu_e);
}


BEGIN_MESSAGE_MAP(余额修改, CDialogEx)
	ON_BN_CLICKED(IDOK, &余额修改::OnBnClickedOk)
END_MESSAGE_MAP()


// 余额修改 消息处理程序


void 余额修改::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CUsers user;
	user.SearchBalance(m_username);
	user.SetBalance(m_yu_e);
	user.UpDateBalance(m_username);
	MessageBox(TEXT("修改成功！"));
	CDialogEx::OnOK();
}
