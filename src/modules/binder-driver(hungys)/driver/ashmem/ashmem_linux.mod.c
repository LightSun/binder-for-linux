#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xdd8f8694, "module_layout" },
	{ 0x2ef07f8e, "kmem_cache_destroy" },
	{ 0x754d539c, "strlen" },
	{ 0xe5801db0, "generic_file_open" },
	{ 0xcadaaa8d, "vfs_llseek" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0x24428be5, "strncpy_from_user" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x908d38d9, "vfs_read" },
	{ 0x978f9593, "misc_register" },
	{ 0x56b1771b, "current_task" },
	{ 0xc5850110, "printk" },
	{ 0xec45149b, "kmem_cache_free" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0x8308ba19, "fput" },
	{ 0x59445d32, "shmem_file_setup" },
	{ 0xc6cbbc89, "capable" },
	{ 0xab33fd9b, "kmem_cache_alloc" },
	{ 0xee62aae4, "unregister_shrinker" },
	{ 0xa916b694, "strnlen" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0xba036ed6, "vfs_fallocate" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xcde35d31, "kmem_cache_create" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3ed15c8f, "register_shrinker" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xdd02ac5a, "misc_deregister" },
	{ 0x88db9f48, "__check_object_size" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9725767CFC626DA47BFDF78");
