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
    unsigned short uint_OutputState[4];
    unsigned short uint_CMStatus;
    unsigned short uint_BarecodeReadCounter;
    unsigned short uint_DestinationReadCounter;
    unsigned short uint_ConfirmationReadCounter;

    unsigned short uint_ScanNotificationCounter;  // SO1 message for Amazon
    unsigned short uint_BarecodeIdLocationLength;
    char           byte_BarecodeIdLocation[8];
    unsigned short uint_SequentialNumber;
    unsigned short uint_BarecodeLength;
    char           byte_Barecode[28];

    unsigned int   uint_IntraloxSortMsgCounter;  // Sort message for intralox
    unsigned int   uint_IntraloxSortMsgPLCID;
    unsigned int   uint_IntraloxSortMsgBarecodeLength;
    char           byte_IntraloxSortMsgBarecode[28];
    unsigned int   uint_IntraloxSortMsgDestRequested;
    unsigned int   uint_IntraloxSortMsgReason;
    unsigned int   uint_IntraloxSortMsgLength; //in mm

    unsigned short uint_DivertNotificationCounter;  // S04 message for Amazon
    unsigned short uint_DivertSequentialNumber;
    unsigned short uint_DivertBarecodeIdLocationLength;
    unsigned short uint_DivertBarecodeLength;
    char           byte_DivertBarecodeIdLocation[8];
    char           byte_DivertBarecode[28];
    unsigned short uint_DestRequestedLength;
    unsigned short uint_SortedDestLength;
    char           byte_DestRequested[8];
    char           byte_SortedDest[8];
    unsigned short uint_SortedCode;
    unsigned short uint_Spare2;

    unsigned short uint_Cad99AnalogMsgCounter; // Cad99 message for Amazon
    unsigned short uint_DeviceIdLength;
    char           byte_DeviceId[8];
    unsigned short uint_LevelPercent;
    unsigned short uint_InError;
    unsigned short uint_NotInUse;
    unsigned short uint_Spare3;

    unsigned int   uint_IntraloxInterlocksStatus;
    unsigned int   uint_ChuteStatus[50];
};

