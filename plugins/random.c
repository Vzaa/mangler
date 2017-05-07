#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <syscall.h>
#include <linux/random.h>

#include "include/common.h"
#include "include/plugin.h"

static int init(plugin_t* self, int argc, char* argv[])
{
    return 0;
}

static void destroy(plugin_t* self)
{
}

static void callback(plugin_t* self, char* buf, uint16_t* buf_len)
{
    syscall(SYS_getrandom, buf, *buf_len, 0);
}

plugin_t random_plugin = {
    .name = "random",
    .priv = NULL,
    .init = init,
    .destroy = destroy,
    .callback = callback
};
