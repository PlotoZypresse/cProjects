#include "linux/kernel.h"
#include "linux/unistd.h"
#include "/home/jathu21/dm510/linux-6.6.9/arch/um/include/asm/dm510_msgbox.h"

asmlinkage
int sys_dm510_msgbox_put(char* buffer, int length) {
    return dm510_msgbox_put(buffer, length);
}
