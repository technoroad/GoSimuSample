/*
The MIT License (MIT)

Copyright (c) 2017 Techno Road Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


//[Do NOT CHAGE]

#include "DllCont5.h"
#include "init_function.h"

#pragma warning(disable:4996)

// Define Function
#define DEF_FUNC(ret, proc, ...) \
	typedef ret(*PF_##proc)(## __VA_ARGS__); \
	PF_##proc             proc;

// Get Function
#define GET_FUNC(proc) \
	proc = (PF_##proc)(sim->GetFunc(#proc));  \
	if (proc == NULL){ \
		wchar_t *s=L"error. couldn't find function '"  L#proc   L"'."; \
		if(PrintCommandWindowW!=NULL){ PrintCommandWindowW(s); } \
		return false; \
	}

//------------------------------------------------------------------------------------
//function definition
DEF_FUNC(bool, IsCameraCaptured, void);
DEF_FUNC(int, GetCameraImageWidth, void);
DEF_FUNC(int, GetCameraImageHeight, void);
DEF_FUNC(const unsigned char*, GetCameraImageOnce, void);
DEF_FUNC(void, FinishDll, void);
DEF_FUNC(void, ResetRobot, void);
DEF_FUNC(const wchar_t *, GetRobotFilePath, void);
DEF_FUNC(void, RunScriptCommand, const wchar_t *);
DEF_FUNC(void, GetAnalogJoypadStatus, double stick[4], double cross[2]);
DEF_FUNC(int, GetNormalJoypadStatus, void);
DEF_FUNC(void, SetRefMotorTorque, int id, double torque);
DEF_FUNC(void, GetBodyPos, double ret_pos[3], int id);
DEF_FUNC(void, GetBodyRot, double ret_R[12], int id);
DEF_FUNC(bool, GetForceTorqueSensor_R, double position[3], double force[3], double torque[3]);
DEF_FUNC(bool, GetForceTorqueSensor_L, double position[3], double force[3], double torque[3]);
DEF_FUNC(bool, CalIK, int fix1_id, int move1_id, const double movePos[3], const double moveRot[3], double *ik_err);
DEF_FUNC(double, GetZmpLpfFreq, void);
DEF_FUNC(void, SetZmpLpfFreq, double freq_hz);
DEF_FUNC(void, GetGyroRad, double ret[3]);
DEF_FUNC(void, GetZmpPos, double ret[3]);
DEF_FUNC(void, GetCgPos, double ret[3]);
DEF_FUNC(void, MoveServoPos, int id, double ref);
DEF_FUNC(void, MoveServoVel, int id, double ref);
DEF_FUNC(void, PrintCommandWindowW, const wchar_t *msg);
DEF_FUNC(void, PrintCommandWindowA, const char *msg);
DEF_FUNC(int, GetJointCount, void);
DEF_FUNC(int, GetServoControlMode, int axis);
DEF_FUNC(int, GetDistanceSensorCount, void);
DEF_FUNC(double, GetDistanceSensorValue, int id);
DEF_FUNC(double, GetSevoNowPos, int id);
DEF_FUNC(bool, GetServoParam, int id, double *speed, double *kp, double *kd);
DEF_FUNC(bool, SetServoParam, int id, double speed, double kp, double kd);
DEF_FUNC(bool, GetTouchRFootSensor, void);
DEF_FUNC(bool, GetTouchLFootSensor, void);
DEF_FUNC(double, GetDt, void);
DEF_FUNC(void, ToSimulink50, const double *buf);
DEF_FUNC(void, StartCameraCapture, void);
DEF_FUNC(void, StopCameraCapture, void);
DEF_FUNC(int, GetContactSensorCount, void);
DEF_FUNC(bool, GetContactSensorFlg, int id);

bool InitFunctions(GOSIMU_DLL_FUNC *sim){
	GET_FUNC(FinishDll);
	GET_FUNC(ResetRobot);
	GET_FUNC(GetRobotFilePath);
	GET_FUNC(RunScriptCommand);
	GET_FUNC(GetAnalogJoypadStatus);
	GET_FUNC(GetNormalJoypadStatus);
	GET_FUNC(SetRefMotorTorque);
	GET_FUNC(GetBodyPos);
	GET_FUNC(GetBodyRot);
	GET_FUNC(GetForceTorqueSensor_R);
	GET_FUNC(GetForceTorqueSensor_L);
	GET_FUNC(CalIK);
	GET_FUNC(GetZmpLpfFreq);
	GET_FUNC(SetZmpLpfFreq);
	GET_FUNC(GetGyroRad);
	GET_FUNC(GetZmpPos);
	GET_FUNC(GetCgPos);
	GET_FUNC(MoveServoPos);
	GET_FUNC(MoveServoVel);
	GET_FUNC(PrintCommandWindowW);
	GET_FUNC(PrintCommandWindowA);
	GET_FUNC(GetJointCount);
	GET_FUNC(GetServoControlMode);
	GET_FUNC(GetDistanceSensorCount);
	GET_FUNC(GetDistanceSensorValue);
	GET_FUNC(GetSevoNowPos);
	GET_FUNC(GetServoParam);
	GET_FUNC(SetServoParam);
	GET_FUNC(GetTouchRFootSensor);
	GET_FUNC(GetTouchLFootSensor);
	GET_FUNC(GetDt);
	GET_FUNC(ToSimulink50);
	GET_FUNC(StartCameraCapture);
	GET_FUNC(StopCameraCapture);
	GET_FUNC(GetContactSensorCount);
	GET_FUNC(GetContactSensorFlg);
	GET_FUNC(IsCameraCaptured);
	GET_FUNC(GetCameraImageWidth);
	GET_FUNC(GetCameraImageHeight);
	GET_FUNC(GetCameraImageOnce);
	return true;
}

//---------- wrapper ----------

//Print function
void PrintMsg(const std::string &msg){
	::PrintCommandWindowA(msg.c_str());
}
void PrintMsg(const std::stringstream &ss){
	std::string str = ss.str();
	::PrintCommandWindowA(str.c_str());
}
void PrintMsg(const char *format, ...) {
	char tsv[1024] ={ L'\0' };
	va_list arg;

	va_start(arg, format);
	vsprintf(tsv, format, arg);
	va_end(arg);

	::PrintCommandWindowA(tsv);
}


#pragma region CSensor
void CSensor::GetGyroRad(double ret[3]){
	::GetGyroRad(ret);
}
void CSensor::GetCgPos(double ret[3]){
	::GetCgPos(ret);
}
void CSensor::GetZmpPos(double ret[3]){
	::GetZmpPos(ret);
}

int CSensor::GetDistanceNum(){
	return ::GetDistanceSensorCount();
}
double CSensor::GetDistanceValue(int id){
	return ::GetDistanceSensorValue(id);
}

int CSensor::GetContactNum(){
	return GetContactSensorCount();
}
bool CSensor::GetContactFlg(int id){
	return GetContactSensorFlg(id);
}


double CSensor::GetZmpLpfFreq(){
	return ::GetZmpLpfFreq();
}
void CSensor::SetZmpLpfFreq(double freq_hz){
	::SetZmpLpfFreq(freq_hz);
}
bool CSensor::GetForceTorque_R(double position[3], double force[3], double torque[3]){
	return GetForceTorqueSensor_R(position, force, torque);
}
bool CSensor::GetForceTorque_L(double position[3], double force[3], double torque[3]){
	return GetForceTorqueSensor_L(position, force, torque);
}
bool CSensor::IsTouchingFoot_R(){
	return ::GetTouchRFootSensor();
}
bool CSensor::IsTouchingFoot_L(){
	return ::GetTouchLFootSensor();
}
#pragma endregion

#pragma region CMotor
void CMotor::SetRefPos(int axis, double ref){
	::MoveServoPos(axis, ref);
}
void CMotor::SetRefVel(int axis, double ref){
	::MoveServoVel(axis, ref);
}
double CMotor::GetNowPos(int axis){
	return GetSevoNowPos(axis);
}
void CMotor::SetRefTorque(int axis, double trq){
	::SetRefMotorTorque(axis, trq);
}
void CMotor::MoveIk(int fix1_id, int move1_id, const double movePos[3], const double moveRot[3], double *ik_err){
	::CalIK(fix1_id, move1_id, movePos, moveRot, ik_err);
}
int CMotor::GetMode(int axis){
	return ::GetServoControlMode(axis);
}
void CMotor::GetServoParam(int axis, double *speed, double *kp, double *kd){
	::GetServoParam(axis, speed, kp, kd);
}
void CMotor::SetServoParam(int axis, double speed, double kp, double kd){
	::SetServoParam(axis, speed, kp, kd);
}
#pragma endregion

#pragma region CCamera
void CCamera::StartCapture(){
	StartCameraCapture();
}
void CCamera::StopCapture(){
	StopCameraCapture();
}
bool CCamera::IsCaptured(){
	return IsCameraCaptured();
}
int CCamera::GetWidth(){
	return ::GetCameraImageWidth();
}
int CCamera::GetHeight(){
	return ::GetCameraImageHeight();
}
const unsigned char * CCamera::GetImageOnce(){
	return ::GetCameraImageOnce();
}
#pragma endregion


#pragma region CJoyPad
int CJoyPad::GetNormalJoypad(){
	return GetNormalJoypadStatus();
}
void CJoyPad::GetAnalogStatus(double stick[4], double cross[2]){
	::GetAnalogJoypadStatus(stick, cross);
}
#pragma endregion

#pragma region CRobot
void CRobot::FinishDll(){
	::FinishDll();
}
void CRobot::Reset(){
	::ResetRobot();
}
double CRobot::GetDt(){
	return ::GetDt();
}
std::wstring CRobot::GetProjectPath(){
	std::wstring ret = ::GetRobotFilePath();
	return ret;
}
void CRobot::RunScript(const wchar_t *cmd){
	::RunScriptCommand(cmd);
}
void CRobot::RunScript(const std::wstring &cmd){
	::RunScriptCommand(cmd.c_str());
}
int CRobot::GetJontCount(){
	return ::GetJointCount();
}
void CRobot::GetBodyPos(double ret_pos[3], int axis){
	::GetBodyPos(ret_pos, axis);
}
void CRobot::GetBodyRot(double ret_R[12], int axis){
	::GetBodyPos(ret_R, axis);
}
void CRobot::ToSimulink50(double buf[50]){
	::ToSimulink50(buf);
}
#pragma endregion

