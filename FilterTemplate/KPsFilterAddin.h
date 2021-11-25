#pragma once

namespace filter_addin {

class KPsFilterAddin {
 public:
  void DoAbout();
  void DoParameters();
  void DoPrepare();
  void DoStart();
  void DoContinue();
  void DoFinish();
  void DoExit();

 private:
  BOOL OpenTemplateExe();
};

}  // namespace filter_addin