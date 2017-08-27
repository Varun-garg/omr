#ifndef _MEMCHECK_WRAPPER_H_
#define _MEMCHECK_WRAPPER_H_

#include <set>
#include <stdint.h>

 void valgrindCreateMempool(uintptr_t PoolAddr);

 void valgrindDestroyMempool(uintptr_t PoolAddr, std::set<uintptr_t> allocatedObjects);

 void valgrindMempoolAlloc(uintptr_t PoolAddr, std::set<uintptr_t> &allocatedObjects, uintptr_t baseAddress, uintptr_t size);

 void valgrindMakeMemDefined(uintptr_t address, uintptr_t size);

 void valgrindMakeMemNoaccess(uintptr_t address, uintptr_t size);

 void valgrindClearRange(uintptr_t PoolAddr, std::set<uintptr_t> &allocatedObjects, uintptr_t baseAddress, uintptr_t size);

#endif /* _MEMCHECK_WRAPPER_H_ */