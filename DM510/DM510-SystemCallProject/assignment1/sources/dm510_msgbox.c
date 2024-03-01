#include </home/jathu21/dm510/linux-6.6.9/include/linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include </home/jathu21/dm510/linux-6.6.9/arch/um/include/asm/uaccess.h>
#include "linux/kernel.h"
#include "linux/unistd.h"
#include "/home/jathu21/dm510/linux-6.6.9/arch/um/include/asm/dm510_msgbox.h"

typedef struct _msgStack msgStack;

struct _msgStack {
    msgStack* previous;
    int length;
    char* message;
};

static msgStack *bottom = NULL;
static msgStack *top = NULL;


int dm510_msgbox_put(char* buffer, int length){
    if(length <= 0){
        return -EINVAL;
    }
    if(length > 101){
        return -EINVAL;
    }
    msgStack* msg = kmalloc(sizeof(msgStack), GFP_KERNEL);
    if(msg == NULL){
        return -ENOMEM;
    }

    msg -> previous = NULL;
    msg -> length = length;
    msg -> message = kmalloc(length, GFP_KERNEL);


    if(msg -> message == NULL){
        kfree(msg);
        return -ENOMEM;
    }

    if(!access_ok(buffer, length)){
        return -EFAULT;
    }

    int copyUser = copy_from_user(msg -> message, buffer, length);
    if(copyUser != 0){
        return -EFAULT;
    }

    unsigned long flags;
    local_irq_save(flags); //start of critical region

    //if the stack is empty
    if(bottom == NULL){
        bottom = msg;
        top = msg;
        msg -> previous = NULL;
    }
    // if stack is not empty
    else{
        msg -> previous = top;
        top = msg;
    }
    local_irq_restore(flags); // critical region end

    return 0;
}


int dm510_msgbox_get(char* buffer, int length){
    unsigned long flags;
    local_irq_save(flags); //start of critical region
    if(top != NULL) {
        msgStack* msg = top;
        int msgLength = msg->length;
        if(msgLength <= 0){
            return -EINVAL;
        }
        if(msgLength > 101){
            return -EINVAL;
        }
        top = msg->previous;

        if(!access_ok(buffer, length)){
            return -EFAULT;
        }
        int cpyToUser = copy_to_user(buffer, msg->message, msgLength);
        if(cpyToUser != 0){
            return -EFAULT;
        }

        kfree(msg -> message);
        kfree(msg);

        return msgLength;
    }
    local_irq_restore(flags); // critical region end

    return -1;

}
