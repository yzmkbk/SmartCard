// AdminDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "AdminDlg.h"
#include "afxdialogex.h"

#include "管理员快速充值.h"
#include "余额修改.h"
#include "添加学生.h"


// AdminDlg 对话框

IMPLEMENT_DYNAMIC(AdminDlg, CDialogEx)

AdminDlg::AdminDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADMIN, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialogEx)
	ON_COMMAND(ID_32782, &AdminDlg::On32782)
	ON_COMMAND(ID_32783, &AdminDlg::On32783)
	ON_COMMAND(ID_32784, &AdminDlg::On32784)
	ON_COMMAND(IDC_STATIC, &AdminDlg::OnStatic)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// AdminDlg 消息处理程序


void AdminDlg::On32782()
{
	// TODO: 在此添加命令处理程序代码
	管理员快速充值 dlg7;
	dlg7.DoModal();

}


void AdminDlg::On32783()
{
	// TODO: 在此添加命令处理程序代码
	余额修改 dlg8;
	dlg8.DoModal();
}


void AdminDlg::On32784()
{
	// TODO: 在此添加命令处理程序代码
	添加学生 dlg9;
	dlg9.DoModal();
}


void AdminDlg::OnStatic()
{
	// TODO: 在此添加命令处理程序代码

}


HBRUSH AdminDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC) {//IDC_STATIC_TEST是控件的ID
		pDC->SetTextColor(RGB(128, 128, 256));//用RGB宏改变颜色       
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
