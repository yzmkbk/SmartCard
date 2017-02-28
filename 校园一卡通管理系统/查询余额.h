#pragma once


// 查询余额 对话框

class 查询余额 : public CDialogEx
{
	DECLARE_DYNAMIC(查询余额)

public:
	查询余额(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~查询余额();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	CString m_balance;
	afx_msg void OnPaint();
	CString m_balance2;
};
