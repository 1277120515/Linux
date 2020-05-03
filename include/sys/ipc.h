
#ifndef _IPC_H_
#define _IPC_H_





struct ipc_perm
{
    uid_t    uid;//    owner's user ID
    gid_t    gid;//    owner's group ID
    uid_t    cuid;//   creator's user ID
    gid_t    cgid;//   creator's group ID
    mode_t   mode;//   read/write permission
};


// Definitions are given for the following constants:

// Mode bits:

#define IPC_CREAT
// Create entry if key does not exist.
#define IPC_EXCL
// Fail if key exists.
#define IPC_NOWAIT
// Error if request must wait.
// Keys:

#define IPC_PRIVATE
// Private key.
// Control commands:

#define IPC_RMID
// Remove identifier.
#define IPC_SET
// Set options.
#define IPC_STAT
// Get options.
// The following is declared as a function and may also be defined as a macro. 
// Function prototypes must be provided for use with an ISO C compiler.


key_t  ftok(const char *, int);




#endif // !_IPC_H_

















