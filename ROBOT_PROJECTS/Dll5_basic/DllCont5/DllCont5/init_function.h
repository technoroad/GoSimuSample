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

#pragma once

#include <string>
#include <sstream>

bool InitFunctions(GOSIMU_DLL_FUNC *sim);

//Print a message in the command window.
void PrintMsg(const std::string &msg);
void PrintMsg(const std::stringstream &ss);
void PrintMsg(const char *format, ...);

class CSensor {
public:
	//Get the value of gyro sensor. The sensor is in the center of body 0.
	void GetGyroRad(double ret[3]);
	//Get the center of gravity position. The sensor is in the center of body 0.
	void GetCgPos(double ret[3]);
	//Get the position of ZMP.
	void GetZmpPos(double ret[3]);

	//[The distance sensor is set in Design / dsensor.txt.]
	//Get the number of distance sensors.
	int GetDistanceNum();
	//Get the value of the distance sensor.
	double GetDistanceValue(int id);

	//[Contact sensor is set in Design / contact_sensor.txt.]
	//Get the number of contact sensors.
	int GetContactNum();
	//Get the value of the contact sensor.
	bool GetContactFlg(int id);

	//Get the frequency of LowPassFilter (LPF) for ZMP calculation.
	double GetZmpLpfFreq();
	//Set the frequency of LowPassFilter(LPF) for ZMP calculation.
	void SetZmpLpfFreq(double freq_hz);
	//Get the value of the force torque sensor for ZMP calculation (for the right foot).
	bool GetForceTorque_R(double position[3], double force[3], double torque[3]);
	//Get the value of the force torque sensor for ZMP calculation (for the left foot).
	bool GetForceTorque_L(double position[3], double force[3], double torque[3]);
	//It is judged whether the right foot is installed on the ground.
	bool IsTouchingFoot_R();
	//It is judged whether the left foot is installed on the ground.
	bool IsTouchingFoot_L();
};

class CMotor {
public:
	//Get current position.
	double GetNowPos(int axis);
	//Set position command value.
	void SetRefPos(int axis, double ref);
	//Set velocity command value.
	void SetRefVel(int axis, double ref);
	//Set torque command value.
	void SetRefTorque(int axis, double trq);
	//Get motor control mode  1:position 2:velocity 3:torque
	int GetMode(int axis);
	//Get control gain of servomotor
	void GetServoParam(int axis, double *speed, double *kp, double *kd);
	//Set control gain of servomotor
	void SetServoParam(int axis, double speed, double kp, double kd);
	//Inverse kinematics drive command
	void MoveIk(int fix1_id, int move1_id, const double movePos[3], const double moveRot[3], double *ik_err);
};

class CCamera {
public:
	//Start capture.
	void StartCapture();
	//Stop capture
	void StopCapture();
	//Check whether the camera data has been updated.
	bool IsCaptured();

	//Get width of captured image
	int GetWidth();
	//Get height of captured image
	int GetHeight();
	//Get captured image
	const unsigned char * GetImageOnce();
};


class CJoyPad {
public:
	//Get the status of normal button
	int GetNormalStatus();
	//Get the status of analog stick and cross button.
	void GetAnalogStatus(double stick[4], double cross[2]);
};

class CRobot {
public:
	CSensor sensor;
	CCamera camera;
	CMotor motor;
	CJoyPad joypad;

	//Finish this dll program
	void FinishDll();
	//Reset robot simulation.
	void Reset();
	//Get dt[msec]
	double GetDt();
	//Get robot project's full path
	std::wstring GetProjectPath();

	//Run script command
	void RunScript(const wchar_t *cmd);
	void RunScript(const std::wstring &cmd);

	//Get the number of joints 
	int GetJontCount();
	//GetBody Position Vector
	void GetBodyPos(double ret_pos[3], int axis);
	//Get Body Rotation Matrix
	void GetBodyRot(double ret_R[12], int axis);
	void ToSimulink50(double buf[50]);
};

