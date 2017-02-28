#pragma once


// 添加学生 对话框

class 添加学生 : public CDialogEx
{
	DECLARE_DYNAMIC(添加学生)

public:
	添加学生(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~添加学生();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	CString m_Pwd;
	CString m_Name;
	CString m_College;
	CString m_Class;
	CString m_Dorm;
	afx_msg void OnBnClickedOk();
};
