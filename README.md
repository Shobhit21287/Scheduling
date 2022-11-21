**Question 1 :**

part 1:
1. Making three threads and giving them different priorities changes their run time and the time it takes for the individual threads to finish
2. SCHED_FIFO and SCHED_RR take roughly the same time to finish, unlike SCHED_OTHER which is always starved
3. This is because SCHED_OTHER is always lower in priority compared to SCHED_FIFO and SCHED_RR regardless of their priority values

part 2:
1. After making a function we call fork() thrice. This creates three child processes.
2. We then use waitpid() to get the ID of the child that is returned
3. Before forking we get the start time and after waitpid() we get the end time for a the child returned by waitpid()
4. All the children take roughly the same time to finish except, when one or more of the make commands fails at the start
5. The reason the ending time is same because the priorities of the child processes is the same

**Question 2 :**

1.To implement the system call after writing the syscall in sys.c, we add the syscall name and type in syscall_64.tbl
2.after doing grub load, we compile the kernel using make -j$(nproc)
3.Then we write a test program and use the system call
4.If the program works as intended, we use diff -u a b > file.patch to get the difference in the files we edited vs the base kernel
5.we do this for sys.c and syscall_64.tbl after which we concatenate the two

The assignment is now complete after which we struggle to push it onto github

=========================END OF ASSIGNMENT=========================
