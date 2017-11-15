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

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#define _USE_MATH_DEFINES //for M_PI
#include <math.h>
#include <string>

#include "DllCont5.h"
#include "init_function.h"
#include "TcpClient.h"

#define DEG2RAD (M_PI/180.0)
#define RAD2DEG (180.0/M_PI)

#pragma warning(disable:4996)

using namespace std;

void Init(void);
void Close(void);

void testBasic();
void testDistanceSensor();
void testAnalogJoypad();
void testCamera();
void testVelRef();
void testTorqueRef();
void testZmpCalcInDll();
void testFootTouchSensor();
void testIk();
void testContact();
void testTcpClient();

//gloval
int gImsec=0;
CRobot robo;

//-----------------------------------------------------------------------
// Simulation Main Routine
// 5[ms](default) sampling
//-----------------------------------------------------------------------
void __stdcall Dll_Run() {

	//[[[ select the test function ]]]
	//testBasic();
	//testDistanceSensor();
	//testAnalogJoypad();
	//testCamera();
	//testVelRef();
	//testTorqueRef();
	//testZmpCalcInDll();
	//testFootTouchSensor();
	//testIk();
	//testContact();
	testTcpClient();

	//Time count up
	int dt = (int)(robo.GetDt() / 0.001);
	gImsec += dt;
	return;
}

//-----------------------------------------------------------------------
// DllMain
//   Do NOT CHANGE.
//-----------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved){
	switch (dwReason){
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Close();
		break;
	}
	return TRUE;
}

//-----------------------------------------------------------------------
// Initilize Routine
//-----------------------------------------------------------------------
void Init(void){
}
//-----------------------------------------------------------------------
// Close Routine
//-----------------------------------------------------------------------
void Close(void){
}

//-----------------------------------------------------------------------
// Dll Version
//   [DO NOT CHANGE]
//-----------------------------------------------------------------------
int __stdcall Dll_GetDllVersion() {
	return DLL_CONT_VERSION;
}

