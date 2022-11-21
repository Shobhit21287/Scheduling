SYSCALL_DEFINE3(twodcopy, double**,src,double**,dest,int,cells){
    double * buff[1];
    double ** temp = dest;
    
    for(int i = 0 ; i < cells ; i++){
        if(__copy_from_user(buff,src,sizeof(double*))){
            return -EFAULT;
        }
        if(__copy_to_user(temp,buff,sizeof(double*))){
            return -EFAULT;
        }
        src++;
        temp++;
    }
    
    return 0;
}
