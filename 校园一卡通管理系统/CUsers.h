#pragma once

#include "ADOConn.h"
#include "afxwin.h"

class CUsers
{
	CString UserName;
	CString Pwd;
	CString User_type;
	CString Name;
	CString College;
	CString Class;
	CString Dorm;
	CString CardStatus;
	int MorningRunNum;
	double Balance;
	double SchoolNetBalance;
	double EnergeCharge;
	double AirCharge;

public:
	CUsers::CUsers()
	{
		UserName = "";
		Pwd = "";
		User_type = "";
		Name = "";
		College = "";
		Class = "";
		Dorm = "";
		CardStatus = "";
		MorningRunNum = 0;
		Balance = 0;
		SchoolNetBalance = 0;
		EnergeCharge = 0;
		AirCharge = 0;
	}

	CUsers::~CUsers()
	{

	}

	CString CUsers::GetUser_Name()
	{
		return UserName;
	}

	void CUsers::SetUserName(CString cUserName)
	{
		UserName = cUserName;
	}

	CString CUsers::GetPwd()
	{
		return Pwd;
	}

	void CUsers::SetPwd(CString cPwd)
	{
		Pwd = cPwd;
	}

	CString CUsers::GetUser_type()
	{
		return User_type;
	}

	void CUsers::SetUser_type(CString iUser_type)
	{
		User_type = iUser_type;
	}

	CString CUsers::GetName()
	{
		return Name;
	}

	void CUsers::SetName(CString cName)
	{
		Name = cName;
	}

	CString CUsers::GetCollege()
	{
		return College;
	}

	void CUsers::SetCollege(CString cCollege)
	{
		College = cCollege;
	}

	CString CUsers::GetClass()
	{
		return Class;
	}

	void CUsers::SetClass(CString cClass)
	{
		Class = cClass;
	}

	CString CUsers::GetDorm()
	{
		return Dorm;
	}

	void CUsers::SetDorm(CString cDorm)
	{
		Dorm = cDorm;
	}

	CString CUsers::GetCardStatus()
	{
		return CardStatus;
	}

	void CUsers::SetCardStatus(CString cCardStatus)
	{
		CardStatus = cCardStatus;
	}

	int CUsers::GetMorningRunNum()
	{
		return MorningRunNum;
	}

	void CUsers::SetMorningRunNum(int cMorningRunNum)
	{
		MorningRunNum = cMorningRunNum;
	}

	double CUsers::GetBalance()
	{
		return Balance;
	}

	void CUsers::SetBalance(double cBalance)
	{
		Balance = cBalance;
	}

	double CUsers::GetSchoolNetBalance()
	{
		return SchoolNetBalance;
	}

	void CUsers::SetSchoolNetBalance(double cSchoolNetBalance)
	{
		SchoolNetBalance = cSchoolNetBalance;
	}

	double CUsers::GetEnergeCharge()
	{
		return EnergeCharge;
	}

	void CUsers::SetEnergeCharge(double cEnergeCharge)
	{
		EnergeCharge = cEnergeCharge;
	}

	double CUsers::GetAirCharge()
	{
		return AirCharge;
	}

	void CUsers::SetAirCharge(double cAirCharge)
	{
		AirCharge = cAirCharge;
	}

	int CUsers::Login(CString cUserName)
	{
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		Pwd = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("Pwd");
		User_type = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("User_type");

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	}
	int CUsers::SearchName(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
			Name = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("Name");

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};

	int CUsers::SearchMorningRunNum(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
			MorningRunNum = atoi((const char*)(_bstr_t)m_pRecordset->GetCollect("MorningRunNum"));

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};

