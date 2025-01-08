/* ​
* Copyright © 2024 Go Touch VR SAS. All rights reserved.
* ​
*/

#include "HapticDeviceManager.h"
#include "enums.h"


std::vector<void*> IH_DEVICE_PROVIDERS;

void InterhapticsEngine::HapticDeviceManager::InitializeAll()
{
	for (int i = IH_DEVICE_PROVIDERS.size() - 1; i >= 0; i--)
	{
		auto it = IH_DEVICE_PROVIDERS[i];
		uintptr_t DllExport = IH_GETDLLEXPORT("ProviderInit", DllExport, it);
		if (DllExport)
		{
			typedef bool(*GetInit)();
			GetInit InitFunc = (GetInit)(DllExport);
			if (!((bool)InitFunc()))
			{
				UE_LOG(LogTemp, Warning, TEXT("Provider failed to initialize. Removing provider at index %d."), i);
				IH_DEVICE_PROVIDERS.erase(IH_DEVICE_PROVIDERS.begin() + i);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to get ProviderInit function. Removing provider at index %d."), i);
			IH_DEVICE_PROVIDERS.erase(IH_DEVICE_PROVIDERS.begin() + i);
		}
	}
}

void InterhapticsEngine::HapticDeviceManager::RenderAll()
{
	// Check if a controller is connected
	for (auto& provider : IH_DEVICE_PROVIDERS)
	{
		if (provider)
		{
			// Call the ProviderIsPresent function for this provider to check if a controller is connected
			uintptr_t DllExport = IH_GETDLLEXPORT("ProviderIsPresent", DllExport, provider);
			if (DllExport)
			{
				typedef bool(*GetIsPresent)();
				GetIsPresent IsPresentFunc = (GetIsPresent)(DllExport);
				if (IsPresentFunc)
				{
					if (IsPresentFunc())
					{
						// Call the ProviderRenderHaptics function for this provider
						uintptr_t DllExportRender = IH_GETDLLEXPORT("ProviderRenderHaptics", DllExportRender, provider);
						if (DllExportRender)
						{
							typedef void(*GetRenderHaptics)();
							GetRenderHaptics RenderHapticsFunc = (GetRenderHaptics)(DllExportRender);
							if (RenderHapticsFunc)
							{
								RenderHapticsFunc();
							}
						}
					}
				}
			}
		}
	}
}

void InterhapticsEngine::HapticDeviceManager::CleanAll()
{
	for (auto it : IH_DEVICE_PROVIDERS)
	{
		if (!it)  // Check if the device pointer is null
		{
			UE_LOG(LogTemp, Warning, TEXT("Device handle is null during cleanup."));
			continue;
		}
		uintptr_t DllExport;
		DllExport = IH_GETDLLEXPORT("ProviderClean", DllExport, it);
		if (DllExport)
		{
			typedef bool(*GetClean)();
			GetClean CleanFunc = (GetClean)(DllExport);
			if (!((bool)CleanFunc()))
			{
                UE_LOG(LogTemp, Warning, TEXT("Provider failed to clean."));
			}
		}
	}
}

void InterhapticsEngine::HapticDeviceManager::AddProvider(void* device)
{
#if PLATFORM_SWITCH
	IH_DEVICE_PROVIDERS.push_back(device);
	return;
#endif
	if (device)
	{
		IH_DEVICE_PROVIDERS.push_back(device);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to add a null device provider.")); 
	}
}

int InterhapticsEngine::HapticDeviceManager::GetProviderCount()
{
	return IH_DEVICE_PROVIDERS.size();
}
