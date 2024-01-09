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

    unsigned short uint_Data[4]; // 0; DI  1:DI  2:SafetyPLC In 3:Err Drive (Culler,Incline,P Turn,Sorter,Jackpot)
    //unsigned int   uint_EDS_ComData[8];
    unsigned int   uint_EDS_ComData_Control;     // uint_EDS_ComData[0]
    unsigned int   uint_EDS_ComData_TsSSMMHHDD;  // uint_EDS_ComData[1]
    unsigned int   uint_EDS_ComData_TsMM__YYYY;  // uint_EDS_ComData[2]
    unsigned short uint_EDS_ComData_Mode;        // uint_EDS_ComData[4].0_15
    unsigned short uint_EDS_ComData_State;       // uint_EDS_ComData[4].16_31
    unsigned short uint_EDS_ComData_Ins;         // uint_EDS_ComData[5].0_15
    unsigned short uint_EDS_ComData_Fault;       // uint_EDS_ComData[5].16_31
    unsigned int   uint_EDS_ComData_Diag;        // uint_EDS_ComData[6].0_31

    //unsigned int   uint_EDS_Id0Data[8];  Piece exiting from EDS
    unsigned int   uint_MHE_Id0Data_Vid_num1_8;  // uint_EDS_Id0[0]
    unsigned int   uint_MHE_Id0Data_Vid_num9_16; // uint_EDS_Id0[1]
    unsigned int   uint_MHE_Id0Data_EDSPseudoId; // uint_EDS_Id0[2]
    unsigned short uint_MHE_Id0Data_PassNumber;  // uint_EDS_Id0[3].0_15
    unsigned short uint_MHE_Id0Data_TsSSMM;      // uint_EDS_Id0[3].16_31
    unsigned short uint_MHE_Id0Data_TsHHDD;      // uint_EDS_Id0[4].0_15
    unsigned short uint_MHE_Id0Data_TsMM_PcsTrk; // uint_EDS_Id0[4].16_31
    unsigned short uint_MHE_Id0Data_TsYYYY;      // uint_EDS_Id0[5].0_15
    unsigned short uint_MHE_Id0Data_SecurityRoutineCode; // uint_EDS_Id0[5].16_31
    unsigned short uint_MHE_Id0Data_PieceDispo;  // uint_EDS_Id0[6].0_15
    unsigned short uint_MHE_Id0Data_PrjSpec;     // uint_EDS_Id0[6].16_31
    unsigned int   uint_MHE_Id0Data_GlobalId;    // uint_EDS_Id0[7]

    //unsigned int   uint_EDS_Id1Data[8];  Piece that have already left EDS
    unsigned int   uint_MHE_Id1Data_Vid_num1_8;  // uint_EDS_Id1[0]
    unsigned int   uint_MHE_Id1Data_Vid_num9_16; // uint_EDS_Id1[1]
    unsigned int   uint_MHE_Id1Data_EDSPseudoId; // uint_EDS_Id1[2]
    unsigned short uint_MHE_Id1Data_PassNumber;  // uint_EDS_Id1[3].0_15
    unsigned short uint_MHE_Id1Data_TsSSMM;      // uint_EDS_Id1[3].16_31
    unsigned short uint_MHE_Id1Data_TsHHDD;      // uint_EDS_Id1[4].0_15
    unsigned short uint_MHE_Id1Data_TsMM_PcsTrk; // uint_EDS_Id1[4].16_31
    unsigned short uint_MHE_Id1Data_TsYYYY;      // uint_EDS_Id1[5].0_15
    unsigned short uint_MHE_Id1Data_SecurityRoutineCode; // uint_EDS_Id1[5].16_31
    unsigned short uint_MHE_Id1Data_PieceDispo;  // uint_EDS_Id1[6].0_15
    unsigned short uint_MHE_Id1Data_PrjSpec;     // uint_EDS_Id1[6].16_31
    unsigned int   uint_MHE_Id1Data_GlobalId;    // uint_EDS_Id1[7]

    //unsigned int   uint_EDS_DiagData[10];  Not used

