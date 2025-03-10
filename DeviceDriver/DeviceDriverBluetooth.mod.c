#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
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



static const char ____versions[]
__used __section("__versions") =
	"\x14\x00\x00\x00\x74\x69\x9a\xf9"
	"hid_hw_stop\0"
	"\x14\x00\x00\x00\x46\x90\x16\x6d"
	"_dev_info\0\0\0"
	"\x18\x00\x00\x00\xbc\x7b\x4d\x9c"
	"hid_open_report\0"
	"\x18\x00\x00\x00\x25\x17\xc6\xdc"
	"hid_hw_start\0\0\0\0"
	"\x14\x00\x00\x00\x10\xf5\xd0\x5b"
	"_dev_err\0\0\0\0"
	"\x20\x00\x00\x00\x4d\x99\xd1\xf7"
	"hid_unregister_driver\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x20\x00\x00\x00\x47\x16\x8f\xcb"
	"__hid_register_driver\0\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x18\x00\x00\x00\xd7\xd3\x75\x6d"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "hid");

MODULE_ALIAS("hid:b0005g0001v0000045Ep000002FD");

MODULE_INFO(srcversion, "94F7D007F8533DDB34CC537");