//-----------------------------------------------------------------------
// Function Setting
//-----------------------------------------------------------------------
bool __stdcall Dll_Initialize(GOSIMU_DLL_FUNC *sim) {
	bool ret = InitFunctions(sim);
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//------------------------------------------------------------------
// Motor angle command and motion execution
//------------------------------------------------------------------
void testBasic(){
	//Move slowly servomotor #17 from 0[deg] to 90[deg].
	if (gImsec < 3000){
		if (gImsec == 0){
			PrintMsg("Servomotor #17 is moving\n");
		}
		static double ref=0;
		if (ref < 90.0){
			int axis=17;
			ref+=0.1;
			robo.motor.SetRefPos(axis, ref * DEG2RAD);
			PrintMsg("ref=%lf now=%lf\n", ref, robo.motor.GetNowPos(axis)*RAD2DEG);
		}
	}

	//3000msec : run the motion file 0Walk.rmo
	if (gImsec == 3000){
		PrintMsg("command rmo(0Walk) is running\n");
		robo.RunScript(L"rmo(0Walk)");
	}

	//3005msec : This rmo command is ignored because the above "0Walk.rmo" is running.
	if (gImsec == 3005){
		PrintMsg("command rmo(0TurnRight) is ignored\n");
		robo.RunScript(L"rmo(0TurnRight)");
	}

	//8000msec : Notification termination of the operation of the DLL
	if (gImsec == 8000){
		PrintMsg("testBasic is finished\n");
		robo.FinishDll();
	}
}

//------------------------------------------------------------------
// Sample of motion execution and distance sensor acquisition
//------------------------------------------------------------------
void testDistanceSensor(){
	//Forward tilt (to make the distance sensors direct to the ground
	static double ref_zenkei=0;
	ref_zenkei+=0.1;
	if (ref_zenkei<30.0){
		robo.motor.SetRefPos(5, ref_zenkei * DEG2RAD);//Hip pitch
		robo.motor.SetRefPos(6, ref_zenkei * DEG2RAD);//Hip pitch
	}

	//Display of the value of the distance sensor.
	PrintMsg("dsensor ");
	for (int i=0; i<robo.sensor.GetDistanceNum(); i++){
		PrintMsg("[%d] %lf.3  ", i, robo.sensor.GetDistanceValue(i));
	}
	PrintMsg("\n");

	//Notification termination of the operation of the DLL
	if (gImsec == 4000){
		robo.FinishDll();//finish DLL 
	}
}


//------------------------------------------------------------------
// How to operate the joypad
// [NOTICE] Please PRESS the ANALOG button on the joypad to enable analog input.
//------------------------------------------------------------------
void testAnalogJoypad(){
	//Display the status of the analog joypad
	double ana_stick4[4];
	double ana_cross2[2];
	robo.joypad.GetAnalogStatus(ana_stick4, ana_cross2);
	PrintMsg("ana   = %lf %lf %lf %lf \n", ana_stick4[0], ana_stick4[1], ana_stick4[2], ana_stick4[3]);
	PrintMsg("cross = %lf %lf \n", ana_cross2[0], ana_cross2[1]);

	//Display the status of the normal joypad
	PrintMsg("normal = %d \n", robo.joypad.GetNormalStatus());

	//The shoulder joint of the robot is driven according to the operation amount of the analog joypad.
	double ref17 = -ana_stick4[1] * 90;
	double ref18 = -ana_stick4[3] * 90;
	double ref19 = -ana_stick4[0] * 90;
	double ref20 = ana_stick4[2] * 90;
	robo.motor.SetRefPos(17, ref17 * DEG2RAD);
	robo.motor.SetRefPos(18, ref18 * DEG2RAD);
	robo.motor.SetRefPos(19, ref19 * DEG2RAD);
	robo.motor.SetRefPos(20, ref20 * DEG2RAD);
}

//------------------------------------------------------------------
// The pixels data of the camera image
//------------------------------------------------------------------
void testCamera(){
	if (gImsec == 0){
		robo.camera.StartCapture();
	}

	PrintMsg("ena=%d w=%d h=%d\n", robo.camera.IsCaptured(),
		robo.camera.GetWidth(), robo.camera.GetHeight());


	if (robo.camera.IsCaptured()){
		wstring motion_full_path = robo.GetProjectPath() + L"Program/cam_test.txt";
		FILE *fp = _wfopen(motion_full_path.c_str(), L"wt");
		if (fp != NULL){
			int width = robo.camera.GetWidth();
			int height = robo.camera.GetHeight();
			const unsigned char *buf = robo.camera.GetImageOnce();

			// save only green pixel data
			for (int h=0; h<height; h++){
				for (int w=0; w<width; w++){
					int temp_size = width * 3;
					int temp_now  = h*width * 3 + w * 3 + 0;
					int r=buf[h*width * 3 + w * 3 + 0];
					int g=buf[h*width * 3 + w * 3 + 1];
					int b=buf[h*width * 3 + w * 3 + 2];
					fprintf(fp, "%X", g / 16);
				}
				fprintf(fp, "\n");
			}
			fclose(fp);
		}

	}

	//Notification termination of the operation of the DLL
	if (gImsec == 1000){
		PrintMsg("Pixel data is saved in 'Program/cam_test.txt'. ");
		robo.FinishDll();//finish DLL 
	}
}

//------------------------------------------------------------------
// Velocity Ref Control
//------------------------------------------------------------------
void testVelRef(){
	if (robo.GetJontCount() <= 19){
		return;
	}

	//Left Sholder Pitch Joint(ShoP_L) is set as "Hinge Joint" and "Velocity Control Motor"
	int axis = 18; //ShoP_R
	if (robo.motor.GetMode(axis) == 2)//check if velocity control mode
	{
		robo.motor.SetRefVel(18, 10 * DEG2RAD);
	} else{
		PrintMsg("Please set #18 motor to speed control mode.\r\n");
		robo.FinishDll();
	}

	if (gImsec == 8000){
		robo.motor.SetRefVel(18, 0 * DEG2RAD);
		PrintMsg("Finished\r\n");
		robo.FinishDll();
	}
}

//------------------------------------------------------------------
// Torque Control (PD Control)
//------------------------------------------------------------------
void testTorqueRef(){
	if (robo.GetJontCount() <= 18){
		return;
	}

	//Right Sholder Pitch Joint(ShoP_R) should be set "Hinge Joint" and "Torque Control Motor"
	int axis = 17; //ShoP_R
	if (robo.motor.GetMode(axis) == 3)//check if torqye control mode
	{
		static double bx=0;
		static double ref=0;

		//angle ref : 0 to 120[deg]
		ref+=0.1;
		if (ref>120){
			ref=120;
		}

		double x = robo.motor.GetNowPos(axis)*RAD2DEG;//now angle
		double v = (x - bx) / robo.GetDt();//vel
		bx = x;//back up

		//PD Control
		double kp = 0.04;
		double kd = 0.001;
		double f = kp*(ref - x) - kd*v;

		//Output Torque Ref
		robo.motor.SetRefTorque(axis, f);

		//message
		PrintMsg("Ang ref=%lf ang now=%lf trq=%lf \n", ref, x, f);
	} else{
		PrintMsg("Please set #17 motor to torque control mode.\r\n");
		robo.FinishDll();
	}

	if (gImsec == 8000){
		robo.motor.SetRefTorque(axis, 0);
		PrintMsg("Finished\r\n");
		robo.FinishDll();
	}

}

//------------------------------------------------------------------
// Calculate ZMP In this DLL
// Although Go Simulation! has the ZMP calculation function,
// this sample shows a case where the user performs ZMP calculation independently.
//------------------------------------------------------------------
void testZmpCalcInDll(){

	// In GoSimu, ZMP is calulated, and this ZMP value is applied 2nd low-pass-filter(LPF);
	// In this sample, as we want to use ZMP value which is not applied LPF, LPF freq is set to very high(10000Hz).
	double now_freq=robo.sensor.GetZmpLpfFreq();
	if (now_freq<10000.0){
		printf("now_freq! = %lf\n", now_freq);
		robo.sensor.SetZmpLpfFreq(10000.0);//equilavant to NO LPF
	}

	//walk motion
	if (gImsec == 1000){
		robo.RunScript(L"rmo(0Walk)");
	}
	// measurement position,  force,  torque
	double posR[3], fR[3], tR[3];
	double posL[3], fL[3], tL[3];
	bool retR = robo.sensor.GetForceTorque_R(posR, fR, tR);
	bool retL = robo.sensor.GetForceTorque_L(posL, fL, tL);
	// If sensor is not set, finished.
	if (retR == false || retL == false){
		return;
	}

	//distance between ground and senser(joint) position.
	double dd = 0.04;

	//Check of Contact
	//force z(fR[2]) should be minus. If not, a foot does not contact to ground.
	if (fR[2] >= 0){
		fR[0] = fR[1] = fR[2]=0;
		tR[0] = tR[1] = tR[2]=0;
	}
	if (fL[2] >= 0){
		fL[0] = fL[1] = fL[2]=0;
		tL[0] = tL[1] = tL[2]=0;
	}

	bool Zmp_exist=true;
	if (fR[2] >= 0 && fL[2] >= 0){
		Zmp_exist=false;//no ZMP
	}

	if (Zmp_exist){
		//ヒューマノイドロボット　3.24 3.25式
		double numX=0;
		numX += -tR[1] - dd * fR[0] + posR[0] * fR[2];
		numX += -tL[1] - dd * fL[0] + posL[0] * fL[2];
		double denX=0;
		denX += fR[2];
		denX += fL[2];

		double numY=0;
		numY += tR[0] - dd * fR[1] + posR[1] * fR[2];
		numY += tL[0] - dd * fL[1] + posL[1] * fL[2];
		double denY=0;
		denY += fR[2];
		denY += fL[2];

		//ZMP
		double zmp[3];
		zmp[0] = numX / denX;
		zmp[1] = numY / denY;
		zmp[2] = 0; //contact point (ground) is z=0;

		//Show in CommandWIndow
		double gosimu_zmp[3];
		robo.sensor.GetZmpPos(gosimu_zmp);
		PrintMsg("zmp gosimu %.3lf %.3lf %.3lf", gosimu_zmp[0], gosimu_zmp[1], gosimu_zmp[2]);
		PrintMsg(" : dll %.3lf %.3lf %.3lf\r\n", zmp[0], zmp[1], zmp[2]);
	}

	if (gImsec == 8000){
		PrintMsg("Finished\r\n");
		robo.FinishDll();
	}

}

//------------------------------------------------------------------
//Left and right foot grounding sensor
//------------------------------------------------------------------
void testFootTouchSensor(){
	if (gImsec == 500){
		robo.RunScript(L"rmo(0Walk)");
	}

	PrintMsg("Touch R=%d L=%d\n", robo.sensor.IsTouchingFoot_R(), robo.sensor.IsTouchingFoot_L());

	if (gImsec == 8000){
		PrintMsg("Finished\r\n");
		robo.FinishDll();
	}
}

//------------------------------------------------------------------
//IK
//------------------------------------------------------------------
void testIk(){
	int fix1 = 11;
	int fix2 = 12;
	int move = 0;
	double err;
	if (gImsec < 1000){
		double dMovePos[3] ={ 0, 0, -0.0002 };
		double dMoveRot[3] ={ 0, 0, 0 };
		//fix 11  move 0
		robo.motor.MoveIk(fix1, move, dMovePos, dMoveRot, &err);
		//fix 12  move 0
		robo.motor.MoveIk(fix2, move, dMovePos, dMoveRot, &err);
	} else if (gImsec < 2000){
		double dMovePos[3] ={ 0.0002, 0, 0 };
		double dMoveRot[3] ={ 0, 0, 0 };
		//fix 11  move 0
		robo.motor.MoveIk(fix1, move, dMovePos, dMoveRot, &err);
		//fix 12  move 0
		robo.motor.MoveIk(fix2, move, dMovePos, dMoveRot, &err);
	} else if (gImsec < 4000){
		double dMovePos[3] ={ 0, 0.0002, 0 };
		double dMoveRot[3] ={ 0, 0, 0 };
		//fix 11  move 0
		robo.motor.MoveIk(fix1, move, dMovePos, dMoveRot, &err);
		//fix 12  move 0
		robo.motor.MoveIk(fix2, move, dMovePos, dMoveRot, &err);
	} else if (gImsec < 4500){
		double dMovePos[3] ={ 0, 0, 0 };
		double dMoveRot[3] ={ -0.05, 0, 0 };
		//fix 11  move 0
		robo.motor.MoveIk(fix1, move, dMovePos, dMoveRot, &err);
		//fix 12  move 0
		robo.motor.MoveIk(fix2, move, dMovePos, dMoveRot, &err);
	}

	if (gImsec == 5000){
		robo.FinishDll();//finish DLL 
	}
}

//------------------------------------------------------------------
// Contact sensor
// Please set the contact sensor infomation at Design/contact_sensor.txt
// In this sample, it is assumed that contact sensors are set on Bodies #23 and#24.
// #23 : Right Hand
// #24 : Left Hand
//------------------------------------------------------------------
void testContact(){
	if (gImsec == 1000){
		PrintMsg("Wake Up Motion\r\n");
		robo.RunScript(L"rmo(Okiagari1)");
	}

	std::stringstream ss;
	for (int i=0; i < robo.sensor.GetContactNum(); i++){
		bool flg = robo.sensor.GetContactFlg(i);
		ss << flg << "  ";
	}
	ss << endl;
	PrintMsg(ss);

	if (gImsec == 6000){
		robo.FinishDll();
	}
}

//------------------------------------------------------------------
// TCP Communication
// This Dll is client side.
//------------------------------------------------------------------
CTcpClient gTcpClient;

# pragma pack (1)
typedef struct {
	int CommandA;
	int CommandB;
} MyTcpCmd;
# pragma pack ()

# pragma pack (1)
typedef struct {
	double AnswerX;
} MyTcpTelem;
# pragma pack ()

MyTcpCmd gTcpCmd;
MyTcpTelem gTcpTlm;

void testTcpClient(){
	char ipadr[] = "127.0.0.1";
	int port = 50000;
	//Initialize
	if (gImsec == 0){
		bool ret = gTcpClient.Connect(ipadr, port);
		if (ret == false){
			PrintMsg("Could not connect to TCP server(%s).\n", ipadr);
			robo.FinishDll();
		}
	}

	//Receive all. 
	//Only the last received data is used.
	//受信バッファにたまっているものを全て取り出し、最新の値を使用する
	bool is_received = false;
	while (gTcpClient.Select()){// if there are received data in buffer
		//receive
		int recv_num = gTcpClient.Recv((char*)(&gTcpCmd), sizeof(gTcpCmd));
		if (recv_num <= 0){
			//connection error
			gTcpClient.Close();
			PrintMsg("Connection Error\n");
			robo.FinishDll();
		}
		is_received = true;
	}

	//If received, print thmem. And send message.
	if(is_received){
		//print
		PrintMsg("Recv -> gTcpCmd.CommandA = %d\n", gTcpCmd.CommandA);
		//send
		gTcpTlm.AnswerX = 0.001 * gTcpCmd.CommandA;
		PrintMsg("Send <- gTcpTlm.AnswerX = %lf\n", gTcpTlm.AnswerX);
		gTcpClient.Send((char*)(&gTcpTlm), sizeof(gTcpTlm));

		//move axis #17
		int axis=17;
		double ref = gTcpTlm.AnswerX;
		robo.motor.SetRefPos(axis, ref * DEG2RAD);
	}

	if (gImsec == 6000){
		PrintMsg("DLL Finished.\n");
		robo.FinishDll();
	}
}
