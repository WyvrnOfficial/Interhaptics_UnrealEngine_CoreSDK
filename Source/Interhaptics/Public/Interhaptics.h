/* ​
* Copyright © 2023 Go Touch VR SAS. All rights reserved.
* ​
*/

#pragma once

#include "Modules/ModuleManager.h"
#include "HapticManager.h"

class FInterhapticsModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void* v_Handle;

#if PLATFORM_PS5
	void* v_dualSenseHandle;
#endif
};
