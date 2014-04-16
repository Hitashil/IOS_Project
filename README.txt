This is the README file for getting the SDL_ttf testing application on ios systems up and running.


1. Download the latest source snapshot of SDL 1.3. Once this is done, in the newly downloaded sdl folder you must navigate to the /Xcode-iPhoneOS/Template folder and copy the SDL iOS Application folder. You will use this folder as the base for your own project. You may rename it whatever you wish and rename the xcode project from within xcode to whatever you wish as well. 

2. Inside of this application folder, create a new folder and name it SDL. Inside of this new SDL folder,    create a folder and call it lib. Next go back to the /Xcode-iPhoneOS folder and then proceed to the SDL folder. From there, open the xcode project. Build the project for both device and simulator. Now go to the build/Debug-iphoneos folder or build/Debug-iphonesimulator depending on which one you wish. If the project built properly you should see a libSDL.a file in both folders. Copy this file and now go back to your own application's SDL/lib folder that we created earlier. Paste the file in here. 

3. Back in your downloaded sdl folder, there is an include folder. Copy it and paste it in you application's sdl folder. Now you should have both an include and a lib folder in here. Now open up your project and add the sdl folder to it (in xcode). You should be able to see the include and lib folder as well as the files contained within them. This should allow you to use SDL on its own. Test your application to ensure it does in fact work.

4. The next step to getting ttf off the ground, is to obtain the freetype library. In safari, navigate to https://github.com/cdave1/freetype2-ios and download the xcode project for freetype 2. Once downloaded, open up the xcode project and build it for both device and simulator. Now you should find the corresponding lib files in the /build/whatever folder. Copy the one you need and paste it in your application's SDL/lib folder.

5. However, you will also need to download the source files for the freetype library. From its top directory, go to the docs folder and follow the instructions on how to install freetype, located in the INSTALL.UNIX file.

6. Finally, download the ttf source. Copy the SDL folder that is in your application's folder. Paste this in the ttf source directory, but you do not need the freetype library file that we just put in the lib folder. So delete it but keep the libSDL.a file. Now locate the directory in which the freetype library was installed in the previous step. It should be located in /usr/local. Copy the entire local folder into the same area where we just copied the sdl folder. 

7. Now open up the ttf project and add both the sdl and local folders to it. Open up the project properties and go to the build tab. Scroll down to the search paths section. In both the header search paths box and the user search paths box, type the directory where the freetype2 folder is located. For example: ../../../SDL_ttf-2.0.10/Xcode/local/include/freetype2. Also, make sure that the project is building for the iOS. Either simulator or device depending on which one you need. And ensure the active target is set to static library. Now you should be able to build the project successfully. If it works, go to the build directory and locate the appropriate folder. Copy the libSDL_ttf.a file which should be there into your application's SDL/lib folder.

You should now have everything you need to get ttf working in your application with either the iOS simulator or device.
