// 查询余额.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "查询余额.h"
#include "afxdialogex.h"
#include "CUsers.h"



// 查询余额 对话框

IMPLEMENT_DYNAMIC(查询余额, CDialogEx)

查询余额::查询余额(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_balance(_T(""))
	, m_balance2(_T(""))
{

	//  m_username = _T("");
}

查询余额::~查询余额()
{
}

void 查询余额::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_balance);
	DDX_Text(pDX, IDC_EDIT2, m_balance2);
}


BEGIN_MESSAGE_MAP(查询余额, CDialogEx)
	ON_BN_CLICKED(IDOK, &查询余额::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &查询余额::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &查询余额::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// 查询余额 消息处理程序


void 查询余额::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}


void 查询余额::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void 查询余额::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void 查询余额::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CUsers user1;
	user1.SearchName(m_balance);
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)user1.GetName());

	user1.SearchBalance(m_balance);
	CString p;
	p.Format(_T("%.2f"), user1.GetBalance());
	GetDlgItem(IDC_EDIT2)->SetWindowText((LPCTSTR)p);

	//GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)USERNAME);
	// TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}
