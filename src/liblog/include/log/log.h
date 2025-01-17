#ifndef _LIBS_LOG_LOG_H
#define _LIBS_LOG_LOG_H

#include <stdio.h>
#include <stdarg.h>


//1024 + 128
#define DEFAULT_LOG_BUFFER_LEN 1152

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

typedef enum android_LogPriority {
    ANDROID_LOG_UNKNOWN = 0,
    ANDROID_LOG_DEFAULT,    /* only for SetMinPriority() */
    ANDROID_LOG_VERBOSE,
    ANDROID_LOG_DEBUG,
    ANDROID_LOG_INFO,
    ANDROID_LOG_WARN,
    ANDROID_LOG_ERROR,
    ANDROID_LOG_FATAL,
    ANDROID_LOG_SILENT,     /* only for SetMinPriority(); must be last */
} android_LogPriority;

int __android_log_print(android_LogPriority priority, const char *tag,
                        const char *fmt, ...);

#ifndef LOG_NDEBUG
#define LOG_NDEBUG 1
#endif

#ifndef LOG_TAG
#define LOG_TAG "shift"
#endif

#ifndef ALOG
#define ALOG(priority, tag, ...) \
    LOG_PRI(ANDROID_##priority, tag, __VA_ARGS__)
#endif

#ifndef LOG_PRI
#define LOG_PRI(priority, tag, ...) \
    __android_log_print(priority, tag, __VA_ARGS__)
#endif

#ifndef ALOGV
#define __ALOGV(...) ((void)ALOG(LOG_VERBOSE, LOG_TAG, __VA_ARGS__))
#if LOG_NDEBUG
#define ALOGV(...) do { if (0) { __ALOGV(__VA_ARGS__); } } while (0)
#else
#define ALOGV(...) __ALOGV(__VA_ARGS__)
#endif
#endif

#ifndef ALOGD
#define ALOGD(...) ((void)ALOG(LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGI
#define ALOGI(...) ((void)ALOG(LOG_INFO, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGW
#define ALOGW(...) ((void)ALOG(LOG_WARN, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGE
#define ALOGE(...) ((void)ALOG(LOG_ERROR, LOG_TAG, __VA_ARGS__))
#endif

#ifndef SLOGV
#define SLOGV(...) ((void)0)
#endif

#ifndef SLOGD
#define SLOGD(...) ((void)0)
#endif

#ifndef SLOGI
#define SLOGI(...) ((void)0)
#endif

#ifndef SLOGW
#define SLOGW(...) ((void)0)
#endif

#ifndef SLOGE
#define SLOGE(...) ((void)0)
#endif

#ifndef ALOGV_IF
#define ALOGV_IF(cond, ...) ((void)0)
#endif

#ifndef ALOGD_IF
#define ALOGD_IF(cond, ...) ((void)0)
#endif

#ifndef ALOGI_IF
#define ALOGI_IF(cond, ...) ((void)0)
#endif

#ifndef ALOGW_IF
#define ALOGW_IF(cond, ...)\
if(cond) {\
    ALOGW(__VA_ARGS__);\
}
#endif

#ifndef ALOGE_IF
#define ALOGE_IF(cond, ...)\
if(cond) {\
    ALOGE(__VA_ARGS__);\
}
#endif

#ifndef ALOG_ASSERT
#define ALOG_ASSERT(cond, ...) ((void)0)
#endif

#ifndef LOG_FATAL_IF
#define LOG_FATAL_IF(cond, ...) ((void)0)
#endif

#ifndef LOG_ALWAYS_FATAL_IF
#define LOG_ALWAYS_FATAL_IF(cond, ...) (void)0
#endif

#ifndef LOG_ALWAYS_FATAL
#define LOG_ALWAYS_FATAL(...) ((void)0)
#endif

#ifndef IF_ALOG
#define IF_ALOG(priority, tag) ((void)0)
#endif

#ifndef IF_ALOGV
#define IF_ALOGV() if (false)
#endif

#define android_errorWriteWithInfoLog(tag, subTag, uid, data, dataLen) ((void)0)

#define android_errorWriteLog(tag, subTag) ((void)0)

#endif
