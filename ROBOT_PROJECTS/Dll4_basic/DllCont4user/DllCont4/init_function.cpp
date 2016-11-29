//[Do NOT CHAGE]
#include "DllCont4.h"
#include "init_function.h"

PF_ResetRobot             ResetRobot;
PF_GetRobotFilePath       GetRobotFilePath;

PF_GetAnalogJoypadStatus  GetAnalogJoypadStatus;
PF_GetNormalJoypadStatus  GetNormalJoypadStatus;

PF_SetRefMotorTorque      SetRefMotorTorque;

PF_GetBodyPos             GetBodyPos;
PF_GetBodyRot             GetBodyRot;

PF_GetForceTorqueSensor_R GetForceTorqueSensor_R;
PF_GetForceTorqueSensor_L GetForceTorqueSensor_L;
PF_GetZmpLpfFreq          GetZmpLpfFreq;
PF_SetZmpLpfFreq          SetZmpLpfFreq;

PF_GetGyroRad             GetGyroRad;
PF_GetZmpPos              GetZmpPos;
PF_GetCgPos               GetCgPos;


bool InitFunctions(DLL_SIM_ROBOT4 *sim){
	ResetRobot = (PF_ResetRobot)(sim->GetFunc("ResetRobot"));
	if(ResetRobot==NULL){
		wchar_t *s=L"error. couldn't find function 'ResetRobot'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetRobotFilePath = (PF_GetRobotFilePath)(sim->GetFunc("GetRobotFilePath"));
	if(GetRobotFilePath==NULL){
		wchar_t *s=L"error. couldn't find function 'GetRobotFilePath'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetAnalogJoypadStatus = (PF_GetAnalogJoypadStatus)(sim->GetFunc("GetAnalogJoypadStatus"));
	if(GetAnalogJoypadStatus==NULL){
		wchar_t *s=L"error. couldn't find function 'GetAnalogJoypadStatus'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetNormalJoypadStatus = (PF_GetNormalJoypadStatus)(sim->GetFunc("GetNormalJoypadStatus"));
	if(GetNormalJoypadStatus==NULL){
		wchar_t *s=L"error. couldn't find function 'GetNormalJoypadStatus'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	SetRefMotorTorque = (PF_SetRefMotorTorque)(sim->GetFunc("SetRefMotorTorque"));
	if(GetNormalJoypadStatus==NULL){
		wchar_t *s=L"error. couldn't find function 'SetRefMotorTorque'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetBodyPos = (PF_GetBodyPos)(sim->GetFunc("GetBodyPos"));
	if(GetBodyPos==NULL){
		wchar_t *s=L"error. couldn't find function 'GetBodyPos'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetBodyRot = (PF_GetBodyRot)(sim->GetFunc("GetBodyRot"));
	if(GetBodyRot==NULL){
		wchar_t *s=L"error. couldn't find function 'GetBodyRot'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetForceTorqueSensor_R = (PF_GetForceTorqueSensor_R)(sim->GetFunc("GetForceTorqueSensor_R"));
	if(GetForceTorqueSensor_R==NULL){
		wchar_t *s=L"error. couldn't find function 'GetForceTorqueSensor_R'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetForceTorqueSensor_L = (PF_GetForceTorqueSensor_L)(sim->GetFunc("GetForceTorqueSensor_L"));
	if(GetForceTorqueSensor_L==NULL){
		wchar_t *s=L"error. couldn't find function 'GetForceTorqueSensor_L'.";
		sim->PrintCommandWindow(s);
		return false;
	}


	GetZmpLpfFreq = (PF_GetZmpLpfFreq)(sim->GetFunc("GetZmpLpfFreq"));
	if(GetZmpLpfFreq==NULL){
		wchar_t *s=L"error. couldn't find function 'GetZmpLpfFreq'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	SetZmpLpfFreq = (PF_SetZmpLpfFreq)(sim->GetFunc("SetZmpLpfFreq"));
	if(SetZmpLpfFreq==NULL){
		wchar_t *s=L"error. couldn't find function 'SetZmpLpfFreq'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetGyroRad = (PF_GetGyroRad)(sim->GetFunc("GetGyroRad"));
	if(GetGyroRad==NULL){
		wchar_t *s=L"error. couldn't find function 'GetGyroRad'.";
		sim->PrintCommandWindow(s);
		return false;
	}
	GetZmpPos = (PF_GetZmpPos)(sim->GetFunc("GetZmpPos"));
	if(GetZmpPos==NULL){
		wchar_t *s=L"error. couldn't find function 'GetZmpPos'.";
		sim->PrintCommandWindow(s);
		return false;
	}

	GetCgPos = (PF_GetCgPos)(sim->GetFunc("GetCgPos"));
	if(GetCgPos==NULL){
		wchar_t *s=L"error. couldn't find function 'GetCgPos'.";
		sim->PrintCommandWindow(s);
		return false;
	}


	return true;
}
