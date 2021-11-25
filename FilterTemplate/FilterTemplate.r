#include "PIDefines.h"
#include "PIGeneral.h"
#include "PIResourceDefines.h"

resource 'PiPL' (16000, "Tommy PiPL", purgeable)
{
	{
		Kind { Filter },

		Name { "FilterTemplate" },

		Category { "�칫ģ��" },

		Version { (latestFilterVersion << 16) | latestFilterSubVersion },

		Component { ComponentNumber, "�칫ģ��" },

    #if __PIMac_
      #if defined(__arm64__)
        CodeMacARM64 { "PluginMain" },
      #endif
      #if defined(__x86_64__)
        CodeMacIntel64 { "PluginMain" },
      #endif
    #elif __PIWin__
      CodeEntryPointWin64 { "PluginMain" },
    #endif

		EnableInfo { "true" },

	}
};

