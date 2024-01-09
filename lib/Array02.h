#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
using namespace v8;
struct StructureArray02
{
    unsigned short uint_CMAlive;
    unsigned short uint_Mode;
    unsigned short uint_State;
    unsigned short uint_Spare1;
    unsigned short uint_OutputState[4];// 0:DO   1 : DO   2 : Enable drive b0 to b4
    unsigned short uint_MotorSpeed[6];
    unsigned short uint_CMStatus;
    //unsigned int   uint_MHE_ComData[10];
    unsigned int   uint_MHE_ComData_Control;  // uint_MHE_ComData[0]
    unsigned short uint_MHE_ComData_Mode;     // uint_MHE_ComData[4].0_15
    unsigned short uint_MHE_ComData_Fault;    // uint_MHE_ComData[4].16_31
    unsigned int   uint_MHE_ComData_Clear;    // uint_MHE_ComData[9].0

    //unsigned int   uint_MHE_Id[20];
    unsigned short uint_MHE_IdData_Align;       // uint_MHE_Id[0].0_15
    unsigned short uint_MHE_IdData_PassNumber;  // uint_MHE_Id[0].16_31
    unsigned int   uint_MHE_IdData_Vid_num1_8;  // uint_MHE_Id[1]
    unsigned int   uint_MHE_IdData_Vid_num9_16; // uint_MHE_Id[2]
    char           byte_MHE_IdData_PieceBcr[40];// uint_MHE_Id[3]-[12]
    unsigned int   uint_MHE_IdData_GlobalId;    // uint_MHE_Id[13]
    unsigned int   uint_MHE_IdData_PrjSpec;     // uint_MHE_Id[14]
    unsigned short uint_MHE_IdData_SecurityRoutineCode;       // uint_MHE_Id[15].0_15
    unsigned short uint_MHE_IdData_DynamicScreeningAlgo;  // uint_MHE_Id[15].16_31
    unsigned int   uint_MHE_IdData_TsSSMMHHDD;  // uint_MHE_Id[16]
    unsigned int   uint_MHE_IdData_TsMM__YYYY;  // uint_MHE_Id[17]

    //      unsigned short uint_BarecodeReadCounter;
    //      unsigned short uint_DestinationReadCounter;
    //      unsigned short uint_ConfirmationReadCounter;

    //      unsigned short uint_ScanNotificationCounter;  // SO1 message for Amazon
    //      unsigned short uint_BarecodeIdLocationLength;
    //      char           byte_BarecodeIdLocation[8];
    //      unsigned short uint_SequentialNumber;
    //      unsigned short uint_BarecodeLength;
    //      char           byte_Barecode[28];

    //      unsigned int   uint_IntraloxSortMsgCounter;  // Sort message for intralox
    //      unsigned int   uint_IntraloxSortMsgPLCID;
    //      unsigned int   uint_IntraloxSortMsgBarecodeLength;
    //      char           byte_IntraloxSortMsgBarecode[28];
    //      unsigned int   uint_IntraloxSortMsgDestRequested;
    //      unsigned int   uint_IntraloxSortMsgReason;
    //      unsigned int   uint_IntraloxSortMsgLength; //in mm

    //      unsigned short uint_DivertNotificationCounter;  // S04 message for Amazon
    //      unsigned short uint_DivertSequentialNumber;
    //      unsigned short uint_DivertBarecodeIdLocationLength;
    //      unsigned short uint_DivertBarecodeLength;
    //      char           byte_DivertBarecodeIdLocation[8];
    //      char           byte_DivertBarecode[28];
    //      unsigned short uint_DestRequestedLength;
    //      unsigned short uint_SortedDestLength;
    //      char           byte_DestRequested[8];
    //      char           byte_SortedDest[8];
    //      unsigned short uint_SortedCode;
    //      unsigned short uint_Spare2;

    //      unsigned short uint_Cad99AnalogMsgCounter; // Cad99 message for Amazon
    //      unsigned short uint_DeviceIdLength;
    //      char           byte_DeviceId[8];
    //      unsigned short uint_LevelPercent;
    //      unsigned short uint_InError;
    //      unsigned short uint_NotInUse;
    //      unsigned short uint_Spare3;

    //      unsigned int   uint_IntraloxInterlocksStatus;
    //      unsigned char  uint_ChuteStatus[50];

    /*      unsigned short uint_Error[8];
          unsigned short uint_Jam[8];
          unsigned short uint_ConfirmationPeBlocked[2];
          unsigned short uint_BinPartiallyFull[2];
          unsigned short uint_BinFull[2];
          unsigned short uint_BinDisabled[2];
          unsigned short uint_BinManualMode[2];
          unsigned short uint_ConveyorState[6];*/
};

StructureArray02 getArray02() {

    StructureArray02 dataArray02 = {
        1,2,3,4,{1,2,3,4},{1,2,3,4,5,6},1,2,3,4,5
        ,1,2,3,4,{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0},1,2,3,4,5,6
    };
    return dataArray02;
}

Local<Object> getObjectFromStructureArray02(Isolate* isolate,Local<Context> context,StructureArray02 array02){
    
    Local<Object> obj = Object::New(isolate);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_CMAlive").ToLocalChecked(),Number::New(isolate, array02.uint_CMAlive));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Mode").ToLocalChecked(),Number::New(isolate, array02.uint_Mode));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_State").ToLocalChecked(),Number::New(isolate, array02.uint_State));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare1").ToLocalChecked(),Number::New(isolate, array02.uint_Spare1));

    Local<Array> uint_OutputState=Array::New(isolate,4);for(int i=0;i<4;i++){uint_OutputState->Set(context,i, Integer::New(isolate,array02.uint_OutputState[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_OutputState").ToLocalChecked(),uint_OutputState);
    Local<Array> uint_MotorSpeed=Array::New(isolate,6);for(int i=0;i<6;i++){uint_MotorSpeed->Set(context,i, Integer::New(isolate,array02.uint_MotorSpeed[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_MotorSpeed").ToLocalChecked(),uint_MotorSpeed);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_CMStatus").ToLocalChecked(),Number::New(isolate, array02.uint_CMStatus));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_ComData_Control").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_ComData_Control));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_ComData_Mode").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_ComData_Mode));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_ComData_Fault").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_ComData_Fault));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_ComData_Clear").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_ComData_Clear));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_Align").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_Align));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_PassNumber").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_PassNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_Vid_num1_8").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_Vid_num1_8));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_Vid_num9_16").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_Vid_num9_16));

    Local<Array> byte_MHE_IdData_PieceBcr=Array::New(isolate,40);for(int i=0;i<40;i++){byte_MHE_IdData_PieceBcr->Set(context,i, Integer::New(isolate,array02.byte_MHE_IdData_PieceBcr[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_MHE_IdData_PieceBcr").ToLocalChecked(),byte_MHE_IdData_PieceBcr);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_GlobalId").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_GlobalId));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_PrjSpec").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_PrjSpec));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_SecurityRoutineCode").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_SecurityRoutineCode));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_DynamicScreeningAlgo").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_DynamicScreeningAlgo));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_TsSSMMHHDD").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_TsSSMMHHDD));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MHE_IdData_TsMM__YYYY").ToLocalChecked(),Number::New(isolate, array02.uint_MHE_IdData_TsMM__YYYY));

    return obj;
}
