To import the Interhaptics SDK into Unreal Engine, follow these steps (Steps 1-3 are for the Interhaptics plugin from the GitHub repository):

1. Go YourProject folder and create a Plugins folder here (YourProject/Plugins).
2. Go inside the Plugins folder and clone the repository here.
3. Open the project and you will be prompt to rebuild the different modules included in the plugin. 
4. Go in Settings > Plugins and check that Interhaptics is enabled under Project > Other.

In the Content Browser, go in Settings and check Show Plugins content. Then go under Interhaptics C++ class > Interhaptics > Public, get the Haptic Manager and drag in into your viewport.
Next you can create a new Blueprint with the Haptic Source type and use the following features:
+ General: Assign a Haptic Effect to the object to be played
+ Blueprint event graph: Set Targets: allows you to set the targets of the source between Left, Right, Both or None
+ Blueprint event graph: Play: starts all haptic events related to the source
+ Blueprint event graph: Stop: stops all haptic events related to the source

To test a level with a Blueprint implementation you can open the HapticLevel map from the Plugins > Interhaptics Content and test with an XInput or compatible controller. The haptic sources will activate when pressing the A,B,X and Y buttons.

You can check directly the documentation at https://doc.wyvrn.com/docs/interhaptics-sdk/haptics-unreal-sdk/

If you need help or want to talk haptics, join us on Discord on this links https://discord.com/invite/93jU9nAX4f
