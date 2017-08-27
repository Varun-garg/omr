#include "MemcheckWrapper.hpp"
#include "omrcomp.h"
#include "modronopt.h"
#include "ModronAssertions.h"
#include "ObjectModel.hpp"
#include <valgrind/memcheck.h>
#include <set>
#include "stdint.h"
#include "EnvironmentBase.hpp"
#include <stdint.h>


 void valgrindCreateMempool(uintptr_t PoolAddr)
{
    //1 lets valgrind know that objects will be defined when allocated
    VALGRIND_CREATE_MEMPOOL(PoolAddr, 0, 1);
}

 void valgrindDestroyMempool(uintptr_t PoolAddr, std::set<uintptr_t> allocatedObjects)
{
    //All objects should have been freed by now!
    Assert_MM_true(allocatedObjects.empty());
    VALGRIND_DESTROY_MEMPOOL(PoolAddr);
}

 void valgrindMempoolAlloc(uintptr_t PoolAddr, std::set<uintptr_t> &allocatedObjects, uintptr_t baseAddress, uintptr_t size)
{
#if defined(VALGRIND_REQUEST_LOGS)
    VALGRIND_PRINTF_BACKTRACE("Allocated object at 0x%lx of size %lu\n", baseAddress, size);
#endif /* defined(VALGRIND_REQUEST_LOGS) */
    /* Allocate object in Valgrind memory pool. */ 		
    VALGRIND_MEMPOOL_ALLOC(PoolAddr, baseAddress, size);
    allocatedObjects.insert(baseAddress);
}

 void valgrindMakeMemDefined(uintptr_t address, uintptr_t size)
{
#if defined(VALGRIND_REQUEST_LOGS)
    VALGRIND_PRINTF_BACKTRACE("Marking area defined at 0x%lx of size %lu\n", address, size);
#endif /* defined(VALGRIND_REQUEST_LOGS) */
    VALGRIND_MAKE_MEM_DEFINED(address, size);
}

 void valgrindMakeMemNoaccess(uintptr_t address, uintptr_t size)
{
#if defined(VALGRIND_REQUEST_LOGS)
    VALGRIND_PRINTF_BACKTRACE("Marking area noaccess at 0x%lx of size %lu\n", address, size);
#endif /* defined(VALGRIND_REQUEST_LOGS) */
    VALGRIND_MAKE_MEM_NOACCESS(address, size);
}

 void valgrindClearRange(uintptr_t PoolAddr, std::set<uintptr_t> &allocatedObjects, uintptr_t baseAddress, uintptr_t size)
{


}