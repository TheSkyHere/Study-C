在linux系统上，sync 和 syncfs 都是阻塞的，会确保数据写入底层的文件系统。但是在POSIX标准里，sync可能在数据写入之前返回。