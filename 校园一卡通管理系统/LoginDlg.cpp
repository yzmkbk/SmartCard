// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "校园一卡通管理系统Dlg.h"
#include "AdminDlg.h"



// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Login, pParent)
	, m_Pwd(_T(""))
	, m_UserName(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, C_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &LoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// LoginDlg 消息处理程序


void LoginDlg::OnBnClickedOk()
{
	//将对话框中编辑框的数据读取到成员变量中
	UpdateData(TRUE);
	//检查数据有效性
	if (m_UserName == "")
	{
		MessageBox(TEXT("请输入用户名,否则出错！"));
		return;



	}
	if (m_Pwd == "")
	{
		MessageBox(TEXT("请输入密码"));
		return;
	}
	//定义CUsers对象，用于从表Users中读取数据
	CUsers user;
	if (user.Login(m_UserName)) {
		//如果读取的数据与用户输入数据不同，则返回
		if (user.GetPwd() != m_Pwd)
		{
			MessageBox(TEXT("用户信息错误！"));
			return;
		}
		
		
			
	}
	else
	{
		MessageBox(TEXT("用户名不存在！"));
	}
	//关闭对话框		

	CDialogEx::OnOK();
	CString s("S");
	CString a("A");
	if (user.GetUser_type() == s) {
		C校园一卡通管理系统Dlg mydlg;
		mydlg.m_UserName = m_UserName;
		mydlg.DoModal();
	}
	else
		if (user.GetUser_type() == a) {
			AdminDlg mydlg;
			mydlg.DoModal();
		}
		else
			MessageBox(TEXT("非法的用户类型！"));
}


