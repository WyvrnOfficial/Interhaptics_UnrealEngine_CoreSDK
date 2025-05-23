# 2024.12.24
# v1.4.0

+ Updated haptic engine to 1.9.1
+ Platform support modification
+ Minor fix in haptic provider rendering loop

# 2024.10.18
# v1.3.1

+ Fixed an issue that would result in a crash while cooking the project

# 2024.10.08
# v1.3.0

+ Updated SDK for 5.4+ support
+ Rebuilt sample scene on UE 4.26 for retrocompatibility
+ Updated GameInput provider to v1.3.1
+ Updated Razer Sensa provider to v1.2.0

# 2024.07.24
# v1.2.4

+ Fixed an issue with haptic provider loading logic 

# 2024.07.08
# v1.2.3

+ Fixed a rendering issue with Razer Sensa devkits
+ Changed blueprint using double to float for UE4 compatibility

# 2024.07.02
# v1.2.2

+ Fixed memory leaks on target creation
+ Fixed loading issues with GameInput provider
+ Known issue with Razer Sensa devkit controller not compatible

# 2024.06.12
# v1.2.1

+ Fix HapticManager singleton behavior

# 2024.05.21
# v1.2.0

+ Enabled Sensa support
+ Added various APIs for C++ and Blueprint usage of the SDK
+ Fixed various bugs 

# 2024.04.19
# v1.1.1

+ Enabled support for the PS5 module
+ Enabled support for the Switch module
+ Reworked the package for Marketplace distribution

# 2024.01.07
# v1.1.0

+ Updated XInput provider to GameInput provider (GameInputProvider.dll supplants XInputProvider.dll) with XInput used as fallback. 
+ Added sample level HapticLevel3D which showcases playing haptics through a PlayerController blueprint class
+ Reorganized folder and file structure to be Epic Marketplace compliant

# 2023.10.30
# v1.0.2

+ Fix Compiler issue that could happen when loading a project just after adding the plugin

# 2023.06.08
# v1.0.1

+ Fix Interhaptics module exception

# 2023.05.02
# v1.0.0

+ README and documentation link update

# 2023.04.20
# v0.0.1

+ First push with PC Windows XInput support