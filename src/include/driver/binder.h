/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_LINUX_BINDER_H
#define _UAPI_LINUX_BINDER_H

#include <linux/types.h>
#include <linux/ioctl.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <fcntl.h>

#ifndef B_PACK_CHARS
#define B_PACK_CHARS(c1,c2,c3,c4) ((((c1) << 24)) | (((c2) << 16)) | (((c3) << 8)) | (c4))
#endif  // B_PACK_CHARS

#define B_TYPE_LARGE 0x85

#ifdef __cplusplus
extern "C" {
#endif

enum {
  BINDER_TYPE_BINDER = B_PACK_CHARS('s', 'b', '*', B_TYPE_LARGE),
  BINDER_TYPE_WEAK_BINDER = B_PACK_CHARS('w', 'b', '*', B_TYPE_LARGE),
  BINDER_TYPE_HANDLE = B_PACK_CHARS('s', 'h', '*', B_TYPE_LARGE),
  BINDER_TYPE_WEAK_HANDLE = B_PACK_CHARS('w', 'h', '*', B_TYPE_LARGE),
  BINDER_TYPE_FD = B_PACK_CHARS('f', 'd', '*', B_TYPE_LARGE),
  BINDER_TYPE_FDA = B_PACK_CHARS('f', 'd', 'a', B_TYPE_LARGE),
  BINDER_TYPE_PTR = B_PACK_CHARS('p', 't', '*', B_TYPE_LARGE),
};
enum {
  FLAT_BINDER_FLAG_PRIORITY_MASK = 0xff,
  FLAT_BINDER_FLAG_ACCEPTS_FDS = 0x100,
};
#ifdef BINDER_IPC_32BIT
typedef __u32 binder_size_t;
typedef __u32 binder_uintptr_t;
#else
typedef __u64 binder_size_t;
typedef __u64 binder_uintptr_t;
#endif
struct binder_object_header {
  __u32 type; /* 8 bytes for large_flat_header. */
};
struct flat_binder_object {
  struct binder_object_header hdr;
  __u32 flags;
  union {
    binder_uintptr_t binder;  //local object
    __u32 handle;             //remote object
  };
  binder_uintptr_t cookie; /* extra data associated with local object */
};
struct binder_fd_object {
  struct binder_object_header hdr;
  __u32 pad_flags;
  union {
    binder_uintptr_t pad_binder;
    __u32 fd;
  };
  binder_uintptr_t cookie;
};
struct binder_buffer_object {
  struct binder_object_header hdr;
  __u32 flags;
  binder_uintptr_t buffer;
  binder_size_t length;
  binder_size_t parent;
  binder_size_t parent_offset;
};
enum {
  BINDER_BUFFER_FLAG_HAS_PARENT = 0x01,
};
struct binder_fd_array_object {
  struct binder_object_header hdr;
  __u32 pad;
  binder_size_t num_fds;
  binder_size_t parent;
  binder_size_t parent_offset;
};
struct binder_write_read {
  binder_size_t write_size;
  binder_size_t write_consumed;
  binder_uintptr_t write_buffer;
  binder_size_t read_size;
  binder_size_t read_consumed;
  binder_uintptr_t read_buffer;
};
struct binder_version {
  __s32 protocol_version; /* increment with incompatible change */
};
#ifdef BINDER_IPC_32BIT
#define BINDER_CURRENT_PROTOCOL_VERSION 7
#else
#define BINDER_CURRENT_PROTOCOL_VERSION 8
#endif
struct binder_node_debug_info {
  binder_uintptr_t ptr;
  binder_uintptr_t cookie;
  __u32 has_strong_ref;
  __u32 has_weak_ref;
};
#define BINDER_WRITE_READ _IOWR('b', 1, struct binder_write_read)
#define BINDER_SET_IDLE_TIMEOUT _IOW('b', 3, __s64)
#define BINDER_SET_MAX_THREADS _IOW('b', 5, __u32)
#define BINDER_SET_IDLE_PRIORITY _IOW('b', 6, __s32)
#define BINDER_SET_CONTEXT_MGR _IOW('b', 7, __s32)
#define BINDER_THREAD_EXIT _IOW('b', 8, __s32)
#define BINDER_VERSION _IOWR('b', 9, struct binder_version)
#define BINDER_GET_NODE_DEBUG_INFO _IOWR('b', 11, struct binder_node_debug_info)

enum transaction_flags {
  TF_ONE_WAY = 0x01,      /* this is a one-way call: async, no return */
  TF_ROOT_OBJECT = 0x04,  /* contents are the component's root object */
  TF_STATUS_CODE = 0x08,  /* contents are a 32-bit status code */
  TF_ACCEPT_FDS = 0x10,   /* allow replies with file descriptors */
};
struct binder_transaction_data {
  union {
    __u32 handle;         /* target descriptor of command transaction */
    binder_uintptr_t ptr; /* target descriptor of return transaction */
  } target;
  binder_uintptr_t cookie;
  __u32 code;             /* transaction command */

  /* General information about the transaction. */
  __u32 flags;
  pid_t sender_pid;
  uid_t sender_euid;
  binder_size_t data_size;
  binder_size_t offsets_size;
  union {
    struct {
      binder_uintptr_t buffer; /* transaction data */
      binder_uintptr_t offsets; /* offsets from buffer to flat_binder_object structs */
    } ptr;
    __u8 buf[8];
  } data;
};
struct binder_transaction_data_sg {
  struct binder_transaction_data transaction_data;
  binder_size_t buffers_size;
};
struct binder_ptr_cookie {
  binder_uintptr_t ptr;
  binder_uintptr_t cookie;
};
struct binder_handle_cookie {
	__u32 handle;
	binder_uintptr_t cookie;
} __attribute__((packed));

struct binder_pri_desc {
  __s32 priority;
  __u32 desc;
};
struct binder_pri_ptr_cookie {
  __s32 priority;
  binder_uintptr_t ptr;
  binder_uintptr_t cookie;
};
enum binder_driver_return_protocol {
  BR_ERROR = _IOR('r', 0, __s32),   // int: error code
  BR_OK = _IO('r', 1),
  BR_TRANSACTION = _IOR('r', 2, struct binder_transaction_data),
  BR_REPLY = _IOR('r', 3, struct binder_transaction_data),
  BR_ACQUIRE_RESULT = _IOR('r', 4, __s32), //binder_transaction_data: the received command.

  BR_DEAD_REPLY = _IO('r', 5),
    /*
     * The target of the last transaction (either a bcTRANSACTION or
     * a bcATTEMPT_ACQUIRE) is no longer with us.  No parameters.
     */
  BR_TRANSACTION_COMPLETE = _IO('r', 6),

    /*
         * No parameters... always refers to the last transaction requested
         * (including replies).  Note that this will be sent even for
         * asynchronous transactions.
         */
  BR_INCREFS = _IOR('r', 7, struct binder_ptr_cookie),
  BR_ACQUIRE = _IOR('r', 8, struct binder_ptr_cookie),
  BR_RELEASE = _IOR('r', 9, struct binder_ptr_cookie),
  BR_DECREFS = _IOR('r', 10, struct binder_ptr_cookie),

    /*
         * void *:	ptr to binder
         * void *: cookie for binder
         */
  BR_ATTEMPT_ACQUIRE = _IOR('r', 11, struct binder_pri_ptr_cookie),
    /*
         * not currently supported
         * int:	priority
         * void *: ptr to binder
         * void *: cookie for binder
         */
  BR_NOOP = _IO('r', 12),
    /*
         * No parameters.  Do nothing and examine the next command.  It exists
         * primarily so that we can replace it with a BR_SPAWN_LOOPER command.
         */
  BR_SPAWN_LOOPER = _IO('r', 13),
    /*
         * No parameters.  The driver has determined that a process has no
         * threads waiting to service incoming transactions.  When a process
         * receives this command, it must spawn a new service thread and
         * register it via bcENTER_LOOPER.
         */
  BR_FINISHED = _IO('r', 14),
    /*
         * not currently supported
         * stop threadpool thread
         */
  BR_DEAD_BINDER = _IOR('r', 15, binder_uintptr_t),
    /*
         * void *: cookie
         */
  BR_CLEAR_DEATH_NOTIFICATION_DONE = _IOR('r', 16, binder_uintptr_t),
    /*
         * The the last transaction (either a bcTRANSACTION or
         * a bcATTEMPT_ACQUIRE) failed (e.g. out of memory).  No parameters.
         */
  BR_FAILED_REPLY = _IO('r', 17),
};
enum binder_driver_command_protocol {
  BC_TRANSACTION = _IOW('c', 0, struct binder_transaction_data),
  BC_REPLY = _IOW('c', 1, struct binder_transaction_data),
    /*
         * binder_transaction_data: the sent command.
         */

  BC_ACQUIRE_RESULT = _IOW('c', 2, __s32),
    /*
         * not currently supported
         * int:  0 if the last BR_ATTEMPT_ACQUIRE was not successful.
         * Else you have acquired a primary reference on the object.
         */

  BC_FREE_BUFFER = _IOW('c', 3, binder_uintptr_t),
    /*
         * void *: ptr to transaction data received on a read
         */

  BC_INCREFS = _IOW('c', 4, __u32),
  BC_ACQUIRE = _IOW('c', 5, __u32),
  BC_RELEASE = _IOW('c', 6, __u32),
  BC_DECREFS = _IOW('c', 7, __u32),
    /*
         * int:	descriptor
         */

  BC_INCREFS_DONE = _IOW('c', 8, struct binder_ptr_cookie),
  BC_ACQUIRE_DONE = _IOW('c', 9, struct binder_ptr_cookie),
    /*
         * void *: ptr to binder
         * void *: cookie for binder
         */

  BC_ATTEMPT_ACQUIRE = _IOW('c', 10, struct binder_pri_desc),
    /*
         * not currently supported
         * int: priority
         * int: descriptor
         */

  BC_REGISTER_LOOPER = _IO('c', 11),
    /*
         * No parameters.
         * Register a spawned looper thread with the device.
         */

  BC_ENTER_LOOPER = _IO('c', 12),
  BC_EXIT_LOOPER = _IO('c', 13),
    /*
         * No parameters.
         * These two commands are sent as an application-level thread
         * enters and exits the binder loop, respectively.  They are
         * used so the binder can have an accurate count of the number
         * of looping threads it has available.
         */

  BC_REQUEST_DEATH_NOTIFICATION = _IOW('c', 14, struct binder_handle_cookie),
    /*
         * int: handle
         * void *: cookie
         */

    BC_CLEAR_DEATH_NOTIFICATION = _IOW('c', 15, struct binder_handle_cookie),
    /*
         * int: handle
         * void *: cookie
         */

    BC_DEAD_BINDER_DONE = _IOW('c', 16, binder_uintptr_t),
    /*
         * void *: cookie
         */

  BC_TRANSACTION_SG = _IOW('c', 17, struct binder_transaction_data_sg),
  BC_REPLY_SG = _IOW('c', 18, struct binder_transaction_data_sg),
};
#ifdef __cplusplus
}
#endif

#endif
