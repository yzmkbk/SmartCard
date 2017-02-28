// 消费记录.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "消费记录.h"
#include "afxdialogex.h"


// 消费记录 对话框

IMPLEMENT_DYNAMIC(消费记录, CDialogEx)

消费记录::消费记录(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PurchaseHistory, pParent)
	, m_UserName(_T(""))
{

}

消费记录::~消费记录()
{
}

void 消费记录::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_消费记录List);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
}


BEGIN_MESSAGE_MAP(消费记录, CDialogEx)

	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &消费记录::OnLvnItemchangedList3)
END_MESSAGE_MAP()


// 消费记录 消息处理程序


BOOL 消费记录::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	m_消费记录List.GetClientRect(&rect);
	m_消费记录List.SetExtendedStyle(m_消费记录List.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_消费记录List.InsertColumn(0, _T("时间"), LVCFMT_CENTER, rect.Width() / 3*2, 0);
	m_消费记录List.InsertColumn(1, _T("消费金额"), LVCFMT_CENTER, rect.Width() / 3, 1);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}





void 消费记录::OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	
}
