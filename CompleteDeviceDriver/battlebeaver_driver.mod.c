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

#ifdef CONFIG_MITIGATION_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x14\x00\x00\x00\xf1\xe4\xd9\xa8"
	"hid_hw_stop\0"
	"\x14\x00\x00\x00\x8e\xa7\x5b\xae"
	"_dev_info\0\0\0"
	"\x18\x00\x00\x00\xcc\x9e\x28\x2e"
	"hid_open_report\0"
	"\x18\x00\x00\x00\x1d\xd4\x94\x6b"
	"hid_hw_start\0\0\0\0"
	"\x14\x00\x00\x00\x48\xfc\xc1\xf0"
	"_dev_err\0\0\0\0"
	"\x20\x00\x00\x00\x56\x53\x44\x11"
	"hid_unregister_driver\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x20\x00\x00\x00\x75\xa1\x4e\x6d"
	"__hid_register_driver\0\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x18\x00\x00\x00\xde\x9f\x8a\x25"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "hid");

MODULE_ALIAS("hid:b0005g0001v0000045Ep000002FD");

MODULE_INFO(srcversion, "C3DB854F661C22E94DA1271");