//StructureArray02 getArray02() {
//
//    StructureArray02 dataArray02;
//
//    dataArray02.ulong_CMAlive = 500;
//    dataArray02.ulong_Mode = 1;
//    dataArray02.ulong_State = 2;
//    dataArray02.ulong_CMStatus = 3;
//
//    unsigned int temp_ulong_OutputState[40] = {
//        50, 48, 50, 49, 45, 48, 56, 45,
//        50, 51, 84, 48, 50, 58, 49, 56,
//        58, 50, 51, 46, 54, 54, 48, 90,
//        50, 51, 84, 48, 50, 58, 49, 56,
//        50, 51, 84, 48, 50, 58, 49, 56
//    };
//    memcpy(dataArray02.ulong_OutputState, temp_ulong_OutputState, sizeof(unsigned int) * 40);
//
//    return dataArray02;
//}
//ostream& operator<<(ostream& os, const StructureArray02 da) {
//    os << "{" << endl;
//    os << " ulong_CMAlive: " << da.ulong_CMAlive << endl;
//    os << " ulong_Mode: " << da.ulong_Mode << endl;
//    os << " ulong_State: " << da.ulong_State << endl;
//    os << " ulong_CMStatus: " << da.ulong_CMStatus << endl;
//
//    os << " ulong_OutputState: ";
//    for (int i = 0; i < 40; i++)
//        printf("%d ", da.ulong_OutputState[i]);
//    os << endl;
//
//    os << "}" << endl;
//    return os;
//}
Local<Object> getObjectFromStructureArray02(Isolate* isolate,Local<Context> context,StructureArray02 array02){
    
    Local<Object> obj = Object::New(isolate);
    obj->Set(context,String::NewFromUtf8(isolate,"uint_CMAlive").ToLocalChecked(),Number::New(isolate, array02.uint_CMAlive));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Mode").ToLocalChecked(),Number::New(isolate, array02.uint_Mode));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_State").ToLocalChecked(),Number::New(isolate, array02.uint_State));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare1").ToLocalChecked(),Number::New(isolate, array02.uint_Spare1));

    Local<Array> uint_OutputState=Array::New(isolate,4);for(int i=0;i<4;i++){uint_OutputState->Set(context,i, Integer::New(isolate,array02.uint_OutputState[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_OutputState").ToLocalChecked(),uint_OutputState);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_CMStatus").ToLocalChecked(),Number::New(isolate, array02.uint_CMStatus));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarecodeReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_BarecodeReadCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DestinationReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_DestinationReadCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_ConfirmationReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_ConfirmationReadCounter));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_ScanNotificationCounter").ToLocalChecked(),Number::New(isolate, array02.uint_ScanNotificationCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarecodeIdLocationLength").ToLocalChecked(),Number::New(isolate, array02.uint_BarecodeIdLocationLength));

    Local<Array> byte_BarecodeIdLocation=Array::New(isolate,8);for(int i=0;i<8;i++){byte_BarecodeIdLocation->Set(context,i, Integer::New(isolate,array02.byte_BarecodeIdLocation[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_BarecodeIdLocation").ToLocalChecked(),byte_BarecodeIdLocation);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_SequentialNumber").ToLocalChecked(),Number::New(isolate, array02.uint_SequentialNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_BarecodeLength));

    Local<Array> byte_Barecode=Array::New(isolate,28);for(int i=0;i<28;i++){byte_Barecode->Set(context,i, Integer::New(isolate,array02.byte_Barecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_Barecode").ToLocalChecked(),byte_Barecode);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgCounter").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgPLCID").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgPLCID));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgBarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgBarecodeLength));

    Local<Array> byte_IntraloxSortMsgBarecode=Array::New(isolate,28);for(int i=0;i<28;i++){byte_IntraloxSortMsgBarecode->Set(context,i, Integer::New(isolate,array02.byte_IntraloxSortMsgBarecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_IntraloxSortMsgBarecode").ToLocalChecked(),byte_IntraloxSortMsgBarecode);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgDestRequested").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgDestRequested));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgReason").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgReason));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgLength").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertNotificationCounter").ToLocalChecked(),Number::New(isolate, array02.uint_DivertNotificationCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertSequentialNumber").ToLocalChecked(),Number::New(isolate, array02.uint_DivertSequentialNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertBarecodeIdLocationLength").ToLocalChecked(),Number::New(isolate, array02.uint_DivertBarecodeIdLocationLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertBarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_DivertBarecodeLength));

    Local<Array> byte_DivertBarecodeIdLocation=Array::New(isolate,8);for(int i=0;i<8;i++){byte_DivertBarecodeIdLocation->Set(context,i, Integer::New(isolate,array02.byte_DivertBarecodeIdLocation[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DivertBarecodeIdLocation").ToLocalChecked(),byte_DivertBarecodeIdLocation);
    Local<Array> byte_DivertBarecode=Array::New(isolate,28);for(int i=0;i<28;i++){byte_DivertBarecode->Set(context,i, Integer::New(isolate,array02.byte_DivertBarecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DivertBarecode").ToLocalChecked(),byte_DivertBarecode);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_DestRequestedLength").ToLocalChecked(),Number::New(isolate, array02.uint_DestRequestedLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_SortedDestLength").ToLocalChecked(),Number::New(isolate, array02.uint_SortedDestLength));

    Local<Array> byte_DestRequested=Array::New(isolate,8);for(int i=0;i<8;i++){byte_DestRequested->Set(context,i, Integer::New(isolate,array02.byte_DestRequested[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DestRequested").ToLocalChecked(),byte_DestRequested);
    Local<Array> byte_SortedDest=Array::New(isolate,8);for(int i=0;i<8;i++){byte_SortedDest->Set(context,i, Integer::New(isolate,array02.byte_SortedDest[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_SortedDest").ToLocalChecked(),byte_SortedDest);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_SortedCode").ToLocalChecked(),Number::New(isolate, array02.uint_SortedCode));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare2").ToLocalChecked(),Number::New(isolate, array02.uint_Spare2));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Cad99AnalogMsgCounter").ToLocalChecked(),Number::New(isolate, array02.uint_Cad99AnalogMsgCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DeviceIdLength").ToLocalChecked(),Number::New(isolate, array02.uint_DeviceIdLength));

    Local<Array> byte_DeviceId=Array::New(isolate,8);for(int i=0;i<8;i++){byte_DeviceId->Set(context,i, Integer::New(isolate,array02.byte_DeviceId[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DeviceId").ToLocalChecked(),byte_DeviceId);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_LevelPercent").ToLocalChecked(),Number::New(isolate, array02.uint_LevelPercent));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_InError").ToLocalChecked(),Number::New(isolate, array02.uint_InError));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_NotInUse").ToLocalChecked(),Number::New(isolate, array02.uint_NotInUse));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_Spare3").ToLocalChecked(),Number::New(isolate, array02.uint_Spare3));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxInterlocksStatus").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxInterlocksStatus));
    Local<Array> uint_ChuteStatus=Array::New(isolate,50);for(int i=0;i<50;i++){uint_ChuteStatus->Set(context,i, Integer::New(isolate,array02.uint_ChuteStatus[i]));}obj->Set(context,String::NewFromUtf8(isolate,"uint_ChuteStatus").ToLocalChecked(),uint_ChuteStatus);

    return obj;
}
