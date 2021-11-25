// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "PIUGet.h"
#include "PIDefines.h"
#include "PIGeneral.h"
#include "SPInterf.h"
#include "SPBasic.h"
#include "SPAccess.h"
#include "PIActions.h"
//#include "ADMBasic.h"
#include "PIUSuites.h"

#include "PItypes.h"
#include "PIFilter.h"

#include "Filter.h"

#define DLLExport extern "C" __declspec(dllexport)


//DLLExport SPAPI SPErr AutoPluginMain(const char* caller,    // who is calling
//                                     const char* selector,  // what do they want
//                                     void* message  // what is the message
//);

SPBasicSuite* sSPBasic = NULL;
SPPluginRef gPlugInRef = NULL;
//PSActionDescriptorProcs* sPSActionDescriptor = NULL;
//PSActionDescriptorProcs* sPSActionReference = NULL;
//PSActionControlProcs* sPSActionControl = NULL;
//PSActionListProcs* sPSActionList = NULL;
//ADMBasicSuite* sADMBasic = NULL;

//DLLExport SPAPI SPErr AutoPluginMain(const char* caller,    // who is calling
//                                     const char* selector,  // what do they want
//                                     void* message  // what is the message
//)
//{
//  SPErr error = kSPNoError;
//
//  SPMessageData* basicMessage = NULL;
//  basicMessage = (SPMessageData*)message;
//  sSPBasic = basicMessage->basic;
//
//  if (sSPBasic->IsEqual((char*)caller, kSPInterfaceCaller)) {
//    if (sSPBasic->IsEqual((char*)selector, kSPInterfaceAboutSelector)) {
//      // about
//      ::MessageBox(NULL, "tss", "tssss", MB_OK);
//    }
//  }
//
//  if (sSPBasic->IsEqual((char*)caller, kPSPhotoshopCaller)) {
//    if (sSPBasic->IsEqual((char*)selector, kPSDoIt)) {
//      ::MessageBox(NULL, "tss", "tssss", MB_OK);
//    }
//  }
//
//  //try {
//  //  // all messages contain a SPMessageData*
//  //  //SPMessageData* basicMessage;
//  //  //basicMessage = (SPMessageData*)message;
//  //  
//  //  gPlugInRef = basicMessage->self;
//
//  //  // check for SP interface callers
//  //  if (sSPBasic->IsEqual(caller, kSPInterfaceCaller)) {
//  //    // pop an about box
//  //    if (sSPBasic->IsEqual(selector, kSPInterfaceAboutSelector)) {
//  //      //DoAbout(gPlugInRef, AboutID);
//  //    }
//  //  }
//
//  //  // Photoshop is calling us
//  //  if (sSPBasic->IsEqual(caller, kPSPhotoshopCaller)) {
//  //    // the one and only message
//  //    if (sSPBasic->IsEqual(selector, kPSDoIt)) {
//  //      //AutomationFilterData afData;
//
//  //      // now that we know more we can cast the message to a
//  //      // PSActionsPlugInMessage*
//  //      /*PSActionsPlugInMessage* actionsMessage =
//  //          (PSActionsPlugInMessage*)message;
//
//  //      error = afData.DoIt(actionsMessage);*/
//  //    }
//  //  }
//  //}
//
//  //catch (...) {
//  //  if (error == 0)
//  //    error = kSPBadParameterError;
//  //}
//
//  return error;
//}

DLLExport SPAPI void PluginMain(const int16 selector,
                                FilterRecordPtr filterParamBlock,
                                intptr_t* data,
                                int16* result);

DLLExport SPAPI void PluginMain(const int16 selector,
                                FilterRecordPtr filterParamBlock,
                                intptr_t* data,
                                int16* result) {
  sSPBasic = filterParamBlock->sSPBasic;
  gPlugInRef = (SPPluginRef)filterParamBlock->plugInRef;

  try {
    //theApp.Entry(filterParamBlock, data);

    switch (selector) {
      case filterSelectorAbout:
        /*sSPBasic = ((AboutRecordPtr)(filterParamBlock))->sSPBasic;
        gPlugInRef =
            (SPPluginRef)((AboutRecordPtr)(filterParamBlock))->plugInRef;
        theApp.About();*/
        break;
      case filterSelectorParameters:
        //theApp.Parameters();
        break;
      case filterSelectorPrepare:
        //theApp.Prepare();
        break;
      case filterSelectorStart:
        //theApp.Start();
        break;
      case filterSelectorContinue:
        //theApp.Continue();
        break;
      case filterSelectorFinish:
        //theApp.Finish();
        break;
    }

    /*if (selector != filterSelectorAbout)
      theApp.Exit();*/
    ::MessageBox(NULL, "ss", "sba", MB_OK);
  }
  catch (char* inErrorString) {
    OutputDebugStringA(inErrorString);
    char* pErrorString = (char*)filterParamBlock->errorString;
    if (pErrorString != NULL && (strlen(inErrorString) < 256)) {
      *pErrorString = (char)strlen(inErrorString);
      memcpy(pErrorString + 1, inErrorString, (unsigned char)(*pErrorString));
    }
    *result = errReportString;

  }

  catch (short inError) {
    *result = inError;
  }

  catch (...) {
    *result = -1;
  }
}


//DLLExport MACPASCAL void PluginMain(const int16 selector,
//                                    FilterRecordPtr filterRecord,
//                                    intptr_t* data,
//                                    int16* result) {
//  try {
//    /*Logger logIt("Dissolve");
//    Timer timeIt;
//
//    logIt.Write("Selector: ", false);
//    logIt.Write(selector, false);
//    logIt.Write(" ", false);*/
//
//    // update our global parameters
//    /*gFilterRecord = filterRecord;
//    gResult = result;
//    gData = (Data*)*data;*/
//
//    /*if (selector == filterSelectorAbout) {
//      sSPBasic = ((AboutRecord*)gFilterRecord)->sSPBasic;
//    } else {
//      sSPBasic = gFilterRecord->sSPBasic;
//
//      if (gFilterRecord->bigDocumentData != NULL)
//        gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates = true;
//    }*/
//
//    // do the command according to the selector
//    switch (selector) {
//      case filterSelectorAbout:
//        test();
//        break;
//      case filterSelectorParameters:
//        test();
//        break;
//      case filterSelectorPrepare:
//        test();
//        break;
//      case filterSelectorStart:
//        test();
//        break;
//      case filterSelectorContinue:
//        test();
//        break;
//      case filterSelectorFinish:
//        test();
//        break;
//      default:
//        break;
//    }
//
//    // Unlock our handles used by gParams
//    if (selector != filterSelectorAbout)
//      test();
//
//    // give the pointer back to Photoshop so it can return the favor in future
//    // calls
//    //*data = (intptr_t)gData;
//
//  } catch (...) {
//    if (NULL != result)
//      *result = -1;
//  }
//}
