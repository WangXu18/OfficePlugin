#include "pch.h"
#include "KPsFilterAddin.h"

using namespace filter_addin;

BOOL KPsFilterAddin::OpenTemplateExe() {
  SHELLEXECUTEINFO sei = {0};
  sei.cbSize = sizeof(SHELLEXECUTEINFOW);
  sei.fMask = SEE_MASK_FLAG_NO_UI;
  sei.lpFile = "C:\\WINDOWS\\system32\\cmd.exe";
  sei.lpVerb = "open";
  sei.nShow = SW_SHOW;
  return ::ShellExecuteEx(&sei);
}

void KPsFilterAddin::DoAbout() {
}

void KPsFilterAddin::DoParameters() {
}

void KPsFilterAddin::DoPrepare() {
}

void KPsFilterAddin::DoStart() {
  OpenTemplateExe();
}

void KPsFilterAddin::DoContinue() {
}

void KPsFilterAddin::DoFinish() {
}

void KPsFilterAddin::DoExit() {
}
