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
    unsigned short uint_OutputState[4]; //0:DO   1:DO   2:Enable drive b0 to b4
    unsigned short uint_MotorSpeed[2];//6
    unsigned short uint_CMStatus;
    unsigned short uint_BarecodeReadCounter;
    unsigned short uint_DestinationReadCounter;
    unsigned short uint_ConfirmationReadCounter;

    unsigned short uint_ScanNotificationCounter;  // SO1 message for Amazon
    unsigned short uint_BarecodeIdLocationLength;
    char           byte_BarecodeIdLocation[4];//8
    unsigned short uint_SequentialNumber;
    unsigned short uint_BarecodeLength;
    char           byte_Barecode[4];//28

    unsigned short uint_IntraloxSortMsgCounter;  // Sort message for intralox
    unsigned short uint_Spare0;
    unsigned int   uint_IntraloxSortMsgPLCID;
    unsigned int   uint_IntraloxSortMsgBarecodeLength;
    char           byte_IntraloxSortMsgBarecode[4];//28
    unsigned int   uint_IntraloxSortMsgDestRequested;
    unsigned int   uint_IntraloxSortMsgReason;
    unsigned int   uint_IntraloxSortMsgLength; //in mm

    unsigned short uint_DivertNotificationCounter;  // S04 message for Amazon
    unsigned short uint_DivertSequentialNumber;
    unsigned short uint_DivertBarecodeIdLocationLength;
    unsigned short uint_DivertBarecodeLength;
    char           byte_DivertBarecodeIdLocation[4];//8
    char           byte_DivertBarecode[4];//28
    unsigned short uint_DestRequestedLength;
    unsigned short uint_SortedDestLength;
    char           byte_DestRequested[4];//8
    char           byte_SortedDest[4];//8
    unsigned short uint_SortedCode;
    unsigned short uint_Spare2;

    unsigned short uint_Cad99AnalogMsgCounter; // Cad99 message for Amazon
    unsigned short uint_DeviceIdLength;
    char           byte_DeviceId[8];
    unsigned short uint_LevelPercent;
    unsigned short uint_InError;
    unsigned short uint_NotInUse;
    unsigned short uint_Spare3;

    // Data for the measuring points
    unsigned short uint_IncMPCountMsgCounter;  // Message to increase the Counter of a MP
    unsigned short uint_MPId;

    unsigned short uint_MPState[26];
    unsigned short uint_MPError[26]; // b0:Estop b1:Modbus comm err b2:Motor Fault b3:Jam Detection b4:Divert/Rat/Mabs Fault
    //unsigned int   uint_IntraloxInterlocksStatus;  //
    //unsigned char  uint_ChuteStatus[50];
    int uint_HMI_Alarms[12];
    int uint_HMI_Jams[12];
    unsigned int udint_InputsBoardIndex;
    short int uint_InputsState[24];
    char m_ucConvState[60];
};

