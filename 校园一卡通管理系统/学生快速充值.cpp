// 学生快速充值.cpp : 实现文件
//

#include "stdafx.h"
#include "校园一卡通管理系统.h"
#include "学生快速充值.h"
#include "afxdialogex.h"
#include "CUsers.h"


// 学生快速充值 对话框

IMPLEMENT_DYNAMIC(学生快速充值, CDialogEx)

学生快速充值::学生快速充值(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CZ_xiaoyuanwang, pParent)
	, m_ChongZhi(0)
	, m_Pwd(_T(""))
	, m_Balance(0)
	, m_username(_T(""))
{

}

学生快速充值::~学生快速充值()
{
}

void 学生快速充值::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ChongZhi);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT3, m_Balance);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT4, m_username);
}


BEGIN_MESSAGE_MAP(学生快速充值, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &学生快速充值::OnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &学生快速充值::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// 学生快速充值 消息处理程序


CString strtype;
int nSel;

void 学生快速充值::OnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	


	// 获取组合框控件的列表框中选中项的索引   
	nSel = m_ComboBox.GetCurSel();
	// 根据选中项索引获取该项字符串   
	m_ComboBox.GetLBText(nSel, strtype);
}




void 学生快速充值::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CUsers user2;
	user2.Login(m_username);
	user2.SearchBalance(m_username);
	
	UpdateData(TRUE);
	if (user2.GetPwd() != m_Pwd) {
		MessageBox(TEXT("密码错误！"));
	}
	else {
		user2.SearchCardStatus(m_username);
		if (user2.GetCardStatus() == "不可用")
		{
			MessageBox(TEXT("此卡已经挂失！"));
		}
		else {
			if (m_ChongZhi >= m_Balance) {
				MessageBox(TEXT("余额不足！"));
				return;
			}

			if (m_ChongZhi <= 0) {
				MessageBox(TEXT("请输入正数！"));
				return;
			}
			else
			{
				if (strtype == "")
					MessageBox(TEXT("请选择充值对象！"));
				else
				{
					if (strtype == "校园网") {
						user2.SearchSchoolNetBalance(m_username);
						user2.SetSchoolNetBalance(user2.GetSchoolNetBalance() + m_ChongZhi);
						user2.SetBalance(user2.GetBalance() - m_ChongZhi);
						user2.UpDateSchoolNetBalance(m_username);
						user2.UpDateBalance(m_username);
					}
					else
					{
						if (strtype == "宿舍电费") {
							user2.SearchEnergeCharge(m_username);
							user2.SetEnergeCharge(user2.GetEnergeCharge() + m_ChongZhi);
							user2.SetBalance(user2.GetBalance() - m_ChongZhi);
							user2.UpDateEnergeCharge(m_username);
							user2.UpDateBalance(m_username);
						}
						else
						{
							if (strtype == "宿舍空调") {
								user2.SearchAirCharge(m_username);
								user2.SetAirCharge(user2.GetAirCharge() + m_ChongZhi);
								user2.SetBalance(user2.GetBalance() - m_ChongZhi);
								user2.UpDateAirCharge(m_username);
								user2.UpDateBalance(m_username);
							}
						}
					}




					CString p;
					p.Format(_T("%.2f"), user2.GetBalance());
					GetDlgItem(IDC_EDIT3)->SetWindowText((LPCTSTR)p);
					MessageBox(TEXT("充值成功"));
				}
			}
		}
	}
		

	
}


void 学生快速充值::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CUsers user2;
	user2.SetUserName(m_username);
	user2.SearchBalance(user2.GetUser_Name());
	CString p;
	p.Format(_T("%.2f"), user2.GetBalance());
	GetDlgItem(IDC_EDIT3)->SetWindowText((LPCTSTR)p);
}