//      unsigned short uint_BarcodeCounter;
//      unsigned short uint_BarecodeMsgLength;
//      char           byte_BarecodeMsg[64];

//      unsigned short uint_DestinationCounter;
//      unsigned short uint_DestinationSequentialNumber;
//      unsigned short uint_DestinationCounterLength;
//      unsigned short uint_spare1;
//      char           byte_Destination[8];
//      unsigned short uint_AlternateDestinationLength;
//      unsigned short uint_spare2;
//      char           byte_AlternateDestination[8];

//      unsigned short uint_ConfirmationCounter;
//      unsigned short uint_ConfirmationSequentialNumber;
//      unsigned short uint_ConfirmationDestination;
//      unsigned short uint_ConfirmationSortCode;

//      unsigned short uint_ScanNotificationReadCounter;
//      unsigned short uint_IntraloxSortMsgReadCounter;
//      unsigned short uint_DivertNotificationReadCounter;
//      unsigned short uint_Cad99AnalogMsgReadCounter;

    unsigned short uint_DeviceConnected[4];
    //      unsigned int   uint_IntraloxStatusStatus[3];
    //      unsigned int   uint_ChuteStatus[50];

};

StructureArray01 getArray01() {

    StructureArray01 dataArray01 =
    {
        54348784,961088068,961088068,961088034,0
        ,{0,0,0,21845},1,2,3,4,5,6,7,8
        ,1,2,3,4,5,6,7,8,9,10,11,12
        ,1,2,3,4,5,6,7,8,9,10,11,12
        ,{151, 0, 0, 0}
    };
    return dataArray01;
}
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

    array_01.uint_EDS_ComData_Control=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_Control").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_TsSSMMHHDD=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_TsSSMMHHDD").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_TsMM__YYYY=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_TsMM__YYYY").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_Mode=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_Mode").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_State=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_State").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_Ins=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_Ins").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_Fault=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_Fault").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_EDS_ComData_Diag=obj->Get(context, String::NewFromUtf8(isolate,"uint_EDS_ComData_Diag").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    array_01.uint_MHE_Id0Data_Vid_num1_8=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_Vid_num1_8").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_Vid_num9_16=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_Vid_num9_16").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_EDSPseudoId=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_EDSPseudoId").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_PassNumber=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_PassNumber").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_TsSSMM=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_TsSSMM").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_TsHHDD=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_TsHHDD").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_TsMM_PcsTrk=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_TsMM_PcsTrk").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_TsYYYY=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_TsYYYY").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_SecurityRoutineCode=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_SecurityRoutineCode").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_PieceDispo=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_PieceDispo").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_PrjSpec=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_PrjSpec").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id0Data_GlobalId=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id0Data_GlobalId").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    array_01.uint_MHE_Id1Data_Vid_num1_8=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_Vid_num1_8").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_Vid_num9_16=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_Vid_num9_16").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_EDSPseudoId=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_EDSPseudoId").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_PassNumber=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_PassNumber").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_TsSSMM=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_TsSSMM").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_TsHHDD=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_TsHHDD").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_TsMM_PcsTrk=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_TsMM_PcsTrk").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_TsYYYY=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_TsYYYY").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_SecurityRoutineCode=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_SecurityRoutineCode").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_PieceDispo=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_PieceDispo").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_PrjSpec=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_PrjSpec").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.uint_MHE_Id1Data_GlobalId=obj->Get(context, String::NewFromUtf8(isolate,"uint_MHE_Id1Data_GlobalId").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();


    Local<Array> uint_DeviceConnected=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"uint_DeviceConnected").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<4;i++){
        array_01.uint_DeviceConnected[i]=uint_DeviceConnected->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }
    return array_01;
}
