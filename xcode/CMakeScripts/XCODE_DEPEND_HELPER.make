# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.1.getting_started__1.1.hello_window.Debug:
PostBuild.STB_IMAGE.Debug: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window
PostBuild.GLAD.Debug: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libSTB_IMAGE.a\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libGLAD.a
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window


PostBuild.GLAD.Debug:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libGLAD.a


PostBuild.STB_IMAGE.Debug:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libSTB_IMAGE.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libSTB_IMAGE.a


PostBuild.1.getting_started__1.1.hello_window.Release:
PostBuild.STB_IMAGE.Release: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window
PostBuild.GLAD.Release: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libSTB_IMAGE.a\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libGLAD.a
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/1.getting_started__1.1.hello_window


PostBuild.GLAD.Release:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libGLAD.a


PostBuild.STB_IMAGE.Release:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libSTB_IMAGE.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libSTB_IMAGE.a


PostBuild.1.getting_started__1.1.hello_window.MinSizeRel:
PostBuild.STB_IMAGE.MinSizeRel: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window
PostBuild.GLAD.MinSizeRel: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libSTB_IMAGE.a\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libGLAD.a
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/MinSizeRel/1.getting_started__1.1.hello_window


PostBuild.GLAD.MinSizeRel:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libGLAD.a


PostBuild.STB_IMAGE.MinSizeRel:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libSTB_IMAGE.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libSTB_IMAGE.a


PostBuild.1.getting_started__1.1.hello_window.RelWithDebInfo:
PostBuild.STB_IMAGE.RelWithDebInfo: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window
PostBuild.GLAD.RelWithDebInfo: /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window:\
	/usr/local/lib/libglfw.dylib\
	/usr/local/lib/libassimp.dylib\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libSTB_IMAGE.a\
	/Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libGLAD.a
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/bin/1.getting_started/RelWithDebInfo/1.getting_started__1.1.hello_window


PostBuild.GLAD.RelWithDebInfo:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libGLAD.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libGLAD.a


PostBuild.STB_IMAGE.RelWithDebInfo:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libSTB_IMAGE.a:
	/bin/rm -f /Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libSTB_IMAGE.a




# For each target create a dummy ruleso the target does not have to exist
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libGLAD.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Debug/libSTB_IMAGE.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libGLAD.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/MinSizeRel/libSTB_IMAGE.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libGLAD.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/RelWithDebInfo/libSTB_IMAGE.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libGLAD.a:
/Users/dangxiaobin/Desktop/github/myOpengl/xcode/Release/libSTB_IMAGE.a:
/usr/local/lib/libassimp.dylib:
/usr/local/lib/libglfw.dylib:
