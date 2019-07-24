
#ifndef LOGGER_H
#define LOGGER_H

#define SHUT_INFO_LOG
#define SHUT_DEBUG_LOG
#define SHUT_WARN_LOG

#ifdef DUAR_ANDROID
#include <android/log.h>
#else
#include <stdio.h>
#endif

#include <errno.h>
#include <string.h>

#define clean_errno() ""

#ifdef _WIN32
#include "../../platforms/PC/common_3dview/ms_log.h"
#endif

#ifdef DUAR_ANDROID
#define __FILENAME__ (strrchr(__FILE__, '/') + 1)

#define ANDROID_LOG(level, format, ...)  __android_log_print(level, \
"EngineLogger", "(%s:%d:) " format "\n", \
__FILENAME__, __LINE__, ##__VA_ARGS__)
#else
#define IOS_LOG(level, format, ...)  fprintf(stderr, level "(%s:%d: errno: %s) " format "\n", \
__FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#endif

#ifdef DUAR_ANDROID
#define LOG_ERR(M, ...) ANDROID_LOG(ANDROID_LOG_ERROR, M, ##__VA_ARGS__)
#elif defined _WIN32
#define LOG_ERR(M, ...) \
{\
log_out_ms(LOG_TYPE_ERROR, M, ##__VA_ARGS__);\
};
#else
#define LOG_ERR(M, ...) IOS_LOG("[ERROR]", M, ##__VA_ARGS__)
#endif

#ifdef DUAR_ANDROID
#define SHUT_DEBUG_LOG
//#define SHUT_WARN_LOG
#define SHUT_INFO_LOG
#elif defined _WIN32

#else
#define SHUT_DEBUG_LOG
//#define SHUT_WARN_LOG
#define SHUT_INFO_LOG
#endif

#ifndef SHUT_DEBUG_LOG
#ifdef DUAR_ANDROID
#define LOG_DEBUG(M, ...) ANDROID_LOG(ANDROID_LOG_DEBUG, M, ##__VA_ARGS__)
#elif defined _WIN32
#define LOG_DEBUG(M, ...) \
{\
log_out_ms(LOG_TYPE_DEBUG, M, ##__VA_ARGS__);\
};

#else
#define LOG_DEBUG(M, ...) IOS_LOG("[DEBUG]", M, ##__VA_ARGS__)
#endif
#else
#define LOG_DEBUG(M, ...) ;
#endif

#ifndef SHUT_WARN_LOG
#ifdef DUAR_ANDROID
#define LOG_WARN(M, ...) ANDROID_LOG(ANDROID_LOG_WARN, M, ##__VA_ARGS__)
#elif defined _WIN32
#define LOG_WARN(M, ...) \
{\
log_out_ms(LOG_TYPE_WARIN, M, ##__VA_ARGS__);\
};

#else
#define LOG_WARN(M, ...) IOS_LOG("[WARN]", M, ##__VA_ARGS__)
#endif
#elif defined _WIN32
#define LOG_WARN(M, ...) \
{\
log_out_ms(LOG_TYPE_WARIN, M, ##__VA_ARGS__);\
};
#else
#define LOG_WARN(M, ...) ;
#endif

#ifndef SHUT_INFO_LOG
#ifdef DUAR_ANDROID
#define LOG_INFO(M, ...) ANDROID_LOG(ANDROID_LOG_INFO, M, ##__VA_ARGS__)
#else
#define LOG_INFO(M, ...) IOS_LOG("[INFO]", M, ##__VA_ARGS__)
#endif
#elif defined _WIN32
#define LOG_INFO(M, ...) \
{\
log_out_ms(LOG_TYPE_INFO, M, ##__VA_ARGS__);\
};
#else
#define LOG_INFO(M, ...) ;
#endif

#endif //LOGGER_H
