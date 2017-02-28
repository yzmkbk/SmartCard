// 添加学生.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "添加学生.h"
#include "afxdialogex.h"
#include "CUsers.h"


// 添加学生 对话框

IMPLEMENT_DYNAMIC(添加学生, CDialogEx)

添加学生::添加学生(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_username(_T(""))
	, m_Pwd(_T(""))
	, m_Name(_T(""))
	, m_College(_T(""))
	, m_Class(_T(""))
	, m_Dorm(_T(""))
{

}

添加学生::~添加学生()
{
}

void 添加学生::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT5, m_Name);
	DDX_Text(pDX, IDC_EDIT6, m_College);
	DDX_Text(pDX, IDC_EDIT7, m_Class);
	DDX_Text(pDX, IDC_EDIT8, m_Dorm);
}


BEGIN_MESSAGE_MAP(添加学生, CDialogEx)
	ON_BN_CLICKED(IDOK, &添加学生::OnBnClickedOk)
END_MESSAGE_MAP()


// 添加学生 消息处理程序


void 添加学生::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CUsers new_user;
	new_user.SetUserName(m_username);
	new_user.SetPwd(m_Pwd);
	new_user.SetName(m_Name);
	new_user.SetCollege(m_College);
	new_user.SetClass(m_Class);
	new_user.SetDorm(m_Dorm);
	if (m_username == "null" || m_Pwd == "null" || m_Name == "null" || m_College == "null" || m_Class == "null" || m_Dorm == "null") {
		MessageBox(TEXT("请完整填写！"));
		return;
	}
	else
	{
		new_user.New();
	}
	MessageBox(TEXT("添加成功！"));



}
