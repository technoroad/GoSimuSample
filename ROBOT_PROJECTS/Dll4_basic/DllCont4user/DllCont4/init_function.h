//[Do NOT CHAGE]

extern PF_ResetRobot             ResetRobot;
extern PF_GetRobotFilePath       GetRobotFilePath;

extern PF_GetAnalogJoypadStatus  GetAnalogJoypadStatus;
extern PF_GetNormalJoypadStatus  GetNormalJoypadStatus;

extern PF_SetRefMotorTorque      SetRefMotorTorque;

extern PF_GetBodyPos             GetBodyPos;
extern PF_GetBodyRot             GetBodyRot;

extern PF_GetForceTorqueSensor_R GetForceTorqueSensor_R;
extern PF_GetForceTorqueSensor_L GetForceTorqueSensor_L;
extern PF_GetZmpLpfFreq          GetZmpLpfFreq;
extern PF_SetZmpLpfFreq          SetZmpLpfFreq;

extern PF_GetGyroRad             GetGyroRad;
extern PF_GetZmpPos              GetZmpPos;
extern PF_GetCgPos               GetCgPos;

bool InitFunctions(DLL_SIM_ROBOT4 *sim);

