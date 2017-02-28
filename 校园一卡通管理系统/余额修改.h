#pragma once


// 余额修改 对话框

class 余额修改 : public CDialogEx
{
	DECLARE_DYNAMIC(余额修改)

public:
	余额修改(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~余额修改();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CZ_yuexiugai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	double m_yu_e;
	afx_msg void OnBnClickedOk();
};
