    fp = filp_open(dir_name,O_RDWR | O_CREAT,0644);
    if (IS_ERR(fp)) {  
        printk("create file error\n");  
        return -1;  
    }
    pos = 0; 
    ret = kernel_read(fp, buf, FRU_DATA_LEN, &pos); 
    filp_close(fp, NULL);

    fp = filp_open(dir_name,O_RDWR | O_CREAT,0644);
    if (IS_ERR(fp)) {  
        printk("create file error\n");  
        return -1;  
    }
    pos = 0; 
    ret = kernel_write(fp, buf, count, &pos);  
    filp_close(fp, NULL);

