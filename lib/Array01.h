#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
using namespace v8;
struct StructureArray01
{
    unsigned int ulong_msCounter;
    unsigned int ulong_SorterEncoder;
    unsigned int ulong_SorterEncoder2;
    unsigned int ulong_SorterEncoder3;
    unsigned int uint_PLCStatus;

    unsigned short uint_Data[4];
    unsigned short uint_BarcodeCounter;
    unsigned short uint_BarecodeMsgLength;
    char           byte_BarecodeMsg[64];

    unsigned short uint_DestinationCounter;
    unsigned short uint_DestinationSequentialNumber;
    unsigned short uint_DestinationCounterLength;
    unsigned short uint_spare1;
    char           byte_Destination[8];
    unsigned short uint_AlternateDestinationLength;
    unsigned short uint_spare2;
    char           byte_AlternateDestination[8];

    unsigned short uint_ConfirmationCounter;
    unsigned short uint_ConfirmationSequentialNumber;
    unsigned short uint_ConfirmationDestination;
    unsigned short uint_spare3;

    unsigned short uint_ScanNotificationReadCounter;
    unsigned short uint_IntraloxSortMsgReadCounter;
    unsigned short uint_DivertNotificationReadCounter;
    unsigned short uint_Cad99AnalogMsgReadCounter;

    unsigned short uint_DeviceConnected[4];
    unsigned int   uint_IntraloxStatusStatus[3];
    unsigned int   uint_ChuteStatus[50];

};
//
//StructureArray01 getArray01() {
//
//    StructureArray01 dataArray01;
//
//    dataArray01.ulong_msCounter = 34320540;
//    dataArray01.ulong_Encoder = 1;
//    dataArray01.ulong_Encoder2 = 2;
//    dataArray01.ulong_Encoder3 = 3;
//    dataArray01.ulong_PLCStatus = 4;
//
//    unsigned int temp_ulong_Data[40] = {
//        5, 6, 7, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 8, 9, 10
//    };
//    memcpy(dataArray01.ulong_Data, temp_ulong_Data, sizeof(unsigned int) * 40);
//
//    unsigned int temp_ulong_DeviceConnected[2] = {
//        11, 12
//    };
//    memcpy(dataArray01.ulong_DeviceConnected, temp_ulong_DeviceConnected, sizeof(unsigned int) * 2);
//    return dataArray01;
//
//
//}
//ostream& operator<<(ostream& os, const StructureArray01 da) {
//    os << "{" << endl;
//    os << " ulong_msCounter: " << da.ulong_msCounter << endl;
//    os << " ulong_Encoder: " << da.ulong_Encoder << endl;
//    os << " ulong_Encoder2: " << da.ulong_Encoder2 << endl;
//    os << " ulong_Encoder3: " << da.ulong_Encoder3 << endl;
//    os << " ulong_PLCStatus: " << da.ulong_PLCStatus << endl;
//    os  <<  "ulong_Data: ";
//    for (int i = 0; i < 40; i++)
//        printf("%d ", da.ulong_Data[i]);
//    os << endl;
//    os  <<  "ulong_DeviceConnected: ";
//    for (int i = 0; i < 2; i++)
//        printf("%d ", da.ulong_DeviceConnected[i]);
//    os << endl;
//    os << "}" << endl;
//    return os;
//}
StructureArray01 getStructureArray01FromObject(Isolate* isolate,Local<Context> context,Local<Object> obj){
    StructureArray01 array_01;
    array_01.ulong_msCounter=obj->Get(context, String::NewFromUtf8(isolate,"ulong_msCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_SorterEncoder=obj->Get(context, String::NewFromUtf8(isolate,"ulong_SorterEncoder").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_SorterEncoder2=obj->Get(context, String::NewFromUtf8(isolate,"ulong_SorterEncoder2").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_SorterEncoder3=obj->Get(context, String::NewFromUtf8(isolate,"ulong_SorterEncoder3").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_PLCStatus=obj->Get(context, String::NewFromUtf8(isolate,"uint_PLCStatus").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    Local<Array> uint_Data=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"uint_Data").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<4;i++){
        array_01.uint_Data[i]=uint_Data->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    array_01.uint_BarcodeCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_BarcodeCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_BarecodeMsgLength=obj->Get(context, String::NewFromUtf8(isolate,"uint_BarecodeMsgLength").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    Local<Array> byte_BarecodeMsg=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"byte_BarecodeMsg").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<64;i++){
        array_01.byte_BarecodeMsg[i]=byte_BarecodeMsg->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    array_01.uint_DestinationCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_DestinationCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_DestinationSequentialNumber=obj->Get(context, String::NewFromUtf8(isolate,"uint_DestinationSequentialNumber").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_DestinationCounterLength=obj->Get(context, String::NewFromUtf8(isolate,"uint_DestinationCounterLength").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_spare1=obj->Get(context, String::NewFromUtf8(isolate,"uint_spare1").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    Local<Array> byte_Destination=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"byte_Destination").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<8;i++){
        array_01.byte_Destination[i]=byte_Destination->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    array_01.uint_AlternateDestinationLength=obj->Get(context, String::NewFromUtf8(isolate,"uint_AlternateDestinationLength").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_spare2=obj->Get(context, String::NewFromUtf8(isolate,"uint_spare2").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    Local<Array> byte_AlternateDestination=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"byte_AlternateDestination").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<8;i++){
        array_01.byte_AlternateDestination[i]=byte_AlternateDestination->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    array_01.uint_ConfirmationCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_ConfirmationCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_ConfirmationSequentialNumber=obj->Get(context, String::NewFromUtf8(isolate,"uint_ConfirmationSequentialNumber").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_ConfirmationDestination=obj->Get(context, String::NewFromUtf8(isolate,"uint_ConfirmationDestination").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_spare3=obj->Get(context, String::NewFromUtf8(isolate,"uint_spare3").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    array_01.uint_ScanNotificationReadCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_ScanNotificationReadCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_IntraloxSortMsgReadCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_IntraloxSortMsgReadCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_DivertNotificationReadCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_DivertNotificationReadCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_Cad99AnalogMsgReadCounter=obj->Get(context, String::NewFromUtf8(isolate,"uint_Cad99AnalogMsgReadCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    Local<Array> uint_DeviceConnected=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"uint_DeviceConnected").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<4;i++){
        array_01.uint_DeviceConnected[i]=uint_DeviceConnected->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    Local<Array> uint_IntraloxStatusStatus=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"uint_IntraloxStatusStatus").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<3;i++){
        array_01.uint_IntraloxStatusStatus[i]=uint_IntraloxStatusStatus->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    Local<Array> uint_ChuteStatus=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"uint_ChuteStatus").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<50;i++){
        array_01.uint_ChuteStatus[i]=uint_ChuteStatus->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }

    return array_01;
}