StructureArray02 getArray02() {

    StructureArray02 dataArray02 = {
        1,2,3,4,{1,2,3,4},{1,2},7,8,9,10
        ,1,2,{1,2,3,4},4,5,{1,2,3,4}
        ,1,2,3,4,{1,2,3,4},6,7,8
        ,1,2,3,4,{1,2,3,4},{1,2,3,4},7,8,{1,2,3,4},{1,2,3,4},1,2
        ,1,2,{1,2,3,4,5,6,7,8},4,5,6,7
        ,1,2
        ,{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6},{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6},{1,2,3,4,5,6,7,8,9,0,1,2},{1,2,3,4,5,6,7,8,9,0,1,2}
        ,1,{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4},{1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,20,1,2,3,4,5,6,7,8,9,30,1,2,3,4,5,6,7,8,9,40,1,2,3,4,5,6,7,8,9,50,1,2,3,4,5,6,7,8,9,60}
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
    Local<Array> uint_MotorSpeed=Array::New(isolate,2);for(int i=0;i<2;i++){uint_MotorSpeed->Set(context,i, Integer::New(isolate,array02.uint_MotorSpeed[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_MotorSpeed").ToLocalChecked(),uint_MotorSpeed);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_CMStatus").ToLocalChecked(),Number::New(isolate, array02.uint_CMStatus));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarecodeReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_BarecodeReadCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DestinationReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_DestinationReadCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_ConfirmationReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_ConfirmationReadCounter));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_ScanNotificationCounter").ToLocalChecked(),Number::New(isolate, array02.uint_ScanNotificationCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarecodeIdLocationLength").ToLocalChecked(),Number::New(isolate, array02.uint_BarecodeIdLocationLength));
    Local<Array> byte_BarecodeIdLocation=Array::New(isolate,4);for(int i=0;i<4;i++){byte_BarecodeIdLocation->Set(context,i, Integer::New(isolate,array02.byte_BarecodeIdLocation[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_BarecodeIdLocation").ToLocalChecked(),byte_BarecodeIdLocation);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_SequentialNumber").ToLocalChecked(),Number::New(isolate, array02.uint_SequentialNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_BarecodeLength));
    Local<Array> byte_Barecode=Array::New(isolate,4);for(int i=0;i<4;i++){byte_Barecode->Set(context,i, Integer::New(isolate,array02.byte_Barecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_Barecode").ToLocalChecked(),byte_Barecode);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgCounter").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare0").ToLocalChecked(),Number::New(isolate, array02.uint_Spare0));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgPLCID").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgPLCID));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgBarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgBarecodeLength));
    Local<Array> byte_IntraloxSortMsgBarecode=Array::New(isolate,4);for(int i=0;i<4;i++){byte_IntraloxSortMsgBarecode->Set(context,i, Integer::New(isolate,array02.byte_IntraloxSortMsgBarecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_IntraloxSortMsgBarecode").ToLocalChecked(),byte_IntraloxSortMsgBarecode);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgDestRequested").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgDestRequested));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgReason").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgReason));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgLength").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgLength));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertNotificationCounter").ToLocalChecked(),Number::New(isolate, array02.uint_DivertNotificationCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertSequentialNumber").ToLocalChecked(),Number::New(isolate, array02.uint_DivertSequentialNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertBarecodeIdLocationLength").ToLocalChecked(),Number::New(isolate, array02.uint_DivertBarecodeIdLocationLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertBarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_DivertBarecodeLength));
    Local<Array> byte_DivertBarecodeIdLocation=Array::New(isolate,4);for(int i=0;i<4;i++){byte_DivertBarecodeIdLocation->Set(context,i, Integer::New(isolate,array02.byte_DivertBarecodeIdLocation[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DivertBarecodeIdLocation").ToLocalChecked(),byte_DivertBarecodeIdLocation);
    Local<Array> byte_DivertBarecode=Array::New(isolate,4);for(int i=0;i<4;i++){byte_DivertBarecode->Set(context,i, Integer::New(isolate,array02.byte_DivertBarecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DivertBarecode").ToLocalChecked(),byte_DivertBarecode);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DestRequestedLength").ToLocalChecked(),Number::New(isolate, array02.uint_DestRequestedLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_SortedDestLength").ToLocalChecked(),Number::New(isolate, array02.uint_SortedDestLength));
    Local<Array> byte_DestRequested=Array::New(isolate,4);for(int i=0;i<4;i++){byte_DestRequested->Set(context,i, Integer::New(isolate,array02.byte_DestRequested[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DestRequested").ToLocalChecked(),byte_DestRequested);
    Local<Array> byte_SortedDest=Array::New(isolate,4);for(int i=0;i<4;i++){byte_SortedDest->Set(context,i, Integer::New(isolate,array02.byte_SortedDest[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_SortedDest").ToLocalChecked(),byte_SortedDest);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_SortedCode").ToLocalChecked(),Number::New(isolate, array02.uint_SortedCode));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare2").ToLocalChecked(),Number::New(isolate, array02.uint_Spare2));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_Cad99AnalogMsgCounter").ToLocalChecked(),Number::New(isolate, array02.uint_Cad99AnalogMsgCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DeviceIdLength").ToLocalChecked(),Number::New(isolate, array02.uint_DeviceIdLength));
    Local<Array> byte_DeviceId=Array::New(isolate,8);for(int i=0;i<8;i++){byte_DeviceId->Set(context,i, Integer::New(isolate,array02.byte_DeviceId[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DeviceId").ToLocalChecked(),byte_DeviceId);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_LevelPercent").ToLocalChecked(),Number::New(isolate, array02.uint_LevelPercent));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_InError").ToLocalChecked(),Number::New(isolate, array02.uint_InError));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_NotInUse").ToLocalChecked(),Number::New(isolate, array02.uint_NotInUse));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare3").ToLocalChecked(),Number::New(isolate, array02.uint_Spare3));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IncMPCountMsgCounter").ToLocalChecked(),Number::New(isolate, array02.uint_IncMPCountMsgCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_MPId").ToLocalChecked(),Number::New(isolate, array02.uint_MPId));


    Local<Array> uint_MPState=Array::New(isolate,26);for(int i=0;i<26;i++){uint_MPState->Set(context,i, Integer::New(isolate,array02.uint_MPState[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_MPState").ToLocalChecked(),uint_MPState);
    Local<Array> uint_MPError=Array::New(isolate,26);for(int i=0;i<26;i++){uint_MPError->Set(context,i, Integer::New(isolate,array02.uint_MPError[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_MPError").ToLocalChecked(),uint_MPError);
    Local<Array> uint_HMI_Alarms=Array::New(isolate,12);for(int i=0;i<12;i++){uint_HMI_Alarms->Set(context,i, Integer::New(isolate,array02.uint_HMI_Alarms[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_HMI_Alarms").ToLocalChecked(),uint_HMI_Alarms);
    Local<Array> uint_HMI_Jams=Array::New(isolate,12);for(int i=0;i<12;i++){uint_HMI_Jams->Set(context,i, Integer::New(isolate,array02.uint_HMI_Jams[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_HMI_Jams").ToLocalChecked(),uint_HMI_Jams);

    obj->Set(context,String::NewFromUtf8(isolate,"udint_InputsBoardIndex").ToLocalChecked(),Number::New(isolate, array02.udint_InputsBoardIndex));
    Local<Array> uint_InputsState=Array::New(isolate,24);for(int i=0;i<24;i++){uint_InputsState->Set(context,i, Integer::New(isolate,array02.uint_InputsState[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_InputsState").ToLocalChecked(),uint_InputsState);
    Local<Array> m_ucConvState=Array::New(isolate,60);for(int i=0;i<60;i++){m_ucConvState->Set(context,i, Integer::New(isolate,array02.m_ucConvState[i]));}obj->Set(context,String::NewFromUtf8(isolate,"m_ucConvState").ToLocalChecked(),m_ucConvState);


    return obj;
}