	int CUsers::SearchBalance(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		Balance = atof((_bstr_t)m_pRecordset->GetCollect("Balance"));

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	int CUsers::SearchSchoolNetBalance(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		SchoolNetBalance = atof((_bstr_t)m_pRecordset->GetCollect("SchoolNetBalance"));

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	int CUsers::SearchEnergeCharge(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
			EnergeCharge = atof((_bstr_t)m_pRecordset->GetCollect("EnergeCharge"));

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	int CUsers::SearchAirCharge(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		AirCharge = atof((_bstr_t)m_pRecordset->GetCollect("AirCharge"));

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	
	int CUsers::SearchCollege(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		College = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("College");

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	int CUsers::SearchClass(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		Class = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("Class");

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	int CUsers::SearchDorm(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else
			UserName = cUserName;
		Dorm = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("Dorm");

		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};
	int CUsers::SearchCardStatus(CString cUserName) {
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		CString p("SELECT * FROM Users WHERE UserName= '");
		vSQL = p + cUserName + "'";

		//执行SELECT语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
		if (m_pRecordset->adoEOF)
			return -1;
		else {
			UserName = cUserName;
			CardStatus = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("CardStatus");
		}
		return 1;

		//断开与数据库的连接
		m_AdoConn.ExitConnect();

	};

	void UpDateSchoolNetBalance(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句
		CString SchoolNetBalance1;

		SchoolNetBalance1.Format(_T("%f"), SchoolNetBalance);

		_bstr_t vSQL;
		CString SchoolNetBalance2("UPDATE Users SET SchoolNetBalance='");

		vSQL = SchoolNetBalance2 + SchoolNetBalance1 + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};

	void UpDateBalance(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句
		CString Balance1;

		Balance1.Format(_T("%f"), Balance);

		_bstr_t vSQL;
		CString Balance2("UPDATE Users SET Balance='");

		vSQL = Balance2 + Balance1 + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};

	void UpDateEnergeCharge(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句
		CString EnergeCharge1;

		EnergeCharge1.Format(_T("%f"), EnergeCharge);

		_bstr_t vSQL;
		CString EnergeCharge2("UPDATE Users SET EnergeCharge='");

		vSQL = EnergeCharge2 + EnergeCharge1 + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void UpDateAirCharge(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句
		CString AirCharge1;

		AirCharge1.Format(_T("%f"), AirCharge);

		_bstr_t vSQL;
		CString AirCharge2("UPDATE Users SET AirCharge='");

		vSQL = AirCharge2 + AirCharge1 + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};

	void UpDateName(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句


		_bstr_t vSQL;
		CString Name2("UPDATE Users SET Name='");

		vSQL = Name2 + Name + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void UpDateCollege(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句


		_bstr_t vSQL;
		CString College2("UPDATE Users SET College='");

		vSQL = College2 + College + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void UpDateClass(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句


		_bstr_t vSQL;
		CString Class2("UPDATE Users SET Class='");

		vSQL = Class2 + Class + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void UpDateDorm(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句


		_bstr_t vSQL;
		CString Dorm2("UPDATE Users SET Dorm='");

		vSQL = Dorm2 + Dorm + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void UpDateCardStatus(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句


		_bstr_t vSQL;
		CString CardStatus2("UPDATE Users SET CardStatus='");

		vSQL = CardStatus2 + CardStatus + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void UpDateMorningRunNum(CString cUserName) {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置UPDATE语句
		CString MorningRunNum1;

		MorningRunNum1.Format(_T("%d"), MorningRunNum);

		_bstr_t vSQL;
		CString MorningRunNum2("UPDATE Users SET MorningRunNum='");

		vSQL = MorningRunNum2 + MorningRunNum1 + "' WHERE UserName='" + cUserName + "'";
		//执行UPDATE语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
	void New() {
		//连接数据库
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置INSERT语句


		User_type = "S";
		CardStatus = "可用";
		_bstr_t vSQL;
		CString new1("INSERT into Users values('");
		CString new2,new3;
		new2.Format(_T("%d"),MorningRunNum);
		new3.Format(_T("%.2f"), Balance);
		vSQL = new1 + UserName+"','" + Pwd + "','" + User_type + "','" + Name + "','" + College + "','" + Class + "','" + Dorm + "','" + CardStatus +  "','" + new3 +"','"+new2+"','"+new3+"','"+new3+"','"+new3+ "')";
		//执行Insert语句
		m_AdoConn.ExecuteSQL(vSQL);
		//断开与数据库的连接
		m_AdoConn.ExitConnect();
	};
};