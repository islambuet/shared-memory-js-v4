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
    unsigned short uint_MotorSpeed[6];//added
    unsigned short uint_CMStatus;
    unsigned short uint_BarcodeReadCounter;
    unsigned short uint_DestinationReadCounter;
    unsigned short uint_ConfirmationReadCounter;

    unsigned short uint_ScanNotificationCounter;  // SO1 message for Amazon
    unsigned short uint_BarcodeIdLocationLength;
    char           byte_BarcodeIdLocation[8];
    unsigned short uint_SequentialNumber;
    unsigned short uint_BarcodeLength;
    char           byte_Barcode[28];

    unsigned int   uint_IntraloxSortMsgCounter;  // Sort message for intralox
    unsigned int   uint_IntraloxSortMsgPLCID;
    unsigned int   uint_IntraloxSortMsgBarecodeLength;
    char           byte_IntraloxSortMsgBarecode[28];
    unsigned int   uint_IntraloxSortMsgDestRequested;
    unsigned int   uint_IntraloxSortMsgReason;
    unsigned int   uint_IntraloxSortMsgLength; //in mm

    unsigned short uint_DivertNotificationCounter;  // S04 message for Amazon
    unsigned short uint_DivertSequentialNumber;
    unsigned short uint_DivertBarcodeIdLocationLength;
    unsigned short uint_DivertBarcodeLength;
    char           byte_DivertBarcodeIdLocation[8];
    char           byte_DivertBarcode[28];
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
    char   uint_ChuteStatus[50];//changed

};

StructureArray02 getArray02() {

    StructureArray02 dataArray02 = {
        1,2,3,4,{1,2,3,4},{1,2,3,4,5,6},1,2,3,4
        ,1,2,{1,2,3,4,5,6,7,8},1,2,{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8}
        ,1,2,3,{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8},1,2,3
        ,1,2,3,4,{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8},1,2,{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},1,2
        ,1,2,{1,2,3,4,5,6,7,8},1,2,3,4
        ,1,{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0}
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
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarcodeReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_BarcodeReadCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DestinationReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_DestinationReadCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_ConfirmationReadCounter").ToLocalChecked(),Number::New(isolate, array02.uint_ConfirmationReadCounter));

    obj->Set(context,String::NewFromUtf8(isolate,"uint_ScanNotificationCounter").ToLocalChecked(),Number::New(isolate, array02.uint_ScanNotificationCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarcodeIdLocationLength").ToLocalChecked(),Number::New(isolate, array02.uint_BarcodeIdLocationLength));

    Local<Array> byte_BarcodeIdLocation=Array::New(isolate,8);for(int i=0;i<8;i++){byte_BarcodeIdLocation->Set(context,i, Integer::New(isolate,array02.byte_BarcodeIdLocation[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_BarcodeIdLocation").ToLocalChecked(),byte_BarcodeIdLocation);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_SequentialNumber").ToLocalChecked(),Number::New(isolate, array02.uint_SequentialNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_BarcodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_BarcodeLength));

    Local<Array> byte_Barcode=Array::New(isolate,28);for(int i=0;i<28;i++){byte_Barcode->Set(context,i, Integer::New(isolate,array02.byte_Barcode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_Barcode").ToLocalChecked(),byte_Barcode);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgCounter").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgPLCID").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgPLCID));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgBarecodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgBarecodeLength));

    Local<Array> byte_IntraloxSortMsgBarecode=Array::New(isolate,28);for(int i=0;i<28;i++){byte_IntraloxSortMsgBarecode->Set(context,i, Integer::New(isolate,array02.byte_IntraloxSortMsgBarecode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_IntraloxSortMsgBarecode").ToLocalChecked(),byte_IntraloxSortMsgBarecode);

    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgDestRequested").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgDestRequested));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgReason").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgReason));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_IntraloxSortMsgLength").ToLocalChecked(),Number::New(isolate, array02.uint_IntraloxSortMsgLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertNotificationCounter").ToLocalChecked(),Number::New(isolate, array02.uint_DivertNotificationCounter));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertSequentialNumber").ToLocalChecked(),Number::New(isolate, array02.uint_DivertSequentialNumber));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertBarcodeIdLocationLength").ToLocalChecked(),Number::New(isolate, array02.uint_DivertBarcodeIdLocationLength));
    obj->Set(context,String::NewFromUtf8(isolate,"uint_DivertBarcodeLength").ToLocalChecked(),Number::New(isolate, array02.uint_DivertBarcodeLength));

    Local<Array> byte_DivertBarcodeIdLocation=Array::New(isolate,8);for(int i=0;i<8;i++){byte_DivertBarcodeIdLocation->Set(context,i, Integer::New(isolate,array02.byte_DivertBarcodeIdLocation[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DivertBarcodeIdLocation").ToLocalChecked(),byte_DivertBarcodeIdLocation);
    Local<Array> byte_DivertBarcode=Array::New(isolate,28);for(int i=0;i<28;i++){byte_DivertBarcode->Set(context,i, Integer::New(isolate,array02.byte_DivertBarcode[i]));}obj->Set(context,String::NewFromUtf8(isolate,"byte_DivertBarcode").ToLocalChecked(),byte_DivertBarcode);

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
