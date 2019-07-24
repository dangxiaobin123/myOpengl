# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.1.getting_started__1.1.hello_window.Debug:
PostBuild.GLAD.Debug: /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Debug/libGLAD.a
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window


PostBuild.GLAD.Debug:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Debug/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Debug/libGLAD.a


PostBuild.1.getting_started__1.1.hello_window.Release:
PostBuild.GLAD.Release: /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Release/libGLAD.a
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window


PostBuild.GLAD.Release:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Release/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Release/libGLAD.a


PostBuild.1.getting_started__1.1.hello_window.MinSizeRel:
PostBuild.GLAD.MinSizeRel: /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/MinSizeRel/libGLAD.a
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window


PostBuild.GLAD.MinSizeRel:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/MinSizeRel/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/MinSizeRel/libGLAD.a


PostBuild.1.getting_started__1.1.hello_window.RelWithDebInfo:
PostBuild.GLAD.RelWithDebInfo: /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/RelWithDebInfo/libGLAD.a
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window


PostBuild.GLAD.RelWithDebInfo:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/RelWithDebInfo/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/RelWithDebInfo/libGLAD.a




# For each target create a dummy ruleso the target does not have to exist
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Debug/libGLAD.a:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/MinSizeRel/libGLAD.a:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/RelWithDebInfo/libGLAD.a:
/Users/dangxiaobin01/Documents/myProject/LearnOpengl/xcode/Release/libGLAD.a:
/usr/local/lib/libassimp.dylib:
/usr/local/lib/libglfw.dylib:
