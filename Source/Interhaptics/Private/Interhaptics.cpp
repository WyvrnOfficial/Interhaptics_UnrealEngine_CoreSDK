/* ​
* Copyright © 2024 Go Touch VR SAS. All rights reserved.
* ​
*/

#include "Interhaptics.h"
#include "HAR.h"
#include "HapticDeviceManager.h"
#include "HapticManager.h" 
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "FInterhapticsModule"

void FInterhapticsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	
	FString BaseDir = IPluginManager::Get().FindPlugin("Interhaptics")->GetBaseDir();
	FString LibraryPath;

#pragma region Load Haptic Engine
	// Add on the relative location of the third party dll and load it
#if PLATFORM_WINDOWS || PLATFORM_MAC
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/Interhaptics/Lib/x64/Release/HAR.dll"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/Interhaptics/Lib/Mac/Release/libHAR.dylib"));
#endif 

	if (LibraryPath.IsEmpty())
	{
		if (!v_Handle)
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("LibraryError", "DLL path is empty"));
		}
	}
	else
	{
		v_Handle = FPlatformProcess::GetDllHandle(*LibraryPath);
		if (!v_Handle)
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("LibraryError", "Failed to load InterhapticsEngine DLL"));
		}
	}
#endif
#pragma endregion
#pragma region Init Haptic Manager
  // Register to spawn HapticManager on world initialization
  FWorldDelegates::OnPostWorldInitialization.AddLambda([](UWorld* World, const UWorld::InitializationValues IVS)
    {
      if (World && World->IsGameWorld())
      {
        // Spawn the HapticManager
        AHapticManager* HapticManager = World->SpawnActor<AHapticManager>();
        if (!HapticManager)
        {
          UE_LOG(LogTemp, Warning, TEXT("Failed to spawn HapticManager."));
        }
		HapticManager = nullptr;
      }
    });
#pragma endregion
}

void FInterhapticsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(v_Handle);
	v_Handle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FInterhapticsModule, Interhaptics)
