//[Do NOT CHAGE]

#pragma once
#define DLL_CONT_VERSION (0x005)

#include <string>
#include <windows.h>
using namespace std;



//------------------------------------------------------------------------------------
// Robot Control Data
// <r> read, <w> write, <rw> both
typedef struct{
	bool   bFinish;         //<w>if this value is set "true", dll program is finished.
	bool   bCaptureEna;     //<->Camera data captured flag.(not used)

	int    Axis;            //<r>The numbers of joint axes.
	int    *ServoMode;      //<rw>Servo motor mode (1:Position Control, 2:Velocity Control, 3:Torque Control)
	int    DsensorNum;      //<r>Ther numbers of distance sensors

	wchar_t *Command;       //<w>Motion script command. Memory is allocated in GOSIMULATION.exe .

	double dt;              //<r>Sampling time dt[s]. 

	double *ServoRefDeg;    //<rw>Servo motor Ref angle[deg]
	double *ServoNowDeg;    //<r>Servo motor Now angle[deg](potentio meter)
	double *ServoRefOmgDeg; //<rw>Servo motor Ref angluar verocity [deg/s]
	double *ServoSpeed;     //<rw>Servo motor control gain(P gain)
	double *ServoKp;        //<rw>Servo motor control gain(spring constant)
	double *ServoKd;        //<rw>Servo motor control gain(dumer)

	double *DsensorDat;     //<r>Distance sensor data.[m]

	bool ZmpRFootTouch;     //<r>The flag with which the right foot contacted a ground.
	bool ZmpLFootTouch;     //<r>The flag with which the right foot contacted a ground. 

	double toSimuLink50[50];//<w>The data transferd to Simulink. User area. The data size is fixed to 50.

	// ----- Function Pointer -----
	// Get DLL version which Go Simulation! requires.
	int(*GetDllVersion)();

	// Print text to Go Simulation's command window.
	void(*PrintCommandWindow)(const wchar_t *msg);

	//Get Function (ver 4)
	DWORD(*GetFunc)(char *func_name);

}DLL_SIM_ROBOT4;

//------------------------------------------------------------------------------------
//function pointer (ver 4)
typedef void(*PF_ResetRobot)(void);
typedef const wchar_t * (*PF_GetRobotFilePath)(void);

typedef void(*PF_GetAnalogJoypadStatus)(double stick[4], double cross[2]);
typedef int(*PF_GetNormalJoypadStatus)(void);

typedef void(*PF_SetRefMotorTorque)(int id, double torque);

typedef void(*PF_GetBodyPos)(double ret_pos[3], int id);
typedef void(*PF_GetBodyRot)(double ret_R[12], int id);

typedef bool(*PF_GetForceTorqueSensor_R)(double position[3], double force[3], double torque[3]);
typedef bool(*PF_GetForceTorqueSensor_L)(double position[3], double force[3], double torque[3]);
typedef double(*PF_GetZmpLpfFreq)(void);
typedef void(*PF_SetZmpLpfFreq)(double freq_hz);

typedef void(*PF_GetGyroRad)(double ret[3]);
typedef void(*PF_GetZmpPos)(double ret[3]);
typedef void(*PF_GetCgPos)(double ret[3]);


//------------------------------------------------------------------------------------
// Camera Data
class DLL_SIM_CAMERA{
public:
	int flg;               //Camera data captured flag.(not used) 1:data updated  0:old data
	int width;             //Camera width [pix]
	int height;            //Camera height [pix]
	int size;              //Camera data buffer size. i.e. 3*width*height.   3=RGB
	unsigned char *buf;    //Camera buffer.
	DLL_SIM_CAMERA(){
		flg=0;
		buf=NULL;
	}
	~DLL_SIM_CAMERA(){
		if (buf != NULL){
			free(buf);
			buf=NULL;
		}
	}
};

//------------------------------------------------------------------------------------
