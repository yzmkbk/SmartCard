#pragma once
#include "afxwin.h"


// 学生快速充值 对话框

class 学生快速充值 : public CDialogEx
{
	DECLARE_DYNAMIC(学生快速充值)

public:
	学生快速充值(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~学生快速充值();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CZ_xiaoyuanwang };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_ChongZhi;
	CString m_Pwd;
	double m_Balance;
	CComboBox m_ComboBox;
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	CString m_username;
};
