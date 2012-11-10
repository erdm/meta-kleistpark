SUMMARY = "Fusion is a Inter-Process-Communication kernel module"
DESCRIPTION = "Fusion is a Inter-Process-Communication (IPC) kernel module with a high level of abstraction. It offers primitives like skirmishes (locks), calls, properties and shared memory pools. You can query the status of the primitives via an entry in the /proc ﬁlesystem"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://linux/include/linux/fusion.h;beginline=9;endline=12;md5=5507d6bdbe75dfd82817ce2ce942259e"

INC_PR = "r0"

SRC_URI = "git://git.directfb.org/git/directfb/core/linux-fusion.git;protocol=git \
    file://40-fusion.rules"

S = "${WORKDIR}/git"

inherit module

EXTRA_OEMAKE="KERNELDIR=${STAGING_KERNEL_DIR}"

do_install_append() {
    # add udev rule
    install -d ${D}${sysconfdir}/udev/rules.d
    install -m 0644 ${WORKDIR}/40-fusion.rules ${D}${sysconfdir}/udev/rules.d/40-fusion.rules
}
