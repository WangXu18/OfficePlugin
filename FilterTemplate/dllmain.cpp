// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "KPsFilterAddin.h"

filter_addin::KPsFilterAddin filterAddin;
SPBasicSuite* sSPBasic = NULL;
SPPluginRef gPlugInRef = NULL;

DLLExport SPAPI void PluginMain(const int16 selector,
                                FilterRecordPtr filterParamBlock,
                                intptr_t* data,
                                int16* result);

DLLExport SPAPI void PluginMain(const int16 selector,
                                FilterRecordPtr filterParamBlock,
                                intptr_t* data,
                                int16* result) {
  //::MessageBox(NULL, "test", "sssa", MB_OK);
  sSPBasic = filterParamBlock->sSPBasic;
  gPlugInRef = (SPPluginRef)filterParamBlock->plugInRef;

  try {
    switch (selector) {
      case filterSelectorAbout:
        /*sSPBasic = ((AboutRecordPtr)(filterParamBlock))->sSPBasic;
        gPlugInRef =
            (SPPluginRef)((AboutRecordPtr)(filterParamBlock))->plugInRef;*/
        //theApp.About();
        //::MessageBox(NULL, "000", "000", MB_OK);
        break;
      case filterSelectorParameters:
        filterAddin.DoParameters();
        break;
      case filterSelectorPrepare:
        filterAddin.DoPrepare();
        break;
      case filterSelectorStart:
        filterAddin.DoStart();
        break;
      case filterSelectorContinue:
        filterAddin.DoContinue();
        break;
      case filterSelectorFinish:
        filterAddin.DoFinish();
        break;
    }

    if (selector != filterSelectorAbout) {
      filterAddin.DoExit();
    }
  } catch (char* inErrorString) {
    OutputDebugStringA(inErrorString);
    char* pErrorString = (char*)filterParamBlock->errorString;
    if (pErrorString != NULL && (strlen(inErrorString) < 256)) {
      *pErrorString = (char)strlen(inErrorString);
      memcpy(pErrorString + 1, inErrorString, (unsigned char)(*pErrorString));
    }
    *result = errReportString;
  } catch (short inError) {
    *result = inError;
  } catch (...) {
    *result = -1;
  }
}
