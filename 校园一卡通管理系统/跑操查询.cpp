// 跑操查询.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "跑操查询.h"
#include "afxdialogex.h"
#include "CUsers.h"


// 跑操查询 对话框

IMPLEMENT_DYNAMIC(跑操查询, CDialogEx)

跑操查询::跑操查询(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAOCAO, pParent)
	, m_Name(_T(""))
	, m_RunNum(_T(""))
{

}

跑操查询::~跑操查询()
{
}

void 跑操查询::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_RunNum);
}


BEGIN_MESSAGE_MAP(跑操查询, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// 跑操查询 消息处理程序


void 跑操查询::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CUsers user1;
	user1.SearchName(m_Name);
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)user1.GetName());

	user1.SearchMorningRunNum(m_Name);
	CString p;
	p.Format(_T("%d"), user1.GetMorningRunNum());
	GetDlgItem(IDC_EDIT2)->SetWindowText((LPCTSTR)p);

}
