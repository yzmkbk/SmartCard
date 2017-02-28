#pragma once


// 管理员快速充值 对话框

class 管理员快速充值 : public CDialogEx
{
	DECLARE_DYNAMIC(管理员快速充值)

public:
	管理员快速充值(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~管理员快速充值();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	int m_ChongZhi;
	afx_msg void OnBnClickedOk();
};
