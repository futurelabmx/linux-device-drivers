# Hello World Module explanation

This small hello world module needs two functions to work properly, the init
function which is used to properly load & initialize this kernel module and the
exit function which is needed to unload and stop the kernel module, both these
functions call some special kernel macros included in the linux headers.

one special macro is the `MODULE_LICENSE` macro which is used to define a
module's license and declare if it is free (or not), in this case we are using
two free-software licenses both BSD and GPL (defaults to GPL-2). If we skip this
declaration the kernel may complain when we load it.

These two modules also use the notify function called `printk` (short for
print-kernel) which is another function defined in the kernel headers, it's
similar to the widely used `printf` C function, this function is needed because
the kernel itself doesn't need help of the C library (libc) but it's own library
to print messages to the boot / load console.

In that same function we encounter the `KERN_ALERT` function which acts like a
high-priority kernel message since any message with the default priority or
lower won't show up in useful places.

To test this module use the `insmod` and `rmmod` utils that come bundled in most
linux distros (Only a superuser can do this). It is also recommended to create a
`MAKEFILE` to specify directories and module uses.

This module should behave like this:

``` sh
root@VentooQEMU# insmod ./hello-world.ko
Hello, world
root@VentooQEMU# rmmod hello-world
Goodbye
```
