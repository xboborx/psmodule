# Linux kernel module psmodule.
### Build
```sh
$ make 
```
### Running
##### Running processes mode:

```sh
$ sudo insmod psmodule.ko 
```
##### Threads mode:
```sh
$ sudo insmod psmodule.ko pid=XXXX 
```
