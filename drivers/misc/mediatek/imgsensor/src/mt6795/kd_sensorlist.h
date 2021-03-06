//s_add new sensor driver here
//export funtions
/*S5K*/
UINT32 S5K3M2_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 S5K3M2_2ND_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
/*OV*/
UINT32 OV5670_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 OV5670_2ND_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 OV5670_FLT_2ND_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);

//! Add Sensor Init function here
//! Note:
//! 1. Add by the resolution from ""large to small"", due to large sensor
//!    will be possible to be main sensor.
//!    This can avoid I2C error during searching sensor.
//! 2. This file should be the same as mediatek\custom\common\hal\imgsensor\src\sensorlist.cpp
ACDK_KD_SENSOR_INIT_FUNCTION_STRUCT kdSensorList[MAX_NUM_OF_SUPPORT_SENSOR+1] =
{
/*S5K*/
#if defined(S5K3M2_MIPI_RAW)
    {S5K3M2_MIPI_RAW_SENSOR_ID, SENSOR_DRVNAME_S5K3M2_MIPI_RAW, S5K3M2_MIPI_RAW_SensorInit},
#endif
#if defined(S5K3M2_2ND_MIPI_RAW)
    {S5K3M2_2ND_MIPI_RAW_SENSOR_ID, SENSOR_DRVNAME_S5K3M2_2ND_MIPI_RAW, S5K3M2_2ND_MIPI_RAW_SensorInit},
#endif
/*OV (OmniVision)*/
#if defined(OV5670_MIPI_RAW)
    {OV5670_MIPI_RAW_SENSOR_ID, SENSOR_DRVNAME_OV5670_MIPI_RAW, OV5670_MIPI_RAW_SensorInit},
#endif
#if defined(OV5670_2ND_MIPI_RAW)
    {OV5670_2ND_MIPI_RAW_SENSOR_ID, SENSOR_DRVNAME_OV5670_2ND_MIPI_RAW, OV5670_2ND_MIPI_RAW_SensorInit},
#endif
#if defined(OV5670_FLT_2ND_MIPI_RAW)
    {OV5670_FLT_2ND_MIPI_RAW_SENSOR_ID, SENSOR_DRVNAME_OV5670_FLT_2ND_MIPI_RAW, OV5670_FLT_2ND_MIPI_RAW_SensorInit},
#endif
/*  ADD sensor driver before this line */
    {0,{0},NULL}, //end of list
};
//e_add new sensor driver here
