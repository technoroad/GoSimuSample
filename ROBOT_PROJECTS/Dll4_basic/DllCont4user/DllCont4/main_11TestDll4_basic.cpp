/*
Go Simulation! DLL Sample
2014 TECHNO-ROAD Inc.

This program is for DLL_CONT_VERSION 0x004
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "DllCont4.h"

#pragma warning(disable:4996)

void Init(void);
void Close(void);

//gloval
DLL_SIM_CAMERA *Cam=NULL;
int gImsec=0;
void testAnalogJoypad(DLL_SIM_ROBOT4 *sim);
void testMotionDSensor( DLL_SIM_ROBOT4 *sim);
void testCamera( DLL_SIM_ROBOT4 *sim);
void testTorqueRef(DLL_SIM_ROBOT4 *sim);
void testSimulinkFootSensoer(DLL_SIM_ROBOT4 *sim);
void testZmpCalcInDll(DLL_SIM_ROBOT4 *sim);

PF_ResetRobot            ResetRobot;
PF_GetRobotFilePath      GetRobotFilePath;
PF_GetAnalogJoypadStatus GetAnalogJoypadStatus;
PF_GetNormalJoypadStatus GetNormalJoypadStatus;
PF_SetRefMotorTorque SetRefMotorTorque;
PF_GetForceTorqueSensor_R GetForceTorqueSensor_R;
PF_GetForceTorqueSensor_L GetForceTorqueSensor_L;
PF_GetZmpLpfFreq          GetZmpLpfFreq;
PF_SetZmpLpfFreq          SetZmpLpfFreq;

//-----------------------------------------------------------------------
// DllMain
//   Do NOT CHANGE.
//-----------------------------------------------------------------------
BOOL WINAPI DllMain( HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved ){
	switch(dwReason){
		case DLL_PROCESS_ATTACH:
			printf("DLL_PROCESS_ATTACH\n");
			Init();
		break;
//		case DLL_THREAD_ATTACH:
//			printf("DLL_THREAD_ATTACH\n");
//		break;
//		case DLL_THREAD_DETACH:
//			printf("DLL_THREAD_DETACHH\n");
//		break;
		case DLL_PROCESS_DETACH:
			printf("DLL_PROCESS_DETACH\n");
			Close();
		break;
	}
	return TRUE;
}

//-----------------------------------------------------------------------
// Initilize Routine
//-----------------------------------------------------------------------
void Init( void ){
	Cam = new DLL_SIM_CAMERA;
}
//-----------------------------------------------------------------------
// Close Routine
//-----------------------------------------------------------------------
void Close( void ){
	delete Cam;
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
bool __stdcall Dll4_Initialize( DLL_SIM_ROBOT4 *sim) {
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
	return true;
}


//-----------------------------------------------------------------------
// Simulation Main Routine
// 5[ms] sampling
//-----------------------------------------------------------------------
void __stdcall Dll4_Run( DLL_SIM_ROBOT4 *sim) {
	//Time count up
	int idt = (int)(sim->dt/0.001);
	gImsec+=idt;

	//[[[ select a test function ]]]
	testMotionDSensor(sim);
	//	testAnalogJoypad(sim);
	//	testCamera(sim);
	//	testTorqueRef(sim);
	//	testZmpCalcInDll(sim);
	return;
}


//-----------------------------------------------------------------------
// Simulation Camera Capture Routine
// 80[ms] sampling
//-----------------------------------------------------------------------
void __stdcall Dll4_Cam(unsigned char *buf, int width, int height, int size ){
	Cam->flg    = 1;
	Cam->width  = width;
	Cam->height = height;
	Cam->size   = size;
	if(Cam->buf!=NULL){
		free(Cam->buf);//clear
		Cam->buf=NULL;
	}
	Cam->buf    = (unsigned char *)malloc( Cam->size );
	memcpy( Cam->buf, buf, Cam->size );
}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//------------------------------------------------------------------
// Sample to move the arms in accordance with analog joypad input.
// [NOTICE] Please PRESS the ANALOG button on the joypad to enable analog input.
//------------------------------------------------------------------
void testAnalogJoypad(DLL_SIM_ROBOT4 *sim){
	wchar_t s[256];

	//Display the status of the analog joypad
	double ana_stick4[4];
	double ana_cross2[2];
	GetAnalogJoypadStatus(ana_stick4, ana_cross2);
	swprintf(s,L"ana   = %lf %lf %lf %lf \n",ana_stick4[0], ana_stick4[1], ana_stick4[2], ana_stick4[3]);
	sim->PrintCommandWindow(s);
	swprintf(s,L"cross = %lf %lf \n",ana_cross2[0], ana_cross2[1]);
	sim->PrintCommandWindow(s);

	//Display the status of the normal joypad
	swprintf(s,L"normal = %d \n",GetNormalJoypadStatus());
	sim->PrintCommandWindow(s);

	//In conjunction with the value of the analog joypad, moving the shoulder.
	double ref17 = ana_stick4[1]*90;
	double ref18 = ana_stick4[3]*90;
	double ref19 = ana_stick4[0]*90;
	double ref20 = ana_stick4[2]*90;
	if(sim->Axis>20){
		sim->ServoRefDeg[17]=ref17;
		sim->ServoRefDeg[18]=ref18;
		sim->ServoRefDeg[19]=ref19;
		sim->ServoRefDeg[20]=ref20;
	}
}

//------------------------------------------------------------------
// Sample using the distance sensor and motion drive
//------------------------------------------------------------------
void testMotionDSensor( DLL_SIM_ROBOT4 *sim){
	wchar_t s[256];

	//Display Body[0]'s position(x,y,z).
	swprintf(s,L"BodyPos[0]=%lf %lf %lf\n",
		sim->BodyPos[0][0],
		sim->BodyPos[0][1],
		sim->BodyPos[0][2]);
	sim->PrintCommandWindow(s);

	//3000msec later, run the motion file 0Walk.rmo
	if(gImsec==3000){
		wcscpy(sim->Command,L"rmo(0Walk)");
	}
	//This rmo command is ignored because the above "0Walk.rmo" is running.
	if(gImsec==3005){
		wcscpy(sim->Command,L"rmo(0TurnRight)");// run motion script file "0Walk.rmo".
	}
	//Move slowly servomotor #17 from 0[deg] to 90[deg].
	static double ref=0;
	if(ref<90.0){
		ref+=0.1;
		if(sim->Axis>17){
			sim->ServoRefDeg[17]=ref;
		}
	}

	//Forward tilt (to make the distance sensors direct to the ground
	static double ref_zenkei=0;
	if(gImsec>10000){
		ref_zenkei+=0.1;
		if(ref_zenkei<30.0){
			if(sim->Axis>6){
				sim->ServoRefDeg[5]=ref_zenkei;//Hip pitch
				sim->ServoRefDeg[6]=ref_zenkei;//Hip pitch
			}
		}
	}

	//Display of the value of the distance sensor.
	{
		std::wstringstream wos;
		wos << L"dsensor ";
		for(int i=0; i<sim->DsensorNum; i++){
			swprintf(s,L"[%d] %lf.3  ", i, sim->DsensorDat[i] );
			wos << s;
		}
		wos << std::endl;
		wstring s=wos.str();
		sim->PrintCommandWindow(s.c_str());
	}

	//Notification termination of the operation of the DLL
	if(gImsec==14000){
		sim->bFinish = true;//DLL finish flag
	}
}

//------------------------------------------------------------------
// Sample to save the pixels data of the camera image
//------------------------------------------------------------------
void testCamera( DLL_SIM_ROBOT4 *sim){
	//Pixel information of the green will be saved to a text file.
	if(Cam!=NULL){
		if(Cam->flg==1){// if camera data is updated
			Cam->flg=0;//clear update flag

			wstring path = wstring(GetRobotFilePath());
			wstring motion_full_path = path + L"Program/cam_test.txt";
			FILE *fp = _wfopen(motion_full_path.c_str(),L"wt");
			if(fp!=NULL){
				// save camera data.
				for(int h=0;h<Cam->height;h++){
					for(int w=0;w<Cam->width;w++){
						int temp_size = Cam->height*Cam->width*3;
						int temp_now  = h*Cam->width*3 + w*3 + 0;
						int r=Cam->buf[ h*Cam->width*3 + w*3 + 0 ];
						int g=Cam->buf[ h*Cam->width*3 + w*3 + 1 ];
						int b=Cam->buf[ h*Cam->width*3 + w*3 + 2 ];
						fprintf(fp,"%X",g/16);
					}
					fprintf(fp,"\n");
				}
				fclose(fp);
			}
		}
	}
}

//------------------------------------------------------------------
// Sample : Torque Control (PD Control)
//------------------------------------------------------------------
void testTorqueRef(DLL_SIM_ROBOT4 *sim){
	if(sim->Axis<=18){
		return;
	}
	int axis;

	//Sholder Pitch Right Joint(ShoP_R) is set as "Hinge Joint" and "Torque Control Motor"
	axis = 17; //ShoP_R
	if(sim->ServoMode[axis]==3)
	{
		//トルク制御モードなら
		static double bx=0;
		static double ref=0;


		//angle ref 0 to 120[deg]
		ref+=0.1;
		if(ref>120){
			ref=120;
		}

		double x = sim->ServoNowDeg[axis];//angle
		double v = (x-bx)/sim->dt;//vel

		//PD Control
		double kp = 0.04;
		double kd = 0.001;
		double f = kp*(ref-x) - kd*v;

		//output torque
		SetRefMotorTorque(axis,f); 

		//message
		wchar_t s[128];
		swprintf(s,L"ang ref=%lf x=%lf\n",ref,x);
		sim->PrintCommandWindow(s);

		bx = x;//back up
	}

	//Sholder Pitch Left Joint(ShoP_L) is set as "Slider Joint" and "Force Control Motor"
	axis = 18; //ShoP_L
	if(sim->ServoMode[axis]==3)
	{
		static double bx=0;
		static double ref=0;

		//position ref 0 to 0.3[m]
		ref+=0.001;
		if(ref>0.3){
			ref=0.3;
		}

		//double f = 0.1;

		double x = sim->ServoNowDeg[axis];//position
		double v = (x-bx)/sim->dt;//vel

		//PD Control
		double kp = 0.8;
		double kd = 0.5;
		double f = kp*(ref-x) - kd*v;

		//output torque
		SetRefMotorTorque(axis,f); 

		//message
		wchar_t s[128];
		swprintf(s,L"pos ref=%lf x=%lf\n",ref,x);
		sim->PrintCommandWindow(s);

		bx = x;//back up
	}

}

// Test : Calculate ZMP In this DLL
// Go Simulation! has the ZMP calculation function,
// it is possible the user calculate zmp by their algorism.
void testZmpCalcInDll(DLL_SIM_ROBOT4 *sim){

	// In GoSimu, ZMP is calulated, and this ZMP value is applied 2nd low-pass-filter(LPF);
	// In this sample, as we want to use ZMP value which is not applied LPF, LPF freq is set to very high(10000Hz).
	double now_freq=GetZmpLpfFreq();
	if(now_freq<10000.0){
		printf("now_freq! = %lf\n",now_freq);
		SetZmpLpfFreq(10000.0);//NO LPF
	}


	wcscpy(sim->Command,L"rmo(0Walk)");
	double posR[3], fR[3],tR[3];
	double posL[3], fL[3],tL[3];

	bool retR = GetForceTorqueSensor_R(posR, fR, tR);
	bool retL = GetForceTorqueSensor_L(posL, fL, tL);
	if(retR==false || retL==false){
		return;
	}

	double dd = 0.04;//distance between ground and senser position.

	//Check of Contact
	//force z(fR[2]) should be minus. If not, a foot does not contact to ground.
	if(fR[2] >= 0 ){
		fR[0] = fR[1] = fR[2]=0;
		tR[0] = tR[1] = tR[2]=0;
	}
	if(fL[2] >= 0 ){
		fL[0] = fL[1] = fL[2]=0;
		tL[0] = tL[1] = tL[2]=0;
	}

	bool Zmp_exist=true;
	if(fR[2] >= 0 && fL[2] >= 0 ){
		Zmp_exist=false;//ZMPが存在しない
	}

	if(Zmp_exist){
		
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
		zmp[0] = numX/denX;
		zmp[1] = numY/denY;
		zmp[2] = 0; //contact point (ground) is z=0;

		//Show in CommandWIndow
		wchar_t s[128];
		swprintf(s,L"zmp gosimu %.3lf %.3lf %.3lf",sim->ZmpPos[0],sim->ZmpPos[1],sim->ZmpPos[2]);
		sim->PrintCommandWindow(s);
		swprintf(s,L" : dll %.3lf %.3lf %.3lf\r\n",zmp[0], zmp[1], zmp[2]);
		sim->PrintCommandWindow(s);
	}


}

